cmake_minimum_required(VERSION 3.6)
project(PAT1053)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(PAT1053 ${SOURCE_FILES})