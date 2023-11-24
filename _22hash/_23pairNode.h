/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月22日09点17分
Last Version:			V1.0
Descriptions:			是字典的一个节点
*/
#pragma once
#ifndef _PAIRNODE_H_
#define _PAIRNODE_H_
using namespace std;
template <class K, class E>
struct pairNode
{
    typedef pair<const K, E> pairType;
    pairType element;
    pairNode<K, E>* next;

    pairNode(const pairType& thePair) :element(thePair) {}
    pairNode(const pairType& thePair, pairNode<K, E>* theNext)
            :element(thePair) {
        next = theNext;
    }
};
#endif