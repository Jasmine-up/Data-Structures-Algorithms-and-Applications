cmake_minimum_required(VERSION 3.25)
project(_2chain)

set(CMAKE_CXX_STANDARD 17)

add_executable(_2chain _1myExceptions.h main.cpp _2myFunctions.cpp _2myFunctions.h _4linearList.h _5arrayList.h _6chain.cpp _6chain.h _6chainNode.h _7arrayAndChain.h)
