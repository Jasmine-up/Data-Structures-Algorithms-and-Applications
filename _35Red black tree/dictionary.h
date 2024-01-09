/*
Project name :			_35Red_black_tree
Last modified Date:		2024��1��5��21��00��
Last Version:			V1.0
Descriptions:			�ֵ������
*/

#ifndef _33SEARCH_TREE_DICTIONARY_H
#define _33SEARCH_TREE_DICTIONARY_H
#include <iostream>
#include <utility>

using namespace std;

template<class K, class E>
class dictionary
{
public:
    virtual ~dictionary() = default;
    [[nodiscard]] virtual bool empty() const = 0;
    // ����ֵ�Ϊ���򷵻�true����֮����false
    [[nodiscard]] virtual int size() const = 0;
    // �����ֵ����ж��ٸ�pair
    virtual pair<K, E>* find(K) const = 0;
    // ���ݼ�ֵ����pair��ָ��
    virtual void erase(K) = 0;
    // ���ݼ�ֵ�Ƴ�pairԪ��
    virtual void insert(pair<K, E>&) = 0;
    // ����һ��(key, value)pair���ֵ���
};
#endif //_33SEARCH_TREE_DICTIONARY_H
