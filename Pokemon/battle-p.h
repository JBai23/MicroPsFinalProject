
#ifndef BTLP_H
#define BTLP_H 1

#include "types.h"


player_t get_rplayer(relid_t rid); // rtns 1 if curr is player1, 2 if player2

void set_curr(trainer_s *trainer);
void swap_curr();

bool check_priority();
int get_priority(trainer_s *trainer);

void battle_phase();

#endif