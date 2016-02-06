cmake_minimum_required(VERSION 2.8)
project(sdl2-toys)

set(SDL2_INCLUDE_DIR /usr/include/SDL2)
set(SDL2_LIBRARY /usr/lib/x86_64-linux-gnu/libSDL2.so /usr/lib/x86_64-linux-gnu/libSDL2_image.so /usr/lib/x86_64-linux-gnu/libSDL2_ttf.so)

include_directories(${SDL2_INCLUDE_DIR})

link_libraries (${SDL2_LIBRARY})

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Werror")

set(SRC main.c sdl_util.c sdl_util.h)

add_executable(toy ${SRC})
