/*
Project name :			_33Search_tree
Last modified Date:		2023��12��21��11��13��
Last Version:			V1.0
Descriptions:			��������������main����
*/
#include "binarySearchTree.h"
#include "dBinarySearchTree.h"
#include "indexedBinarySearchTree.h"

using namespace std;


int main(void)
{
    // ���Զ���������
    binarySearchTreeTest();
    // ���Դ�����ͬ�ؼ��ֵĶ���������
    dBinarySearchTreeTest();
    // ��������������
    indexedBinarySearchTreeTest();

    // ������������Ӧ��
    // ֱ��ͼ �����
    SimpleHistogramSolution();
    // ֱ��ͼ�Ķ������������
    binarySearchTreeHistogramSolution();
    // �ֲ����� �����
    SimpleCrossDistribution();
}