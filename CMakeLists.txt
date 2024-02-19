cmake_minimum_required(VERSION 3.15)

project("syconf" VERSION 0.1.0 LANGUAGES CXX)

find_program(GIT_EXECUTABLE NAMES git)

if(NOT GIT_EXECUTABLE)
    message(FATAL_ERROR "syconf needs git to be installed")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(SYNC_CONFIG_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)
