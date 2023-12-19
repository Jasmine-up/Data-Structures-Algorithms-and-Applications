/*
Project name :			_30winnerTree
Last modified Date:		2023年12月19日11点18分
Last Version:			V1.0
Descriptions:			最小赢者树——模板类
*/

#ifndef _30WINNERTREE_COMPLETEWINNERTREE_H
#define _30WINNERTREE_COMPLETEWINNERTREE_H
#include <iostream>
#include "winnerTree.h"
#include "myExceptions.h"
void completeWinnerTreeTest();
template<class T>
class completeWinnerTree : public winnerTree<T>
{
public:
    completeWinnerTree(T *thePlayer, int theNumberOfPlayers)
    {
        tree = nullptr;
        initialize(thePlayer, theNumberOfPlayers);
    }
    ~completeWinnerTree() {delete [] tree;}
    void initialize(T*, int);
    [[nodiscard]] int winner() const
    {return tree[1];}
    [[nodiscard]] int winner(int i) const
    // 返回节点i的胜者的index
    {return (i < numberOfPlayers) ? tree[i] : 0;}
    void rePlay(int);
    void output() const;
private:
    int lowExt{};           // lowest-level external nodes
    int offset{};           // 2^log(n-1) - 1
    int *tree;            // array for winner tree
    int numberOfPlayers{};
    T *player;            // array of players
    void play(int, int, int);
};

template<class T>
void completeWinnerTree<T>::initialize(T *thePlayer,
                                       int theNumberOfPlayers)
{// 使用thePlayer[1:numberOfPlayers]数组初始化赢者树
    int n = theNumberOfPlayers;
    if (n < 2)
        throw illegalParameterValue("must have at least 2 players");

    player = thePlayer;
    numberOfPlayers = n;
    delete [] tree;// 清空tree
    tree = new int [n];// 重新为tree初始化空间

    // 计算  s = 2^log (n-1)
    int i, s;
    for (s = 1; 2 * s <= n - 1; s += s);

    lowExt = 2 * (n - s);
    offset = 2 * s - 1;

    // 从最底层的外部节点开始比赛
    for (i = 2; i <= lowExt; i += 2)
        play((offset + i) / 2, i - 1, i);

    // 处理剩余的外部节点
    if (n % 2 == 1) // 当n是奇数时，总是有一场内部节点和外部节点的比赛
    {
        play(n/2, tree[n - 1], lowExt + 1);
        i = lowExt + 3;
    }
    else i = lowExt + 2;

    // i是最右边的外部节点
    for (; i <= n; i += 2)
        play((i - lowExt + n - 1) / 2, i - 1, i);
}

template<class T>
void completeWinnerTree<T>::play(int p, int leftChild, int rightChild)
{// 开展tree[p]处的比赛
    // leftChild是p的左孩子
    // rightChild是p的右孩子
    // 定义的是数越小就胜出

    tree[p] = (player[leftChild] <= player[rightChild]) ?
              leftChild : rightChild;

    // 如果p是右孩子
    while (p % 2 == 1 && p > 1)
    {// 从右孩子开始
        tree[p / 2] = (player[tree[p - 1]] <= player[tree[p]]) ?
                      tree[p - 1] : tree[p];
        p /= 2;  // 到其父亲节点
    }
}


template<class T>
void completeWinnerTree<T>::rePlay(int thePlayer)
{//  为玩家thePlayer重新组织比赛
    int n = numberOfPlayers;
    if (thePlayer <= 0 || thePlayer > n)
        throw illegalParameterValue("Player index is illegal");

    int matchNode,       // 进行下一场比赛的节点
    leftChild,       // matchNode的左孩子
    rightChild;      // matchNode的右孩子

    // 找到第一个match节点和他的孩子
    if (thePlayer <= lowExt)
    {// 从最底层开始
        matchNode = (offset + thePlayer) / 2;
        leftChild = 2 * matchNode - offset;
        rightChild = leftChild + 1;
    }
    else
    {
        matchNode = (thePlayer - lowExt + n - 1) / 2;
        if (2 * matchNode == n - 1)
        {
            leftChild = tree[2 * matchNode];
            rightChild = thePlayer;
        }
        else
        {
            leftChild = 2 * matchNode - n + 1 + lowExt;
            rightChild = leftChild + 1;
        }
    }

    tree[matchNode] = (player[leftChild] <= player[rightChild])
                      ? leftChild : rightChild;

    // 第二场比赛的特殊情况
    if (matchNode == n - 1 && n % 2 == 1)
    {
        matchNode /= 2;   // move to parent
        tree[matchNode] = (player[tree[n - 1]] <=
                           player[lowExt + 1]) ?
                          tree[n - 1] : lowExt + 1;
    }

    // 进行其他比赛，也就是父亲节点的比赛
    matchNode /= 2;  // 移动到父亲节点
    for (; matchNode >= 1; matchNode /= 2)
        tree[matchNode] = (player[tree[2 * matchNode]] <=
                           player[tree[2 * matchNode + 1]]) ?
                          tree[2 * matchNode] : tree[2 * matchNode + 1];
}

template<class T>
void completeWinnerTree<T>::output() const
{
    cout << "number of players  = " << numberOfPlayers
         << " lowExt = " << lowExt
         << " offset = " << offset << endl;
    cout << "complete winner tree pointers are" << endl;
    for (int i = 1; i < numberOfPlayers; i++)
        cout << tree[i] << ' ';
    cout << endl;
}

#endif //_30WINNERTREE_COMPLETEWINNERTREE_H
