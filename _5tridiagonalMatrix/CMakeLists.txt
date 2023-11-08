cmake_minimum_required(VERSION 3.25)
project(_5tridiagonalMatrix)

set(CMAKE_CXX_STANDARD 17)

add_executable(_5tridiagonalMatrix main.cpp _10tridiagonalMatrix.h _10tridiagonalMatrix.cpp _1myExceptions.h)
