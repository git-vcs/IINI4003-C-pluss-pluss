cmake_minimum_required(VERSION 3.13)
project(assignment_05)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -pthread -std=c++1y -Wall -Wextra")

add_executable(assignment_05 main.cpp)