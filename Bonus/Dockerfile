FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    build-essential \
    gcc \
    git \
    apt-utils \
    make \
    vim \
    sudo

RUN useradd -m -s /bin/bash testuser && \
    echo 'testuser:testpassword' | chpasswd && \
    adduser testuser sudo

USER testuser
WORKDIR /home/testuser

CMD ["/bin/bash"]
