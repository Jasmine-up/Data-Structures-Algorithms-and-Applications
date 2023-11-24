/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月23日10点18分
Last Version:			V1.0
Descriptions:			哈希表(数组存储)---使用线性探查的头文件---是无序的
// hash table using linear open addressing and division
// implements dictionary methods other than erase
*/
#pragma once
#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_
#include <iostream>
#include "_1myExceptions.h"
#include "_25hash.h"  // mapping functions from K to nonnegative integer
using namespace std;
/*测试函数*/
void hashTableTest();

template<class K, class E>
class hashTable
{
public:
    hashTable(int theDivisor = 11);
    ~hashTable() { delete[] table; }

    bool empty() const { return dSize == 0; }
    int size() const { return dSize; }
    pair<const K, E>* find(const K&) const;
    void insert(const pair<const K, E>&);
    void erase(const K theKey);

    /*友元函数*/
    /*输入字典*/
    istream& input(istream& in);
//    friend istream& operator>> <K, E>(istream& in, hashTable<K, E>& m);
    /*输出字典*/
    ostream& output(ostream& out) const;
//    friend ostream& operator<< <K, E>(ostream& out, const hashTable<K, E>& m);

protected:
    int search(const K&) const;
    pair<const K, E>** table;  // hash table
    hashNode<K> hashNode;              // maps type K to nonnegative integer
    int dSize;                 // number of pairs in dictionary
    int divisor;               // hash function divisor
};

/*输入字典*/
template<class K, class E>
istream& hashTable<K, E>::input(istream& in)
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
    K first;
    E second;
    for (int i = 0; i < numberOfElement; i++)
    {
        cout << "Please enter the element " << i + 1 << ":";
        while (!(in >> first >> second))
        {
            in.clear();//清空标志位
            while (in.get() != '\n')//删除无效的输入
                continue;
            cout << "Please enter the element " << i + 1 << ":";
        }
        const pair<const K, E> element(first, second);
        insert(element);
    }
    return in;
}
template<class K, class E>
istream& operator>>(istream& in, hashTable<K, E>& m){
    m.input(in);
    return in;
}
/*输出字典*/
template<class K, class E>
ostream& hashTable<K, E>::output(ostream& out) const
{
    for (int i = 0; i < divisor; i++)
        if (table[i] == nullptr)
            cout << "nullptr" << " ";
        else
            cout << "(" << table[i]->first << "," << table[i]->second << ")" << " ";
    cout << endl;
    return out;
}

template<class K, class E>
ostream& operator<<(ostream& out, const hashTable<K, E>& m){
    m.output(out);
    return out;
}

template<class K, class E>
hashTable<K, E>::hashTable(int theDivisor)
{
    divisor = theDivisor;
    dSize = 0;

    // allocate and initialize hash table array
    table = new pair<const K, E>*[divisor];
    for (int i = 0; i < divisor; i++)
        table[i] = nullptr;
}

template<class K, class E>
int hashTable<K, E>::search(const K& theKey) const
{// Search an open addressed hash table for a pair with key theKey.
    // Return location of matching pair if found, otherwise return
    // location where a pair with key theKey may be inserted
    // provided the hash table is not full.

    int i = (int)hashNode(theKey) % divisor;  // home bucket
    int j = i;    // start at home bucket
    do
    {
        if (table[j] == nullptr || table[j]->first == theKey)
            return j;
        j = (j + 1) % divisor;  // next bucket
    } while (j != i);          // returned to home bucket?

    return j;  // table full
}

template<class K, class E>
pair<const K, E>* hashTable<K, E>::find(const K& theKey) const
{// Return pointer to matching pair.
    // Return nullptr if no matching pair.
    // search the table
    int b = search(theKey);

    // see if a match was found at table[b]
    if (table[b] == nullptr || table[b]->first != theKey)
        return nullptr;           // no match

    return table[b];  // matching pair
}

template<class K, class E>
void hashTable<K, E>::insert(const pair<const K, E>& thePair)
{// Insert thePair into the dictionary. Overwrite existing
    // pair, if any, with same key.
    // Throw hashTableFull exception in case table is full.
    // search the table for a matching pair
    int b = search(thePair.first);

    // check if matching pair found
    if (table[b] == nullptr)
    {
        // no matching pair and table not full
        table[b] = new pair<const K, E>(thePair);
        dSize++;
    }
    else
    {// check if duplicate or table full
        if (table[b]->first == thePair.first)
        {// duplicate, change table[b]->second
            table[b]->second = thePair.second;
        }
        else // table is full
            throw hashTableFull();
    }
}

/*删除关键字为theKey的元素*/
template<class K, class E>
void hashTable<K, E>::erase(const K theKey)
{
    int i = (int)hashNode(theKey) % divisor;
    int j = i;
    /*从起始桶开始寻找关键字为theKey的元素*/
    while (table[j] != nullptr && table[j]->first != theKey)
    {
        j = (++j) % divisor;
        /*如果找完了所有桶都没找到以theKey为关键字的数对，说明该数对不存在，抛出异常*/
        if (j == i)
            throw illegalParameterValue("The key is not exist");
    }
    if(table[j] == nullptr)
        throw illegalParameterValue("The key is not exist");

    /*能到这里说明已经找到以theKey为关键字的数对了*/
    i = j;//使用i记录该数对的位置
    delete table[i];//将该数对删除
    table[i] = nullptr;
    j++;//找到下一个数对

    /*将后面的数对前移*/
    /*不是空桶不是起始桶不是原始桶*/
    while (table[j] != nullptr && (int)hashNode(table[j]->first) % divisor != j && j != i)
    {
        table[j - 1] = table[j];//移动后面的元素
        j = (++j) % divisor;
    }
}
#endif
