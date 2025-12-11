#!/bin/zsh

# Start navigation
source install/setup.sh

ros2 launch rm_nav_bringup bringup_real.launch.py \
    world:=RMUL \
    mode:=nav \
    lio:=fastlio \
    localization:=slam_toolbox \
    lio_rviz:=False \
    nav_rviz:=False
