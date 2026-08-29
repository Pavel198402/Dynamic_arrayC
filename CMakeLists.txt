cmake_minimum_required(VERSION 3.20)

project(Dynamic_arrayC)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(Dynamic_arrayC
    src/Dynamic_array.cpp
	src/Vector.cpp

 "include/StaticArray.h" "include/Sort.h")