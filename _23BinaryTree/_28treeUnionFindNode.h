#pragma once
#ifndef _TREEUNIONFINDNODE_H_
#define _TREEUNIONFINDNODE_H_
/*
注意事项：
1.当且仅当一个节点是当前根节点时，他的root域为true;
2.每个根节点的parent域用来记录该树的节点总数

规则
1.重量规则
    若根为i的树的节点数少于根为j的树的节点数，则将j作为i的父节点；否则，将i作为j的父节点。
2.高度规则
    若根为i的树的高度小于根为j的树的高度，则将j作为i的父节点；否则，将i作为j的父节点。
*/
struct treeUnionFindNode
{
    int parent;  // if true then tree weight
    // otherwise pointer to parent in tree
    bool root;   // true iff root

    treeUnionFindNode()
    {
        parent = 1; root = true;
    }
};
#endif