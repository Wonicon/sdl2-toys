cmake_minimum_required(VERSION 3.3)
project(sdl2-toys)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${sdl2-toys_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED)
find_package(SDL2_Image REQUIRED)
find_package(SDL2_ttf REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(sdl2-toys ${SOURCE_FILES})