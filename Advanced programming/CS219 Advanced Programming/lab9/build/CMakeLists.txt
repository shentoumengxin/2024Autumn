# 指定 CMake 最低版本
cmake_minimum_required(VERSION 3.10)


project(CandyBarProject)


set(CMAKE_CXX_STANDARD 11)


add_executable(CandyBar2 main.cpp candybar.cpp)
