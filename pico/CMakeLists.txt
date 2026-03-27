cmake_minimum_required(VERSION 3.13)

# pico-sdk 경로 설정 (deps/pico-sdk 서브모듈 사용)
set(PICO_SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/deps/pico-sdk")

include(pico_sdk_import.cmake)

project(pico_project C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

# src/ 내 모든 .c 파일에 대해 타겟 자동 생성
file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.c")

foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(TARGET_NAME ${SRC_FILE} NAME_WE)

    add_executable(${TARGET_NAME} ${SRC_FILE})

    target_link_libraries(${TARGET_NAME}
        pico_stdlib
    )

    # USB를 기본 stdio로 사용 (UART도 원하면 pico_enable_stdio_uart 추가)
    pico_enable_stdio_usb(${TARGET_NAME} 1)
    pico_enable_stdio_uart(${TARGET_NAME} 0)

    # .uf2, .bin, .hex 등 추가 출력 파일 생성
    pico_add_extra_outputs(${TARGET_NAME})
endforeach()
