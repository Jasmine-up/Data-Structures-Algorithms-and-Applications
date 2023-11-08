cmake_minimum_required(VERSION 3.25)
project(_7sparseMatrix)

set(CMAKE_CXX_STANDARD 17)

add_executable(_7sparseMatrix main.cpp _12matrixTerm.h _13sparseMatrix.h _13sparseMatrix.cpp _1myExceptions.h)
