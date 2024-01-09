/*
Project name :			_35Red_black_tree
Last modified Date:		2024��1��5��21��00��
Last Version:			V1.0
Descriptions:			��������ڵ�ģ����
*/

#ifndef _35RED_BLACK_TREE_REDBLACKTREENODE_H
#define _35RED_BLACK_TREE_REDBLACKTREENODE_H

template<class T>
struct RedBlackTreeNode {
    T element;// �洢��ֵ��
    RedBlackTreeNode<T> *leftChild,   // ������
    *rightChild, // ������
    *parent;  // ���׽ڵ�
    bool isRed; // true��ʾΪ��ɫ��false��ʾΪ��ɫ

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
