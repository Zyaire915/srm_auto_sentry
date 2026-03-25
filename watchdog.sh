#!/bin/zsh

# 进入目标目录
TARGET_DIR="/home/srm"
SCRIPT_NAME="./start_robomaster.sh"

cd "$TARGET_DIR" || exit 1

MAX_RETRY=100
RETRY_COUNT=0

cleanup() {
    echo "检测到终止信号，正在清理子进程..."
    # 杀死由本脚本启动的所有子进程
    pkill -P $$ 
    exit 0
}

trap cleanup SIGINT SIGTERM

while true; do
    # 检查 start_robomaster.sh 是否正在运行
    # pgrep -f 匹配完整命令行，避免只匹配到文件名
    if ! pgrep -f "$SCRIPT_NAME" > /dev/null; then
        echo "脚本 $SCRIPT_NAME 未在运行，正在尝试启动..."
        
        RETRY_COUNT=$((RETRY_COUNT + 1))
        if [ "$RETRY_COUNT" -gt "$MAX_RETRY" ]; then
            echo "错误: 脚本崩溃重启已达上限 ($MAX_RETRY 次)"
            exit 1
        fi

        # 给予一点缓冲时间
        sleep 1
        
        # 直接启动脚本，并将输出重定向，方便你后续排查
        # 这里的 & 让它后台运行，以便循环继续监控
        /bin/zsh "$SCRIPT_NAME" > /dev/null 2>&1 &
        
        echo "脚本已启动 (尝试第 $RETRY_COUNT 次)"
    else
        # 运行正常，重置计数器
        RETRY_COUNT=0
    fi

    # 每 5 秒检查一次状态
    sleep 5
done
