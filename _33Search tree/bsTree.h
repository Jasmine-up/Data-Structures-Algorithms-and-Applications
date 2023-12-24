/*
Project name :			_33Search_tree
Last modified Date:		2023��12��21��11��13��
Last Version:			V1.0
Descriptions:			�������������������
*/

#ifndef _33SEARCH_TREE_BSTREE_H
#define _33SEARCH_TREE_BSTREE_H
#include "dictionary.h"

using namespace std;

template<class K, class E>
class bsTree : public dictionary<K,E>
{
public:
    virtual void ascend() = 0;
    // ���ؼ����������
};
#endif //_33SEARCH_TREE_BSTREE_H
