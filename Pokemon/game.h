#include <stdio.h>
#include "battle.h"
#include "pokemon.h"
#include "moves.h"
#include "rentals.h"

// include phases
#include "inputphase.h"


#ifndef GME_H
#define GME_H 1


// global battlestate typedefs
typedef struct {
	player_s *player1;
	player_s *player2;

	player_s *curr_player;
	player_s *othr_player;

	pokemon_s *curr_pokemon;
	pokemon_s *othr_pokemon;

	int last_dmg;
	move_s *last_move;

	int turn;
} battlestate_s;


// global battlestate
battlestate_s curr;

int get_currplayer(); // rtns 1 if curr is player1, 2 if player2


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