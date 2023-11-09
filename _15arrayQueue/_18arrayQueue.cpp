/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			测试_18arrayQueue.h头文件中的所有函数
*/
#include <iostream>
#include <time.h>
#include "_18arrayQueue.h"
using namespace std;

/*测试函数*/
void arrayQueueTest()
{
    cout << endl << "*********************************arrayQueueTest()函数开始*************************************" << endl;
    arrayQueue<int> a;

    //测试输入和输出
    cout << endl << "测试输入输出函数*******************************************" << endl;
    cout << "输入输出************************" << endl;
    cin >> a;
    cout << "arrayQueue a is:" << a;
    cout << endl << "测试成员函数*******************************************" << endl;
    cout << "empty()*************************" << endl;
    cout << "a.empty() = " << a.empty() << endl;
    cout << "size()**************************" << endl;
    cout << "a.size() = " << a.size() << endl;
    cout << "capacity()**********************" << endl;
    cout << "a.capacity() = " << a.capacity() << endl;
    cout << "push()**************************" << endl;
    cout << "arrayQueue a is:" << a;
    a.push(99);
    a.push(22);
    cout << "arrayQueue a is:" << a;
    cout << "front()*************************" << endl;
    cout << "a.front() = " << a.front() << endl;
    cout << "back()**************************" << endl;
    cout << "a.back() = " << a.back() << endl;
    cout << "pop()***************************" << endl;
    cout << "before pop arrayQueue a is:" << a;
    a.pop();
    a.pop();
    cout << "after pop arrayQueue a is:" << a;
    cout << "resizeQueue()*******************" << endl;
    cout << "before resizeQueue a.capacity() = " << a.capacity()<<endl;
    a.resizeQueue(4);
    cout << "after resizeQueue a.capacity() = " << a.capacity() << endl;
    cout << "arrayQueue a is:" << a;
    cout << "a.front() = " << a.front() << endl;
    cout << "a.back() = " << a.back() << endl;
    a.push(88);
    cout << "after resizeQueue a.capacity() = " << a.capacity() << endl;
    cout << "meld()**************************" << endl;
    arrayQueue<int> b;
    cin >> b;
    cout << "arrayQueue a is:" << a;
    cout << "arrayQueue b is:" << b;
    arrayQueue<int> c;
    c.meld(a, b);
    cout << "arrayQueue c is:" << c;
    cout << "split()*************************" << endl;
    arrayQueue<int> d;
    arrayQueue<int> e;
    c.split(d, e);
    cout << "arrayQueue c is:" << c;
    cout << "arrayQueue d is:" << d;
    cout << "arrayQueue e is:" << e;

    cout << endl << "测试成员函数性能***************************************" << endl;
    cout << "push()**************************" << endl;
    arrayQueue<int> f;
    double clocksPerMillis = double(CLOCKS_PER_SEC) / 1000;
    clock_t startTime = clock();
    for (int i = 0; i < 100000000; i++)
        f.push(i);
    double pushTime = (clock() - startTime) / clocksPerMillis;
    cout << 10000 << " push took " << pushTime << " ms" << endl;
    cout << "*********************************arrayQueueTest()函数结束*************************************" << endl;

}
