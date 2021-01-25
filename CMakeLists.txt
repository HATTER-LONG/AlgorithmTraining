cmake_minimum_required(VERSION 3.5)

project(TDD-Learning-Project LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-Wall -pedantic)

find_package(Threads)
find_package(spdlog REQUIRED CONFIG)
set(LOCAL_LINK_LIB spdlog::spdlog pthread)
include_directories(Src)

add_subdirectory(Src)