import os

from ament_index_python.packages import get_package_share_directory

from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    # Get the launch directory
    nav_launch_dir = os.path.join(
        get_package_share_directory('my_robot_navigation'), 'launch')

    robot_cmd_node = Node(
    package='my_robot_commander',
    executable='my_robot_commander',
    name='my_robot_commander',
    output='screen') 

    nav_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(nav_launch_dir, 'my_robot_navigation.launch.py')))

    # Create the launch description and populate
    ld = LaunchDescription()

    # Declare the launch options
    ld.add_action(nav_launch)
    ld.add_action(robot_cmd_node)

    return ld