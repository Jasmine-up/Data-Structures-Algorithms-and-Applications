/*
Project name :			_26maxHblt
Last modified Date:		2023年12月14日10点20分
Last Version:			V1.0
Descriptions:			最大高度优先左高树——树的节点类
*/

#ifndef _26MAXHBLT_MAXHBLTTREENODE_H
#define _26MAXHBLT_MAXHBLTTREENODE_H
template<class T>
struct maxHbltTreeNode
{
    int height;// 存储权重
    T element;
    maxHbltTreeNode<T>* leftChild,//左子树
    *rightChild;//右子树
    /*默认构造函数*/
    maxHbltTreeNode() { leftChild = rightChild = nullptr; height = 0; element = 0;}
    /*只初始化element*/
    explicit maxHbltTreeNode(T melement)
    {
        element = melement;
        height = 1;
        leftChild = rightChild = nullptr;
    }
    maxHbltTreeNode(T melement, int mheight)
    {
        element = melement;
        height = mheight;
        leftChild = rightChild = nullptr;
    }
    /*三个元素都初始化*/
    maxHbltTreeNode(T& melement, int mheight, maxHbltTreeNode<T>* mleftChild, maxHbltTreeNode<T>* mrightChild)
    {
        element = melement;
        height = mheight;
        leftChild = mleftChild;
        rightChild = mrightChild;
    }
};
#endif //_26MAXHBLT_MAXHBLTTREENODE_H
