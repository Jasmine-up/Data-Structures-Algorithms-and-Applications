/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��27��09��44��
Last Version:			V1.0
Descriptions:			�������ʾ�Ķ�����.h
�ʼǣ�
	1.��̬����ָ���ʼ����ʽ��void (*binaryTreeChains<E>::visit)(binaryTreeNode<E>*) = 0;
	2.���ܵ���ר�Ż���Աģ�庯����ֻ�����������ר�Ż���
	3.��ģ�庯���п���ʹ��typeid()����Դ��ض��������͡�
������ע�����
	1.���й���ǰ׺����׺����׺���ʽ��ȫ��ʹ����char���ʹ���Ԫ�أ�char��������洢�������ʽ
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
    /*�������Ļ�����Ա����*/
    /*���캯������*/
    binaryTreeChains() {
        root = nullptr; treeSize = 0;
    }
    /*��ϰ44:��д��linkedBinaryTree��һ�����ƹ��캯�������Դ��롣*/
    /* ����ʱ�临���ԡ����ƹ��캯��*/
    binaryTreeChains(binaryTreeChains<E>& m) {
        root = treeCreateTree(m.root);
    }
    /*��ϰ��33����ϰ��35*/
    /*���캯��---���������������������򴴽�������*/
    /*flag == falseʱ����������������������������flag == trueʱ���Ǻ�������򹹽�������*/
    binaryTreeChains(E preOrPostOrder[], E inOrder[],int length,bool flag)
    {
        if(flag == false)
            root = preInCreateTree(preOrPostOrder, inOrder, length);
        else
            root = postInCreateTree(preOrPostOrder, inOrder, length);
    }
    /*���캯��---ǰ׺���׺����׺���ʽ����������*/
    /*
    ��ϰ37����flag = 1ʱ��ǰ׺���ʽ����������
    ��flag = 2ʱ����׺���ʽ����������
    ��ϰ36����flag = 3ʱ����׺���ʽ����������
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
    /*��������*/
    ~binaryTreeChains() { erase(); }
    /*����Ϊ��ʱ������true�����򣬷���false*/
    bool empty() const { return treeSize == 0; }
    /*����Ԫ�ظ���*/
    int size() const { return treeSize; }
    /*ǰ�������������ʹ�ú���ָ���Ŀ�����ǵı���������ʵ�ֶ���Ŀ��*/
    void preOrder(void(*theVisit)(binaryTreeNode<E>*))
    {
        visit = theVisit;
        /*����Ϊ�ݹ飬���Բ�Ҫ������*/
        preOrder(root);/*������õ��ǳ�Ա������preOrder()*/
    }
    /*ǰ�����---���endl*/
    void preOrderOutput() { preOrder(output); cout << endl; }
    /*ǰ�����---��ʹ�õݹ��ʹ�õ�������*/
    vector<E> iterativePreOrder();

    /*���������������ʹ�ú���ָ���Ŀ�����ǵı���������ʵ�ֶ���Ŀ��*/
    void inOrder(void(*theVisit)(binaryTreeNode<E>*))
    {
        visit = theVisit;
        /*����Ϊ�ݹ飬���Բ�Ҫ������*/
        inOrder(root);/*������õ��Ǿ�̬��Ա����inOrder()*/
    }
    /*�������---���endl*/
    void inOrderOutput() { inOrder(output); cout << endl; }
    /*�������---��ʹ�õݹ��ʹ�õ�������*/
    vector<E> iterativeInOrder();

    /*����������������ʹ�ú���ָ���Ŀ�����ǵı���������ʵ�ֶ���Ŀ��*/
    void postOrder(void(*theVisit)(binaryTreeNode<E>*))
    {
        visit = theVisit;
        /*����Ϊ�ݹ飬���Բ�Ҫ������*/
        postOrder(root);/*������õ��Ǿ�̬��Ա����inOrder()*/
    }
    /*�������---���endl*/
    void postOrderOutput() { postOrder(output); cout << endl; }
    /*�������---��ʹ�õݹ��ʹ�õ�������*/
    vector<E> iterativePostOrder();

    /*��α���������*/
    void levelOrder(void (*theVisit)(binaryTreeNode<E>*));
    /*��α���---���endl*/
    void levelOrderOutput() { levelOrder(output); cout << endl; }

    /*��ն����� �������ʹ�ú������ ��Ȼ�����*/
    void erase()
    {
        postOrder(dispose);
        root = nullptr;
        treeSize = 0;
    }
    /*����ʱΪ�˽�root���ڵ㴫�ݸ�createBiTree()����*/
    void input(void)
    {
        createBiTree(root);
    }
    /*��һ���ֶ������������ĺ�����ʹ�ñ��������ֶ����ø��ڵ�֮��Ĺ�ϵ�����źŷŴ���Ӧ�õ�ʹ��*/
    /*�������������ϲ�Ϊһ����(Ҳ����this��)*/
    void makeTree(const E& element, binaryTreeChains<E>&, binaryTreeChains<E>&);
    /*��ϰ45���Ƚ϶�����*this�Ͷ�����m*/
    bool compare(binaryTreeChains<E>& m)
    {
        return compareTree(root, m.root);
    }
    /*��ϰ46������ÿһ��������������*/
    void swapTrees()
    {
        swapTrees(root);
    }
    /*��ϰ27������������߶�*/
    int height() const { return height(root); }
    /*��ϰ47����������������߶Ȳ�*/
    int maxHeightDifference()
    {
        return maxHeightDifference(root);
    }
    /*��ϰ29���������������һ��������Ľ��---����ֵΪ������Ĳ�*/
    int layerMaxNumOfNode();
    /*���������������һ��������Ľ��--����ֵΪ������Ĳ�Ľ������*/
    int maxNumOfNodeInLayer();


    /*���������ʽ�ĳ�Ա����*/
    /*�������ı��ʽ��ֵ*/
    int compulateTree()
    {
        return compulateTree(root);
    }
private:
    /*����������˽�г�Ա*/
    binaryTreeNode<E>* root;//ָ�����ָ��
    int treeSize;//���Ľ�����
    static void (*visit)(binaryTreeNode<E>*);//��һ������ָ��,����ֵΪvoid ��������ΪbinaryTreeNode<E>*
    static void preOrder(binaryTreeNode<E>* t);
    static void inOrder(binaryTreeNode<E>* t);
    static void postOrder(binaryTreeNode<E>* t);
    static void dispose(binaryTreeNode<E>* t) { delete t; }
    static void output(binaryTreeNode<E>* t) { cout << t->element << " "; }
    /*����������---�ݹ�---��Ϊ˽�г�Աֻ�ܱ���Ա��������*/
    void createBiTree(binaryTreeNode<E>*& tree);
    /*���ƹ��캯�����õĺ���*/
    binaryTreeNode<E>* treeCreateTree(binaryTreeNode<E>*& node);
    /*˽�г�Ա����---���ڱȽ϶�����compare()*/
    bool compareTree(binaryTreeNode<E>* thisNode, binaryTreeNode<E>* xNode);
    /*˽�г�Ա����---��������ÿ��������������---�ݹ�*/
    void swapTrees(binaryTreeNode<E>*& node);
    /*˽�г�Ա����---����������߶�---���ظ�Ϊnode�����ĸ߶�*/
    int height(binaryTreeNode<E>* node) const;
    /*˽�г�Ա����---������node�����������߶ȵĲ�ֵ*/
    int heightDifference(binaryTreeNode<E>* node) const;
    /*˽�г�Ա����---��������������߶Ȳ�---����ֵΪ�����������߶Ȳ�*/
    int maxHeightDifference(binaryTreeNode<E>* node) const;
    binaryTreeNode<E>* preInCreateTree(E preOrder[], E inOrder[], int size);
    binaryTreeNode<E>* postInCreateTree(E postOrder[], E inOrder[], int size);


    /*���������ʽ��˽�г�Ա*/
    /*�������ı��ʽ��ֵ*/
    /*���������й���ǰ׺����׺����׺���ʽ�Ĵ���ȫ����char���ͣ�����ֻ�ܽ��и�λ���ļ���*/
    int compulateTree(binaryTreeNode<E>* node) const;
    binaryTreeNode<E>* preExprCreateTree(E expression[], int length);
    binaryTreeNode<E>* inExprCreateTree(E expression[], int length);
    binaryTreeNode<E>* postExprCreateTree(E expression[], int length);
};

/*˽�о�̬��Ա��ʼ��*/
/*�����Ǿ�̬����ָ���Ա�ĳ�ʼ��������ʼ��������LINK����*/
template<class E>
void (*binaryTreeChains<E>::visit)(binaryTreeNode<E>*) = 0;      // visit function

/*����������ͨ��Ա����*/
/*ǰ����� �ݹ�*/
template<class E>
void binaryTreeChains<E>::preOrder(binaryTreeNode<E>* t)
{
    if (t != nullptr)
    {
        visit(t);/*��������*/
        preOrder(t->leftChild);/*ǰ�����������*/
        preOrder(t->rightChild);/*ǰ�����������*/
    }
}
/*ǰ�����---��ʹ�õݹ��ʹ�õ�������*/
template<class E>
vector<E> binaryTreeChains<E>::iterativePreOrder()
{
    binaryTreeNode<E>* currentNode = root;
    stack<binaryTreeNode<E>*> st;
    vector<E> result;

    /*д��1---ǰ�������������ǵݹ�ͳһ��*/
    /*���Ƚ����ڵ���ջ*/
    if (currentNode != nullptr)
        st.push(currentNode);
    while (!st.empty())
    {
        currentNode = st.top();
        st.pop();
        /*�������nullptr,�������ǰջ��Ԫ��*/
        if (currentNode == nullptr)
        {
            result.push_back(st.top()->element);
            st.pop();
        }
            /*���û������nullptr,���������е�˳����ջ��㣬�����ջnullptr*/
        else
        {
            if (currentNode->rightChild != nullptr)
                st.push(currentNode->rightChild);
            if (currentNode->leftChild != nullptr)
                st.push(currentNode->leftChild);
            st.push(currentNode);
            /*ÿ�ζ����ѱ����ĸ��ڵ����ջnullptr*/
            st.push(nullptr);
        }
    }

    ///*д��2*/
    ///*�����Ϊnullptr����ջΪ��ʱ����ѭ��*/
    //while (currentNode != nullptr || !st.empty())
    //{
    //	/*�Ƚ���ߵ���ߵ�Ԫ����ջ*/
    //	while (currentNode != nullptr)
    //	{
    //		st.push(currentNode);
    //		result.push_back(currentNode->element);
    //		currentNode = currentNode->leftChild;
    //	}
    //	/*Ȼ��һ��һ��������ߵ�Ԫ�أ�������Ԫ�ش洢��vector��*/
    //	currentNode = st.top();
    //	st.pop();
    //	currentNode = currentNode->rightChild;
    //}
    return result;
}

/*������� �ݹ�*/
template<class E>
void binaryTreeChains<E>::inOrder(binaryTreeNode<E>* t)
{
    if (t != nullptr)
    {
        inOrder(t->leftChild);/*�������������*/
        visit(t);/*��������*/
        inOrder(t->rightChild);/*�������������*/
    }
}
/*�������---��ʹ�õݹ��ʹ�õ�������*/
template<class E>
vector<E> binaryTreeChains<E>::iterativeInOrder()
{
    binaryTreeNode<E>* currentNode = root;
    stack<binaryTreeNode<E>*> st;
    vector<E> result;
    /*д��1---ǰ�������������ǵݹ�ͳһ��*/
    /*���Ƚ����ڵ���ջ*/
    if (currentNode != nullptr)
        st.push(currentNode);
    while (!st.empty())
    {
        currentNode = st.top();
        st.pop();
        /*�������nullptr,�������ǰջ��Ԫ��*/
        if (currentNode == nullptr)
        {
            result.push_back(st.top()->element);
            st.pop();
        }
            /*���û������nullptr,���������е�˳����ջ��㣬�����ջnullptr*/
        else
        {
            if (currentNode->rightChild != nullptr)
                st.push(currentNode->rightChild);
            st.push(currentNode);
            /*ÿ�ζ����ѱ����ĸ��ڵ����ջnullptr*/
            st.push(nullptr);
            if (currentNode->leftChild != nullptr)
                st.push(currentNode->leftChild);
        }
    }
    /*д��2*/
    ///*�����Ϊnullptr����ջΪ��ʱ����ѭ��*/
    //while (currentNode != nullptr || !st.empty())
    //{
    //	/*�Ƚ���ߵ���ߵ�Ԫ����ջ*/
    //	while (currentNode != nullptr)
    //	{
    //		st.push(currentNode);
    //		currentNode = currentNode->leftChild;
    //	}
    //	/*Ȼ��һ��һ��������ߵ�Ԫ�أ�������Ԫ�ش洢��vector��*/
    //	currentNode = st.top();
    //	st.pop();
    //	result.push_back(currentNode->element);
    //	currentNode = currentNode->rightChild;
    //}
    return result;
}

/*������� �ݹ�*/
template<class E>
void binaryTreeChains<E>::postOrder(binaryTreeNode<E>* t)
{
    if (t != nullptr)
    {
        postOrder(t->leftChild);/*�������������*/
        postOrder(t->rightChild);/*�������������*/
        visit(t);/*��������*/
    }
}
/*�������---��ʹ�õݹ��ʹ�õ�������*/
template<class E>
vector<E> binaryTreeChains<E>::iterativePostOrder()
{
    binaryTreeNode<E>* currentNode = root;
    stack<binaryTreeNode<E>*> st;
    vector<E> result;
    /*ǰ�������������ǵݹ�ͳһ��*/
    /*���Ƚ����ڵ���ջ*/
    if (currentNode != nullptr)
        st.push(currentNode);
    while (!st.empty())
    {
        currentNode = st.top();
        st.pop();
        /*�������nullptr,�������ǰջ��Ԫ��*/
        if (currentNode == nullptr)
        {
            result.push_back(st.top()->element);
            st.pop();
        }
            /*���û������nullptr,���������е�˳����ջ��㣬�����ջnullptr*/
        else
        {
            st.push(currentNode);
            /*ÿ�ζ����ѱ����ĸ��ڵ����ջnullptr*/
            st.push(nullptr);
            if (currentNode->rightChild != nullptr)
                st.push(currentNode->rightChild);
            if (currentNode->leftChild != nullptr)
                st.push(currentNode->leftChild);
        }
    }
    return result;
}

/*��α��������� �ǵݹ�*/
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
/*����������---�ݹ�---ģ���ʵ��*/
template<class E>
void binaryTreeChains<E>::createBiTree(binaryTreeNode<E>*& tree)
{
    E data;
    cout << "Please enter the tree element:";
    while (!(cin >> data))
    {
        cin.clear();//��ձ�־λ
        while (cin.get() != '\n')//ɾ����Ч������
            continue;
        cout << "Please enter the tree element:";
    }
    cin.get();
    /*���char���͵�����*/
    if (typeid(data) == typeid(char)) {
        if (data == '#')
            tree = nullptr;
        else {
            treeSize++;
            tree = new binaryTreeNode<E>(data);
            createBiTree(tree->leftChild);
            createBiTree(tree->rightChild);
        }
        /*���ڶ��������������źŷŴ�����Ӧ�����¶����˳�Ա����maketree()���ɶ�����
            ����ᱨ��C2228��.degradeFromParent������߱�������/�ṹ/����
            ��ʵ���ǲ�֪����ô��
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
    else/*�����������*/{
        if (data == 999)
            tree = nullptr;//������999ʱ�������ĸ��ڵ�Ϊnullptr,�Ӷ������÷�֧�ĵݹ�
        else
        {
            treeSize++;
            tree = new binaryTreeNode<E>(data);
            createBiTree(tree->leftChild);
            createBiTree(tree->rightChild);
        }
    }
}
/*��һ���ֶ������������ĺ�����ʹ�ñ��������ֶ����ø��ڵ�֮��Ĺ�ϵ�����źŷŴ���Ӧ�õ�ʹ��*/
/*�������������ϲ�Ϊһ����*/
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

/*��ϰ24�����ݶ���������������---���ڸ��ƹ��캯��*/
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

/*��ϰ45��˽�г�Ա����---���ڱȽ϶�����compare()*/
template<class E>
bool binaryTreeChains<E>::compareTree(binaryTreeNode<E>* thisNode, binaryTreeNode<E>* xNode)
{
    /*������㶼Ϊ��ʱ�����������*/
    if (thisNode == nullptr && xNode == nullptr)
        return true;
    /*һ�����Ϊ�գ�һ�����ǿգ�������������*/
    if ((thisNode == nullptr && xNode != nullptr) || (thisNode != nullptr && xNode == nullptr))
        return false;
    /*��������Ԫ�ز��ȣ�������������*/
    if (thisNode->element != xNode->element)
        return false;
    else/*���������ȣ���Ƚϱ˴˵���������������*/
        return compareTree(thisNode->leftChild, xNode->leftChild) && compareTree(thisNode->rightChild, xNode->rightChild);
}

/*��ϰ46��˽�г�Ա����---��������ÿ��������������---�ݹ�*/
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

/*��ϰ27��˽�г�Ա����---����������߶�---���ظ�Ϊnode�����ĸ߶�*/
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

/*˽�г�Ա����---������node�����������߶ȵĲ�ֵ*/
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

/*��ϰ47��˽�г�Ա����---��������������߶Ȳ�---����ֵΪ�����������߶Ȳ�*/
template<class E>
int binaryTreeChains<E>::maxHeightDifference(binaryTreeNode<E>* node) const
{
    if (node == nullptr)
        return 0;
    int height = heightDifference(node);//��ǰ�������������ĸ߶Ȳ�
    int hl = maxHeightDifference(node->leftChild);//��ǰ���������������������ĸ߶Ȳ�
    int hr = maxHeightDifference(node->rightChild);//��ǰ���������������������ĸ߶Ȳ�

    if (height >= hl && height >= hr)
        return height;
    else if (hl >= height && hl >= hr)
        return hl;
    else if (hr >= height && hr >= hl)
        return hr;
}

/*��ϰ29���������������һ��������Ľ��---����ֵΪ������Ĳ�*/
/*��������Ϊ��ʱ������0*/
template<class E>
int binaryTreeChains<E>::layerMaxNumOfNode()
{
    if (root == nullptr)
        return 0;
    int num = 0;//�ۼ�ÿ��Ľ����
    int layer = 0;//��¼��ǰ�Ĳ���
    int maxNum = 0;//�洢������Ĳ�Ľ�����
    int maxLayer = 0;//�洢������Ĳ�Ĳ���
    binaryTreeNode<E>* lastNode = root;//�洢��һ�����һ������Ԫ��λ��
    binaryTreeNode<E>* nextNode = nullptr;//�洢��ǰ�����һ������Ԫ��λ��
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
            layer++;//�ոմ�����ڼ���
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

/*���������������һ��������Ľ��--����ֵΪ������Ĳ�Ľ������*/
/*��������Ϊ��ʱ������0*/
template<class E>
int binaryTreeChains<E>::maxNumOfNodeInLayer()
{
    if (root == nullptr)
        return 0;
    int num = 0;//�ۼ�ÿ��Ľ����
    int layer = 0;//��¼��ǰ�Ĳ���
    int maxNum = 0;//�洢������Ĳ�Ľ�����
    int maxLayer = 0;//�洢������Ĳ�Ĳ���
    binaryTreeNode<E>* lastNode = root;//�洢��һ�����һ������Ԫ��λ��
    binaryTreeNode<E>* nextNode = nullptr;//�洢��ǰ�����һ������Ԫ��λ��
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
            layer++;//�ոմ�����ڼ���
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

/*ʹ��ǰ��������������������*/
/*�ؼ��������ҵ����ڵ��������е�λ�ã���λ��֮ǰΪ�ø�������������λ��֮��Ϊ�ø���������*/
template<class E>
binaryTreeNode<E>* binaryTreeChains<E>::preInCreateTree(E preOrder[], E inOrder[], int size)
{
    /*���û�������������򷵻�nullptr*/
    if (size == 0)
        return nullptr;
    binaryTreeNode<E>*  rootData = new binaryTreeNode<E>(preOrder[0]);
    /*�ҵ����ڵ��λ�ã������и�λ�������Ǹø��ڵ������������λ���Ҳ���Ǹø��ڵ��������*/
    int rootLoc = findRootLoc<E>(inOrder, preOrder[0] ,size);
    /*������������������*/
    rootData->leftChild = preInCreateTree(preOrder + 1, inOrder, rootLoc);
    rootData->rightChild = preInCreateTree(preOrder + 1 + rootLoc, inOrder + rootLoc + 1, size - 1 - rootLoc);
    return rootData;
}
/*ʹ�ú���������������������*/
/*�ؼ��������ҵ����ڵ��������е�λ�ã���λ��֮ǰΪ�ø�������������λ��֮��Ϊ�ø���������*/
template<class E>
binaryTreeNode<E>* binaryTreeChains<E>::postInCreateTree(E postOrder[], E inOrder[], int size)
{
    /*���û�������������򷵻�nullptr*/
    if (size == 0)
        return nullptr;
    binaryTreeNode<E>* rootData = new binaryTreeNode<E>(postOrder[size-1]);
    /*�ҵ����ڵ��λ�ã������и�λ�������Ǹø��ڵ������������λ���Ҳ���Ǹø��ڵ��������*/
    int rootLoc = findRootLoc<E>(inOrder, postOrder[size-1], size);
    /*������������������*/
    rootData->leftChild = postInCreateTree(postOrder, inOrder, rootLoc);
    rootData->rightChild = postInCreateTree(postOrder + rootLoc, inOrder + rootLoc + 1, size - 1 - rootLoc);
    return rootData;
}


/*���������ʽ�ĳ�Ա����*/
/*�������ı��ʽ��ֵ*/
/*���ַ�����¼���ʽ*/
/*���������Ҫʹ��char���͵������������͵Ķ�����������Ҫ��*/
template<class E>
int binaryTreeChains<E>::compulateTree(binaryTreeNode<E>* node) const
{
    if (node == nullptr)
        return 0;
    if (node->leftChild == nullptr && node->rightChild == nullptr) //������������nullptrʱ��˵������Ҷ�ӽڵ㣬��Ҷ�ӽ����������Ƿ���
        return node->element - '0';//�ͷ���Ҷ�ӽ��
    int a = compulateTree(node->leftChild);//�ȼ���������
    int b = compulateTree(node->rightChild);//�ټ���������
    switch (node->element)//��ǰ��㲻��Ҷ�ӽڵ�ʱ��˵�����Ƿ��Ž��
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
                throw illegalParameterValue("��������Ϊ0��");
    }
}

/*ʹ��ȫ���Ƕ�Ԫ��������ǰ׺���ʽ����������*/
/*��βԪ�ؿ�ʼ�������ʽ��Ԫ��*/
/*��������ݣ�������binaryTreeNode����ջ*/
/*����������ݣ�������binaryTreeNode����ջ�е������������γ�������,��һ���������������������ڶ���������������������Ȼ���ٽ���ǰ�����ջ*/
template<class E>
binaryTreeNode<E>* binaryTreeChains<E>::preExprCreateTree(E expression[],int length)
{
    stack<binaryTreeNode<E>*> st;//���ڴ洢�Ѿ�������������ɵ�binaryTreeNode
    binaryTreeNode<E>* temp = nullptr;
    for (int i = length-1; i >= 0; i--)
    {
        /*��������ݣ������ɶ����������ջ*/
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

/*ʹ��ȫ���Ƕ�Ԫ����������׺���ʽ(���������Ա������ȼ�)����������*/
/*��������ݣ�������binaryTreeNode��������ջ*/
/*
�������������
	�����ǰ���������ȼ����ڲ�����ջ�Ķ���Ԫ�أ�ֱ���������ջ
	�����ǰ���������ȼ�С�ڻ���ڲ�����ջ�Ķ���Ԫ�أ��Ƚ�����Ԫ�س�������ջ�ٽ���ǰ�������������ջ
	��ǰ������Ϊ������ʱֱ����ջ
	��ǰ������Ϊ������ʱ����ջ����������Ϊֹ�Ĳ�������������ջ�����Ų������ں�׺���ʽ��
��������ջʱ�����ɵ�ǰ���ŵ�binaryTreeNode����������Ϊ����ջ��ջ��Ԫ�أ�����ջ��Ԫ�س�ջ����������Ϊ����ջ��ǰ��ջ��Ԫ�أ�����ջ��Ԫ�س�ջ��
			  ��ǰ����binaryTreeNode������ջ��
*/
/*��ȡ���������ȼ���getPriority()������һ���ǳ�Ա����*/
template<class E>
binaryTreeNode<E>* binaryTreeChains<E>::inExprCreateTree(E expression[], int length)
{
    stack<binaryTreeNode<E>*> st;//���ڴ洢�Ѿ�������������ɵ�binaryTreeNode
    stack<E> opStack;
    binaryTreeNode<E>* temp = nullptr;
    E data;
    for (int i = 0; i < length; i++)
    {
        data = expression[i];
        /*��������ݣ������ɶ����������ջ*/
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
                    case '(':opStack.push(data); break;//������������ʱ��ֱ�ӽ�����ջ
                    case ')'://������������ʱ����ջ���������ŵĲ�������ջ
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
                        opStack.pop();//��(��ջ
                        break;
                        /*������+ - * /ʱ,�������ȼ�����ջ��Ԫ��ʱ����ջ�������Ƚ�ջ��Ԫ�س�ջ���ٽ���ǰԪ����ջ*/
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
            /*����鵽��׺���ʽ�����һ��Ԫ����ջ�ǿ�ʱ����ջ�е�Ԫ��ȫ���������׺���ʽ*/
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

/*ʹ��ȫ���Ƕ�Ԫ�������ĺ�׺���ʽ����������*/
/*����Ԫ�ؿ�ʼ�������ʽ��Ԫ��*/
/*��������ݣ�������binaryTreeNode����ջ*/
/*����������ݣ�������binaryTreeNode����ջ�е������������γ�������,��һ���������������������ڶ���������������������Ȼ���ٽ���ǰ�����ջ*/
template<class E>
binaryTreeNode<E>* binaryTreeChains<E>::postExprCreateTree(E expression[], int length)
{
    stack<binaryTreeNode<E>*> st;//���ڴ洢�Ѿ�������������ɵ�binaryTreeNode
    binaryTreeNode<E>* temp = nullptr;
    for (int i = 0; i < length; i++)
    {
        /*��������ݣ������ɶ����������ջ*/
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