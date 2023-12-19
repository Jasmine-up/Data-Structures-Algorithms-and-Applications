/*
Project name :			_30winnerTree
Last modified Date:		2023��12��19��16��48��
Last Version:			V1.0
Descriptions:			��С����������ģ����
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
    /*���캯��*/
    explicit MinimumLoserTree(T *thePlayer = nullptr, int theNumberOfPlayers = 0) {
        tree = nullptr;
        advance = nullptr;
        initialize(thePlayer, theNumberOfPlayers);
    }

    /*��������*/
    ~MinimumLoserTree() {
        delete[] tree;
        delete[] advance;
    }

    void initialize(T *thePlayer, int theNumberOfPlayers);//��ʼ��
    [[nodiscard]] int getTheWinner() const { return tree[0]; };//�����ǰ��Ӯ��
    void rePlay(int thePlayer, T newvalue);//�ع�
    void output() const;
private:
    int numberOfPlayers{};
    int *tree;// ��¼�ڲ���㣬tree[0]�����յ�Ӯ���±꣬��ʹ�ö�������㣬��Ϊ���ӹ�ϵ����ͨ������ó�
    int *advance;// ��¼���������ĳ�Ա
    T *player;//���������Ԫ��
    int lowExt{};//��ײ��ⲿ���ĸ���,2*(n-s)
    int offset{};//2*s-1
    void play(int, int, int);

    int winner(int x, int y) { return player[x] <= player[y] ? x : y; };//���ظ�С��Ԫ���±�
    int loser(int x, int y) { return player[x] <= player[y] ? y : x; };//���ظ����Ԫ���±�
};

template<class T>
void MinimumLoserTree<T>::initialize(T *thePlayer, int theNumberOfPlayers) {
    int n = theNumberOfPlayers;
    if (n < 2) {
        throw illegalParameterValue("must have at least 2 players");
    }
    player = thePlayer;
    numberOfPlayers = n;
    // ɾ��ԭ����ʼ�����ڴ�ռ䣬��ʼ���µ��ڴ�ռ�
    delete[] tree;
    delete[] advance;
    tree = new int[n + 1];
    advance = new int[n + 1];
    // ����s
    int s;
    for (s = 1; 2 * s <= n - 1; s += s);//s=2^log(n-1)-1�������Ż��ٶȸ��죩��s����ײ�����˵��ڲ����

    lowExt = 2 * (n - s);
    offset = 2 * s - 1;

    for (int i = 2; i <= lowExt; i += 2)//������һ�㿪ʼ����
        play((i + offset) / 2, i - 1, i);//�������㹫ʽ��һ��

    int temp = 0;
    if (n % 2 == 1) {//�������������㣬һ������������������Ҫ�ڲ��ڵ���ⲿ�ڵ�ı���
        play(n / 2, advance[n - 1], lowExt + 1);
        temp = lowExt + 3;
    } else temp = lowExt + 2;//ż������㣬ֱ�Ӵ�����²�

    for (int i = temp; i <= n; i += 2)//�������ѭ�������е��ⲿ��㶼�������
        play((i - lowExt + n - 1) / 2, i - 1, i);

    tree[0] = advance[1];//tree[0]�����յ�Ӯ�ߣ�Ҳ���Ǿ�����Ӯ��

}

template<class T>
void MinimumLoserTree<T>::play(int p, int leftChild, int rightChild) {
    // tree���洢��Խϴ��ֵ��Ҳ�����ⳡ����������
    tree[p] = loser(leftChild, rightChild);
    // advance���洢��Խ�С��ֵ��Ҳ�����ⳡ�����Ľ�����
    advance[p] = winner(leftChild, rightChild);

    // ���p���Һ���
    while (p % 2 == 1 && p > 1) {
        tree[p / 2] = loser(advance[p - 1], advance[p]);
        advance[p / 2] = winner(advance[p - 1], advance[p]);
        p /= 2;//��������
    }
}

template<class T>
void MinimumLoserTree<T>::rePlay(int thePlayer, T newvalue) {
    int n = numberOfPlayers;
    if (thePlayer <= 0 || thePlayer > n) {
        throw illegalParameterValue("Player index is illegal");
    }

    player[thePlayer] = newvalue;

    int matchNode,//��Ҫ�����ĳ���
    leftChild,//������������
    rightChild;//���������Һ���

    if (thePlayer <= lowExt) {//���Ҫ�����Ľ�������²�
        matchNode = (offset + thePlayer) / 2;
        leftChild = 2 * matchNode - offset;
        rightChild = leftChild + 1;
    } else {//Ҫ�����Ľ���ڴ��²�
        matchNode = (thePlayer - lowExt + n - 1) / 2;
        if (2 * matchNode == n - 1) {//���������������һ���ǽ���
            leftChild = advance[2 * matchNode];
            rightChild = thePlayer;
        } else {
            leftChild = 2 * matchNode - n + 1 + lowExt;//�����������Ϊ����matchNode������/2ȡ����
            rightChild = leftChild + 1;
        }
    }
    //��Ŀǰλ�ã������Ѿ�ȷ����Ҫ�����ĳ����Լ�������ѡ��

    //������б����ع���Ҳ���Ǻ�Ӯ�������Ĳ�ͬ�����������
    if (thePlayer == tree[0]) {//����Ҫ�ع��ĵ�����һ��������Ӯ�ҵĻ������̱�Ӯ����Ҫ�򻯣���֮��ֻ��Ҫ�͸��ױȽϣ�����Ҫ���ֵܱȽ�
        for (; matchNode >= 1; matchNode /= 2) {
            int oldLoserNode = tree[matchNode];//��һ������������
            tree[matchNode] = loser(oldLoserNode, thePlayer);
            advance[matchNode] = winner(oldLoserNode, thePlayer);
            thePlayer = advance[matchNode];
        }
    } else {//��������ع���Ӯ������ͬ
        tree[matchNode] = loser(leftChild, rightChild);
        advance[matchNode] = winner(leftChild, rightChild);
        if (matchNode == n - 1 && n % 2 == 1) {//�������
            // ������matchNode/2���������ڲ��ڵ㣬�Һ������ⲿ�ڵ�
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
    tree[0] = advance[1];//����ʤ��
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
