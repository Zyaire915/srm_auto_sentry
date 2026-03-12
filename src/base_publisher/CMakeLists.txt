cmake_minimum_required(VERSION 3.8)
project(base_publisher)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

add_executable(base_publisher_node src/base_publisher_node.cpp)
ament_target_dependencies(base_publisher_node
  rclcpp
  geometry_msgs
  tf2_ros
  tf2_geometry_msgs
)

install(TARGETS base_publisher_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY config launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
