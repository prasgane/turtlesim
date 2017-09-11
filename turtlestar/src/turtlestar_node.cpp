#include <ros/ros.h>
#include <turtlestar/turtlestar.h>

int main(int argc, char** argv)
{
  ros::init(argc,argv,"turtle_star_node");
  ros::NodeHandle nh;

  turtle_star::turtleStar Hello;

  ros::spin();

  return 0;

}
