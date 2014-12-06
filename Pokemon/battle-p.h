
#include "pkmn-tdef.h"
#include "input-p.h"

#ifndef BTLP_H
#define BTLP_H 1

// battlestate typedefs
typedef enum {
	curr_r = 0, othr_r = 1
} relid_t; // relative identification

typedef enum {
	p1_p = 0, p2_p = 1
} player_t;

typedef struct {
	player_s *player1;
	player_s *player2;

	player_s *players[2];
	pokemon_s *apkmn[2];

	int last_dmg;
	move_s *last_move;

	int round_num;
	action_t player1_action;
	action_t player2_action;
} battle_s;

int get_player(relid_t rid); // rtns 1 if curr is player1, 2 if player2

#endif