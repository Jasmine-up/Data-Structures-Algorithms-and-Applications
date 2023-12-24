/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			�������Ա�ͷ�ļ�---������
*/
#pragma once
#ifndef _CHAIN_H_
#define _CHAIN_H_
#include<iostream>
#include<sstream>
#include<cmath>
#include "_1myExceptions.h"
#include "_2myFunctions.h"
#include "_4linearList.h"
#include "_5arrayList.h"
#include "_6chainNode.h"

using std::ostream;
using std::ostringstream;
using std::find;
using std::cout;
using std::forward_iterator_tag;
using std::ptrdiff_t;
using std::endl;

void chainTest();//���Ժ���������������chain.cpp�С�

template<class T>
class chain : public linearList<T>
{
public:

    /*���캯��*/
    chain(int initialCapacity = 10);
    /*���ƹ��캯��*/
    chain(const chain<T>&);
    /*���鹹������*/
    chain(const arrayList<T>& arrayTo);//ֱ��ʹ�ù��캯��--ʹ�������ʼ������
    /*��������*/
    ~chain();

    //������������ADT����
    bool empty() const { return listSize == 0; }
    int size() const { return listSize; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void output(ostream& out) const;
    void clear();
    void push_back(const T& theElement);
    /*ϰ��2*/
    void setSize(int theSize);
    /*ϰ��3*/
    void set(int theIndex, const T& theElement);
    /*ϰ��4*/
    void removeRange(int fromIndex, int toIndex);
    /*ϰ��5*/
    int lastIndexOf(const T& theElement);
    /*ϰ��10*/
    void swap(chain<T>& theChain);
    /*ϰ��13*/
    void toArray(arrayList<T>& theArray);
    /*ϰ��14*/
    void leftShift(int i);
    /*ϰ��15*/
    void reverse();
    /*ϰ��18*/
    void meld(chain<T>& a, chain<T>& b);
    /*ϰ��20*/
    void merge(chain<T>& a, chain<T>& b);
    /*ϰ��22*/
    void split(chain<T>& a, chain<T>& b);
    /*ϰ��23*/
    void circularShift(int i);

    /*������*/
    class iterator
    {
    public:
        //��ǰ����������Ҫ��typedef
        typedef forward_iterator_tag iterator_category;
        typedef T value_type;
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
        /*���캯��*/
        iterator(chainNode<T>* theNode = nullptr) { node = theNode; }
        /*�����ò���*/
        T& operator*() const { return node->element; }
        T* operator->() const { return &node->element; }
        /*�������ӷ�����*/
        iterator& operator++() //ǰ��
        {
            node = node->next; return *this;
        }
        iterator& operator++(int) //���
        {
            iterator old = *this;
            node = node->next;
            return old;
        }
        /*��ȼ���*/
        bool operator!=(const iterator right) const { return node != right.node; }
        bool operator==(const iterator right) const { return node == right.node; }
    protected:
        chainNode<T>* node;
    };
    iterator begin() const { return iterator(firstNode); }
    iterator end() const { return iterator(nullptr); }

    /*���ز�����*/
    /*ϰ��6*/
    T& operator[](int i);
    const T& operator[](int i) const;
    /*ϰ��7*/
    bool operator==(chain<T>& right) const;
    /*ϰ��8*/
    bool operator!=(chain<T>& right) const;
    /*ϰ��9*/
    bool operator<(chain<T>& right) const;

    /*����*/
    void bubbleSort();
    void rankSort();
    T maxOfList();
    void selectionSort();
    void insertSort();
    /*��������*/
    void binSort(int range);
    /*��������*/
    void baseBinSort(int range);

    //�����������һ��������ܶ�Ԫ�ص����Ա�
    istream& input(istream& in);
protected:
    void checkIndex(int theIndex) const;
    //���������Ч���׳��쳣
    chainNode<T>* firstNode;//ָ�������һ���ڵ��ָ��
    int listSize;//���Ա��Ԫ�ظ���
};

/*input����*/
template<class T>
istream& chain<T>::input(istream& in)
{
    int numberOfElement = 0;
    cout << "Please enter the number of elements:" << endl;
    while (!(in >> numberOfElement)) {//����������Ͳ�ƥ�䣬��ִ��ѭ����
        in.clear(); // reset input���ñ�־λΪ��Ч
        while (in.get() != '\n') //ɾ��û���õ�����
            continue; // get rid of bad input
        cout << "Please enter the number of elements:" << endl;
    }
    T inElement = 0;
    for (int i = 0; i < numberOfElement; i++)
    {
        cout << "Please enter the element: " << (i + 1) << endl;
        while (!(in >> inElement)) {//����������Ͳ�ƥ�䣬��ִ��ѭ����
            in.clear(); // reset input���ñ�־λΪ��Ч
            while (in.get() != '\n') //ɾ��û���õ�����
                continue;
            cout << "Please enter the element: " << (i + 1) << endl;
        }
        push_back(inElement);
    }
    return in;
}

/*���캯����ʵ����initialCapacityû������ģ�����Ϊ������arrayList����*/
template<class T>
chain<T>::chain(int initialCapacity)
{
    //���캯��
    if (initialCapacity < 1)
    {
        ostringstream s("");
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    firstNode = nullptr;
    listSize = 0;
}

/*���ƹ��캯��*/
template<class T>
chain<T>::chain(const chain<T>& theList)
{
    listSize = theList.listSize;
    if (listSize == 0)
    {
        firstNode = nullptr;
        return;
    }
    //ָ��Ҫ���Ƶ�Ԫ��λ��
    chainNode<T>* sourceNode = theList.firstNode;
    firstNode = new chainNode<T>(sourceNode->element);//��������theList����Ԫ��
    sourceNode = sourceNode->next;
    //ָ��Ҫ���Ƶ�Ԫ��λ��֮ǰ��λ��
    chainNode<T>* targetNode = firstNode;
    while (sourceNode != nullptr)
    {
        targetNode->next = new chainNode<T>(sourceNode->element);
        targetNode = targetNode->next;
        sourceNode = sourceNode->next;
    }
}

/*ʹ��arrayList��ʼ������Ĺ��캯��*/
template<class T>
chain<T>::chain(const arrayList<T>& arrayTo)
{
    listSize = arrayTo.size();
    if (listSize == 0)
    {
        firstNode = nullptr;
    }
    else
    {
        int data = arrayTo.get(0);
        firstNode = new chainNode<T>(data);
        chainNode<T>* currentNode = firstNode;
        for (int i = 1; i < listSize; i++)
        {
            data = arrayTo.get(i);
            currentNode->next = new chainNode<T>(data);
            currentNode = currentNode->next;
        }
    }
}

/*��������*/
template<class T>
chain<T>::~chain()
{
    while (firstNode != nullptr)
    {
        chainNode<T>* nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

/*��������Ƿ���Ч*/
template<class T>
void chain<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= listSize)
    {
        ostringstream s("");
        s << "index = " << theIndex << "size = " << listSize;
        throw illegalIndex(s.str());
    }
}

/*��ȡ����ΪtheIndex��Ԫ��*/
template<class T>
T& chain<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex; i++)
        currentNode = currentNode->next;
    return currentNode->element;
}

/*����Ԫ��theElement�״γ���ʱ������������Ԫ�ز����ڣ��򷵻�-1��*/
template<class T>
int chain<T>::indexOf(const T& theElement) const
{
    //��������Ѱ��Ԫ��theElement
    chainNode<T>* currentNode = firstNode;
    int index = 0;
    while (currentNode != NULL && currentNode->element != theElement)
    {
        index++;
        currentNode = currentNode->next;
    }
    if (index == listSize)
        return -1;
    else
        return index;
}

/*ɾ������ΪtheIndex��Ԫ�أ�����Ԫ�ز����ڣ����׳��쳣*/
template<class T>
void chain<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    chainNode<T>* deleteNode = nullptr;
    if (theIndex == 0)
    {
        deleteNode = firstNode;
        firstNode = firstNode->next;
    }
    else
    {
        chainNode<T>* currentNode = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
        {
            currentNode = currentNode->next;
        }
        deleteNode = currentNode->next;
        currentNode->next = currentNode->next->next;
    }
    delete deleteNode;
    listSize--;
}

/*����Ԫ��theElement��ʹ������ΪtheIndex*/
template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{
    //��Ч����
    if (theIndex < 0 || theIndex > listSize)
    {
        ostringstream s("");
        s << "index = " << theIndex << "size = " << listSize;
        throw illegalIndex(s.str());
    }
    //������ͷ����
    if (theIndex == 0)
        firstNode = new chainNode<T>(theElement, firstNode);
    else
    {
        //Ѱ����Ԫ�ص�ǰ��
        chainNode<T>* p = firstNode;
        for (int i = 0; i < theIndex - 1; i++)
            p = p->next;
        //��p֮�����
        p->next = new chainNode<T>(theElement, p->next);
    }
    listSize++;
}

/*����output*/
template<class T>
void chain<T>::output(ostream& out) const
{
    for (chainNode<T>* currentNode = firstNode;
         currentNode != nullptr;
         currentNode = currentNode->next)
        out << currentNode->element << " ";
}

/*����<<������*/
template<class T>
ostream& operator<<(ostream& out, const chain<T>& x)
{
    x.output(out);
    return out;
}
/*����>>������*/
template<typename T>
std::istream& operator>>(std::istream &os, chain<T>& m)
{
    m.input(os);
    return os;
}

/*�������*/
template<class T>
void chain<T>::clear()
{
    chainNode<T>* nextNode = nullptr;
    while (firstNode != nullptr)
    {
        nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
    listSize = 0;
}

/*������ĩβ����Ԫ��theElement�Ľڵ�*/
template<class T>
void chain<T>::push_back(const T& theElement)
{
    chainNode<T>* newNode = new chainNode<T>(theElement, nullptr);
    if (firstNode == nullptr)
        firstNode = newNode;
    else
    {
        chainNode<T>* currentNode = firstNode;
        while (currentNode->next != nullptr)
            currentNode = currentNode->next;
        currentNode->next = newNode;
    }
    listSize++;
}

/*
* ϰ��2
* ʹ�����Ա�Ĵ�С����theSize;����ʼ���Ա�Ĵ�СС��theSize,������Ԫ�أ�
* ����ʼ���Ա�Ĵ�С����theSize����ɾ�������Ԫ�ء�
*/
template<class T>
void chain<T>::setSize(int theSize)
{
    if (listSize > theSize)
    {
        chainNode<T>* currentNode = firstNode;
        for (int i = 0; i < theSize-1; i++)
            currentNode = currentNode->next;//ʹ��currentNodeָ���theSize��Ԫ��

        chainNode<T>* deleteNode = currentNode->next;
        currentNode->next = nullptr;//����theSize��Ԫ��ָ��nullptr
        //ɾ�����ж����Ԫ�أ��ظ�������currentNode������
        while (deleteNode != nullptr)
        {
            currentNode = deleteNode->next;
            delete deleteNode;
            deleteNode = currentNode;
        }
        listSize = theSize;
    }
}

/*
* ϰ��3
* ��Ԫ��theElement�滻����ΪtheIndex��Ԫ�أ�������theIndex������Χ�����׳��쳣
*/
template<class T>
void chain<T>::set(int theIndex, const T& theElement)
{
    checkIndex(theIndex);
    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i < theIndex - 1; i++)
        currentNode = currentNode->next;
    currentNode->element = theElement;
}

/*
* ϰ��4
* ɾ��ָ��������Χ�ڵ�����Ԫ��:(fromIndex,toIndex)---ǰ����
* ���������Χ��������Χ�����׳��쳣��
*/
template<class T>
void chain<T>::removeRange(int fromIndex, int toIndex)
{
    checkIndex(fromIndex+1);
    checkIndex(toIndex-1);
    chainNode<T>* fromNode = firstNode;
    int i = 0;
    for (i = 0; i < fromIndex; i++)
        fromNode = fromNode->next;//��סfromIndex��ָ��
    chainNode<T>* toNode = fromNode->next;//��ɾ��fromIndex�Ľ��
    i++;
    chainNode<T>* deleteNode = nullptr;
    //��סtoIndex��ָ�벢delete���Ľ��
    while (i < toIndex)
    {
        deleteNode = toNode;
        toNode = toNode->next;
        delete deleteNode;//Ҫע���ɾ����ȻtoNode��ָ��nullptr
        i++;
    }
    fromNode->next = toNode;
    listSize = listSize - (toIndex - fromIndex - 1);
}

/*
* ϰ��5
* ����ֵ��ָ��Ԫ��������ʱ����������������Ԫ�ز����ڣ��򷵻�-1��
*/
template<class T>
int chain<T>::lastIndexOf(const T& theElement)
{
    int index = -1;
    int loc = 0;
    chainNode<T>* currentNode = firstNode;
    while (currentNode != nullptr)
    {
        //�ҵ��͸���index��û�ҵ��Ͳ�����
        if (currentNode->element == theElement)
            index = loc;
        currentNode = currentNode->next;
        loc++;
    }
    return index;
}

/*
* ϰ��10��
* ��������*this��theChain������Ԫ��
*/
template<class T>
void chain<T>::swap(chain<T>& theChain)
{
    chainNode<T>* temp = firstNode;
    firstNode = theChain.firstNode;
    theChain.firstNode = temp;

    int tempnum = listSize;
    listSize = theChain.listSize;
    theChain.listSize = tempnum;
}

/*
* ϰ��13��
* ������*thisת��Ϊ����theArray
* ������ת��Ϊ������ʹ���˹��캯��ʵ��
*/
template<class T>
void chain<T>::toArray(arrayList<T>& theArray)
{
    theArray.clear();//����Ҫ�������
    chainNode<T>* currentNode = firstNode;
    for (int i = 0; i < listSize; i++)
    {
        theArray.push_back(currentNode->element);
        currentNode = currentNode->next;
    }
}

/*ϰ��14�������е�Ԫ�������ƶ�i��λ��*/
template<class T>
void chain<T>::leftShift(int i)
{
    if (listSize > i)
    {
        chainNode<T>* deleteNode = nullptr;
        for (int j = 0; j < i && j < listSize; j++)
        {
            deleteNode = firstNode;
            firstNode = firstNode->next;
            delete deleteNode;
        }
        listSize -= i;
    }
    else
        throw illegalIndex();
}

/*ϰ��15���ߵ�*this�е�Ԫ�ص�˳��*/
template<class T>
void chain<T>::reverse()
{
    /*�õڶ����ڵ�ָ���һ���ڵ�*/
    chainNode<T>* beforeNode = nullptr;
    chainNode<T>* currentNode = firstNode;
    chainNode<T>* temp;
    /*�õڶ����ڵ��Ժ����һ���ڵ���ǰ�����нڵ�ָ����ǰ��Ľڵ�*/
    while (currentNode != nullptr)
    {
        temp = currentNode->next;
        currentNode->next = beforeNode;
        beforeNode = currentNode;
        currentNode = temp;
    }
    /*firstNodeָ�����һ���ڵ�*/
    firstNode = beforeNode;
}

/*
* ϰ��18��
meld()��*thisΪ�µ���չ������,����a����Ԫ�ؿ�ʼ������ذ���a��b��Ԫ�ء�
���һ�������Ԫ��ȡ���ˣ��Ͱ���һ�������ʣ��Ԫ�ظ��ӵ��µ���չ����c�С�
�ϲ��������ʹ�õ�Ӧ��������a��b�Ľڵ�ռ䣬�ϲ�֮����������a��b�ǿձ�
*/
template<class T>
void chain<T>::meld(chain<T>& a, chain<T>& b)
{
    //����ձ�����
    (*this).clear();
    chainNode<T>* currentNode = nullptr;
    /*��ǰa,b������Ϊnullptrʱ*/
    while (a.firstNode != nullptr && b.firstNode != nullptr)
    {
        if (listSize == 0)
        {
            //���a,b������Ϊ�գ�����c���Ȳ���a,b��һ��Ԫ��
            firstNode = a.firstNode;
            a.firstNode = (a.firstNode)->next;
            (a.listSize)--;
            firstNode->next = b.firstNode;
            b.firstNode = (b.firstNode)->next;
            (b.listSize)--;
            listSize += 2;
            currentNode = firstNode->next;//��ǰ���ָ��ڶ���Ԫ��
        }
        else
        {
            currentNode->next = a.firstNode;
            a.firstNode = (a.firstNode)->next;
            (a.listSize)--;
            listSize++;
            currentNode = currentNode->next;
            currentNode->next = b.firstNode;
            b.firstNode = (b.firstNode)->next;
            (b.listSize)--;
            listSize++;
            currentNode = currentNode->next;
        }
    }
    /*��ǰb����Ϊnullptrʱ*/
    if (a.firstNode != nullptr)
    {
        if (listSize == 0)
        {
            //�����ǰa����Ϊ�գ�����c�в���a������Ԫ��
            firstNode = a.firstNode;
            a.firstNode = nullptr;
            listSize += a.listSize;
            a.listSize = 0;
        }
        else
        {
            currentNode->next = a.firstNode;
            listSize += a.listSize;
            a.firstNode = nullptr;
            a.listSize = 0;
        }
    }
    /*��ǰa����Ϊnullptrʱ*/
    if (b.firstNode != nullptr)
    {
        if (listSize == 0)
        {
            //�����ǰa����Ϊ�գ�����c�в���a������Ԫ��
            firstNode = b.firstNode;
            b.firstNode = nullptr;
            listSize += b.listSize;
            b.listSize = 0;
        }
        else
        {
            currentNode->next = b.firstNode;
            b.firstNode = nullptr;
            listSize+=b.listSize;
            b.listSize = 0;
        }
    }
}

/*
* ϰ��20
* merge():��������a��b,�ϲ�������������(*this),�˺�a,b����Ϊ�ձ�
*/
template<class T>
void chain<T>::merge(chain<T>& a, chain<T>& b)
{
    //����ձ�����
    (*this).clear();
    chainNode<T>* currentNode = nullptr;
    /*��ǰa,b������Ϊnullptrʱ*/
    while (a.firstNode != nullptr && b.firstNode != nullptr)
    {
        //���Ƚ����һ��Ԫ��
        if (listSize == 0)
        {
            //���a,b������Ϊ�գ�����c�����Ȳ���a,b��С��һ��Ԫ��
            if ((a.firstNode)->element <= (b.firstNode)->element)
            {
                firstNode = a.firstNode;
                a.firstNode = (a.firstNode)->next;
                listSize++;
                a.listSize--;
                currentNode = firstNode;//��ǰ���ָ���һ��Ԫ��
            }
            else
            {   //���a,b������Ϊ�գ�����c�����Ȳ���a,b��С��һ��Ԫ��
                firstNode = b.firstNode;
                b.firstNode = (b.firstNode)->next;
                listSize++;
                b.listSize--;
                currentNode = firstNode;//��ǰ���ָ���һ��Ԫ��
            }
        }
            //Ȼ���������Ԫ��
        else
        {
            if ((a.firstNode)->element <= (b.firstNode)->element)
            {
                currentNode->next = a.firstNode;
                a.firstNode = (a.firstNode)->next;
                listSize++;
                a.listSize--;
                currentNode = currentNode->next;
            }
            else
            {
                currentNode->next = b.firstNode;
                b.firstNode = (b.firstNode)->next;
                listSize++;
                b.listSize--;
                currentNode = currentNode->next;
            }
        }
    }
    /*��ǰb����Ϊnullptrʱ*/
    if (a.firstNode != nullptr)
    {
        if (listSize == 0)
        {
            //�����ǰa����Ϊ�գ�����c�в���a������Ԫ��
            firstNode = a.firstNode;
            a.firstNode = nullptr;
            listSize += a.listSize;
            a.listSize = 0;
        }
        else
        {
            currentNode->next = a.firstNode;
            listSize += a.listSize;
            a.firstNode = nullptr;
            a.listSize = 0;
        }
    }
    /*��ǰa����Ϊnullptrʱ*/
    while (b.firstNode != nullptr)
    {
        if (listSize == 0)
        {
            //�����ǰa����Ϊ�գ�����c�в���b������Ԫ��
            firstNode = b.firstNode;
            b.firstNode = nullptr;
            listSize += b.listSize;
            b.listSize = 0;
        }
        else
        {
            currentNode->next = b.firstNode;
            b.firstNode = nullptr;
            listSize += b.listSize;
            b.listSize = 0;
        }
    }
}

/*
* ��ϰ22
* split():����������չ����a��b,a����*this������Ϊ������Ԫ�أ�b����*this��������Ԫ��,�˺�*this����Ϊ�ձ�
*/
template<class T>
void chain<T>::split(chain<T>& a, chain<T>& b)
{
    chainNode<T>* currentNodeA = nullptr;
    chainNode<T>* currentNodeB = nullptr;
    for (int i = 0; i < listSize; i++)
    {
        if (i % 2 == 0)
        {
            if (b.listSize == 0)
            {
                b.firstNode = firstNode;
                firstNode = firstNode->next;
                (b.listSize)++;
                currentNodeB = b.firstNode;
            }
            else
            {
                currentNodeB->next = firstNode;
                firstNode = firstNode->next;
                (b.listSize)++;
                currentNodeB = currentNodeB->next;
            }
        }
        else
        {
            if (a.listSize == 0)
            {
                a.firstNode = firstNode;
                firstNode = firstNode->next;
                (a.listSize)++;
                currentNodeA = a.firstNode;
            }
            else
            {
                currentNodeA->next = firstNode;
                firstNode = firstNode->next;
                (a.listSize)++;
                currentNodeA = currentNodeA->next;
            }
        }
    }
    listSize = 0;
    currentNodeA->next = nullptr;
    currentNodeB->next = nullptr;
}

/*
* ϰ��23��
* ѭ���ƶ� [0,1,2,3,4]ѭ���ƶ���λ��[2,3,4,0,1]
*/
template<class T>
void chain<T>::circularShift(int i)
{
    //��סԭʼ��һ���ڵ�
    chainNode<T>* originalNode = firstNode;
    chainNode<T>* lastNode = nullptr;
    //�ҵ�ѭ���ƶ�������ĵ�һ���ڵ�
    for (int j = 0; j < i; j++)
    {
        firstNode = firstNode->next;
        //�ҵ�ѭ���ƶ�����������һ���ڵ�
        if (j == i - 2)
            lastNode = firstNode;
    }
    chainNode<T>* currentNode = firstNode;
    //�ҵ�ԭʼ��������һ���ڵ�
    while (currentNode->next != nullptr)
        currentNode = currentNode->next;
    //ԭʼ��������һ�����ָ��ԭʼ����ĵ�һ�����
    currentNode->next = originalNode;
    //ѭ������������һ�����ָ��nullptr
    lastNode->next = nullptr;
}

/*���ز�����*/

/*
* ϰ��6
* ����[]������
*/
template<class T>
T& chain<T>::operator[](int i)
{
    checkIndex(i);
    chainNode<T>* currentNode = firstNode;
    for (int j = 0; j < i; j++)
        currentNode = currentNode->next;//�Ȼ�ȡ����ַ
    return currentNode->element;//Ȼ�󷵻�Ԫ��
}
template<class T>
const T& chain<T>::operator[](int i) const
{
    checkIndex(i);
    chainNode<T>* currentNode = firstNode;
    for (int j = 0; j < i; j++)
        currentNode = currentNode->next;//�Ȼ�ȡ����ַ
    return currentNode->element;//Ȼ�󷵻�Ԫ��
}

/*ϰ��7������==������*/
template<class T>
bool chain<T>::operator==(chain<T>& right) const
{
    if (listSize == right.listSize)
    {
        int i = listSize;
        chainNode<T>* leftNode = firstNode;
        chainNode<T>* rightNode = right.firstNode;
        while (i--)
        {
            //ֻҪ�в���Ⱦͷ���false
            if (leftNode->element != rightNode->element)
                return false;
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }
        //ֻ��ȫ�����ʱ�ŷ���true
        return true;
    }
    else  //���Ȳ����ֱ�ӷ���false
        return false;
}

/*ϰ��8������!=������*/
template<class T>
bool chain<T>::operator!=(chain<T>& right) const
{
    if (listSize == right.listSize)
    {
        int i = listSize;
        chainNode<T>* leftNode = firstNode;
        chainNode<T>* rightNode = right.firstNode;
        while (i--)
        {
            //ֻҪ�в���Ⱦͷ���true
            if (leftNode->element != rightNode->element)
                return true;
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }
        //ֻ��ȫ�����ʱ�ŷ���false
        return false;
    }
    else  //���Ȳ����ֱ�ӷ���true
        return true;
}

/*ϰ��9������<������,Ҫ������������е�Ԫ�ض�С���ұ������Ԫ��*/
template<class T>
bool chain<T>::operator<(chain<T>& right) const
{
    //��������ȴ����ұ�����ʱ��ֱ�ӷ���false
    if (listSize > right.listSize)
        return false;
    else
    {
        chainNode<T>* leftNode = firstNode;
        chainNode<T>* rightNode = right.firstNode;
        for (int i = 0; i < listSize; i++)
        {
            //������������Ԫ�ش����ұ������Ԫ��ʱ��ֱ�ӷ���false
            if (leftNode->element >= rightNode->element)
                return false;
            leftNode = leftNode->next;
            rightNode = rightNode->next;
        }
        return true;
    }
}

/*����*/
/*ð������*/
template<class T>
void chain<T>::bubbleSort()
{
    for (int i = listSize; i > 1; i--)
    {
        int j = 1;
        chainNode<T>* currentNode = firstNode;
        while (j < i)
        {
            if (currentNode->element > currentNode->next->element)
                Swap<T>(currentNode->element, currentNode->next->element);
            currentNode = currentNode->next;
            j++;
        }
    }
}

/*����������*/
template<class T>
void chain<T>::rankSort()
{
    int* r = new int[listSize];
    //��ʼ������
    for (int i = 0; i < listSize; i++)
        r[i] = 0;
    //��������
    for (int i = listSize - 1; i >= 0; i--) //���������ó�ÿ��Ԫ��������Ԫ�رȽ�
    {
        for (int j = 0; j < i; j++)
        {
            if ((*this)[i]>(*this)[j])
                r[i]++;
            else
                r[j]++;
        }
    }
    //����������
    for (int i = 0; i < listSize; i++)
    {
        if (i != r[i])
        {
            Swap<T>((*this)[i], (*this)[r[i]]);
            Swap<T>(r[i], r[r[i]]);
        }
    }
    delete[] r;
}

/*������������Ԫ��*/
template<class T>
T chain<T>::maxOfList()
{
    chain<T>::iterator it = (*this).begin();
    T tempMax = *it;//�洢���Ԫ��
    for (int i = 1; i < listSize; i++)
    {
        it++;
        if ((*it) > tempMax)
        {
            tempMax = *it;
        }
    }
    return tempMax;
}

/*ѡ������*/
template<class T>
void chain<T>::selectionSort()
{
    int indexMax = 0;
    bool is_sorted = false;
    for (int i = listSize; i > 1 && !is_sorted; i--)
    {
        is_sorted = true;
        indexMax = 0;
        chain<T>::iterator it = (*this).begin();
        T tempMax = *it;//�洢���Ԫ��
        for (int j = 1; j < i; j++)
        {
            it++;
            if ((*it) > tempMax)
            {
                tempMax = *it;
                indexMax = j;
            }
            else
                is_sorted = false;
        }
        Swap<T>((*this)[i - 1], (*this)[indexMax]);
    }
}

/*��������*/
template<class T>
void  chain<T>::insertSort()
{
    for (int i = 1; i < listSize; i++)
    {
        chainNode<T>* currentNode = firstNode;
        int tempData = (*this)[i];
        int j = 0;
        for (j = 0; j < i ; j++)
        {
            if (tempData < currentNode->element)
                break;
            else
                currentNode = currentNode->next;
        }
        if (j != i)
        {
            (*this).insert(j, tempData);
            (*this).erase(i + 1);
        }
    }
}

/*��������,rangeָ��������Ԫ�ص����Χ,�ʺ����ݼ��е����*/
template<class T>
void chain<T>::binSort(int range)
{
    //�������еĽ������
    //������ʼ������
    chainNode<T>** bottom, ** top;//bottomָ�����ӵĵײ���topָ�����ӵĶ���
    bottom = new chainNode<T>*[range + 1];
    top = new chainNode<T>*[range + 1];
    for (int b = 0; b <= range; b++)
        bottom[b] = nullptr;

    //������Ľ����䵽����
    for (; firstNode != nullptr; firstNode = firstNode->next)
    {//���׽��firstNode���뵽������
        int data = firstNode->element;//Ԫ������ת��Ϊ����
        if (bottom[data] == nullptr) //����Ϊ��
            bottom[data] = top[data] = firstNode;
        else  //���Ӳ���
        {
            top[data]->next = firstNode;
            top[data] = firstNode;
        }
    }

    //�������еĽ���ռ�����������
    chainNode<T>* y = nullptr;
    for (int bin = 0; bin <= range; bin++)
    {
        if (bottom[bin] != nullptr)
        {
            if (y == nullptr)  //��һ���ǿ�����
                firstNode = bottom[bin];
            else
                y->next = bottom[bin];
            y = top[bin];
        }
    }
    if (y->next != nullptr)
        y->next = nullptr;
    delete[] bottom;
    delete[] top;
}

/*��������*/
template<class T>
void chain<T>::baseBinSort(int range)
{
    //�������еĽ������
    chainNode<T>** bottom, ** top;//bottomָ�����ӵĵײ���topָ�����ӵĶ���
    bottom = new chainNode<T>*[range + 1];
    top = new chainNode<T>*[range + 1];
    //��ȡ���������ݵ����ֵ
    int maxData = maxOfList();
    int binNum = 1;//����Ҫ������������Ĵ���
    while (maxData / (range + 1))
    {
        maxData /= (range + 1);
        binNum++;
    }
    for(int i = 0;i< binNum;i++)
    {
        //ÿһ�ζ�Ҫ��ʼ������
        for (int b = 0; b <= range; b++)
            bottom[b] = nullptr;

        //������Ľ����䵽����
        for (; firstNode != nullptr; firstNode = firstNode->next)
        {//���׽��firstNode���뵽������
            int data = int((firstNode->element)/pow(10,i)) % 10;//Ԫ������ת��Ϊ����
            if (bottom[data] == nullptr) //����Ϊ��
                bottom[data] = top[data] = firstNode;
            else  //���Ӳ���
            {
                top[data]->next = firstNode;
                top[data] = firstNode;
            }
        }

        //�������еĽ���ռ�����������
        chainNode<T>* y = nullptr;
        for (int bin = 0; bin <= range; bin++)
        {
            if (bottom[bin] != nullptr)
            {
                if (y == nullptr)  //��һ���ǿ�����
                    firstNode = bottom[bin];
                else
                    y->next = bottom[bin];
                y = top[bin];
            }
        }
        if (y->next != nullptr)
            y->next = nullptr;
        cout << "(*this) = " << *this << endl;
    }
    delete[] bottom;
    delete[] top;
}


/*�ǳ�Ա����*/
/*meld()������һ���µ���չ������c,����a����Ԫ�ؿ�ʼ������ذ���a��b��Ԫ�ء�
���һ�������Ԫ��ȡ���ˣ��Ͱ���һ�������ʣ��Ԫ�ظ��ӵ��µ���չ����c�С�*/
template<class T>
void meld(chain<T>& a, chain<T>& b, chain<T>& c)
{
    c.clear();//���������C
    typename chain<T>::iterator pointerA = a.begin();
    typename chain<T>::iterator pointerB = b.begin();
    while (pointerA != nullptr && pointerB != nullptr)
    {
        c.push_back(*pointerA);
        pointerA++;
        c.push_back(*pointerB);
        pointerB++;
    }
    while (pointerA != nullptr)
    {
        c.push_back(*pointerA);
        pointerA++;
    }
    while (pointerB != nullptr)
    {
        c.push_back(*pointerB);
        pointerB++;
    }
}

/*����merge()---����һ���µ���������c,������a��b������Ԫ��,�Һ�����a,b����Ϊ��*/
template<class T>
void merge(chain<T>& a, chain<T>& b, chain<T>& c)
{
    c.clear();//���������C
    typename chain<T>::iterator pointerA = a.begin();
    typename chain<T>::iterator pointerB = b.begin();
    while (pointerA != nullptr && pointerB != nullptr)
    {
        /*����С����һ��*/
        if (*pointerA > *pointerB)
        {
            c.push_back(*pointerB);
            pointerB++;
        }
        else
        {
            c.push_back(*pointerA);
            pointerA++;
        }
    }
    while (pointerA != nullptr)
    {
        c.push_back(*pointerA);
        pointerA++;
    }
    while (pointerB != nullptr)
    {
        c.push_back(*pointerB);
        pointerB++;
    }
}

/*������������a��b,a����c������Ϊ������Ԫ�أ�b����c��������Ԫ�أ��Һ�����c����Ϊ��*/
template<class T>
void split(chain<T>& a, chain<T>& b, chain<T>& c)
{
    //���������a������b
    a.clear();
    b.clear();
    typename chain<T>::iterator pointerC = c.begin();
    for (int i = 0; i < c.size(); i++)
    {
        if (i % 2 == 1)
        {
            a.push_back(*pointerC);
            pointerC++;
        }
        else
        {
            b.push_back(*pointerC);
            pointerC++;
        }
    }
}

#endif