/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��27��09��44��
Last Version:			V1.0
Descriptions:			�������Ľ��ṹ��
*/
#pragma once
#ifndef _BINARYTREENODE_H_
#define _BINARYTREENODE_H_
template<class T>
struct binaryTreeNode
{
    T element;
    binaryTreeNode<T>* leftChild,//������
    *rightChild;//������
    /*Ĭ�Ϲ��캯��*/
    binaryTreeNode() { leftChild = rightChild = nullptr; }
    /*ֻ��ʼ��element*/
    binaryTreeNode(T melement)
    {
        element = melement;
        leftChild = rightChild = nullptr;
    }
    /*����Ԫ�ض���ʼ��*/
    binaryTreeNode(T melement, binaryTreeNode<T>* mleftChild, binaryTreeNode<T>* mrightChild)
    {
        element = melement;
        leftChild = mleftChild;
        rightChild = mrightChild;
    }
};

#endif