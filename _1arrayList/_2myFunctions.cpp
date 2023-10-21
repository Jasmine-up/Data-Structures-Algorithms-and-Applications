/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			测试_2myFunctions.h头文件中的所有函数
*/
#include "_2myFunctions.h"
using std::cout;
using std::endl;
/*myFunctions的测试函数*/
void myFunctionsTest()
{
    cout << endl << "********************************myFunctionsTest()函数开始*************************************" << endl;
    //cout << "汉诺塔*************************************************" << endl;
    //towersOfHanoiRecursion(4, 1, 2, 3);
    cout << "********************************myFunctionsTest()函数结束*************************************" << endl;
}

/*汉诺塔的递归解决方案*/
/*执行搬运次数为2^n-1次*/
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
