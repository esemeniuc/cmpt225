cmake_minimum_required(VERSION 3.5)
project(codingquiz1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES SomeList_Test_Driver.cpp SomeList.h SomeList.cpp Node.h Node.cpp)
add_executable(codingquiz1 ${SOURCE_FILES})