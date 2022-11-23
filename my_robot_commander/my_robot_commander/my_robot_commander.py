from geometry_msgs.msg import PoseStamped
from nav2_simple_commander.robot_navigator import BasicNavigator, TaskResult
import rclpy
from rclpy.node import Node
from rclpy.duration import Duration

def main():
    rclpy.init()

    navigator = BasicNavigator()


    initial_pose = PoseStamped()
    initial_pose.header.frame_id = 'map'
    initial_pose.header.stamp = navigator.get_clock().now().to_msg()
    initial_pose.pose.position.x = -5.8
    initial_pose.pose.position.y = 7.5
    navigator.setInitialPose(initial_pose)
    navigator.waitUntilNav2Active()

    goal_pose_x = [-3.0, -5.8]
    goal_pose_y = [7.0, 7.5]

    j = 0
    size = len(goal_pose_x)
   
    goal_pose = PoseStamped()
    goal_pose.header.frame_id = 'map'
    goal_pose.header.stamp = navigator.get_clock().now().to_msg()

    while rclpy.ok():
        while j < size:
            goal_pose.pose.position.x = goal_pose_x[j]
            goal_pose.pose.position.y = goal_pose_y[j]
            navigator.goToPose(goal_pose)
            result = navigator.getResult()

            if navigator.isTaskComplete():
                j = j+1
                print(str(j))
                print(size)
                if(j == size):
                    j = 0
            
            if result == TaskResult.SUCCEEDED:
                print('goal succeeded')
                
            elif result == TaskResult.FAILED:
                print('Failed!')

if __name__ == '__main__':
    main()
