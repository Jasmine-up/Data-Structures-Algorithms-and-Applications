/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			链表线性表头文件---单链表
*/
#pragma once
#ifndef _CHAIN_H_
#define _CHAIN_H_
#include<iostream>
#include<sstream>
#include<cmath>
#include "_1myExceptions.h"
#include "_2myFunctions.h"
#include "_4linearList.h"
#include "_5arrayList.h"
#include "_6chainNode.h"

using std::ostream;
using std::ostringstream;
using std::find;
using std::cout;
using std::forward_iterator_tag;
using std::ptrdiff_t;
using std::endl;

void chainTest();//测试函数，函数定义在chain.cpp中。

template<class T>
class chain : public linearList<T>
{
public:

    /*构造函数*/
    chain(int initialCapacity = 10);
    /*复制构造函数*/
    chain(const chain<T>&);
    /*数组构造链表*/
    chain(const arrayList<T>& arrayTo);//直接使用构造函数--使用数组初始化链表
    /*析构函数*/
    ~chain();

    //抽象数据类型ADT方法
    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;
    void clear();
    void push_back(const T& theElement);
    /*习题2*/
    void setSize(int theSize);
    /*习题3*/
    void set(int theIndex, const T& theElement);
    /*习题4*/
    void removeRange(int fromIndex, int toIndex);
    /*习题5*/
    int lastIndexOf(const T& theElement);
    /*习题10*/
    void swap(chain<T>& theChain);
    /*习题13*/
    void toArray(arrayList<T>& theArray);
    /*习题14*/
    void leftShift(int i);
    /*习题15*/
    void reverse();
    /*习题18*/
    void meld(chain<T>& a, chain<T>& b);
    /*习题20*/
    void merge(chain<T>& a, chain<T>& b);
    /*习题22*/
    void split(chain<T>& a, chain<T>& b);
    /*习题23*/
    void circularShift(int i);

    /*迭代器*/
    class iterator
    {
    public:
        //向前迭代器所需要的typedef
        typedef forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        /*构造函数*/
        iterator(chainNode<T>* theNode = nullptr) { node = theNode; }
        /*解引用操作*/
        T& operator*() const { return node->element; }
        T* operator->() const { return &node->element; }
        /*迭代器加法操作*/
        iterator& operator++() //前加
        {
            node = node->next; return *this;
        }
        iterator& operator++(int) //后加
        {
            iterator old = *this;
            node = node->next;
            return old;
        }
        /*相等检验*/
        bool operator!=(const iterator right) const { return node != right.node; }
        bool operator==(const iterator right) const { return node == right.node; }
    protected:
        chainNode<T>* node;
    };
    iterator begin() const { return iterator(firstNode); }
    iterator end() const { return iterator(nullptr); }

    /*重载操作符*/
    /*习题6*/
    T& operator[](int i);
    const T& operator[](int i) const;
    /*习题7*/
    bool operator==(chain<T>& right) const;
    /*习题8*/
    bool operator!=(chain<T>& right) const;
    /*习题9*/
    bool operator<(chain<T>& right) const;

    /*排序*/
    void bubbleSort();
    void rankSort();
    T maxOfList();
    void selectionSort();
    void insertSort();
    /*箱子排序*/
    void binSort(int range);
    /*基数排序*/
    void baseBinSort(int range);

    //这个函数用于一次性输入很多元素到线性表
    istream& input(istream& in);
protected:
    void checkIndex(int theIndex) const;
    //如果索引无效，抛出异常
    chainNode<T>* firstNode;//指向链表第一个节点的指针
    int listSize;//线性表的元素个数
};

/*input函数*/
template<class T>
istream& chain<T>::input(istream& in)
{
    int numberOfElement = 0;
    cout << "Please enter the number of elements:" << endl;
    while (!(in >> numberOfElement)) {//如果输入类型不匹配，则执行循环体
        in.clear(); // reset input设置标志位为有效
        while (in.get() != '\n') //删除没有用的输入
            continue; // get rid of bad input
        cout << "Please enter the number of elements:" << endl;
    }
    T inElement = 0;
    for (int i = 0; i < numberOfElement; i++)
    {
        cout << "Please enter the element: " << (i + 1) << endl;
        while (!(in >> inElement)) {//如果输入类型不匹配，则执行循环体
            in.clear(); // reset input设置标志位为有效
            while (in.get() != '\n') //删除没有用的输入
                continue;
            cout << "Please enter the element: " << (i + 1) << endl;
        }
        push_back(inElement);
    }
    return in;
}

/*构造函数：实质上initialCapacity没有意义的，但是为了与类arrayList相容*/
template<class T>
chain<T>::chain(int initialCapacity)
{
    //构造函数
    if (initialCapacity < 1)
    {
        ostringstream s("");
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = nullptr;
    listSize = 0;
}

/*复制构造函数*/
template<class T>
chain<T>::chain(const chain<T>& theList)
{
    listSize = theList.listSize;
    if (listSize == 0)
    {
        firstNode = nullptr;
        return;
    }
    //指向要复制的元素位置
    chainNode<T>* sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element);//复制链表theList的首元素
    sourceNode = sourceNode->next;
    //指向要复制的元素位置之前的位置
    chainNode<T>* targetNode = firstNode;
    while (sourceNode != nullptr)
    {
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
}

/*使用arrayList初始化链表的构造函数*/
template<class T>
chain<T>::chain(const arrayList<T>& arrayTo)
{
    listSize = arrayTo.size();
    if (listSize == 0)
    {
        firstNode = nullptr;
    }
    else
    {
        int data = arrayTo.get(0);
        firstNode = new chainNode<T>(data);
        chainNode<T>* currentNode = firstNode;
        for (int i = 1; i < listSize; i++)
        {
            data = arrayTo.get(i);
            currentNode->next = new chainNode<T>(data);
            currentNode = currentNode->next;
        }
    }
}

/*析构函数*/
template<class T>
chain<T>::~chain()
{
    while (firstNode != nullptr)
    {
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

/*检查索引是否有效*/
template<class T>
void chain<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s("");
        s << "index = " << theIndex << "size = " << listSize;
        throw illegalIndex(s.str());
    }
}

/*获取索引为theIndex的元素*/
template<class T>
T& chain<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
        currentNode = currentNode->next;
    return currentNode->element;
}

/*返回元素theElement首次出现时的索引，若该元素不存在，则返回-1。*/
template<class T>
int chain<T>::indexOf(const T& theElement) const
{
    //搜索链表寻找元素theElement
    chainNode<T>* currentNode = firstNode;
    int index = 0;
    while (currentNode != NULL && currentNode->element != theElement)
    {
        index++;
        currentNode = currentNode->next;
    }
    if (index == listSize)
        return -1;
    else
        return index;
}

/*删除索引为theIndex的元素；若该元素不存在，则抛出异常*/
template<class T>
void chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    chainNode<T>* deleteNode = nullptr;
    if (theIndex == 0)
    {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
        chainNode<T>* currentNode = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
        {
            currentNode = currentNode->next;
        }
        deleteNode = currentNode->next;
        currentNode->next = currentNode->next->next;
    }
    delete deleteNode;
    listSize--;
}

/*插入元素theElement并使其索引为theIndex*/
template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{
    //无效索引
    if (theIndex < 0 || theIndex > listSize)
    {
        ostringstream s("");
        s << "index = " << theIndex << "size = " << listSize;
        throw illegalIndex(s.str());
    }
    //在链表头插入
    if (theIndex == 0)
        firstNode = new chainNode<T>(theElement, firstNode);
    else
    {
        //寻找新元素的前驱
        chainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;
        //在p之后插入
        p->next = new chainNode<T>(theElement, p->next);
    }
    listSize++;
}

/*方法output*/
template<class T>
void chain<T>::output(ostream& out) const
{
    for (chainNode<T>* currentNode = firstNode;
         currentNode != nullptr;
         currentNode = currentNode->next)
        out << currentNode->element << " ";
}

/*重载<<操作符*/
template<class T>
ostream& operator<<(ostream& out, const chain<T>& x)
{
    x.output(out);
    return out;
}
/*重载>>操作符*/
template<typename T>
std::istream& operator>>(std::istream &os, chain<T>& m)
{
    m.input(os);
    return os;
}

/*清空链表*/
template<class T>
void chain<T>::clear()
{
    chainNode<T>* nextNode = nullptr;
    while (firstNode != nullptr)
    {
        nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
    listSize = 0;
}

/*在链表末尾插入元素theElement的节点*/
template<class T>
void chain<T>::push_back(const T& theElement)
{
    chainNode<T>* newNode = new chainNode<T>(theElement, nullptr);
    if (firstNode == nullptr)
        firstNode = newNode;
    else
    {
        chainNode<T>* currentNode = firstNode;
        while (currentNode->next != nullptr)
            currentNode = currentNode->next;
        currentNode->next = newNode;
    }
    listSize++;
}

/*
* 习题2
* 使得线性表的大小等于theSize;若初始线性表的大小小于theSize,则不增加元素；
* 若初始线性表的大小大于theSize，则删除多余的元素。
*/
template<class T>
void chain<T>::setSize(int theSize)
{
    if (listSize > theSize)
    {
        chainNode<T>* currentNode = firstNode;
        for (int i = 0; i < theSize-1; i++)
            currentNode = currentNode->next;//使得currentNode指向第theSize个元素

        chainNode<T>* deleteNode = currentNode->next;
        currentNode->next = nullptr;//将第theSize个元素指向nullptr
        //删除所有多余的元素，重复利用了currentNode，可行
        while (deleteNode != nullptr)
        {
            currentNode = deleteNode->next;
            delete deleteNode;
            deleteNode = currentNode;
        }
        listSize = theSize;
    }
}

/*
* 习题3
* 用元素theElement替换索引为theIndex的元素；若索引theIndex超出范围，则抛出异常
*/
template<class T>
void chain<T>::set(int theIndex, const T& theElement)
{
    checkIndex(theIndex);
    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex - 1; i++)
        currentNode = currentNode->next;
    currentNode->element = theElement;
}

/*
* 习题4
* 删除指定索引范围内的所有元素:(fromIndex,toIndex)---前开后开
* 如果给定范围超出链表范围，则抛出异常。
*/
template<class T>
void chain<T>::removeRange(int fromIndex, int toIndex)
{
    checkIndex(fromIndex+1);
    checkIndex(toIndex-1);
    chainNode<T>* fromNode = firstNode;
    int i = 0;
    for (i = 0; i < fromIndex; i++)
        fromNode = fromNode->next;//存住fromIndex的指针
    chainNode<T>* toNode = fromNode->next;//不删除fromIndex的结点
    i++;
    chainNode<T>* deleteNode = nullptr;
    //存住toIndex的指针并delete其间的结点
    while (i < toIndex)
    {
        deleteNode = toNode;
        toNode = toNode->next;
        delete deleteNode;//要注意后删，不然toNode会指向nullptr
        i++;
    }
    fromNode->next = toNode;
    listSize = listSize - (toIndex - fromIndex - 1);
}

/*
* 习题5
* 返回值是指定元素最后出现时的索引；若这样的元素不存在，则返回-1。
*/
template<class T>
int chain<T>::lastIndexOf(const T& theElement)
{
    int index = -1;
    int loc = 0;
    chainNode<T>* currentNode = firstNode;
    while (currentNode != nullptr)
    {
        //找到就更新index，没找到就不更新
        if (currentNode->element == theElement)
            index = loc;
        currentNode = currentNode->next;
        loc++;
    }
    return index;
}

/*
* 习题10：
* 交换链表*this和theChain的所有元素
*/
template<class T>
void chain<T>::swap(chain<T>& theChain)
{
    chainNode<T>* temp = firstNode;
    firstNode = theChain.firstNode;
    theChain.firstNode = temp;

    int tempnum = listSize;
    listSize = theChain.listSize;
    theChain.listSize = tempnum;
}

/*
* 习题13：
* 将链表*this转换为数组theArray
* 将数组转换为链表我使用了构造函数实现
*/
template<class T>
void chain<T>::toArray(arrayList<T>& theArray)
{
    theArray.clear();//首先要清空数组
    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i < listSize; i++)
    {
        theArray.push_back(currentNode->element);
        currentNode = currentNode->next;
    }
}

/*习题14：将表中的元素向左移动i个位置*/
template<class T>
void chain<T>::leftShift(int i)
{
    if (listSize > i)
    {
        chainNode<T>* deleteNode = nullptr;
        for (int j = 0; j < i && j < listSize; j++)
        {
            deleteNode = firstNode;
            firstNode = firstNode->next;
            delete deleteNode;
        }
        listSize -= i;
    }
    else
        throw illegalIndex();
}

/*习题15：颠倒*this中的元素的顺序*/
template<class T>
void chain<T>::reverse()
{
    /*让第二个节点指向第一个节点*/
    chainNode<T>* beforeNode = nullptr;
    chainNode<T>* currentNode = firstNode;
    chainNode<T>* temp;
    /*让第二个节点以后，最后一个节点以前的所有节点指向它前面的节点*/
    while (currentNode != nullptr)
    {
        temp = currentNode->next;
        currentNode->next = beforeNode;
        beforeNode = currentNode;
        currentNode = temp;
    }
    /*firstNode指向最后一个节点*/
    firstNode = beforeNode;
}

/*
* 习题18：
meld()：*this为新的扩展的链表,它从a的首元素开始，交替地包含a和b的元素。
如果一个链表的元素取完了，就把另一个链表的剩余元素附加到新的扩展链表c中。
合并后的链表使用的应该是链表a和b的节点空间，合并之后，输入链表a和b是空表
*/
template<class T>
void chain<T>::meld(chain<T>& a, chain<T>& b)
{
    //先清空本链表
    (*this).clear();
    chainNode<T>* currentNode = nullptr;
    /*当前a,b链表都不为nullptr时*/
    while (a.firstNode != nullptr && b.firstNode != nullptr)
    {
        if (listSize == 0)
        {
            //如果a,b链表都不为空，则在c中先插入a,b的一个元素
            firstNode = a.firstNode;
            a.firstNode = (a.firstNode)->next;
            (a.listSize)--;
            firstNode->next = b.firstNode;
            b.firstNode = (b.firstNode)->next;
            (b.listSize)--;
            listSize += 2;
            currentNode = firstNode->next;//当前结点指向第二个元素
        }
        else
        {
            currentNode->next = a.firstNode;
            a.firstNode = (a.firstNode)->next;
            (a.listSize)--;
            listSize++;
            currentNode = currentNode->next;
            currentNode->next = b.firstNode;
            b.firstNode = (b.firstNode)->next;
            (b.listSize)--;
            listSize++;
            currentNode = currentNode->next;
        }
    }
    /*当前b链表为nullptr时*/
    if (a.firstNode != nullptr)
    {
        if (listSize == 0)
        {
            //如果当前a链表不为空，则在c中插入a的所有元素
            firstNode = a.firstNode;
            a.firstNode = nullptr;
            listSize += a.listSize;
            a.listSize = 0;
        }
        else
        {
            currentNode->next = a.firstNode;
            listSize += a.listSize;
            a.firstNode = nullptr;
            a.listSize = 0;
        }
    }
    /*当前a链表为nullptr时*/
    if (b.firstNode != nullptr)
    {
        if (listSize == 0)
        {
            //如果当前a链表不为空，则在c中插入a的所有元素
            firstNode = b.firstNode;
            b.firstNode = nullptr;
            listSize += b.listSize;
            b.listSize = 0;
        }
        else
        {
            currentNode->next = b.firstNode;
            b.firstNode = nullptr;
            listSize+=b.listSize;
            b.listSize = 0;
        }
    }
}

/*
* 习题20
* merge():有序链表a和b,合并生成有序链表(*this),此后a,b链表都为空表
*/
template<class T>
void chain<T>::merge(chain<T>& a, chain<T>& b)
{
    //先清空本链表
    (*this).clear();
    chainNode<T>* currentNode = nullptr;
    /*当前a,b链表都不为nullptr时*/
    while (a.firstNode != nullptr && b.firstNode != nullptr)
    {
        //首先解决第一个元素
        if (listSize == 0)
        {
            //如果a,b链表都不为空，则在c中首先插入a,b中小的一个元素
            if ((a.firstNode)->element <= (b.firstNode)->element)
            {
                firstNode = a.firstNode;
                a.firstNode = (a.firstNode)->next;
                listSize++;
                a.listSize--;
                currentNode = firstNode;//当前结点指向第一个元素
            }
            else
            {   //如果a,b链表都不为空，则在c中首先插入a,b中小的一个元素
                firstNode = b.firstNode;
                b.firstNode = (b.firstNode)->next;
                listSize++;
                b.listSize--;
                currentNode = firstNode;//当前结点指向第一个元素
            }
        }
            //然后解决后面的元素
        else
        {
            if ((a.firstNode)->element <= (b.firstNode)->element)
            {
                currentNode->next = a.firstNode;
                a.firstNode = (a.firstNode)->next;
                listSize++;
                a.listSize--;
                currentNode = currentNode->next;
            }
            else
            {
                currentNode->next = b.firstNode;
                b.firstNode = (b.firstNode)->next;
                listSize++;
                b.listSize--;
                currentNode = currentNode->next;
            }
        }
    }
    /*当前b链表为nullptr时*/
    if (a.firstNode != nullptr)
    {
        if (listSize == 0)
        {
            //如果当前a链表不为空，则在c中插入a的所有元素
            firstNode = a.firstNode;
            a.firstNode = nullptr;
            listSize += a.listSize;
            a.listSize = 0;
        }
        else
        {
            currentNode->next = a.firstNode;
            listSize += a.listSize;
            a.firstNode = nullptr;
            a.listSize = 0;
        }
    }
    /*当前a链表为nullptr时*/
    while (b.firstNode != nullptr)
    {
        if (listSize == 0)
        {
            //如果当前a链表为空，则在c中插入b的所有元素
            firstNode = b.firstNode;
            b.firstNode = nullptr;
            listSize += b.listSize;
            b.listSize = 0;
        }
        else
        {
            currentNode->next = b.firstNode;
            b.firstNode = nullptr;
            listSize += b.listSize;
            b.listSize = 0;
        }
    }
}

/*
* 练习22
* split():生成两个扩展链表a和b,a包含*this中索引为奇数的元素，b包含*this中其他的元素,此后*this链表为空表
*/
template<class T>
void chain<T>::split(chain<T>& a, chain<T>& b)
{
    chainNode<T>* currentNodeA = nullptr;
    chainNode<T>* currentNodeB = nullptr;
    for (int i = 0; i < listSize; i++)
    {
        if (i % 2 == 0)
        {
            if (b.listSize == 0)
            {
                b.firstNode = firstNode;
                firstNode = firstNode->next;
                (b.listSize)++;
                currentNodeB = b.firstNode;
            }
            else
            {
                currentNodeB->next = firstNode;
                firstNode = firstNode->next;
                (b.listSize)++;
                currentNodeB = currentNodeB->next;
            }
        }
        else
        {
            if (a.listSize == 0)
            {
                a.firstNode = firstNode;
                firstNode = firstNode->next;
                (a.listSize)++;
                currentNodeA = a.firstNode;
            }
            else
            {
                currentNodeA->next = firstNode;
                firstNode = firstNode->next;
                (a.listSize)++;
                currentNodeA = currentNodeA->next;
            }
        }
    }
    listSize = 0;
    currentNodeA->next = nullptr;
    currentNodeB->next = nullptr;
}

/*
* 习题23：
* 循环移动 [0,1,2,3,4]循环移动两位是[2,3,4,0,1]
*/
template<class T>
void chain<T>::circularShift(int i)
{
    //存住原始第一个节点
    chainNode<T>* originalNode = firstNode;
    chainNode<T>* lastNode = nullptr;
    //找到循环移动结束后的第一个节点
    for (int j = 0; j < i; j++)
    {
        firstNode = firstNode->next;
        //找到循环移动结束后的最后一个节点
        if (j == i - 2)
            lastNode = firstNode;
    }
    chainNode<T>* currentNode = firstNode;
    //找到原始链表的最后一个节点
    while (currentNode->next != nullptr)
        currentNode = currentNode->next;
    //原始链表的最后一个结点指向原始链表的第一个结点
    currentNode->next = originalNode;
    //循环结束后的最后一个结点指向nullptr
    lastNode->next = nullptr;
}

/*重载操作符*/

/*
* 习题6
* 重载[]操作符
*/
template<class T>
T& chain<T>::operator[](int i)
{
    checkIndex(i);
    chainNode<T>* currentNode = firstNode;
    for (int j = 0; j < i; j++)
        currentNode = currentNode->next;//先获取到地址
    return currentNode->element;//然后返回元素
}
template<class T>
const T& chain<T>::operator[](int i) const
{
    checkIndex(i);
    chainNode<T>* currentNode = firstNode;
    for (int j = 0; j < i; j++)
        currentNode = currentNode->next;//先获取到地址
    return currentNode->element;//然后返回元素
}

/*习题7：重载==操作符*/
template<class T>
bool chain<T>::operator==(chain<T>& right) const
{
    if (listSize == right.listSize)
    {
        int i = listSize;
        chainNode<T>* leftNode = firstNode;
        chainNode<T>* rightNode = right.firstNode;
        while (i--)
        {
            //只要有不相等就返回false
            if (leftNode->element != rightNode->element)
                return false;
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }
        //只有全部相等时才返回true
        return true;
    }
    else  //长度不相等直接返回false
        return false;
}

/*习题8：重载!=操作符*/
template<class T>
bool chain<T>::operator!=(chain<T>& right) const
{
    if (listSize == right.listSize)
    {
        int i = listSize;
        chainNode<T>* leftNode = firstNode;
        chainNode<T>* rightNode = right.firstNode;
        while (i--)
        {
            //只要有不相等就返回true
            if (leftNode->element != rightNode->element)
                return true;
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }
        //只有全部相等时才返回false
        return false;
    }
    else  //长度不相等直接返回true
        return true;
}

/*习题9；重载<操作符,要求左边链表所有的元素都小于右边链表的元素*/
template<class T>
bool chain<T>::operator<(chain<T>& right) const
{
    //左边链表长度大于右边链表时，直接返回false
    if (listSize > right.listSize)
        return false;
    else
    {
        chainNode<T>* leftNode = firstNode;
        chainNode<T>* rightNode = right.firstNode;
        for (int i = 0; i < listSize; i++)
        {
            //存在左边链表的元素大于右边链表的元素时，直接返回false
            if (leftNode->element >= rightNode->element)
                return false;
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }
        return true;
    }
}

/*排序*/
/*冒泡排序*/
template<class T>
void chain<T>::bubbleSort()
{
    for (int i = listSize; i > 1; i--)
    {
        int j = 1;
        chainNode<T>* currentNode = firstNode;
        while (j < i)
        {
            if (currentNode->element > currentNode->next->element)
                Swap<T>(currentNode->element, currentNode->next->element);
            currentNode = currentNode->next;
            j++;
        }
    }
}

/*按名次排序*/
template<class T>
void chain<T>::rankSort()
{
    int* r = new int[listSize];
    //初始化名次
    for (int i = 0; i < listSize; i++)
        r[i] = 0;
    //计算名次
    for (int i = listSize - 1; i >= 0; i--) //从右往左拿出每个元素与其他元素比较
    {
        for (int j = 0; j < i; j++)
        {
            if ((*this)[i]>(*this)[j])
                r[i]++;
            else
                r[j]++;
        }
    }
    //按名次排序
    for (int i = 0; i < listSize; i++)
    {
        if (i != r[i])
        {
            Swap<T>((*this)[i], (*this)[r[i]]);
            Swap<T>(r[i], r[r[i]]);
        }
    }
    delete[] r;
}

/*返回链表的最大元素*/
template<class T>
T chain<T>::maxOfList()
{
    chain<T>::iterator it = (*this).begin();
    T tempMax = *it;//存储最大元素
    for (int i = 1; i < listSize; i++)
    {
        it++;
        if ((*it) > tempMax)
        {
            tempMax = *it;
        }
    }
    return tempMax;
}

/*选择排序*/
template<class T>
void chain<T>::selectionSort()
{
    int indexMax = 0;
    bool is_sorted = false;
    for (int i = listSize; i > 1 && !is_sorted; i--)
    {
        is_sorted = true;
        indexMax = 0;
        chain<T>::iterator it = (*this).begin();
        T tempMax = *it;//存储最大元素
        for (int j = 1; j < i; j++)
        {
            it++;
            if ((*it) > tempMax)
            {
                tempMax = *it;
                indexMax = j;
            }
            else
                is_sorted = false;
        }
        Swap<T>((*this)[i - 1], (*this)[indexMax]);
    }
}

/*插入排序*/
template<class T>
void  chain<T>::insertSort()
{
    for (int i = 1; i < listSize; i++)
    {
        chainNode<T>* currentNode = firstNode;
        int tempData = (*this)[i];
        int j = 0;
        for (j = 0; j < i ; j++)
        {
            if (tempData < currentNode->element)
                break;
            else
                currentNode = currentNode->next;
        }
        if (j != i)
        {
            (*this).insert(j, tempData);
            (*this).erase(i + 1);
        }
    }
}

/*箱子排序,range指定了链表元素的最大范围,适合数据集中的情况*/
template<class T>
void chain<T>::binSort(int range)
{
    //对链表中的结点排序
    //创建初始化箱子
    chainNode<T>** bottom, ** top;//bottom指向箱子的底部，top指向箱子的顶部
    bottom = new chainNode<T>*[range + 1];
    top = new chainNode<T>*[range + 1];
    for (int b = 0; b <= range; b++)
        bottom[b] = nullptr;

    //把链表的结点分配到箱子
    for (; firstNode != nullptr; firstNode = firstNode->next)
    {//把首结点firstNode加入到箱子中
        int data = firstNode->element;//元素类型转换为整型
        if (bottom[data] == nullptr) //箱子为空
            bottom[data] = top[data] = firstNode;
        else  //箱子不空
        {
            top[data]->next = firstNode;
            top[data] = firstNode;
        }
    }

    //把箱子中的结点收集到有序链表
    chainNode<T>* y = nullptr;
    for (int bin = 0; bin <= range; bin++)
    {
        if (bottom[bin] != nullptr)
        {
            if (y == nullptr)  //第一个非空箱子
                firstNode = bottom[bin];
            else
                y->next = bottom[bin];
            y = top[bin];
        }
    }
    if (y->next != nullptr)
        y->next = nullptr;
    delete[] bottom;
    delete[] top;
}

/*基数排序*/
template<class T>
void chain<T>::baseBinSort(int range)
{
    //对链表中的结点排序
    chainNode<T>** bottom, ** top;//bottom指向箱子的底部，top指向箱子的顶部
    bottom = new chainNode<T>*[range + 1];
    top = new chainNode<T>*[range + 1];
    //获取链表中数据的最大值
    int maxData = maxOfList();
    int binNum = 1;//计算要进行箱子排序的次数
    while (maxData / (range + 1))
    {
        maxData /= (range + 1);
        binNum++;
    }
    for(int i = 0;i< binNum;i++)
    {
        //每一次都要初始化箱子
        for (int b = 0; b <= range; b++)
            bottom[b] = nullptr;

        //把链表的结点分配到箱子
        for (; firstNode != nullptr; firstNode = firstNode->next)
        {//把首结点firstNode加入到箱子中
            int data = int((firstNode->element)/pow(10,i)) % 10;//元素类型转换为整型
            if (bottom[data] == nullptr) //箱子为空
                bottom[data] = top[data] = firstNode;
            else  //箱子不空
            {
                top[data]->next = firstNode;
                top[data] = firstNode;
            }
        }

        //把箱子中的结点收集到有序链表
        chainNode<T>* y = nullptr;
        for (int bin = 0; bin <= range; bin++)
        {
            if (bottom[bin] != nullptr)
            {
                if (y == nullptr)  //第一个非空箱子
                    firstNode = bottom[bin];
                else
                    y->next = bottom[bin];
                y = top[bin];
            }
        }
        if (y->next != nullptr)
            y->next = nullptr;
        cout << "(*this) = " << *this << endl;
    }
    delete[] bottom;
    delete[] top;
}


/*非成员方法*/
/*meld()：生成一个新的扩展的链表c,它从a的首元素开始，交替地包含a和b的元素。
如果一个链表的元素取完了，就把另一个链表的剩余元素附加到新的扩展链表c中。*/
template<class T>
void meld(chain<T>& a, chain<T>& b, chain<T>& c)
{
    c.clear();//先清空链表C
    typename chain<T>::iterator pointerA = a.begin();
    typename chain<T>::iterator pointerB = b.begin();
    while (pointerA != nullptr && pointerB != nullptr)
    {
        c.push_back(*pointerA);
        pointerA++;
        c.push_back(*pointerB);
        pointerB++;
    }
    while (pointerA != nullptr)
    {
        c.push_back(*pointerA);
        pointerA++;
    }
    while (pointerB != nullptr)
    {
        c.push_back(*pointerB);
        pointerB++;
    }
}

/*方法merge()---生成一个新的有序链表c,包含了a和b的所有元素,且函数后a,b链表不为空*/
template<class T>
void merge(chain<T>& a, chain<T>& b, chain<T>& c)
{
    c.clear();//先清空链表C
    typename chain<T>::iterator pointerA = a.begin();
    typename chain<T>::iterator pointerB = b.begin();
    while (pointerA != nullptr && pointerB != nullptr)
    {
        /*插入小的那一个*/
        if (*pointerA > *pointerB)
        {
            c.push_back(*pointerB);
            pointerB++;
        }
        else
        {
            c.push_back(*pointerA);
            pointerA++;
        }
    }
    while (pointerA != nullptr)
    {
        c.push_back(*pointerA);
        pointerA++;
    }
    while (pointerB != nullptr)
    {
        c.push_back(*pointerB);
        pointerB++;
    }
}

/*生成两个链表a和b,a包含c中索引为奇数的元素，b包含c中其他的元素，且函数后c链表不为空*/
template<class T>
void split(chain<T>& a, chain<T>& b, chain<T>& c)
{
    //先清空链表a和链表b
    a.clear();
    b.clear();
    typename chain<T>::iterator pointerC = c.begin();
    for (int i = 0; i < c.size(); i++)
    {
        if (i % 2 == 1)
        {
            a.push_back(*pointerC);
            pointerC++;
        }
        else
        {
            b.push_back(*pointerC);
            pointerC++;
        }
    }
}

#endif