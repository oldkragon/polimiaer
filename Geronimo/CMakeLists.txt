cmake_minimum_required(VERSION 3.27)
project(Geronimo C)

set(CMAKE_C_STANDARD 99)

add_executable(Geronimo main.c)

find_package(CURL)
if(CURL_FOUND)
    include_directories(${CURL_INCLUDE_DIRS})
    target_link_libraries(Geronimo ${CURL_LIBRARIES})
else(CURL_FOUND)
    message(FATAL_ERROR "CURL library not found")
endif(CURL_FOUND)

