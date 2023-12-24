/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月27日09点44分
Last Version:			V1.0
Descriptions:			二叉树的结点结构体
*/
#pragma once
#ifndef _BINARYTREENODE_H_
#define _BINARYTREENODE_H_
template <class T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T> *leftChild,   // left subtree
    *rightChild;  // right subtree

    binaryTreeNode() {leftChild = rightChild = nullptr;}
    explicit binaryTreeNode(const T& theElement):element(theElement)
    {
        leftChild = rightChild = nullptr;
    }
    binaryTreeNode(const T& theElement,
                   binaryTreeNode *theLeftChild,
                   binaryTreeNode *theRightChild)
            :element(theElement)
    {
        leftChild = theLeftChild;
        rightChild = theRightChild;
    }
};

#endif