/*
Project name :			_30winnerTree
Last modified Date:		2023��12��19��16��48��
Last Version:			V1.0
Descriptions:			��С���������������
*/

#ifndef _31LOSERTREE_LOSERTREE_H
#define _31LOSERTREE_LOSERTREE_H

template<class T>
class loserTree {
public:
    virtual ~loserTree() {}
    virtual void initialize(T *thePlayer, int number) = 0;
    virtual int getTheWinner() const = 0;
    virtual void rePlay(int thePLayer) = 0;
};

#endif //_31LOSERTREE_LOSERTREE_H
