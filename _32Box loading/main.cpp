// first fit bin packing

#include <iostream>
#include "MaxmumLoserTree.h"
using namespace std;

// ���������㷨��ʵ��
/*
 * ���������㷨��ʵ��
 * objectSize����洢�����������objectSize[i]��ʾ����i������
 * numberOfObjects�洢���������
 * binCapacity�洢��ʼʱ���ӵ�����
 */
void firstFitPack(const int *objectSize, int numberOfObjects,
                  int binCapacity)
{// ��ʼ״̬���������Ӷ��ǿյģ�������ΪbinCapacity��objectSize[1:numberOfObjects] = {binCapacity}

    int n = numberOfObjects;             // ����ĸ���

    // ��ʼ������������������Խ�󣬾���ʤ��
    auto *bin = new int[n + 1];  // bins
    for (int i = 1; i <= n; i++)
        bin[i] = binCapacity;
    MaxmumLoserTree loserTreeObj(bin, n);
    loserTreeObj.output();
    // ������i�����������
    for (int i = 1; i <= n; i++)
    {
        // Ѱ�����㹻�ڴ������
        int child = 2;  // �Ӹ������ӿ�ʼ����
        while (child < n)
        {
            int winner = loserTreeObj.getTheWinner(child);// �������ӵ�Ӯ��
            if (bin[winner] < objectSize[i]) // ���ӵ�Ӯ���ڴ治�������Һ���
                child++;
            child *= 2;   // �ҵ���ǰ���ӵ����ӣ�������������·����Ҷ�ӽڵ���
        }

        int binToUse;          // ����ΪҪʹ�õ�����
        child /= 2;            // �������������ӵ��ƶ����ҵ��丸��
        if (child < n)
        {
            binToUse = loserTreeObj.getTheWinner(child);
            // ��֤binToUse������ߵ�����
            if (binToUse > 1 && bin[binToUse - 1] >= objectSize[i])
                binToUse--;
        }
        else // ��n������ʱ��ǰ���whileѭ�����ܶ�λ�� �ڲ��ڵ����ⲿ�ڵ�������ⲿ�ڵ㣬����child�Ϳ��ܻ�>=n�������Ļ�����Ҫ��λ�����ⲿ�ڵ�ĸ���
            binToUse = loserTreeObj.getTheWinner(child / 2); // ��Ȼǰ���whileѭ����λ���˸ñ���(�ڲ��ڵ����ⲿ�ڵ����)���Һ��ӣ�˵�����Ӳ�����Ҫ��һ�����Һ�����Ӯ��

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
    int n, binCapacity; // ��������������ӵ�����
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
