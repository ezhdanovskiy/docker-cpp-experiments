#!/usr/bin/env bash

set -ex
ccache -s
pwd
ls -al
ls -al /app/src
time -p make
./app_test