/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����洢�Ķ�ά������ͷ�ļ�
*/
#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_
#include "_1myExceptions.h"
#include<iostream>
#include <algorithm>
using namespace std;
//����Ĳ���cpp�ļ�
void matrixTest();
/*���������ľ���*/
template<class T>
class matrix
{
public:
    int rows() const { return theRows; }
    int columns() const { return theColumns; }
    matrix(int theRows, int theColumns);//�Ѳ�
    matrix(const matrix<T>& m);//�Ѳ�
    matrix<T>& operator=(const matrix<T>& m);//�Ѳ�
    T& operator()(int i, int j) const;//�Ѳ�
    matrix<T> operator+() const;//�Ѳ�
    matrix<T> operator+(const matrix<T>& m) const;//�Ѳ�
    matrix<T> operator+(const T& data) const;//�Ѳ�
    matrix<T>& operator+=(const matrix<T>& m);//�Ѳ�
    matrix<T>& operator+=(const T& data);//�Ѳ�
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
    //<<��>>û�м�<T>֮ǰһֱ����LNK1120��LNK2019,����֮��Ͳ������ˣ���Ҳ��֪��Ϊʲô
    //Ӧ����һ��ʵ������
    istream& input(istream& in);
    void output(ostream& out) const;
private:
    int theRows;//���������
    int theColumns;//���������
    T* element;//����element
};
/*��Ԫ����:�������������*/
/*����Ԫ�����*/
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
/*input����*/
template<class T>
istream& matrix<T>::input(istream& in){
    cout << "���������" << theRows << "*" << theColumns << ":" << endl;
    for (int i = 0; i < (theRows) * (theColumns); i++)
    {
        cout << "Please enter a data: ";
        while (!(in >> element[i])) {//����������Ͳ�ƥ�䣬��ִ��ѭ����
            in.clear(); // reset input���ñ�־λΪ��Ч
            while (in.get() != '\n') //ɾ��û���õ�����
                continue; // get rid of bad input
            cout << "Please enter a data: ";
        }
    }
    return in;
}

/*����<<������*/
template<class T>
ostream& operator<<(ostream& out, const matrix<T>& x)
{
    x.output(out);
    return out;
}
/*����>>������*/
template<typename T>
std::istream& operator>>(std::istream &os, matrix<T>& m)
{
    m.input(os);
    return os;
}

/*���캯��*/
template<class T>
matrix<T>::matrix(int theRows, int theColumns)
{
    //������������������Ч��
    if (theRows < 0 || theColumns < 0)
        throw illegalParameterValue("Rows and columns mush be >=0");
    if((theRows==0||theColumns==0)&&(theRows!=0||theColumns!=0)) //ҪΪ0ʱ��������������ͬʱΪ0
        throw illegalParameterValue("Either both or neither rows and columns should be zero");
    //��������
    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T[theRows * theColumns];
}
/*���ƹ��캯��*/
template<class T>
matrix<T>::matrix(const matrix<T>& m)
{
    //��������
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T[theRows * theColumns];

    //����m��ÿһ��Ԫ��
    copy(m.element, m.element + theRows * theColumns, element);
}
/*����ת��*/
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

/*���ز�����*/
/*��ֵ������=������*/
template<class T>
matrix<T>& matrix<T>::operator=(const matrix<T>& m)
{
    if (this != &m)//�����Լ������Լ�
    {
        delete[] element;
        theRows = m.theRows;
        theColumns = m.theColumns;
        element = new T[theRows * theColumns];
        //����m��ÿһ��Ԫ��
        copy(m.element, m.element + theRows * theColumns, element);
    }
    return *this;
}
/*����()������*/
template<class T>
T& matrix<T>::operator()(int i, int j) const
{
    if (i<1 || j<1 || i>theRows || j>theColumns)
        throw matrixIndexOutOfBounds();
    return element[(i - 1) * theColumns + j - 1];
}
/*����һԪ+������*/
template<class T>
matrix<T> matrix<T>::operator+() const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i];
    return w;
}
/*���ض�Ԫ+������*/
template<class T>
matrix<T> matrix<T>::operator+(const matrix<T>& m) const
{
    if (theRows != m.theRows || theColumns != m.theColumns)
        throw matrixSizeMismatch();
    //���ɽ������
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] + m.element[i];
    return w;
}
/*����+���������þ�������Ԫ�ض���һ������*/
template<class T>
matrix<T> matrix<T>::operator+(const T& data) const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] + data;
    return w;
}
/*����+=������*/
/*��ǰ�����һ������*/
template<class T>
matrix<T>& matrix<T>::operator+=(const matrix<T>& m)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] = element[i] + m.element[i];
    return *this;
}
/*����+=������*/
/*��ǰ����ÿ��Ԫ�ؼ�һ����*/
template<class T>
matrix<T>& matrix<T>::operator+=(const T& data)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] = element[i] + data;
    return *this;
}
/*����һԪ-������*/
template<class T>
matrix<T> matrix<T>::operator-() const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = -element[i];
    return w;
}
/*���ض�Ԫ-�����������������*/
template<class T>
matrix<T> matrix<T>::operator-(const matrix<T>& m) const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] - m.element[i];
    return w;
}
/*���ض�Ԫ-�����������������*/
template<class T>
matrix<T> matrix<T>::operator-(const T& data) const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] - data;
    return w;
}
/*����-=�������������һ������*/
template<class T>
matrix<T>& matrix<T>::operator-=(const matrix<T>& m)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] = element[i] - m.element[i];
    return *this;
}
/*����-=�������������ÿ��Ԫ�ؼ���data*/
template<class T>
matrix<T>& matrix<T>::operator-=(const T& data)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] = element[i] - data;
    return *this;
}
/*����*������*/
template<class T>
matrix<T> matrix<T>::operator*(const matrix<T>& m) const
{
    if (theColumns != m.theRows)
        throw matrixSizeMismatch();
    matrix<T> w(theRows, m.theColumns);//�������
    int indext = 0, indexm = 0, indexw = 0;//����������α�
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
            //���е�������һ�д��¿�ʼ
            indext -= (theColumns - 1);
            indexm = j;
        }
        //����һ�к���һ�����¿�ʼ
        indext += theColumns;
        indexm = 0;
    }
    return w;
}
/*����*�������������������data*/
template<class T>
matrix<T> matrix<T>::operator*(const T& data) const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] * data;
    return w;
}
/*����*=��������������Ծ���,����Ū��û��Ҫ*/
/*����*=�������������������data*/
template<class T>
matrix<T>& matrix<T>::operator*=(const T& data)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] = element[i] * data;
    return *this;
}
/*����/������*/
template<class T>
matrix<T> matrix<T>::operator/(const T& data) const
{
    matrix<T> w(theRows, theColumns);
    for (int i = 0; i < theRows * theColumns; i++)
        w.element[i] = element[i] / data;
    return w;
}
/*����/=������*/
template<class T>
matrix<T>& matrix<T>::operator/=(const T& data)
{
    for (int i = 0; i < theRows * theColumns; i++)
        element[i] = element[i] / data;
    return *this;
}

#endif
