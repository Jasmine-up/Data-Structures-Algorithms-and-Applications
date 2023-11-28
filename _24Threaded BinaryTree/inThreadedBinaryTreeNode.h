/*
Project name :			_24Threaded_BinaryTree
Last modified Date:		2023年11月28日17点06分
Last Version:			V1.0
Descriptions:			线索二叉树节点结构体
*/

#ifndef _24THREADED_BINARYTREE_INTHREADEDBINARYTREENODE_H
#define _24THREADED_BINARYTREE_INTHREADEDBINARYTREENODE_H
template<class T>
struct inThreadedBinaryTreeNode
{
    T element;
    inThreadedBinaryTreeNode<T>* leftChild,//左子树
    *rightChild;//右子树
    bool LTag, RTag;// 左右子树指针是否为索引，为True则是索引，否则不是索引
    /*默认构造函数*/
    inThreadedBinaryTreeNode() { leftChild = rightChild = nullptr; LTag = RTag = false;}
    /*只初始化element*/
    inThreadedBinaryTreeNode(T melement)
    {
        element = melement;
        leftChild = rightChild = nullptr;
        LTag = RTag = false;
    }
    /*三个元素都初始化*/
    inThreadedBinaryTreeNode(T melement, inThreadedBinaryTreeNode<T>* mleftChild, inThreadedBinaryTreeNode<T>* mrightChild)
    {
        element = melement;
        leftChild = mleftChild;
        rightChild = mrightChild;
        LTag = RTag = false;
    }
};
#endif //_24THREADED_BINARYTREE_INTHREADEDBINARYTREENODE_H
