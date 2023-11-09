/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			数组存储的无序的双端队列类的头文件
*/
#pragma once
#ifndef _ARRAYDEQUE_H_
#define _ARRAYDEQUE_H_
#include<sstream>
#include<iostream>
#include "_1myExceptions.h"
#include "_19deque.h"
/*测试函数*/
void arrayDequeTest();
template<class T>
class arrayDeque : public deque<T>
{
public:
    /*成员函数*/
    /*构造函数*/
    arrayDeque(int initialCapacity = 10);
    /*析构函数*/
    ~arrayDeque() {
        delete[]  deque;
    }
    bool empty() const { return theFront == theBack; };//返回true,当且仅当队列为空
    int size() const { return (dequeLength - theFront + theBack)%dequeLength; };//返回队列中元素个数
    int capacity() const {
        return dequeLength - 1;
    }
    void clear() { theFront = theBack = 0; }
    T& front();//返回头元素的引用
    T& back();//返回尾元素的引用
    void pop_front();//删除首元素
    void pop_back();//删除尾元素
    void push_front(const T& theElement);//把元素theELment加入队首
    void push_back(const T& theElement);//把元素theELment加入队尾
    /*调整队列容量大小*/
    void resizeDeque(int newLength);
    void meld(arrayDeque<T>& a, arrayDeque<T>& b);
    void split(arrayDeque<T>& a, arrayDeque<T>& b);

    /*重载操作符*/
    /*重载[]操作符*/
    T operator[](int i) { return deque[(theFront + i + 1) % dequeLength]; }

    istream& input(istream& in);
    void output(ostream& out) const;
//    /*友元函数*/
//    friend istream& operator>> <T>(istream& in, arrayDeque<T>& m);
//    //输出但是不pop()元素
//    friend ostream& operator<< <T>(ostream& out, arrayDeque<T>& m);
private:
    int theFront;       // 第一个元素的前一个位置
    int theBack;        // 最后一个元素的位置
    int dequeLength;    // 队列的容量，实质上比队列容量(不包含queueFront指向的那一个位置)大1
    T* deque;
};

/*友元函数*/
/*>>操作符*/
template<class T>
istream& arrayDeque<T>::input(istream& in)
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
        push_back(cinElement);
    }
    return in;
}

template<class T>
istream& operator>>(istream& in, arrayDeque<T>& m){
    m.input(in);
    return in;
}

/*<<操作符*/
template<class T>
void arrayDeque<T>::output(ostream& out) const
{
    int length = size();
    for (int i = 0; i < length; i++)
        out << deque[(theFront + i + 1) % dequeLength] << "  ";
    out << endl;
}

template<class T>
ostream& operator<<(ostream& out, const arrayDeque<T>& x)
{
    x.output(out);
    return out;
}

/*构造函数*/
template<class T>
arrayDeque<T>::arrayDeque(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s("");
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    deque = new T[initialCapacity + 1];
    dequeLength = initialCapacity + 1;
    theFront = theBack = 0;
}
/*返回头元素的引用*/
template<class T>
T& arrayDeque<T>::front()
{
    if(theFront == theBack)
        throw queueEmpty();
    return deque[(theFront + 1) % dequeLength];
}
/*返回尾元素的引用*/
template<class T>
T& arrayDeque<T>::back()
{
    if (theFront == theBack)
        throw queueEmpty();
    return deque[theBack];
}
/*删除首元素*/
template<class T>
void arrayDeque<T>::pop_front()
{
    /*检查是否为空，为空就抛出异常*/
    if (theFront == theBack)
        throw queueEmpty();
    /*不为空就删除首元素*/
    theFront = (theFront + 1) % dequeLength;
    deque[theFront].~T();
}
/*删除尾元素*/
template<class T>
void arrayDeque<T>::pop_back()
{
    /*检查是否为空，为空就抛出异常*/
    if (theFront == theBack)
        throw queueEmpty();
    /*不为空就删除尾元素*/
    deque[theBack].~T();
    if (theBack == 0)
        theBack = dequeLength - 1;
    else
        theBack--;
}
/*把元素theELment加入队首*/
template<class T>
void arrayDeque<T>::push_front(const T& theElement)
{
    /*判断队列是否满了，如果满了，就调整容量为原来的两倍*/
    if ((theFront + 1) % dequeLength == theBack)
        resizeDeque(2 * (dequeLength-1));
    deque[theFront] = theElement;
    if (theFront == 0)
        theFront = dequeLength - 1;
    else
        theFront = theFront - 1;
}
/*把元素theELment加入队尾*/
template<class T>
void arrayDeque<T>::push_back(const T& theElement)
{
    /*判断队列是否满了，如果满了，就调整容量为原来的两倍*/
    if ((theBack + 1) % dequeLength == theFront)
        resizeDeque(2 * (dequeLength - 1));
    theBack = (theBack + 1) % dequeLength;
    deque[theBack] = theElement;
}

/*调整队列容量大小*/
template<class T>
void arrayDeque<T>::resizeDeque(int newLength)
{
    T* temp = new T[newLength + 1];
    int size = min((*this).size(), newLength);
    for (int i = 0; i < size; i++)
        temp[i] = deque[(theFront + i + 1) % dequeLength];
    dequeLength = newLength + 1;
    theFront = newLength;
    theBack = size - 1;
    delete[] deque;
    deque = temp;
}

/*
创建一个新的队列，该表包含了a和b中的所有元素，其中a和b的元素轮流出现，表中的首
元素为a中的第一个元素。在轮流排列元素时，如果某个队列的元素用完了，则把另一个队列的其
余元素依次添加在新队列的后部。代码的复杂性应与两个输入队列的长度呈线性比例关系。
归并后的线性队列是调用对象*this
*/
template <class T>
void arrayDeque<T>::meld(arrayDeque<T>& a, arrayDeque<T>& b)
{
    (*this).clear();
    int i = 0;
    while (i < a.size() && i < b.size())
    {
        push_back(a[i]);
        push_back(b[i]);
        i++;
    }
    while (i < a.size())
    {
        push_back(a[i]);
        i++;
    }
    while (i < b.size())
    {
        push_back(b[i]);
        i++;
    }
}

/*生成两个线性队列a和b，a包含*this中索引为奇数的元素，b包含其余的元素*/
template<class T>
void arrayDeque<T>::split(arrayDeque<T>& a, arrayDeque<T>& b)
{
    a.clear();
    b.clear();
    int size = (*this).size();
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            a.push_back(deque[(theFront + i + 1) % dequeLength]);
        else
            b.push_back(deque[(theFront + i + 1) % dequeLength]);
    }
}

#endif
