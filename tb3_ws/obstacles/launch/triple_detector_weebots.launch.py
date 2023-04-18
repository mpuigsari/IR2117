from launch import LaunchDescription 
from launch_ros.actions import Node
import launch.actions

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='obstacles',
            executable='detector',
            namespace='front',
            parameters=[
                {"obs_angle_min": -0.2785},
                {"obs_angle_max": 0.2785},
                {"obs_threshold": 0.4}]
            ),
            Node(
            package='obstacles',
            executable='detector',
            namespace='right',
            parameters=[
                {"obs_angle_min": -0.2785},
                {"obs_angle_max": -0.1989},
                {"obs_threshold": 0.4}]
            ),
            Node(
            package='obstacles',
            executable='detector',
            namespace='left',
            parameters=[
                {"obs_angle_min": 0.1989},
                {"obs_angle_max": 0.2785},
                {"obs_threshold": 0.4}]
            )
        ])
