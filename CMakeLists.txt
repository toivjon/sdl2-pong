cmake_minimum_required (VERSION 3.7.2)
project (SDL2-Pong)

file(GLOB SOURCES src/*.cpp)

include_directories(include)

add_executable(pong ${SOURCES})