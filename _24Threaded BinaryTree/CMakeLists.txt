cmake_minimum_required(VERSION 3.25)
project(_24Threaded_BinaryTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(_24Threaded_BinaryTree main.cpp binaryTree.h inThreadedBinaryTreeNode.h inThreadedBinaryTreeChains.h inThreadedBinaryTreeChains.cpp)
