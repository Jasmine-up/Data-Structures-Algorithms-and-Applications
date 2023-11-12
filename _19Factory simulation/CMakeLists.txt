cmake_minimum_required(VERSION 3.25)
project(_19Factory_simulation)

set(CMAKE_CXX_STANDARD 17)

add_executable(_19Factory_simulation main.cpp _22factorySim.h _22eventList.h _22task.h _22job.h _22machine.h _22factorySim.cpp _1myExceptions.h)
