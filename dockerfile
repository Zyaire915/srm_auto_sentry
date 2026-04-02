FROM ros:humble-ros-base

# 创建工作空间
RUN mkdir -p /ros_ws
WORKDIR /ros_ws/

# -----------------------------------------------------------------------
# 1. 核心修复：强制替换密钥文件 & 锁定中科大源
#    (这是为了规避你遇到的 EXPKEYSIG 错误)
# -----------------------------------------------------------------------
RUN apt-get update && apt-get install -y \
    curl \
    gnupg2 \
    lsb-release \
    build-essential \
    cmake \
    git \
    wget \
    python3-pip \
    && \
    # [关键步骤 1] 强制删除系统里过期的 ROS 密钥文件
    rm -f /usr/share/keyrings/ros-archive-keyring.gpg && \
    # [关键步骤 2] 下载最新的 ROS 2 密钥并保存到原位置 (使用 GPG 解码保存)
    curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key  -o - | gpg --dearmor -o /usr/share/keyrings/ros-archive-keyring.gpg || \
    # 如果上面 Github 连不上，尝试用 keyserver 备用方案
    curl -s --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654 | gpg --dearmor -o /usr/share/keyrings/ros-archive-keyring.gpg && \
    # [关键步骤 3] 清理旧源配置 (删除可能存在的 fishros 或其他 list)
    rm -f /etc/apt/sources.list.d/ros-fish.list /etc/apt/sources.list.d/ros2.list && \
    # [关键步骤 4] 写入中科大源 (明确指定 signed-by 使用刚才下载的密钥)
    echo "deb [arch=$(dpkg --print-architecture) signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] https://mirrors.ustc.edu.cn/ros2/ubuntu jammy main" | tee /etc/apt/sources.list.d/ros2.list > /dev/null

# -----------------------------------------------------------------------
# 2. 安装项目依赖 (ASIO, Example Interfaces, Clang)
#    (固化你昨天手动 apt install 的内容)
# -----------------------------------------------------------------------
RUN apt-get update && apt-get install -y --no-install-recommends \
    libasio-dev \
    ros-humble-example-interfaces \
    clang \
    clangd \
    clang-format \
    && rm -rf /var/lib/apt/lists/*

# -----------------------------------------------------------------------
# 3. Python & Rosdepc (保留原有配置)
# -----------------------------------------------------------------------
RUN pip install rosdepc && \
    rosdepc init && \
    rosdepc update

# -----------------------------------------------------------------------
# 4. 安装 Livox-SDK2 (保留原有配置)
# -----------------------------------------------------------------------
RUN git clone https://github.com/Livox-SDK/Livox-SDK2.git && \
    cd ./Livox-SDK2/ && \
    mkdir build && \
    cd build && \
    cmake .. && make -j && \
    make install && \
    cd ../.. && rm -rf Livox-SDK2

# -----------------------------------------------------------------------
# 5. ZSH 美化 (保留原有配置)
# -----------------------------------------------------------------------
RUN sh -c "$(wget -O- https://github.com/deluan/zsh-in-docker/releases/download/v1.2.0/zsh-in-docker.sh)" -- \
    -t jispwoso -p git \
    -p https://github.com/zsh-users/zsh-autosuggestions \
    -p https://github.com/zsh-users/zsh-syntax-highlighting && \
    chsh -s /bin/zsh && \
    rm -rf /var/lib/apt/lists/*

# 配置环境变量
RUN echo 'export TERM=xterm-256color\n\
source /opt/ros/humble/setup.zsh\n\
eval "$(register-python-argcomplete3 ros2)"\n\
eval "$(register-python-argcomplete3 colcon)"\n'\
>> /root/.zshrc

RUN sed --in-place --expression \
    '$isource "/opt/ros/humble/setup.sh"' \
    /ros_entrypoint.sh