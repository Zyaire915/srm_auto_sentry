# rm_serial_driver

RoboMaster 视觉系统与电控系统的串口通讯模块

该项目为 [rm_vision](https://github.com/chenjunnn/rm_vision) 的子模块

## Overview

本模块基于 [transport_drivers](https://github.com/ros-drivers/transport_drivers) 实现了上位机与电控部分通讯的功能

## 使用指南

安装依赖 `sudo apt install ros-humble-serial-driver`

更改 [serial_driver.yaml](config/serial_driver.yaml) 中的参数以匹配与电控通讯的串口

提权 `sudo chmod 777 /dev/ttyACM0`

启动串口模块 `ros2 launch rm_serial_driver serial_driver.launch.py`

## 接口

| **packet**          | **header** | **information** |
|:-------------------:|:----------:|:---------------:|
| ReceivePacketVision | 0x5A       | 接收云台姿态用于自瞄      |
| SendPacketVision    | 0xA5       | 输出敌方机器人状态用于电控解算 |
| SendPacketTwist     | 0xA4       | 底盘导航控制          |

详情请参考 [packet.hpp](include/rm_serial_driver/packet.hpp)

### ReceivePacketVision

- 机器人的自身颜色 `robot_color` 以判断对应的识别目标颜色
- 云台姿态 `pitch` 和 `yaw`, 单位和方向请参考 <https://www.ros.org/reps/rep-0103.html>
- 当前云台瞄准的位置 `aim_x, aim_y, aim_z`，用于发布可视化 Marker

### SendPacketVision

- 视觉端发送 armor_tracker 的输出，即对于目标机器人的观测，具体的运动预测、装甲板选择、弹道解算在电控端完成

### SendPacketTwist

由导航模块输出，用于哨兵机器人底盘运动控制（针对平面运动）

- linear: 线速度，包含 x, y 分量，分别代表沿 x, y 轴的线速度。单位 m/s
- angular: 角速度，仅包含 z 分量，代表绕 z 轴的角速度（yaw）。单位 rad/s
