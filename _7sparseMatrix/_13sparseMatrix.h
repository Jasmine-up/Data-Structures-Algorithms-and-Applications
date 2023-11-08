/*
Project name :			allAlgorithmsTest
Last modified Date:		2023��9��19��21��59��
Last Version:			V1.0
Descriptions:			�������Ա�洢��ϡ�������ͷ�ļ�
*/
#pragma once
//ϡ��������
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
void sparseMatrixTest();//���Ժ���
/*����������ϡ�����*/
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
/*input����*/
template<class T>
istream& sparseMatrix<T>::input(istream& in)
{
    // Input a sparse matrix.
    // input matrix characteristics
    int numberOfTerms;
    cout << "Enter number of rows, columns, and #terms" << endl;
    while (!(in >> rows >> cols >> numberOfTerms)) {//����������Ͳ�ƥ�䣬��ִ��ѭ����
        in.clear(); // reset input���ñ�־λΪ��Ч
        while (in.get() != '\n') //ɾ��û���õ�����
            continue; // get rid of bad input
        cout << "Enter number of rows, columns, and #terms" << endl;
    }
    //����x.terms�Ĵ�С��ȷ���㹻������
    terms.resize(numberOfTerms);
    int before_rows = 0, before_columns = 0;
    // input terms
    matrixTerm<T> mTerm;
    for (int i = 0; i < numberOfTerms; i++)
    {
        cout << "Enter row, column, and value of term " << (i + 1) << endl;
        while (!(in >> mTerm.row >> mTerm.col >> mTerm.value)) {//����������Ͳ�ƥ�䣬��ִ��ѭ����
            in.clear(); // reset input���ñ�־λΪ��Ч
            while (in.get() != '\n') //ɾ��û���õ�����
                continue; // get rid of bad input
            cout << "Enter row, column, and value of term " << (i + 1) << endl;
        }
        // ��ǰԪ�ص�λ�ñ�֮ǰԪ�ص�λ��ҪС
        // �������� > ��������
        while (before_rows * cols + before_columns > mTerm.row * rows + mTerm.col)
        {
            cout << "Please enter in row master mapping order:" << endl;
            cout << "Enter row, column, and value of term " << (i + 1) << endl;
            while (!(in >> mTerm.row >> mTerm.col >> mTerm.value)) {//����������Ͳ�ƥ�䣬��ִ��ѭ����
                in.clear(); // reset input���ñ�־λΪ��Ч
                while (in.get() != '\n') //ɾ��û���õ�����
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

/*����<<������*/
template<class T>
ostream& operator<<(ostream& out, const sparseMatrix<T>& x)
{
    x.output(out);
    return out;
}
/*����>>������*/
template<typename T>
std::istream& operator>>(std::istream &os, sparseMatrix<T>& m)
{
    m.input(os);
    return os;
}
/*ת��:b����洢*thisת�õĽ��*/
/*���ȼ���*thisÿһ���ж��ٸ�����Ԫ�أ�Ȼ�����*thisÿһ���׸�Ԫ�ص�λ�ã������Ԫ�ص�����b*/
template<class T>
void sparseMatrix<T>::transpose(sparseMatrix<T>& b)
{
    //����b���г����г����Լ�����Ԫ�ص���Ŀ
    b.cols = rows;
    b.rows = cols;
    b.terms.resize(terms.size());

    //colSize[i]�Ǿ���*this�ڵ�i�еķ�0Ԫ�ظ���
    int* colSize = new int[cols + 1];
    //rowNext[i]��ת�þ���b��i���׸���0Ԫ����b�е�����
    int* rowNext = new int[cols + 1];
    //colSize[0]û��
    for (int i = 1; i <= cols; i++)
        colSize[i] = 0;//��ʼ������colSize[i]Ϊ0
    for (typename vector<matrixTerm<T> >::iterator i = terms.begin(); i != terms.end(); i++)
        colSize[(*i).col]++;//�������*this�ڵ�i�еķ�0Ԫ�ظ������洢��colSize��
    //rowNext[0]Ҳû��
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
        b.terms[j] = mTerm;// 2023��9��19��
    }
}
/*c = *this+b;ͨ����������ɨ��*this��b�ķ�0����ʵ�ֵ�*/
template<class T>
void sparseMatrix<T>::add(sparseMatrix<T>& b, sparseMatrix<T>& c)
{
    //������*this�;���b�Ĵ�С��ƥ��ʱ������ִ�мӲ���
    if (rows != b.rows || cols != b.cols)
        throw matrixSizeMismatch();

    //���þ���c�Ĳ���
    c.rows = rows;
    c.cols = cols;
    c.terms.clear();//��վ���c
    int cSize = 0;

    //Ϊ*this��b���������
    typename vector<matrixTerm<T> >::iterator it = terms.begin();
    typename vector<matrixTerm<T> >::iterator ib = b.terms.begin();
    typename vector<matrixTerm<T> >::iterator itEnd = terms.end();
    typename vector<matrixTerm<T> >::iterator ibEnd = b.terms.end();

    //����*this��b,����ص������
    while (it != itEnd && ib != ibEnd)
    {
        //��������������������бȽ�˭��ǰ˭�ں�
        int tIndex = (*it).row * cols + (*it).col;
        int bIndex = (*ib).row * cols + (*ib).col;

        if (tIndex < bIndex)
        {//b��Ԫ���ں�
            c.terms.insert(terms.begin() + cSize, *it);
            cSize++;
            it++;
        }
        else {
            if (tIndex == bIndex)
            {//*this��b��Ԫ����ͬһλ��

                //���ҽ���������Ӳ�Ϊ0ʱ�ż���c
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
            {//a�ں�
                c.terms.insert(terms.begin() + cSize, *ib);
                cSize++;
                ib++;
            }
        }
    }
    //����ʣ����
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
