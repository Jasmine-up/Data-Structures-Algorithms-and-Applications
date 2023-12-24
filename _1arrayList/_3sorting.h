/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			һЩ���򷽷�
* ****** ����������
* ****** ѡ������
* ****** ð������
* ****** ��������
* ****** ��������
* ******
* ******
*/
#pragma once
#ifndef _SORT_H
#define _SORT_H
#include<iostream>
using std::cout;
using std::endl;
//���Ժ���
void sortingTest();
/*
���ܣ�������ʾ����
�����б�
	a[]---��Ҫ��ʾ���б�
	n---a[]Ԫ�ظ���
*/
template<class T>
void traverse(T a[],int n)
{
    cout << "[ ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "]";
}

/*
���ܣ���������,ʱ�临�Ӷ�Ϊ(n-1)n/2
�����б�
	a[]---��ʾ��Ҫ�������ε��б�
	n---��ʾ��Ҫ���������б��Ԫ�ظ���
	r[]---��¼���ε��б�
*/
template<class T>
void rank(T a[], int n, int r[])
{
    //��ʼ������r[]
    for (int i = 0; i < n; i++)
        r[i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] <= a[i]) r[i]++;//����ߵ������
            else r[j]++;//���ұߵ������
}

/*
���ܣ�����������(ǰ����֪������)��ʱ�临�Ӷ�Ϊ2n
�����б�
	a[]---��ʾ��Ҫ������������б�
	n---��ʾ��Ҫ�����������б��Ԫ�ظ���
	r[]---��Ҫ������������б��Ԫ����������
*/
template<class T>
void rearrange(T a[], int n, int r[])
{
    //��Ҫ����һ��u
    T* u = new T[n];
    //���Ƚ�����������ݷŵ�u��
    for (int i = 0; i < n; i++)
        u[r[i]] = a[i];
    //Ȼ������������ݷŵ�a��
    for (int i = 0; i < n; i++)
        a[i] = u[i];
}

/*
���ܣ�������Ԫ�ص�����
�����б�
	a---Ԫ��a
	b---Ԫ��b
*/
template<class T>
void swap(T& a, T& b)
{
    T temp;
    temp = a;
    a = b;
    b = temp;
}
/*
���ܣ�ԭ������(Ҳ�ǰ���������)����������Ϊ2(n-1),��ʡ���ڴ�ռ�
�����б�
	a[]---��ʾ��Ҫԭ�����ŵ��б�
	n---��ʾ��Ҫԭ�������б��Ԫ�ظ���
	r[]---��¼���ε��б�
*/
template<class T>
void situ_rearrange(T a[], int n, int r[])
{
    for (int i = 0; i < n; i++)
    {
        if (i != r[i])
        {
            swap(a[i], a[r[i]]);
            swap(r[i], r[r[i]]);
        }
    }
}

/*
���ܣ��������������Ԫ�صĵ�ַ
�����б�
	a[]---�б�
	n---�б�Ԫ�ظ���
*/
template<class T>
int indexofMax(T a[], int n)
{
    int indexofmax = 0;
    for (int i = 0; i < n; i++)
        if (a[indexofmax] < a[i])
            indexofmax = i;
    return indexofmax;
}

/*
���ܣ�ѡ������ʹ����indexofMax()����
�����б�
	a[]---�б�
	n---�б�Ԫ�ظ���
*/
template<class T>
void selectionSort(T a[], int n)
{
    for (int i = n; i > 1; i--)
        swap<T>(a[i - 1], a[indexofMax<T>(a, i)]);
}

/*
���ܣ���ʱ��ֹ��ѡ������
�����б�
	a[]---�б�
	n---�б�Ԫ�ظ���
*/
template<class T>
void Timely_Terminated_selectionSort(T a[], int n)
{
    bool is_sorted = false;
    for (int i = n; (i > 1) && (!is_sorted); i--)
    {
        int indexofmax = 0;
        is_sorted = true;
        for (int j = 0; j < i; j++)
        {
            if (a[indexofmax] < a[j])
                indexofmax = j;//indexofmaxһֱ�䣬�Ͳ�����is_sorted��Ϊfalse,���������������
            else
                is_sorted = false;
        }
        swap(a[indexofmax], a[i-1]);
    }
}

/*
���ܣ���ʱ��ֹ��ð������,ʱ�临�Ӷ�Ϊn(n-1)/2
�����б�
	a[]---�б�
	n---�б�Ԫ�ظ���
*/
template<class T>
void bubbleSort(T a[], int n)
{
    bool is_sorted = true;
    for (int i = n; is_sorted && i > 1; i--)  //���is_sortedһֱû�䣬˵���б��Ѿ����ź���ģ�ѭ������
    {
        is_sorted = false;//������Ϊδ��������������˾ͻᱻ����Ϊ������
        for (int j = 0; j < i - 1; j++)
            if (a[j] > a[j + 1])
            {
                swap<T>(a[j], a[j + 1]);
                is_sorted = true;
            }
    }
}

/*
���ܣ���������
�����б�
	a[]---�б�
	n---�б�Ԫ�ظ���
*/
template<class T>
void insertionSort(T a[], int n)
{
    //���ڴ洢��0�������ݲ���
    for (int i = 1; i < n; i++)
    {
        T temp = a[i];//�ȴ�סҪ�ƶ�������
        int j = 0;//������������Ϊforѭ��֮��Ҫ��
        //�������˵����ǰԪ��a[i]�����б��У������ǰ������ݴ��������ͽ���ǰ������ݺ���һλ��������λ��
        for (j = i - 1; j >= 0 && temp < a[j]; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
}
//ϣ������
//�������Ӷ�:O(N^2)
//���ȶ�����
template<class T>
void shellsort(T a[], int n)
{
    int h = n / 2;
    while (h >= 1) {
        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h) {
                std::swap(a[j], a[j - h]);
            }
        }
        h = h / 2;
    }
}

/*
���ܣ���������
�����б�
	a[]---�б�
	left---�б�ʼλ��
	right---�б����λ��
*/
//�����׼�ǵ�һ��Ԫ�صĻ��������õ��ʱ�临�Ӷȣ�
//�����׼�����һ��Ԫ�صĻ���˳���õ��ʱ�临�Ӷȣ�
template<class T>
void quickSort(T a[], int left, int right)
{
    //����һ���ݹ飬�ݹ����ֹ����
    //ʹ��������ҿ�����
    if (left >= right)
        return;
    //ѡ���׼Ϊ�м��Ǹ�ֵ
    T bench = a[left];
    int l = left;
    int r = right;
    while (l < r)
    {
        while (l <= r && a[r] > bench) r--;
        while (l <= r && a[l] < bench) l++;
        if (l <= r)
            swap<T>(a[l++], a[r--]);
    }
    //����l > r
    quickSort(a, left, r);
    quickSort(a, l, right);
}


#endif