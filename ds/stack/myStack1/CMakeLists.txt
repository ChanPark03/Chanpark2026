cmake_minimum_required(VERSION 3.10)
project(myStack1)

include_directories(${CMAKE_CURRENT_LIST_DIR})
add_executable(myStack1 main.c myStack1.c)