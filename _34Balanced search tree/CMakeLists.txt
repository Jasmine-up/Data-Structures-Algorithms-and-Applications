cmake_minimum_required(VERSION 3.27)
project(_34Balanced_search_tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(_34Balanced_search_tree main.cpp
        AVLTreeNode.h
        AVLTree.h
        dictionary.h
        AVLTree.cpp)
