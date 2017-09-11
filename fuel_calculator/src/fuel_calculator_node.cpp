#include <ros/ros.h>
#include <fuel_calculator/fuel_calculator.h>

int main(int argc, char** argv)
{
  ros::init(argc,argv,"fuel_calc_node");
  ros::NodeHandle nh;

  fuel_calc::fuelCalc Hello;

  ros::spin();

  return 0;

}
