/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			���Ա�����
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
    virtual bool empty() const = 0;//����true ���ҽ������Ա�Ϊ��
    virtual int size() const = 0;//�������Ա��Ԫ�ظ���
    virtual T& get(int theIndex) const = 0;//��������ΪtheIndex��Ԫ��
    virtual int indexOf(const T& theElement) const = 0;//����Ԫ��theElement��һ�γ���ʱ������
    virtual void erase(int theIndex) = 0;//ɾ������ΪtheIndex��Ԫ��
    virtual void insert(int theIndex, const T& theElement) = 0;//��Ԫ��theElement�������Ա�������ΪtheIndex��λ����
    virtual void output(ostream& out) const = 0;//�����Ա����������out
};
#endif

