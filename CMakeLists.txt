cmake_minimum_required(VERSION 3.9)
project(tasks)

set(CMAKE_CXX_STANDARD 17)

add_executable(tasks main.cpp array/slidingMax.hpp array/slidingMax.cpp)