import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    config = os.path.join(
        get_package_share_directory('base_publisher'),
        'config', 'base_publisher.yaml'
    )

    return LaunchDescription([
        Node(
            package='base_publisher',
            executable='base_publisher_node',
            name='base_publisher_node',
            parameters=[config],
            output='screen',
        )
    ])
