/*
Project name :			_33Search_tree
Last modified Date:		2023��12��21��11��13��
Last Version:			V1.0
Descriptions:			�������������������
*/

#ifndef _33SEARCH_TREE_INDEXEDBSTREE_H
#define _33SEARCH_TREE_INDEXEDBSTREE_H
#include "bsTree.h"

template<class K, class E>
class indexedBSTree : public bsTree<K,E>
{
public:
    virtual pair<K, E>* get(int index) const = 0;
    // ���ص�index������
};
#endif //_33SEARCH_TREE_INDEXEDBSTREE_H
