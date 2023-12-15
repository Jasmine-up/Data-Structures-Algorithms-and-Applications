/*
Project name :			allAlgorithmsTest
Last modified Date:		2023��12��15��21��59��
Last Version:			V1.0
Descriptions:			���������Ľ��ṹ��
*/
#ifndef _29HUFFMANTREE_HUFFMANNODE_H
#define _29HUFFMANTREE_HUFFMANNODE_H
#include "_28binaryTreeChains.h"
template<class T>
struct huffmanNode
{
    binaryTreeChains<int> *tree{};// �����ⲿ�ڵ㣬element���ֵ��������ʾ�ķ��ţ������ڲ��ڵ㣬element���ֵ��0��
    T weight;// ��ʾ���ų��ֵ�Ƶ��
    huffmanNode(){weight = 0;}
    explicit huffmanNode(T pweight){weight = pweight;}
    operator T () const {return weight;}
    bool operator>(const huffmanNode &a) const { return weight > a.weight; }
};

#endif //_29HUFFMANTREE_HUFFMANNODE_H
