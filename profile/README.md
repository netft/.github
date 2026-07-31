<div align="center">

# Net F/T

**Open-source software for ATI Net F/T Ethernet force/torque sensors.**

Build native or Python applications, use a cross-platform command line,
integrate force/torque data into ROS and `ros2_control`, or inspect and record
measurements from a desktop viewer.

</div>

---

## 🧰 Projects

| Project | Best for | What it provides |
| --- | --- | --- |
| [**netft-cpp**](https://github.com/netft/netft-cpp) | Native C++ applications | Cross-platform C++17 SDK and CMake package |
| [**netft-cli**](https://github.com/netft/netft-cli) | Terminal use and automation | Cross-platform `netft` command with diagnostics, recording, and structured output |
| [**pyNetFT**](https://github.com/netft/pyNetFT) | Python applications | Typed synchronous Python API backed by a native C++ core |
| [**ros-netft**](https://github.com/netft/ros-netft) | ROS robots and controllers | ROS 1 and ROS 2 driver with `ros2_control` sensor integration |
| [**netft-viewer**](https://github.com/netft/netft-viewer) | Live inspection and data capture | Cross-platform desktop plots, health monitoring, bias control, and CSV recording |

Each repository maintains its own installation, compatibility, API, and
development documentation.

## 🚀 Where to start

- Use [netft-cpp](https://github.com/netft/netft-cpp) for a native C++ application.
- Use [netft-cli](https://github.com/netft/netft-cli) for interactive terminal
  work, health checks, scripts, and recording.
- Use [pyNetFT](https://github.com/netft/pyNetFT) for a typed Python application.
- Use [ros-netft](https://github.com/netft/ros-netft) for a standalone ROS driver
  or `ros2_control` integration.
- Use [netft-viewer](https://github.com/netft/netft-viewer) to connect without
  ROS, view all six axes, and record CSV data.

## ⚙️ Ecosystem capabilities

- Discover calibration scales and measurement units from the sensor before
  streaming RDT data.
- Access raw counts, calibrated force and torque, sequence health, device status,
  and recovery information.
- Build with C++17, use a typed synchronous Python API, or automate with the
  cross-platform CLI.
- Publish ROS wrench and diagnostics data from ROS 1 and ROS 2.
- Connect sensors to the standard `ros2_control` force/torque broadcaster.
- Inspect real-time six-axis plots and capture accepted samples through buffered
  CSV recording.

## 💻 Platform support

The `netft-cpp` SDK, `netft-cli`, and Net F/T Viewer are tested on Linux,
Windows, and macOS. Individual interfaces and installation artifacts vary by
platform. pyNetFT wheel availability and supported ROS distributions are listed
in their respective repository compatibility tables.

## 🤝 Support and contributions

Report bugs, request features, or ask project-specific questions through the
issue tracker of the relevant repository.

Contributions are welcome through pull requests. Review the contribution guide
for the project you plan to change before submitting one.

---

<p align="center">
  <sub>Community-maintained projects, not affiliated with ATI Industrial Automation.</sub>
</p>
