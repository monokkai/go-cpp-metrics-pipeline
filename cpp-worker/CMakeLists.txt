cmake_minimum_required(VERSION 3.14)

project(go_cpp_worker_metrics LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

FetchContent_Declare(
        prometheus-cpp
        GIT_REPOSITORY https://github.com/jupp0r/prometheus-cpp.git
        GIT_TAG v1.1.0
)

set(BUILD_SHARED_LIBS ON CACHE BOOL "" FORCE)
set(ENABLE_PUSH OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(prometheus-cpp)

find_package(Threads REQUIRED)

add_executable(go_cpp_worker_metrics
        src/main.cpp
        src/main.h
)

target_include_directories(go_cpp_worker_metrics
        PRIVATE
        src
)

target_link_libraries(go_cpp_worker_metrics
        PRIVATE
        prometheus-cpp::core
        prometheus-cpp::pull
        Threads::Threads
)
