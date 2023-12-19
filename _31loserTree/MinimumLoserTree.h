/*
Project name :			_30winnerTree
Last modified Date:		2023年12月19日16点48分
Last Version:			V1.0
Descriptions:			最小输者树——模板类
*/

#ifndef _31LOSERTREE_MINIMUMLOSERTREE_H
#define _31LOSERTREE_MINIMUMLOSERTREE_H
#include<iostream>
#include "loserTree.h"
#include "myExceptions.h"
using namespace std;

void MinimumLoserTreeTest();

template<class T>
class MinimumLoserTree : public loserTree<T> {
public:
    /*构造函数*/
    explicit MinimumLoserTree(T *thePlayer = nullptr, int theNumberOfPlayers = 0) {
        tree = nullptr;
        advance = nullptr;
        initialize(thePlayer, theNumberOfPlayers);
    }

    /*析构函数*/
    ~MinimumLoserTree() {
        delete[] tree;
        delete[] advance;
    }

    void initialize(T *thePlayer, int theNumberOfPlayers);//初始化
    [[nodiscard]] int getTheWinner() const { return tree[0]; };//输出当前的赢者
    void rePlay(int thePlayer, T newvalue);//重构
    void output() const;
private:
    int numberOfPlayers{};
    int *tree;// 记录内部结点，tree[0]是最终的赢者下标，不使用二叉树结点，因为父子关系都是通过计算得出
    int *advance;// 记录比赛晋级的成员
    T *player;//参与比赛的元素
    int lowExt{};//最底层外部结点的个数,2*(n-s)
    int offset{};//2*s-1
    void play(int, int, int);

    int winner(int x, int y) { return player[x] <= player[y] ? x : y; };//返回更小的元素下标
    int loser(int x, int y) { return player[x] <= player[y] ? y : x; };//返回更大的元素下标
};

template<class T>
void MinimumLoserTree<T>::initialize(T *thePlayer, int theNumberOfPlayers) {
    int n = theNumberOfPlayers;
    if (n < 2) {
        throw illegalParameterValue("must have at least 2 players");
    }
    player = thePlayer;
    numberOfPlayers = n;
    // 删除原来初始化的内存空间，初始化新的内存空间
    delete[] tree;
    delete[] advance;
    tree = new int[n + 1];
    advance = new int[n + 1];
    // 计算s
    int s;
    for (s = 1; 2 * s <= n - 1; s += s);//s=2^log(n-1)-1（常数优化速度更快），s是最底层最左端的内部结点

    lowExt = 2 * (n - s);
    offset = 2 * s - 1;

    for (int i = 2; i <= lowExt; i += 2)//最下面一层开始比赛
        play((i + offset) / 2, i - 1, i);//父结点计算公式第一条

    int temp = 0;
    if (n % 2 == 1) {//如果有奇数个结点，一定会存在特殊情况，需要内部节点和外部节点的比赛
        play(n / 2, advance[n - 1], lowExt + 1);
        temp = lowExt + 3;
    } else temp = lowExt + 2;//偶数个结点，直接处理次下层

    for (int i = temp; i <= n; i += 2)//经过这个循环，所有的外部结点都处理完毕
        play((i - lowExt + n - 1) / 2, i - 1, i);

    tree[0] = advance[1];//tree[0]是最终的赢者，也就是决赛的赢者

}

template<class T>
void MinimumLoserTree<T>::play(int p, int leftChild, int rightChild) {
    // tree结点存储相对较大的值，也就是这场比赛的输者
    tree[p] = loser(leftChild, rightChild);
    // advance结点存储相对较小的值，也就是这场比赛的晋级者
    advance[p] = winner(leftChild, rightChild);

    // 如果p是右孩子
    while (p % 2 == 1 && p > 1) {
        tree[p / 2] = loser(advance[p - 1], advance[p]);
        advance[p / 2] = winner(advance[p - 1], advance[p]);
        p /= 2;//向上搜索
    }
}

template<class T>
void MinimumLoserTree<T>::rePlay(int thePlayer, T newvalue) {
    int n = numberOfPlayers;
    if (thePlayer <= 0 || thePlayer > n) {
        throw illegalParameterValue("Player index is illegal");
    }

    player[thePlayer] = newvalue;

    int matchNode,//将要比赛的场次
    leftChild,//比赛结点的左孩子
    rightChild;//比赛结点的右孩子

    if (thePlayer <= lowExt) {//如果要比赛的结点在最下层
        matchNode = (offset + thePlayer) / 2;
        leftChild = 2 * matchNode - offset;
        rightChild = leftChild + 1;
    } else {//要比赛的结点在次下层
        matchNode = (thePlayer - lowExt + n - 1) / 2;
        if (2 * matchNode == n - 1) {//特殊情况，比赛的一方是晋级
            leftChild = advance[2 * matchNode];
            rightChild = thePlayer;
        } else {
            leftChild = 2 * matchNode - n + 1 + lowExt;//这个操作是因为上面matchNode计算中/2取整了
            rightChild = leftChild + 1;
        }
    }
    //到目前位置，我们已经确定了要比赛的场次以及比赛的选手

    //下面进行比赛重构，也就是和赢者树最大的不同，分两种情况
    if (thePlayer == tree[0]) {//当你要重构的点是上一场比赛的赢家的话，过程比赢者树要简化，简化之后只需要和父亲比较，不需要和兄弟比较
        for (; matchNode >= 1; matchNode /= 2) {
            int oldLoserNode = tree[matchNode];//上一场比赛的输者
            tree[matchNode] = loser(oldLoserNode, thePlayer);
            advance[matchNode] = winner(oldLoserNode, thePlayer);
            thePlayer = advance[matchNode];
        }
    } else {//其他情况重构和赢者树相同
        tree[matchNode] = loser(leftChild, rightChild);
        advance[matchNode] = winner(leftChild, rightChild);
        if (matchNode == n - 1 && n % 2 == 1) {//特殊情况
            // 特殊在matchNode/2后，左孩子是内部节点，右孩子是外部节点
            matchNode /= 2;
            tree[matchNode] = loser(advance[n - 1], lowExt + 1);
            advance[matchNode] = winner(advance[n - 1], lowExt + 1);
        }
        matchNode /= 2;
        for (; matchNode >= 1; matchNode /= 2) {
            tree[matchNode] = loser(advance[matchNode * 2], advance[matchNode * 2 + 1]);
            advance[matchNode] = winner(advance[matchNode * 2], advance[matchNode * 2 + 1]);
        }
    }
    tree[0] = advance[1];//最终胜者
}

template<class T>
void MinimumLoserTree<T>::output() const
{
    cout << "number of players = " << numberOfPlayers
         << " lowExt = " << lowExt
         << " offset = " << offset << endl;
    cout << "complete loser tree pointers are" << endl;
    for (int i = 1; i < numberOfPlayers; i++)
        cout << tree[i] << ' ';
    cout << endl;
}

#endif //_31LOSERTREE_MINIMUMLOSERTREE_H
