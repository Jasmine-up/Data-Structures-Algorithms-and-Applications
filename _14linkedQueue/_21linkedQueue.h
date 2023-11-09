/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����洢�Ķ��е�ͷ�ļ�
*/
#pragma once
#ifndef _LINKEDQUEUE_H_
#define _LINKEDQUEUE_H_
#include<sstream>
#include<iostream>
#include "_1myExceptions.h"
#include "_6chainNode.h"
#include "_17queue.h"
/*���Ժ���*/
void linkedQueueTest();

using namespace std;
template<class T>
class linkedQueue : public queue<T>
{
public:
    /*��Ա����*/
    linkedQueue(int initialCapacity = 10)
    {
        theFront = theBack = nullptr;
        queueSize = 0;
    }
    ~linkedQueue();
    bool empty() const { return queueSize == 0; }
    //���ض��е�Ԫ�ظ���
    int size() const { return queueSize; }
    /*��ն����е�Ԫ��*/
    void clear();
    /*���ص�һ��Ԫ��*/
    T& front() { return theFront->element; }
    /*�������һ��Ԫ��*/
    T& back() { return theBack->element; }
    /*ɾ������Ԫ��*/
    void pop()
    {
        chainNode<T>* next = theFront->next;
        delete theFront;
        theFront = next;
        queueSize--;
    }
    /*���β����Ԫ��theElement*/
    void push(const T& theElement)
    {
        if (queueSize == 0)
            theFront = theBack = new chainNode<T>(theElement, nullptr);
        else
        {
            theBack->next = new chainNode<T>(theElement, nullptr);
            theBack = theBack->next;
        }
        queueSize++;
    }
    //void meld(arrayQueue<T>& a, arrayQueue<T>& b);//�ϲ�����a,b����ǰ����
    //void split(arrayQueue<T>& a, arrayQueue<T>& b);//����ǰ���зֳ���������a,b

    /*���ز�����*/
    /*����[]������*/
    T operator[](int i)
    {
        chainNode<T>* currentNode = theFront;
        for (int j = 0; j < i; j++)
            currentNode = currentNode->next;
        return currentNode->element;
    }

    istream& input(istream& in);
    void output(ostream& out) const;
//    /*��Ԫ����*/
//    friend istream& operator>> <T>(istream& in, linkedQueue<T>& m);
//    //������ǲ�pop()Ԫ��
//    friend ostream& operator<< <T>(ostream& out, linkedQueue<T>& m);
private:
    chainNode<T>* theFront;       // ָ���һ��Ԫ�ص�ָ��
    chainNode<T>* theBack;        // ָ�����һ��Ԫ�ص�ָ��
    int queueSize;    // ���е�������ʵ���ϱȶ�������(������queueFrontָ�����һ��λ��)��1
};
/*��Ԫ����*/
/*>>������*/
template<class T>
istream& linkedQueue<T>::input(istream& in)
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
istream& operator>>(istream& in, linkedQueue<T>& m){
    m.input(in);
    return in;
}

//������ǲ�pop()Ԫ��
/*<<������*/
template<class T>
void linkedQueue<T>::output(ostream& out) const
{
    chainNode<T>* currentNode =  theFront;
    while(currentNode != nullptr)
    {
        cout << currentNode->element << " ";
        currentNode = currentNode->next;
    }
    out << endl;
}

template<class T>
ostream& operator<<(ostream& out, const linkedQueue<T>& x)
{
    x.output(out);
    return out;
}
/*��Ա����*/
/*��������*/
template<class T>
linkedQueue<T>::~linkedQueue()
{
    chainNode<T>* nextNode = theFront;
    while (nextNode != nullptr)
    {
        nextNode = nextNode->next;
        delete theFront;
        theFront = nextNode;
    }
}
/*��ն����е�Ԫ��*/
template<class T>
void linkedQueue<T>::clear()
{
    chainNode<T>* nextNode = theFront;
    while (nextNode != nullptr)
    {
        nextNode = nextNode->next;
        delete theFront;
        theFront = nextNode;
    }
    queueSize = 0;
    theFront = theBack = nullptr;
}

#endif
