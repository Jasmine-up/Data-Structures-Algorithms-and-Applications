cmake_minimum_required(VERSION 3.25)
project(_3matrix)

set(CMAKE_CXX_STANDARD 17)

add_executable(_3matrix main.cpp _8matrix.h _8matrix.cpp _1myExceptions.h)
