cmake_minimum_required(VERSION 3.10.2)
project(assignment_02)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")
set(CMAKE_CXX_STANDARD 14 )
add_executable(assignment_02
        CMakeLists.txt
        main.cpp)
