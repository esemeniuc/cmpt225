cmake_minimum_required(VERSION 3.5)
project(4p2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES EKTAppV2.cpp ekt.h ekt.cpp word.h word.cpp nodeDL.h nodeSL.h btree.h exQueue.h exQueue.cpp classException.h classException.cpp testDriver.cpp testDriver.h)
add_executable(4p2 ${SOURCE_FILES})