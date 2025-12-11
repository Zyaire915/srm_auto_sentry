#!/bin/zsh

# Start rm_decision

    # attack_left
    # attack_right
    # retreat_attack_left
    # protect_supply

source install/setup.sh
ros2 launch rm_behavior_tree rm_behavior_tree.launch.py \
    style:=retreat_attack_left \
    use_sim_time:=True
