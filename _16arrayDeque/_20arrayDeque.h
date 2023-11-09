/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����洢�������˫�˶������ͷ�ļ�
*/
#pragma once
#ifndef _ARRAYDEQUE_H_
#define _ARRAYDEQUE_H_
#include<sstream>
#include<iostream>
#include "_1myExceptions.h"
#include "_19deque.h"
/*���Ժ���*/
void arrayDequeTest();
template<class T>
class arrayDeque : public deque<T>
{
public:
    /*��Ա����*/
    /*���캯��*/
    arrayDeque(int initialCapacity = 10);
    /*��������*/
    ~arrayDeque() {
        delete[]  deque;
    }
    bool empty() const { return theFront == theBack; };//����true,���ҽ�������Ϊ��
    int size() const { return (dequeLength - theFront + theBack)%dequeLength; };//���ض�����Ԫ�ظ���
    int capacity() const {
        return dequeLength - 1;
    }
    void clear() { theFront = theBack = 0; }
    T& front();//����ͷԪ�ص�����
    T& back();//����βԪ�ص�����
    void pop_front();//ɾ����Ԫ��
    void pop_back();//ɾ��βԪ��
    void push_front(const T& theElement);//��Ԫ��theELment�������
    void push_back(const T& theElement);//��Ԫ��theELment�����β
    /*��������������С*/
    void resizeDeque(int newLength);
    void meld(arrayDeque<T>& a, arrayDeque<T>& b);
    void split(arrayDeque<T>& a, arrayDeque<T>& b);

    /*���ز�����*/
    /*����[]������*/
    T operator[](int i) { return deque[(theFront + i + 1) % dequeLength]; }

    istream& input(istream& in);
    void output(ostream& out) const;
//    /*��Ԫ����*/
//    friend istream& operator>> <T>(istream& in, arrayDeque<T>& m);
//    //������ǲ�pop()Ԫ��
//    friend ostream& operator<< <T>(ostream& out, arrayDeque<T>& m);
private:
    int theFront;       // ��һ��Ԫ�ص�ǰһ��λ��
    int theBack;        // ���һ��Ԫ�ص�λ��
    int dequeLength;    // ���е�������ʵ���ϱȶ�������(������queueFrontָ�����һ��λ��)��1
    T* deque;
};

/*��Ԫ����*/
/*>>������*/
template<class T>
istream& arrayDeque<T>::input(istream& in)
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
        push_back(cinElement);
    }
    return in;
}

template<class T>
istream& operator>>(istream& in, arrayDeque<T>& m){
    m.input(in);
    return in;
}

/*<<������*/
template<class T>
void arrayDeque<T>::output(ostream& out) const
{
    int length = size();
    for (int i = 0; i < length; i++)
        out << deque[(theFront + i + 1) % dequeLength] << "  ";
    out << endl;
}

template<class T>
ostream& operator<<(ostream& out, const arrayDeque<T>& x)
{
    x.output(out);
    return out;
}

/*���캯��*/
template<class T>
arrayDeque<T>::arrayDeque(int initialCapacity)
{
    if (initialCapacity < 1)
    {
        ostringstream s("");
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    deque = new T[initialCapacity + 1];
    dequeLength = initialCapacity + 1;
    theFront = theBack = 0;
}
/*����ͷԪ�ص�����*/
template<class T>
T& arrayDeque<T>::front()
{
    if(theFront == theBack)
        throw queueEmpty();
    return deque[(theFront + 1) % dequeLength];
}
/*����βԪ�ص�����*/
template<class T>
T& arrayDeque<T>::back()
{
    if (theFront == theBack)
        throw queueEmpty();
    return deque[theBack];
}
/*ɾ����Ԫ��*/
template<class T>
void arrayDeque<T>::pop_front()
{
    /*����Ƿ�Ϊ�գ�Ϊ�վ��׳��쳣*/
    if (theFront == theBack)
        throw queueEmpty();
    /*��Ϊ�վ�ɾ����Ԫ��*/
    theFront = (theFront + 1) % dequeLength;
    deque[theFront].~T();
}
/*ɾ��βԪ��*/
template<class T>
void arrayDeque<T>::pop_back()
{
    /*����Ƿ�Ϊ�գ�Ϊ�վ��׳��쳣*/
    if (theFront == theBack)
        throw queueEmpty();
    /*��Ϊ�վ�ɾ��βԪ��*/
    deque[theBack].~T();
    if (theBack == 0)
        theBack = dequeLength - 1;
    else
        theBack--;
}
/*��Ԫ��theELment�������*/
template<class T>
void arrayDeque<T>::push_front(const T& theElement)
{
    /*�ж϶����Ƿ����ˣ�������ˣ��͵�������Ϊԭ��������*/
    if ((theFront + 1) % dequeLength == theBack)
        resizeDeque(2 * (dequeLength-1));
    deque[theFront] = theElement;
    if (theFront == 0)
        theFront = dequeLength - 1;
    else
        theFront = theFront - 1;
}
/*��Ԫ��theELment�����β*/
template<class T>
void arrayDeque<T>::push_back(const T& theElement)
{
    /*�ж϶����Ƿ����ˣ�������ˣ��͵�������Ϊԭ��������*/
    if ((theBack + 1) % dequeLength == theFront)
        resizeDeque(2 * (dequeLength - 1));
    theBack = (theBack + 1) % dequeLength;
    deque[theBack] = theElement;
}

/*��������������С*/
template<class T>
void arrayDeque<T>::resizeDeque(int newLength)
{
    T* temp = new T[newLength + 1];
    int size = min((*this).size(), newLength);
    for (int i = 0; i < size; i++)
        temp[i] = deque[(theFront + i + 1) % dequeLength];
    dequeLength = newLength + 1;
    theFront = newLength;
    theBack = size - 1;
    delete[] deque;
    deque = temp;
}

/*
����һ���µĶ��У��ñ������a��b�е�����Ԫ�أ�����a��b��Ԫ���������֣����е���
Ԫ��Ϊa�еĵ�һ��Ԫ�ء�����������Ԫ��ʱ�����ĳ�����е�Ԫ�������ˣ������һ�����е���
��Ԫ������������¶��еĺ󲿡�����ĸ�����Ӧ������������еĳ��ȳ����Ա�����ϵ��
�鲢������Զ����ǵ��ö���*this
*/
template <class T>
void arrayDeque<T>::meld(arrayDeque<T>& a, arrayDeque<T>& b)
{
    (*this).clear();
    int i = 0;
    while (i < a.size() && i < b.size())
    {
        push_back(a[i]);
        push_back(b[i]);
        i++;
    }
    while (i < a.size())
    {
        push_back(a[i]);
        i++;
    }
    while (i < b.size())
    {
        push_back(b[i]);
        i++;
    }
}

/*�����������Զ���a��b��a����*this������Ϊ������Ԫ�أ�b���������Ԫ��*/
template<class T>
void arrayDeque<T>::split(arrayDeque<T>& a, arrayDeque<T>& b)
{
    a.clear();
    b.clear();
    int size = (*this).size();
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            a.push_back(deque[(theFront + i + 1) % dequeLength]);
        else
            b.push_back(deque[(theFront + i + 1) % dequeLength]);
    }
}

#endif
