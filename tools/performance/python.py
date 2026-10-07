"""Fixed nine-second loopback baseline; only talks to its own UDP fake sensor."""
import json,resource,socket,struct,threading,time,statistics
from pynetft import Client,Config,Calibration,ForceUnit,TorqueUnit
for rate in (100,1000,7000):
 for repeat in range(3):
  sock=socket.socket(socket.AF_INET,socket.SOCK_DGRAM);sock.bind(('127.0.0.1',0));sock.settimeout(.05)
  done=threading.Event()
  def producer():
   peer=None;sequence=0;next_at=time.monotonic()
   while not done.is_set():
    if peer is None:
     try:
      request,address=sock.recvfrom(64)
      if request[2:4]==b'\x00\x02':peer=address
     except socket.timeout:continue
    sequence+=1;sock.sendto(struct.pack('>III6i',sequence,sequence,0,100,-200,300,10,-20,30),peer)
    next_at+=1/rate;done.wait(max(0,next_at-time.monotonic()))
  worker=threading.Thread(target=producer);worker.start()
  config=Config(sensor_host='127.0.0.1',rdt_port=sock.getsockname()[1],calibration_override=Calibration(1e6,1e6,ForceUnit.NEWTON,TorqueUnit.NEWTON_METER))
  client=Client(config,queue_size=128);age=[];cpu=time.process_time();start=time.monotonic()
  try:
   client.start();samples=client.samples(timeout=.2)
   while time.monotonic()-start<1:
    s=next(samples);age.append((time.monotonic_ns()-s.received_at_ns)/1000)
    if rate==7000:time.sleep(.0005)
   health=client.health();stop=time.monotonic();client.stop();stop_ms=(time.monotonic()-stop)*1000
  finally:
   client.stop();done.set();worker.join(1);sock.close()
  age.sort();p=lambda q:age[min(len(age)-1,int(q*len(age)))] if age else 0
  print(json.dumps(dict(rate=rate,repeat=repeat,samples=len(age),p50_us=p(.5),p95_us=p(.95),p99_us=p(.99),cpu_percent=100*(time.process_time()-cpu)/(time.monotonic()-start),rss_peak_kib=resource.getrusage(resource.RUSAGE_SELF).ru_maxrss,queue_drops=health.python_queue_dropped_count,lost=health.lost_count,stop_ms=stop_ms)))
