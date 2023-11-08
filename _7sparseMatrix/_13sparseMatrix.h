/*
Project name :			allAlgorithmsTest
Last modified Date:		2023年9月19日21点59分
Last Version:			V1.0
Descriptions:			数组线性表存储的稀疏矩阵类头文件
*/
#pragma once
//稀疏矩阵的类
#ifndef _SPARSEMATRIX_H_
#define _SPARSEMATRIX_H_

#include <iostream>
#include "_12matrixTerm.h"
#include <vector>
#include "_1myExceptions.h"
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::vector;
using std::endl;
void sparseMatrixTest();//测试函数
/*行主描述的稀疏矩阵*/
template<class T>
class sparseMatrix
{
public:
    void transpose(sparseMatrix<T>& b);
    void add(sparseMatrix<T>& b, sparseMatrix<T>& c);
    istream& input(istream& in);
    void output(ostream& out) const;
private:
    int rows;   // number of rows in matrix
    int cols;    // number of columns in matrix
    vector<matrixTerm<T>> terms;
    // list of nonzero terms
};
// overload <<
template<class T>
void sparseMatrix<T>::output(ostream& out) const
{
    // Put x in output stream.
    // put matrix characteristics
    out << "rows = " << rows << " columns = " << cols << endl;
    out << "nonzero terms = " << terms.size() << endl;
    // put terms, one per line
    for (auto i = terms.begin();i != terms.end(); i++)
        out << "a(" << (*i).row << ',' << (*i).col << ") = " << (*i).value << endl;
    return;
}

// overload >>
/*input函数*/
template<class T>
istream& sparseMatrix<T>::input(istream& in)
{
    // Input a sparse matrix.
    // input matrix characteristics
    int numberOfTerms;
    cout << "Enter number of rows, columns, and #terms" << endl;
    while (!(in >> rows >> cols >> numberOfTerms)) {//如果输入类型不匹配，则执行循环体
        in.clear(); // reset input设置标志位为有效
        while (in.get() != '\n') //删除没有用的输入
            continue; // get rid of bad input
        cout << "Enter number of rows, columns, and #terms" << endl;
    }
    //设置x.terms的大小，确保足够的容量
    terms.resize(numberOfTerms);
    int before_rows = 0, before_columns = 0;
    // input terms
    matrixTerm<T> mTerm;
    for (int i = 0; i < numberOfTerms; i++)
    {
        cout << "Enter row, column, and value of term " << (i + 1) << endl;
        while (!(in >> mTerm.row >> mTerm.col >> mTerm.value)) {//如果输入类型不匹配，则执行循环体
            in.clear(); // reset input设置标志位为有效
            while (in.get() != '\n') //删除没有用的输入
                continue; // get rid of bad input
            cout << "Enter row, column, and value of term " << (i + 1) << endl;
        }
        // 当前元素的位置比之前元素的位置要小
        // 行主索引 > 列主索引
        while (before_rows * cols + before_columns > mTerm.row * rows + mTerm.col)
        {
            cout << "Please enter in row master mapping order:" << endl;
            cout << "Enter row, column, and value of term " << (i + 1) << endl;
            while (!(in >> mTerm.row >> mTerm.col >> mTerm.value)) {//如果输入类型不匹配，则执行循环体
                in.clear(); // reset input设置标志位为有效
                while (in.get() != '\n') //删除没有用的输入
                    continue; // get rid of bad input
                cout << "Enter row, column, and value of term " << (i + 1) << endl;
            }
        }
        terms[i] = mTerm;
        before_rows = mTerm.row;
        before_columns = mTerm.col;
    }
    return in;
}

/*重载<<操作符*/
template<class T>
ostream& operator<<(ostream& out, const sparseMatrix<T>& x)
{
    x.output(out);
    return out;
}
/*重载>>操作符*/
template<typename T>
std::istream& operator>>(std::istream &os, sparseMatrix<T>& m)
{
    m.input(os);
    return os;
}
/*转置:b矩阵存储*this转置的结果*/
/*首先计算*this每一列有多少个非零元素；然后计算*this每一列首个元素的位置；最后复制元素到矩阵b*/
template<class T>
void sparseMatrix<T>::transpose(sparseMatrix<T>& b)
{
    //设置b的行长和列长，以及非零元素的数目
    b.cols = rows;
    b.rows = cols;
    b.terms.resize(terms.size());

    //colSize[i]是矩阵*this在第i列的非0元素个数
    int* colSize = new int[cols + 1];
    //rowNext[i]是转置矩阵b第i行首个非0元素在b中的索引
    int* rowNext = new int[cols + 1];
    //colSize[0]没用
    for (int i = 1; i <= cols; i++)
        colSize[i] = 0;//初始化所有colSize[i]为0
    for (typename vector<matrixTerm<T> >::iterator i = terms.begin(); i != terms.end(); i++)
        colSize[(*i).col]++;//计算矩阵*this在第i列的非0元素个数并存储到colSize中
    //rowNext[0]也没用
    rowNext[1] = 0;
    for (int i = 2; i <= cols; i++)
        rowNext[i] = rowNext[i - 1] + colSize[i - 1];

    matrixTerm<T> mTerm;
    for (typename vector<matrixTerm<T> >::iterator i = terms.begin(); i != terms.end(); i++)
    {
        int j = rowNext[(*i).col]++; // position in b
        mTerm.row = (*i).col;
        mTerm.col = (*i).row;
        mTerm.value = (*i).value;
        b.terms[j] = mTerm;// 2023年9月19日
    }
}
/*c = *this+b;通过从左至右扫描*this和b的非0项来实现的*/
template<class T>
void sparseMatrix<T>::add(sparseMatrix<T>& b, sparseMatrix<T>& c)
{
    //当矩阵*this和矩阵b的大小不匹配时，不可执行加操作
    if (rows != b.rows || cols != b.cols)
        throw matrixSizeMismatch();

    //设置矩阵c的参数
    c.rows = rows;
    c.cols = cols;
    c.terms.clear();//清空矩阵c
    int cSize = 0;

    //为*this和b定义迭代器
    typename vector<matrixTerm<T> >::iterator it = terms.begin();
    typename vector<matrixTerm<T> >::iterator ib = b.terms.begin();
    typename vector<matrixTerm<T> >::iterator itEnd = terms.end();
    typename vector<matrixTerm<T> >::iterator ibEnd = b.terms.end();

    //遍历*this和b,把相关的项相加
    while (it != itEnd && ib != ibEnd)
    {
        //计算行主索引，方便进行比较谁在前谁在后
        int tIndex = (*it).row * cols + (*it).col;
        int bIndex = (*ib).row * cols + (*ib).col;

        if (tIndex < bIndex)
        {//b的元素在后
            c.terms.insert(terms.begin() + cSize, *it);
            cSize++;
            it++;
        }
        else {
            if (tIndex == bIndex)
            {//*this和b的元素在同一位置

                //当且仅当两者相加不为0时才加入c
                if ((*it).value + (*ib).value != 0)
                {
                    matrixTerm<T> mTerm;
                    mTerm.row = (*it).row;
                    mTerm.col = (*it).col;
                    mTerm.value = (*it).value + (*ib).value;
                    c.terms.insert(terms.begin() + cSize, mTerm);
                    cSize++;
                }

                it++;
                ib++;
            }
            else
            {//a在后
                c.terms.insert(terms.begin() + cSize, *ib);
                cSize++;
                ib++;
            }
        }
    }
    //复制剩余项
    for (; it != itEnd; it++)
    {
        c.terms.insert(terms.begin() + cSize, *it);
        cSize++;
    }

    for (; ib != ibEnd; ib++)
    {
        c.terms.insert(terms.begin() + cSize, *ib);
        cSize++;
    }
}

#endif
