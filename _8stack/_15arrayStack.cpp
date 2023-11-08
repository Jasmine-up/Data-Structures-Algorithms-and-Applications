/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����_15arrayStack.hͷ�ļ��е����к���
*/
// test array based sparse matrix class

#include <iostream>
#include "_15arrayStack.h"
using namespace std;

/*���Ժ���*/
void arrayStackTest()
{
    cout << endl << "*********************************arrayStackTest()������ʼ*************************************" << endl;
    arrayStack<int> a;

    //������������
    cout << endl << "������Ԫ����*******************************************" << endl;
    cout << "�������************************" << endl;
    cin >> a;
    cout << "arrayStack a is:" << a;//arrayStack a is:1  2  3  4  5  6
    cout << endl << "���Գ�Ա����*******************************************" << endl;
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
    cout << "*********************************arrayStackTest()��������*************************************" << endl;
}
