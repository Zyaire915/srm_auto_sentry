#!/bin/bash

###############################################################################
#                    多途径点导航一键启动脚本
#
# 功能: 快速启动多途径点导航系统
# 用法: ./start_waypoints_nav.sh [preset|custom] [参数...]
#
# 示例:
#   ./start_waypoints_nav.sh fast      # 快速导航
#   ./start_waypoints_nav.sh precise   # 精密导航
#   ./start_waypoints_nav.sh custom    # 自定义参数
###############################################################################

set -e

# 颜色定义
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# 工作空间路径
WORKSPACE_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# 预设配置
declare -A PRESETS

# 快速导航配置
PRESETS[fast]="
world=RMUL
mode=nav
lio=fastlio
localization=slam_toolbox
lio_rviz=False
nav_rviz=True
waypoint_tolerance=1.5
final_goal_tolerance=0.5
"

# 标准导航配置
PRESETS[standard]="
world=RMUL
mode=nav
lio=fastlio
localization=slam_toolbox
lio_rviz=False
nav_rviz=True
waypoint_tolerance=1.0
final_goal_tolerance=0.25
"

# 精密导航配置
PRESETS[precise]="
world=RMUL
mode=nav
lio=fastlio
localization=slam_toolbox
lio_rviz=False
nav_rviz=True
waypoint_tolerance=0.5
final_goal_tolerance=0.1
"

# 点云调试配置
PRESETS[debug]="
world=RMUL
mode=nav
lio=fastlio
localization=slam_toolbox
lio_rviz=True
nav_rviz=True
waypoint_tolerance=1.0
final_goal_tolerance=0.25
"

# RMUC 地图配置
PRESETS[rmuc]="
world=RMUC
mode=nav
lio=fastlio
localization=slam_toolbox
lio_rviz=False
nav_rviz=True
waypoint_tolerance=1.0
final_goal_tolerance=0.25
"

# 实车配置
PRESETS[real]="
world=best
mode=nav
lio=pointlio
localization=slam_toolbox
lio_rviz=False
nav_rviz=True
waypoint_tolerance=1.0
final_goal_tolerance=0.25
"

# 打印欢迎信息
print_header() {
    clear
    echo -e "${BLUE}"
    echo "╔══════════════════════════════════════════════════════╗"
    echo "║     多途径点导航系统 - 一键启动脚本                    ║"
    echo "║                                                      ║"
    echo "║  功能: 生成全局路线，灵活调整容差，启用 RViz 可视化   ║"
    echo "╚══════════════════════════════════════════════════════╝"
    echo -e "${NC}"
}

# 打印帮助信息
print_help() {
    echo -e "${GREEN}用法:${NC}"
    echo "  $0 [preset] [选项]"
    echo ""
    echo -e "${GREEN}预设配置:${NC}"
    echo "  fast      - 快速导航 (容差: 1.5m / 0.5m)"
    echo "  standard  - 标准导航 (容差: 1.0m / 0.25m) [默认]"
    echo "  precise   - 精密导航 (容差: 0.5m / 0.1m)"
    echo "  debug     - 调试模式 (显示点云)"
    echo "  rmuc      - RMUC 地图"
    echo "  real      - 实车配置"
    echo "  custom    - 完全自定义"
    echo ""
    echo -e "${GREEN}自定义参数:${NC}"
    echo "  world=RMUL|RMUC|best"
    echo "  mode=nav|mapping"
    echo "  lio=fastlio|pointlio"
    echo "  localization=slam_toolbox|amcl|icp"
    echo "  lio_rviz=True|False"
    echo "  nav_rviz=True|False"
    echo "  waypoint_tolerance=<值>"
    echo "  final_goal_tolerance=<值>"
    echo ""
    echo -e "${GREEN}示例:${NC}"
    echo "  $0 fast                    # 快速导航"
    echo "  $0 precise                 # 精密导航"
    echo "  $0 custom waypoint_tolerance=1.5 final_goal_tolerance=0.5"
    echo ""
}

# 验证工作空间
verify_workspace() {
    if [ ! -d "$WORKSPACE_PATH/src/rm_nav_bringup" ]; then
        echo -e "${RED}✗ 错误: 无法找到 rm_nav_bringup 包${NC}"
        echo "请确保在正确的工作空间目录中运行此脚本"
        exit 1
    fi
    echo -e "${GREEN}✓ 工作空间验证成功${NC}"
}

# 源化 ROS 环境
setup_ros_env() {
    if [ -f "$WORKSPACE_PATH/install/setup.zsh" ]; then
        echo -e "${YELLOW}加载 ROS 环境...${NC}"
        source "$WORKSPACE_PATH/install/setup.zsh"
        echo -e "${GREEN}✓ ROS 环境已加载${NC}"
    elif [ -f /opt/ros/humble/setup.zsh ]; then
        echo -e "${YELLOW}使用系统 ROS 环境...${NC}"
        source /opt/ros/humble/setup.zsh
        echo -e "${GREEN}✓ ROS 环境已加载${NC}"
    else
        echo -e "${RED}✗ 无法加载 ROS 环境${NC}"
        exit 1
    fi
}

# 构建启动命令
build_launch_command() {
    local preset=$1
    local config=""
    
    if [ -z "${PRESETS[$preset]}" ] && [ "$preset" != "custom" ]; then
        echo -e "${RED}✗ 未知的预设: $preset${NC}"
        print_help
        exit 1
    fi
    
    if [ "$preset" != "custom" ]; then
        config="${PRESETS[$preset]}"
    else
        # 自定义模式：使用预设的标准配置作为基础
        config="${PRESETS[standard]}"
    fi
    
    # 添加自定义参数
    shift
    while [ $# -gt 0 ]; do
        config="$config
$1"
        shift
    done
    
    # 清理配置字符串并构建命令
    local launch_cmd="ros2 launch rm_nav_bringup waypoints_navigator.launch.py"
    
    while IFS= read -r line; do
        line=$(echo "$line" | xargs)  # 去除前后空格
        if [ -n "$line" ] && [ "${line:0:1}" != "#" ]; then
            launch_cmd="$launch_cmd \\
    $line"
        fi
    done <<< "$config"
    
    echo "$launch_cmd"
}

# 显示配置
show_config() {
    local preset=$1
    shift
    
    echo ""
    echo -e "${BLUE}═══════════════════════════════════════${NC}"
    echo -e "${BLUE}启动配置${NC}"
    echo -e "${BLUE}═══════════════════════════════════════${NC}"
    echo ""
    
    if [ "$preset" != "custom" ]; then
        echo -e "${GREEN}预设:${NC} $preset"
    else
        echo -e "${GREEN}预设:${NC} 自定义"
    fi
    
    echo ""
    echo -e "${YELLOW}参数:${NC}"
    echo ""
    
    # 显示预设参数
    if [ "$preset" != "custom" ]; then
        while IFS= read -r line; do
            line=$(echo "$line" | xargs)
            if [ -n "$line" ]; then
                echo "  $line"
            fi
        done <<< "${PRESETS[$preset]}"
    else
        # 显示自定义参数
        while [ $# -gt 0 ]; do
            echo "  $1"
            shift
        done
    fi
    
    echo ""
    echo -e "${BLUE}═══════════════════════════════════════${NC}"
    echo ""
}

# 主函数
main() {
    print_header
    
    # 如果没有参数或参数为 help，显示帮助
    if [ $# -eq 0 ] || [ "$1" = "help" ] || [ "$1" = "-h" ] || [ "$1" = "--help" ]; then
        print_help
        
        echo -e "${BLUE}预设配置详情:${NC}"
        echo ""
        for preset_name in "${!PRESETS[@]}"; do
            echo -e "${GREEN}▶ $preset_name${NC}"
            while IFS= read -r line; do
                line=$(echo "$line" | xargs)
                if [ -n "$line" ]; then
                    echo "    $line"
                fi
            done <<< "${PRESETS[$preset_name]}"
            echo ""
        done
        
        exit 0
    fi
    
    # 验证工作空间
    verify_workspace
    
    # 源化 ROS 环境
    setup_ros_env
    
    # 获取预设名称（默认为 standard）
    local preset="${1:-standard}"
    
    # 显示配置
    show_config "$preset" "${@:2}"
    
    # 确认启动
    echo -e "${YELLOW}按 Enter 继续启动，按 Ctrl+C 取消...${NC}"
    read -r
    
    # 构建并执行启动命令
    local launch_cmd=$(build_launch_command "$preset" "${@:2}")
    
    echo ""
    echo -e "${BLUE}执行命令:${NC}"
    echo "$launch_cmd"
    echo ""
    echo -e "${GREEN}启动系统...${NC}"
    echo ""
    
    eval "$launch_cmd"
}

# 运行主函数
main "$@"
