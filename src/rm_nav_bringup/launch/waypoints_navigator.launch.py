#!/usr/bin/env python3
"""
多途径点导航启动文件
集成：
- 导航系统 (Nav2)
- 多途径点导航器
- RViz 可视化
"""

import os
from launch import LaunchDescription
from launch.actions import (
    DeclareLaunchArgument,
    IncludeLaunchDescription,
    LogInfo,
)
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    """生成启动描述"""
    
    # ==================== 参数声明 ====================
    
    # 仿真参数
    world_arg = DeclareLaunchArgument(
        'world',
        default_value='RMUL',
        description='仿真世界: RMUL, RMUC',
        choices=['RMUL', 'RMUC']
    )
    
    mode_arg = DeclareLaunchArgument(
        'mode',
        default_value='nav',
        description='运行模式: mapping (边建图), nav (已知地图)',
        choices=['mapping', 'nav']
    )
    
    lio_arg = DeclareLaunchArgument(
        'lio',
        default_value='fastlio',
        description='LIO 选择: fastlio, pointlio',
        choices=['fastlio', 'pointlio']
    )
    
    localization_arg = DeclareLaunchArgument(
        'localization',
        default_value='slam_toolbox',
        description='定位方式: slam_toolbox, amcl, icp',
        choices=['slam_toolbox', 'amcl', 'icp']
    )
    
    lio_rviz_arg = DeclareLaunchArgument(
        'lio_rviz',
        default_value='False',
        description='是否显示 LIO 点云'
    )
    
    nav_rviz_arg = DeclareLaunchArgument(
        'nav_rviz',
        default_value='True',
        description='是否显示导航 RViz'
    )
    
    # 多途径点导航参数
    waypoint_tolerance_arg = DeclareLaunchArgument(
        'waypoint_tolerance',
        default_value='1.0',
        description='途径点容差 (米)'
    )
    
    final_goal_tolerance_arg = DeclareLaunchArgument(
        'final_goal_tolerance',
        default_value='0.25',
        description='最终目标容差 (米)'
    )
    
    # ==================== 变量替换 ====================
    
    world = LaunchConfiguration('world')
    mode = LaunchConfiguration('mode')
    lio = LaunchConfiguration('lio')
    localization = LaunchConfiguration('localization')
    lio_rviz = LaunchConfiguration('lio_rviz')
    nav_rviz = LaunchConfiguration('nav_rviz')
    waypoint_tolerance = LaunchConfiguration('waypoint_tolerance')
    final_goal_tolerance = LaunchConfiguration('final_goal_tolerance')
    
    # 获取包目录
    rm_nav_bringup_dir = FindPackageShare('rm_nav_bringup')
    
    # ==================== 启动项 ====================
    
    log_info_1 = LogInfo(
        msg=['启动多途径点导航系统...']
    )
    
    log_info_2 = LogInfo(
        msg=[
            '参数配置:\n',
            '  世界: ', world, '\n',
            '  模式: ', mode, '\n',
            '  LIO: ', lio, '\n',
            '  定位: ', localization, '\n',
            '  显示 LIO 点云: ', lio_rviz, '\n',
            '  显示导航 RViz: ', nav_rviz, '\n',
            '  途径点容差: ', waypoint_tolerance, 'm\n',
            '  最终目标容差: ', final_goal_tolerance, 'm\n',
        ]
    )
    
    # 启动导航系统 (bringup_sim.launch.py)
    nav_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([rm_nav_bringup_dir, 'launch', 'bringup_sim.launch.py'])
        ),
        launch_arguments={
            'world': world,
            'mode': mode,
            'lio': lio,
            'localization': localization,
            'lio_rviz': lio_rviz,
            'nav_rviz': nav_rviz,
        }.items()
    )
    
    # 启动多途径点导航器
    waypoints_navigator = Node(
        package='rm_nav_bringup',
        executable='waypoints_navigator',
        name='waypoints_navigator',
        output='screen',
        parameters=[
            {'waypoint_tolerance': waypoint_tolerance},
            {'final_goal_tolerance': final_goal_tolerance},
        ],
        remappings=[
            ('/set_waypoints', '/set_waypoints'),
            ('/navigate_to_pose', '/navigate_to_pose'),
            ('/controller_server/set_parameters', '/controller_server/set_parameters'),
        ]
    )
    
    # ==================== 返回启动描述 ====================
    
    return LaunchDescription([
        # 声明参数
        world_arg,
        mode_arg,
        lio_arg,
        localization_arg,
        lio_rviz_arg,
        nav_rviz_arg,
        waypoint_tolerance_arg,
        final_goal_tolerance_arg,
        
        # 日志输出
        log_info_1,
        log_info_2,
        
        # 启动节点
        nav_launch,
        waypoints_navigator,
    ])
