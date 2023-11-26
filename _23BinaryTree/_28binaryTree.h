/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月27日09点43分
Last Version:			V1.0
Descriptions:			二叉树的抽象类
*/
#pragma once
#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
template<class T>
class binaryTree
{
public:
    virtual ~binaryTree() {}
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual void preOrder(void (*)(T*)) = 0;
    virtual void inOrder(void (*)(T*)) = 0;
    virtual void postOrder(void (*)(T*)) = 0;
    virtual void levelOrder(void (*)(T*)) = 0;
};
#endif