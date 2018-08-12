cmake_minimum_required(VERSION 3.10)

project(junior)
set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

add_executable(__run ${SOURCE_FILES})

add_subdirectory(src)