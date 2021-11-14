cmake_minimum_required(VERSION 3.5)

project(AlgorithmTraining LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_VERBOSE_MAKEFILE OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_definitions(-Wall -Wextra -pedantic)
if(CMAKE_BUILD_TYPE MATCHES "Debug" OR CMAKE_BUILD_TYPE MATCHES "RelWithDebInfo")
    add_definitions(-DDEBUG)
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
       add_definitions(-fno-limit-debug-info)
    endif()
endif()

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/library)   
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/library) 
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin) # exe 

find_package(Threads)
find_package(glog REQUIRED CONFIG)
set(LOCAL_LINK_LIB glog::glog pthread)
include_directories(Src)

add_subdirectory(Src)
