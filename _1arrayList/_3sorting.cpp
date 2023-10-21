/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月13日17点38分
Last Version:			V1.0
Descriptions:			测试_3sorting.h头文件中的所有函数
*/
#include "_3sorting.h"
using std::cout;
using std::endl;

void sortingTest()
{
    //cout << endl << "*********************************sortingTest()函数开始****************************************" << endl;
    //int a[4] = { 1,6,9,12 };
    //int r[4];
    //std::cout << "名次计算************************************************" << std::endl;
    //rank<int>(a, 4, r);
    //traverse<int>(a, 4);
    //std::cout << "数组中各个元素的名次为:";
    //traverse<int>(r, 4);
    //std::cout << "\n按名次排序**********************************************" << std::endl;
    //std::cout << "简单重排：" << std::endl;
    //std::cout << "排序前的数组：";
    //traverse<int>(a, 4);
    //rearrange<int>(a, 4, r);
    //std::cout << "\n排序后的数组：";
    //traverse<int>(a, 4);
    //std::cout << "\n原地重排：" << std::endl;
    //int d[4] = { 3,6,1,9 };
    //std::cout << "排序前的数组：";
    //traverse<int>(d, 4);
    //rank<int>(d, 4, r);
    //situ_rearrange<int>(d, 4, r);
    //std::cout << "\n排序后的数组：";
    //traverse<int>(d, 4);
    //std::cout << "\n选择排序************************************************" << std::endl;
    //std::cout << "普通排序：" << std::endl;
    //int b[4] = { 3,6,1,9 };
    //std::cout << "排序前的数组：";
    //traverse<int>(b, 4);
    //selectionSort<int>(b, 4);
    //std::cout << "\n排序后的数组：";
    //traverse<int>(b, 4);
    //std::cout << "\n及时终止的选择排序：" << std::endl;
    //int e[4] = { 3,9,1,9 };
    //std::cout << "排序前的数组：";
    //traverse<int>(e, 4);
    //Timely_Terminated_selectionSort<int>(e, 4);
    //std::cout << "\n排序后的数组：";
    //traverse<int>(e, 4);
    //std::cout << "\n冒泡排序************************************************" << std::endl;
    //int c[4] = { 9,6,1,9 };
    //std::cout << "排序前的数组：";
    //traverse<int>(c, 4);
    //bubbleSort<int>(c, 4);
    //std::cout << "\n排序后的数组：";
    //traverse<int>(c, 4);
    //std::cout << "\n插入排序************************************************" << std::endl;
    //int f[5] = { 9,6,1,7,8 };
    //std::cout << "排序前的数组：";
    //traverse<int>(f, 5);
    //insertionSort<int>(f, 5);
    //std::cout << "\n排序后的数组：";
    //traverse<int>(f, 5);
    std::cout << "\n快速排序************************************************" << std::endl;
    //int f[5] = { 9,6,1,7,8 };
    int f[] = { 25,12,20,31,8,46,15,4,50,10 };
    std::cout << "排序前的数组：";
    traverse<int>(f, 10);
    shellsort(f, 10);
    std::cout << "\n排序后的数组：";
    traverse<int>(f, 10);
    cout << endl << "*********************************sortingTest()函数结束****************************************" << endl;
}