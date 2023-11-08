/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����_13sparseMatrix.hͷ�ļ��е����к���(ϡ�����)
*/
// test array based sparse matrix class

#include <iostream>
#include "_13sparseMatrix.h"
using namespace std;

void sparseMatrixTest()
{
    cout << endl << "********************************sparseMatrixTest()������ʼ************************************" << endl;
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
    cout << "********************************sparseMatrixTest()��������************************************" << endl;
}
