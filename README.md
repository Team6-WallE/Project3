# Project3
#### Use my_robot_description. Only this works as the other one movement is wrong
#### To launch in gazebo follow the command: 
      ros2 launch my_robot_description gazebo.launch.py
#### To launch in rviz follow the command: 
      ros2 launch my_robot_description display.launch.py
#### To move the robot in gazebo follow the command: 
      ros2 run teleop_twist_keyboard teleop_twist_keyboard
#### Note: For the robot to move in gazebo, you need to click on the play button at the bottom of the screen. Then the robot will move.

#### All necessary sensors have been setup
#### Topics:
      1. cmd_vel: to see the velocity of robot
      2. imu: to see robot position
      3. scan: to see sensor data (lidar)
      

----------------------------------------------Updates-------------------------------------------------------------------
#### 14/11/22
- Added level5 model, world,launch file
- Currently cannot launch a custom world in conjunction with robot. World issue(?) 
