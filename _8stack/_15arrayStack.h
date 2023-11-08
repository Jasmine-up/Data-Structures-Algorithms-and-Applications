/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			数组存储的栈类的头文件
*/
#pragma once
#ifndef _ARRAYSTACK_H_
#define _ARRAYSTACK_H_
#include "_1myExceptions.h"
#include "_14stack.h"
#include<iostream>
#include<sstream>
#include<cstring>
using std::ostringstream;
using std::endl;
using std::cout;
using std::istream;
using std::ostream;
using std::string;
//测试函数
void arrayStackTest();
/*
作用：将数组的长度加倍
输入：指针a指向需要改变长度的数组，oldLength表示数组原来的长度，newLength表示需要改变的新长度
结果：将数组扩容/缩容 为newLength
*/
template<class T>
void changeLength(T*& a, int oldLength, int newLength)
{
    if (newLength < 0)
        throw illegalParameterValue("new length must be >= 0");
    T* temp = new T[newLength];
    int number = min(oldLength, newLength);
    copy(a, a + number, temp);
    delete[] a;
    a = temp;
}

/*本来可以直接派生arrayList来实现，但是该方法会损失性能。*/
/*因此本节开发一个类，利用数组来包含所有的栈元素*/
template<class T>
class arrayStack :public stack<T>
{
public:
    arrayStack(int initialCapacity = 10);
    ~arrayStack() { delete[] stack; }
    bool empty() const { return stackTop == -1; }
    int size() const { return stackTop + 1; }
    int capacity() const { return stackLength; }
    T& top()
    {
        if (stackTop == -1)
            throw stackEmpty();
        return stack[stackTop];
    }
    T pop()
    {
        if (stackTop == -1)
            throw stackEmpty();
        T temp = stack[stackTop];
        stack[stackTop--].~T();//T的析构函数
        while (stackTop + 1 < stackLength / 4)
        {
            changeLength(stack, stackLength, stackLength / 2);
            stackLength /= 2;
        }
        return temp;
    }
    void push(const T& theElement);
    void clear() { stackTop = -1; }
    void split(arrayStack<T>& a, arrayStack<T>& b);
    void merge(arrayStack<T>& a);

    /*重载操作符*/
    /*重载操作符[]*/
    T& operator[](int i) { return stack[i]; }

    istream& input(istream& in);
    void output(ostream& out) const;
private:
    int stackTop;//当前栈顶
    int stackLength;//栈容量
    T* stack;//元素数组
};
/*友元函数*/
/*>>操作符*/
template<class T>
istream& arrayStack<T>::input(istream& in)
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
/*<<操作符*/
template<class T>
void arrayStack<T>::output(ostream& out) const
{
    for (int i = 0; i <= stackTop; i++)
        out << stack[i] << "  ";
    out << endl;
}

/*重载<<操作符*/
template<class T>
ostream& operator<<(ostream& out, const arrayStack<T>& x)
{
    x.output(out);
    return out;
}
/*重载>>操作符*/
template<typename T>
std::istream& operator>>(std::istream &os, arrayStack<T>& m)
{
    m.input(os);
    return os;
}

/*构造函数*/
template<class T>
arrayStack<T>::arrayStack(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s("");
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    stackLength = initialCapacity;
    stack = new T[initialCapacity];
    stackTop = -1;
}

/*将元素theElement压入栈*/
template<class T>
void arrayStack<T>::push(const T& theElement)
{
    if (stackTop == stackLength - 1)
    {
        //空间已满，容量加倍
        changeLength(stack, stackLength, 2 * stackLength);
        stackLength *= 2;
    }
    stack[++stackTop] = theElement;
}
/*将一个栈分裂为两个栈。第一个栈包含从栈底开始的一半元素，第二个栈包含剩余元素*/
template<class T>
void arrayStack<T>::split(arrayStack<T>& a, arrayStack<T>& b)
{
    //首先清空a,b栈
    b.clear();
    a.clear();
    /*将当前栈中的前一半元素存入a栈中*/
    int i = 0;
    for (i = 0; i <= stackTop / 2; i++)
        a.push(stack[i]);
    /*将当前栈中的后一半元素存入b栈中*/
    for (; i <= stackTop; i++)
        b.push(stack[i]);
}
/*将两个栈合并，把第二个栈的所有元素置于第一个栈的顶部。不改变第二个栈中元素的相对顺序*/
template<class T>
void arrayStack<T>::merge(arrayStack<T>& a)
{
    for (int i = 0; i <= a.stackTop; i++)
        push(a.stack[i]);
}
#endif
