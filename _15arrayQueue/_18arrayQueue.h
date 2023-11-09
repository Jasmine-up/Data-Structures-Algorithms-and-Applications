/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			数组存储的队列的头文件
*/
#pragma once
#ifndef _ARRAYQUEUE_H_
#define _ARRAYQUEUE_H_
#include<sstream>
#include<iostream>
#include "_1myExceptions.h"
#include "_17queue.h"
#include <cmath>
/*测试函数*/
void arrayQueueTest();

using namespace std;
template<class T>
class arrayQueue : public queue<T>
{
public:
    /*成员函数*/
    arrayQueue(int initialCapacity = 10);
    ~arrayQueue() { delete[] queue; }
    bool empty() const { return theFront == theBack; }
    int size() const //返回队列的元素个数
    {
        return (queueLength - theFront + theBack) % queueLength;
    }
    void clear() { theFront = theBack = 0; }/*清空队列中的元素*/
    int capacity() const { return queueLength-1; }
    //返回第一个元素
    T& front()
    {
        if (theFront == theBack)
            throw queueEmpty();
        return queue[(theFront + 1) % queueLength];
    }
    //返回最后一个元素
    T& back()
    {
        if (theFront == theBack)
            throw queueEmpty();
        return queue[theBack];
    }
    //删除队首元素
    void pop()
    {
        if (theFront == theBack)
            throw queueEmpty();
        theFront = (theFront + 1) % queueLength;
        queue[theFront].~T();
    }
    //向队尾插入元素theElement
    void push(const T& theElement);
    /*调整队列容量大小*/
    void resizeQueue(int newLength);
    void meld(arrayQueue<T>& a, arrayQueue<T>& b);//合并队列a,b到当前队列
    void split(arrayQueue<T>& a, arrayQueue<T>& b);//将当前队列分成两个队列a,b

    /*重载操作符*/
    /*重载[]操作符*/
    T operator[](int i)
    { return queue[(theFront + i + 1) % queueLength]; }

    istream& input(istream& in);
    void output(ostream& out) const;
//    /*友元函数*/
//    friend istream& operator>> <T>(istream& in, arrayQueue<T>& m);
//    //输出但是不pop()元素
//    friend ostream& operator<< <T>(ostream& out, arrayQueue<T>& m);
private:
    int theFront;       // 第一个元素的前一个位置
    int theBack;        // 最后一个元素的位置
    int queueLength;    // 队列的容量，实质上比队列容量(不包含queueFront指向的那一个位置)大1
    T* queue;           // 指向队列首地址的指针
};
/*友元函数*/
/*>>操作符*/
template<class T>
istream& arrayQueue<T>::input(istream& in)
{
    int numberOfElement = 0;
    cout << "Please enter the number of element:";
    while (!(in >> numberOfElement))
    {
        in.clear();//清空标志位
        while (in.get() != '\n')//删除无效的输入
            continue;
        cout << "Please enter the number of element:";
    }
    T cinElement;
    for (int i = 0; i < numberOfElement; i++)
    {
        cout << "Please enter the element " << i + 1 << ":";
        while (!(in >> cinElement))
        {
            in.clear();//清空标志位
            while (in.get() != '\n')//删除无效的输入
                continue;
            cout << "Please enter the element " << i + 1 << ":";
        }
        push(cinElement);
    }
    return in;
}

template<class T>
istream& operator>>(istream& in, arrayQueue<T>& m){
    m.input(in);
    return in;
}

/*<<操作符*/
template<class T>
void arrayQueue<T>::output(ostream& out) const
{
    int length = size();
    for (int i = 0; i < length; i++)
        out << queue[(theFront + i + 1) % queueLength] << "  ";
    out << endl;
}
template<class T>
ostream& operator<<(ostream& out, const arrayQueue<T>& x)
{
    x.output(out);
    return out;
}
/*成员函数*/
/*构造函数*/
template<class T>
arrayQueue<T>::arrayQueue(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s("");
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    queue = new T[initialCapacity+1];
    queueLength = initialCapacity+1;
    theFront = theBack = 0;
}

/*向队尾插入元素theElement*/
template<class T>
void arrayQueue<T>::push(const T& theElement)
{
    //首先检查队列是否已满，如已满，则将队列容量加倍
    if ((theBack + 1) % queueLength == theFront)
        resizeQueue(2 * (queueLength-1));
    theBack = (theBack + 1) % queueLength;
    queue[theBack] = theElement;
}
/*调整队列容量大小*/
template<class T>
void arrayQueue<T>::resizeQueue(int newLength)
{
    T* temp = new T[newLength + 1];
    int size = min((*this).size(), newLength);
    for (int i = 0; i < size; i++)
        temp[i] = queue[(theFront + i + 1) % queueLength];
    queueLength = newLength+1;
    theFront = newLength;
    theBack = size - 1;
    delete[] queue;
    queue = temp;
}

/*
创建一个新的队列，该表包含了a和b中的所有元素，其中a和b的元素轮流出现，表中的首
元素为a中的第一个元素。在轮流排列元素时，如果某个队列的元素用完了，则把另一个队列的其
余元素依次添加在新队列的后部。代码的复杂性应与两个输入队列的长度呈线性比例关系。
归并后的线性队列是调用对象*this
*/
template <class T>
void arrayQueue<T>::meld(arrayQueue<T>& a, arrayQueue<T>& b)
{
    (*this).clear();
    int i = 0;
    while (i < a.size() && i < b.size())
    {
        push(a[i]);
        push(b[i]);
        i++;
    }
    while (i < a.size())
    {
        push(a[i]);
        i++;
    }
    while (i < b.size())
    {
        push(b[i]);
        i++;
    }
}

/*生成两个线性队列a和b，a包含*this中索引为奇数的元素，b包含其余的元素*/
template<class T>
void arrayQueue<T>::split(arrayQueue<T>& a, arrayQueue<T>& b)
{
    a.clear();
    b.clear();
    int size = (*this).size();
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            a.push(queue[(theFront + i + 1) % queueLength]);
        else
            b.push(queue[(theFront + i + 1) % queueLength]);
    }
}
#endif
