cmake_minimum_required(VERSION 3.8)
project(manual_localization)

find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)

# Install Python package
ament_python_install_package(${PROJECT_NAME})

# Install Python scripts as executables
install(PROGRAMS
  scripts/manual_localization_node.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
