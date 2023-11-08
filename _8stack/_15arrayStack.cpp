/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			测试_15arrayStack.h头文件中的所有函数
*/
// test array based sparse matrix class

#include <iostream>
#include "_15arrayStack.h"
using namespace std;

/*测试函数*/
void arrayStackTest()
{
    cout << endl << "*********************************arrayStackTest()函数开始*************************************" << endl;
    arrayStack<int> a;

    //测试输入和输出
    cout << endl << "测试友元函数*******************************************" << endl;
    cout << "输入输出************************" << endl;
    cin >> a;
    cout << "arrayStack a is:" << a;//arrayStack a is:1  2  3  4  5  6
    cout << endl << "测试成员函数*******************************************" << endl;
    cout << "empty()*************************" << endl;
    cout << "a.empty() = " << a.empty() << endl;//a.empty() = 0
    cout << "size()**************************" << endl;
    cout << "a.size() = " << a.size() << endl;//a.size() = 6
    cout << "top()***************************" << endl;
    cout << "a.top() = " << a.top() << endl;//a.top() = 6
    cout << "pop()***************************" << endl;
    cout << "a.capacity() = " << a.capacity() << endl;//a.capacity() = 10
    cout << "arrayStack a is:" << a;//arrayStack a is:1  2  3  4  5  6
    cout << "a.pop() = " << a.pop() << endl;//a.pop() = 6
    cout << "a.pop() = " << a.pop() << endl;//a.pop() = 5
    cout << "a.pop() = " << a.pop() << endl;//a.pop() = 4
    cout << "a.pop() = " << a.pop() << endl;//a.pop() = 3
    cout << "a.pop() = " << a.pop() << endl;//a.pop() = 2
    cout << "arrayStack a is:" << a;//arrayStack a is:1
    cout << "a.capacity() = " << a.capacity() << endl;//a.capacity() = 5
    cout << "push()**************************" << endl;
    a.push(99);
    cout << "arrayStack a is:" << a;//arrayStack a is:1  99
    cout << "split()*************************" << endl;
    arrayStack<int> b, c;
    a.split(b, c);
    cout << "arrayStack a is:" << a;//arrayStack a is:1  99
    cout << "arrayStack b is:" << b;//arrayStack b is:1
    cout << "arrayStack c is:" << c;//arrayStack c is:99
    cout << "merge()*************************" << endl;
    a.merge(b);
    cout << "arrayStack a is:" << a;//arrayStack a is:1  99  1
    cout << "arrayStack b is:" << b;//arrayStack b is:1
    cout << "*********************************arrayStackTest()函数结束*************************************" << endl;
}
