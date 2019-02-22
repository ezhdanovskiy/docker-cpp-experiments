#!/usr/bin/env bash

set -x

docker build -f .build/Dockerfile -t docker-cpp-experiments .

docker container rm docker-cpp-experiments-container

docker create --name docker-cpp-experiments-container -v $(pwd)/.build/ccache:/ccache -v $(pwd)/src:/app/src docker-cpp-experiments

docker start -i docker-cpp-experiments-container