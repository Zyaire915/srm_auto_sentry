#!/bin/zsh

# Set password
password=' '

# Attach to C board
sudo -S chmod 777 /dev/ttyACM0 << EOF
$password
EOF

# Start vision
source install/setup.sh
ros2 launch rm_vision_bringup vision_bringup.launch.py
