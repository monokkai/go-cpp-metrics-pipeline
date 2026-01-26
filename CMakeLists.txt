cmake_minimum_required(VERSION 4.1)
project(go_cpp_worker_metrics)

set(CMAKE_CXX_STANDARD 14)

include_directories(cpp-worker/src)

add_executable(go_cpp_worker_metrics
        cpp-worker/src/main.cpp
        cpp-worker/src/main.h)
