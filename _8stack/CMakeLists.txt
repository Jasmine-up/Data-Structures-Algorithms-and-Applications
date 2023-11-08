cmake_minimum_required(VERSION 3.25)
project(_8stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(_8stack main.cpp _14stack.h _15arrayStack.h _15arrayStack.cpp _1myExceptions.h)
