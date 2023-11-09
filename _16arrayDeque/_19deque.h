/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			�����˫�˶��еĳ������ͷ�ļ�
*/
#pragma once
#ifndef _DEQUE_H_
#define _DEQUE_H_
template<class T>
class deque
{
public:
    virtual ~deque() {}
    virtual bool empty() const = 0;//����true,���ҽ�������Ϊ��
    virtual int size() const = 0;//���ض�����Ԫ�ظ���
    virtual T& front() = 0;//����ͷԪ�ص�����
    virtual T& back() = 0;//����βԪ�ص�����
    virtual void pop_front() = 0;//ɾ����Ԫ��
    virtual void pop_back() = 0;//ɾ��βԪ��
    virtual void push_front(const T& theElement) = 0;//��Ԫ��theELment�������
    virtual void push_back(const T& theElement) = 0;//��Ԫ��theELment�����β
};
#endif
