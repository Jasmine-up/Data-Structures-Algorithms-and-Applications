/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年8月23日10点18分
Last Version:			V1.0
Descriptions:			哈希---散列函数(将type K转换为非负整数)
// functions to convert from type K to nonnegative integer
// derived from similar classes in SGI STL
*/
#pragma once
#ifndef _HASH_H_
#define _HASH_H_
#include <iostream>
#include <string>
using namespace std;
/*之前名称时hash，实例化hash一直报错，然后我就各种找原因*/
/*后来发现原因可能是 C++STL源文件定义了hash类，所以我后面定义的模板就不作数，所以一直报错*/
/*因此解决方案就是：将类名称hash改为hashNode*/
template <class K>
class hashNode
{
public:
    size_t operator()(const int theKey) const
    {
        return size_t(theKey);
    }
};

/*这是一个实例化*/
template<>
class hashNode<string>
{
public:
    size_t operator()(const string theKey) const
    {// Convert theKey to a nonnegative integer.
        unsigned long hashNodeValue = 0;
        int length = (int)theKey.length();
        for (int i = 0; i < length; i++)
            hashNodeValue = 5 * hashNodeValue + theKey.at(i);

        return size_t(hashNodeValue);
    }
};
/*这是一个实例化*/
template<>
class hashNode<int>
{
public:
    size_t operator()(const int theKey) const
    {
        return size_t(theKey);
    }
};
/*这是一个实例化*/
template<>
class hashNode<long>
{
public:
    size_t operator()(const long theKey) const
    {
        return size_t(theKey);
    }
};

#endif
