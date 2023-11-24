/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月24日11点16分
Last Version:			V1.0
Descriptions:			哈希表---链式散列(链表存储)---cpp文件
// hash table using sorted chains and division
// implements all dictionary methods
*/
#include <iostream>
#include "_26hashChains.h"
using namespace std;

void hashChainsTest()
{
    cout << endl << "*********************************hashChainsTest()函数开始*************************************" << endl;

    hashChains<int, int> a;
    //测试输入和输出
    cout << endl << "测试友元函数*******************************************" << endl;
    cout << "输入输出************************" << endl;
    cin >> a;
    cout << "hashChains a is:" << a;
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
    cout << "hashChains a is:" << a;
    cout << "erase()*************************" << endl;
    a.erase(1);
    cout << "hashChains a is:" << a;
    cout << "*********************************hashChainsTest()函数结束*************************************" << endl;
}
