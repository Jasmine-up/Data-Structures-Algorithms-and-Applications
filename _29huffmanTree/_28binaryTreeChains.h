/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月27日09点44分
Last Version:			V1.0
Descriptions:			用链表表示的二叉树.h
笔记：
	1.静态函数指针初始化格式：void (*binaryTreeChains<E>::visit)(binaryTreeNode<E>*) = 0;
	2.不能单独专门化成员模板函数，只能针对整个类专门化。
	3.在模板函数中可以使用typeid()区别对待特定数据类型。
本程序注意事项：
	1.所有关于前缀、后缀、中缀表达式的全部使用了char类型代表元素，char类型数组存储整个表达式
*/
#pragma once
#ifndef _BINARYTREECHAINS_H_
#define _BINARYTREECHAINS_H_
#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
#include <queue>
#include "_1myExceptions.h"
#include "_28binaryTreeNode.h"
#include "_28binaryTree.h"
using namespace std;

template<class E>
class binaryTreeChains : public binaryTree<binaryTreeNode<E>>
{
public:
    /*二叉树的基础成员函数*/
    /*构造函数函数*/
    binaryTreeChains() {
        root = nullptr; treeSize = 0;
    }
    /*练习44:编写类linkedBinaryTree的一个复制构造函数。测试代码。*/
    /* 计算时间复杂性。复制构造函数*/
    binaryTreeChains(binaryTreeChains<E>& m) {
        root = treeCreateTree(m.root);
    }
    /*练习题33和练习题35*/
    /*构造函数---先序和中序遍历或后序和中序创建二叉树*/
    /*flag == false时，是先序和中序遍历构建二叉树；flag == true时，是后序和中序构建二叉树*/
    binaryTreeChains(E preOrPostOrder[], E inOrder[],int length,bool flag)
    {
        if(flag == false)
            root = preInCreateTree(preOrPostOrder, inOrder, length);
        else
            root = postInCreateTree(preOrPostOrder, inOrder, length);
    }
    /*构造函数---前缀或后缀或中缀表达式创建二叉树*/
    /*
    练习37：当flag = 1时，前缀表达式创建二叉树
    当flag = 2时，中缀表达式创建二叉树
    练习36：当flag = 3时，后缀表达式创建二叉树
    */
    binaryTreeChains(E expression[], int length,int flag)
    {
        switch (flag)
        {
            case 1:
                root = preExprCreateTree(expression, length);
                break;
            case 2:
                root = inExprCreateTree(expression, length);
                break;
            case 3:
                root = postExprCreateTree(expression, length);
                break;
        }
    }
    /*析构函数*/
    ~binaryTreeChains() { erase(); }
    /*当树为空时，返回true；否则，返回false*/
    bool empty() const { return treeSize == 0; }
    /*返回元素个数*/
    int size() const { return treeSize; }
    /*前序遍历二叉树，使用函数指针的目的是是的本函数可以实现多种目的*/
    void preOrder(void(*theVisit)(binaryTreeNode<E>*))
    {
        visit = theVisit;
        /*是因为递归，所以才要这样的*/
        preOrder(root);/*这里调用的是成员函数，preOrder()*/
    }
    /*前序遍历---输出endl*/
    void preOrderOutput() { preOrder(output); cout << endl; }
    /*前序遍历---不使用递归而使用迭代函数*/
    vector<E> iterativePreOrder();

    /*中序遍历二叉树，使用函数指针的目的是是的本函数可以实现多种目的*/
    void inOrder(void(*theVisit)(binaryTreeNode<E>*))
    {
        visit = theVisit;
        /*是因为递归，所以才要这样的*/
        inOrder(root);/*这里调用的是静态成员函数inOrder()*/
    }
    /*中序遍历---输出endl*/
    void inOrderOutput() { inOrder(output); cout << endl; }
    /*中序遍历---不使用递归而使用迭代函数*/
    vector<E> iterativeInOrder();

    /*后续遍历二叉树，使用函数指针的目的是是的本函数可以实现多种目的*/
    void postOrder(void(*theVisit)(binaryTreeNode<E>*))
    {
        visit = theVisit;
        /*是因为递归，所以才要这样的*/
        postOrder(root);/*这里调用的是静态成员函数inOrder()*/
    }
    /*后序遍历---输出endl*/
    void postOrderOutput() { postOrder(output); cout << endl; }
    /*后序遍历---不使用递归而使用迭代函数*/
    vector<E> iterativePostOrder();

    /*层次遍历二叉树*/
    void levelOrder(void (*theVisit)(binaryTreeNode<E>*));
    /*层次遍历---输出endl*/
    void levelOrderOutput() { levelOrder(output); cout << endl; }

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
    /*是一个手动创建二叉树的函数，使用本函数得手动设置各节点之间的关系，见信号放大器应用的使用*/
    /*将左数和右数合并为一个树(也就是this树)*/
    void makeTree(const E& element, binaryTreeChains<E>&, binaryTreeChains<E>&);
    /*练习45：比较二叉树*this和二叉树m*/
    bool compare(binaryTreeChains<E>& m)
    {
        return compareTree(root, m.root);
    }
    /*练习46：交换每一个结点的左右子树*/
    void swapTrees()
    {
        swapTrees(root);
    }
    /*练习27：计算二叉树高度*/
    int height() const { return height(root); }
    /*练习47：计算二叉树的最大高度差*/
    int maxHeightDifference()
    {
        return maxHeightDifference(root);
    }
    /*练习29：计算二叉树在那一层具有最多的结点---返回值为结点最多的层*/
    int layerMaxNumOfNode();
    /*计算二叉树在在哪一层具有最多的结点--返回值为结点最多的层的结点数量*/
    int maxNumOfNodeInLayer();


    /*二叉树表达式的成员函数*/
    /*计算树的表达式的值*/
    int compulateTree()
    {
        return compulateTree(root);
    }
private:
    /*二叉树基础私有成员*/
    binaryTreeNode<E>* root;//指向根的指针
    int treeSize;//树的结点个数
    static void (*visit)(binaryTreeNode<E>*);//是一个函数指针,返回值为void 函数参数为binaryTreeNode<E>*
    static void preOrder(binaryTreeNode<E>* t);
    static void inOrder(binaryTreeNode<E>* t);
    static void postOrder(binaryTreeNode<E>* t);
    static void dispose(binaryTreeNode<E>* t) { delete t; }
    static void output(binaryTreeNode<E>* t) { cout << t->element << " "; }
    /*创建二叉树---递归---作为私有成员只能被成员函数调用*/
    void createBiTree(binaryTreeNode<E>*& tree);
    /*复制构造函数调用的函数*/
    binaryTreeNode<E>* treeCreateTree(binaryTreeNode<E>*& node);
    /*私有成员函数---用于比较二叉树compare()*/
    bool compareTree(binaryTreeNode<E>* thisNode, binaryTreeNode<E>* xNode);
    /*私有成员函数---交换树的每个结点的左右子树---递归*/
    void swapTrees(binaryTreeNode<E>*& node);
    /*私有成员函数---计算二叉树高度---返回根为node的树的高度*/
    int height(binaryTreeNode<E>* node) const;
    /*私有成员函数---计算结点node的左右子树高度的差值*/
    int heightDifference(binaryTreeNode<E>* node) const;
    /*私有成员函数---计算二叉树的最大高度差---返回值为二叉树的最大高度差*/
    int maxHeightDifference(binaryTreeNode<E>* node) const;
    binaryTreeNode<E>* preInCreateTree(E preOrder[], E inOrder[], int size);
    binaryTreeNode<E>* postInCreateTree(E postOrder[], E inOrder[], int size);


    /*二叉树表达式的私有成员*/
    /*计算树的表达式的值*/
    /*本程序所有关于前缀、中缀、后缀表达式的处理全部是char类型，并且只能进行个位数的计算*/
    int compulateTree(binaryTreeNode<E>* node) const;
    binaryTreeNode<E>* preExprCreateTree(E expression[], int length);
    binaryTreeNode<E>* inExprCreateTree(E expression[], int length);
    binaryTreeNode<E>* postExprCreateTree(E expression[], int length);
};

/*私有静态成员初始化*/
/*这里是静态函数指针成员的初始化，不初始化会引发LINK错误*/
template<class E>
void (*binaryTreeChains<E>::visit)(binaryTreeNode<E>*) = 0;      // visit function

/*二叉树的普通成员函数*/
/*前序遍历 递归*/
template<class E>
void binaryTreeChains<E>::preOrder(binaryTreeNode<E>* t)
{
    if (t != nullptr)
    {
        visit(t);/*访问树根*/
        preOrder(t->leftChild);/*前序遍历左子树*/
        preOrder(t->rightChild);/*前序遍历右子树*/
    }
}
/*前序遍历---不使用递归而使用迭代函数*/
template<class E>
vector<E> binaryTreeChains<E>::iterativePreOrder()
{
    binaryTreeNode<E>* currentNode = root;
    stack<binaryTreeNode<E>*> st;
    vector<E> result;

    /*写法1---前序中序后序遍历非递归统一版*/
    /*首先将父节点入栈*/
    if (currentNode != nullptr)
        st.push(currentNode);
    while (!st.empty())
    {
        currentNode = st.top();
        st.pop();
        /*如果遇到nullptr,则输出当前栈顶元素*/
        if (currentNode == nullptr)
        {
            result.push_back(st.top()->element);
            st.pop();
        }
            /*如果没有遇到nullptr,则按照右左中的顺序入栈结点，最后入栈nullptr*/
        else
        {
            if (currentNode->rightChild != nullptr)
                st.push(currentNode->rightChild);
            if (currentNode->leftChild != nullptr)
                st.push(currentNode->leftChild);
            st.push(currentNode);
            /*每次都在已遍历的根节点后入栈nullptr*/
            st.push(nullptr);
        }
    }

    ///*写法2*/
    ///*当结点为nullptr并且栈为空时结束循环*/
    //while (currentNode != nullptr || !st.empty())
    //{
    //	/*先将左边的左边的元素入栈*/
    //	while (currentNode != nullptr)
    //	{
    //		st.push(currentNode);
    //		result.push_back(currentNode->element);
    //		currentNode = currentNode->leftChild;
    //	}
    //	/*然后一个一个遍历左边的元素，并将该元素存储到vector中*/
    //	currentNode = st.top();
    //	st.pop();
    //	currentNode = currentNode->rightChild;
    //}
    return result;
}

/*中序遍历 递归*/
template<class E>
void binaryTreeChains<E>::inOrder(binaryTreeNode<E>* t)
{
    if (t != nullptr)
    {
        inOrder(t->leftChild);/*中序遍历左子树*/
        visit(t);/*访问树根*/
        inOrder(t->rightChild);/*中序遍历右子树*/
    }
}
/*中序遍历---不使用递归而使用迭代函数*/
template<class E>
vector<E> binaryTreeChains<E>::iterativeInOrder()
{
    binaryTreeNode<E>* currentNode = root;
    stack<binaryTreeNode<E>*> st;
    vector<E> result;
    /*写法1---前序中序后序遍历非递归统一版*/
    /*首先将父节点入栈*/
    if (currentNode != nullptr)
        st.push(currentNode);
    while (!st.empty())
    {
        currentNode = st.top();
        st.pop();
        /*如果遇到nullptr,则输出当前栈顶元素*/
        if (currentNode == nullptr)
        {
            result.push_back(st.top()->element);
            st.pop();
        }
            /*如果没有遇到nullptr,则按照右左中的顺序入栈结点，最后入栈nullptr*/
        else
        {
            if (currentNode->rightChild != nullptr)
                st.push(currentNode->rightChild);
            st.push(currentNode);
            /*每次都在已遍历的根节点后入栈nullptr*/
            st.push(nullptr);
            if (currentNode->leftChild != nullptr)
                st.push(currentNode->leftChild);
        }
    }
    /*写法2*/
    ///*当结点为nullptr并且栈为空时结束循环*/
    //while (currentNode != nullptr || !st.empty())
    //{
    //	/*先将左边的左边的元素入栈*/
    //	while (currentNode != nullptr)
    //	{
    //		st.push(currentNode);
    //		currentNode = currentNode->leftChild;
    //	}
    //	/*然后一个一个遍历左边的元素，并将该元素存储到vector中*/
    //	currentNode = st.top();
    //	st.pop();
    //	result.push_back(currentNode->element);
    //	currentNode = currentNode->rightChild;
    //}
    return result;
}

/*后序遍历 递归*/
template<class E>
void binaryTreeChains<E>::postOrder(binaryTreeNode<E>* t)
{
    if (t != nullptr)
    {
        postOrder(t->leftChild);/*后序遍历左子树*/
        postOrder(t->rightChild);/*后序遍历右子树*/
        visit(t);/*访问树根*/
    }
}
/*后序遍历---不使用递归而使用迭代函数*/
template<class E>
vector<E> binaryTreeChains<E>::iterativePostOrder()
{
    binaryTreeNode<E>* currentNode = root;
    stack<binaryTreeNode<E>*> st;
    vector<E> result;
    /*前序中序后序遍历非递归统一版*/
    /*首先将父节点入栈*/
    if (currentNode != nullptr)
        st.push(currentNode);
    while (!st.empty())
    {
        currentNode = st.top();
        st.pop();
        /*如果遇到nullptr,则输出当前栈顶元素*/
        if (currentNode == nullptr)
        {
            result.push_back(st.top()->element);
            st.pop();
        }
            /*如果没有遇到nullptr,则按照右左中的顺序入栈结点，最后入栈nullptr*/
        else
        {
            st.push(currentNode);
            /*每次都在已遍历的根节点后入栈nullptr*/
            st.push(nullptr);
            if (currentNode->rightChild != nullptr)
                st.push(currentNode->rightChild);
            if (currentNode->leftChild != nullptr)
                st.push(currentNode->leftChild);
        }
    }
    return result;
}

/*层次遍历二叉树 非递归*/
template<class E>
void binaryTreeChains<E>::levelOrder(void (*theVisit)(binaryTreeNode<E>*))
{
    visit = theVisit;
    binaryTreeNode<E>* temp;
    queue<binaryTreeNode<E>*> que;
    que.push(root);
    while (!que.empty())
    {
        temp = que.front();
        que.pop();
        visit(temp);
        if (temp->leftChild != nullptr)
            que.push(temp->leftChild);
        if (temp->rightChild != nullptr)
            que.push(temp->rightChild);
    }
}
/*创建二叉树---递归---模板的实现*/
template<class E>
void binaryTreeChains<E>::createBiTree(binaryTreeNode<E>*& tree)
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
            tree = new binaryTreeNode<E>(data);
            createBiTree(tree->leftChild);
            createBiTree(tree->rightChild);
        }
        /*关于二叉树对于设置信号放大器的应用我新定义了成员函数maketree()生成二叉树
            这里会报错：C2228“.degradeFromParent”的左边必须有类/结构/联合
            我实在是不知道怎么改
        */
        //else if (typeid(data) == typeid(booster))
        //	if (data.degradeFromParent == 999)
        //		tree = nullptr;
        //	else
        //	{
        //		treeSize++;
        //		tree = new binaryTreeNode<E>(data);
        //		createBiTree(tree->leftChild);
        //		createBiTree(tree->rightChild);
        //	}
    }
    else/*针对其他类型*/{
        if (data == 999)
            tree = nullptr;//当遇到999时，令树的根节点为nullptr,从而结束该分支的递归
        else
        {
            treeSize++;
            tree = new binaryTreeNode<E>(data);
            createBiTree(tree->leftChild);
            createBiTree(tree->rightChild);
        }
    }
}
/*是一个手动创建二叉树的函数，使用本函数得手动设置各节点之间的关系，见信号放大器应用的使用*/
/*将左树和右树合并为一个树*/
template<class E>
void binaryTreeChains<E>::makeTree(const E& element, binaryTreeChains<E>& left, binaryTreeChains<E>& right)
{// Combine left, right, and element to make new tree.
    // left, right, and this must be different trees.
    // create combined tree
    root = new binaryTreeNode<E>(element, left.root, right.root);
    treeSize = left.treeSize + right.treeSize + 1;

    // deny access from trees left and right
    left.root = right.root = NULL;
    left.treeSize = right.treeSize = 0;
}

/*练习24：根据二叉树创建二叉树---用于复制构造函数*/
template<class E>
binaryTreeNode<E>* binaryTreeChains<E>::treeCreateTree(binaryTreeNode<E>*& node)
{
    binaryTreeNode<E>* head = nullptr;
    if (node != nullptr)
    {
        treeSize++;
//        cout << "node->element = " << node->element << endl;
        head = new binaryTreeNode<E>(node->element);
        head->leftChild = treeCreateTree(node->leftChild);
        head->rightChild = treeCreateTree(node->rightChild);
    }
    return head;
}

/*练习45：私有成员函数---用于比较二叉树compare()*/
template<class E>
bool binaryTreeChains<E>::compareTree(binaryTreeNode<E>* thisNode, binaryTreeNode<E>* xNode)
{
    /*两个结点都为空时，二叉树相等*/
    if (thisNode == nullptr && xNode == nullptr)
        return true;
    /*一个结点为空，一个结点非空，则二叉树不相等*/
    if ((thisNode == nullptr && xNode != nullptr) || (thisNode != nullptr && xNode == nullptr))
        return false;
    /*两个结点的元素不等，则二叉树不相等*/
    if (thisNode->element != xNode->element)
        return false;
    else/*两个结点相等，则比较彼此的左子树和右子树*/
        return compareTree(thisNode->leftChild, xNode->leftChild) && compareTree(thisNode->rightChild, xNode->rightChild);
}

/*练习46：私有成员函数---交换树的每个结点的左右子树---递归*/
template<class E>
void binaryTreeChains<E>::swapTrees(binaryTreeNode<E>*& node)
{
    if (node != nullptr)
    {
        swapTrees(node->leftChild);
        swapTrees(node->rightChild);
        binaryTreeNode<E>* temp = node->leftChild;
        node->leftChild = node->rightChild;
        node->rightChild = temp;
    }
}

/*练习27：私有成员函数---计算二叉树高度---返回根为node的树的高度*/
template<class E>
int binaryTreeChains<E>::height(binaryTreeNode<E>* node) const
{
    if (node == nullptr)
        return 0;
    int hl = height(node->leftChild);
    int hr = height(node ->rightChild);
    if (hl > hr)
        return ++hl;
    else
        return ++hr;
}

/*私有成员函数---计算结点node的左右子树高度的差值*/
template<class E>
int binaryTreeChains<E>::heightDifference(binaryTreeNode<E>* node) const
{
    if (node == nullptr)
        return 0;
    int lh = height(node->leftChild);
    int rh = height(node->rightChild);
//    cout << node->element << ":" << lh << endl;
//    cout << node->element << ":" << rh << endl;

    if (lh > rh)
        return lh - rh;
    else
        return rh - lh;
}

/*练习47：私有成员函数---计算二叉树的最大高度差---返回值为二叉树的最大高度差*/
template<class E>
int binaryTreeChains<E>::maxHeightDifference(binaryTreeNode<E>* node) const
{
    if (node == nullptr)
        return 0;
    int height = heightDifference(node);//当前结点的左右子树的高度差
    int hl = maxHeightDifference(node->leftChild);//当前结点的左子树的左右子树的高度差
    int hr = maxHeightDifference(node->rightChild);//当前结点的右子树的左右子树的高度差

    if (height >= hl && height >= hr)
        return height;
    else if (hl >= height && hl >= hr)
        return hl;
    else if (hr >= height && hr >= hl)
        return hr;
}

/*练习29：计算二叉树在那一层具有最多的结点---返回值为结点最多的层*/
/*当二叉树为空时，返回0*/
template<class E>
int binaryTreeChains<E>::layerMaxNumOfNode()
{
    if (root == nullptr)
        return 0;
    int num = 0;//累加每层的结点数
    int layer = 0;//记录当前的层数
    int maxNum = 0;//存储结点最多的层的结点个数
    int maxLayer = 0;//存储结点最多的层的层数
    binaryTreeNode<E>* lastNode = root;//存储上一层最后一个结点的元素位置
    binaryTreeNode<E>* nextNode = nullptr;//存储当前层最后一个结点的元素位置
    binaryTreeNode<E>* currentNode;
    queue<binaryTreeNode<E>*> que;
    que.push(root);
    while (!que.empty())
    {
        currentNode = que.front();
        que.pop();
        num++;
        if (currentNode->leftChild != nullptr)
        {
            que.push(currentNode->leftChild);
            nextNode = currentNode->leftChild;
        }
        if (currentNode->rightChild != nullptr)
        {
            que.push(currentNode->rightChild);
            nextNode = currentNode->rightChild;
        }
        if (currentNode == lastNode)
        {
            layer++;//刚刚处理完第几层
            lastNode = nextNode;
            nextNode = nullptr;
            if (num > maxNum)
            {
                maxNum = num;
                maxLayer = layer;
            }
            num = 0;
        }
    }
    return maxLayer;
}

/*计算二叉树在在哪一层具有最多的结点--返回值为结点最多的层的结点数量*/
/*当二叉树为空时，返回0*/
template<class E>
int binaryTreeChains<E>::maxNumOfNodeInLayer()
{
    if (root == nullptr)
        return 0;
    int num = 0;//累加每层的结点数
    int layer = 0;//记录当前的层数
    int maxNum = 0;//存储结点最多的层的结点个数
    int maxLayer = 0;//存储结点最多的层的层数
    binaryTreeNode<E>* lastNode = root;//存储上一层最后一个结点的元素位置
    binaryTreeNode<E>* nextNode = nullptr;//存储当前层最后一个结点的元素位置
    binaryTreeNode<E>* currentNode = nullptr;
    queue<binaryTreeNode<E>*> que;
    que.push(root);
    while (!que.empty())
    {
        currentNode = que.front();
        que.pop();
        num++;
        if (currentNode->leftChild != nullptr)
        {
            que.push(currentNode->leftChild);
            nextNode = currentNode->leftChild;
        }
        if (currentNode->rightChild != nullptr)
        {
            que.push(currentNode->rightChild);
            nextNode = currentNode->rightChild;
        }
        if (currentNode == lastNode)
        {
            layer++;//刚刚处理完第几层
            lastNode = nextNode;
            nextNode = nullptr;
            if (num > maxNum)
            {
                maxNum = num;
                maxLayer = layer;
            }
            num = 0;
        }
    }
    return maxNum;
}

/*使用前序和中序遍历构建二叉树*/
/*关键点在于找到根节点在中序中的位置，该位置之前为该根的左子树，该位置之后为该根的右子树*/
template<class E>
binaryTreeNode<E>* binaryTreeChains<E>::preInCreateTree(E preOrder[], E inOrder[], int size)
{
    /*如果没有左右子树，则返回nullptr*/
    if (size == 0)
        return nullptr;
    binaryTreeNode<E>*  rootData = new binaryTreeNode<E>(preOrder[0]);
    /*找到根节点的位置，中序中该位置左侧就是该根节点的左子树，该位置右侧就是该根节点的右子树*/
    int rootLoc = findRootLoc<E>(inOrder, preOrder[0] ,size);
    /*创建左子树和右子树*/
    rootData->leftChild = preInCreateTree(preOrder + 1, inOrder, rootLoc);
    rootData->rightChild = preInCreateTree(preOrder + 1 + rootLoc, inOrder + rootLoc + 1, size - 1 - rootLoc);
    return rootData;
}
/*使用后序和中序遍历构建二叉树*/
/*关键点在于找到根节点在中序中的位置，该位置之前为该根的左子树，该位置之后为该根的右子树*/
template<class E>
binaryTreeNode<E>* binaryTreeChains<E>::postInCreateTree(E postOrder[], E inOrder[], int size)
{
    /*如果没有左右子树，则返回nullptr*/
    if (size == 0)
        return nullptr;
    binaryTreeNode<E>* rootData = new binaryTreeNode<E>(postOrder[size-1]);
    /*找到根节点的位置，中序中该位置左侧就是该根节点的左子树，该位置右侧就是该根节点的右子树*/
    int rootLoc = findRootLoc<E>(inOrder, postOrder[size-1], size);
    /*创建左子树和右子树*/
    rootData->leftChild = postInCreateTree(postOrder, inOrder, rootLoc);
    rootData->rightChild = postInCreateTree(postOrder + rootLoc, inOrder + rootLoc + 1, size - 1 - rootLoc);
    return rootData;
}


/*二叉树表达式的成员函数*/
/*计算树的表达式的值*/
/*用字符串记录表达式*/
/*这个函数需要使用char类型的树，其他类型的二叉树不满足要求*/
template<class E>
int binaryTreeChains<E>::compulateTree(binaryTreeNode<E>* node) const
{
    if (node == nullptr)
        return 0;
    if (node->leftChild == nullptr && node->rightChild == nullptr) //左右子树都是nullptr时，说明它是叶子节点，而叶子结点就是数而非符号
        return node->element - '0';//就返回叶子结点
    int a = compulateTree(node->leftChild);//先计算左子树
    int b = compulateTree(node->rightChild);//再计算右子树
    switch (node->element)//当前结点不是叶子节点时，说明他是符号结点
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            if (b != 0)
                return a / b;
            else
                throw illegalParameterValue("除数不能为0！");
    }
}

/*使用全部是二元操作符的前缀表达式创建二叉树*/
/*从尾元素开始遍历表达式的元素*/
/*如果是数据，则生成binaryTreeNode并入栈*/
/*如果不是数据，则生成binaryTreeNode，从栈中弹出两个数据形成其子树,第一个弹出的是其左子树，第二个弹出的是其右子树；然后再将当前结点入栈*/
template<class E>
binaryTreeNode<E>* binaryTreeChains<E>::preExprCreateTree(E expression[],int length)
{
    stack<binaryTreeNode<E>*> st;//用于存储已经处理的数据生成的binaryTreeNode
    binaryTreeNode<E>* temp = nullptr;
    for (int i = length-1; i >= 0; i--)
    {
        /*如果是数据，则生成二叉树结点入栈*/
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            temp = new binaryTreeNode<E>(expression[i]);
            st.push(temp);
        }
        else
        {
            temp = new binaryTreeNode<E>(expression[i]);
            temp->leftChild = st.top();
            st.pop();
            temp->rightChild = st.top();
            st.pop();
            st.push(temp);
        }
    }
    return temp;
}

/*使用全部是二元操作符的中缀表达式(包含括号以表明优先级)创建二叉树*/
/*如果是数据，则生成binaryTreeNode并入数据栈*/
/*
操作符处理规则：
	如果当前操作符优先级大于操作符栈的顶部元素，直接入操作符栈
	如果当前操作符优先级小于或等于操作符栈的顶部元素，先将顶部元素出操作符栈再将当前操作符入操作符栈
	当前操作符为左括号时直接入栈
	当前操作符为右括号时，让栈顶到左括号为止的操作符出操作符栈，括号不出现在后缀表达式中
出操作符栈时：生成当前符号的binaryTreeNode，其右子树为数据栈的栈顶元素，数据栈顶元素出栈，其左子树为数据栈当前的栈顶元素，数据栈顶元素出栈；
			  当前符号binaryTreeNode入数据栈。
*/
/*获取操作符优先级的getPriority()函数是一个非成员函数*/
template<class E>
binaryTreeNode<E>* binaryTreeChains<E>::inExprCreateTree(E expression[], int length)
{
    stack<binaryTreeNode<E>*> st;//用于存储已经处理的数据生成的binaryTreeNode
    stack<E> opStack;
    binaryTreeNode<E>* temp = nullptr;
    E data;
    for (int i = 0; i < length; i++)
    {
        data = expression[i];
        /*如果是数据，则生成二叉树结点入栈*/
        if (data >= '0' && data <= '9')
        {
            temp = new binaryTreeNode<E>(data);
            st.push(temp);
        }
        else
        {
            if (opStack.empty())
                opStack.push(data);
            else
                switch (data)
                {
                    case '(':opStack.push(data); break;//当遇到左括号时，直接将其入栈
                    case ')'://当遇到右括号时，让栈顶到左括号的操作符出栈
                        while (opStack.top() != '(')
                        {
                            temp = new binaryTreeNode<E>(opStack.top());
                            opStack.pop();
                            temp->rightChild = st.top();
                            st.pop();
                            temp->leftChild = st.top();
                            st.pop();
                            st.push(temp);
                        }
                        opStack.pop();//让(出栈
                        break;
                        /*当遇到+ - * /时,当其优先级大于栈顶元素时，入栈；否则，先将栈顶元素出栈，再将当前元素入栈*/
                    case '+':
                    case '-':
                    case '*':
                    case '/':
                        if (getPriority(data) > getPriority(opStack.top()))
                            opStack.push(data);
                        else
                        {
                            temp = new binaryTreeNode<E>(opStack.top());
                            opStack.pop();
                            temp->rightChild = st.top();
                            st.pop();
                            temp->leftChild = st.top();
                            st.pop();
                            st.push(temp);
                        }
                        break;
                    default:break;
                }
            /*当检查到中缀表达式的最后一个元素且栈非空时，将栈中的元素全部输出到后缀表达式*/
            if (!opStack.empty() && i == length - 1)
                while (!opStack.empty())
                {
                    temp = new binaryTreeNode<E>(opStack.top());
                    opStack.pop();
                    temp->rightChild = st.top();
                    st.pop();
                    temp->leftChild = st.top();
                    st.pop();
                    st.push(temp);
                }
        }
    }
    return temp;
}

/*使用全部是二元操作符的后缀表达式创建二叉树*/
/*从首元素开始遍历表达式的元素*/
/*如果是数据，则生成binaryTreeNode并入栈*/
/*如果不是数据，则生成binaryTreeNode，从栈中弹出两个数据形成其子树,第一个弹出的是其右子树，第二个弹出的是其左子树；然后再将当前结点入栈*/
template<class E>
binaryTreeNode<E>* binaryTreeChains<E>::postExprCreateTree(E expression[], int length)
{
    stack<binaryTreeNode<E>*> st;//用于存储已经处理的数据生成的binaryTreeNode
    binaryTreeNode<E>* temp = nullptr;
    for (int i = 0; i < length; i++)
    {
        /*如果是数据，则生成二叉树结点入栈*/
        if (expression[i] >= '0' && expression[i] <= '9')
        {
            temp = new binaryTreeNode<E>(expression[i]);
            st.push(temp);
        }
        else
        {
            temp = new binaryTreeNode<E>(expression[i]);
            temp->rightChild = st.top();
            st.pop();
            temp->leftChild = st.top();
            st.pop();
            st.push(temp);
        }
    }
    return temp;
}

#endif