cmake_minimum_required(VERSION 3.5)
project(4p2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES EKTApp.cpp word.h word.cpp node.h btree.h exQueue.h exQueue.cpp ClassException.h ClassException.cpp testDriver.cpp testDriver.h)
add_executable(4p2 ${SOURCE_FILES})