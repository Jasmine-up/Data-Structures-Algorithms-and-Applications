/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����_5arrayList.hͷ�ļ��е����к���
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
    cout << endl << "��Ա��������********************************************************************" << endl;
    //����ʹ��chain��ʼ������Ĺ��캯��
    cout << "����ʹ��chain��ʼ������Ĺ��캯��***********" << endl;
    chain<int> chainData;
    chainData.insert(0, 99);
    chainData.insert(1, 22);
    chainData.insert(2, 8);
    cout << "chainData = " << chainData << endl;//chainData = 99 22 8
    arrayList<int> arrayData(chainData);
    cout << "arrayData = " << arrayData << endl;//arrayData = 99 22 8
    arrayList<int> data(10);
    cout << "����Ԫ��8***********************************" << endl;
    data.insert(0, 8);
    cout << "data.capacity() = " << data.capacity() << endl;//data.capacity() = 10
    cout << "data.size() = " << data.size() << endl;//data.size() = 1
    cout << "��ȡ��һ��Ԫ��******************************" << endl;
    cout << "data.get(0) = " << data.get(0) << endl;//data.get(0) = 8
    cout << "�Ƴ���һ��Ԫ��******************************" << endl;
    data.erase(0);
    cout << "��ʱ��Ԫ��**********************************" << endl;
    cout << "data.size() = " << data.size() << endl;//data.size() = 0
    cout << "data.capacity() = " << data.capacity() << endl;//data.capacity() = 1
    cout << "����6��Ԫ��*********************************" << endl;
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
    cout << "����Ԫ�ز������鳤������Ϊ10***************" << endl;
    data.insert(2, 99, 10);
    data.insert(2, 99, 10);
    data.insert(6, 99, 10);
    cout << "data.size() = " << data.size() << endl;//data.size() = 9
    cout << "data.capacity() = " << data.capacity() << endl;//data.capacity() = 10
    cout << data << endl;//8 6 99 99 5 4 99 3 1
    cout << "��ջԪ��99*********************************" << endl;
    data.push_back(99);
    cout << data << endl;//8 6 99 99 5 4 99 3 1 99
    cout << "��ջԪ��99*********************************" << endl;
    int popback = data.pop_back();
    cout << "popback = " << popback << endl;//popback = 99
    cout << data << endl;//8 6 99 99 5 4 99 3 1
    cout << "����������data3****************************" << endl;
    arrayList<int> data3(2);
    data3.push_back(99);
    data3.push_back(99);
    cout << "data = " << data << endl;//data = 8 6 99 99 5 4 99 3 1
    cout << "data3 = " << data3 << endl;//data3 = 99 99
    cout << "��������data��data3************************" << endl;
    data.swap(data3);
    cout << "data = " << data << endl;//data = 99 99
    cout << "data3 = " << data3 << endl;//data3 = 8 6 99 99 5 4 99 3 1
    cout << "����reserve()******************************" << endl;
    data3.reserve(12);
    cout << "data3.size() = " << data3.size() << endl;//data3.size() = 9
    cout << "data3.capacity() = " << data3.capacity() << endl;//data3.capacity() = 12
    cout << "data3 = " << data3 << endl;//data3 = 8 6 99 99 5 4 99 3 1
    cout << "����set()**********************************" << endl;
    data3.set(0, 99);
    cout << "data3 = " << data3 << endl;//data3 = 99 6 99 99 5 4 99 3 1
    cout << "��������data��data3************************" << endl;
    data.swap(data3);
    cout << "data = " << data << endl;//data = 199 6 99 99 5 4 99 3 1
    cout << "data3 = " << data3 << endl;//data3 = 99 99
    cout << "�������data3******************************" << endl;
    data3.clear();
    cout << "data3.size() = " << data3.size() << endl;//data3.size() = 0
    cout << "data3.capacity() = " << data3.capacity() << endl;//data3.capacity() = 2
    cout << "data3 = " << data3 << endl;//data3 =
    cout << "ɾ������data����Ϊ[0,2]��Ԫ��**************" << endl;
    data.removeRange(0, 2);
    cout << "data.size() = " << data.size() << endl;//data.size() = 6
    cout << "data.capacity() = " << data.capacity() << endl;//data.capacity() = 12
    cout << "data = " << data << endl;//data = 99 5 4 99 3 1
    cout << "ָ��Ԫ�������ֵ�����*********************" << endl;
    cout << "data.lastIndexOf(99) = " << data.lastIndexOf(99) << endl;//data.lastIndexOf(99) = 3
    cout << "data.lastIndexOf(1) = " << data.lastIndexOf(1) << endl;//data.lastIndexOf(1) = 5
    cout << "data.lastIndexOf(4) = " << data.lastIndexOf(4) << endl;//data.lastIndexOf(4) = 2
    cout << "ԭ�صߵ����Ա�Ԫ��*************************" << endl;
    data.reverse();
    cout << "data = " << data << endl;//data = 1 3 99 4 5 99
    cout << "data��������2λ****************************" << endl;
    data.leftShift(2);
    cout << "data = " << data << endl;//data = 99 4 5 99
    cout << "data����ѭ������2λ************************" << endl;
    data.circularShift(2);
    cout << "data = " << data << endl;//data = 5 99 99 4
    data.insert(0, 5);
    data.insert(0, 3);
    data.insert(0, 2);
    data.insert(0, 8);
    data.insert(0, 9);
    data.insert(0, 6);
    cout << "data�����Ԫ��ɾ��Ԫ��*********************" << endl;
    cout << "dataԭ = " << data << endl;//dataԭ = 6 9 8 2 3 5 5 99 99 4
    data.half();
    cout << "data�� = " << data << endl;//data�� = 6 8 3 5 99
    cout << "�ϲ��������Ԫ��***************************" << endl;
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
    cout << "�ϲ�����������****************************" << endl;
    data4.merge(data, data3);
    cout << "data4.merge(data,data3) = " << data4 << endl;//data4.merge(data,data3) = 2 3 6 6 8 3 5 9 8 2 3 5 99
    cout << "����ż�����������************************" << endl;
    data4.split(data, data3);
    cout << "data = " << data << endl;//data = 2 6 8 5 8 3 99
    cout << "data3 = " << data3 << endl;//data3 = 3 6 3 9 2 5

    cout << endl << "������*************************************************************************" << endl;
    cout << "itָ��data.begin()**************" << endl;
    arrayList<int>::iterator it = data.begin();
    cout << "*it = " << *it << endl;//*it = 2
    cout << "it��++֮��**********************" << endl;
    it++;
    cout << "*it = " << *it << endl;//*it = 6
    cout << "itǰ++֮��**********************" << endl;
    ++it;
    cout << "*it = " << *it << endl;//*it = 8
    cout << "it��--֮��**********************" << endl;
    it--;
    cout << "*it = " << *it << endl;//*it = 6
    cout << "itǰ--֮��**********************" << endl;
    --it;
    cout << "*it = " << *it << endl;//*it = 2
    cout << "itָ��data.end()****************" << endl;
    it = data.end();
    cout << "*it = " << *it << endl;//*it = 99
    cout << "it1ָ��data.end()***************" << endl;
    arrayList<int>::iterator it1 = data.begin();
    cout.setf(ios_base::boolalpha);//������ʾΪtrue��false
    cout << "(it1 == it) = " << (it1 == it) << endl;//(it1 == it) = false
    cout << "(it1 != it) = " << (it1 != it) << endl;//(it1 != it) = true

    cout << endl << "���ز�����*********************************************************************" << endl;
    cout << "����[]������*********************" << endl;
    cout << "data[2] = " << data[2] << endl;//data[2] = 8
    data[2] = 9;
    arrayList<int> data1(data);
    //data1.erase(0);
    cout << "data = " << data << endl;//data = 2 6 9 5 8 3 99
    cout << "data1 = " << data1 << endl;//data1 = 2 6 9 5 8 3 99
    cout << "����==������*********************" << endl;
    if (data == data1)
        cout << "data == data1!" << endl;//data == data1!
    cout << "����!=������*********************" << endl;
    if (data != data1)
        cout << "data != data1!" << endl;
    cout << "����<������**********************" << endl;
    if (data < data1)
        cout << "data < data1!" << endl;//data2 < data!
    arrayList<int> data2(2);
    data2.insert(0, 1);
    data2.insert(0, 1);
    if (data2 < data)
        cout << "data2 < data!" << endl;

    cout << endl << "����***************************************************************************" << endl;
    cout << "ð������**********************************" << endl;
    data.bubbleSort();
    data3.bubbleSort();
    cout << "data = " << data << endl;//data = 2 3 5 6 8 9 99
    cout << "data3 = " << data3 << endl;//data3 = 2 3 3 5 6 9
    cout << "rankSort()����****************************" << endl;
    data.reverse();
    cout << "data = " << data << endl;
    data.rankSort();
    cout << "data = " << data << endl;
    cout << "indexOfMax()******************************" << endl;
    cout << "data.indexOfMax() = " << data.indexOfMax() << endl;
    cout << "selectionSort()����***********************" << endl;
    data.reverse();
    cout << "data = " << data << endl;
    data.selectionSort();
    cout << "data = " << data << endl;
    cout << "insertSort()����**************************" << endl;
    data.reverse();
    cout << "data = " << data << endl;
    data.insertSort();
    cout << "data = " << data << endl;
    cout << endl << "��Ԫ����***********************************************************************" << endl;
    cout << "cin>>*************************************" << endl;
    arrayList<int> cindata;
    cin >> cindata;
    cout << "cindata = " << cindata << endl;
    cindata.reverse();
    cout << "reversedata = " << cindata << endl;

    cout << endl << "********************************arrayListTest()***************************************" << endl;
}
