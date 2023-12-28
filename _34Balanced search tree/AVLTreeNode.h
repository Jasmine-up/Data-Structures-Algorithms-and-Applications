/*
Project name :			_34Balanced_search_tree
Last modified Date:		2023��12��27��10��57��
Last Version:			V1.0
Descriptions:			AVL���ڵ�ģ����
*/

#ifndef _34BALANCED_SEARCH_TREE_AVLTREENODE_H
#define _34BALANCED_SEARCH_TREE_AVLTREENODE_H

template<class T>
struct AVLTreeNode {
    T element;
    AVLTreeNode<T> *leftChild,   // ������
    *rightChild;  // ������
    // ��¼height���ɣ���Ҫbf��ֵ���Ը���height�����㣬����bfֵ����û���ر�����壬ֻ��Ϊ�˷���������ֲ�ƽ������
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
