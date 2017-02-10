cmake_minimum_required(VERSION 3.6)
project(_PAT1032)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(_PAT1032 ${SOURCE_FILES})