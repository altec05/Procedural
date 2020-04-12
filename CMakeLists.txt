cmake_minimum_required(VERSION 3.15)
project(procedural)

set(CMAKE_CXX_STANDARD 14)

add_executable(procedural main.cpp numbers.cpp numbers.h complex_numbers.cpp
               complex_numbers.h fractional_numbers.cpp fractional_numbers.h
               container.cpp container.h polar_numbers.h polar_numbers.cpp)