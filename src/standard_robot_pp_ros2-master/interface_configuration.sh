#!/bin/bash

# 停止脚本执行如果任何命令失败
set -e

# echo "开始清理和构建..."

# # 清理之前的构建文件
# sudo rm -rf build install log

# # 进入src目录
# cd src

# # 克隆transport_drivers仓库
# git clone https://github.com/ros-drivers/transport_drivers.git -b humble

# # 进入transport_drivers目录并克隆udp_msgs
# cd transport_drivers
# git clone https://github.com/flynneva/udp_msgs.git

# # 返回工作空间根目录
# cd ../..

# # 安装依赖
# sudo apt-get install -y libasio-dev

# 构建选定的包
colcon build --packages-select asio_cmake_module udp_msgs udp_driver io_context serial_driver

# 构建所有包
colcon build

echo "构建完成！"

ros2 launch standard_robot_pp_ros2 standard_robot_pp_ros2.launch.py
