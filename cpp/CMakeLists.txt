CMAKE_MINIMUM_REQUIRED(VERSION 3.11)

project(supersonic)

set(CXX_FLAGS "-O3 -march=native -std=c++20")

FILE(GLOB SOURCE_FILES src/*.cpp)

add_executable(main main.cpp src/timer.cpp src/standard_sort.cpp src/radixsort_normal.cpp src/radixsort_fast.cpp src/generation_lists.cpp src/funcs.cpp)#${SOURCE_FILES})