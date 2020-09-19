cmake_minimum_required(VERSION 3.13)
project(assignment_06)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -Wall -Wextra")
add_executable(assignment_06 main.cpp)

find_package(Boost 1.54.0 COMPONENTS system REQUIRED)
include_directories(${Boost_INCLUDE_DIR})


add_executable(oppgave2 example6.cpp)
target_link_libraries(oppgave2 ${Boost_LIBRARIES})

