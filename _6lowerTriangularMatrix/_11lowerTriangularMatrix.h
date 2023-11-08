/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			数组存储的下三角矩阵类头文件
*/
#pragma once
#ifndef _LOWERTRIANGULARMATRIX_H_
#define _LOWERTRIANGULARMATRIX_H_
#include "_1myExceptions.h"
using namespace std;
void lowerTriangularMatrixTest();//测试函数

template<class T>
class lowerTriangularMatrix
{
public:
    lowerTriangularMatrix(int theN = 10);
    ~lowerTriangularMatrix() {delete [] element;}
    T get(int, int) const;
    void set(int, int, const T&);
private:
    int n;       // matrix dimension
    T *element;  // 1D array for lower triangle
};


template<class T>
lowerTriangularMatrix<T>::lowerTriangularMatrix(int theN)
{// Constructor.
    // validate theN
    if (theN < 1)
        throw illegalParameterValue("Matrix size must be > 0");

    n = theN;
    element = new T [n * (n + 1) / 2];
}

template <class T>
T lowerTriangularMatrix<T>::get(int i, int j) const
{// Return (i,j)th element of matrix.
    // validate i and j
    if ( i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();

    // (i,j) in lower triangle if i >= j
    if (i >= j)
        return element[i * (i - 1) / 2 + j - 1];
    else
        return 0;
}

template<class T>
void lowerTriangularMatrix<T>::set(int i, int j, const T& newValue)
{// Store newValue as (i,j)th element.
    // validate i and j
    if ( i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();

    // (i,j) in lower triangle iff i >= j
    if (i >= j)
        element[i * (i - 1) / 2 + j - 1] = newValue;
    else
    if (newValue != 0)
        throw illegalParameterValue
                ("elements not in lower triangle must be zero");
}

#endif
