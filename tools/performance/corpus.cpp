#include "detail/protocol.hpp"
#include "detail/xml_config.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
int main(int argc, char **argv) {
  if (argc != 2)
    return 2;
  std::string root = argv[1];
  for (auto name : {"extreme", "short", "long"}) {
    std::ifstream f(root + "/" + name + ".hex");
    std::string hex;
    f >> hex;
    std::vector<unsigned char> data;
    for (size_t i = 0; i < hex.size(); i += 2)
      data.push_back(static_cast<unsigned char>(
          std::stoul(hex.substr(i, 2), nullptr, 16)));
    bool accepted = false;
    try {
      auto r = netft::detail::decode_record(data.data(), data.size());
      accepted = true;
      if (r.fx != INT32_MIN || r.fy != INT32_MAX)
        return 1;
    } catch (const netft::detail::ProtocolError &) {
    }
    if (accepted != (std::string(name) == "extreme"))
      return 1;
  }
  for (auto name : {"unsafe-scale", "safe-scale"}) {
    std::ifstream f(root + "/" + name + ".xml");
    std::string xml{std::istreambuf_iterator<char>(f), {}};
    bool accepted = false;
    try {
      netft::detail::parse_sensor_configuration(xml);
      accepted = true;
    } catch (const std::exception &) {
    }
    if (accepted != (std::string(name) == "safe-scale"))
      return 1;
  }
  std::cout << "5 corpus decoding/calibration cases passed\n";
}
