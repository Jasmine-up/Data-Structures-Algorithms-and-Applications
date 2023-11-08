/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����洢��ջ���ͷ�ļ�
*/
#pragma once
#ifndef _ARRAYSTACK_H_
#define _ARRAYSTACK_H_
#include "_1myExceptions.h"
#include "_14stack.h"
#include<iostream>
#include<sstream>
#include<cstring>
using std::ostringstream;
using std::endl;
using std::cout;
using std::istream;
using std::ostream;
using std::string;
//���Ժ���
void arrayStackTest();
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

/*��������ֱ������arrayList��ʵ�֣����Ǹ÷�������ʧ���ܡ�*/
/*��˱��ڿ���һ���࣬�����������������е�ջԪ��*/
template<class T>
class arrayStack :public stack<T>
{
public:
    arrayStack(int initialCapacity = 10);
    ~arrayStack() { delete[] stack; }
    bool empty() const { return stackTop == -1; }
    int size() const { return stackTop + 1; }
    int capacity() const { return stackLength; }
    T& top()
    {
        if (stackTop == -1)
            throw stackEmpty();
        return stack[stackTop];
    }
    T pop()
    {
        if (stackTop == -1)
            throw stackEmpty();
        T temp = stack[stackTop];
        stack[stackTop--].~T();//T����������
        while (stackTop + 1 < stackLength / 4)
        {
            changeLength(stack, stackLength, stackLength / 2);
            stackLength /= 2;
        }
        return temp;
    }
    void push(const T& theElement);
    void clear() { stackTop = -1; }
    void split(arrayStack<T>& a, arrayStack<T>& b);
    void merge(arrayStack<T>& a);

    /*���ز�����*/
    /*���ز�����[]*/
    T& operator[](int i) { return stack[i]; }

    istream& input(istream& in);
    void output(ostream& out) const;
private:
    int stackTop;//��ǰջ��
    int stackLength;//ջ����
    T* stack;//Ԫ������
};
/*��Ԫ����*/
/*>>������*/
template<class T>
istream& arrayStack<T>::input(istream& in)
{
    int numberOfElement = 0;
    cout << "Please enter the number of element:";
    while (!(in >> numberOfElement))
    {
        in.clear();//��ձ�־λ
        while (in.get() != '\n')//ɾ����Ч������
            continue;
        cout << "Please enter the number of element:";
    }
    T cinElement;
    for (int i = 0; i < numberOfElement; i++)
    {
        cout << "Please enter the element " << i + 1 << ":";
        while (!(in >> cinElement))
        {
            in.clear();//��ձ�־λ
            while (in.get() != '\n')//ɾ����Ч������
                continue;
            cout << "Please enter the element " << i + 1 << ":";
        }
        push(cinElement);
    }
    return in;
}
/*<<������*/
template<class T>
void arrayStack<T>::output(ostream& out) const
{
    for (int i = 0; i <= stackTop; i++)
        out << stack[i] << "  ";
    out << endl;
}

/*����<<������*/
template<class T>
ostream& operator<<(ostream& out, const arrayStack<T>& x)
{
    x.output(out);
    return out;
}
/*����>>������*/
template<typename T>
std::istream& operator>>(std::istream &os, arrayStack<T>& m)
{
    m.input(os);
    return os;
}

/*���캯��*/
template<class T>
arrayStack<T>::arrayStack(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s("");
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    stackLength = initialCapacity;
    stack = new T[initialCapacity];
    stackTop = -1;
}

/*��Ԫ��theElementѹ��ջ*/
template<class T>
void arrayStack<T>::push(const T& theElement)
{
    if (stackTop == stackLength - 1)
    {
        //�ռ������������ӱ�
        changeLength(stack, stackLength, 2 * stackLength);
        stackLength *= 2;
    }
    stack[++stackTop] = theElement;
}
/*��һ��ջ����Ϊ����ջ����һ��ջ������ջ�׿�ʼ��һ��Ԫ�أ��ڶ���ջ����ʣ��Ԫ��*/
template<class T>
void arrayStack<T>::split(arrayStack<T>& a, arrayStack<T>& b)
{
    //�������a,bջ
    b.clear();
    a.clear();
    /*����ǰջ�е�ǰһ��Ԫ�ش���aջ��*/
    int i = 0;
    for (i = 0; i <= stackTop / 2; i++)
        a.push(stack[i]);
    /*����ǰջ�еĺ�һ��Ԫ�ش���bջ��*/
    for (; i <= stackTop; i++)
        b.push(stack[i]);
}
/*������ջ�ϲ����ѵڶ���ջ������Ԫ�����ڵ�һ��ջ�Ķ��������ı�ڶ���ջ��Ԫ�ص����˳��*/
template<class T>
void arrayStack<T>::merge(arrayStack<T>& a)
{
    for (int i = 0; i <= a.stackTop; i++)
        push(a.stack[i]);
}
#endif
