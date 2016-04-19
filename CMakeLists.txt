cmake_minimum_required(VERSION 3.5)
project(race_to_gaia)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Fleet.cpp Fleet.h)
add_executable(race_to_gaia ${SOURCE_FILES} Fleet.h)