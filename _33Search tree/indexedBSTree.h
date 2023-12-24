/*
Project name :			_33Search_tree
Last modified Date:		2023年12月21日11点13分
Last Version:			V1.0
Descriptions:			索引二叉搜索树虚基类
*/

#ifndef _33SEARCH_TREE_INDEXEDBSTREE_H
#define _33SEARCH_TREE_INDEXEDBSTREE_H
#include "bsTree.h"

template<class K, class E>
class indexedBSTree : public bsTree<K,E>
{
public:
    virtual pair<K, E>* get(int index) const = 0;
    // 返回第index个数对
};
#endif //_33SEARCH_TREE_INDEXEDBSTREE_H
