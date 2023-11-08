/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			������ջ
*/
#pragma once
#ifndef _STACK_H_
#define _STACK_H_
/*������ջ*/
template<class T>
class stack
{
public:
    virtual ~stack() {}
    //����true�����ҽ���ջΪ��
    virtual bool empty() const = 0;
    //����ջ��Ԫ�ظ���
    virtual int size() const = 0;
    //����ջ��Ԫ�ص�����
    virtual T& top() = 0;
    //ɾ��ջ��Ԫ��
    virtual T pop() = 0;
    //��Ԫ��theElementѹ��ջ��
    virtual void push(const T& theELment) = 0;
};
#endif
