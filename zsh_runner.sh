#!/bin/zsh
# 显式加载 zsh 环境和 ROS 2 路径
source /opt/ros/humble/setup.zsh
source /home/srm/srm_auto_sentry/install/setup.zsh

# 导出 ROS 2 必要的变量
export ROS_DOMAIN_ID=1
export PYTHONUNBUFFERED=1

# 执行传入的服务命令
exec "$@"
