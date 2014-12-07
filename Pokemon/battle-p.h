
#ifndef BTLP_H
#define BTLP_H 1

#include "types.h"



#define PLAYER1 battle.player[p1_p]
#define PLAYER2 battle.player[p2_p]

player_t get_rplayer(relid_t rid); // rtns 1 if curr is player1, 2 if player2

void set_active(player_t player);

#endif