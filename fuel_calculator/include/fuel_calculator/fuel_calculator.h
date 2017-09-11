#ifndef FUEL_CALCULATOR_H
#define FUEL_CALCULATOR_H

#include <ros/ros.h>
#include <turtlesim/Pose.h>
#include <geometry_msgs/Twist.h>
#include <math.h>
#include <std_msgs/Float32.h>
#include <turtlesim/Kill.h>

namespace fuel_calc
{

  class fuelCalc
  {
  public:
    fuelCalc();

  private:
    ros::NodeHandle nh_;
    ros::NodeHandle nh_private_;

    ros::Subscriber vel_subscriber_;
    ros::Publisher fuel_reminder_;
    ros::ServiceClient killClient;

    turtlesim::Kill::Request req;
    turtlesim::Kill::Response resp;

    void velCallback(const geometry_msgs::Twist::ConstPtr& msg);

    double start_time;
    float total_fuel, current_fuel,fuel_k;
    std_msgs::Float32 current_fuel_obj;
  };

}

#endif
