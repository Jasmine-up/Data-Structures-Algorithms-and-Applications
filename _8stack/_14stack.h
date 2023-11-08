/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			抽象类栈
*/
#pragma once
#ifndef _STACK_H_
#define _STACK_H_
/*抽象类栈*/
template<class T>
class stack
{
public:
    virtual ~stack() {}
    //返回true，当且仅当栈为空
    virtual bool empty() const = 0;
    //返回栈中元素个数
    virtual int size() const = 0;
    //返回栈顶元素的引用
    virtual T& top() = 0;
    //删除栈顶元素
    virtual T pop() = 0;
    //将元素theElement压入栈顶
    virtual void push(const T& theELment) = 0;
};
#endif
