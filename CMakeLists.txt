cmake_minimum_required(VERSION 3.3)
project(sdl2-toys)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${sdl2-toys_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

include_directories(.)

set(SOURCE_FILES main.cpp sdl_util.c)
set(PIC_MOVE_SRC pic_move/main.c sdl_util.c)

add_executable(sdl2-toys ${SOURCE_FILES})
add_executable(pic_move ${PIC_MOVE_SRC})

target_link_libraries(sdl2-toys ${SDL2_LIBRARY}
                                ${SDL2_IMAGE_LIBRARIES}
                                ${SDL2_TTF_LIBRARIES})

target_link_libraries(pic_move ${SDL2_LIBRARY}
                                ${SDL2_IMAGE_LIBRARIES}
                                ${SDL2_TTF_LIBRARIES})