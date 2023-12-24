/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			�������Ա�ͷ�ļ�---����
*/
#pragma once
#ifndef __ARRAYLIST_H_
#define __ARRAYLIST_H_
/*��ʵ֤����ģ����ģ���ǿ��Բ���ͬһ��ͷ�ļ��µġ����ǣ�ģ�庯�������Ͷ���Ҫ��ͬһ��ͷ�ļ��¡�*/

#include <algorithm>
#include<iostream>
#include<sstream>
#include<cmath>
#include<cstddef>
#include <iterator>
#include "_1myExceptions.h"
#include "_2myFunctions.h"
#include "_4linearList.h"

using std::ostream;
using std::ostringstream;
using std::find;
using std::cout;
using std::copy;
using std::min;
using std::copy_backward;
using std::ostream_iterator;
using std::bidirectional_iterator_tag;
using std::ptrdiff_t;

//���ڲ��ܻ������ͷ�ļ�����˸�������
template<class T>
class chain;
template<typename T>
class arrayList;
void arrayListTest();//arrayList���Ժ���������arrayList���к���

template<class T>
class arrayList : public linearList<T>
{
public:
    /*���캯��*/
    arrayList(int initialCapacity = 1);
    /*���ƹ��캯��*/
    arrayList(const arrayList<T>&);
    /*ʹ������������*/
    arrayList(const chain<T>& theChain);
    /*��������*/
    ~arrayList() { delete[] element; }

    /*������Ա����*/
    bool empty() const { return arraySize == 0; }
    int size() const { return arraySize; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void insert(int theIndex, const T& theElement,int size);
    void output(ostream& out) const;
    /*��ϰ��5 ʱ�临�Ӷ�ΪO(1)*/
    void trimToSize();

    int capacity() const { return arrayLength; }
    /*��ϰ��11*/
    void push_back(const T& theElement);//��Ԫ��theElement������������Ҷ�
    /*��ϰ��12*/
    T pop_back();//ɾ���������Ҷ�Ԫ�أ������ظ�Ԫ��
    /*��ϰ��13*/
    void swap(arrayList<T>& theList);
    /*��ϰ��14*/
    void reserve(int theCapacity);
    /*��ϰ��15*/
    void set(int theIndex, const T& theElement);
    /*��ϰ��16*/
    void clear();
    /*��ϰ��17*/
    void removeRange(int theIndex1, int theIndex2);
    /*��ϰ��18*/
    int lastIndexOf(T theElement);
    /*��ϰ��22*/
    void reverse();
    /*��ϰ��23*/
    void leftShift(int num);
    /*��ϰ��24*/
    void circularShift(int i);
    /*��ϰ��25*/
    void half();
    /*��ϰ��28*/
    void meld(arrayList<T>& a, arrayList<T>& b);
    /*��ϰ��29*/
    void merge(arrayList<T>& a, arrayList<T>& b);
    /*��ϰ��30*/
    void split(arrayList<T>& a, arrayList<T>& b);
    void reSet(int capacity);

    /*���������*/
    //���⣺��չ��������ʹ֮��Ϊ������ʵ������������ʱ��̫�ᡣ
    class iterator
    {
    public:
        //��C++��typedef���ʵ��˫�������
        //��һС��typedef��ʱ��̫��
        typedef bidirectional_iterator_tag iterator_category;//˫�������
        typedef T value_type;
        typedef ptrdiff_t difference_type;//��һ���������ص��������ͣ�ͨ��������������ָ����������Ľ����
        typedef T* pointer;
        typedef T& reference;

        //���캯��
        iterator(T* thePosition = 0) { position = thePosition; }
        //�����ò�����
        T& operator*() const { return *position; }
        //ָ�������->
        T* operator->() const { return &*position; }
        //��������ֵ����
        iterator& operator++()//ǰ��
        {
            ++position;
            return *this;
        }
        iterator operator++(int)//���
        {
            iterator old = *this;
            ++position;
            return old;
        }
        //��������ֵ����
        iterator& operator--()//ǰ��
        {
            --position;
            return *this;
        }
        iterator operator--(int)//���
        {
            iterator old = *this;
            --position;
            return old;
        }
        //�����Ƿ����
        bool operator!=(const iterator right) const
        {
            return position != right.position;
        }
        bool operator==(const iterator right) const
        {
            return position == right.position;
        }
    protected:
        T* position;
    };
    iterator begin() { return iterator(element); }
    iterator end() { return iterator(element + arraySize); }//���ص������һ��Ԫ�غ����һ��λ��

    /*���ز�����*/
    /*��ϰ��7*/
    T& operator[](int i);
    const T& operator[](int i) const;
    /*��ϰ��8*/
    bool operator==(arrayList<T> right) const;
    /*��ϰ��9*/
    bool operator!=(arrayList<T> right) const;
    /*��ϰ��10*/
    bool operator<(arrayList<T> right) const;

    /*����*/
    void bubbleSort();
    void rankSort();
    int indexOfMax();
    void selectionSort();
    void insertSort();

    //�����������һ��������ܶ�Ԫ�ص����Ա�
    istream& input(istream& in);

protected:
    void checkIndex(int theIndex) const;//������theIndex��Ч�����׳��쳣
    /*setLength()����û�����·����ڴ�*/
    /*setLength(),setSize(),setElement()����ֻӦ����swap()����*/
    void setLength(int Length) { arrayLength = Length; }
    void setSize(int Size) { arraySize = Size; }
    void setElement(T* theElement) { element = theElement; }
    T* address() const { return element; }
    T* element;//�洢���Ա�Ԫ�ص�һά����
    int arrayLength;//һά���������
    int arraySize;//���Ա��Ԫ�ظ���
};

/*���캯��*/
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
    //����ʼ�����С�Ƿ����Ҫ��
    if ( initialCapacity < 1 )
    {
        ostringstream s("");
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    //��ʼ������˽��Ԫ��
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    arraySize = 0;
}

/*���ƹ��캯��*/
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
    arrayLength = theList.arrayLength;
    arraySize = theList.arraySize;
    //Ϊ����������ڴ�
    element = new T[arrayLength];
    //���������е�Ԫ�ظ��Ƶ�������
    copy(theList.element, theList.element + arraySize, element);
}

/*ʹ��chain��ʼ������,ʹ���˵�����*/
template<class T>
arrayList<T>::arrayList(const chain<T>& theChain)
{
    arraySize = theChain.size();
    arrayLength = arraySize;
    element = new T[arraySize];//ʹ������ĳ��Ⱥ��������
    //���ȶ���һ�����������ָ�������׵�ַ
    /*����ΪʲôҪ����typename?ԭ���ǲ�ʹ��typename������������
      ����	C7510	��iterator��: ���� �������Ƶ�ʹ�ñ����ԡ�typename��Ϊǰ׺��
      ֻ�м���typename�ſɽ��������⣬����ԭ����ʱ�������

      ԭ��typename��class��ͬ��ʣ�����ʹ��typename��class����ͨ�����롣
      Ŀ�����ڸ��߱�����chain<T>::iterator��һ�����Ͷ��Ǳ�������������Ϊ�˽��
      ͷ�ļ��������õ����⣬ֻ������chain��һ���࣬�������ڴ˴�����֪��chain��
      ��Աiterator�����ͻ��Ǳ��������Ϊ����������������ʹ��typename��class��
      ��iterator�����͡�
    */
    typename chain<T>::iterator pointer = theChain.begin();
    int i = 0;
    while (pointer != nullptr)
    {
        *(element + i) = *pointer;
        pointer++;
        i++;
    }
}

/*��������Ƿ���Ч*/
template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{
    if (theIndex < 0 || theIndex >= arraySize)
    {
        ostringstream s("");
        s << "index = " << theIndex << "size = "<<arraySize;
        throw illegalIndex(s.str());
    }
}

/*��������ΪtheIndex��Ԫ�أ�����Ԫ�ز����ڣ����׳��쳣*/
template<class T>
T& arrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element[theIndex];
}

/*����Ԫ��theElement��һ�γ���ʱ������������Ԫ�ز����ڣ��򷵻�-1*/
template<class T>
int arrayList<T>::indexOf(const T& theElement) const//const��ʾ�˺����������βε�����
{
    int theIndex = (int)(find(element, element + arraySize, theElement) - element);
    if (theIndex == arraySize)
        return -1;
    else
        return theIndex;
}

/*�������Ԫ������Ϊ0��������������Ϊ1*/
template<class T>
void arrayList<T>::trimToSize()
{
    if (arraySize == 0)
    {
        //��������Ԫ��ʱ����������������Ϊ1
        changeLength(element, arrayLength, 1);
        arrayLength = 1;
    }
}

/*ɾ������ΪtheIndex��Ԫ�أ������Ԫ�ز����ڣ����׳�illegalIndex�쳣*/
template<class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    copy(element + theIndex + 1, element + arraySize, element + theIndex);
    element[--arraySize].~T();//������������������ȫ
    trimToSize();
    //���������������̫�٣�ʹ��arraySize<= arrayLength / 4��������佫��С�����С
    while (arraySize < arrayLength / 4)
    {
        changeLength(element, arrayLength, arrayLength / 2);
        arrayLength /= 2;
    }
}

/*������theIndex��λ���ϲ���һ��Ԫ��theElement*/
template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
    /*�ж��Ƿ�Ϊ��Ч����*/
    if(theIndex != 0 && theIndex != arraySize)
        checkIndex(theIndex);
    //��Ч������ȷ���Ƿ���������
    if (arraySize == arrayLength)
    {
        //����ռ����������鳤�ȱ���
        changeLength(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }
    copy_backward(element + theIndex, element + arraySize, element + arraySize + 1);
    element[theIndex] = theElement;
    arraySize += 1;
}

/*������theIndex��λ���ϲ���һ��Ԫ��theElement,���ָ��size��������ռ���ʱ������������趨Ϊsize*/
template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement,int size)
{
    /*�ж��Ƿ�Ϊ��Ч����*/
    if(theIndex != 0 && theIndex != arraySize)
        checkIndex(theIndex);
    //��Ч������ȷ���Ƿ���������
    if (arraySize == arrayLength)
    {
        //����ռ����������鳤������Ϊsize
        changeLength(element, arrayLength, size);
        arrayLength = size;
    }
    copy_backward(element + theIndex, element + arraySize, element + arraySize + 1);
    element[theIndex] = theElement;
    arraySize += 1;
}

/*����Ԫ�����*/
template<class T>
void arrayList<T>::output(ostream& out) const
{
    copy(element, element + arraySize, ostream_iterator<T>(cout, " "));
}

/*���������Ҷ˲���Ԫ��theElement*/
template<class T>
void arrayList<T>::push_back(const T& theElement)
{
    //��Ч������ȷ����������
    if (arraySize == arrayLength)
    {
        //����ռ����������鳤������Ϊsize
        changeLength(element, arrayLength, arrayLength*2);
        arrayLength = arrayLength * 2;
    }
    *(element + arraySize) = theElement;
    arraySize++;
}

/*ɾ���������Ҷ�Ԫ�ز����ظ�Ԫ��*/
template<class T>
T arrayList<T>::pop_back()
{
    checkIndex(arraySize-1);
    T temp = element[arraySize - 1];
    arraySize--;
    trimToSize();//�����������Ԫ�أ��������������Ϊ1
    //���������������̫�٣�ʹ��arraySize<= arrayLength / 4��������佫��С�����С
    while (arraySize < arrayLength / 4)
    {
        changeLength(element, arrayLength, arrayLength / 2);
        arrayLength /= 2;
    }
    return temp;
}

/*�����������Ԫ��,���ݵĲ�������������*/
template<class T>
void arrayList<T>::swap(arrayList<T>& theList)
{
    T* temp = element;
    int thisLength = arrayLength;
    int thisSize = arraySize;

    element = theList.address();
    arraySize = theList.size();
    arrayLength = theList.capacity();

    theList.setSize(thisSize);
    theList.setLength(thisLength);
    theList.setElement(temp);
}

/*������������ı�Ϊ��ǰ������theCapacity�Ľϴ���*/
template<class T>
void arrayList<T>::reserve(int theCapacity)
{
    if (arrayLength < theCapacity)
    {
        T* temp = new T[theCapacity];
        for (int i = 0; i < arraySize; i++)
        {
            temp[i] = element[i];
        }
        delete[] element;
        element = temp;
        arrayLength = theCapacity;
    }
}
/*��Ԫ��theElement�滻����ΪtheIndex��Ԫ��*/
template<class T>
void arrayList<T>::set(int theIndex, const T& theElement)
{
    checkIndex(theIndex);
    element[theIndex] = theElement;
}
/*�������*/
template<class T>
void arrayList<T>::clear()
{
    arraySize = 0;
    trimToSize();
}

/*ɾ��[theIndex1,theIndex2]ָ��������Χ�ڵ�Ԫ��*/
template<class T>
void arrayList<T>::removeRange(int theIndex1, int theIndex2)
{
    //���ȼ�������Ƿ���Ч
    checkIndex(theIndex1);
    checkIndex(theIndex2);
    for (int i = theIndex1; i < arraySize - (theIndex2 - theIndex1); i++)
    {
        element[i] = element[i + theIndex2 - theIndex1 + 1];
    }
    arraySize -= theIndex2 - theIndex1 + 1;
}

/*����ֵΪָ��Ԫ��������ʱ�����������Ԫ�ز����ڣ��򷵻�-1��*/
template<class T>
int arrayList<T>::lastIndexOf(T theElement)
{
    for (int i = arraySize - 1; i >= 0; i--)
    {
        if (element[i] == theElement)
            return i;
    }
    return -1;
}

/*ԭ�صߵ����Ա�Ԫ�ص�˳��*/
template<class T>
void arrayList<T>::reverse()
{
    for (int i = 0; i < arraySize / 2; i++)
        Swap<T>(element[i], element[arraySize - i - 1]);
}

/*�����Ա��Ԫ�������ƶ�i��λ��*/
template<class T>
void arrayList<T>::leftShift(int num)
{
    //���ȼ�������Ƿ���Ч
    checkIndex(num-1);
    for (int i = 0; i < arraySize - num + 1; i++)
    {
        element[i] = element[i + num];
    }
    arraySize -= num;
}

/*�����Ա��Ԫ��ѭ������iλ*/
template<class T>
void arrayList<T>::circularShift(int num)
{
    for(int i = 0; i < num; i++)
        push_back(element[i]);
    leftShift(num);
}

/*�����Ա��Ԫ�ظ�һ��ɾ��һ��*/
template<class T>
void arrayList<T>::half()
{
    for (int i = 1; i <= (arraySize+1) / 2; i++)
        element[i] = element[2 * i];
    arraySize = (arraySize+1) / 2;
}

/*
����һ���µ����Ա��ñ������a��b�е�����Ԫ�أ�����a��b��Ԫ���������֣����е���
Ԫ��Ϊa�еĵ�һ��Ԫ�ء�����������Ԫ��ʱ�����ĳ�����Ԫ�������ˣ������һ�������
��Ԫ������������±�ĺ󲿡�����ĸ�����Ӧ�����������ĳ��ȳ����Ա�����ϵ��
�鲢������Ա��ǵ��ö���*this
*/
template <class T>
void arrayList<T>::meld(arrayList<T>& a, arrayList<T>& b)
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

/*�����б�a,b���ϲ�����һ���µ������б����б�Ϊ(*this)*/
template<class T>
void arrayList<T>::merge(arrayList<T>& a, arrayList<T>& b)
{
    (*this).clear();
    int i = 0;
    int j = 0;
    while ((i < a.size()) && (j < b.size()))
    {
        if (a[i] < b[j])
        {
            push_back(a[i]);
            i++;
        }
        else if (a[i] == b[j])
        {
            push_back(a[i]);
            push_back(b[j]);
            i++;
            j++;
        }
        else
        {
            push_back(b[j]);
            j++;
        }
    }
    while (i < a.size())
    {
        push_back(a[i]);
        i++;
    }
    while (j < b.size())
    {
        push_back(b[j]);
        j++;
    }
}

/*�����������Ա�a��b��a����*this������Ϊ������Ԫ�أ�b���������Ԫ��*/
template<class T>
void arrayList<T>::split(arrayList<T>& a, arrayList<T>& b)
{
    a.clear();
    b.clear();
    for (int i = 0; i < arraySize; i++)
    {
        if (i % 2 == 0)
            a.push_back(element[i]);
        else
            b.push_back(element[i]);
    }
}
/*���������������Ϊcapacity,��������Ĵ�С����Ϊcapacity,ֻ����sparseMatrix��*/
template<class T>
void arrayList<T>::reSet(int capacity)
{
    if (capacity < 0)
        throw illegalParameterValue("capacity must be >= 0");
    T* temp = new T[capacity];
    delete[] element;
    element = temp;
    arraySize = capacity;
}

/*input����*/
template<class T>
istream& arrayList<T>::input(istream& in)
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
        this->push_back(inElement);
    }
    return in;
}

/*����<<������*/
template<class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
{
    x.output(out);
    return out;
}
/*����>>������*/
template<typename T>
std::istream& operator>>(std::istream &os, arrayList<T>& m)
{
    m.input(os);
    return os;
}

/*����[]������*/
template<class T>
T& arrayList<T>::operator[](int i)
{
    return element[i];
}
template<class T>
const T& arrayList<T>::operator[](int i) const
{
    return element[i];
}

/*����==������*/
template<class T>
bool arrayList<T>::operator==(arrayList<T> right) const
{
    if (arraySize == right.size())
    {
        for (int i = 0; i < arraySize; i++)
        {
            if ((*this)[i] != right[i])
                return false;//���������ֱ�ӷ���false
        }
        return true;//�����ʱ����true
    }
    else
        return false;
}

/*����!=������*/
template<class T>
bool arrayList<T>::operator!=(arrayList<T> right) const
{
    if (arraySize == right.size())
    {
        for (int i = 0; i < arraySize; i++)
        {
            if ((*this)[i] != right[i])
                return true;//���������ֱ�ӷ���true
        }
        return false;//�����ʱ����false
    }
    else
        return true;//Ԫ����������ȷ���true
}

/*����<������*/
//��left�ĳ���С���ұ�ʱ���Ƚ�left��right��Ԫ��;������leftԪ�ذ��ֵ�˳��С�ڶ�Ӧ��rightԪ�أ��򷵻�true����֮����false
//��left�ĳ��ȴ����ұ�ʱ������false
template<class T>
bool arrayList<T>::operator<(arrayList<T> right) const
{
    if (arraySize <= right.size())
    {
        for (int i = 0; i < arraySize; i++)
        {
            if ((*this)[i] >= right[i])
                return false;//��������ֱ�ӷ���false
        }
        return true;//��С��ʱ����false
    }
    else
        return false;//Ԫ����������ȷ���true
}

/*����*/
/*���ܣ���ʱ��ֹ��ð������,ʱ�临�Ӷ�Ϊn(n-1)/2*/
template<class T>
void arrayList<T>::bubbleSort()
{
    bool is_sorted = true;
    for (int i = arraySize; is_sorted && i > 1; i--)
    {
        is_sorted = false;//������Ϊδ��������������˾ͻᱻ����Ϊ������
        for (int j = 0; j < i - 1; j++)
        {
            if (element[j] > element[j + 1])
            {
                Swap<T>(element[j], element[j + 1]);
                is_sorted = true;
            }
        }
    }
}

/*����������*/
template<class T>
void arrayList<T>::rankSort()
{
    int* r = new int[arraySize];
    //��ʼ������
    for (int i = 0; i < arraySize; i++)
        r[i] = 0;
    //��������
    for (int i = arraySize - 1; i >= 0; i--) //���������ó�ÿ��Ԫ��������Ԫ�رȽ�
    {
        for (int j = 0; j < i ; j++)
        {
            if (*(element + i) > *(element + j))
                r[i]++;
            else
                r[j]++;
        }
    }
    //����������
    for (int i = 0; i < arraySize; i++)
    {
        if (i != r[i])
        {
            Swap<T>(element[i], element[r[i]]);
            Swap<T>(r[i], r[r[i]]);
        }
    }
    delete[] r;
}

/*�����������������Ԫ�ص�����*/
template<class T>
int arrayList<T>::indexOfMax()
{
    int indexMax = 0;
    for (int i = 1; i < arraySize; i++)
    {
        if (element[i] > element[indexMax])
        {
            indexMax = i;
        }
    }
    return indexMax;
}
/*ѡ������*/
template<class T>
void arrayList<T>::selectionSort()
{
    bool is_sorted = false;
    for (int i = arraySize; i > 1 && !is_sorted; i--)
    {
        is_sorted = true;
        int indexMax = 0;
        for (int j = 1; j < i; j++)
        {
            if (element[j] > element[indexMax])
                indexMax = j;
            else
                is_sorted = false;
        }
        Swap<T>(element[i - 1], element[indexMax]);
    }
}
/*ԭ�ز�������*/
template<class T>
void arrayList<T>::insertSort()
{
    int temp = 0;
    for (int i = 1; i < arraySize; i++)
    {
        temp = element[i];//��סҪ�����Ԫ��
        //�����ǰ���Ԫ�ض����ڸ�Ԫ�صĻ����ͽ���ǰ���Ԫ�غ���һλ
        int j = 0;
        for (j = i - 1; temp < element[j]; j--)
        {
            element[j + 1] = element[j];
        }
        element[j + 1] = temp;
    }
}

#endif