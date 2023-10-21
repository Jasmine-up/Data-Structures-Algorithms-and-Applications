/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			数组线性表头文件---单表
*/
#pragma once
#ifndef __ARRAYLIST_H_
#define __ARRAYLIST_H_
/*事实证明，模板与模板是可以不在同一个头文件下的。但是，模板函数声明和定义要在同一个头文件下。*/

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

//由于不能互相包含头文件，因此给出声明
template<class T>
class chain;
template<typename T>
class arrayList;
void arrayListTest();//arrayList测试函数，测试arrayList所有函数

template<class T>
class arrayList : public linearList<T>
{
public:
    /*构造函数*/
    arrayList(int initialCapacity = 1);
    /*复制构造函数*/
    arrayList(const arrayList<T>&);
    /*使用链表构造数组*/
    arrayList(const chain<T>& theChain);
    /*析构函数*/
    ~arrayList() { delete[] element; }

    /*其他成员函数*/
    bool empty() const { return arraySize == 0; }
    int size() const { return arraySize; }
    T& get(int theIndex) const;
    int indexOf(const T& theElement) const;
    void erase(int theIndex);
    void insert(int theIndex, const T& theElement);
    void insert(int theIndex, const T& theElement,int size);
    void output(ostream& out) const;
    /*练习题5 时间复杂度为O(1)*/
    void trimToSize();

    int capacity() const { return arrayLength; }
    /*练习题11*/
    void push_back(const T& theElement);//将元素theElement插入数组的最右端
    /*练习题12*/
    T pop_back();//删除数组最右端元素，并返回该元素
    /*练习题13*/
    void swap(arrayList<T>& theList);
    /*练习题14*/
    void reserve(int theCapacity);
    /*练习题15*/
    void set(int theIndex, const T& theElement);
    /*练习题16*/
    void clear();
    /*练习题17*/
    void removeRange(int theIndex1, int theIndex2);
    /*练习题18*/
    int lastIndexOf(T theElement);
    /*练习题22*/
    void reverse();
    /*练习题23*/
    void leftShift(int num);
    /*练习题24*/
    void circularShift(int i);
    /*练习题25*/
    void half();
    /*练习题28*/
    void meld(arrayList<T>& a, arrayList<T>& b);
    /*练习题29*/
    void merge(arrayList<T>& a, arrayList<T>& b);
    /*练习题30*/
    void split(arrayList<T>& a, arrayList<T>& b);
    void reSet(int capacity);

    /*迭代器相关*/
    //问题：扩展迭代器，使之成为随机访问迭代器，这个暂时不太会。
    class iterator
    {
    public:
        //用C++的typedef语句实现双向迭代器
        //这一小段typedef暂时不太懂
        typedef bidirectional_iterator_tag iterator_category;//双向迭代器
        typedef T value_type;
        typedef ptrdiff_t difference_type;//是一个与机器相关的数据类型，通常用来保存两个指针减法操作的结果。
        typedef T* pointer;
        typedef T& reference;

        //构造函数
        iterator(T* thePosition = 0) { position = thePosition; }
        //解引用操作符
        T& operator*() const { return *position; }
        //指针操作符->
        T* operator->() const { return &*position; }
        //迭代器的值增加
        iterator& operator++()//前加
        {
            ++position;
            return *this;
        }
        iterator operator++(int)//后加
        {
            iterator old = *this;
            ++position;
            return old;
        }
        //迭代器的值减少
        iterator& operator--()//前减
        {
            --position;
            return *this;
        }
        iterator operator--(int)//后减
        {
            iterator old = *this;
            --position;
            return old;
        }
        //测试是否相等
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
    iterator end() { return iterator(element + arraySize); }//返回的是最后一个元素后面的一个位置

    /*重载操作符*/
    /*练习题7*/
    T& operator[](int i);
    const T& operator[](int i) const;
    /*练习题8*/
    bool operator==(arrayList<T> right) const;
    /*练习题9*/
    bool operator!=(arrayList<T> right) const;
    /*练习题10*/
    bool operator<(arrayList<T> right) const;

    /*排序*/
    void bubbleSort();
    void rankSort();
    int indexOfMax();
    void selectionSort();
    void insertSort();

    //这个函数用于一次性输入很多元素到线性表
    istream& input(istream& in);

protected:
    void checkIndex(int theIndex) const;//若索引theIndex无效，则抛出异常
    /*setLength()函数没有重新分配内存*/
    /*setLength(),setSize(),setElement()函数只应用于swap()函数*/
    void setLength(int Length) { arrayLength = Length; }
    void setSize(int Size) { arraySize = Size; }
    void setElement(T* theElement) { element = theElement; }
    T* address() const { return element; }
    T* element;//存储线性表元素的一维数组
    int arrayLength;//一维数组的容量
    int arraySize;//线性表的元素个数
};

/*构造函数*/
template<class T>
arrayList<T>::arrayList(int initialCapacity)
{
    //检查初始数组大小是否符合要求
    if ( initialCapacity < 1 )
    {
        ostringstream s("");
        s << "Initial capacity = " << initialCapacity << "Must be > 0";
        throw illegalParameterValue(s.str());
    }
    //初始化数组私有元素
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    arraySize = 0;
}

/*复制构造函数*/
template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{
    arrayLength = theList.arrayLength;
    arraySize = theList.arraySize;
    //为新数组分配内存
    element = new T[arrayLength];
    //将旧数组中的元素复制到新数组
    copy(theList.element, theList.element + arraySize, element);
}

/*使用chain初始化数组,使用了迭代器*/
template<class T>
arrayList<T>::arrayList(const chain<T>& theChain)
{
    arraySize = theChain.size();
    arrayLength = arraySize;
    element = new T[arraySize];//使得数组的长度和容量相等
    //首先定义一个链表迭代器指向链表首地址
    /*这里为什么要是有typename?原因是不使用typename将会引发错误：
      错误	C7510	“iterator”: 类型 从属名称的使用必须以“typename”为前缀。
      只有加上typename才可解决这个问题，具体原因暂时不清楚。

      原因：typename是class的同义词；这里使用typename或class都可通过编译。
      目的在于告诉编译器chain<T>::iterator是一个类型而非变量，本程序中为了解决
      头文件互相引用的问题，只声明了chain是一个类，编译器在此处并不知道chain的
      成员iterator是类型还是变量，因此为解决二义性问题必须使用typename或class声
      明iterator是类型。
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

/*检查索引是否有效*/
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

/*返回索引为theIndex的元素；若此元素不存在，则抛出异常*/
template<class T>
T& arrayList<T>::get(int theIndex) const
{
    checkIndex(theIndex);
    return element[theIndex];
}

/*返回元素theElement第一次出现时的索引；若该元素不存在，则返回-1*/
template<class T>
int arrayList<T>::indexOf(const T& theElement) const//const表示此函数不更改形参的内容
{
    int theIndex = (int)(find(element, element + arraySize, theElement) - element);
    if (theIndex == arraySize)
        return -1;
    else
        return theIndex;
}

/*如果数组元素数量为0，则将其容量设置为1*/
template<class T>
void arrayList<T>::trimToSize()
{
    if (arraySize == 0)
    {
        //数组中无元素时，将数组容量设置为1
        changeLength(element, arrayLength, 1);
        arrayLength = 1;
    }
}

/*删除索引为theIndex的元素；如果该元素不存在，则抛出illegalIndex异常*/
template<class T>
void arrayList<T>::erase(int theIndex)
{
    checkIndex(theIndex);
    copy(element + theIndex + 1, element + arraySize, element + theIndex);
    element[--arraySize].~T();//调用析构函数，更安全
    trimToSize();
    //如果数组所存数据太少，使得arraySize<= arrayLength / 4，以下语句将缩小数组大小
    while (arraySize < arrayLength / 4)
    {
        changeLength(element, arrayLength, arrayLength / 2);
        arrayLength /= 2;
    }
}

/*在索引theIndex的位置上插入一个元素theElement*/
template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{
    /*判断是否为有效索引*/
    if(theIndex != 0 && theIndex != arraySize)
        checkIndex(theIndex);
    //有效索引，确定是否数组已满
    if (arraySize == arrayLength)
    {
        //数组空间已满，数组长度倍增
        changeLength(element, arrayLength, 2 * arrayLength);
        arrayLength *= 2;
    }
    copy_backward(element + theIndex, element + arraySize, element + arraySize + 1);
    element[theIndex] = theElement;
    arraySize += 1;
}

/*在索引theIndex的位置上插入一个元素theElement,如果指定size，当数组空间满时将数组的容量设定为size*/
template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement,int size)
{
    /*判断是否为有效索引*/
    if(theIndex != 0 && theIndex != arraySize)
        checkIndex(theIndex);
    //有效索引，确定是否数组已满
    if (arraySize == arrayLength)
    {
        //数组空间已满，数组长度设置为size
        changeLength(element, arrayLength, size);
        arrayLength = size;
    }
    copy_backward(element + theIndex, element + arraySize, element + arraySize + 1);
    element[theIndex] = theElement;
    arraySize += 1;
}

/*数组元素输出*/
template<class T>
void arrayList<T>::output(ostream& out) const
{
    copy(element, element + arraySize, ostream_iterator<T>(cout, " "));
}

/*在数组最右端插入元素theElement*/
template<class T>
void arrayList<T>::push_back(const T& theElement)
{
    //有效索引，确定数组已满
    if (arraySize == arrayLength)
    {
        //数组空间已满，数组长度设置为size
        changeLength(element, arrayLength, arrayLength*2);
        arrayLength = arrayLength * 2;
    }
    *(element + arraySize) = theElement;
    arraySize++;
}

/*删除数组最右端元素并返回该元素*/
template<class T>
T arrayList<T>::pop_back()
{
    checkIndex(arraySize-1);
    T temp = element[arraySize - 1];
    arraySize--;
    trimToSize();//如果数组中无元素，则将数组的容量置为1
    //如果数组所存数据太少，使得arraySize<= arrayLength / 4，以下语句将缩小数组大小
    while (arraySize < arrayLength / 4)
    {
        changeLength(element, arrayLength, arrayLength / 2);
        arrayLength /= 2;
    }
    return temp;
}

/*交换两数组的元素,传递的参数必须是引用*/
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

/*将数组的容量改编为当前容量和theCapacity的较大者*/
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
/*用元素theElement替换索引为theIndex的元素*/
template<class T>
void arrayList<T>::set(int theIndex, const T& theElement)
{
    checkIndex(theIndex);
    element[theIndex] = theElement;
}
/*清空数组*/
template<class T>
void arrayList<T>::clear()
{
    arraySize = 0;
    trimToSize();
}

/*删除[theIndex1,theIndex2]指定索引范围内的元素*/
template<class T>
void arrayList<T>::removeRange(int theIndex1, int theIndex2)
{
    //首先检查索引是否有效
    checkIndex(theIndex1);
    checkIndex(theIndex2);
    for (int i = theIndex1; i < arraySize - (theIndex2 - theIndex1); i++)
    {
        element[i] = element[i + theIndex2 - theIndex1 + 1];
    }
    arraySize -= theIndex2 - theIndex1 + 1;
}

/*返回值为指定元素最后出现时的索引；如果元素不存在，则返回-1。*/
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

/*原地颠倒线性表元素的顺序*/
template<class T>
void arrayList<T>::reverse()
{
    for (int i = 0; i < arraySize / 2; i++)
        Swap<T>(element[i], element[arraySize - i - 1]);
}

/*将线性表的元素向左移动i个位置*/
template<class T>
void arrayList<T>::leftShift(int num)
{
    //首先检查索引是否有效
    checkIndex(num-1);
    for (int i = 0; i < arraySize - num + 1; i++)
    {
        element[i] = element[i + num];
    }
    arraySize -= num;
}

/*将线性表的元素循环左移i位*/
template<class T>
void arrayList<T>::circularShift(int num)
{
    for(int i = 0; i < num; i++)
        push_back(element[i]);
    leftShift(num);
}

/*将线性表的元素隔一个删除一个*/
template<class T>
void arrayList<T>::half()
{
    for (int i = 1; i <= (arraySize+1) / 2; i++)
        element[i] = element[2 * i];
    arraySize = (arraySize+1) / 2;
}

/*
创建一个新的线性表，该表包含了a和b中的所有元素，其中a和b的元素轮流出现，表中的首
元素为a中的第一个元素。在轮流排列元素时，如果某个表的元素用完了，则把另一个表的其
余元素依次添加在新表的后部。代码的复杂性应与两个输入表的长度呈线性比例关系。
归并后的线性表是调用对象*this
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

/*有序列表a,b，合并生成一个新的有序列表，新列表为(*this)*/
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

/*生成两个线性表a和b，a包含*this中索引为奇数的元素，b包含其余的元素*/
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
/*将数组的容量设置为capacity,并将数组的大小设置为capacity,只用于sparseMatrix类*/
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

/*input函数*/
template<class T>
istream& arrayList<T>::input(istream& in)
{
    int numberOfElement = 0;
    cout << "Please enter the number of elements:" << endl;
    while (!(in >> numberOfElement)) {//如果输入类型不匹配，则执行循环体
        in.clear(); // reset input设置标志位为有效
        while (in.get() != '\n') //删除没有用的输入
            continue; // get rid of bad input
        cout << "Please enter the number of elements:" << endl;
    }
    T inElement = 0;
    for (int i = 0; i < numberOfElement; i++)
    {
        cout << "Please enter the element: " << (i + 1) << endl;
        while (!(in >> inElement)) {//如果输入类型不匹配，则执行循环体
            in.clear(); // reset input设置标志位为有效
            while (in.get() != '\n') //删除没有用的输入
                continue;
            cout << "Please enter the element: " << (i + 1) << endl;
        }
        this->push_back(inElement);
    }
    return in;
}

/*重载<<操作符*/
template<class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
{
    x.output(out);
    return out;
}
/*重载>>操作符*/
template<typename T>
std::istream& operator>>(std::istream &os, arrayList<T>& m)
{
    m.input(os);
    return os;
}

/*重载[]操作符*/
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

/*重载==操作符*/
template<class T>
bool arrayList<T>::operator==(arrayList<T> right) const
{
    if (arraySize == right.size())
    {
        for (int i = 0; i < arraySize; i++)
        {
            if ((*this)[i] != right[i])
                return false;//遇到不相等直接返回false
        }
        return true;//都相等时返回true
    }
    else
        return false;
}

/*重载!=操作符*/
template<class T>
bool arrayList<T>::operator!=(arrayList<T> right) const
{
    if (arraySize == right.size())
    {
        for (int i = 0; i < arraySize; i++)
        {
            if ((*this)[i] != right[i])
                return true;//遇到不相等直接返回true
        }
        return false;//都相等时返回false
    }
    else
        return true;//元素数量不相等返回true
}

/*重载<操作符*/
//当left的长度小于右边时，比较left和right的元素;如所有left元素按字典顺序小于对应的right元素，则返回true，反之返回false
//当left的长度大于右边时，返回false
template<class T>
bool arrayList<T>::operator<(arrayList<T> right) const
{
    if (arraySize <= right.size())
    {
        for (int i = 0; i < arraySize; i++)
        {
            if ((*this)[i] >= right[i])
                return false;//遇到大于直接返回false
        }
        return true;//都小于时返回false
    }
    else
        return false;//元素数量不相等返回true
}

/*排序*/
/*功能：及时终止的冒泡排序,时间复杂度为n(n-1)/2*/
template<class T>
void arrayList<T>::bubbleSort()
{
    bool is_sorted = true;
    for (int i = arraySize; is_sorted && i > 1; i--)
    {
        is_sorted = false;//先设置为未交换，如果交换了就会被设置为交换。
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

/*按名次排序*/
template<class T>
void arrayList<T>::rankSort()
{
    int* r = new int[arraySize];
    //初始化名次
    for (int i = 0; i < arraySize; i++)
        r[i] = 0;
    //计算名次
    for (int i = arraySize - 1; i >= 0; i--) //从右往左拿出每个元素与其他元素比较
    {
        for (int j = 0; j < i ; j++)
        {
            if (*(element + i) > *(element + j))
                r[i]++;
            else
                r[j]++;
        }
    }
    //按名次排序
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

/*返回整个数组中最大元素的索引*/
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
/*选择排序*/
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
/*原地插入排序*/
template<class T>
void arrayList<T>::insertSort()
{
    int temp = 0;
    for (int i = 1; i < arraySize; i++)
    {
        temp = element[i];//存住要插入的元素
        //如果它前面的元素都大于该元素的话，就将它前面的元素后移一位
        int j = 0;
        for (j = i - 1; temp < element[j]; j--)
        {
            element[j + 1] = element[j];
        }
        element[j + 1] = temp;
    }
}

#endif