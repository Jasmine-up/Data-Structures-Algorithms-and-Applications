/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��13��17��38��
Last Version:			V1.0
Descriptions:			����_3sorting.hͷ�ļ��е����к���
*/
#include "_3sorting.h"
using std::cout;
using std::endl;

void sortingTest()
{
    //cout << endl << "*********************************sortingTest()������ʼ****************************************" << endl;
    //int a[4] = { 1,6,9,12 };
    //int r[4];
    //std::cout << "���μ���************************************************" << std::endl;
    //rank<int>(a, 4, r);
    //traverse<int>(a, 4);
    //std::cout << "�����и���Ԫ�ص�����Ϊ:";
    //traverse<int>(r, 4);
    //std::cout << "\n����������**********************************************" << std::endl;
    //std::cout << "�����ţ�" << std::endl;
    //std::cout << "����ǰ�����飺";
    //traverse<int>(a, 4);
    //rearrange<int>(a, 4, r);
    //std::cout << "\n���������飺";
    //traverse<int>(a, 4);
    //std::cout << "\nԭ�����ţ�" << std::endl;
    //int d[4] = { 3,6,1,9 };
    //std::cout << "����ǰ�����飺";
    //traverse<int>(d, 4);
    //rank<int>(d, 4, r);
    //situ_rearrange<int>(d, 4, r);
    //std::cout << "\n���������飺";
    //traverse<int>(d, 4);
    //std::cout << "\nѡ������************************************************" << std::endl;
    //std::cout << "��ͨ����" << std::endl;
    //int b[4] = { 3,6,1,9 };
    //std::cout << "����ǰ�����飺";
    //traverse<int>(b, 4);
    //selectionSort<int>(b, 4);
    //std::cout << "\n���������飺";
    //traverse<int>(b, 4);
    //std::cout << "\n��ʱ��ֹ��ѡ������" << std::endl;
    //int e[4] = { 3,9,1,9 };
    //std::cout << "����ǰ�����飺";
    //traverse<int>(e, 4);
    //Timely_Terminated_selectionSort<int>(e, 4);
    //std::cout << "\n���������飺";
    //traverse<int>(e, 4);
    //std::cout << "\nð������************************************************" << std::endl;
    //int c[4] = { 9,6,1,9 };
    //std::cout << "����ǰ�����飺";
    //traverse<int>(c, 4);
    //bubbleSort<int>(c, 4);
    //std::cout << "\n���������飺";
    //traverse<int>(c, 4);
    //std::cout << "\n��������************************************************" << std::endl;
    //int f[5] = { 9,6,1,7,8 };
    //std::cout << "����ǰ�����飺";
    //traverse<int>(f, 5);
    //insertionSort<int>(f, 5);
    //std::cout << "\n���������飺";
    //traverse<int>(f, 5);
    std::cout << "\n��������************************************************" << std::endl;
    //int f[5] = { 9,6,1,7,8 };
    int f[] = { 25,12,20,31,8,46,15,4,50,10 };
    std::cout << "����ǰ�����飺";
    traverse<int>(f, 10);
    shellsort(f, 10);
    std::cout << "\n���������飺";
    traverse<int>(f, 10);
    cout << endl << "*********************************sortingTest()��������****************************************" << endl;
}