/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月23日10点18分
Last Version:			V1.0
Descriptions:			哈希表(数组存储)---使用线性探查的cpp文件
*/
#include <iostream>
#include "_25hashTable.h"
using namespace std;

void hashTableTest()
{
    cout << endl << "*********************************hashTableTest()函数开始**************************************" << endl;
    hashTable<int, int> a;
    //测试输入和输出
    cout << endl << "测试友元函数*******************************************" << endl;
    cout << "输入输出************************" << endl;
    cin >> a;
    cout << "hashTable a is:" << a;
    cout << endl << "测试成员函数*******************************************" << endl;
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
    cout << "*********************************hashTableTest()函数结束**************************************" << endl;
}
