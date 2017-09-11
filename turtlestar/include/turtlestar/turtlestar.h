#ifndef TURTLESTAR_H
#define TURTLESTAR_H

#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>

namespace turtle_star
{

class turtleStar
{
public:
  turtleStar();

private:

  ros::NodeHandle nh_;
  ros::NodeHandle nh_private_;

  ros::Subscriber pose_subscriber_; // subscribe to the pose of turtlesim

  ros::Publisher velocity_command_publisher_; //pusblishes the velocity commands
  turtlesim::Pose current_pose;

  float lin_vel_2, ang_vel_1,ang_vel_2, lin_time, ang_time,lin_vel_1;

  void poseCallback(const turtlesim::PoseConstPtr &msg); //callback function for
  //the pose
  ros::Time start_time;
  void velocity_calculator(); //calculates the velocity

};

}

#endif
