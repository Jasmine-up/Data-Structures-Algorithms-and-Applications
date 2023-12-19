/*
Project name :			_30winnerTree
Last modified Date:		2023年12月19日11点18分
Last Version:			V1.0
Descriptions:			最小赢者树——测试函数
*/

#include <iostream>
#include "completeWinnerTree.h"
#include "player.h"

using namespace std;

void completeWinnerTreeTest()
{
    int n;
    cout << "Enter number of players, >= 2" << endl;
    cin >> n;
    if (n < 2)
    {cout << "Bad input" << endl;
        exit(1);}


    player *thePlayer = new player[n + 1];

    cout << "Enter player values" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> thePlayer[i].key;
        thePlayer[i].id = i;
    }

    completeWinnerTree<player> *w =
            new completeWinnerTree<player>(thePlayer, n);
    cout << "The winner tree is" << endl;
    w->output();

    thePlayer[2].key = 0;
    w->rePlay(2);
    cout << "Changed player 2 to zero, new tree is" << endl;
    w->output();

    thePlayer[3].key = -1;
    w->rePlay(3);
    cout << "Changed player 3 to -1, new tree is" << endl;
    w->output();

    thePlayer[7].key = 2;
    w->rePlay(7);
    cout << "Changed player 7 to 2, new tree is" << endl;
    w->output();
    delete [] thePlayer;
    delete w;
}
