/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��24��11��16��
Last Version:			V1.0
Descriptions:			��ϣ��---��ʽɢ��(����洢)---ͷ�ļ�---�������
// hash table using sorted chains and division
// implements all dictionary methods
*/
#pragma once
#ifndef _HASHCHAINDS_H_
#define _HASHCHAINDS_H_
#include <iostream>
#include "_23dictionary.h"
#include "_23dictionaryChain.h"
#include "_25hash.h"
using namespace std;
/*���Ժ���*/
void hashChainsTest();

template<class K, class E>
class hashChains : public dictionary<K, E>
{
public:
    hashChains(int theDivisor = 11)
    {
        divisor = theDivisor;
        dSize = 0;

        // allocate and initialize hash table array
        table = new dictionaryChain<K, E>[divisor];
    }

    ~hashChains() { delete[] table; }

    bool empty() const { return dSize == 0; }
    int size() const { return dSize; }

    pair<const K, E>* find(const K& theKey) const
    {
        return table[hashNode(theKey) % divisor].find(theKey);
    }

    void insert(const pair<const K, E>& thePair)
    {
        int homeBucket = (int)hashNode(thePair.first) % divisor;
        int homeSize = table[homeBucket].size();
        table[homeBucket].insert(thePair);
        if (table[homeBucket].size() > homeSize)
            dSize++;
    }
    void erase(const K& theKey)
    {
        table[hashNode(theKey) % divisor].erase(theKey);
    }
    /*��Ԫ����*/
    /*�����ֵ�*/
    istream& input(istream& in);
//    friend istream& operator>> <K, E>(istream& in, hashChains<K, E>& m);
    /*����ֵ�*/
    ostream& output(ostream& out) const;
//    friend ostream& operator<< <K, E>(ostream& out, const hashChains<K, E>& m);
protected:
    dictionaryChain<K, E>* table;  // hash table
    hashNode<K> hashNode;              // maps type K to nonnegative integer
    int dSize;                 // number of elements in list
    int divisor;               // hash function divisor
};

/*�����ֵ�*/
template<class K, class E>
istream& hashChains<K, E>::input(istream& in)
{
    int numberOfElement = 0;
    cout << "Please enter the number of element:";
    while (!(in >> numberOfElement))
    {
        in.clear();//��ձ�־λ
        while (in.get() != '\n')//ɾ����Ч������
            continue;
        cout << "Please enter the number of element:";
    }
    K first;
    E second;
    for (int i = 0; i < numberOfElement; i++)
    {
        cout << "Please enter the element " << i + 1 << ":";
        while (!(in >> first >> second))
        {
            in.clear();//��ձ�־λ
            while (in.get() != '\n')//ɾ����Ч������
                continue;
            cout << "Please enter the element " << i + 1 << ":";
        }
        const pair<const K, E> element(first, second);
        cout << element.first << endl;
        cout << element.second << endl;
        insert(element);
    }
    return in;
}
template<class K, class E>
istream& operator>>(istream& in, hashChains<K, E>& m){
    m.input(in);
    return in;
}
/*����ֵ�*/
template<class K, class E>
ostream& hashChains<K, E>::output(ostream& out) const
{
    for (int i = 0; i < divisor; i++)
    {
        if (table[i].size() == 0)
            cout << "nullptr" << endl;
        else
            cout << table[i] << " ";
    }
    return out;
}
template<class K, class E>
ostream& operator<<(ostream& out, const hashChains<K, E>& m){
    m.output(out);
    return out;
}

#endif
