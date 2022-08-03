cmake_minimum_required(VERSION 3.16)
project(emu6502)

set(CMAKE_C_STANDARD 99)
file(GLOB SRC_SOURCES src/*.c)
file(GLOB SRC_HEADERS src/*.h)
#LINK_LIBRARIES(SDL2main SDL2 SDL2_image SDL2_mixer)
#add_compile_options(-municode) #Needed for windows using gcc
add_executable(emu6502 ${SRC_SOURCES} ${SRC_HEADER})