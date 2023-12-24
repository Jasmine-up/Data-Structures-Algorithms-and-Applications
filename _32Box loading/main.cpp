// first fit bin packing

#include <iostream>
#include "MaxmumLoserTree.h"
#include "dBinarySearchTree.h"

using namespace std;

/*最大输者树的测试*/
void MaxmumLoserTreeTest() {
    cout << "*************************MaxmumLoserTreeTest() begin*******************************" << endl;
    int n;
    cout << "Enter number of players, >= 2" << endl;
    cin >> n;
    if (n < 2) {
        cout << "Bad input" << endl;
        exit(1);
    }
    int *thePlayer = new int[n + 1];

    cout << "Enter player values" << endl;
    for (int i = 1; i <= n; i++) {
        cin >> thePlayer[i];
    }

    auto *w = new MaxmumLoserTree<int>(thePlayer, n);
    cout << "The loser tree is" << endl;
    w->output();
    cout << "*************************MaxmumLoserTreeTest() end*******************************" << endl;
}

// 最先适配算法的实现
/*
 * 最先适配算法的实现
 * objectSize数组存储物体的重量，objectSize[i]表示物体i的重量
 * numberOfObjects存储物体的数量
 * binCapacity存储初始时箱子的容量
 * 时间复杂度：O(nlogn)
 */
void firstFitPack(const int *objectSize, int numberOfObjects,
                  int binCapacity) {// 初始状态下所有箱子都是空的，容量都为binCapacity。objectSize[1:numberOfObjects] = {binCapacity}

    int n = numberOfObjects;             // 物体的个数

    // 初始化输者树，箱子容量越大，就是胜者
    auto *bin = new int[n + 1];  // bins
    for (int i = 1; i <= n; i++)
        bin[i] = binCapacity;
    MaxmumLoserTree loserTreeObj(bin, n);
    loserTreeObj.output();
    // 将物体i打包到箱子中
    for (int i = 1; i <= n; i++) {
        // 寻找有足够内存的箱子
        int child = 2;  // 从根的左孩子开始搜索
        while (child < n) {
            int winner = loserTreeObj.getTheWinner(child);// 返回左孩子的赢者
            if (bin[winner] < objectSize[i]) // 左孩子的赢者内存不够，找右孩子
                child++;
            child *= 2;   // 找到当前孩子的左孩子，继续沿着树的路径往叶子节点走
        }

        int binToUse;          // 设置为要使用的箱子
        child /= 2;            // 撤销向最后的左孩子的移动，找到其父亲
        if (child < n) {
            binToUse = loserTreeObj.getTheWinner(child);
            // 保证binToUse是最左边的箱子
            if (binToUse > 1 && bin[binToUse - 1] >= objectSize[i])
                binToUse--;
        } else // 当n是奇数时，前面的while循环可能定位到 内部节点与外部节点比赛的外部节点，这样child就可能会>=n，这样的话就需要定位到该外部节点的父亲
            binToUse = loserTreeObj.getTheWinner(
                    child / 2); // 既然前面的while循环定位到了该比赛(内部节点与外部节点比赛)的右孩子，说明左孩子不符合要求，一定是右孩子是赢者

        cout << "Pack object " << i << " in bin "
             << binToUse << endl;
        bin[binToUse] -= objectSize[i];
        loserTreeObj.rePlay(binToUse);
    }
}

/*最先适配算法的测试*/
void firstFitPackTest(){
    cout << "*************************firstFitPackTest() begin*******************************" << endl;
    int n, binCapacity; // 物体的数量与箱子的容量
    cout << "Enter number of objects and bin capacity"
         << endl;
    cin >> n >> binCapacity;
    if (n < 2)
        throw illegalParameterValue("must have at least 2 objects");
    int *objectSize = new int[n + 1];

    for (int i = 1; i <= n; i++) {
        cout << "Enter space requirement of object "
             << i << endl;
        cin >> objectSize[i];
        if (objectSize[i] > binCapacity)
            throw illegalParameterValue("Object too large to fit in a bin");
    }
    firstFitPack(objectSize, n, binCapacity);
    delete[] objectSize;
    cout << "*************************firstFitPackTest() end*******************************" << endl;
}
/*
 * 最优适配算法的实现
 * objectSize数组存储物体的重量，objectSize[i]表示物体i的重量
 * numberOfObjects存储物体的数量
 * binCapacity存储初始时箱子的容量
 * 时间复杂度：O(logn)
 */
void bestFitPack(int *objectSize, int numberOfObjects, int binCapacity) {
    // 输出容量为binCapacity的最优箱子匹配.
    // objectSize[1:numberOfObjects]表示物品大小
    int n = numberOfObjects;
    int binsUsed = 0; // 表示使用了多少个箱子，方便给箱子取名字
    // 箱子容量树 pair<K, E>.first表示箱子的容量，pair<K, E>.second表示箱子的名称
    dBinarySearchTree<int, int> theTree;
    pair<int, int> theBin;

    // 将物品逐个装箱
    for (int i = 1; i <= n; i++) {
        // 将物品i装箱
        // 寻找最合适的箱子
        pair<int, int> *bestBin = theTree.findGE(objectSize[i]);
        if (bestBin == nullptr) {// 没有足够大的箱子，启用一个新箱子
            theBin.first = binCapacity;
            theBin.second = ++binsUsed;
        } else {// 从树theTree中删除最匹配的箱子
            theBin = *bestBin;
            theTree.erase(bestBin->first);
        }

        cout << "Pack object " << i << " in bin "
             << theBin.second << endl;

        // 将箱子插到树中，除非箱子已满
        theBin.first -= objectSize[i];
        if (theBin.first > 0)
            theTree.insert(theBin);
    }
}

/*最优适配算法测试*/
void bestFitPackTest(){
    cout << "*************************bestFitPackTest() begin*******************************" << endl;
    cout << "Enter number of objects and bin capacity" << endl;
    int numberOfObjects, binCapacity;
    cin >> numberOfObjects >> binCapacity;
    if (numberOfObjects < 2)
    {
        cout << "Too few objects" << endl;
        exit(1);
    }

    // 输入物体大小objectSize[1:numberOfObjects]
    int *objectSize = new int [numberOfObjects + 1];
    for (int i = 1; i <= numberOfObjects; i++)
    {
        cout << "Enter space requirement of object " << i << endl;
        cin >> objectSize[i];
        if (objectSize[i] > binCapacity)
        {
            cout << "Object too large to fit in a bin" << endl;
            exit(1);
        }
    }

    // 输出分装物品到箱子的结果
    bestFitPack(objectSize, numberOfObjects, binCapacity);
    delete [] objectSize;
    cout << "*************************bestFitPackTest() end*******************************" << endl;
}


// test program
int main() {
    /*最先适配算法测试*/
    firstFitPackTest();
    /*最优适配算法测试*/
    bestFitPackTest();
    return 0;
}
