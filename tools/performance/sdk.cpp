#include "netft/client.hpp"
#include "support/fake_sensor.hpp"
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <sys/resource.h>
#include <thread>
#include <vector>
using Clock = std::chrono::steady_clock;
int main() {
  for (int rate : {100, 1000, 7000})
    for (int repeat = 0; repeat < 3; ++repeat) {
      netft::test::FakeSensor sensor(rate);
      netft::Config config;
      config.sensor_host = sensor.host();
      config.rdt_port = sensor.rdt_port();
      config.http_port = sensor.http_port();
      netft::Client client(config);
      std::vector<double> age;
      age.reserve(9000);
      auto cpu = std::clock();
      auto start = Clock::now();
      client.start([&](const netft::Sample &s) {
        age.push_back(std::chrono::duration<double, std::micro>(Clock::now() -
                                                                s.received_at)
                          .count());
        if (rate == 7000)
          std::this_thread::sleep_for(std::chrono::microseconds(200));
      });
      std::this_thread::sleep_for(std::chrono::seconds(1));
      auto stop = Clock::now();
      client.stop();
      const auto stop_ms =
          std::chrono::duration<double, std::milli>(Clock::now() - stop)
              .count();
      auto h = client.health();
      auto cpu_pct =
          100.0 * (std::clock() - cpu) / CLOCKS_PER_SEC /
          std::chrono::duration<double>(Clock::now() - start).count();
      std::sort(age.begin(), age.end());
      auto p = [&](double q) {
        return age.empty()
                   ? 0
                   : age[std::min(age.size() - 1, size_t(q * age.size()))];
      };
      struct rusage usage{};
      getrusage(RUSAGE_SELF, &usage);
      std::cout << "{\"rate\":" << rate << ",\"repeat\":" << repeat
                << ",\"samples\":" << age.size() << ",\"p50_us\":" << p(.50)
                << ",\"p95_us\":" << p(.95) << ",\"p99_us\":" << p(.99)
                << ",\"cpu_percent\":" << cpu_pct
                << ",\"rss_peak_kib\":" << usage.ru_maxrss
                << ",\"lost\":" << h.lost_count << ",\"stop_ms\":" << stop_ms
                << "}\n";
    }
}
