# CMake generated Testfile for 
# Source directory: /workspaces/auto_sentry/src/standard_robot_pp_ros2-master/src/BehaviorTree.CPP/tests
# Build directory: /workspaces/auto_sentry/build/behaviortree_cpp/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(behaviortree_cpp_test "/usr/bin/python3" "-u" "/opt/ros/humble/share/ament_cmake_test/cmake/run_test.py" "/workspaces/auto_sentry/build/behaviortree_cpp/test_results/behaviortree_cpp/behaviortree_cpp_test.gtest.xml" "--package-name" "behaviortree_cpp" "--output-file" "/workspaces/auto_sentry/build/behaviortree_cpp/ament_cmake_gtest/behaviortree_cpp_test.txt" "--command" "/workspaces/auto_sentry/build/behaviortree_cpp/tests/behaviortree_cpp_test" "--gtest_output=xml:/workspaces/auto_sentry/build/behaviortree_cpp/test_results/behaviortree_cpp/behaviortree_cpp_test.gtest.xml")
set_tests_properties(behaviortree_cpp_test PROPERTIES  LABELS "gtest" REQUIRED_FILES "/workspaces/auto_sentry/build/behaviortree_cpp/tests/behaviortree_cpp_test" TIMEOUT "60" WORKING_DIRECTORY "/workspaces/auto_sentry/build/behaviortree_cpp/tests" _BACKTRACE_TRIPLES "/opt/ros/humble/share/ament_cmake_test/cmake/ament_add_test.cmake;125;add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest_test.cmake;86;ament_add_test;/opt/ros/humble/share/ament_cmake_gtest/cmake/ament_add_gtest.cmake;93;ament_add_gtest_test;/workspaces/auto_sentry/src/standard_robot_pp_ros2-master/src/BehaviorTree.CPP/tests/CMakeLists.txt;41;ament_add_gtest;/workspaces/auto_sentry/src/standard_robot_pp_ros2-master/src/BehaviorTree.CPP/tests/CMakeLists.txt;0;")
subdirs("../gtest")
