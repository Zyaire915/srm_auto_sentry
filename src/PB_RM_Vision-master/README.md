# 北极熊视觉系统

> 本项目为北极熊视觉系统，基于 ROS2 实现不同兵种所需的视觉功能。

日前迁移了 rm_vision 进入系统，实现了装甲板瞄准功能，现在正在开发能量机关识别以及矿物拾取和兑换识别。

## 一. 环境搭建与编译

```sh
rosdep install --from-paths src --ignore-src -r -y
sudo apt install ros-humble-serial-driver
```

```sh
git clone https://gitee.com/SMBU-POLARBEAR/PB_RM_Vision
cd PB_RM_Vision
```

```sh
colcon build --symlink-install
```

## 二. 使用帮助

### 1.1 启动所有模块

以下为可供选择的 launch 文件和说明

<!-- markdownlint-disable MD033 -->

- <details>

    <summary>rm_vision</summary>

    仅包括 `装甲板识别` 模块

    ```sh
    sudo chmod 777 /dev/ttyACM0

    source install/setup.bash
    ros2 launch rm_vision_bringup vision_bringup.launch.py
    ```

  </details>

<!-- markdownlint-enable MD033 -->

- 步兵：包括 `装甲板识别` 和 `能量机关识别` 模块

  ```sh
  sudo chmod 777 /dev/ttyACM0

  source install/setup.bash
  ros2 launch rm_vision_bringup infantry_bringup.launch.py
  ```

- 英雄：包括 `装甲板识别` 模块

  ```sh
  sudo chmod 777 /dev/ttyACM0

  source install/setup.bash
  ros2 launch rm_vision_bringup hero_bringup.launch.py
  ```

- 工程：包括`兑换站识别`和`矿石识别`模块

- 哨兵：包括`装甲板识别`模块

### 1.2 启动可视化

```sh
source install/setup.bash
ros2 launch foxglove_bridge foxglove_bridge_launch.xml port:=8765
```

### 1.3 单独运行子模块

一般用不上，写在这只为了有时开发要调用 rv 独立模块调试

- 自瞄模块

    ```sh
    source install/setup.bash
    ros2 launch auto_aim_bringup auto_aim.launch.py 
    ```

- 海康相机模块

    ```sh
    source install/setup.bash
    ros2 launch hik_camera hik_camera.launch.py
    ```

- 串口模块

    ```sh
    sudo chmod 777 /dev/ttyACM0

    source install/setup.bash
    ros2 launch rm_serial_driver serial_driver.launch.py
    ```

- 能量机关识别模块

    ```sh
    source install/setup.bash
    ros2 launch rm_rune_detector rm_rune_detector.launch.py
    ```

## 三. 相关信息

### 3.1 通讯协议

详见：[README (rm_serial_driver)](/src/rm_serial_driver/README.md)

## 其他文档

rm_vision 部署文档： [部署华师视觉项目](https://flowus.cn/lihanchen/share/0d472992-f136-4e0e-856f-89328e99c684) 

测算相机畸变与内参矩阵：[相机标定](https://flowus.cn/lihanchen/share/02a518a0-f1bb-47a5-8313-55f75bab21b5)
