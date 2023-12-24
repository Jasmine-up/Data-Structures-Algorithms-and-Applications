/*
Project name :			_33Search_tree
Last modified Date:		2023年12月21日11点13分
Last Version:			V1.0
Descriptions:			二叉搜索树——测试函数汇总
*/
#include "binarySearchTree.h"
#include "dBinarySearchTree.h"
#include "indexedBinarySearchTree.h"
#include<vector>

void binarySearchTreeTest() {
    cout << "*************************binarySearchTreeTest() begin*******************************" << endl;
    binarySearchTree<int, char> y;
    y.insert(pair<int, char>(30, 'a'));
    y.insert(pair<int, char>(5, 'b'));
    y.insert(pair<int, char>(60, 'c'));
    y.insert(pair<int, char>(2, 'd'));
    y.insert(pair<int, char>(35, 'e'));
    y.insert(pair<int, char>(80, 'f'));
    y.insert(pair<int, char>(32, 'g'));
    y.insert(pair<int, char>(85, 'h'));
    y.insert(pair<int, char>(31, 'i'));
    y.insert(pair<int, char>(33, 'j'));
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();

    pair<int, char> *s = y.find(60);
    cout << "Search for 60 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(60);
    cout << "60 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();

    s = y.find(80);
    cout << "Search for 80 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(80);
    cout << "80 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();

    s = y.find(30);
    cout << "Search for 30 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(30);
    cout << "30 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();

    s = y.find(35);
    cout << "Search for 35 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(35);
    cout << "35 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();
    cout << "***************************binarySearchTreeTest() end*******************************" << endl;
}

void dBinarySearchTreeTest() {
    cout << "*************************dBinarySearchTreeTest() begin*******************************" << endl;
    dBinarySearchTree<int, char> y;
    y.insert(pair<int, char>(30, 'a'));
    y.insert(pair<int, char>(5, 'b'));
    y.insert(pair<int, char>(60, 'c'));
    y.insert(pair<int, char>(30, 'd'));
    y.insert(pair<int, char>(35, 'e'));
    y.insert(pair<int, char>(80, 'f'));
    y.insert(pair<int, char>(32, 'g'));
    y.insert(pair<int, char>(30, 'h'));
    y.insert(pair<int, char>(31, 'i'));
    y.insert(pair<int, char>(33, 'j'));
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();

    pair<int, char> *s = y.find(30);
    cout << "Search for 30 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(30);
    cout << "30 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();

    s = y.find(30);
    cout << "Search for 30 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(30);
    cout << "30 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();

    s = y.find(30);
    cout << "Search for 30 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(30);
    cout << "30 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();
    cout << "***************************dBinarySearchTreeTest() end*******************************" << endl;
}

void indexedBinarySearchTreeTest() {
    cout << "*************************indexedBinarySearchTreeTest() begin*******************************" << endl;
    indexedBinarySearchTree<int, char> y;
    y.insert(pair<int, char>(30, 'a'));
    y.insert(pair<int, char>(5, 'b'));
    y.insert(pair<int, char>(60, 'c'));
    y.insert(pair<int, char>(2, 'd'));
    y.insert(pair<int, char>(35, 'e'));
    y.insert(pair<int, char>(80, 'f'));
    y.insert(pair<int, char>(32, 'g'));
    y.insert(pair<int, char>(85, 'h'));
    y.insert(pair<int, char>(31, 'i'));
    y.insert(pair<int, char>(33, 'j'));
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();

    pair<int, char> *s = y.get(0);
    if (s != nullptr)
        cout << "get the index " << 0 << " element: " << *s << endl;
    s = y.get(1);
    if (s != nullptr)
        cout << "get the index " << 1 << " element: " << *s << endl;
    s = y.get(2);
    if (s != nullptr)
        cout << "get the index " << 2 << " element: " << *s << endl;
    s = y.get(3);
    if (s != nullptr)
        cout << "get the index " << 3 << " element: " << *s << endl;
    s = y.get(4);
    if (s != nullptr)
        cout << "get the index " << 4 << " element: " << *s << endl;
    s = y.get(5);
    if (s != nullptr)
        cout << "get the index " << 5 << " element: " << *s << endl;
    s = y.get(6);
    if (s != nullptr)
        cout << "get the index " << 6 << " element: " << *s << endl;
    s = y.get(7);
    if (s != nullptr)
        cout << "get the index " << 7 << " element: " << *s << endl;
    s = y.get(8);
    if (s != nullptr)
        cout << "get the index " << 8 << " element: " << *s << endl;
    s = y.get(9);
    if (s != nullptr)
        cout << "get the index " << 9 << " element: " << *s << endl;

    s = y.find(30);
    cout << "Search for 30 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(30);
    cout << "30 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();
    s = y.find(60);
    cout << "Search for 60 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(60);
    cout << "60 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();
    s = y.find(32);
    cout << "Search for 32 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(32);
    cout << "32 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();
    s = y.find(80);
    cout << "Search for 80 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(80);
    cout << "80 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();
    s = y.find(31);
    cout << "Search for 31 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(31);
    cout << "31 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();
    s = y.find(35);
    cout << "Search for 35 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(35);
    cout << "35 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();
    s = y.find(85);
    cout << "Search for 85 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(85);
    cout << "85 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();
    s = y.find(5);
    cout << "Search for 5 succeeds " << endl;
    cout << s->first << ' ' << s->second << endl;
    y.erase(5);
    cout << "5 deleted " << endl;
    cout << "Tree size is " << y.size() << endl;
    cout << "Elements in ascending order are" << endl;
    y.ascend();
    cout << "***************************indexedBinarySearchTreeTest() end*******************************" << endl;
}

/*二叉搜索树的应用*/
/*
 *  直方图的简单求法
 *  时间复杂度：O(n)，但是当关键字不是整型或者范围很大时，不再适用
 */
void SimpleHistogramSolution() {
    cout << "***************************SimpleHistogramSolution() begin*******************************" << endl;

    int n, r;  // 元素个数，元素的上限
    cout << "Enter number of elements and range" << endl;
    cin >> n >> r;
    // 生成直方图数组h
    int *h = new int[r + 1];
    // 初始化直方图数组h
    for (int i = 0; i <= r; i++)
        h[i] = 0;
    for (int i = 1; i <= n; i++) {
        int key;// 假设输入的值在0-r之间
        cout << "Enter element " << i << endl;
        cin >> key;
        h[key]++;
    }

    // 输出直方图
    cout << "Distinct elements and frequencies are"
         << endl;
    for (int i = 0; i <= r; i++)
        if (h[i] != 0)
            cout << i << "  " << h[i] << endl;
    delete[] h;
    cout << "***************************SimpleHistogramSolution() end*******************************" << endl;
}

void add(int &count) { count++; }

/*
 *  直方图的二叉搜索树求法
 *  时间复杂度：O(nlog(m))，n表示输入关键字个数，m表示关键字有多少种
 *  当m很小时，此方法非常好用
 */
void binarySearchTreeHistogramSolution() {
    cout << "***************************binarySearchTreeHistogramSolution() begin*******************************" << endl;

    int n;  // 元素个数
    cout << "Enter number of elements" << endl;
    cin >> n;

    // 输入元素并插入到二叉搜索树中
    binarySearchTree<int, int> theTree;
    for (int i = 1; i <= n; i++) {
        pair<int, int> thePair;  // 输入元素
        cout << "Enter element " << i << endl;
        cin >> thePair.first;    // 键值
        thePair.second = 1;      // 频率
        // 将这一对插入到树中，除非匹配已经存在，在后一种情况下对应的键值增加1
        theTree.insert(thePair, add);
    }

    // 输出直方图
    cout << "Distinct elements and frequencies are"
         << endl;
    theTree.ascend();
    cout << "***************************binarySearchTreeHistogramSolution() end*******************************" << endl;

}

/*
 * 交叉分布的简单求法
 * 不太看得明白，由于学不会，索引二叉树的解法就放弃了
 * 时间复杂度：O(n^2)
 */
void SimpleCrossDistribution() {
    cout << "***************************SimpleCrossDistribution() begin*******************************" << endl;

    // 定义要解决的问题实例
    // 在通道底部的连接点theC[1:10]
    int theC[] = {0, 8, 7, 4, 2, 5, 1, 9, 3, 10, 6};
    // 交叉数量k[1:10]
    int k[] = {0, 7,6,3,1,2,0,2,0,1,0};
    int n = 10;// 在通道每一边的针脚数量
    int theK = 22;// 交叉总数量

    // 生成数据结构
    std::vector<int> theList(n);
    int * theA = new int[n + 1];// 顶端的排列
    int * theB = new int[n + 1];// 底端的排列
    int * theX = new int[n + 1];// 中间的排列：表明哪一条线路连接到中间的针脚上
    // 需要在上半部分保留的交叉数
    int crossingsNeeded = theK / 2;
    // 从右到左扫描线路
    // 如果将与cur相交的k[cur]条线路中的c条分配到上半部分，那么这条线路必定与theList中的前c条线路相交。
    int currentWire = n;
    while(currentWire > 0){
        if(k[currentWire] < crossingsNeeded){
            // 使用来自cur的所有交叉
            theList.insert(theList.begin() + k[currentWire], currentWire);
            crossingsNeeded -= k[currentWire];
        }
        else{
            // 仅使用来自cur的crossingsNeeded
            theList.insert(theList.begin() + crossingsNeeded, currentWire);
            crossingsNeeded = 0;
        }
        currentWire--;
    }

    // 确定中间的线路排列
    // 前面这一段的交叉放到下半部，因此连接到自己平行的地方就行
    for(int i = 1; i <= currentWire; i++)
        theX[i] = i;

    // 剩余线路次序来自表，theX表示哪一条线路连接到中间的针脚上
    for(int i = currentWire + 1; i <= n; i++)
        theX[i] = theList[i - currentWire - 1];

    // 计算上半部的排列
    for(int i = 1; i <= n; i++)
        theA[theX[i]] = i;

    // 计算下半部的排列
    for(int i = 1; i <= n; i++)
        theB[i] = theC[theX[i]];

    cout << "A is ";
    for(int i = 1; i <= n; i++)
        cout << theA[i] << " ";
    cout << endl;

    cout << "B is ";
    for(int i = 1; i <= n; i++)
        cout << theB[i] << " ";
    cout << endl;

    delete [] theA;
    delete [] theB;
    delete [] theX;
    cout << "***************************SimpleCrossDistribution() end*******************************" << endl;
}