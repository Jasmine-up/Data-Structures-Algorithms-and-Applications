/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月22日09点17分
Last Version:			V1.0
Descriptions:			使用链表实现的字典的cpp文件
*/
#include "_23dictionaryChain.h"
using namespace std;
void dictionaryChainTest()
{
    cout << endl << "******************************dictionaryChainTest()函数开始***********************************" << endl;
    dictionaryChain<int, int> a;
    //测试输入和输出
    cout << endl << "测试输入输出*******************************************" << endl;
    cout << "输入输出************************" << endl;
    cin >> a;
    cout << "dictionaryChain a is:" << a;
    cout << endl << "测试成员函数*******************************************" << endl;
    cout << "empty()*************************" << endl;
    cout << "a.empty() = " << a.empty() << endl;
    cout << "size()**************************" << endl;
    cout << "a.size() = " << a.size() << endl;
    cout << "find()**************************" << endl;
    cout << "a.find(1)->second = " << a.find(1)->second << endl;
    cout << "insert()************************" << endl;
    pair<const int, int> insertData(3,4);
    a.insert(insertData);
    cout << "dictionaryChain a is:" << a;
    cout << "erase()*************************" << endl;
    a.erase(1);
    cout << "dictionaryChain a is:" << a;

    cout << "******************************dictionaryChainTest()函数结束***********************************" << endl;
}