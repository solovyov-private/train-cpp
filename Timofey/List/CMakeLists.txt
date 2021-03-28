cmake_minimum_required(VERSION 3.17)
project(List)

set(CMAKE_CXX_STANDARD 14)

add_executable(List node.hpp linked_list.cpp)
#add_executable(List main.cpp node.hpp linked_list.cpp)