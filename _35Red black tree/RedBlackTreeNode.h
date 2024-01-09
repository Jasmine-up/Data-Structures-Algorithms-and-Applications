/*
Project name :			_35Red_black_tree
Last modified Date:		2024年1月5日21点00分
Last Version:			V1.0
Descriptions:			红黑树树节点模板类
*/

#ifndef _35RED_BLACK_TREE_REDBLACKTREENODE_H
#define _35RED_BLACK_TREE_REDBLACKTREENODE_H

template<class T>
struct RedBlackTreeNode {
    T element;// 存储键值对
    RedBlackTreeNode<T> *leftChild,   // 左子树
    *rightChild, // 右子树
    *parent;  // 父亲节点
    bool isRed; // true表示为红色，false表示为黑色

    RedBlackTreeNode() {
        leftChild = rightChild = parent = nullptr;
        isRed = true;
    }

    explicit RedBlackTreeNode(T &theElement) : element(theElement) {
        leftChild = rightChild = parent = nullptr;
        isRed = true;
    }

    explicit RedBlackTreeNode(T &theElement,
                              RedBlackTreeNode *theLeftChild,
                              RedBlackTreeNode *theRightChild,
                              RedBlackTreeNode *theParent)
            : element(theElement), leftChild(theLeftChild),
              rightChild(theRightChild), parent(theParent) {
        isRed = true;
    }

    explicit RedBlackTreeNode(T &theElement,
                              RedBlackTreeNode *theLeftChild,
                              RedBlackTreeNode *theRightChild,
                              RedBlackTreeNode *theParent, bool theIsRed)
            : element(theElement), leftChild(theLeftChild), rightChild(theRightChild), parent(theParent) {
        isRed = theIsRed;
    }
};

#endif //_35RED_BLACK_TREE_REDBLACKTREENODE_H
