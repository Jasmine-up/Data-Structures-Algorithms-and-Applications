/*
Project name :			_24Threaded_BinaryTree
Last modified Date:		2023��11��28��17��06��
Last Version:			V1.0
Descriptions:			�������������Ժ���
*/
#include "inThreadedBinaryTreeChains.h"
void inThreadedBinaryTreeChainsTest(){
    cout << endl << "******************************inThreadedBinaryTreeChains()������ʼ**********************************" << endl;
    cout << endl << "���Գ�Ա����*******************************************" << endl;
    cout << "����****************************" << endl;
    cout << "Ĭ�Ϲ��캯��********************" << endl;
    inThreadedBinaryTreeChains<int> a;
    a.input();
    cout << "���****************************" << endl;
    cout << "�������************************" << endl;
    //�ݹ����
    a.inOrderThreaded();
    cout << "a.inOrderOutput() = ";
    a.inOrderOutput();
    cout << "�������************************" << endl;
    a.inOrderThreaded();
    cout << "a.postOrderOutput() = ";
    a.postOrderOutput();
    cout << "empty()*************************" << endl;
    cout << "a.empty() = " << a.empty() << endl;
    cout << "size()**************************" << endl;
    cout << "a.size() = " << a.size() << endl;
    cout << "erase()**************************" << endl;
    a.erase();
    cout << "a.inOrderOutput() = ";
    a.inOrderOutput();
    cout << "******************************inThreadedBinaryTreeChains()��������**********************************" << endl;
}