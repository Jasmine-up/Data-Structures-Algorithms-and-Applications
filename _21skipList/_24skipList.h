/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��23��10��18��
Last Version:			V1.0
Descriptions:			������---��������Ǽ����������ʱ���Ǽ��������ھ��Ǽ���---ͷ�ļ�
                        ����ʱ���Խ�ʡʱ��
*/
#pragma once
#ifndef _SKIPLIST_H_
#define _SKIPLIST_H_
#include <iostream>
#include <cmath>
#include <sstream>
#include <string>
#include <cstdlib>
#include "_1myExceptions.h"
#include "_23dictionary.h"
#include "_24skipNode.h"
using namespace std;
/*���Ժ���*/
void skipListTest();

template<class K, class E>
class skipList : public dictionary<K, E>
{
public:
    skipList(K largeKey, int maxPairs = 10000, float prob = 0.5);
    ~skipList();

    bool empty() const { return dSize == 0; }
    int size() const { return dSize; }
    pair<const K, E>* find(const K&) const;
    void erase(const K&);
    void insert(const pair<const K, E>&);
    void deleteFront();
    void deleteBack();
    /*��Ԫ����*/
    /*�����ֵ�*/
    istream& input(istream& in);
//    friend istream& operator>> <K, E>(istream& in, skipList<K, E>& m);
    /*����ֵ�*/
    ostream& output(ostream& out) const;
//    friend ostream& operator<< <K, E>(ostream& out, const skipList<K, E>& m);

protected:
    float cutOff;          // used to decide level number--����ȷ������
    int level() const;     // generate a random level number
    int levels;            // max current nonempty chain
    int dSize;             // number of pairs in dictionary
    int maxLevel;          // max permissible chain level
    K tailKey;             // a large key
    skipNode<K, E>* search(const K&) const;
    // search saving last nodes seen
    skipNode<K, E>* headerNode;  // header node pointer
    skipNode<K, E>* tailNode;    // tail node pointer
    skipNode<K, E>** last;       // last[i] = last node seen on level i
};

/*�����ֵ�*/
template<class K, class E>
istream& skipList<K, E>::input(istream& in)
//istream& operator>>(istream& in, skipList<K, E>& m)
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
        insert(element);
    }
    return in;
}
template<class K, class E>
istream& operator>>(istream& in, skipList<K, E>& m){
    m.input(in);
    return in;
}
/*����ֵ�*/
template<class K, class E>
ostream& skipList<K, E>::output(ostream& out) const
//ostream& operator<<(ostream& out, const skipList<K, E>& m)
{
    skipNode<K, E>* currentNode = headerNode->next[0];
    while (currentNode != tailNode)
    {
        out << *currentNode;
        currentNode = currentNode->next[0];
    }
    cout << endl;
    return out;
}
template<class K, class E>
ostream& operator<<(ostream& out, const skipList<K, E>& m){
    m.output(out);
    return out;
}
/*���캯��*/
template<class K, class E>
skipList<K, E>::skipList(K largeKey, int maxPairs, float prob)
{
    /*RAND_MAX����һ���궨��,���ǲ�������������ֵ����stdlibͷ�ļ���*/
    /*probһ����0.5*/
    cutOff = prob * RAND_MAX;
    /*ceil()������ʾ����ȡ����logf()������ʾȡ������maxPairs��ʾ���Ը����������*/
    maxLevel = (int)ceil(logf((float)maxPairs) / logf(1 / prob)) - 1;//�����������
    levels = 0;  //��ʼ�ǿղ���Ϊ0
    dSize = 0;//��ʼ�����СΪ0
    tailKey = largeKey;//��ʾ����ֵ

    // create header & tail nodes and last array
    pair<K, E> tailPair;
    tailPair.first = tailKey;
    headerNode = new skipNode<K, E>(tailPair, maxLevel + 1);//����ͷ�ڵ�
    tailNode = new skipNode<K, E>(tailPair, 0);//����β�ڵ�
    last = new skipNode<K, E> *[maxLevel + 1];//last[i]��ʾi��������

    // ��ʼ״̬�����е�i�������ͷ�ڵ�ָ��β�ڵ�
    for (int i = 0; i <= maxLevel; i++)
        headerNode->next[i] = tailNode;
}
/*ɾ�����н��� ָ������last*/
template<class K, class E>
skipList<K, E>::~skipList()
{// Delete all nodes and array last.
    skipNode<K, E>* nextNode;

    /*һ��������ִ��һ�Σ���Ϊ��ͷ�ڵ㡣*/
    while (headerNode != tailNode)
    {
        nextNode = headerNode->next[0];
        delete headerNode;
        headerNode = nextNode;
    }
    delete tailNode;
    delete[] last;
}
/*����ƥ������Ե�ָ�룻���û��ƥ������ԣ��򷵻�nullptr*/
template<class K, class E>
pair<const K, E>* skipList<K, E>::find(const K& theKey) const
{
    if (theKey >= tailKey)
        return nullptr;  // no matching pair possible

    // position beforeNode just before possible node with theKey
    skipNode<K, E>* beforeNode = headerNode;
    for (int i = levels; i >= 0; i--)          // go down levels
        // follow level i pointers
        while (beforeNode->next[i]->element.first < theKey)
            beforeNode = beforeNode->next[i];

    // check if next node has theKey
    if (beforeNode->next[0]->element.first == theKey)
        return &beforeNode->next[0]->element;

    return nullptr;  // no matching pair
}

template<class K, class E>
int skipList<K, E>::level() const
{// Return a random level number <= maxLevel.
    int lev = 0;
    while (rand() <= cutOff)
        lev++;
    return (lev <= maxLevel) ? lev : maxLevel;
}
/*�����ؼ���theKey����ÿһ��������Ҫ�鿴�����һ�����洢������last��*/
/*���ذ����ؼ���theKey�Ľ��*/
/*λ��beforeNode�ǹؼ���ΪtheKey�Ľ��֮ǰ���ұߵ�λ��*/
template<class K, class E>
skipNode<K, E>* skipList<K, E>::search(const K& theKey) const
{
    skipNode<K, E>* beforeNode = headerNode;
    for (int i = levels; i >= 0; i--)
    {
        while (beforeNode->next[i]->element.first < theKey)
            beforeNode = beforeNode->next[i];
        last[i] = beforeNode;  //theKey�ؼ���֮ǰ�Ľ��
    }
    return beforeNode->next[0];//����ֵ��0���� ���п�����theKeyΪ�ؼ��ֵĽ�㣬�������keyֵ����Ľ��
}

/*�������в���Ԫ��thePair����������в�������thePair�Ĺؼ�����ͬ��Ԫ������룬������¸ùؼ�����Ӧ��ֵ*/
template<class K, class E>
void skipList<K, E>::insert(const pair<const K, E>& thePair)
{
    /*keyֵ�������keyֵʱ*/
    if (thePair.first >= tailKey) // key too large
    {
        ostringstream s("");
        s << "Key = " << thePair.first << " Must be < " << tailKey;
        throw illegalParameterValue(s.str());
    }

    /*thePair��keyֵ�Ѿ�����ʱ�����¸�key��Ӧ��ֵ*/
    skipNode<K, E>* theNode = search(thePair.first);
    if (theNode->element.first == thePair.first)
    {
        theNode->element.second = thePair.second;
        return;
    }

    /*�������ڸ�keyֵʱ�������ȼ�i*/
    int theLevel = level(); //��������½ڵ�ĵȼ�
    /*����ȼ����ڷǿյȼ��ĸ�����������*/
    if (theLevel > levels)
    {
        theLevel = ++levels;
        last[theLevel] = headerNode;
    }

    /*���½ڵ�洢��theNode֮��*/
    skipNode<K, E>* newNode = new skipNode<K, E>(thePair, theLevel + 1);
    for (int i = 0; i <= theLevel; i++)
    {// insert into level i chain
        newNode->next[i] = last[i]->next[i];
        last[i]->next[i] = newNode;
    }

    dSize++;
    return;
}

template<class K, class E>
void skipList<K, E>::erase(const K& theKey)
{// Delete the pair, if any, whose key equals theKey.
    if (theKey >= tailKey) // too large
        return;

    // see if matching pair present
    skipNode<K, E>* theNode = search(theKey);
    if (theNode->element.first != theKey) // not present
        return;

    // delete node from skip list
    for (int i = 0; i <= levels && last[i]->next[i] == theNode; i++)
        last[i]->next[i] = theNode->next[i];

    // update levels
    while (levels > 0 && headerNode->next[levels] == tailNode)
        levels--;

    delete theNode;
    dSize--;
}
/*��ϰ9��ɾ���ؼ�����С�Ľ��*/
template<class K, class E>
void skipList<K, E>::deleteFront()
{
    if (dSize == 0)
        return;
    /*�ҵ��ؼ�����С�Ľ��*/
    skipNode<K, E>* frontNode = headerNode->next[0];
    /*ɾ���������� �ý��*/
    for(int i = 0;i <= levels && headerNode->next[i] == frontNode;i++)
        headerNode->next[i] = frontNode->next[i];
    /*����levels*/
    while (levels > 0 && headerNode->next[levels] == tailNode)
        levels--;
    delete frontNode;
    dSize--;
}
/*��ϰ9��ɾ���ؼ������Ľ��*/
template<class K, class E>
void skipList<K, E>::deleteBack()
{
    /*�ҵ��ؼ������Ľ��*/
    skipNode<K, E>* deleteBack = headerNode;
    for (int i = levels; i >= 0; i--)
    {
        while (deleteBack->next[i]->element.first < tailKey)
            deleteBack = deleteBack->next[i];
    }
    /*�ҵ��������� deleteBack ֮ǰ��Ԫ�ص�ַ*/
    search(deleteBack->element.first);
    /*ɾ���������� �ý��*/
    for (int i = 0; i <= levels && last[i]->next[i] == deleteBack; i++)
        last[i]->next[i] = deleteBack->next[i];
    /*����levels*/
    while (levels > 0 && headerNode->next[levels] == tailNode)
        levels--;
    delete deleteBack;
    dSize--;
}
#endif