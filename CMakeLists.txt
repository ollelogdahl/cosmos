cmake_minimum_required(VERSION 3.17)
project(cosmosEmu C)

set(CMAKE_C_STANDARD 99)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH})

find_package(SDL2 REQUIRED)

include_directories(
        "${CMAKE_SOURCE_DIR}/src"
        ${SDL2_INCLUDE_DIR}
        ${SDL2TTF_INCLUDE_DIR}
)

add_executable(cosmosEmu main.c src/types.h src/instructionParser.c src/instructionParser.h src/emulator/cpu.c src/emulator/cpu.h src/emulator/emulator.c src/emulator/emulator.h src/emulator/cpu_opcodes.c src/asprintf.h src/assembler/assembler.c src/disassembler/disassembler.c src/disassembler/disassembler.h)
target_link_libraries(cosmosEmu SDL2)