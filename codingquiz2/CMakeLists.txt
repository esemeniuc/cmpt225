cmake_minimum_required(VERSION 3.5)
project(codingquiz2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES BST.cpp Node.cpp Test_Driver.cpp)
add_executable(codingquiz2 ${SOURCE_FILES})