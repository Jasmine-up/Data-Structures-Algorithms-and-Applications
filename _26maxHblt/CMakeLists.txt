cmake_minimum_required(VERSION 3.27)
project(_26maxHblt)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")

add_executable(_26maxHblt main.cpp
        maxhblt.h
        maxPriorityQueue.h
        maxHbltTreeNode.h
        myExceptions.h
        maxHblt.cpp)
