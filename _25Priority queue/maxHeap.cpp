/*
Project name :			_25Priority_queue
Last modified Date:		2023年11月29日21点08分
Last Version:			V1.0
Descriptions:			优先级队列——大根堆模板源文件
*/
#include "maxHeap.h"

using namespace std;

int maxHeapTest()
{
    // test constructor and push
    maxHeap<int> h(3);
    h.push(10);
    h.push(20);
    h.push(5);

    cout << "Heap size is " << h.size() << endl;
    cout << "Elements in array order are" << endl;
    cout << h << endl;

    h.push(15);
    h.push(30);

    cout << "Heap size is " << h.size() << endl;
    cout << "Elements in array order are" << endl;
    cout << h << endl;

    // test top and pop
    cout << "The max element is " << h.top() << endl;
    h.pop();
    cout << "The max element is " << h.top() << endl;
    h.pop();
    cout << "The max element is " << h.top() << endl;
    h.pop();
    cout << "Heap size is " << h.size() << endl;
    cout << "Elements in array order are" << endl;
    cout << h << endl;

    // test initialize
    int z[10];
    for (int i = 1; i < 10; i++)
        z[i] = i;
    h.initialize(z, 9);
    cout << "Elements in array order are" << endl;
    cout << h << endl;
    return 0;
}