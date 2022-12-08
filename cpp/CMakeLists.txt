CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

project(supersonic)

set(CXX_FLAGS "-O3 -march=native -std=c++20")

FILE(GLOB SOURCE_FILES src/*.cpp)

add_executable(main.cpp ${SOURCE_FILES})