cmake_minimum_required(VERSION 3.8)
project(standard_robot_pp_ros2)

# 编译器选项
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 1. 查找依赖
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_components REQUIRED)
find_package(serial_driver REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(pb_rm_interfaces REQUIRED)
find_package(rm_decision_interfaces REQUIRED)

# 2. 生成共享库
add_library(${PROJECT_NAME} SHARED
  src/standard_robot_pp_ros2.cpp
  src/crc_func.c
)

# 【关键修复】指定头文件包含目录
# 这一步告诉编译器：在编译当前项目时，去 include/ 目录下找 .hpp/.h 文件
target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# 添加依赖
ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  rclcpp_components
  serial_driver
  tf2_ros
  tf2_geometry_msgs
  geometry_msgs
  sensor_msgs
  example_interfaces
  pb_rm_interfaces
  rm_decision_interfaces
)

# 3. 注册组件并生成可执行文件
rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN standard_robot_pp_ros2::StandardRobotPpRos2Node
  EXECUTABLE ${PROJECT_NAME}_node
)

# 4. 安装目标
install(TARGETS ${PROJECT_NAME} ${PROJECT_NAME}_node
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION lib/${PROJECT_NAME}
)

# 5. 安装头文件 (导出给其他包使用)
install(DIRECTORY include/
  DESTINATION include
)

# 6. 安装配置文件和启动文件
install(DIRECTORY
  config
  launch
  DESTINATION share/${PROJECT_NAME}
)

ament_package()