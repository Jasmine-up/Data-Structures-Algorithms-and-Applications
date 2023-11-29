/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			综合各种非成员函数
*/
#pragma once
#ifndef _MYFUNCTIONS_H_
#define _MYFUNCTIONS_H_
#include<iostream>
#include "_1myExceptions.h"
#include<cmath>
#include <exception>
#include <memory>

using std::min;
using std::endl;
using std::cout;
using std::bad_alloc;
/*交换两数据*/
template<class V>
void Swap(V& a, V& b)
{
    V temp = a;
    a = b;
    b = temp;
}
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
/*遍历一维数组*/
template<class T>
void traverse1dArray(T* x, int length)
{
    for (int i = 0; i < length; i++)
        cout << x[i] << " ";
    cout << endl;
}
/*创建二维数组*/
template <class T>
bool make2dArray(T**& x, int numberOfRows, int numberOfColumns)
{
    try {
        //行指针
        x = new T * [numberOfRows];
        //为每一行分配内存
        for (int i = 0; i < numberOfRows; i++)
            x[i] = new int[numberOfColumns];
        return true;
    }
    catch (bad_alloc) { return false; }
}

/*遍历二维数组*/
template<class T>
void traverse2dArray(T**& x, int numberOfRows, int numberOfColumns)
{
    for (int i = 0; i < numberOfRows; i++)
    {
        for (int j = 0; j < numberOfColumns; j++)
        {
            cout.width(4);
            cout << x[i][j] << "  ";
        }
        cout << endl;
    }
}
template<class T>
void changeLength1D(T*& a, int oldLength, int newLength)
{
    if (newLength < 0)
        throw illegalParameterValue("new length must be >= 0");

    T* temp = new T[newLength];              // new array
    int number = min(oldLength, newLength);  // number to copy
    copy(a, a + number, temp);
    a = temp;
}
#endif