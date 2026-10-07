// Run from Viewer with its locked Node/Vite. Fixed three scenes, three repeats.
import {createRequire} from 'node:module';
import {resolve} from 'node:path';
import {performance} from 'node:perf_hooks';
const require=createRequire(resolve('package.json'));
const {createServer}=await import(require.resolve('vite'));
const server=await createServer({server:{middlewareMode:true}});
try {
 const {ChartModel}=await server.ssrLoadModule('/app/renderer/model/chart-model.ts');
 const axes=['Fx','Fy','Fz','Tx','Ty','Tz'];
 // PlotAggregator sends first/min/max/last per 33 ms, not raw sensor samples.
 for(const rate of [100,1000,7000])for(let repeat=0;repeat<3;repeat++){
  const model=new ChartModel(60000);const n=Math.min(4,Math.ceil(rate*.033));let tick=0;
  const batch=()=>({type:'plot_batch',payload:{axes:axes.map(axis=>({axis,points:Array.from({length:n},(_,i)=>({hostTimeNs:String(BigInt(tick*33000000+i*1000000)),value:Math.sin(tick+i)}))}))}});
  for(;tick<1819;tick++)model.append(batch());
  const durations=[];const cpu=process.cpuUsage();const start=performance.now();
  for(let f=0;f<120;f++,tick++){let at=performance.now();model.append(batch());for(const a of axes)model.series(a).map(p=>[p.timeMs,p.value]);durations.push(performance.now()-at);}
  durations.sort((a,b)=>a-b);const used=process.cpuUsage(cpu);const p=q=>durations[Math.min(durations.length-1,Math.floor(q*durations.length))];
  console.log(JSON.stringify({rate,repeat,points:model.pointCount,p50_ms:p(.5),p95_ms:p(.95),p99_ms:p(.99),cpu_ms:(used.user+used.system)/1000,elapsed_ms:performance.now()-start,rss_bytes:process.memoryUsage().rss,heap_bytes:process.memoryUsage().heapUsed}));
 }
}finally{await server.close();}
