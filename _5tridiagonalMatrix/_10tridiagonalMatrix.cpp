/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			测试_10tridiagonalMatrix.h头文件中的所有函数(三对角矩阵)
*/
#include <iostream>
#include "_10tridiagonalMatrix.h"

using namespace std;
void tridiagonalMatrixTest()
{
    cout << endl << "******************************tridiagonalMatrixTest()函数开始*********************************" << endl;
    tridiagonalMatrix<int> x(20);
    x.set(1, 1, 22);
    x.set(5, 5, 44);
    x.set(8, 5, 0);
    x.set(7, 8, 55);
    cout << x.get(7, 8) << endl;
    cout << x.get(5, 5) << endl;
    cout << x.get(1, 1) << endl;
    cout << x.get(10, 1) << endl;
    cout << x.get(1, 5) << endl;
    cout << "*****************************tridiagonalMatrixTest()函数结束**********************************" << endl;
}
