#!/usr/bin/env python

import rospy
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose

class turtle_star():



    def __init__(self):
        rospy.init_node('turtle_pystar')
        self.pose_subscriber_ = rospy.Subscriber("/turtle1/pose",Pose,self.poseCallback)
        self.velocity_publisher = rospy.Publisher('/turtle1/cmd_vel', Twist, queue_size=10)
        self.start_time = rospy.get_rostime()
        self.rate = rospy.Rate(10)
        self.current_pose = Pose()
        self.lin_vel = rospy.get_param('~linear_vel_1',1)
        self.ang_vel = rospy.get_param('~angular_vel_1',1)
        init_message = rospy.get_param('~message', 'hello')


    def poseCallback(self,msg):
        self.current_pose = msg;
        #rospy.loginfo('I got the message')



    def velocity_calculator(self):
        now = rospy.get_rostime()
        cmd_vel = Twist()
        #rospy.loginfo("Current time %i",self.ang_vel)
        while now.secs - self.start_time.secs <= 20 and not rospy.is_shutdown():
            now = rospy.get_rostime()
            timeDiff = now.secs - self.start_time.secs
            #rospy.loginfo("Inside While %i", now.secs - self.start_time.secs)
            if timeDiff <= 3:
                cmd_vel.linear.x = self.lin_vel
            elif timeDiff >= 3 and timeDiff <= 4 :
                cmd_vel.angular.z = self.ang_vel
                cmd_vel.linear.x = 0
            elif timeDiff >= 4 and timeDiff <= 7 :
                cmd_vel.linear.x = self.lin_vel
                cmd_vel.angular.z = 0
            elif timeDiff >= 7 and timeDiff <= 8 :
                cmd_vel.angular.z = self.ang_vel
                cmd_vel.linear.x = 0
            elif timeDiff >= 8 and timeDiff <= 11 :
                cmd_vel.linear.x = self.lin_vel
                cmd_vel.angular.z = 0
            elif timeDiff >= 11 and timeDiff <= 12 :
                cmd_vel.angular.z = self.ang_vel
                cmd_vel.linear.x = 0
            elif timeDiff >= 12 and timeDiff <= 15 :
                cmd_vel.linear.x = self.lin_vel
                cmd_vel.angular.z = 0
            elif timeDiff >= 15 and timeDiff <= 16 :
                cmd_vel.angular.z = self.ang_vel
                cmd_vel.linear.x = 0
            elif timeDiff >= 16 and timeDiff <= 19 :
                cmd_vel.linear.x = self.lin_vel
                cmd_vel.angular.z = 0
            else:
                cmd_vel.angular.z = 0
                cmd_vel.linear.x = 0
            self.velocity_publisher.publish(cmd_vel)




        rospy.spin()


if __name__ == '__main__':
    try:
        mainObj = turtle_star()
        mainObj.velocity_calculator()
    except rospy.ROSInterruptException:
        pass
