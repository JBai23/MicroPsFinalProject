#include <stdio.h>
#include "battle.h"
#include "pokemon.h"
#include "moves.h"
#include "rentals.h"

#include "battlestate.h"

// include phases
#include "inputphase.h"


#ifndef GME_H
#define GME_H 1

// battle phase func

// end phase func
void apply_eoteffects();
void apply_toxic();
void apply_poison();
void apply_burn();

// win phase func
bool can_fight(player_s *player); // rtns tru if player has pkmn left
void player1_win();
void player2_win();
void draw_win();

// phases
int battle_phase();
int end_phase();
int win_phase();

// main game func
int game();

#endif