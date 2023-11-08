/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			数组存储的二维矩阵类头文件
*/
#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_
#include "_1myExceptions.h"
#include<iostream>
#include <algorithm>
using namespace std;
//矩阵的测试cpp文件
void matrixTest();
/*行主描述的矩阵*/
template<class T>
class matrix
{
public:
    int rows() const { return theRows; }
    int columns() const { return theColumns; }
    matrix(int theRows, int theColumns);//已测
    matrix(const matrix<T>& m);//已测
    matrix<T>& operator=(const matrix<T>& m);//已测
    T& operator()(int i, int j) const;//已测
    matrix<T> operator+() const;//已测
    matrix<T> operator+(const matrix<T>& m) const;//已测
    matrix<T> operator+(const T& data) const;//已测
    matrix<T>& operator+=(const matrix<T>& m);//已测
    matrix<T>& operator+=(const T& data);//已测
    matrix<T> operator-() const;
    matrix<T> operator-(const matrix<T>& m) const;
    matrix<T> operator-(const T& data) const;
    matrix<T>& operator-=(const matrix<T>& m);
    matrix<T>& operator-=(const T& data);
    matrix<T> operator*(const matrix<T>& m) const;
    matrix<T> operator*(const T& data) const;
    matrix<T>& operator*=(const T& data);
    matrix<T> operator/(const T& data) const;
    matrix<T>& operator/=(const T& data);
    matrix<T> tranpose();
    //<<和>>没有加<T>之前一直报错LNK1120和LNK2019,加了之后就不报错了，我也不知道为什么
    //应该是一种实例化吧
    istream& input(istream& in);
    void output(ostream& out) const;
private:
    int theRows;//矩阵的行数
    int theColumns;//矩阵的列数
    T* element;//数组element
};
/*友元函数:重载输出操作符*/
/*数组元素输出*/
template<class T>
void matrix<T>::output(ostream& out) const
{
    int k = 0;
    for (int i = 0; i < theRows; i++)
    {
        cout << endl;
        for (int j = 0; j < theColumns; j++)
        {
            out.width(3);
            out << element[k++] << "  ";
        }
    }
    return;
}
/*input函数*/
template<class T>
istream& matrix<T>::input(istream& in){
    cout << "请输入矩阵" << theRows << "*" << theColumns << ":" << endl;
    for (int i = 0; i < (theRows) * (theColumns); i++)
    {
        cout << "Please enter a data: ";
        while (!(in >> element[i])) {//如果输入类型不匹配，则执行循环体
            in.clear(); // reset input设置标志位为有效
            while (in.get() != '\n') //删除没有用的输入
                continue; // get rid of bad input
            cout << "Please enter a data: ";
        }
    }
    return in;
}

/*重载<<操作符*/
template<class T>
ostream& operator<<(ostream& out, const matrix<T>& x)
{
    x.output(out);
    return out;
}
/*重载>>操作符*/
template<typename T>
std::istream& operator>>(std::istream &os, matrix<T>& m)
{
    m.input(os);
    return os;
}

/*构造函数*/
template<class T>
matrix<T>::matrix(int theRows, int theColumns)
{
    //检验行数和列数的有效性
    if (theRows < 0 || theColumns < 0)
        throw illegalParameterValue("Rows and columns mush be >=0");
    if((theRows==0||theColumns==0)&&(theRows!=0||theColumns!=0)) //要为0时行数和列数必须同时为0
        throw illegalParameterValue("Either both or neither rows and columns should be zero");
    //创建矩阵
    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T[theRows * theColumns];
}
/*复制构造函数*/
template<class T>
matrix<T>::matrix(const matrix<T>& m)
{
    //创建数组
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T[theRows * theColumns];

    //复制m的每一个元素
    copy(m.element, m.element + theRows * theColumns, element);
}
/*矩阵转置*/
template<class T>
matrix<T> matrix<T>::tranpose()
{
    matrix<T> w(theColumns, theRows);
    for(int i = 1;i<=theRows;i++)
        for (int j = 1; j <= theColumns; j++)
        {
            w(j, i) = (*this)(i, j);
        }
    return w;
}

/*重载操作符*/
/*赋值操作符=的重载*/
template<class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m)
{
    if (this != &m)//不能自己复制自己
    {
        delete[] element;
        theRows = m.theRows;
        theColumns = m.theColumns;
        element = new T[theRows * theColumns];
        //复制m的每一个元素
        copy(m.element, m.element + theRows * theColumns, element);
    }
    return *this;
}
/*重载()操作符*/
template<class T>
T& matrix<T>::operator()(int i, int j) const
{
    if (i<1 || j<1 || i>theRows || j>theColumns)
        throw matrixIndexOutOfBounds();
    return element[(i - 1) * theColumns + j - 1];
}
/*重载一元+操作符*/
template<class T>
matrix<T> matrix<T>::operator+() const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i];
    return w;
}
/*重载二元+操作符*/
template<class T>
matrix<T> matrix<T>::operator+(const matrix<T>& m) const
{
    if (theRows != m.theRows || theColumns != m.theColumns)
        throw matrixSizeMismatch();
    //生成结果矩阵
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] + m.element[i];
    return w;
}
/*重载+操作符：让矩阵所有元素都加一个整数*/
template<class T>
matrix<T> matrix<T>::operator+(const T& data) const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] + data;
    return w;
}
/*重载+=操作符*/
/*当前矩阵加一个矩阵*/
template<class T>
matrix<T>& matrix<T>::operator+=(const matrix<T>& m)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] = element[i] + m.element[i];
    return *this;
}
/*重载+=操作符*/
/*当前矩阵每个元素加一个数*/
template<class T>
matrix<T>& matrix<T>::operator+=(const T& data)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] = element[i] + data;
    return *this;
}
/*重载一元-操作符*/
template<class T>
matrix<T> matrix<T>::operator-() const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = -element[i];
    return w;
}
/*重载二元-操作符：矩阵减矩阵*/
template<class T>
matrix<T> matrix<T>::operator-(const matrix<T>& m) const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] - m.element[i];
    return w;
}
/*重载二元-操作符：矩阵减数据*/
template<class T>
matrix<T> matrix<T>::operator-(const T& data) const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] - data;
    return w;
}
/*重载-=操作符：矩阵加一个矩阵*/
template<class T>
matrix<T>& matrix<T>::operator-=(const matrix<T>& m)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] = element[i] - m.element[i];
    return *this;
}
/*重载-=操作符：矩阵的每个元素加数data*/
template<class T>
matrix<T>& matrix<T>::operator-=(const T& data)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] = element[i] - data;
    return *this;
}
/*重载*操作符*/
template<class T>
matrix<T> matrix<T>::operator*(const matrix<T>& m) const
{
    if (theColumns != m.theRows)
        throw matrixSizeMismatch();
    matrix<T> w(theRows, m.theColumns);//结果矩阵
    int indext = 0, indexm = 0, indexw = 0;//三个矩阵的游标
    T multiData = 0;
    for (int i = 1; i <= theRows; i++)
    {
        for (int j = 1; j <= m.theColumns; j++)
        {
            multiData = element[indext] * element[indexm];
            for (int k = 2; k <= theColumns; k++)
            {
                indext++;
                indexm += m.theColumns;
                multiData += element[indext] * element[indexm];
            }
            w.element[indexw++] = multiData;
            //从行的起点和下一列从新开始
            indext -= (theColumns - 1);
            indexm = j;
        }
        //从下一行和下一列重新开始
        indext += theColumns;
        indexm = 0;
    }
    return w;
}
/*重载*操作符：矩阵乘以数据data*/
template<class T>
matrix<T> matrix<T>::operator*(const T& data) const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] * data;
    return w;
}
/*重载*=操作符：矩阵乘以矩阵,不好弄且没必要*/
/*重载*=操作符：矩阵乘以数据data*/
template<class T>
matrix<T>& matrix<T>::operator*=(const T& data)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] = element[i] * data;
    return *this;
}
/*重载/操作符*/
template<class T>
matrix<T> matrix<T>::operator/(const T& data) const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] / data;
    return w;
}
/*重载/=操作符*/
template<class T>
matrix<T>& matrix<T>::operator/=(const T& data)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] = element[i] / data;
    return *this;
}

#endif
