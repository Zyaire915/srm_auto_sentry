FROM ros:humble-ros-base

# 小鱼一键换源
RUN apt update \ 
    && apt install wget python3-yaml -y  \
    && echo "chooses:\n" > fish_install.yaml \
    && echo "- {choose: 5, desc: '一键配置:系统源(更换系统源,支持全版本Ubuntu系统)'}\n" >> fish_install.yaml \
    && echo "- {choose: 2, desc: 更换系统源并清理第三方源}\n" >> fish_install.yaml \
    && echo "- {choose: 1, desc: 添加ROS/ROS2源}\n" >> fish_install.yaml \
    && wget http://fishros.com/install  -O fishros && /bin/bash fishros \
    && rm -rf /var/lib/apt/lists/*  /tmp/* /var/tmp/* \
    && apt-get clean && apt autoclean 

# 初始化 rosdepc
RUN apt-get update && apt-get install python3-pip -y && \
    pip install rosdepc && \
    sudo rosdepc init  && \
    rosdepc update

# clone projects
RUN git clone https://gitee.com/SMBU-POLARBEAR/PB_RM_Vision

# create workspace
WORKDIR /PB_RM_Vision/

# install dependencies and some tools
RUN rosdepc install -r --from-paths src --ignore-src --rosdistro $ROS_DISTRO -y && \
    apt-get install ros-humble-foxglove-bridge wget htop vim -y && \
    rm -rf /var/lib/apt/lists/*

# setup zsh
RUN sh -c "$(wget -O- https://mirror.ghproxy.com/https://github.com/deluan/zsh-in-docker/releases/download/v1.1.5/zsh-in-docker.sh)" -- \
    -t jispwoso -p git \
    -p https://mirror.ghproxy.com/https://github.com/zsh-users/zsh-autosuggestions \
    -p https://mirror.ghproxy.com/https://github.com/zsh-users/zsh-syntax-highlighting && \
    chsh -s /bin/zsh && \
    rm -rf /var/lib/apt/lists/*

# build
RUN . /opt/ros/humble/setup.sh && colcon build --symlink-install

# setup .zshrc
RUN echo 'export TERM=xterm-256color\n\
source /PB_RM_Vision/install/setup.zsh\n\
eval "$(register-python-argcomplete3 ros2)"\n\
eval "$(register-python-argcomplete3 colcon)"\n'\
>> /root/.zshrc

# source entrypoint setup
RUN sed --in-place --expression \
      '$isource "/PB_RM_Vision/install/setup.bash"' \
      /ros_entrypoint.sh