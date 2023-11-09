/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			���еĳ�����
*/
#pragma once
#ifndef _QUEUE_H_
#define _QUEUE_H_
template<class T>
class queue
{
public:
    virtual ~queue() {}
    virtual bool empty() const = 0;//����true,���ҽ�������Ϊ��
    virtual int size() const = 0;//���ض�����Ԫ�ظ���
    virtual T& front() = 0;//����ͷԪ�ص�����
    virtual T& back() = 0;//����βԪ�ص�����
    virtual void pop() = 0;//ɾ����Ԫ��
    virtual void push(const T& theElement) = 0;//��Ԫ��theELment�����β
};
#endif
