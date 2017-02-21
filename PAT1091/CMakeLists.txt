cmake_minimum_required(VERSION 3.6)
project(PAT1091)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(PAT1091 ${SOURCE_FILES})