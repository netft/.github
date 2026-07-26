<div align="center">

# Net F/T

**Open-source C++, Python, and ROS software for ATI Net F/T Ethernet force/torque sensors.**

Build native applications, stream measurements from Python, or integrate force/torque data into ROS and `ros2_control`.

</div>

---

## 🧰 Projects

| Project | Interface | What it provides |
| --- | --- | --- |
| [**netft-cpp**](https://github.com/netft/netft-cpp) | C++ | Native client library and the `netft` command-line tool |
| [**pyNetFT**](https://github.com/netft/pyNetFT) | Python | Typed Python API backed by a native C++ core |
| [**ros-netft**](https://github.com/netft/ros-netft) | ROS 1 & ROS 2 | Standalone ROS driver and `ros2_control` sensor integration |

> Each project provides its own installation, configuration, API, and development documentation.

## 🚀 Where to start

- Building a **C++ application** or using the command line? Start with [netft-cpp](https://github.com/netft/netft-cpp).
- Building a **Python application**? Start with [pyNetFT](https://github.com/netft/pyNetFT).
- Integrating a sensor into a **ROS robot**? Start with [ros-netft](https://github.com/netft/ros-netft).

## 📦 Ecosystem capabilities

- Stream force and torque measurements over Ethernet
- Discover calibration scales and measurement units from the sensor
- Access raw counts, calibrated measurements, health information, and faults
- Use native C++ or typed Python APIs
- Publish ROS wrench data from ROS 1 and ROS 2
- Integrate with `ros2_control` force/torque broadcasters
- Monitor sensors from the `netft` command-line tool

## 🤝 Support and contributions

Report bugs, request features, or ask project-specific questions through the issue tracker of the relevant repository.

Contributions are welcome through pull requests. Please review the contributing guidelines and development documentation in each project before submitting changes.

---

<p align="center">
  <sub>Community-maintained projects, not affiliated with ATI Industrial Automation.</sub>
</p>
