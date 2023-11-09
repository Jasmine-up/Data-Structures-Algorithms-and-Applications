/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			无序的双端队列的抽象类的头文件
*/
#pragma once
#ifndef _DEQUE_H_
#define _DEQUE_H_
template<class T>
class deque
{
public:
    virtual ~deque() {}
    virtual bool empty() const = 0;//返回true,当且仅当队列为空
    virtual int size() const = 0;//返回队列中元素个数
    virtual T& front() = 0;//返回头元素的引用
    virtual T& back() = 0;//返回尾元素的引用
    virtual void pop_front() = 0;//删除首元素
    virtual void pop_back() = 0;//删除尾元素
    virtual void push_front(const T& theElement) = 0;//把元素theELment加入队首
    virtual void push_back(const T& theElement) = 0;//把元素theELment加入队尾
};
#endif
