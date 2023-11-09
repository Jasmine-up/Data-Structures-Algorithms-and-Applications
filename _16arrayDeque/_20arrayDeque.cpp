/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����_20arrayDeque.hͷ�ļ��е����к���
*/
#include <iostream>
#include "_20arrayDeque.h"
using namespace std;
/*���Ժ���*/
void arrayDequeTest()
{
    cout << endl << "*********************************arrayDequeTest()������ʼ*************************************" << endl;
    arrayDeque<int> a;
    //������������
    cout << endl << "�����������*******************************************" << endl;
    cout << "�������************************" << endl;
    cin >> a;
    cout << "arrayDeque a is:" << a;
    cout << endl << "���Գ�Ա����*******************************************" << endl;
    cout << "empty()*************************" << endl;
    cout << "a.empty() = " << a.empty() << endl;
    cout << "size()**************************" << endl;
    cout << "a.size() = " << a.size() << endl;
    cout << "capacity()**********************" << endl;
    cout << "a.capacity() = " << a.capacity() << endl;
    cout << "push_front()********************" << endl;
    cout << "before push_front() arrayDeque a is:" << a;
    a.push_front(99);
    a.push_front(22);
    cout << "after push_front() arrayDeque a is:" << a;
    cout << "push_back()*********************" << endl;
    cout << "before push_back() arrayDeque a is:" << a;
    a.push_back(99);
    a.push_back(22);
    cout << "after push_back() arrayDeque a is:" << a;
    cout << "front()*************************" << endl;
    cout << "a.front() = " << a.front() << endl;
    cout << "back()**************************" << endl;
    cout << "a.back() = " << a.back() << endl;
    cout << "pop_front()*********************" << endl;
    cout << "before pop_front arrayDeque a is:" << a;
    a.pop_front();
    a.pop_front();
    cout << "after pop_front arrayDeque a is:" << a;
    cout << "pop_back()**********************" << endl;
    cout << "before pop_back arrayDeque a is:" << a;
    a.pop_back();
    a.pop_back();
    cout << "after pop_back arrayDeque a is:" << a;
    cout << "resizeDeque()*******************" << endl;
    cout << "before resizeDeque a.capacity() = " << a.capacity() << endl;
    a.resizeDeque(4);
    cout << "after resizeDeque a.capacity() = " << a.capacity() << endl;
    cout << "resizeDeque a is:" << a;
    cout << "a.front() = " << a.front() << endl;
    cout << "a.back() = " << a.back() << endl;
    a.push_back(88);
    cout << "after resizeDeque a.capacity() = " << a.capacity() << endl;
    cout << "meld()**************************" << endl;
    arrayDeque<int> b;
    cin >> b;
    cout << "arrayDeque a is:" << a;
    cout << "arrayDeque b is:" << b;
    arrayDeque<int> c;
    c.meld(a, b);
    cout << "arrayDeque c is:" << c;
    cout << "split()*************************" << endl;
    arrayDeque<int> d;
    arrayDeque<int> e;
    c.split(d, e);
    cout << "arrayDeque c is:" << c;
    cout << "arrayDeque d is:" << d;
    cout << "arrayDeque e is:" << e;
    cout << "*********************************arrayDequeTest()��������*************************************" << endl;

}
