/*
Project name :			allAlgorithmsTest
Last modified Date:		2022年9月17日10点47分
Last Version:			V1.0
Descriptions:			二叉树的应用 设置信号放大器 节点结构体
*/
#pragma once
#ifndef _BOOSTER_H_
#define _BOOSTER_H_
#include <iostream>
using namespace std;

struct booster
{
    int degradeToLeaf,           //到叶子结点的衰减
    degradeFromParent;       //父节点到该节点的衰减
    bool boosterHere;            //是否在此节点放置放大器
    /*重载<<操作符*/
    friend ostream& operator<<(ostream& out, booster& m)
    {
        out << m.boosterHere << ' ' << m.degradeToLeaf << ' ' << m.degradeFromParent << ' ';
        return out;
    }
    /*重载>>操作符*/
    friend istream& operator>>(istream& in, booster& m)
    {
        cout << "Please enter the degradeToLeaf:";
        while (!(in >> m.degradeToLeaf))
        {
            in.clear();//清空标志位
            while (in.get() != '\n')//删除无效的输入
                continue;
            cout << "Please enter the degradeToLeaf:";
        }
        cout << "Please enter the degradeFromParent:";
        while (!(in >> m.degradeFromParent))
        {
            in.clear();//清空标志位
            while (in.get() != '\n')//删除无效的输入
                continue;
            cout << "Please enter the degradeFromParent:";
        }
        m.boosterHere = 0;
        return in;
    }
};
#endif
