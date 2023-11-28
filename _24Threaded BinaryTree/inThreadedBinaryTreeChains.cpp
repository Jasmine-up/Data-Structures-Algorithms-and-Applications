/*
Project name :			_24Threaded_BinaryTree
Last modified Date:		2023年11月28日17点06分
Last Version:			V1.0
Descriptions:			线索二叉树测试函数
*/
#include "inThreadedBinaryTreeChains.h"
void inThreadedBinaryTreeChainsTest(){
    cout << endl << "******************************inThreadedBinaryTreeChains()函数开始**********************************" << endl;
    cout << endl << "测试成员函数*******************************************" << endl;
    cout << "输入****************************" << endl;
    cout << "默认构造函数********************" << endl;
    inThreadedBinaryTreeChains<int> a;
    a.input();
    cout << "输出****************************" << endl;
    cout << "中序输出************************" << endl;
    //递归遍历
    a.inOrderThreaded();
    cout << "a.inOrderOutput() = ";
    a.inOrderOutput();
    cout << "后序输出************************" << endl;
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
    cout << "******************************inThreadedBinaryTreeChains()函数结束**********************************" << endl;
}