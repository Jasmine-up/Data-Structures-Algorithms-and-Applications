/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			�������Ա���������Ա�����ͷ�ļ�
*/
#pragma once
#ifndef _ARRAYANDCHAIN_H_
#define _ARRAYANDCHAIN_H_
#include "_6chain.h"
#include "_5arrayList.h"
/*������ϰ��11��������ת��Ϊ������������*/
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

/*������ϰ��12��������ת��Ϊ���飬����ֵΪ���顣*/
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