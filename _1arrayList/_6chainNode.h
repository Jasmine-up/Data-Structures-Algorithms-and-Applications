/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日22点06分
Last Version:			V1.0
Descriptions:			链表的结点
*/
#pragma once
#ifndef _CHAINNODE_H_
#define _CHAINNODE_H_
template <class T>
struct chainNode
{
    //数据成员
    T element;
    chainNode<T>* next;
    //方法
    chainNode() {}
    chainNode(const T& element)
    {
        this->element = element;
        this->next = nullptr;
    }

    chainNode(const T& element, chainNode<T>* next)
    {
        this->element = element;
        this->next = next;
    }
};
#endif
