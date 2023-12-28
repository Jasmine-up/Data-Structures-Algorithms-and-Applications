/*
Project name :			_34Balanced_search_tree
Last modified Date:		2023年12月27日10点57分
Last Version:			V1.0
Descriptions:			AVL树测试函数
*/
#include "AVLTree.h"
#include<vector>

void AVLTreeTest() {
    cout << "*************************AVLTreeTest() begin*******************************" << endl;
    AVLTree<int, char> y;
    pair<int, char> data(30, 'a');
    y.insert(data);
    data = pair<int, char>(35, 'e');
    y.insert(data);
    data = pair<int, char>(60, 'c');
    y.insert(data);
    data = pair<int, char>(5, 'b');
    y.insert(data);
    data = pair<int, char>(2, 'd');
    y.insert(data);
    data = pair<int, char>(80, 'f');
    y.insert(data);
    data = pair<int, char>(32, 'g');
    y.insert(data);
    data = pair<int, char>(85, 'h');
    y.insert(data);
    data = pair<int, char>(31, 'i');
    y.insert(data);
    data = pair<int, char>(33, 'j');
    y.insert(data);
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.inOrderOutput();

    pair<int, char> *s = y.find(60);
    cout << "Search for 60 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(60);
    cout << "60 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.inOrderOutput();

    s = y.find(80);
    cout << "Search for 80 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(80);
    cout << "80 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.inOrderOutput();

    s = y.find(30);
    cout << "Search for 30 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(30);
    cout << "30 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.inOrderOutput();

    s = y.find(35);
    cout << "Search for 35 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(35);
    cout << "35 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.inOrderOutput();
    s = y.find(2);
    cout << "Search for 2 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(2);
    cout << "2 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.inOrderOutput();
    s = y.find(32);
    cout << "Search for 32 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(32);
    cout << "32 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.inOrderOutput();
    s = y.find(5);
    cout << "Search for 5 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(5);
    cout << "5 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.inOrderOutput();
    cout << "***************************AVLTreeTest() end*******************************" << endl;
}