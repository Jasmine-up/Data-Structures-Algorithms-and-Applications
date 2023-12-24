/*
Project name :			_33Search_tree
Last modified Date:		2023��12��21��11��13��
Last Version:			V1.0
Descriptions:			�����������������Ժ�������
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

/*������������Ӧ��*/
/*
 *  ֱ��ͼ�ļ���
 *  ʱ�临�Ӷȣ�O(n)�����ǵ��ؼ��ֲ������ͻ��߷�Χ�ܴ�ʱ����������
 */
void SimpleHistogramSolution() {
    cout << "***************************SimpleHistogramSolution() begin*******************************" << endl;

    int n, r;  // Ԫ�ظ�����Ԫ�ص�����
    cout << "Enter number of elements and range" << endl;
    cin >> n >> r;
    // ����ֱ��ͼ����h
    int *h = new int[r + 1];
    // ��ʼ��ֱ��ͼ����h
    for (int i = 0; i <= r; i++)
        h[i] = 0;
    for (int i = 1; i <= n; i++) {
        int key;// ���������ֵ��0-r֮��
        cout << "Enter element " << i << endl;
        cin >> key;
        h[key]++;
    }

    // ���ֱ��ͼ
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
 *  ֱ��ͼ�Ķ�����������
 *  ʱ�临�Ӷȣ�O(nlog(m))��n��ʾ����ؼ��ָ�����m��ʾ�ؼ����ж�����
 *  ��m��Сʱ���˷����ǳ�����
 */
void binarySearchTreeHistogramSolution() {
    cout << "***************************binarySearchTreeHistogramSolution() begin*******************************" << endl;

    int n;  // Ԫ�ظ���
    cout << "Enter number of elements" << endl;
    cin >> n;

    // ����Ԫ�ز����뵽������������
    binarySearchTree<int, int> theTree;
    for (int i = 1; i <= n; i++) {
        pair<int, int> thePair;  // ����Ԫ��
        cout << "Enter element " << i << endl;
        cin >> thePair.first;    // ��ֵ
        thePair.second = 1;      // Ƶ��
        // ����һ�Բ��뵽���У�����ƥ���Ѿ����ڣ��ں�һ������¶�Ӧ�ļ�ֵ����1
        theTree.insert(thePair, add);
    }

    // ���ֱ��ͼ
    cout << "Distinct elements and frequencies are"
         << endl;
    theTree.ascend();
    cout << "***************************binarySearchTreeHistogramSolution() end*******************************" << endl;

}

/*
 * ����ֲ��ļ���
 * ��̫�������ף�����ѧ���ᣬ�����������Ľⷨ�ͷ�����
 * ʱ�临�Ӷȣ�O(n^2)
 */
void SimpleCrossDistribution() {
    cout << "***************************SimpleCrossDistribution() begin*******************************" << endl;

    // ����Ҫ���������ʵ��
    // ��ͨ���ײ������ӵ�theC[1:10]
    int theC[] = {0, 8, 7, 4, 2, 5, 1, 9, 3, 10, 6};
    // ��������k[1:10]
    int k[] = {0, 7,6,3,1,2,0,2,0,1,0};
    int n = 10;// ��ͨ��ÿһ�ߵ��������
    int theK = 22;// ����������

    // �������ݽṹ
    std::vector<int> theList(n);
    int * theA = new int[n + 1];// ���˵�����
    int * theB = new int[n + 1];// �׶˵�����
    int * theX = new int[n + 1];// �м�����У�������һ����·���ӵ��м�������
    // ��Ҫ���ϰ벿�ֱ����Ľ�����
    int crossingsNeeded = theK / 2;
    // ���ҵ���ɨ����·
    // �������cur�ཻ��k[cur]����·�е�c�����䵽�ϰ벿�֣���ô������·�ض���theList�е�ǰc����·�ཻ��
    int currentWire = n;
    while(currentWire > 0){
        if(k[currentWire] < crossingsNeeded){
            // ʹ������cur�����н���
            theList.insert(theList.begin() + k[currentWire], currentWire);
            crossingsNeeded -= k[currentWire];
        }
        else{
            // ��ʹ������cur��crossingsNeeded
            theList.insert(theList.begin() + crossingsNeeded, currentWire);
            crossingsNeeded = 0;
        }
        currentWire--;
    }

    // ȷ���м����·����
    // ǰ����һ�εĽ���ŵ��°벿��������ӵ��Լ�ƽ�еĵط�����
    for(int i = 1; i <= currentWire; i++)
        theX[i] = i;

    // ʣ����·�������Ա�theX��ʾ��һ����·���ӵ��м�������
    for(int i = currentWire + 1; i <= n; i++)
        theX[i] = theList[i - currentWire - 1];

    // �����ϰ벿������
    for(int i = 1; i <= n; i++)
        theA[theX[i]] = i;

    // �����°벿������
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