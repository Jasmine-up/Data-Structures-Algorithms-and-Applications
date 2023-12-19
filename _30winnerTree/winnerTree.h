/*
Project name :			_30winnerTree
Last modified Date:		2023��12��18��16��28��
Last Version:			V1.0
Descriptions:			Ӯ�����ĳ�����
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
    // ʹ��thePlayer[1:numberOfPlayers]����Ӯ����
    virtual int winner() const = 0;
    // ����Ӯ������index
    virtual void rePlay(int thePLayer) = 0;
    // �ı�ѡ��thePLayer��ֵ֮��������֯����
};
#endif //_30WINNERTREE_WINNERTREE_H
