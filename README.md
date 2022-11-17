# Project3
#### Use my_robot_description. Only this works as the other one movement is wrong
#### To launch in gazebo follow the command: 
      ros2 launch my_robot_description gazebo.launch.py
#### To launch in rviz follow the command: 
      ros2 launch my_robot_description display.launch.py
#### To move the robot in gazebo follow the command: 
      ros2 run teleop_twist_keyboard teleop_twist_keyboard
#### To check if odomtery is runnng smoothly follow the command:
      ros2 launch my_robot_description level5.launch.py
      ros2 topic list
      ros2 topic info /my_robot/imu
      ros2 topic info /my_robot/odom
#### Check if these 2 topics have 1 publisher and 1 subscrciber
      ros2 node info /ekf_filter_node
#### Check the output seen on terminal against the output shown below:
           /ekf_filter_node
      Subscribers:
        /demo/imu: sensor_msgs/msg/Imu
        /demo/odom: nav_msgs/msg/Odometry
        /parameter_events: rcl_interfaces/msg/ParameterEvent
        /set_pose: geometry_msgs/msg/PoseWithCovarianceStamped
      Publishers:
        /accel/filtered: geometry_msgs/msg/AccelWithCovarianceStamped
        /diagnostics: diagnostic_msgs/msg/DiagnosticArray
        /odometry/filtered: nav_msgs/msg/Odometry
        /parameter_events: rcl_interfaces/msg/ParameterEvent
        /rosout: rcl_interfaces/msg/Log
        /tf: tf2_msgs/msg/TFMessage
      Service Servers:
#### Run the following command and check against the frames.pdf
      ros2 run tf2_tools view_frames


----------------------------------------------Updates-------------------------------------------------------------------
#### Changes made to files
      1. package.xml: added robot_localization dependencies
      2. my_robot.xacro: added base_footprint link and base_joint join
      3. my_robot.gazebo: created a ros namespace "/my_robot" 
      4. config folder: created a new ekf.yaml file to fuse the odometry information given by the sensors through the use of state estimation nodes.
                        It can also publish the odom => base_link transform on the /tf topic.
      5. level5.launch.py: added a robot_localization node

