# Use the official Ubuntu base image
FROM ubuntu:22.04

# Avoid prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install essential packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    gdb \
    git \
    libgtest-dev \
    lldb \
    ninja-build \
    python3 \
    python3-pip \
    sudo \
    unzip \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Install aider-chat python package
RUN pip3 install aider-chat

# Create a non-root user and add to sudoers
RUN useradd -ms /bin/bash vscode \
    && echo "vscode ALL=(ALL) NOPASSWD:ALL" >> /etc/sudoers

# Switch to the non-root user
USER vscode

# Set the working directory
WORKDIR /workspace

# Install Google Test
RUN cd /usr/src/gtest && \
    sudo mkdir build && \
    cd build && \
    sudo cmake .. && \
    sudo make && \
    sudo cp lib/*.a /usr/local/lib

# Set the default shell to bash
SHELL ["/bin/bash", "-c"]