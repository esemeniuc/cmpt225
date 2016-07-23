cmake_minimum_required(VERSION 3.5)
project(4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp university.cpp university.h student.cpp student.h testDriver.cpp testDriver.h musla.cpp musla.h btree.h btree.cpp node.h node.cpp classException.cpp classException.h)
add_executable(4 ${SOURCE_FILES})