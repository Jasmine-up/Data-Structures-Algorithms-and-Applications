/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��23��10��18��
Last Version:			V1.0
Descriptions:			��ϣ---ɢ�к���(��type Kת��Ϊ�Ǹ�����)
// functions to convert from type K to nonnegative integer
// derived from similar classes in SGI STL
*/
#pragma once
#ifndef _HASH_H_
#define _HASH_H_
#include <iostream>
#include <string>
using namespace std;
/*֮ǰ����ʱhash��ʵ����hashһֱ����Ȼ���Ҿ͸�����ԭ��*/
/*��������ԭ������� C++STLԴ�ļ�������hash�࣬�����Һ��涨���ģ��Ͳ�����������һֱ����*/
/*��˽���������ǣ���������hash��ΪhashNode*/
template <class K>
class hashNode
{
public:
    size_t operator()(const int theKey) const
    {
        return size_t(theKey);
    }
};

/*����һ��ʵ����*/
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
/*����һ��ʵ����*/
template<>
class hashNode<int>
{
public:
    size_t operator()(const int theKey) const
    {
        return size_t(theKey);
    }
};
/*����һ��ʵ����*/
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
