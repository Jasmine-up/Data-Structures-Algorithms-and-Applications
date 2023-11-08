/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			测试_13sparseMatrix.h头文件中的所有函数(稀疏矩阵)
*/
// test array based sparse matrix class

#include <iostream>
#include "_13sparseMatrix.h"
using namespace std;

void sparseMatrixTest()
{
    cout << endl << "********************************sparseMatrixTest()函数开始************************************" << endl;
    sparseMatrix<int> a, b, c;

    // test input and output
    cin >> a;
    cout << "Matrix a is" << endl << a;
    cin >> b;
    cout << "Matrix b is" << endl << b;

    // test transpose
    a.transpose(c);
    cout << "The transpose of a is" << endl << c;

    // test add
    a.add(b,c);
    cout << "The sum of a and b is" << endl << c;
    cout << "********************************sparseMatrixTest()函数结束************************************" << endl;
}
