#!/bin/bash
set -e # 遇到任何错误立即停止

echo "=========================================="
echo "开始全自动修复环境并安装依赖"
echo "=========================================="

# 0. 确保基础工具已安装 (忽略更新报错，确保 gnupg 存在)
echo "[0/5] 准备基础工具..."
sudo apt-get update -o Acquire::AllowInsecureRepositories=true -o Acquire::AllowDowngradeToInsecureRepositories=true || true
sudo apt-get install -y gnupg2 curl lsb-release

# 1. 清理旧的密钥和源文件 (防止冲突)
echo "[1/5] 清理旧密钥和配置文件..."
sudo rm -f /usr/share/keyrings/ros-archive-keyring.gpg
sudo rm -f /etc/apt/sources.list.d/ros-fish.list
sudo rm -f /etc/apt/sources.list.d/ros2.list
# 同时清理 trusted.gpg 里的残留，防止干扰
sudo apt-key del F42ED6FBAB17C654 2>/dev/null || true

# 2. 从 Ubuntu 密钥服务器获取 ROS 密钥 (修正版逻辑)
echo "[2/5] 获取并导入新密钥..."
mkdir -p ~/.gnupg && chmod 700 ~/.gnupg
# 拉取到当前用户临时钥匙环
gpg --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
# 导出到系统 apt 钥匙环
sudo mkdir -p /usr/share/keyrings
gpg --export C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654 | sudo tee /usr/share/keyrings/ros-archive-keyring.gpg > /dev/null

# 3. 写入中科大源
echo "[3/5] 写入中科大源配置..."
echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] https://mirrors.ustc.edu.cn/ros2/ubuntu $(lsb_release -cs) main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null

# 4. 更新软件源索引
echo "[4/5] 更新软件源..."
sudo apt update

# 5. 自动安装你需要的依赖 (新增步骤)
echo "[5/5] 正在自动安装 libasio-dev 和 example-interfaces..."
sudo apt install -y libasio-dev ros-humble-example-interfaces

echo "=========================================="
echo "大功告成！环境已修复且依赖已安装。"
echo "现在你可以直接去编译了。"