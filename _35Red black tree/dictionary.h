/*
Project name :			_35Red_black_tree
Last modified Date:		2024年1月5日21点00分
Last Version:			V1.0
Descriptions:			字典虚基类
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
    // 如果字典为空则返回true，反之返回false
    [[nodiscard]] virtual int size() const = 0;
    // 返回字典中有多少个pair
    virtual pair<K, E>* find(K) const = 0;
    // 根据键值返回pair的指针
    virtual void erase(K) = 0;
    // 根据键值移除pair元素
    virtual void insert(pair<K, E>&) = 0;
    // 插入一个(key, value)pair到字典中
};
#endif //_33SEARCH_TREE_DICTIONARY_H
