/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			一些排序方法
* ****** 按名次排序
* ****** 选择排序
* ****** 冒泡排序
* ****** 插入排序
* ****** 快速排序
* ******
* ******
*/
#pragma once
#ifndef _SORT_H
#define _SORT_H
#include<iostream>
using std::cout;
using std::endl;
//测试函数
void sortingTest();
/*
功能：遍历显示数组
参数列表：
	a[]---需要显示的列表
	n---a[]元素个数
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
功能：计算名次,时间复杂度为(n-1)n/2
参数列表：
	a[]---表示需要计算名次的列表
	n---表示需要计算名次列表的元素个数
	r[]---记录名次的列表
*/
template<class T>
void rank(T a[], int n, int r[])
{
    //初始化名次r[]
    for (int i = 0; i < n; i++)
        r[i] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] <= a[i]) r[i]++;//与左边的数相比
            else r[j]++;//与右边的数相比
}

/*
功能：按名次排序(前提是知道名次)，时间复杂度为2n
参数列表：
	a[]---表示需要按名次排序的列表
	n---表示需要按名次排序列表的元素个数
	r[]---需要按名次排序的列表的元素名次数组
*/
template<class T>
void rearrange(T a[], int n, int r[])
{
    //需要借助一个u
    T* u = new T[n];
    //首先将排完序的数据放到u中
    for (int i = 0; i < n; i++)
        u[r[i]] = a[i];
    //然后将排完序的数据放到a中
    for (int i = 0; i < n; i++)
        a[i] = u[i];
}

/*
功能：交换两元素的数据
参数列表：
	a---元素a
	b---元素b
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
功能：原地重排(也是按名次排序)，交换次数为2(n-1),节省了内存空间
参数列表：
	a[]---表示需要原地重排的列表
	n---表示需要原地重排列表的元素个数
	r[]---记录名次的列表
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
功能：返回数组中最大元素的地址
参数列表：
	a[]---列表
	n---列表元素个数
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
功能：选择排序，使用了indexofMax()函数
参数列表：
	a[]---列表
	n---列表元素个数
*/
template<class T>
void selectionSort(T a[], int n)
{
    for (int i = n; i > 1; i--)
        swap<T>(a[i - 1], a[indexofMax<T>(a, i)]);
}

/*
功能：及时终止的选择排序
参数列表：
	a[]---列表
	n---列表元素个数
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
                indexofmax = j;//indexofmax一直变，就不会有is_sorted变为false,这样就是排序好啦
            else
                is_sorted = false;
        }
        swap(a[indexofmax], a[i-1]);
    }
}

/*
功能：及时终止的冒泡排序,时间复杂度为n(n-1)/2
参数列表：
	a[]---列表
	n---列表元素个数
*/
template<class T>
void bubbleSort(T a[], int n)
{
    bool is_sorted = true;
    for (int i = n; is_sorted && i > 1; i--)  //如果is_sorted一直没变，说明列表已经是排好序的，循环结束
    {
        is_sorted = false;//先设置为未交换，如果交换了就会被设置为交换。
        for (int j = 0; j < i - 1; j++)
            if (a[j] > a[j + 1])
            {
                swap<T>(a[j], a[j + 1]);
                is_sorted = true;
            }
    }
}

/*
功能：插入排序
参数列表：
	a[]---列表
	n---列表元素个数
*/
template<class T>
void insertionSort(T a[], int n)
{
    //对于存储在0处的数据不动
    for (int i = 1; i < n; i++)
    {
        T temp = a[i];//先存住要移动的数据
        int j = 0;//这里声明是因为for循环之后还要用
        //这里就是说将当前元素a[i]插入列表中，如果它前面的数据大于它，就将它前面的数据后移一位，给它腾位置
        for (j = i - 1; j >= 0 && temp < a[j]; j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = temp;
    }
}
//希尔排序
//最坏情况复杂度:O(N^2)
//不稳定排序
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
功能：快速排序
参数列表：
	a[]---列表
	left---列表开始位置
	right---列表结束位置
*/
//如果基准是第一个元素的话，逆序会得到最坏时间复杂度；
//如果基准是最后一个元素的话，顺序会得到最坏时间复杂度；
template<class T>
void quickSort(T a[], int left, int right)
{
    //这是一个递归，递归的终止条件
    //使用了左闭右开区间
    if (left >= right)
        return;
    //选择基准为中间那个值
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
    //现在l > r
    quickSort(a, left, r);
    quickSort(a, l, right);
}


#endif