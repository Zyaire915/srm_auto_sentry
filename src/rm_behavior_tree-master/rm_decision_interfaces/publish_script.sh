#!/bin/zsh

source install/setup.sh

ros2 topic pub -r 10 /decision_num rm_decision_interfaces/msg/DecisionNum "{
    decision_num: 1,
}" &

ros2 topic pub -r 10 /robot_status rm_decision_interfaces/msg/RobotStatus "{
    robot_id: 7,
    current_hp: 600,
    shooter_heat: 0,
    team_color: 0,
    is_attacked: 0,
}" &

ros2 topic pub -r 1 /game_status rm_decision_interfaces/msg/GameStatus "{
    game_progress: 4, # 4:比赛开始
    stage_remain_time: 220,
}" &

ros2 topic pub -r 3 /robot_hp rm_decision_interfaces/msg/AllRobotHP "{
    red_1_robot_hp: 100,
    red_2_robot_hp: 100,
    red_3_robot_hp: 100,
    red_4_robot_hp: 100,
    red_5_robot_hp: 200,
    red_7_robot_hp: 200,
    red_outpost_hp: 20,
    red_base_hp: 1000,
    blue_1_robot_hp: 100,
    blue_2_robot_hp: 100,
    blue_3_robot_hp: 100,
    blue_4_robot_hp: 200,
    blue_5_robot_hp: 200,
    blue_7_robot_hp: 200,
    blue_outpost_hp: 1000,
    blue_base_hp: 1000
}" &

ros2 topic pub -r 3 /referee/ally_robot_hp rm_decision_interfaces/msg/AllyRobotHP "{
    ally_1_robot_hp: 100,
    ally_2_robot_hp: 100,
    ally_3_robot_hp: 100,
    ally_4_robot_hp: 100,
    ally_7_robot_hp: 400,  # 哨兵通常是 7 号
    ally_outpost_hp: 20,  
    ally_base_hp: 1000
}" &

ros2 topic pub /srm/sefdefined rm_decision_interfaces/msg/Sefdefined "{
  robot_id: 7,
  robot_level: 1,
  current_hp: 500,
  maximum_hp: 600,
  shooter_barrel_cooling_value: 30,
  shooter_barrel_heat_limit: 200,
  shooter_17mm_1_barrel_heat: 50,
  robot_pos_x: 2.5,
  robot_pos_y: 3.5,
  robot_pos_angle: 90.0,
  armor_id: 0,
  hp_deduction_reason: 0,
  projectile_allowance_17mm_1: 400,
  remaining_gold_coin: 200
}" &

ros2 topic pub -r 5 /detector/armors auto_aim_interfaces/msg/Armors "{
  header: {
    stamp: {sec: 0, nanosec: 0},
    frame_id: 'my_frame'
  },

  # armors: [ # 取消注释，代表识别到敌人
  #   {
  #     number: '1',
  #     type: '0',
  #     distance_to_image_center: 1.0,
  #     pose: {
  #       position: {x: 0.0, y: 0.0, z: 0.0},
  #       orientation: {x: 0.0, y: 0.0, z: 0.0, w: 1.0}
  #     }
  #   }
  # ]
}" &

wait
