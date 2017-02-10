cmake_minimum_required(VERSION 3.6)
project(PAT1035)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(PAT1035 ${SOURCE_FILES})