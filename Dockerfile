# Use the official Ubuntu 16.04 image as the base
FROM ubuntu:16.04

# Set the working directory inside the container
WORKDIR /app

# Install any necessary packages or dependencies
# For example, you can install updates and some basic utilities
RUN apt-get update && \
    apt-get install -y \
    sudo \
    build-essential \
    gcc \
    wget \
	vim \
    man \
    && rm -rf /var/lib/apt/lists/*

# Specify the entry point when the container starts
CMD ["/bin/bash"]

