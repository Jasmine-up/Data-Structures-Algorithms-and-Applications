/*
Project name :			allAlgorithmsTest
Last modified Date:		2022��8��22��09��17��
Last Version:			V1.0
Descriptions:			�ֵ�ĳ�����
*/
/*
pair:
	���ܣ��ǽ�2��������ϳ�һ������,��һ���ṹ�壬��Ҫ��������Ա����first��second���ֱ�洢��������.
	ʹ�ã�ʹ��std�����ռ��������std::pair
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
    /*����Ϊtrue�����ҽ����ֵ�Ϊ��*/
    virtual bool empty() const = 0;
    /*�����ֵ������Ե���Ŀ*/
    virtual int size() const = 0;
    /*����ƥ�����Ե�ָ��*/
    virtual pair<const K, E>* find(const K&) const = 0;
    /*ɾ��ƥ�������*/
    virtual void erase(const K&) = 0;
    /*���ֵ��в���һ������*/
    virtual void insert(const pair<const K, E>&) = 0;
};
#endif