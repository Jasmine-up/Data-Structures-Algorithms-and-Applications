/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			线性表虚类
*/
#pragma once
#ifndef __LINEARLIST_H_
#define __LINEARLIST_H_
#include<iostream>
using std::ostream;

template <class T>
class linearList
{
public:
    virtual ~linearList() {};
    virtual bool empty() const = 0;//返回true 当且仅当线性表为空
    virtual int size() const = 0;//返回线性表的元素个数
    virtual T& get(int theIndex) const = 0;//返回索引为theIndex的元素
    virtual int indexOf(const T& theElement) const = 0;//返回元素theElement第一次出现时的索引
    virtual void erase(int theIndex) = 0;//删除索引为theIndex的元素
    virtual void insert(int theIndex, const T& theElement) = 0;//把元素theElement插入线性表中索引为theIndex的位置上
    virtual void output(ostream& out) const = 0;//把线性表插入输入流out
};
#endif

