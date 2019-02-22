#!/usr/bin/env bash

set -x

docker container rm docker-cpp-experiments-container

docker run --name docker-cpp-experiments-container -v $(pwd)/.build/ccache:/ccache -v $(pwd)/src:/app/src -it docker-cpp-experiments bash