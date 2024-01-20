cmake_minimum_required(VERSION 3.15)

project(sync-config VERSION 0.1.0 LANGUAGES CXX)

find_program(GIT_EXECUTABLE NAMES git)

if (NOT GIT_EXECUTABLE)
    message(STATUS "Git found: ${GIT_EXECUTABLE}")
else()
    message(FATAL_ERROR "Git not found. Please install Git.")
endif()

add_subdirectory(src)
