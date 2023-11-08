/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			用于存储稀疏矩阵的行号、列号和元素的结构体
*/

#ifndef _MATRIXTERM_H_
#define _MATRIXTERM_H_
using namespace std;
template <class T>
struct matrixTerm
{
    int row,
            col;
    T value;

    operator T() const {return value;}
    // type conversion from matrixTerm to T
};

#endif
