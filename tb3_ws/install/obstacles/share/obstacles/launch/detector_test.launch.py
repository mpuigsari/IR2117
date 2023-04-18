from launch import LaunchDescription
from launch_ros.actions import Node
import launch.actions

def generate_launch_description():
    return LaunchDescription([
        launch.actions.DeclareLaunchArgument('bagfile'),
        launch.action.ExecuteProcess(
            cmd=['ros2','bag', 'play',
                launch.sustitutions.LaunchConfiguration('bagfile')],
            output='screen'),
        Node(
            package='obstacles',
            executable='detector')])
