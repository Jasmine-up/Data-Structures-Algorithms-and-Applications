/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����_2myFunctions.hͷ�ļ��е����к���
*/
#include "_2myFunctions.h"
using std::cout;
using std::endl;
/*myFunctions�Ĳ��Ժ���*/
void myFunctionsTest()
{
    cout << endl << "********************************myFunctionsTest()������ʼ*************************************" << endl;
    //cout << "��ŵ��*************************************************" << endl;
    //towersOfHanoiRecursion(4, 1, 2, 3);
    cout << "********************************myFunctionsTest()��������*************************************" << endl;
}

/*��ŵ���ĵݹ�������*/
/*ִ�а��˴���Ϊ2^n-1��*/
void towersOfHanoiRecursion(int n, int x, int y, int z)
{
    static int numberOfMove = 0;
    if (n > 0)
    {
        towersOfHanoiRecursion(n - 1, x, z, y);
        cout << "Move top disk from tower " << x << " to top of tower " << y << endl;
        numberOfMove++;
        towersOfHanoiRecursion(n - 1, z, y, x);
    }
    else
        cout << "numberOfMove = " << numberOfMove << endl;
}
