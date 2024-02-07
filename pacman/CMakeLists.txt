cmake_minimum_required(VERSION 3.27)

project(pacman C)

set(CMAKE_C_STANDARD 11)

set(SDL2_DIR "/Users/olthe/Polimi/polimiaer/pacman/lib/cmake/SDL2")

find_package(SDL2 REQUIRED)

include_directories(include, ${SDL2_INCLUDE_DIRS})
link_directories(lib)

add_executable(pacman src/main.c)

target_link_libraries(pacman ${SDL2_LIBRARIES})