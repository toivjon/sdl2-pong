cmake_minimum_required (VERSION 3.7.2)
project (SDL2-Pong)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)

file(GLOB SOURCES src/*.cpp)

include_directories(
	include
	${SDL2_INCLUDE}
)

add_executable(pong ${SOURCES})

target_link_libraries(pong
	${SDL2_LIBRARY}
)

file(COPY ${SDL2_BINARY_PATH}/SDL2.dll DESTINATION ${CMAKE_CURRENT_BINARY_DIR})