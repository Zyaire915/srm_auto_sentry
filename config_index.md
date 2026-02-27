# 雷达
- [主配置文件](src/pb_rmsimulation/src/rm_nav_bringup/config/reality/MID360_config.json)
  `timestamp_type` 为新增字段 尝试统一硬件软件时间 减少tf delay
  使用ptp则加入 `"sync_type": "ptp",`      // 强制指定为 ptp
  ip ：`lidar_configs` - `ip`

- 测量机器人底盘正中心到雷达的相对坐标

    x, y 距离比较重要，将影响云台旋转时解算到 base_link 的坐标准确性

    填入 [measurement_params_real.yaml](./src/rm_nav_bringup/config/reality/measurement_params_real.yaml)

    若雷达倾斜放置，无需在此处填入 rpy，而是将点云旋转角度填入 [MID360_config.json](./src/rm_nav_bringup/config/reality/MID360_config.json) - `extrinsic_parameter`

- 测量雷达与地面的垂直距离

    此参数影响点云分割效果

    填入 [segmentation_real.yaml](./src/rm_nav_bringup/config/reality/segmentation_real.yaml) - `sensor_height`


- [imu、tf相关配置文件](src/pb_rmsimulation/src/rm_nav_bringup/config/reality/fastlio_mid360_real.yaml)
  `time_sync_en: false` 在使用ptp硬件时间时开启
  

# 局部路径规划
- [主配置文件](src/pb_rmsimulation/src/rm_navigation/teb_local_planner/teb_local_planner/params/teb_params.yaml)


# nav2
- [主配置文件](src/pb_rmsimulation/src/rm_nav_bringup/config/reality/nav2_params_real.yaml)
- 参数很多，比较重要的是 robot_radius 和 速度相关参数。详见 [nav2官方文档](https://docs.nav2.org/)

# rm_simulation  
[README](src/pb_rmsimulation/README.md)

# FAST_LIO
[README](src/pb_rmsimulation/src/rm_localization/FAST_LIO/README.md)

