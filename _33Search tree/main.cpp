/*
Project name :			_33Search_tree
Last modified Date:		2023年12月21日11点13分
Last Version:			V1.0
Descriptions:			二叉搜索树——main函数
*/
#include "binarySearchTree.h"
#include "dBinarySearchTree.h"
#include "indexedBinarySearchTree.h"

using namespace std;


int main(void)
{
    // 测试二叉搜索树
    binarySearchTreeTest();
    // 测试带有相同关键字的二叉搜索树
    dBinarySearchTreeTest();
    // 测试索引二叉树
    indexedBinarySearchTreeTest();

    // 搜索二叉树的应用
    // 直方图 简单求解
    SimpleHistogramSolution();
    // 直方图的二叉搜索树求解
    binarySearchTreeHistogramSolution();
    // 分布交叉 简单求解
    SimpleCrossDistribution();
}