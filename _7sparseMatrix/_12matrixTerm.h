/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			���ڴ洢ϡ�������кš��кź�Ԫ�صĽṹ��
*/

#ifndef _MATRIXTERM_H_
#define _MATRIXTERM_H_
using namespace std;
template <class T>
struct matrixTerm
{
    int row,
            col;
    T value;

    operator T() const {return value;}
    // type conversion from matrixTerm to T
};

#endif
