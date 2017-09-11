cmake_minimum_required(VERSION 2.8.3)
project(fuel_calculator)


find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
  turtlesim
)

catkin_package()

include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(fuel_calc_node
              src/fuel_calculator_node.cpp
              src/fuel_calculator.cpp)

target_link_libraries(fuel_calc_node # This links up the node with the compiled libraries catkin knows about
                ${catkin_LIBRARIES}                    # Basically, it allows the node to leverage ROS libraries.
              )
