cmake_minimum_required(VERSION 3.27)
project(_33Search_tree)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)

add_executable(_33Search_tree main.cpp
        bsTree.h
        dictionary.h
        indexedBSTree.h
        binarySearchTree.h
        binaryTreeNode.h
        binarySearchTree.cpp
        dBinarySearchTree.h
        indexedBinarySearchTree.h
        indexedBinarySearchTreeNode.h
)
