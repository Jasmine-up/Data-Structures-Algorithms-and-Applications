/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����_9diagonalMatrix.hͷ�ļ��е����к���(�ԽǾ���)
*/
#include <iostream>
#include "_9diagonalMatrix.h"
using namespace std;

void diagonalMatrixTest()
{
    cout << endl << "*******************************diagonalMatrixTest()������ʼ***********************************" << endl;
    diagonalMatrix<int> x(20);
    x.set(1,1,22);
    x.set(5,5,44);
    x.set(8,5,0);
    cout << x.get(5,5) << endl;
    cout << x.get(1,1) << endl;
    cout << x.get(10,1) << endl;
    cout << "*******************************diagonalMatrixTest()��������***********************************" << endl;
}
