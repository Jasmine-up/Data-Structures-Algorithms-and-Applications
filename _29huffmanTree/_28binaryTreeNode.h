/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月27日09点44分
Last Version:			V1.0
Descriptions:			二叉树的结点结构体
*/
#pragma once
#ifndef _BINARYTREENODE_H_
#define _BINARYTREENODE_H_
template<class T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T>* leftChild,//左子树
    *rightChild;//右子树
    /*默认构造函数*/
    binaryTreeNode() { leftChild = rightChild = nullptr; }
    /*只初始化element*/
    binaryTreeNode(T melement)
    {
        element = melement;
        leftChild = rightChild = nullptr;
    }
    /*三个元素都初始化*/
    binaryTreeNode(T melement, binaryTreeNode<T>* mleftChild, binaryTreeNode<T>* mrightChild)
    {
        element = melement;
        leftChild = mleftChild;
        rightChild = mrightChild;
    }
};

#endif