/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����洢�Ķ��е�ͷ�ļ�
*/
#pragma once
#ifndef _ARRAYQUEUE_H_
#define _ARRAYQUEUE_H_
#include<sstream>
#include<iostream>
#include "_1myExceptions.h"
#include "_17queue.h"
#include <cmath>
/*���Ժ���*/
void arrayQueueTest();

using namespace std;
template<class T>
class arrayQueue : public queue<T>
{
public:
    /*��Ա����*/
    arrayQueue(int initialCapacity = 10);
    ~arrayQueue() { delete[] queue; }
    bool empty() const { return theFront == theBack; }
    int size() const //���ض��е�Ԫ�ظ���
    {
        return (queueLength - theFront + theBack) % queueLength;
    }
    void clear() { theFront = theBack = 0; }/*��ն����е�Ԫ��*/
    int capacity() const { return queueLength-1; }
    //���ص�һ��Ԫ��
    T& front()
    {
        if (theFront == theBack)
            throw queueEmpty();
        return queue[(theFront + 1) % queueLength];
    }
    //�������һ��Ԫ��
    T& back()
    {
        if (theFront == theBack)
            throw queueEmpty();
        return queue[theBack];
    }
    //ɾ������Ԫ��
    void pop()
    {
        if (theFront == theBack)
            throw queueEmpty();
        theFront = (theFront + 1) % queueLength;
        queue[theFront].~T();
    }
    //���β����Ԫ��theElement
    void push(const T& theElement);
    /*��������������С*/
    void resizeQueue(int newLength);
    void meld(arrayQueue<T>& a, arrayQueue<T>& b);//�ϲ�����a,b����ǰ����
    void split(arrayQueue<T>& a, arrayQueue<T>& b);//����ǰ���зֳ���������a,b

    /*���ز�����*/
    /*����[]������*/
    T operator[](int i)
    { return queue[(theFront + i + 1) % queueLength]; }

    istream& input(istream& in);
    void output(ostream& out) const;
//    /*��Ԫ����*/
//    friend istream& operator>> <T>(istream& in, arrayQueue<T>& m);
//    //������ǲ�pop()Ԫ��
//    friend ostream& operator<< <T>(ostream& out, arrayQueue<T>& m);
private:
    int theFront;       // ��һ��Ԫ�ص�ǰһ��λ��
    int theBack;        // ���һ��Ԫ�ص�λ��
    int queueLength;    // ���е�������ʵ���ϱȶ�������(������queueFrontָ�����һ��λ��)��1
    T* queue;           // ָ������׵�ַ��ָ��
};
/*��Ԫ����*/
/*>>������*/
template<class T>
istream& arrayQueue<T>::input(istream& in)
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

template<class T>
istream& operator>>(istream& in, arrayQueue<T>& m){
    m.input(in);
    return in;
}

/*<<������*/
template<class T>
void arrayQueue<T>::output(ostream& out) const
{
    int length = size();
    for (int i = 0; i < length; i++)
        out << queue[(theFront + i + 1) % queueLength] << "  ";
    out << endl;
}
template<class T>
ostream& operator<<(ostream& out, const arrayQueue<T>& x)
{
    x.output(out);
    return out;
}
/*��Ա����*/
/*���캯��*/
template<class T>
arrayQueue<T>::arrayQueue(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s("");
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    queue = new T[initialCapacity+1];
    queueLength = initialCapacity+1;
    theFront = theBack = 0;
}

/*���β����Ԫ��theElement*/
template<class T>
void arrayQueue<T>::push(const T& theElement)
{
    //���ȼ������Ƿ����������������򽫶��������ӱ�
    if ((theBack + 1) % queueLength == theFront)
        resizeQueue(2 * (queueLength-1));
    theBack = (theBack + 1) % queueLength;
    queue[theBack] = theElement;
}
/*��������������С*/
template<class T>
void arrayQueue<T>::resizeQueue(int newLength)
{
    T* temp = new T[newLength + 1];
    int size = min((*this).size(), newLength);
    for (int i = 0; i < size; i++)
        temp[i] = queue[(theFront + i + 1) % queueLength];
    queueLength = newLength+1;
    theFront = newLength;
    theBack = size - 1;
    delete[] queue;
    queue = temp;
}

/*
����һ���µĶ��У��ñ������a��b�е�����Ԫ�أ�����a��b��Ԫ���������֣����е���
Ԫ��Ϊa�еĵ�һ��Ԫ�ء�����������Ԫ��ʱ�����ĳ�����е�Ԫ�������ˣ������һ�����е���
��Ԫ������������¶��еĺ󲿡�����ĸ�����Ӧ������������еĳ��ȳ����Ա�����ϵ��
�鲢������Զ����ǵ��ö���*this
*/
template <class T>
void arrayQueue<T>::meld(arrayQueue<T>& a, arrayQueue<T>& b)
{
    (*this).clear();
    int i = 0;
    while (i < a.size() && i < b.size())
    {
        push(a[i]);
        push(b[i]);
        i++;
    }
    while (i < a.size())
    {
        push(a[i]);
        i++;
    }
    while (i < b.size())
    {
        push(b[i]);
        i++;
    }
}

/*�����������Զ���a��b��a����*this������Ϊ������Ԫ�أ�b���������Ԫ��*/
template<class T>
void arrayQueue<T>::split(arrayQueue<T>& a, arrayQueue<T>& b)
{
    a.clear();
    b.clear();
    int size = (*this).size();
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            a.push(queue[(theFront + i + 1) % queueLength]);
        else
            b.push(queue[(theFront + i + 1) % queueLength]);
    }
}
#endif
