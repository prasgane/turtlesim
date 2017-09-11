cmake_minimum_required(VERSION 2.8.3)
project(pystar)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  turtlesim
)

## Declare a catkin package
catkin_package()


catkin_install_python(PROGRAMS
  scripts/turtlestar.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})
