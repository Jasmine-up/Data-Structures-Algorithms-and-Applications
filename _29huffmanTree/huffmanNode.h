/*
Project name :			allAlgorithmsTest
Last modified Date:		2023年12月15日21点59分
Last Version:			V1.0
Descriptions:			哈夫曼树的结点结构体
*/
#ifndef _29HUFFMANTREE_HUFFMANNODE_H
#define _29HUFFMANTREE_HUFFMANNODE_H
#include "_28binaryTreeChains.h"
template<class T>
struct huffmanNode
{
    binaryTreeChains<int> *tree{};// 对于外部节点，element域的值是它所表示的符号，对于内部节点，element域的值是0。
    T weight;// 表示符号出现的频率
    huffmanNode(){weight = 0;}
    explicit huffmanNode(T pweight){weight = pweight;}
    operator T () const {return weight;}
    bool operator>(const huffmanNode &a) const { return weight > a.weight; }
};

#endif //_29HUFFMANTREE_HUFFMANNODE_H
