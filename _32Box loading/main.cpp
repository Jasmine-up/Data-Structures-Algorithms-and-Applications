// first fit bin packing

#include <iostream>
#include "MaxmumLoserTree.h"
using namespace std;

// 最先适配算法的实现
/*
 * 最先适配算法的实现
 * objectSize数组存储物体的重量，objectSize[i]表示物体i的重量
 * numberOfObjects存储物体的数量
 * binCapacity存储初始时箱子的容量
 */
void firstFitPack(const int *objectSize, int numberOfObjects,
                  int binCapacity)
{// 初始状态下所有箱子都是空的，容量都为binCapacity。objectSize[1:numberOfObjects] = {binCapacity}

    int n = numberOfObjects;             // 物体的个数

    // 初始化输者树，箱子容量越大，就是胜者
    auto *bin = new int[n + 1];  // bins
    for (int i = 1; i <= n; i++)
        bin[i] = binCapacity;
    MaxmumLoserTree loserTreeObj(bin, n);
    loserTreeObj.output();
    // 将物体i打包到箱子中
    for (int i = 1; i <= n; i++)
    {
        // 寻找有足够内存的箱子
        int child = 2;  // 从根的左孩子开始搜索
        while (child < n)
        {
            int winner = loserTreeObj.getTheWinner(child);// 返回左孩子的赢者
            if (bin[winner] < objectSize[i]) // 左孩子的赢者内存不够，找右孩子
                child++;
            child *= 2;   // 找到当前孩子的左孩子，继续沿着树的路径往叶子节点走
        }

        int binToUse;          // 设置为要使用的箱子
        child /= 2;            // 撤销向最后的左孩子的移动，找到其父亲
        if (child < n)
        {
            binToUse = loserTreeObj.getTheWinner(child);
            // 保证binToUse是最左边的箱子
            if (binToUse > 1 && bin[binToUse - 1] >= objectSize[i])
                binToUse--;
        }
        else // 当n是奇数时，前面的while循环可能定位到 内部节点与外部节点比赛的外部节点，这样child就可能会>=n，这样的话就需要定位到该外部节点的父亲
            binToUse = loserTreeObj.getTheWinner(child / 2); // 既然前面的while循环定位到了该比赛(内部节点与外部节点比赛)的右孩子，说明左孩子不符合要求，一定是右孩子是赢者

        cout << "Pack object " << i << " in bin "
             << binToUse << endl;
        bin[binToUse] -= objectSize[i];
        loserTreeObj.rePlay(binToUse);
    }
}


// test program
int main()
{
//    int n;
//    cout << "Enter number of players, >= 2" << endl;
//    cin >> n;
//    if (n < 2)
//    {cout << "Bad input" << endl;
//        exit(1);}
//
//
//    int *thePlayer = new int[n + 1];
//
//    cout << "Enter player values" << endl;
//    for (int i = 1; i <= n; i++)
//    {
//        cin >> thePlayer[i];
//    }
//
//    MaxmumLoserTree<int> *w =
//            new MaxmumLoserTree<int>(thePlayer, n);
//    cout << "The loser tree is" << endl;
//    w->output();
    int n, binCapacity; // 物体的数量与箱子的容量
    cout << "Enter number of objects and bin capacity"
         << endl;
    cin >> n >> binCapacity;
    if (n < 2)
        throw illegalParameterValue("must have at least 2 objects");
    int *objectSize = new int[n+1];

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter space requirement of object "
             << i << endl;
        cin >> objectSize[i];
        if (objectSize[i] > binCapacity)
            throw illegalParameterValue("Object too large to fit in a bin");
    }
    firstFitPack(objectSize, n, binCapacity);
    delete [] objectSize;
    return 0;
}
