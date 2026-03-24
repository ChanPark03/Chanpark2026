cmake_minimum_required(VERSION 3.10)
project(stack3)

include_directories(${CMAKE_CURRENT_LIST_DIR})

find_library(PAHO_MQTT_LIB paho-mqtt3c)
add_executable(mqttpub mqttpub.c)
target_link_libraries(mqttpub ${PAHO_MQTT_LIB})
