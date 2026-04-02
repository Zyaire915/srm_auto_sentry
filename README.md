# RM2024_SMBU_auto_sentry_ws

深圳北理莫斯科大学北极熊战队 Robomaster 2024 赛季 自动哨兵上位机算法

## 项目结构

1. rm_decision_ws

    分支： `master`

    决策模块，与其他模块存在依赖关系。可在仿真环境中进行决策预设的开发。

2. rm_vision_ws

    分支： `sentry`

    视觉模块，从 [rm_vision](https://gitlab.com/rm_vision) 开源修改而来。

3. rm_navigaion_ws

    分支： `RM2024_SMBU_auto_sentry`

    导航模块，实现了 Sim2Real。
