cmake_minimum_required(VERSION 3.4 FATAL_ERROR)

project(strcmp_test CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wformat-overflow")

add_executable(strcmp_test strcmp_test.cpp)
