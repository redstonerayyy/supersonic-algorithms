CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

project(datastructures)

set(CMAKE_CXX_FLAGS "-O3 -march=native -std=c++20")

FILE(GLOB SOURCE_FILES ./*.cpp)

add_executable(datastructures ${SOURCE_FILES})