cmake_minimum_required(VERSION 3.10)

# standalone configure일 때만 기본 AVR 툴체인 파일을 지정한다.
if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/avr-toolchain.cmake")
endif()

project(Atmega128_Project C)

# --- 하드웨어 설정 ---
set(MCU atmega128)
set(F_CPU 16000000UL)
set(PROG_TYPE avrispmkII)
set(PROG_PORT usb)

# --- src/ 내 모든 .c 파일에 대해 빌드 + 업로드 타겟 자동 생성 ---
file(GLOB SRC_FILES "src/*.c")

foreach(SRC_FILE ${SRC_FILES})
    get_filename_component(TARGET_NAME ${SRC_FILE} NAME_WE)

    add_executable(${TARGET_NAME}.elf ${SRC_FILE})

    target_compile_options(${TARGET_NAME}.elf PUBLIC
        -mmcu=${MCU}
        -DF_CPU=${F_CPU}
        -Os -Wall
    )

    target_link_options(${TARGET_NAME}.elf PUBLIC -mmcu=${MCU})

    add_custom_command(TARGET ${TARGET_NAME}.elf POST_BUILD
        COMMAND avr-objcopy -j .text -j .data -O ihex ${TARGET_NAME}.elf ${TARGET_NAME}.hex
        COMMAND avr-size --format=avr --mcu=${MCU} ${TARGET_NAME}.elf
        COMMENT "Generating HEX for ${TARGET_NAME}"
    )

    add_custom_target(upload_${TARGET_NAME}
        COMMAND avrdude -p m128 -c ${PROG_TYPE} -P ${PROG_PORT} -U flash:w:${TARGET_NAME}.hex:i
        DEPENDS ${TARGET_NAME}.elf
        COMMENT "Flashing ${TARGET_NAME}.hex to hardware..."
        USES_TERMINAL
    )
endforeach()