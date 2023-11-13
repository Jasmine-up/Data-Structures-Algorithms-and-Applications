/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月23日10点18分
Last Version:			V1.0
Descriptions:			跳表结构
// node type used in skip lists
// node with a next and element field; element is a pair<const K, E>
// next is a 1D array of pointers
*/
#pragma once
#ifndef _SKIPNODE_H_
#define _SKIPNODE_H_

template <class K, class E>
struct skipNode
{
    typedef pair<const K, E> pairType;
    pairType element;
    skipNode<K, E>** next;   // 1D array of pointers

    skipNode(const pairType& thePair, int size)
            :element(thePair) {
        next = new skipNode<K, E>*[size];
    }
    friend ostream& operator<<(ostream& out, skipNode<K, E>& m)
    {
        out << "(" << m.element.first << " ," << m.element.second << ")" << " ";
        return out;
    }
};

#endif
