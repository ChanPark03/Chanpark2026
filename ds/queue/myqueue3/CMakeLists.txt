cmake_minimum_required(VERSION 3.10)
project(myqueue3)

include_directories(${CMAKE_CURRENT_LIST_DIR})
add_executable(myqueue3 main.c myqueue3.c)