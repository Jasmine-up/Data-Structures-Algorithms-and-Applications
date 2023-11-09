/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			测试_21linkedQueue.h头文件中的所有函数
*/
#include <iostream>
#include <time.h>
#include "_21linkedQueue.h"
using namespace std;
/*测试函数*/
void linkedQueueTest()
{
    cout << endl << "*********************************linkedQueueTest()函数开始*************************************" << endl;
    linkedQueue<int> a;

    //测试输入和输出
    cout << endl << "测试输入输出*******************************************" << endl;
    cout << "输入输出************************" << endl;
    cin >> a;
    cout << "linkedQueue a is:" << a;
    cout << endl << "测试成员函数*******************************************" << endl;
    cout << "empty()*************************" << endl;
    cout << "a.empty() = " << a.empty() << endl;
    cout << "size()**************************" << endl;
    cout << "a.size() = " << a.size() << endl;
    cout << "push()**************************" << endl;
    cout << "before push linkedQueue a is:" << a;
    a.push(99);
    a.push(22);
    cout << "after push linkedQueue a is:" << a;
    cout << "front()*************************" << endl;
    cout << "a.front() = " << a.front() << endl;
    cout << "back()**************************" << endl;
    cout << "a.back() = " << a.back() << endl;
    cout << "pop()***************************" << endl;
    cout << "before pop linkedQueue a is:" << a;
    a.pop();
    a.pop();
    cout << "after pop linkedQueue a is:" << a;
    cout << "clear()*************************" << endl;
    a.clear();
    cout << "after clear linkedQueue a is:" << a;

    cout << endl << "测试成员函数性能***************************************" << endl;
    cout << "push()**************************" << endl;
    linkedQueue<int> f;
    double clocksPerMillis = double(CLOCKS_PER_SEC) / 1000;
    clock_t startTime = clock();
    for (int i = 0; i < 100000000; i++)
        f.push(i);
    double pushTime = (clock() - startTime) / clocksPerMillis;
    cout << 10000 << " push took " << pushTime << " ms" << endl;

    cout << "*********************************linkedQueueTest()函数结束*************************************" << endl;
}
