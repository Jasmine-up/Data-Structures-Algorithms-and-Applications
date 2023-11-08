/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����_10tridiagonalMatrix.hͷ�ļ��е����к���(���ԽǾ���)
*/
#include <iostream>
#include "_10tridiagonalMatrix.h"

using namespace std;
void tridiagonalMatrixTest()
{
    cout << endl << "******************************tridiagonalMatrixTest()������ʼ*********************************" << endl;
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
    cout << "*****************************tridiagonalMatrixTest()��������**********************************" << endl;
}
