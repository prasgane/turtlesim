#include "turtlestar/turtlestar.h"

namespace turtle_star
{
  turtleStar::turtleStar() :
    nh_(ros::NodeHandle()),
    nh_private_(ros::NodeHandle("~"))
  {
    pose_subscriber_ = nh_.subscribe<turtlesim::Pose>
                        ("/turtle1/pose",10, &turtleStar::poseCallback, this);

    velocity_command_publisher_ = nh_.advertise<geometry_msgs::Twist>
                                  ("/turtle1/cmd_vel",10,this);

    start_time = ros::Time::now();
  }

  void turtleStar::poseCallback(const turtlesim::PoseConstPtr &msg)
  {
    current_pose = *msg;
    ROS_INFO("got message %d \n",int(lin_vel_1));
    velocity_calculator();
  }

  void turtleStar::velocity_calculator()
  {

    nh_private_.param<float>("linear_vel_1",lin_vel_1,0.01);
    nh_private_.param<float>("linear_vel_2",lin_vel_2,0.01);
    nh_private_.param<float>("angular_vel_1",ang_vel_1,0.01);
    nh_private_.param<float>("angular_vel_2",ang_vel_2,0.01);
    geometry_msgs::Twist cmd_vel;
    //ros::Time f_time = ros::time::now();
    if(ros::Time::now() - start_time <= ros::Duration(3))
      cmd_vel.linear.x = lin_vel_2;
    else if(ros::Time::now() - start_time > ros::Duration(3) && (ros::Time::now() - start_time <= ros::Duration(4)))
      cmd_vel.angular.z = ang_vel_1;
    else if(ros::Time::now() - start_time > ros::Duration(4) && (ros::Time::now() - start_time <= ros::Duration(7)))
      cmd_vel.linear.x = lin_vel_1;
    else if(ros::Time::now() - start_time > ros::Duration(7) && (ros::Time::now() - start_time <= ros::Duration(8)))
      cmd_vel.angular.z = ang_vel_2;
    else if(ros::Time::now() - start_time > ros::Duration(8) && (ros::Time::now() - start_time <= ros::Duration(11)))
      cmd_vel.linear.x = lin_vel_1;
    else if(ros::Time::now() - start_time > ros::Duration(11) && (ros::Time::now() - start_time <= ros::Duration(12)))
      cmd_vel.angular.z = ang_vel_1;
    else if(ros::Time::now() - start_time > ros::Duration(12) && (ros::Time::now() - start_time <= ros::Duration(15)))
      cmd_vel.linear.x = lin_vel_1;
    else if(ros::Time::now() - start_time > ros::Duration(15) && (ros::Time::now() - start_time <= ros::Duration(16)))
      cmd_vel.angular.z = ang_vel_2;
    else if(ros::Time::now() - start_time > ros::Duration(16) && (ros::Time::now() - start_time <= ros::Duration(19)))
      cmd_vel.linear.x = lin_vel_1;
    else{
      cmd_vel.angular.z = 0;
      cmd_vel.linear.x = 0;
    }
    velocity_command_publisher_.publish(cmd_vel);


  }//function




}//namespace
