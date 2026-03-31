cmake_minimum_required(VERSION 3.13)

# Set PICO_SDK_PATH to local submodule
set(PICO_SDK_PATH ${CMAKE_CURRENT_SOURCE_DIR}/deps/pico-sdk)

set(PICO_SDK_FETCH_FROM_GIT ON)
include(pico_sdk_import.cmake)

project(fitpico C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

# Auto build all src/*.c files
file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.c")

foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(TARGET_NAME ${SRC_FILE} NAME_WE)
    add_executable(${TARGET_NAME} ${SRC_FILE})

    target_link_libraries(${TARGET_NAME} 
        pico_stdlib 
        hardware_gpio 
        hardware_timer
    )
    pico_enable_stdio_usb(${TARGET_NAME} 1)
    pico_enable_stdio_uart(${TARGET_NAME} 0)
    pico_add_extra_outputs(${TARGET_NAME})
endforeach()

