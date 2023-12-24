/*
Project name :			_33Search_tree
Last modified Date:		2023年12月21日11点13分
Last Version:			V1.0
Descriptions:			二叉搜索树——虚基类
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
    // 按关键字升序输出
};
#endif //_33SEARCH_TREE_BSTREE_H
