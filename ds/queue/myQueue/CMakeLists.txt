cmake_minimum_required(VERSION 3.10)
project(myQueue)

include_directories(${CMAKE_CURRENT_LIST_DIR})
add_executable(myQueue main.c myQueue.c)