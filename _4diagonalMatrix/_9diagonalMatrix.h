/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����洢�ĶԽǾ�����ͷ�ļ�
*/
#pragma once
#ifndef _DIAGONALMATRIX_H_
#define _DIAGONALMATRIX_H_
#include "_1myExceptions.h"
using namespace std;
void diagonalMatrixTest();//���Դ���

template<class T>
class diagonalMatrix
{
public:
    diagonalMatrix(int theN = 10);
    ~diagonalMatrix() {delete [] element;}
    T get(int, int) const;
    void set(int, int, const T&);
private:
    int n;       // matrix dimension
    T *element;  // 1D array for diagonal elements
};

template<class T>
diagonalMatrix<T>::diagonalMatrix(int theN)
{// Constructor.
    // validate theN
    if (theN < 1)
        throw illegalParameterValue("Matrix size must be > 0");

    n = theN;
    element = new T [n];
}

template <class T>
T diagonalMatrix<T>::get(int i, int j) const
{// Return (i,j)th element of matrix.
    // validate i and j
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();

    if (i == j)
        return element[i-1];   // diagonal element
    else
        return 0;              // nondiagonal element
}

template<class T>
void diagonalMatrix<T>::set(int i, int j, const T& newValue)
{// Store newValue as (i,j)th element.
    // validate i and j
    if (i < 1 || j < 1 || i > n || j > n)
        throw matrixIndexOutOfBounds();

    if (i == j)
        // save the diagonal value
        element[i-1] = newValue;
    else
        // nondiagonal value, newValue must be zero
    if (newValue != 0)
        throw illegalParameterValue
                ("nondiagonal elements must be zero");
}

#endif
