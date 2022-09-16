cmake_minimum_required(VERSION 2.8)
project(transform)

include_directories("/usr/include/eigen3")
add_executable(transform transform.cpp)