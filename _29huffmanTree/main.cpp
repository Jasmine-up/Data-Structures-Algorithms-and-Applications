/*
Project name :			allAlgorithmsTest
Last modified Date:		2023��12��15��21��59��
Last Version:			V1.0
Descriptions:			���������Ĺ���������main����
*/
#include "_28binaryTreeChains.h"
#include "huffmanNode.h"

template <class T>
binaryTreeChains<int>* huffmanTree(T weight[], int n)
{
    // ����һ�����������ϣ�ÿ���ڵ��weightΪweight[i]��treeΪelementΪi����������Ϊ�յ���
    vector<huffmanNode<T>> hNode(n);
    binaryTreeChains<int> emptyTree;
    for (int i = 1; i <= n; i++)
    {
        hNode[i-1].weight = weight[i-1];
        hNode[i-1].tree = new binaryTreeChains<int>;
        hNode[i-1].tree->makeTree(i, emptyTree, emptyTree);
    }
    // ���ڵ�洢Ϊһ��С����
    std::priority_queue<huffmanNode<T>, std::vector<huffmanNode<T>>, std::greater<>> heap(hNode.begin(),
                                                                                          hNode.end());

    // ��С�������治�Ϻϲ���
    // ֱ��С������ֻ��һ����
    huffmanNode<T> w, x, y;
    binaryTreeChains<int> *z;
    for (int i = 1; i < n; i++)
    {
        // ��С����ȡ������Ԫ��
        x = heap.top(); heap.pop();
        y = heap.top(); heap.pop();

        // ���������ϲ�Ϊһ����
        z = new binaryTreeChains<int>;
        z->makeTree(0, *x.tree, *y.tree);
        w.weight = x.weight + y.weight;
        w.tree = z;
        heap.push(w);
        delete x.tree;
        delete y.tree;
    }

    // ����С����������һ����
    return heap.top().tree;
}

int main()
{
    int a[5];
    int n = 5;
    for (int i = 1; i <= n; i++)
        a[i-1] = 2 * i;
    binaryTreeChains<int> *x = huffmanTree(a, n);
    x->postOrderOutput();
    x->preOrderOutput();
    x->inOrderOutput();
    return 0;
}
