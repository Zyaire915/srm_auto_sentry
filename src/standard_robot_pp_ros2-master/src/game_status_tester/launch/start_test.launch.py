from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='game_status_tester',
            executable='test_node',
            name='game_status_test_node',
            output='screen',
            parameters=[],
            # 如果需要重映射话题，可以在这里添加
            # remappings=[
            #     ('/cmd_vel', '/your_robot/cmd_vel'),
            # ]
        )
    ])