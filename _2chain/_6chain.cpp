/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����_6chain.hͷ�ļ��е����к���
*/
#include "_5arrayList.h"
#include "_6chain.h"
#include "_7arrayAndChain.h"
using std::cout;
using std::endl;

void chainTest()
{
	cout << endl << "**********************************chainTest()������ʼ*****************************************" << endl;
	cout << "���Գ�Ա����*********************************************" << endl;
	//���Թ��캯��
	cout << "���Թ��캯��******************" << endl;
	chain<int> data;
	//����insert()��Ա����
	cout << "����insert()��Ա����**********" << endl;
	data.insert(0, 99);
	data.insert(0, 88);
	data.insert(0, 77);
	data.insert(0, 66);
	//�������
	cout << "�������**********************" << endl;
	cout << "data = " << data << endl;//data = 66 77 88 99
	//���Ը��ƹ��캯��
	cout << "���Ը��ƹ��캯��**************" << endl;
	chain<int> data1(data);
	cout << "data1 = " << data1 << endl;//data1 = 66 77 88 99
	//����ʹ��arrayList��ʼ������Ĺ��캯��
	cout << "����ʹ��arrayList��ʼ������Ĺ��캯��" << endl;
	arrayList<int> arrayData2;
	arrayData2.push_back(1);
	arrayData2.push_back(2);
	arrayData2.push_back(3);
	chain<int> chainData1(arrayData2);
	cout << "chainData1 = " << chainData1 << endl;//chainData1 = 1 2 3
	//����get()��Ա����
	cout << "����get()��Ա����*************" << endl;
	cout << "data.get(0) = " << data.get(0) << endl;//data.get(0) = 66
	//����indexOf()��Ա����
	cout << "����indexOf()��Ա����*********" << endl;
	cout << "data.indexOf(99) = " << data.indexOf(99) << endl;//data.indexOf(99) = 3
	//����erase()��Ա����
	cout << "����erase()��Ա����***********" << endl;
	data.erase(0);
	cout << "data = " << data << endl;//data = 77 88 99
	//����clear()��Ա����
	cout << "����clear()��Ա����***********" << endl;
	data1.clear();
	cout << "data1 = " << data1 << endl;//data1 =
	//����push_back()��Ա����
	cout << "����push_back()��Ա����*******" << endl;
	data1.push_back(99);
	cout << "data1 = " << data1 << endl;//data1 = 99
	data.push_back(66);
	cout << "data = " << data << endl;//data = 77 88 99 66
	//����setSize()��Ա����
	cout << "����setSize()��Ա����*********" << endl;
	data.setSize(5);
	cout << "data = " << data << endl;//data = 77 88 99 66
	data.setSize(3);
	cout << "data = " << data << endl;//data = 77 88 99
	data.setSize(2);
	cout << "data = " << data << endl;//data = 77 88
	//����set()��Ա����
	cout << "����set()��Ա����*************" << endl;
	data.insert(0, 5);
	data.insert(0, 9);
	data.insert(0, 8);
	data.insert(0, 2);
	cout << "data = " << data << endl;//data = 2 8 9 5 77 88
	data.set(0, 99);
	cout << "data = " << data << endl;//data = 99 8 9 5 77 88
	cout << "����removeRange()��Ա����*****" << endl;
	data.removeRange(1, 3);
	cout << "data = " << data << endl;//data = 99 8 5 77 88
	cout << "����lastIndexOf()��Ա����*****" << endl;
	cout << "data.lastIndexOf(8) = " << data.lastIndexOf(8) << endl;//data.lastIndexOf(8) = 1
	cout << "data.lastIndexOf(2) = " << data.lastIndexOf(2) << endl;//data.lastIndexOf(2) = -1
	cout << "����swap()��Ա����************" << endl;
	chain<int> data3(data1);
	chain<int> data4(data);
	cout << "data3 = " << data3 << endl;//data3 = 99
	cout << "data4 = " << data4 << endl;//data4 = 99 8 5 77 88
	data3.swap(data4);
	cout << "data3 = " << data3 << endl;//data4 = 99 8 5 77 88
	cout << "data4 = " << data4 << endl;//data4 = 99
	cout << "����toArray()��Ա����*********" << endl;
	arrayList<int> arrayData3;
	cout << "arrayData3 = " << arrayData3 << endl;//arrayData3 =
	data3.toArray(arrayData3);
	cout << "arrayData3 = " << arrayData3 << endl;//arrayData3 = 99 8 5 77 88
	cout << "����leftShift()��Ա����*********" << endl;
	cout << "data3 = " << data3 << endl;//data3 = 5 77 88 10 66
	data3.leftShift(2);
	cout << "data3 = " << data3 << endl;//data3 = 5 77 88
	cout << "����reverse()��Ա����***********" << endl;
	data3.push_back(10);
	data3.push_back(66);
	cout << "data3 = " << data3 << endl;//data3 = 5 77 88 10 66
	data3.reverse();
	cout << "data3 = " << data3 << endl;//data3 = 66 10 88 77 5
	cout << "����meld()��Ա����**************" << endl;
	data4.push_back(68);
	chain<int> data5;
	chain<int> data6(data3);
	chain<int> data7(data4);
	chain<int> data8(data3);
	cout << "data3 = " << data3 << endl;//data3 = 66 10 88 77 5
	cout << "data4 = " << data4 << endl;//data4 = 99 68
	data5.meld(data3, data4);
	cout << "data5.meld(data3, data4)֮��**" << endl;
	cout << "data3 = " << data3 << endl;//data3 =
	cout << "data4 = " << data4 << endl;//data4 =
	cout << "data5 = " << data5 << endl << endl;//data5 = 66 99 10 68 88 77 5

	cout << "data7 = " << data7 << endl;//data7 = 99 68
	cout << "data6 = " << data6 << endl;//data6 = 66 10 88 77 5
	data5.meld(data7, data6);
	cout << "data5.meld(data7, data6)֮��**" << endl;
	cout << "data7 = " << data7 << endl;//data7 =
	cout << "data6 = " << data6 << endl;//data6 =
	cout << "data5 = " << data5 << endl << endl;//data5 = 99 66 68 10 88 77 5

	chain<int> data9;
	cout << "data8 = " << data8 << endl;//data8 = 66 10 88 77 5
	cout << "data9 = " << data9 << endl;//data9 =
	data5.meld(data8, data9);
	cout << "data5.meld(data8, data9)֮��**" << endl;
	cout << "data8 = " << data8 << endl;//data8 =
	cout << "data8.size() = " << data8.size() << endl;//data8.size = 0
	cout << "data9 = " << data9 << endl;//data9 =
	cout << "data9.size() = " << data9.size() << endl;//data9.size = 0
	cout << "data5 = " << data5 << endl;//data5 = 66 10 88 77 5
	cout << "data5.size() = " << data5.size() << endl;//data5.size() = 5
	cout << "����merge()��Ա����*************" << endl;
	chain<int> data10(data5);
	data10.erase(0);
	chain<int> data11;
	cout << "data5 = " << data5 << endl;//data5 = 5 10 66 77 88
	cout << "data10 = " << data10 << endl;//data10 = 10 66 77 88
	cout << "data11 = " << data11 << endl;//data11 =
	data11.merge(data5, data10);
	cout << "data11.merge(data5, data10)֮��" << endl;
	cout << "data5 = " << data5 << endl;//data5 =
	cout << "data5.size() = " << data5.size() << endl;//data5.size() = 0
	cout << "data10 = " << data10 << endl;//data10 =
	cout << "data10.size() = " << data10.size() << endl;//data10.size() = 0
	cout << "data11 = " << data11 << endl;//data11 = 5 10 10 66 66 77 77 88 88
	cout << "data11.size() = " << data11.size() << endl;//data11.size() = 9
	cout << "����split()��Ա����*************" << endl;
	cout << "����circularShift()��Ա����*****" << endl;
	data11.split(data5, data10);
	cout << "data5 = " << data5 << endl;//data5 = 5 10 66 77 88
	cout << "data5.size() = " << data5.size() << endl;//data5.size() = 5
	cout << "data10 = " << data10 << endl;//data10 = 10 66 77 88
	cout << "data10.size() = " << data10.size() << endl;//data10.size() = 4
	cout << "data11 = " << data11 << endl;//data11 =
	cout << "data11.size() = " << data11.size() << endl;//data11.size() = 0
	cout << "����circularShift()��Ա����*****" << endl;
	data5.circularShift(2);
	cout << "data5 = " << data5 << endl;//data5 = 66 77 88 5 10

	cout << endl << "���ز�����************************************************" << endl;
	cout << "����[]������******************" << endl;
	cout << "data = " << data << endl;
	cout << "data[0] = " << data[0] << endl;//data[0] = 99
	cout << "data[1] = " << data[1] << endl;//data[1] = 8
	cout << "data[2] = " << data[2] << endl;//data[2] = 5
	data[0] = 88;
	cout << "data = " << data << endl;//data = 88 8 5 77 88
	cout << "����==������******************" << endl;
	chain<int> data2(data);
	cout << "data2 = " << data2 << endl;//data2 = 88 8 5 77 88
	cout << "data = " << data << endl;//data = 88 8 5 77 88
	cout << "data1 = " << data1 << endl;//data1 = 99
	cout << "(data2 == data) = " << (data2 == data) << endl;//(data2 == data) = 1
	cout << "(data2 == data1) = " << (data2 == data1) << endl;//(data2 == data1) = 0
	data2[4] = 9;
	cout << "data2 = " << data2 << endl;//data2 = 88 8 5 77 9
	cout << "data = " << data << endl;//data = 88 8 5 77 88
	cout << "(data2 == data) = " << (data2 == data) << endl;//(data2 == data) = 0
	cout << "����!=������******************" << endl;
	cout << "data2 = " << data2 << endl;//data2 = 88 8 5 77 9
	cout << "data = " << data << endl;//data = 88 8 5 77 88
	cout << "data1 = " << data1 << endl;//data1 = 99
	cout << "(data2 != data) = " << (data2 != data) << endl;//(data2 != data) = 1
	cout << "(data2 != data1) = " << (data2 != data1) << endl;//(data2 != data1) = 1
	data2[4] = 88;
	cout << "data2 = " << data2 << endl;//data2 = 88 8 5 77 88
	cout << "data = " << data << endl;//data = 88 8 5 77 88
	cout << "(data2 != data) = " << (data2 != data) << endl;//(data2 != data) = 0
	cout << "����<������*******************" << endl;
	cout << "data2 = " << data2 << endl;//data2 = 88 8 5 77 88
	cout << "data = " << data << endl;//data = 88 8 5 77 88
	data1[0] = 66;
	cout << "data1 = " << data1 << endl;//data1 = 66
	cout << "(data2 < data) = " << (data2 < data) << endl;//(data2 < data) = 0
	cout << "(data1 < data2) = " << (data1 < data2) << endl;//(data1 < data2) = 1
	data2[0] = 1;
	data2[1] = 1;
	data2[2] = 1;
	data2[3] = 1;
	data2[4] = 1;
	cout << "data2 = " << data2 << endl;//data2 = 1 1 1 1 1
	cout << "data = " << data << endl;//data = 88 8 5 77 88
	cout << "(data2 < data) = " << (data2 < data) << endl;//(data2 < data) = 1

	cout << endl << "���Էǳ�Ա����******************************************" << endl;
	arrayList<int> arrayData;
	arrayData.push_back(9);
	arrayData.push_back(999);
	arrayData.push_back(99);
	cout << "����arrayToChain()����********" << endl;
	cout << "arrayData = " << arrayData << endl;//arrayData = 9 999 99
	chain<int> chainData(arrayToChain(arrayData));
	cout << "chainData = " << chainData << endl;//chainData = 9 999 99
	cout << "����chainToArray()����********" << endl;
	arrayList<int> arrayData1(chainToArray(chainData));
	arrayData1.push_back(88);
	cout << "arrayData1 = " << arrayData1 << endl;//arrayData1 = 9 999 99 88
	cout << "����meld()����****************" << endl;
	chain<int> chainData3(arrayToChain(arrayData));
	chain<int> chainData4;
	cout << "chainData = " << chainData << endl;//chainData = 9 999 99
	cout << "chainData3 = " << chainData3 << endl;//chainData3 = 9 999 99
	meld(chainData, chainData3, chainData4);
	cout << "chainData4 = " << chainData4 << endl << endl;//chainData4 = 9 9 999 999 99 99
	chainData3.insert(0, 68);
	chainData3.insert(0, 98);
	cout << "chainData = " << chainData << endl;//chainData = 9 999 99
	cout << "chainData3 = " << chainData3 << endl;//chainData3 = 98 68 9 999 99
	meld(chainData, chainData3, chainData4);
	cout << "chainData4 = " << chainData4 << endl<<endl;//chainData4 = 9 98 999 68 99 9 999 99
	meld(chainData3, chainData, chainData4);
	cout << "chainData4 = " << chainData4 << endl<<endl;//chainData4 = 98 9 68 999 9 99 999 99
	chain<int> chainData5;
	meld(chainData3, chainData5, chainData4);
	cout << "chainData3 = " << chainData3 << endl;//chainData3 = 98 68 9 999 99
	cout << "chainData5 = " << chainData5 << endl;//chainData5 =
	cout << "chainData4 = " << chainData4 << endl << endl;//chainData4 = 98 68 9 999 99
	meld(chainData5, chainData3, chainData4);
	cout << "chainData5 = " << chainData5 << endl;//chainData5 =
	cout << "chainData3 = " << chainData3 << endl;//chainData3 = 98 68 9 999 99
	cout << "chainData4 = " << chainData4 << endl << endl;//chainData4 = 98 68 9 999 99
	cout << "����split()����**************" << endl;
	chain<int> chainData6;
	chain<int> chainData7;
	cout << "chainData6 = " << chainData6 << endl;//chainData6 =
	cout << "chainData7 = " << chainData7 << endl;//chainData7 =
	cout << "chainData4 = " << chainData4 << endl;//chainData4 = 98 68 9 999 99
	split(chainData6, chainData7, chainData4);
	cout << "split(chainData6, chainData7, chainData4)֮��" << endl;
	cout << "chainData6 = " << chainData6 << endl;//chainData6 =
	cout << "chainData6.size() = " << chainData6.size() << endl;//chainData6 =
	cout << "chainData7 = " << chainData7 << endl;//chainData7 =
	cout << "chainData7.size() = " << chainData7.size() << endl;//chainData7 =
	cout << "chainData4 = " << chainData4 << endl;//chainData4 = 98 68 9 999 99
	cout << "chainData4.size() = " << chainData4.size() << endl;//chainData7 =

	cout << endl << "����****************************************************" << endl;
	cout << "����bubbleSort()��Ա����********" << endl;
	data5.bubbleSort();
	cout << "data5 = " << data5 << endl;//data5 = 5 10 66 77 88
	cout << "����rankSort()��Ա����**********" << endl;
	data5.reverse();
	cout << "data5 = " << data5 << endl;//data5 = 5 10 66 77 88
	data5.rankSort();
	cout << "data5 = " << data5 << endl;//data5 = 5 10 66 77 88

	cout << "maxOfList()*******************************" << endl;
	cout << "data5.maxOfList() = " << data5.maxOfList() << endl;//data5.maxOfList() = 4
	cout << "selectionSort()����***********************" << endl;
	data5.reverse();
	cout << "data5 = " << data5 << endl;//data5 = 88 77 10 10 5
	data5.selectionSort();
	cout << "data5 = " << data5 << endl;//data5 = 5 10 10 77 88
	cout << "insertSort()����**************************" << endl;
	data5.reverse();
	data5.insert(1, 99);
	cout << "data5 = " << data5 << endl;//data5 = 88 99 77 10 10 5
	data5.insertSort();
	cout << "data5 = " << data5 << endl;//data5 = 5 10 10 77 88 99
	cout << "binSort()����****************************" << endl;
	chain<int> data12;
	data12.push_back(0);
	data12.push_back(5);
	data12.push_back(3);
	data12.push_back(4);
	data12.push_back(2);
	data12.push_back(5);
	cout << "data12 = " << data12 << endl;//data12 = 0 5 3 4 2 5
	data12.binSort(5);
	cout << "data12 = " << data12 << endl;//data12 = 0 2 3 4 5 5
	cout << "baseBinSort()����************************" << endl;
	chain<int> data13;
	data13.push_back(216);
	data13.push_back(521);
	data13.push_back(425);
	data13.push_back(116);
	data13.push_back(91);
	data13.push_back(515);
	data13.push_back(124);
	data13.push_back(34);
	data13.push_back(96);
	data13.push_back(24);
	cout << "data13 = " << data13 << endl;
	data13.baseBinSort(9);
	cout << "data13 = " << data13 << endl;

	cout << endl << "�����������***********************************************************************" << endl;
	cout << "cin>>*************************************" << endl;
	chain<int> cindata;
	cin >> cindata;
	cout << "cindata = " << cindata << endl;

	cout << "**********************************chainTest()��������*****************************************" << endl;
}