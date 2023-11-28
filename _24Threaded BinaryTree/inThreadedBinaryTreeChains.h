/*
Project name :			_24Threaded_BinaryTree
Last modified Date:		2023年11月28日17点06分
Last Version:			V1.0
Descriptions:			线索二叉树链表表示
*/

#ifndef _24THREADED_BINARYTREE_INTHREADEDBINARYTREE_H
#define _24THREADED_BINARYTREE_INTHREADEDBINARYTREE_H
#include <iostream>
#include "binaryTree.h"
#include "inThreadedBinaryTreeNode.h"
using namespace std;
/*二叉树基础测试函数*/
void inThreadedBinaryTreeChainsTest();
template<class E>
class inThreadedBinaryTreeChains : public binaryTree<inThreadedBinaryTreeNode<E>>
{
public:
    /*二叉树的基础成员函数*/
    /*构造函数函数*/
    inThreadedBinaryTreeChains() {
        root = nullptr; treeSize = 0;
    }
    /*析构函数*/
    ~inThreadedBinaryTreeChains() { erase(); }
    /*当树为空时，返回true；否则，返回false*/
    bool empty() const { return treeSize == 0; }
    /*返回元素个数*/
    int size() const { return treeSize; }

    void inOrderThreaded()  // 中序遍历索引，就是中序遍历的时候添加索引
    {
        pre = nullptr;
        inOrderThreaded(root);
    }

    /*中序遍历二叉树，使用函数指针的目的是是的本函数可以实现多种目的*/
    void inOrder(void(*theVisit)(inThreadedBinaryTreeNode<E>*))
    {
        visit = theVisit;
        /*是因为递归，所以才要这样的*/
        inOrder(root);/*这里调用的是静态成员函数inOrder()*/
    }
    /*中序遍历---输出endl*/
    void inOrderOutput() { inOrder(output); cout << endl; }

    /*后续遍历二叉树，使用函数指针的目的是是的本函数可以实现多种目的*/
    void postOrder(void(*theVisit)(inThreadedBinaryTreeNode<E>*))
    {
        visit = theVisit;
        /*是因为递归，所以才要这样的*/
        postOrder(root);/*这里调用的是静态成员函数inOrder()*/
    }
    /*后序遍历---输出endl*/
    void postOrderOutput() { postOrder(output); cout << endl; }

    /*清空二叉树 这里必须使用后序遍历 不然会出错*/
    void erase()
    {
        postOrder(dispose);
        root = nullptr;
        treeSize = 0;
    }
    /*输入时为了将root根节点传递给createBiTree()函数*/
    void input(void)
    {
        createBiTree(root);
    }
private:
/*二叉树基础私有成员*/
    inThreadedBinaryTreeNode<E>* root;//指向根的指针
    int treeSize;//树的结点个数
    static inThreadedBinaryTreeNode<E>* pre;// 在线索化时使用的前驱temp
    static void (*visit)(inThreadedBinaryTreeNode<E>*);//是一个函数指针,返回值为void 函数参数为binaryTreeNode<E>*
    static void inOrder(inThreadedBinaryTreeNode<E>* t);
    static void inOrderThreaded(inThreadedBinaryTreeNode<E>* t);// 中序遍历索引，就是中序遍历的时候添加索引
    static void postOrder(inThreadedBinaryTreeNode<E>* t);
    static void dispose(inThreadedBinaryTreeNode<E>* t) { delete t; }
    static void output(inThreadedBinaryTreeNode<E>* t) { cout << t->element << " "; }
    /*创建二叉树---递归---作为私有成员只能被成员函数调用*/
    void createBiTree(inThreadedBinaryTreeNode<E>*& tree);
};
/*私有静态成员初始化*/
/*这里是静态函数指针成员的初始化，不初始化会引发LINK错误*/
template<class E>
void (*inThreadedBinaryTreeChains<E>::visit)(inThreadedBinaryTreeNode<E>*) = 0;      // visit function
// 这个地方需要做一个初始化，不做的话就会bug
template<class E>
inThreadedBinaryTreeNode<E>* inThreadedBinaryTreeChains<E>:: pre = nullptr;
/*中序遍历 递归*/
/*不受索引影响的中序遍历*/
template<class E>
void inThreadedBinaryTreeChains<E>::inOrder(inThreadedBinaryTreeNode<E>* t)
{
    if (t != nullptr)
    {
        // 在其左孩子不是索引时遍历
        if(!t->LTag)
            inOrder(t->leftChild);/*中序遍历左子树*/
        visit(t);/*访问树根*/
        // 在其右孩子不是索引时遍历
        if(!t->RTag)
            inOrder(t->rightChild);/*中序遍历右子树*/
    }
}
/*中序遍历索引 递归*/
/*本文写法可以保证在多次调用此函数下依然能正常执行，当插入新元素后再执行本函数可更新节点的索引*/
template<class E>
void inThreadedBinaryTreeChains<E>::inOrderThreaded(inThreadedBinaryTreeNode<E>* t)
{
    if (t != nullptr)
    {
        if(!t->LTag)
            inOrderThreaded(t->leftChild);/*中序遍历左子树*/
        if(!t->leftChild || t->LTag) // 没有左孩子，或者是第二次遍历即左孩子指向了他的前驱
        {
            t->LTag = true;
            t->leftChild = pre;
        }
        if(pre){
            if(!pre->rightChild || t->RTag)  // 如果前驱没有右孩子，或者是第二次遍历即右孩子指向了它的后继
            {
                pre->RTag = true;
                pre->rightChild = t;
            }
        }
        pre = t;
        if(!t->RTag)
            inOrderThreaded(t->rightChild);/*中序遍历右子树*/
    }
}
/*后序遍历 递归*/
/*不受索引影响的后序遍历*/
template<class E>
void inThreadedBinaryTreeChains<E>::postOrder(inThreadedBinaryTreeNode<E>* t)
{
    if (t != nullptr)
    {
        // 在其左孩子不是索引时遍历
        if(!t->LTag)
            postOrder(t->leftChild);/*后序遍历左子树*/
        // 在其右孩子不是索引时遍历
        if(!t->LTag)
            postOrder(t->rightChild);/*后序遍历右子树*/
        visit(t);/*访问树根*/
    }
}

/*创建二叉树---递归---模板的实现*/
template<class E>
void inThreadedBinaryTreeChains<E>::createBiTree(inThreadedBinaryTreeNode<E>*& tree)
{
    E data;
    cout << "Please enter the tree element:";
    while (!(cin >> data))
    {
        cin.clear();//清空标志位
        while (cin.get() != '\n')//删除无效的输入
            continue;
        cout << "Please enter the tree element:";
    }
    cin.get();
    /*针对char类型的特例*/
    if (typeid(data) == typeid(char)) {
        if (data == '#')
            tree = nullptr;
        else {
            treeSize++;
            tree = new inThreadedBinaryTreeNode<E>(data);
            createBiTree(tree->leftChild);
            createBiTree(tree->rightChild);
        }
    }
    else/*针对其他类型*/{
        if (data == 999)
            tree = nullptr;//当遇到999时，令树的根节点为nullptr,从而结束该分支的递归
        else
        {
            treeSize++;
            tree = new inThreadedBinaryTreeNode<E>(data);
            createBiTree(tree->leftChild);
            createBiTree(tree->rightChild);
        }
    }
}
#endif //_24THREADED_BINARYTREE_INTHREADEDBINARYTREE_H
