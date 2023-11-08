/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			测试_11lowerTriangularMatrix.h头文件中的所有函数(下三角矩阵)
*/
#include <iostream>
#include "_11lowerTriangularMatrix.h"
using namespace std;

void lowerTriangularMatrixTest()
{
    cout << endl << "****************************lowerTriangularMatrixTest()函数开始*******************************" << endl;
    lowerTriangularMatrix<int> x(20);
    x.set(1, 1, 22);
    x.set(5, 3, 44);
    x.set(8, 5, 0);
    x.set(10, 2, 55);
    x.set(8, 5, 0);
    cout << x.get(10, 2) << endl;
    cout << x.get(5, 3) << endl;
    cout << x.get(1, 1) << endl;
    cout << x.get(10, 14) << endl;
    cout << x.get(8, 5) << endl;
    cout << "*******************************diagonalMatrixTest()函数结束***********************************" << endl;
}
