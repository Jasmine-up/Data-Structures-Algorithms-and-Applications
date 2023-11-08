/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			测试_8matrix.h头文件中的所有函数
*/
#include"_8matrix.h"
#include<iostream>
using namespace std;

void matrixTest()
{
    cout << endl << "**********************************matrixTest()函数开始****************************************" << endl;
    cout << endl << "测试成员函数*******************************************" << endl;
    cout << "构造函数+输入输出***************" << endl;
    matrix<int> matrix1(2, 3);
    cin >> matrix1;
    cout <<"matrix1 = "<< matrix1 << endl;
    matrix<int> matrix2(matrix1);
    cout << "matrix2 = " << matrix2 << endl;
    cout << "测试tranpose()成员函数**********" << endl;
    matrix<int> matrix14 = matrix2.tranpose();
    cout << "matrix14 = " << matrix14 << endl;
    cout << endl << "重载操作符**********************************************" << endl;
    cout << "重载=操作符*********************" << endl;
    matrix<int> matrix3 = matrix2;
    cout << "matrix3 = " << matrix3 << endl;
    cout << "重载()操作符********************" << endl;
    cout << "matrix3(1,2) = " << matrix3(1,2) << endl;
    cout << "重载一元+操作符*****************" << endl;
    matrix<int> matrix4 = +matrix3;
    cout << "matrix4 = +matrix3：" << matrix4 << endl;
    cout << "重载二元+操作符：矩阵加矩阵*****" << endl;
    matrix<int> matrix5 = matrix3 + matrix4;
    cout << "matrix5 = matrix3 + matrix4：" << matrix5 << endl;
    cout << "重载二元+操作符：矩阵加数据*****" << endl;
    matrix<int> matrix6 = matrix5+2;
    cout << "matrix6 = matrix5+2：" << matrix6 << endl;
    cout << "重载+=操作符：矩阵加矩阵********" << endl;
    matrix6 += matrix5;
    cout << "matrix6 += matrix5：" << matrix6 << endl;
    cout << "重载+=操作符：矩阵加数据********" << endl;
    matrix6 += 1;
    cout << "matrix6 += 1：" << matrix6 << endl;
    cout << "重载一元-操作符*****************" << endl;
    matrix<int> matrix7 = -matrix6;
    cout << "matrix7 = -matrix6：" << matrix7 << endl;
    cout << "重载二元-操作符：矩阵减矩阵*****" << endl;
    matrix<int> matrix8 = matrix7 - matrix5;
    cout << "matrix8 = matrix7 - matrix5：" << matrix8 << endl;
    cout << "重载二元-操作符：矩阵减数据*****" << endl;
    matrix<int> matrix9 = matrix8 - 1;
    cout << "matrix9 = matrix8 - 1：" << matrix9 << endl;
    cout << "重载-=操作符：矩阵减矩阵********" << endl;
    matrix9 -= matrix8;
    cout << "matrix9 -= matrix8：" << matrix9 << endl;
    cout << "重载-=操作符：矩阵减数据********" << endl;
    matrix9 -= 2;
    cout << "matrix9 -= 2：" << matrix9 << endl;
    cout << "重载*操作符:矩阵乘矩阵**********" << endl;
    matrix9 += 4;
    matrix<int> matrix10(3, 2);
    cin >> matrix10;
    cout << "matrix9 = " << matrix9 << endl;
    cout << "matrix10 = " << matrix10 << endl;
    matrix<int> matrix11 = matrix9*matrix10;
    cout << "matrix11 = matrix9*matrix10：" << matrix11 << endl;
    cout << "重载*操作符:矩阵乘数据**********" << endl;
    matrix<int> matrix12 = matrix11 * 2;
    cout << "matrix12 = matrix11 * 2：" << matrix12 << endl;
    cout << "重载*=操作符:矩阵乘数据*********" << endl;
    matrix12 *= 2;
    cout << "matrix12 *= 2：" << matrix12 << endl;
    cout << "重载/操作符:矩阵除数据**********" << endl;
    matrix<int> matrix13 = matrix12 / 2;
    cout << "matrix13 = matrix12 / 2：" << matrix13 << endl;
    cout << "重载/=操作符:矩阵除数据*********" << endl;
    matrix13 /= 2;
    cout << "matrix13 = " << matrix13 << endl;
    cout << "**********************************matrixTest()函数结束****************************************" << endl;

}
