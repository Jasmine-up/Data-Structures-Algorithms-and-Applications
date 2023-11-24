/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��23��10��18��
Last Version:			V1.0
Descriptions:			��ϣ��(����洢)---ʹ������̽���cpp�ļ�
*/
#include <iostream>
#include "_25hashTable.h"
using namespace std;

void hashTableTest()
{
    cout << endl << "*********************************hashTableTest()������ʼ**************************************" << endl;
    hashTable<int, int> a;
    //������������
    cout << endl << "������Ԫ����*******************************************" << endl;
    cout << "�������************************" << endl;
    cin >> a;
    cout << "hashTable a is:" << a;
    cout << endl << "���Գ�Ա����*******************************************" << endl;
    cout << "empty()*************************" << endl;
    cout << "a.empty() = " << a.empty() << endl;
    cout << "size()**************************" << endl;
    cout << "a.size() = " << a.size() << endl;
    cout << "find()**************************" << endl;
    cout << "a.find(1)->second = " << a.find(1)->second << endl;
    cout << "insert()************************" << endl;
    pair<const int, int> insertData(3, 4);
    a.insert(insertData);
    cout << "hashTable a is:" << a;
    cout << "erase()*************************" << endl;
    a.erase(2);
    cout << "hashTable a is:" << a;
    cout << "*********************************hashTableTest()��������**************************************" << endl;
}
