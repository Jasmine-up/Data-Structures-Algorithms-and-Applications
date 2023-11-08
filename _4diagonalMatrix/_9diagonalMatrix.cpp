/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			测试_9diagonalMatrix.h头文件中的所有函数(对角矩阵)
*/
#include <iostream>
#include "_9diagonalMatrix.h"
using namespace std;

void diagonalMatrixTest()
{
    cout << endl << "*******************************diagonalMatrixTest()函数开始***********************************" << endl;
    diagonalMatrix<int> x(20);
    x.set(1,1,22);
    x.set(5,5,44);
    x.set(8,5,0);
    cout << x.get(5,5) << endl;
    cout << x.get(1,1) << endl;
    cout << x.get(10,1) << endl;
    cout << "*******************************diagonalMatrixTest()函数结束***********************************" << endl;
}
