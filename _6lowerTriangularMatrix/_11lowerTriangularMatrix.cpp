/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����_11lowerTriangularMatrix.hͷ�ļ��е����к���(�����Ǿ���)
*/
#include <iostream>
#include "_11lowerTriangularMatrix.h"
using namespace std;

void lowerTriangularMatrixTest()
{
    cout << endl << "****************************lowerTriangularMatrixTest()������ʼ*******************************" << endl;
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
    cout << "*******************************diagonalMatrixTest()��������***********************************" << endl;
}
