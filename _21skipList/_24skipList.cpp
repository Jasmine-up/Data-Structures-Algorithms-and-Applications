/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��23��10��18��
Last Version:			V1.0
Descriptions:			������---��������Ǽ����������ʱ���Ǽ��������ھ��Ǽ���---cpp�ļ�
*/
#include <iostream>
#include "_24skipList.h"
using namespace std;

void skipListTest()
{
    cout << endl << "*********************************skipListTest()������ʼ***************************************" << endl;
    //������������
    cout << endl << "�����������*******************************************" << endl;
    cout << "�������************************" << endl;
    skipList<int, int> a(20);
    cin >> a;
    cout << "The dictionary is " << a;
    cout << endl << "���Գ�Ա����*******************************************" << endl;
    cout << "empty()*************************" << endl;
    cout << "a.empty() = " << a.empty() << endl;
    cout << "size()**************************" << endl;
    cout << "a.size() = " << a.size() << endl;
    cout << "find()**************************" << endl;
    cout << "Element associated with 1 is " << a.find(1)->second << endl;
    cout << "insert()************************" << endl;
    pair<const int, int> insertData(4, 4);
    a.insert(insertData);
    cout << "The dictionary is " << a;
    cout << "erase()*************************" << endl;
    a.erase(1);
    cout << "The dictionary is " << a;
    cout << "deleteFront()*******************" << endl;
    a.deleteFront();
    cout << "The dictionary is " << a;
    cout << "deleteBack()********************" << endl;
    a.deleteBack();
    cout << "The dictionary is " << a;

    cout << "**********************************skipListTest()��������**************************************" << endl;
}
