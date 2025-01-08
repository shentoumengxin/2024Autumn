# 指定 CMake 的最低版本要求
cmake_minimum_required(VERSION 3.10)

# 定义项目的名称和版本
project(RectangleExample VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(RectangleApp Main.cpp Rectangle.cpp)
