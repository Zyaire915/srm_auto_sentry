# EventData.msg

# --- 补给区状态 ---
uint8 supply_zone_non_overlap      # 己方与资源区不重叠的补给区
uint8 supply_zone_overlap          # 己方与资源区重叠的补给区
uint8 supply_zone_rmul             # 己方补给区占领状态 (仅 RMUL)

# --- 能量机关状态 ---
uint8 small_energy_status          # 己方小能量机关状态
uint8 big_energy_status            # 己方大能量机关状态

# --- 高地占领状态 ---
uint8 central_highland_status      # 环形/中央高地占领状态
uint8 trapezoidal_highland_status  # 己方梯形高地占领状态

# --- 飞镖相关 ---
uint16 dart_last_hit_time          # 对方飞镖最后一次击中时间
uint8 dart_last_hit_target         # 对方飞镖最后一次击中目标

# --- 增益点状态 ---
uint8 center_gain_point_status     # 中心增益点 (仅 RMUL)
uint8 fortress_gain_point_status   # 己方堡垒增益点
uint8 outpost_gain_point_status    # 己方前哨站增益点
uint8 base_gain_point_status       # 己方基地增益点