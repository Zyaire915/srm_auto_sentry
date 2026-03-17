cmake_minimum_required(VERSION 3.8)
project(rm_nav_bringup)

if(CMAKE_EXPORT_COMPILE_COMMANDS)
  set(CMAKE_EXPORT_COMPILE_COMMANDS ${CMAKE_EXPORT_COMPILE_COMMANDS})
endif()

find_package(ament_cmake REQUIRED)

# 在源文件中设置可执行权限
file(CHMOD 
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/waypoints_navigator.py 
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/waypoints_test_client.py
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/single_plan_navigator.py
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/waypoints_navigator_fixed.py
  ${CMAKE_CURRENT_SOURCE_DIR}/scripts/diagnose_replanning.py
  FILE_PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

# 安装 Python 脚本（标记为可执行）
install(
  PROGRAMS
    scripts/waypoints_navigator.py
    scripts/waypoints_test_client.py
    scripts/single_plan_navigator.py
    scripts/waypoints_navigator_fixed.py
    scripts/diagnose_replanning.py
  DESTINATION lib/${PROJECT_NAME}
)

# 创建不带扩展名的符号链接以支持 ros2 run
install(
  CODE "
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E create_symlink 
      waypoints_navigator.py 
      \${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}/waypoints_navigator
    )
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E create_symlink 
      waypoints_test_client.py 
      \${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}/waypoints_test_client
    )
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E create_symlink 
      single_plan_navigator.py 
      \${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}/single_plan_navigator
    )
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E create_symlink 
      waypoints_navigator_fixed.py 
      \${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}/waypoints_navigator_fixed
    )
    execute_process(
      COMMAND ${CMAKE_COMMAND} -E create_symlink 
      diagnose_replanning.py 
      \${CMAKE_INSTALL_PREFIX}/lib/${PROJECT_NAME}/diagnose_replanning
    )
  "
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# 安装其他资源
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})
install(DIRECTORY config DESTINATION share/${PROJECT_NAME})
install(DIRECTORY map DESTINATION share/${PROJECT_NAME})
install(DIRECTORY PCD DESTINATION share/${PROJECT_NAME})
install(DIRECTORY rviz DESTINATION share/${PROJECT_NAME})
install(DIRECTORY urdf DESTINATION share/${PROJECT_NAME})

ament_package()

