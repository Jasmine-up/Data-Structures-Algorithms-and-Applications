/*
Project name :			_30winnerTree
Last modified Date:		2023年12月18日16点28分
Last Version:			V1.0
Descriptions:			赢者树的抽象类
*/

#ifndef _30WINNERTREE_WINNERTREE_H
#define _30WINNERTREE_WINNERTREE_H
using namespace std;

template<class T>
class winnerTree
{
public:
    virtual ~winnerTree() {}
    virtual void initialize(T *thePlayer, int theNumberOfPlayers) = 0;
    // 使用thePlayer[1:numberOfPlayers]创建赢者树
    virtual int winner() const = 0;
    // 返回赢者树的index
    virtual void rePlay(int thePLayer) = 0;
    // 改变选手thePLayer的值之后重新组织比赛
};
#endif //_30WINNERTREE_WINNERTREE_H
