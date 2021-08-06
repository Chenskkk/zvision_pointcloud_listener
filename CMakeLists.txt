cmake_minimum_required(VERSION 2.7.1)
project(zvision_pointcloud_listener)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(PCL 1.8 REQUIRED)
if( PCL_FOUND )
    include_directories( ${PCL_INCLUDE_DIRS} )
    add_definitions( ${PCL_DEFINITIONS} )
    link_directories( ${PCL_LIBRARY_DIRS} )
endif()


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
)

catkin_package()


include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node src/zvision_pointcloud_listener_node.cpp)


target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES} ${PCL_LIBRARIES}
)
