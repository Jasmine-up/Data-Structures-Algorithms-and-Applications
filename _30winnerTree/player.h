/*
Project name :			_30winnerTree
Last modified Date:		2023��12��19��11��18��
Last Version:			V1.0
Descriptions:		    id&��ֵ
*/

#ifndef _30WINNERTREE_PLAYER_H
#define _30WINNERTREE_PLAYER_H
struct player
{
    int id, key;

    operator int () const {return key;}
};
#endif //_30WINNERTREE_PLAYER_H
