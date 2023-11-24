/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��24��11��16��
Last Version:			V1.0
Descriptions:			��ϣ��---��ʽɢ��(����洢)---cpp�ļ�
// hash table using sorted chains and division
// implements all dictionary methods
*/
#include <iostream>
#include "_26hashChains.h"
using namespace std;

void hashChainsTest()
{
    cout << endl << "*********************************hashChainsTest()������ʼ*************************************" << endl;

    hashChains<int, int> a;
    //������������
    cout << endl << "������Ԫ����*******************************************" << endl;
    cout << "�������************************" << endl;
    cin >> a;
    cout << "hashChains a is:" << a;
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
    cout << "hashChains a is:" << a;
    cout << "erase()*************************" << endl;
    a.erase(1);
    cout << "hashChains a is:" << a;
    cout << "*********************************hashChainsTest()��������*************************************" << endl;
}
