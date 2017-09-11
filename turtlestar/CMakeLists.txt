cmake_minimum_required(VERSION 2.8.3)
project(turtlestar)

find_package(catkin REQUIRED COMPONENTS
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

add_executable(turtle_star_node
              src/turtlestar_node.cpp
              src/turtlestar.cpp)

target_link_libraries(turtle_star_node # This links up the node with the compiled libraries catkin knows about
                ${catkin_LIBRARIES}                    # Basically, it allows the node to leverage ROS libraries.
              )
