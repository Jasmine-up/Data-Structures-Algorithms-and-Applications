// first fit bin packing

#include <iostream>
#include "MaxmumLoserTree.h"
#include "dBinarySearchTree.h"

using namespace std;

/*����������Ĳ���*/
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

// ���������㷨��ʵ��
/*
 * ���������㷨��ʵ��
 * objectSize����洢�����������objectSize[i]��ʾ����i������
 * numberOfObjects�洢���������
 * binCapacity�洢��ʼʱ���ӵ�����
 * ʱ�临�Ӷȣ�O(nlogn)
 */
void firstFitPack(const int *objectSize, int numberOfObjects,
                  int binCapacity) {// ��ʼ״̬���������Ӷ��ǿյģ�������ΪbinCapacity��objectSize[1:numberOfObjects] = {binCapacity}

    int n = numberOfObjects;             // ����ĸ���

    // ��ʼ������������������Խ�󣬾���ʤ��
    auto *bin = new int[n + 1];  // bins
    for (int i = 1; i <= n; i++)
        bin[i] = binCapacity;
    MaxmumLoserTree loserTreeObj(bin, n);
    loserTreeObj.output();
    // ������i�����������
    for (int i = 1; i <= n; i++) {
        // Ѱ�����㹻�ڴ������
        int child = 2;  // �Ӹ������ӿ�ʼ����
        while (child < n) {
            int winner = loserTreeObj.getTheWinner(child);// �������ӵ�Ӯ��
            if (bin[winner] < objectSize[i]) // ���ӵ�Ӯ���ڴ治�������Һ���
                child++;
            child *= 2;   // �ҵ���ǰ���ӵ����ӣ�������������·����Ҷ�ӽڵ���
        }

        int binToUse;          // ����ΪҪʹ�õ�����
        child /= 2;            // �������������ӵ��ƶ����ҵ��丸��
        if (child < n) {
            binToUse = loserTreeObj.getTheWinner(child);
            // ��֤binToUse������ߵ�����
            if (binToUse > 1 && bin[binToUse - 1] >= objectSize[i])
                binToUse--;
        } else // ��n������ʱ��ǰ���whileѭ�����ܶ�λ�� �ڲ��ڵ����ⲿ�ڵ�������ⲿ�ڵ㣬����child�Ϳ��ܻ�>=n�������Ļ�����Ҫ��λ�����ⲿ�ڵ�ĸ���
            binToUse = loserTreeObj.getTheWinner(
                    child / 2); // ��Ȼǰ���whileѭ����λ���˸ñ���(�ڲ��ڵ����ⲿ�ڵ����)���Һ��ӣ�˵�����Ӳ�����Ҫ��һ�����Һ�����Ӯ��

        cout << "Pack object " << i << " in bin "
             << binToUse << endl;
        bin[binToUse] -= objectSize[i];
        loserTreeObj.rePlay(binToUse);
    }
}

/*���������㷨�Ĳ���*/
void firstFitPackTest(){
    cout << "*************************firstFitPackTest() begin*******************************" << endl;
    int n, binCapacity; // ��������������ӵ�����
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
 * ���������㷨��ʵ��
 * objectSize����洢�����������objectSize[i]��ʾ����i������
 * numberOfObjects�洢���������
 * binCapacity�洢��ʼʱ���ӵ�����
 * ʱ�临�Ӷȣ�O(logn)
 */
void bestFitPack(int *objectSize, int numberOfObjects, int binCapacity) {
    // �������ΪbinCapacity����������ƥ��.
    // objectSize[1:numberOfObjects]��ʾ��Ʒ��С
    int n = numberOfObjects;
    int binsUsed = 0; // ��ʾʹ���˶��ٸ����ӣ����������ȡ����
    // ���������� pair<K, E>.first��ʾ���ӵ�������pair<K, E>.second��ʾ���ӵ�����
    dBinarySearchTree<int, int> theTree;
    pair<int, int> theBin;

    // ����Ʒ���װ��
    for (int i = 1; i <= n; i++) {
        // ����Ʒiװ��
        // Ѱ������ʵ�����
        pair<int, int> *bestBin = theTree.findGE(objectSize[i]);
        if (bestBin == nullptr) {// û���㹻������ӣ�����һ��������
            theBin.first = binCapacity;
            theBin.second = ++binsUsed;
        } else {// ����theTree��ɾ����ƥ�������
            theBin = *bestBin;
            theTree.erase(bestBin->first);
        }

        cout << "Pack object " << i << " in bin "
             << theBin.second << endl;

        // �����Ӳ嵽���У�������������
        theBin.first -= objectSize[i];
        if (theBin.first > 0)
            theTree.insert(theBin);
    }
}

/*���������㷨����*/
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

    // ���������СobjectSize[1:numberOfObjects]
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

    // �����װ��Ʒ�����ӵĽ��
    bestFitPack(objectSize, numberOfObjects, binCapacity);
    delete [] objectSize;
    cout << "*************************bestFitPackTest() end*******************************" << endl;
}


// test program
int main() {
    /*���������㷨����*/
    firstFitPackTest();
    /*���������㷨����*/
    bestFitPackTest();
    return 0;
}
