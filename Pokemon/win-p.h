
#ifndef WINP_H
#define WINP_H 1

#include "types.h"

// win phase func
bool can_fight(player_s *player); // rtns tru if player has pkmn left
void player1_win();
void player2_win();
void draw_win();

bool win_phase();

#endif