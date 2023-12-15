/*
Project name :			allAlgorithmsTest
Last modified Date:		2023年12月15日21点59分
Last Version:			V1.0
Descriptions:			哈夫曼树的构建函数与main函数
*/
#include "_28binaryTreeChains.h"
#include "huffmanNode.h"

template <class T>
binaryTreeChains<int>* huffmanTree(T weight[], int n)
{
    // 建立一个二叉树集合，每个节点的weight为weight[i]，tree为element为i，左右子树为空的树
    vector<huffmanNode<T>> hNode(n);
    binaryTreeChains<int> emptyTree;
    for (int i = 1; i <= n; i++)
    {
        hNode[i-1].weight = weight[i-1];
        hNode[i-1].tree = new binaryTreeChains<int>;
        hNode[i-1].tree->makeTree(i, emptyTree, emptyTree);
    }
    // 将节点存储为一个小根堆
    std::priority_queue<huffmanNode<T>, std::vector<huffmanNode<T>>, std::greater<>> heap(hNode.begin(),
                                                                                          hNode.end());

    // 从小根堆里面不断合并树
    // 直到小根堆里只有一颗树
    huffmanNode<T> w, x, y;
    binaryTreeChains<int> *z;
    for (int i = 1; i < n; i++)
    {
        // 从小根堆取出两个元素
        x = heap.top(); heap.pop();
        y = heap.top(); heap.pop();

        // 将两棵树合并为一颗树
        z = new binaryTreeChains<int>;
        z->makeTree(0, *x.tree, *y.tree);
        w.weight = x.weight + y.weight;
        w.tree = z;
        heap.push(w);
        delete x.tree;
        delete y.tree;
    }

    // 返回小根堆里的最后一颗树
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
