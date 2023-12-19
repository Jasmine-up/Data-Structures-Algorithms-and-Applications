/*
Project name :			_30winnerTree
Last modified Date:		2023年12月19日11点18分
Last Version:			V1.0
Descriptions:		    id&键值
*/

#ifndef _30WINNERTREE_PLAYER_H
#define _30WINNERTREE_PLAYER_H
struct player
{
    int id, key;

    operator int () const {return key;}
};
#endif //_30WINNERTREE_PLAYER_H
