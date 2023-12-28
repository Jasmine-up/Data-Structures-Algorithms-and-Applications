/*
Project name :			_34Balanced_search_tree
Last modified Date:		2023年12月27日10点57分
Last Version:			V1.0
Descriptions:			AVL树节点模板类
*/

#ifndef _34BALANCED_SEARCH_TREE_AVLTREENODE_H
#define _34BALANCED_SEARCH_TREE_AVLTREENODE_H

template<class T>
struct AVLTreeNode {
    T element;
    AVLTreeNode<T> *leftChild,   // 左子树
    *rightChild;  // 右子树
    // 记录height即可，需要bf的值可以根据height来计算，但是bf值本身没有特别的意义，只是为了方便分析各种不平衡的情况
    int height;

    AVLTreeNode() {
        leftChild = rightChild = nullptr;
        height = 0;
    }

    explicit AVLTreeNode(T &theElement) : element(theElement) {
        leftChild = rightChild = nullptr;
        height = 0;
    }

    explicit AVLTreeNode(T &theElement,
                AVLTreeNode *theLeftChild,
                AVLTreeNode *theRightChild)
            : element(theElement), leftChild(theLeftChild), rightChild(theRightChild) {
        height = 0;
    }
    explicit AVLTreeNode(T &theElement,
                AVLTreeNode *theLeftChild,
                AVLTreeNode *theRightChild, int theHeight)
            : element(theElement), leftChild(theLeftChild), rightChild(theRightChild) {
        height = theHeight;
    }
};

#endif //_34BALANCED_SEARCH_TREE_AVLTREENODE_H
