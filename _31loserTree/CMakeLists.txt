cmake_minimum_required(VERSION 3.27)
project(_31loserTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(_31loserTree main.cpp
        loserTree.h
        MinimumLoserTree.h
        MinimumLoserTree.cpp
        MinimumLoserTree.cpp)
