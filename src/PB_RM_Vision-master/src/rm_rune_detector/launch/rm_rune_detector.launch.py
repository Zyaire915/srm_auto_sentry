from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():

    rm_rune_detector_node = Node(
            package='rm_rune_detector',
            executable='rm_rune_detector_node',
            name='rm_rune_detector_node',
            output='screen',
        )

    return LaunchDescription([rm_rune_detector_node])