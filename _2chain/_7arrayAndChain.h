/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			数组线性表和链表线性表交互的头文件
*/
#pragma once
#ifndef _ARRAYANDCHAIN_H_
#define _ARRAYANDCHAIN_H_
#include "_6chain.h"
#include "_5arrayList.h"
/*第六章习题11：将数组转换为链表，返回链表*/
template<class T>
chain<T> arrayToChain(const arrayList<T>& arrayTo)
{
	chain<T> toChain;
	int size = arrayTo.size();
	T data = 0;
	for (int i = 0; i < size; i++)
	{
		data = arrayTo.get(i);
		toChain.insert(i, data);
	}
	return toChain;
}

/*第六章习题12：将链表转换为数组，返回值为数组。*/
template<class T>
arrayList<T> chainToArray(const chain<T>& chainTo)
{
	arrayList<T> toArray;
	int size = chainTo.size();
	T data = 0;
	for (int i = 0; i < size; i++)
	{
		data = chainTo.get(i);
		toArray.insert(i, data);
	}
	return toArray;
}
#endif