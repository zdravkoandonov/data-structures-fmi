cmake_minimum_required(VERSION 3.3)
project(exam)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES problem3.cpp)
add_executable(exam ${SOURCE_FILES})