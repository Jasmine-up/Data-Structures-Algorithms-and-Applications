/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��22��09��17��
Last Version:			V1.0
Descriptions:			ʹ������ʵ�ֵ��ֵ��ͷ�ļ�---�������
*/
#pragma once
#ifndef _DICTIONARY_CHAIN_H_
#define _DICTIONARY_CHAIN_H_
#include <iostream>
#include "_23pairNode.h"
#include "_23dictionary.h"
using namespace std;
/*���Ժ���*/
void dictionaryChainTest();

template<class K, class E>
class dictionaryChain : public dictionary<K, E>
{
public:
    /*��Ա����*/
    /*���캯������������*/
    dictionaryChain() { firstNode = nullptr; dSize = 0; }
    ~dictionaryChain();
    /*������Ա����*/
    bool empty() const { return dSize == 0; }
    int size() const { return dSize; }
    pair<const K, E>* find(const K&) const;
    void erase(const K&);
    void insert(const pair<const K, E>&);

    /*��Ԫ����*/
    /*�����ֵ�*/
    istream& input(istream& in);
//    friend istream& operator>> <K,E>(istream& in, dictionaryChain<K,E>& m);
    /*����ֵ�*/
    ostream& output(ostream& out) const;
//    friend ostream& operator<< <K,E>(ostream& out, const dictionaryChain<K,E>& m);
protected:
    pairNode<K, E>* firstNode;  // pointer to first node in chain
    int dSize;                 // number of elements in dictionary
};

/*�����ֵ�*/
template<class K, class E>
istream& dictionaryChain<K, E>::input(istream& in)
//istream& operator>>(istream& in, dictionaryChain<K,E>& m)
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
    pair<K, E> element;
    for (int i = 0; i < numberOfElement; i++)
    {
        cout << "Please enter the element " << i + 1 << ":";
        while (!(in >> element.first >> element.second))
        {
            in.clear();//��ձ�־λ
            while (in.get() != '\n')//ɾ����Ч������
                continue;
            cout << "Please enter the element " << i + 1 << ":";
        }
        insert(element);
    }
    return in;
}
template<class K, class E>
istream& operator>>(istream& in, dictionaryChain<K,E>& m){
    m.input(in);
    return in;
}
/*����ֵ�*/
template<class K, class E>
ostream& dictionaryChain<K, E>::output(ostream& out) const
//ostream& operator<<(ostream& out, const dictionaryChain<K,E>& m)
{
    pairNode<K, E>* currentNode = firstNode;
    while (currentNode != nullptr)
    {
        out << "(" << currentNode->element.first << " ," << currentNode->element.second << ")" << " ";
        currentNode = currentNode->next;
    }
    cout << endl;
    return out;
}
template<class K, class E>
ostream& operator<<(ostream& out, const dictionaryChain<K,E>& m){
    m.output(out);
    return out;
}
/*��������*/
template<class K,class E>
dictionaryChain<K,E>::~dictionaryChain()
{
    pairNode<K, E>* nextNode;
    while (firstNode != nullptr)
    {
        nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}
/*Ѱ�ҹؼ���Ϊkey�����Բ�����*/
template<class K, class E>
pair<const K, E>* dictionaryChain<K, E>::find(const K& key) const
{
    //����ƥ������Ե�ָ��
    //���������ƥ������ԣ��򷵻�nullptr
    pairNode<K, E>* currentNode = firstNode;
    while (currentNode != nullptr && currentNode->element.first != key)
        currentNode = currentNode->next;
    if (currentNode != nullptr && currentNode->element.first == key)
        return &currentNode->element;
    return nullptr;//���û�ҵ��ͷ���nullptr
}
/*ɾ���ؼ���Ϊkey������*/
template<class K, class E>
void dictionaryChain<K, E>::erase(const K& key)
{
    //ɾ���ؼ���Ϊkey������
    pairNode<K, E>* p = firstNode;//�洢���ǲ���Ԫ��֮���λ��
    pairNode<K, E>* tp = nullptr;//�洢���ǲ���Ԫ��֮ǰ��λ��
    //�����ؼ���Ϊkey������
    while (p != nullptr && p->element.first < key)
    {
        tp = p;
        p = p->next;
    }
    //ȷ���Ƿ�ƥ��
    if (p != nullptr && p->element.first == key)
        if (tp == nullptr) firstNode = p->next;//p�ǵ�һ���ڵ�
        else tp->next = p->next;
    delete p;
    dSize--;
}
/*���ֵ��в���data,�����Ѿ����ڵ�ƥ�������*/
template<class K,class E>
void dictionaryChain<K, E>::insert(const pair<const K, E>& data)
{
    pairNode<K, E>* p = firstNode;//�洢���ǲ���Ԫ��֮���λ��
    pairNode<K, E>* tp = nullptr;//�洢���ǲ���Ԫ��֮ǰ��λ��
    while (p != nullptr && p->element.first < data.first)
    {
        tp = p;
        p = p->next;
    }
    //����Ƿ���ƥ�������
    if (p != nullptr && p->element.first == data.first)
    {
        p->element.second = data.second;
        return;
    }
    //��ƥ������ԣ�ΪthePair�����½ڵ�
    pairNode<K, E>* newNode = new pairNode<K, E>(data, p);
    //��tp֮������½ڵ�
    if (tp == nullptr) firstNode = newNode;
    else tp->next = newNode;
    dSize++;
    return;
}

#endif
