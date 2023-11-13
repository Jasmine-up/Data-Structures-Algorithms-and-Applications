/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月22日09点17分
Last Version:			V1.0
Descriptions:			字典的抽象类
*/
/*
pair:
	介绍：是将2个数据组合成一组数据,是一个结构体，主要的两个成员变量first和second，分别存储两个数据.
	使用：使用std命名空间引入对组std::pair
*/
#pragma once
#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_
using namespace std;
template<class K,class E>
class dictionary
{
public:
    virtual ~dictionary() {}
    /*返回为true，当且仅当字典为空*/
    virtual bool empty() const = 0;
    /*返回字典中数对的数目*/
    virtual int size() const = 0;
    /*返回匹配数对的指针*/
    virtual pair<const K, E>* find(const K&) const = 0;
    /*删除匹配的数对*/
    virtual void erase(const K&) = 0;
    /*往字典中插入一个数对*/
    virtual void insert(const pair<const K, E>&) = 0;
};
#endif