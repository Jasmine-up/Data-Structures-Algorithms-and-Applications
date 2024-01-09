cmake_minimum_required(VERSION 3.27)
project(_35Red_black_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(_35Red_black_tree main.cpp
        RedBlackTreeNode.h
        dictionary.h
        RedBlackTree.cpp)
