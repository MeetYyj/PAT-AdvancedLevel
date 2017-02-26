cmake_minimum_required(VERSION 3.6)
project(PAT1114)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(PAT1114 ${SOURCE_FILES})