cmake_minimum_required(VERSION 3.3)
project(homework12)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(homework12 ${SOURCE_FILES})