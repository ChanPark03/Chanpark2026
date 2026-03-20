cmake_minimum_required(VERSION 3.10)
project(bowlingGame)

include_directories(${CMAKE_CURRENT_LIST_DIR})
add_executable(bowlingGame main.c bowling.c)
