cmake_minimum_required(VERSION 3.3)
project(huffman)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp HuffmanTree.cpp HuffmanTree.h Tree.cpp Tree.h)
add_executable(huffman ${SOURCE_FILES})