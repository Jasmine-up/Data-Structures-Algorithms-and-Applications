/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			测试_5arrayList.h头文件中的所有函数
*/
#include<iostream>
#include "_3sorting.h"
#include "_5arrayList.h"
#include "_6chain.h"
#include <iomanip>

using std::cout;
using std::endl;
using std::ios_base;
using std::boolalpha;

void arrayListTest()
{
    cout << endl << "********************************arrayListTest()***************************************" << endl;
    cout << endl << "成员函数测试********************************************************************" << endl;
    //测试使用chain初始化数组的构造函数
    cout << "测试使用chain初始化数组的构造函数***********" << endl;
    chain<int> chainData;
    chainData.insert(0, 99);
    chainData.insert(1, 22);
    chainData.insert(2, 8);
    cout << "chainData = " << chainData << endl;//chainData = 99 22 8
    arrayList<int> arrayData(chainData);
    cout << "arrayData = " << arrayData << endl;//arrayData = 99 22 8
    arrayList<int> data(10);
    cout << "插入元素8***********************************" << endl;
    data.insert(0, 8);
    cout << "data.capacity() = " << data.capacity() << endl;//data.capacity() = 10
    cout << "data.size() = " << data.size() << endl;//data.size() = 1
    cout << "获取第一个元素******************************" << endl;
    cout << "data.get(0) = " << data.get(0) << endl;//data.get(0) = 8
    cout << "移除第一个元素******************************" << endl;
    data.erase(0);
    cout << "此时无元素**********************************" << endl;
    cout << "data.size() = " << data.size() << endl;//data.size() = 0
    cout << "data.capacity() = " << data.capacity() << endl;//data.capacity() = 1
    cout << "插入6个元素*********************************" << endl;
    data.insert(0, 3);
    data.insert(0, 4);
    data.insert(0, 5);
    data.insert(0, 6);
    data.insert(0, 8);
    data.insert(5, 1);
    cout << "data.size() = " << data.size() << endl;//data.size() = 6
    cout << "data.capacity() = " << data.capacity() << endl;//data.capacity() = 8
    cout << "data.indexOf(1) = " << data.indexOf(1) << endl;//data.indexOf(1) = 5
    cout << data << endl;//8 6 5 4 3 1
    cout << "插满元素并将数组长度设置为10***************" << endl;
    data.insert(2, 99, 10);
    data.insert(2, 99, 10);
    data.insert(6, 99, 10);
    cout << "data.size() = " << data.size() << endl;//data.size() = 9
    cout << "data.capacity() = " << data.capacity() << endl;//data.capacity() = 10
    cout << data << endl;//8 6 99 99 5 4 99 3 1
    cout << "入栈元素99*********************************" << endl;
    data.push_back(99);
    cout << data << endl;//8 6 99 99 5 4 99 3 1 99
    cout << "出栈元素99*********************************" << endl;
    int popback = data.pop_back();
    cout << "popback = " << popback << endl;//popback = 99
    cout << data << endl;//8 6 99 99 5 4 99 3 1
    cout << "生成新数组data3****************************" << endl;
    arrayList<int> data3(2);
    data3.push_back(99);
    data3.push_back(99);
    cout << "data = " << data << endl;//data = 8 6 99 99 5 4 99 3 1
    cout << "data3 = " << data3 << endl;//data3 = 99 99
    cout << "交换数组data和data3************************" << endl;
    data.swap(data3);
    cout << "data = " << data << endl;//data = 99 99
    cout << "data3 = " << data3 << endl;//data3 = 8 6 99 99 5 4 99 3 1
    cout << "函数reserve()******************************" << endl;
    data3.reserve(12);
    cout << "data3.size() = " << data3.size() << endl;//data3.size() = 9
    cout << "data3.capacity() = " << data3.capacity() << endl;//data3.capacity() = 12
    cout << "data3 = " << data3 << endl;//data3 = 8 6 99 99 5 4 99 3 1
    cout << "函数set()**********************************" << endl;
    data3.set(0, 99);
    cout << "data3 = " << data3 << endl;//data3 = 99 6 99 99 5 4 99 3 1
    cout << "交换数组data和data3************************" << endl;
    data.swap(data3);
    cout << "data = " << data << endl;//data = 199 6 99 99 5 4 99 3 1
    cout << "data3 = " << data3 << endl;//data3 = 99 99
    cout << "清空数组data3******************************" << endl;
    data3.clear();
    cout << "data3.size() = " << data3.size() << endl;//data3.size() = 0
    cout << "data3.capacity() = " << data3.capacity() << endl;//data3.capacity() = 2
    cout << "data3 = " << data3 << endl;//data3 =
    cout << "删除数组data索引为[0,2]的元素**************" << endl;
    data.removeRange(0, 2);
    cout << "data.size() = " << data.size() << endl;//data.size() = 6
    cout << "data.capacity() = " << data.capacity() << endl;//data.capacity() = 12
    cout << "data = " << data << endl;//data = 99 5 4 99 3 1
    cout << "指定元素最后出现的索引*********************" << endl;
    cout << "data.lastIndexOf(99) = " << data.lastIndexOf(99) << endl;//data.lastIndexOf(99) = 3
    cout << "data.lastIndexOf(1) = " << data.lastIndexOf(1) << endl;//data.lastIndexOf(1) = 5
    cout << "data.lastIndexOf(4) = " << data.lastIndexOf(4) << endl;//data.lastIndexOf(4) = 2
    cout << "原地颠倒线性表元素*************************" << endl;
    data.reverse();
    cout << "data = " << data << endl;//data = 1 3 99 4 5 99
    cout << "data数组左移2位****************************" << endl;
    data.leftShift(2);
    cout << "data = " << data << endl;//data = 99 4 5 99
    cout << "data数组循环左移2位************************" << endl;
    data.circularShift(2);
    cout << "data = " << data << endl;//data = 5 99 99 4
    data.insert(0, 5);
    data.insert(0, 3);
    data.insert(0, 2);
    data.insert(0, 8);
    data.insert(0, 9);
    data.insert(0, 6);
    cout << "data数组隔元素删除元素*********************" << endl;
    cout << "data原 = " << data << endl;//data原 = 6 9 8 2 3 5 5 99 99 4
    data.half();
    cout << "data后 = " << data << endl;//data后 = 6 8 3 5 99
    cout << "合并两数组的元素***************************" << endl;
    data3.insert(0, 5);
    data3.insert(0, 3);
    data3.insert(0, 2);
    data3.insert(0, 8);
    data3.insert(0, 9);
    data3.insert(0, 6);
    data.insert(0, 3);
    data.insert(0, 2);
    cout << "data = " << data << endl;//data = 2 3 6 8 3 5 99
    cout << "data3 = " << data3 << endl;//data3 = 6 9 8 2 3 5
    arrayList<int> data4(10);
    data4.meld(data, data3);
    cout << "data4.meld(data,data3) = " << data4 << endl;//data4.meld(data,data3) = 2 6 3 9 6 8 8 2 3 3 5 5 99
    cout << "合并两有序数组****************************" << endl;
    data4.merge(data, data3);
    cout << "data4.merge(data,data3) = " << data4 << endl;//data4.merge(data,data3) = 2 3 6 6 8 3 5 9 8 2 3 5 99
    cout << "按奇偶索引拆分数组************************" << endl;
    data4.split(data, data3);
    cout << "data = " << data << endl;//data = 2 6 8 5 8 3 99
    cout << "data3 = " << data3 << endl;//data3 = 3 6 3 9 2 5

    cout << endl << "迭代器*************************************************************************" << endl;
    cout << "it指向data.begin()**************" << endl;
    arrayList<int>::iterator it = data.begin();
    cout << "*it = " << *it << endl;//*it = 2
    cout << "it后++之后**********************" << endl;
    it++;
    cout << "*it = " << *it << endl;//*it = 6
    cout << "it前++之后**********************" << endl;
    ++it;
    cout << "*it = " << *it << endl;//*it = 8
    cout << "it后--之后**********************" << endl;
    it--;
    cout << "*it = " << *it << endl;//*it = 6
    cout << "it前--之后**********************" << endl;
    --it;
    cout << "*it = " << *it << endl;//*it = 2
    cout << "it指向data.end()****************" << endl;
    it = data.end();
    cout << "*it = " << *it << endl;//*it = 99
    cout << "it1指向data.end()***************" << endl;
    arrayList<int>::iterator it1 = data.begin();
    cout.setf(ios_base::boolalpha);//可以显示为true或false
    cout << "(it1 == it) = " << (it1 == it) << endl;//(it1 == it) = false
    cout << "(it1 != it) = " << (it1 != it) << endl;//(it1 != it) = true

    cout << endl << "重载操作符*********************************************************************" << endl;
    cout << "测试[]操作符*********************" << endl;
    cout << "data[2] = " << data[2] << endl;//data[2] = 8
    data[2] = 9;
    arrayList<int> data1(data);
    //data1.erase(0);
    cout << "data = " << data << endl;//data = 2 6 9 5 8 3 99
    cout << "data1 = " << data1 << endl;//data1 = 2 6 9 5 8 3 99
    cout << "测试==操作符*********************" << endl;
    if (data == data1)
        cout << "data == data1!" << endl;//data == data1!
    cout << "测试!=操作符*********************" << endl;
    if (data != data1)
        cout << "data != data1!" << endl;
    cout << "测试<操作符**********************" << endl;
    if (data < data1)
        cout << "data < data1!" << endl;//data2 < data!
    arrayList<int> data2(2);
    data2.insert(0, 1);
    data2.insert(0, 1);
    if (data2 < data)
        cout << "data2 < data!" << endl;

    cout << endl << "排序***************************************************************************" << endl;
    cout << "冒泡排序**********************************" << endl;
    data.bubbleSort();
    data3.bubbleSort();
    cout << "data = " << data << endl;//data = 2 3 5 6 8 9 99
    cout << "data3 = " << data3 << endl;//data3 = 2 3 3 5 6 9
    cout << "rankSort()排序****************************" << endl;
    data.reverse();
    cout << "data = " << data << endl;
    data.rankSort();
    cout << "data = " << data << endl;
    cout << "indexOfMax()******************************" << endl;
    cout << "data.indexOfMax() = " << data.indexOfMax() << endl;
    cout << "selectionSort()排序***********************" << endl;
    data.reverse();
    cout << "data = " << data << endl;
    data.selectionSort();
    cout << "data = " << data << endl;
    cout << "insertSort()排序**************************" << endl;
    data.reverse();
    cout << "data = " << data << endl;
    data.insertSort();
    cout << "data = " << data << endl;
    cout << endl << "友元函数***********************************************************************" << endl;
    cout << "cin>>*************************************" << endl;
    arrayList<int> cindata;
    cin >> cindata;
    cout << "cindata = " << cindata << endl;
    cindata.reverse();
    cout << "reversedata = " << cindata << endl;

    cout << endl << "********************************arrayListTest()***************************************" << endl;
}
