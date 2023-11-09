/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			链表存储的队列的头文件
*/
#pragma once
#ifndef _LINKEDQUEUE_H_
#define _LINKEDQUEUE_H_
#include<sstream>
#include<iostream>
#include "_1myExceptions.h"
#include "_6chainNode.h"
#include "_17queue.h"
/*测试函数*/
void linkedQueueTest();

using namespace std;
template<class T>
class linkedQueue : public queue<T>
{
public:
    /*成员函数*/
    linkedQueue(int initialCapacity = 10)
    {
        theFront = theBack = nullptr;
        queueSize = 0;
    }
    ~linkedQueue();
    bool empty() const { return queueSize == 0; }
    //返回队列的元素个数
    int size() const { return queueSize; }
    /*清空队列中的元素*/
    void clear();
    /*返回第一个元素*/
    T& front() { return theFront->element; }
    /*返回最后一个元素*/
    T& back() { return theBack->element; }
    /*删除队首元素*/
    void pop()
    {
        chainNode<T>* next = theFront->next;
        delete theFront;
        theFront = next;
        queueSize--;
    }
    /*向队尾插入元素theElement*/
    void push(const T& theElement)
    {
        if (queueSize == 0)
            theFront = theBack = new chainNode<T>(theElement, nullptr);
        else
        {
            theBack->next = new chainNode<T>(theElement, nullptr);
            theBack = theBack->next;
        }
        queueSize++;
    }
    //void meld(arrayQueue<T>& a, arrayQueue<T>& b);//合并队列a,b到当前队列
    //void split(arrayQueue<T>& a, arrayQueue<T>& b);//将当前队列分成两个队列a,b

    /*重载操作符*/
    /*重载[]操作符*/
    T operator[](int i)
    {
        chainNode<T>* currentNode = theFront;
        for (int j = 0; j < i; j++)
            currentNode = currentNode->next;
        return currentNode->element;
    }

    istream& input(istream& in);
    void output(ostream& out) const;
//    /*友元函数*/
//    friend istream& operator>> <T>(istream& in, linkedQueue<T>& m);
//    //输出但是不pop()元素
//    friend ostream& operator<< <T>(ostream& out, linkedQueue<T>& m);
private:
    chainNode<T>* theFront;       // 指向第一个元素的指针
    chainNode<T>* theBack;        // 指向最后一个元素的指针
    int queueSize;    // 队列的容量，实质上比队列容量(不包含queueFront指向的那一个位置)大1
};
/*友元函数*/
/*>>操作符*/
template<class T>
istream& linkedQueue<T>::input(istream& in)
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
istream& operator>>(istream& in, linkedQueue<T>& m){
    m.input(in);
    return in;
}

//输出但是不pop()元素
/*<<操作符*/
template<class T>
void linkedQueue<T>::output(ostream& out) const
{
    chainNode<T>* currentNode =  theFront;
    while(currentNode != nullptr)
    {
        cout << currentNode->element << " ";
        currentNode = currentNode->next;
    }
    out << endl;
}

template<class T>
ostream& operator<<(ostream& out, const linkedQueue<T>& x)
{
    x.output(out);
    return out;
}
/*成员函数*/
/*析构函数*/
template<class T>
linkedQueue<T>::~linkedQueue()
{
    chainNode<T>* nextNode = theFront;
    while (nextNode != nullptr)
    {
        nextNode = nextNode->next;
        delete theFront;
        theFront = nextNode;
    }
}
/*清空队列中的元素*/
template<class T>
void linkedQueue<T>::clear()
{
    chainNode<T>* nextNode = theFront;
    while (nextNode != nullptr)
    {
        nextNode = nextNode->next;
        delete theFront;
        theFront = nextNode;
    }
    queueSize = 0;
    theFront = theBack = nullptr;
}

#endif
