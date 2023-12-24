/*
Project name :			allAlgorithmsTest
Last modified Date:		2023年12月21日11点28分
Last Version:			V1.0
Descriptions:			索引二叉搜索树的结点结构体
*/

#ifndef _33SEARCH_TREE_INDEXEDBINARYSEARCHTREENODE_H
#define _33SEARCH_TREE_INDEXEDBINARYSEARCHTREENODE_H
#include<iostream>
using namespace std;
template<class T>
struct indexedBinarySearchTreeNode {
    T element;
    int leftSize;
    indexedBinarySearchTreeNode<T> *leftChild,   // 左子树
                                   *rightChild;  // 右子树

    indexedBinarySearchTreeNode() { leftChild = rightChild = nullptr; leftSize = 0;}

    explicit indexedBinarySearchTreeNode(const T &theElement) : element(theElement) {
        leftChild = rightChild = nullptr;
        leftSize = 0;
    }

    indexedBinarySearchTreeNode(const T &theElement,
                                indexedBinarySearchTreeNode *theLeftChild,
                                indexedBinarySearchTreeNode *theRightChild)
                                : element(theElement) {
        leftChild = theLeftChild;
        rightChild = theRightChild;
        leftSize = 0;
    }
    indexedBinarySearchTreeNode(const T &theElement,
                                const int theleftSize,
                                indexedBinarySearchTreeNode *theLeftChild,
                                indexedBinarySearchTreeNode *theRightChild)
                                : element(theElement), leftSize(theleftSize) {
        leftChild = theLeftChild;
        rightChild = theRightChild;
    }
};

// overload << for pair
template <class T>
ostream& operator<<(ostream& out, const indexedBinarySearchTreeNode<T>& x)
{
    out << x.element << ' ' << x.leftSize;
    return out;}

#endif //_33SEARCH_TREE_INDEXEDBINARYSEARCHTREENODE_H
