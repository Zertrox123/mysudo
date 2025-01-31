FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    build-essential \
    zsh \
    curl \
    gcc \
    git \
    apt-utils \
    make \
    vim \
    sudo \
    man \
    less \
    net-tools \
    iputils-ping && \
    apt-get clean

RUN useradd -m -s /bin/bash testuser && \
    echo 'testuser:testpassword' | chpasswd && \
    usermod -aG sudo testuser

RUN echo 'testuser ALL=(ALL) NOPASSWD:ALL' >> /etc/sudoers

USER testuser
WORKDIR /home/testuser

CMD ["/bin/zsh"]
