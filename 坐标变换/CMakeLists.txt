cmake_minimum_required(VERSION 2.8)
project(transform)

include_directories("/usr/include/eigen3")
add_executable(transform transform.cpp)
add_executable(nclt_lidar2imu nclt_lidar2imu.cpp)
add_executable(computeTbi computeTbi.cpp)
add_executable(20HK compute20HK.cpp)