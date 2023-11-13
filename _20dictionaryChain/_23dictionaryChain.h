/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月22日09点17分
Last Version:			V1.0
Descriptions:			使用链表实现的字典的头文件---是有序的
*/
#pragma once
#ifndef _DICTIONARY_CHAIN_H_
#define _DICTIONARY_CHAIN_H_
#include <iostream>
#include "_23pairNode.h"
#include "_23dictionary.h"
using namespace std;
/*测试函数*/
void dictionaryChainTest();

template<class K, class E>
class dictionaryChain : public dictionary<K, E>
{
public:
    /*成员函数*/
    /*构造函数和析构函数*/
    dictionaryChain() { firstNode = nullptr; dSize = 0; }
    ~dictionaryChain();
    /*其他成员函数*/
    bool empty() const { return dSize == 0; }
    int size() const { return dSize; }
    pair<const K, E>* find(const K&) const;
    void erase(const K&);
    void insert(const pair<const K, E>&);

    /*友元函数*/
    /*输入字典*/
    istream& input(istream& in);
//    friend istream& operator>> <K,E>(istream& in, dictionaryChain<K,E>& m);
    /*输出字典*/
    ostream& output(ostream& out) const;
//    friend ostream& operator<< <K,E>(ostream& out, const dictionaryChain<K,E>& m);
protected:
    pairNode<K, E>* firstNode;  // pointer to first node in chain
    int dSize;                 // number of elements in dictionary
};

/*输入字典*/
template<class K, class E>
istream& dictionaryChain<K, E>::input(istream& in)
//istream& operator>>(istream& in, dictionaryChain<K,E>& m)
{
    int numberOfElement = 0;
    cout << "Please enter the number of element:";
    while (!(in >> numberOfElement))
    {
        in.clear();//清空标志位
        while (in.get() != '\n')//删除无效的输入
            continue;
        cout << "Please enter the number of element:";
    }
    pair<K, E> element;
    for (int i = 0; i < numberOfElement; i++)
    {
        cout << "Please enter the element " << i + 1 << ":";
        while (!(in >> element.first >> element.second))
        {
            in.clear();//清空标志位
            while (in.get() != '\n')//删除无效的输入
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
/*输出字典*/
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
/*析构函数*/
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
/*寻找关键字为key的数对并返回*/
template<class K, class E>
pair<const K, E>* dictionaryChain<K, E>::find(const K& key) const
{
    //返回匹配的数对的指针
    //如果不存在匹配的数对，则返回nullptr
    pairNode<K, E>* currentNode = firstNode;
    while (currentNode != nullptr && currentNode->element.first != key)
        currentNode = currentNode->next;
    if (currentNode != nullptr && currentNode->element.first == key)
        return &currentNode->element;
    return nullptr;//如果没找到就返回nullptr
}
/*删除关键字为key的数对*/
template<class K, class E>
void dictionaryChain<K, E>::erase(const K& key)
{
    //删除关键字为key的数对
    pairNode<K, E>* p = firstNode;//存储的是插入元素之后的位置
    pairNode<K, E>* tp = nullptr;//存储的是插入元素之前的位置
    //搜索关键字为key的数对
    while (p != nullptr && p->element.first < key)
    {
        tp = p;
        p = p->next;
    }
    //确定是否匹配
    if (p != nullptr && p->element.first == key)
        if (tp == nullptr) firstNode = p->next;//p是第一个节点
        else tp->next = p->next;
    delete p;
    dSize--;
}
/*往字典中插入data,覆盖已经存在的匹配的数对*/
template<class K,class E>
void dictionaryChain<K, E>::insert(const pair<const K, E>& data)
{
    pairNode<K, E>* p = firstNode;//存储的是插入元素之后的位置
    pairNode<K, E>* tp = nullptr;//存储的是插入元素之前的位置
    while (p != nullptr && p->element.first < data.first)
    {
        tp = p;
        p = p->next;
    }
    //检查是否有匹配的数对
    if (p != nullptr && p->element.first == data.first)
    {
        p->element.second = data.second;
        return;
    }
    //无匹配的数对，为thePair建立新节点
    pairNode<K, E>* newNode = new pairNode<K, E>(data, p);
    //在tp之后插入新节点
    if (tp == nullptr) firstNode = newNode;
    else tp->next = newNode;
    dSize++;
    return;
}

#endif
