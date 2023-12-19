/*
Project name :			_30winnerTree
Last modified Date:		2023年12月19日16点48分
Last Version:			V1.0
Descriptions:			最小输者树——测试函数
*/
#include "MinimumLoserTree.h"

void MinimumLoserTreeTest(){
    int n;
    cout << "Enter number of players, >= 2" << endl;
    cin >> n;
    if (n < 2)
    {cout << "Bad input" << endl;
        exit(1);}


    int *thePlayer = new int[n + 1];

    cout << "Enter player values" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> thePlayer[i];
    }

    MinimumLoserTree<int> *w =
            new MinimumLoserTree<int>(thePlayer, n);
    cout << "The loser tree is" << endl;
    w->output();

    w->rePlay(2, 0);
    cout << "Changed player 2 to zero, new tree is" << endl;
    w->output();

    w->rePlay(3, -1);
    cout << "Changed player 3 to -1, new tree is" << endl;
    w->output();

    w->rePlay(7, 2);
    cout << "Changed player 7 to 2, new tree is" << endl;
    w->output();
    delete [] thePlayer;
    delete w;
}