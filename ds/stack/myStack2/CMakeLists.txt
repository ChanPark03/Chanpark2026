cmake_minimum_required(VERSION 3.10)
project(myStack2)

include_directories(${CMAKE_CURRENT_LIST_DIR})
add_executable(myStack2 main.c myStack2.c)