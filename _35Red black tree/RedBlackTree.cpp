/*
Project name :			_35Red_black_tree
Last modified Date:		2024年1月9日21点10分
Last Version:			V1.0
Descriptions:			红黑树测试函数
*/
#include "RedBlackTree.h"
#include<vector>

void RedBlackTreeTest() {
    cout << "*************************RedBlackTreeTest() begin*******************************" << endl;
    RedBlackTree<int, char> y;
    pair<int, char> data;
    for(int i = 1; i < 100001; i++){
        data = pair<int, char>(i, 'e');
        y.insert(data);
    }

    // 第二种删除策略
    for(int i = 25000; i > 0; i--){
        cout << " Delete " << i << endl;
        y.erase(i);
        cout << "y.ISRBTree() = " << y.ISRBTree() << endl;
    }
    for(int i = 50000; i < 75001; i++){
        cout << " Delete " << i << endl;
        y.erase(i);
        cout << "y.ISRBTree() = " << y.ISRBTree() << endl;
    }
    for(int i = 25001; i < 50000; i++){
        cout << " Delete " << i << endl;
        y.erase(i);
        cout << "y.ISRBTree() = " << y.ISRBTree() << endl;
    }
    for(int i = 100000; i > 75000; i--){
        cout << " Delete " << i << endl;
        y.erase(i);
        cout << "y.ISRBTree() = " << y.ISRBTree() << endl;
    }

    cout << "***************************RedBlackTreeTest() end*******************************" << endl;
}