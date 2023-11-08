/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			�ۺϸ��ַǳ�Ա����
*/
#pragma once
#ifndef _MYFUNCTIONS_H_
#define _MYFUNCTIONS_H_
#include<iostream>
#include "_1myExceptions.h"
#include<cmath>
#include <exception>
using std::min;
using std::endl;
using std::cout;
using std::bad_alloc;
/*����������*/
template<class V>
void Swap(V& a, V& b)
{
	V temp = a;
	a = b;
	b = temp;
}
/*
���ã�������ĳ��ȼӱ�
���룺ָ��aָ����Ҫ�ı䳤�ȵ����飬oldLength��ʾ����ԭ���ĳ��ȣ�newLength��ʾ��Ҫ�ı���³���
���������������/���� ΪnewLength
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
/*����һά����*/
template<class T>
void traverse1dArray(T* x, int length)
{
	for (int i = 0; i < length; i++)
		cout << x[i] << " ";
	cout << endl;
}
/*������ά����*/
template <class T>
bool make2dArray(T**& x, int numberOfRows, int numberOfColumns)
{
	try {
		//��ָ��
		x = new T * [numberOfRows];
		//Ϊÿһ�з����ڴ�
		for (int i = 0; i < numberOfRows; i++)
			x[i] = new int[numberOfColumns];
		return true;
	}
	catch (bad_alloc) { return false; }
}

/*������ά����*/
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
/*myFunctions�Ĳ��Ժ���*/
void myFunctionsTest();
/*��ŵ���ĵݹ�������*/
void towersOfHanoiRecursion(int n, int x, int y, int z);
#endif