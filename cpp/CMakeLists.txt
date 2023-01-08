CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

project(supersonic)

set(CMAKE_CXX_FLAGS "-O3 -march=native -std=c++20 -Wall")

FILE(GLOB SOURCE_FILES src/*.cpp)

add_executable(main main.cpp ${SOURCE_FILES})

add_subdirectory(src/datastructures)
add_subdirectory(src/hellofradixsort)
