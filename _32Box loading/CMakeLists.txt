cmake_minimum_required(VERSION 3.27)
project(_32Box_loading_)

set(CMAKE_CXX_STANDARD 17)
set(DCMAKE_BUILD_TYPE Debug)
add_executable(_32Box_loading_ main.cpp
        loserTree.h
        myExceptions.h
        MaxmumLoserTree.h
        dBinarySearchTree.h
        bsTree.h
        dictionary.h
        binaryTreeNode.h)
