/*
Project name :			_30winnerTree
Last modified Date:		2023��12��19��11��18��
Last Version:			V1.0
Descriptions:			��СӮ��������ģ����
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
    // ���ؽڵ�i��ʤ�ߵ�index
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
{// ʹ��thePlayer[1:numberOfPlayers]�����ʼ��Ӯ����
    int n = theNumberOfPlayers;
    if (n < 2)
        throw illegalParameterValue("must have at least 2 players");

    player = thePlayer;
    numberOfPlayers = n;
    delete [] tree;// ���tree
    tree = new int [n];// ����Ϊtree��ʼ���ռ�

    // ����  s = 2^log (n-1)
    int i, s;
    for (s = 1; 2 * s <= n - 1; s += s);

    lowExt = 2 * (n - s);
    offset = 2 * s - 1;

    // ����ײ���ⲿ�ڵ㿪ʼ����
    for (i = 2; i <= lowExt; i += 2)
        play((offset + i) / 2, i - 1, i);

    // ����ʣ����ⲿ�ڵ�
    if (n % 2 == 1) // ��n������ʱ��������һ���ڲ��ڵ���ⲿ�ڵ�ı���
    {
        play(n/2, tree[n - 1], lowExt + 1);
        i = lowExt + 3;
    }
    else i = lowExt + 2;

    // i�����ұߵ��ⲿ�ڵ�
    for (; i <= n; i += 2)
        play((i - lowExt + n - 1) / 2, i - 1, i);
}

template<class T>
void completeWinnerTree<T>::play(int p, int leftChild, int rightChild)
{// ��չtree[p]���ı���
    // leftChild��p������
    // rightChild��p���Һ���
    // ���������ԽС��ʤ��

    tree[p] = (player[leftChild] <= player[rightChild]) ?
              leftChild : rightChild;

    // ���p���Һ���
    while (p % 2 == 1 && p > 1)
    {// ���Һ��ӿ�ʼ
        tree[p / 2] = (player[tree[p - 1]] <= player[tree[p]]) ?
                      tree[p - 1] : tree[p];
        p /= 2;  // ���丸�׽ڵ�
    }
}


template<class T>
void completeWinnerTree<T>::rePlay(int thePlayer)
{//  Ϊ���thePlayer������֯����
    int n = numberOfPlayers;
    if (thePlayer <= 0 || thePlayer > n)
        throw illegalParameterValue("Player index is illegal");

    int matchNode,       // ������һ�������Ľڵ�
    leftChild,       // matchNode������
    rightChild;      // matchNode���Һ���

    // �ҵ���һ��match�ڵ�����ĺ���
    if (thePlayer <= lowExt)
    {// ����ײ㿪ʼ
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

    // �ڶ����������������
    if (matchNode == n - 1 && n % 2 == 1)
    {
        matchNode /= 2;   // move to parent
        tree[matchNode] = (player[tree[n - 1]] <=
                           player[lowExt + 1]) ?
                          tree[n - 1] : lowExt + 1;
    }

    // ��������������Ҳ���Ǹ��׽ڵ�ı���
    matchNode /= 2;  // �ƶ������׽ڵ�
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
