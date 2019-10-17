cmake_minimum_required(VERSION 3.15)
project(sort)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
include_directories("include")

add_executable(sort src/main.cpp src/Tester.cpp solutions/BubbleSort.cpp solutions/InsertionSort.cpp solutions/SelectSort.cpp solutions/MergeSort.cpp solutions/QuickSort.cpp)