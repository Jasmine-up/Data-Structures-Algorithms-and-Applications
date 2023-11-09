/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			队列的抽象类
*/
#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_
template<class T>
class queue
{
public:
    virtual ~queue() {}
    virtual bool empty() const = 0;//返回true,当且仅当队列为空
    virtual int size() const = 0;//返回队列中元素个数
    virtual T& front() = 0;//返回头元素的引用
    virtual T& back() = 0;//返回尾元素的引用
    virtual void pop() = 0;//删除首元素
    virtual void push(const T& theElement) = 0;//把元素theELment加入队尾
};
#endif
