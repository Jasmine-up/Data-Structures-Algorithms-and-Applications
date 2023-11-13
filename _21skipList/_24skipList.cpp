/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月23日10点18分
Last Version:			V1.0
Descriptions:			跳表类---随机决定是几级，插入的时候是几级，现在就是几级---cpp文件
*/
#include <iostream>
#include "_24skipList.h"
using namespace std;

void skipListTest()
{
    cout << endl << "*********************************skipListTest()函数开始***************************************" << endl;
    //测试输入和输出
    cout << endl << "测试输入输出*******************************************" << endl;
    cout << "输入输出************************" << endl;
    skipList<int, int> a(20);
    cin >> a;
    cout << "The dictionary is " << a;
    cout << endl << "测试成员函数*******************************************" << endl;
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

    cout << "**********************************skipListTest()函数结束**************************************" << endl;
}
