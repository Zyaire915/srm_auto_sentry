"""
多途径点导航启动文件
支持不同的途径点和最终目标容差
"""

import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.substitutions import LaunchConfiguration
from launch.actions import DeclareLaunchArgument


def generate_launch_description():
    # 获取包目录
    rm_nav_bringup_dir = get_package_share_directory('rm_nav_bringup')
    
    # 声明启动参数
    declare_waypoint_tolerance = DeclareLaunchArgument(
        'waypoint_tolerance',
        default_value='1.0',
        description='途径点容差（米）'
    )
    
    declare_final_goal_tolerance = DeclareLaunchArgument(
        'final_goal_tolerance',
        default_value='0.25',
        description='最终目标容差（米）'
    )

    # 创建节点
    navigate_waypoints_node = Node(
        package='rm_nav_bringup',
        executable='navigate_through_waypoints',
        name='navigate_through_waypoints',
        output='screen',
        parameters=[
            {
                'waypoint_tolerance': LaunchConfiguration('waypoint_tolerance'),
                'final_goal_tolerance': LaunchConfiguration('final_goal_tolerance'),
                'goal_checker_service_timeout': 2.0,
            }
        ],
        remappings=[
            ('/navigate_to_pose', '/navigate_to_pose'),
            ('/controller_server/set_parameters', '/controller_server/set_parameters'),
        ]
    )

    return LaunchDescription([
        declare_waypoint_tolerance,
        declare_final_goal_tolerance,
        navigate_waypoints_node,
    ])
