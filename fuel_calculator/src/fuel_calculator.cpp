#include "fuel_calculator/fuel_calculator.h"

namespace fuel_calc
{
  fuelCalc::fuelCalc() :
    nh_(ros::NodeHandle()),
    nh_private_(ros::NodeHandle("~"))
    {

      vel_subscriber_ = nh_.subscribe<geometry_msgs::Twist>
                        ("/turtle1/cmd_vel",10, &fuelCalc::velCallback, this);
      fuel_reminder_ = nh_.advertise<std_msgs::Float32>
                        ("/fuel_reminder",10,this);
      killClient = nh_private_.serviceClient<turtlesim::Kill>("kill");

      nh_private_.param<float>("initial_fuel",total_fuel,100.0);
      nh_private_.param<float>("fuel_const",fuel_k,0.10);
      start_time = ros::Time::now().toSec();
      current_fuel = total_fuel;
      req.name = "turtle1";

    }

  void fuelCalc::velCallback(const geometry_msgs::Twist::ConstPtr& msg)
  {

    float t;
    float mag_lin, mag_ang, fuel_spent;

    mag_lin = sqrt( pow(msg->linear.x,2.0) + pow(msg->linear.y,2.0) + pow(msg->linear.z,2.0) );
    mag_ang = sqrt( pow(msg->angular.x,2.0) + pow(msg->angular.y,2.0) + pow(msg->angular.z,2.0) );
    t = ros::Time::now().toSec() - start_time;

    fuel_spent =  t * (mag_lin  + mag_ang)   ;//exp(mag_lin*t) + exp(mag_ang*t);
    current_fuel = current_fuel - (fuel_spent * fuel_k);



    if(current_fuel > 0)
        ROS_INFO("Current Fuel Level is at %f", current_fuel);
    else
    {
      bool success = killClient.call(req,resp);
      ROS_INFO("Out of Fuel. Turtle is DEAD!! %d",success);
    }


    current_fuel_obj.data = current_fuel;
    fuel_reminder_.publish(current_fuel_obj);


  }


}
