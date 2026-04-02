# ROS2的使用
- [ROS2的使用](#ros2的使用)
- [新建软件包](#新建软件包)
  - [编辑CMakeLists.txt](#编辑cmakeliststxt)
  - [编辑package.xml](#编辑packagexml)
- [编译项目](#编译项目)
- [报错](#报错)
  - [编辑器找不到ROS2头文件](#编辑器找不到ros2头文件)
  - [undefined symbol](#undefined-symbol)

# 新建软件包
在ROS2中，你可以使用 `ros2 pkg create` 命令来创建一个新的C++软件包。

如通过以下代码创建一个名为rm_rune_detector的新软件包的示例，该软件包依赖于rclcpp和std_msgs
```shell
ros2 pkg create --build-type ament_cmake rm_rune_detector --dependencies rclcpp std_msgs
```
这将在当前目录下创建一个名为`rm_rune_detector`的新目录，其中包含了一个基本的ROS2软件包结构，以及一个`CMakeLists.txt`文件，该文件已经配置好了对`rclcpp`和`std_msgs`的依赖。

你可以根据需要修改这个命令，将rm_rune_detector替换为你想要的软件包名，将rclcpp和std_msgs替换为你的软件包所依赖的其他ROS2软件包。

## 编辑CMakeLists.txt
`CMakeLists.txt`用于配置如何构建、编译项目

以下是一个示例，主要要修改`Build`部分的内容(`ament_auto_add_library`和`rclcpp_components_register_node`)
```cmake
cmake_minimum_required(VERSION 3.10)
project(rm_rune_detector)

## Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## By adding -Wall and -Werror, the compiler does not ignore warnings anymore,
## enforcing cleaner code.
add_definitions(-Wall -Werror)

## Export compile commands for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#######################
## Find dependencies ##
#######################

find_package(ament_cmake_auto REQUIRED)
ament_auto_find_build_dependencies()

###########
## Build ##
###########

ament_auto_add_library(${PROJECT_NAME} SHARED
  src/rm_rune_detector.cpp
)

rclcpp_components_register_node(${PROJECT_NAME}
  PLUGIN rm_rune_detector::RMRuneDetector
  EXECUTABLE ${PROJECT_NAME}_node
)

#############
## Testing ##
#############

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  list(APPEND AMENT_LINT_AUTO_EXCLUDE
    ament_cmake_copyright
    ament_cmake_uncrustify
  )
  ament_lint_auto_find_test_dependencies()
endif()

#############
## Install ##
#############

ament_auto_package(
  INSTALL_TO_SHARE
  launch
)
```

## 编辑package.xml
`package.xml`用于定义包的基本信息和依赖关系。

通过编辑`depend`内容来定义依赖关系。
```xml
<depend></depend>
```


# 编译项目
使用 `colcon build` 来编译项目
> Tip:使用`--symlink-install`命令可以创建配置文件的链接，这样在更改配置文件后可以不用重新编译。

如使用以下命令编译项目

```shell
colcon build --symlink-install
```

# 报错
## 编辑器找不到ROS2头文件
有时候会发现如下的ROS头文件会被加上下划波浪线并显示找不到

```
#include <rclcpp/publisher.hpp>
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/subscription.hpp>
```

点击 `快速修复` - `编辑includePath` 后找到 `包含路径`，并增加一行添加以下内容（其中humble为安装的ROS版本）

```
/opt/ros/humble/**
```
## undefined symbol
形如以下报错，估计是cmakelist编写问题导致部分文件没有被编译。
```shell
[rm_rune_detector_node-3] /home/polarbear/Desktop/Polarbear_Vision_ws/PB_RM_Vision/install/rm_rune_detector/lib/rm_rune_detector/rm_rune_detector_node: symbol lookup error: /home/polarbear/Desktop/Polarbear_Vision_ws/PB_RM_Vision/install/rm_rune_detector/lib/librm_rune_detector.so: undefined symbol: _ZN16rm_rune_detector9PnPSolverC1ERKSt5arrayIdLm9EERKSt6vectorIdSaIdEE
```
将`ament_auto_add_library`中的文件
```cmake
ament_auto_add_library(${PROJECT_NAME} SHARED
  src/rm_rune_detector.cpp
)
```
改为`src`文件夹即可。
```cmake
ament_auto_add_library(${PROJECT_NAME} SHARED
  DIRECTORY src
)
```