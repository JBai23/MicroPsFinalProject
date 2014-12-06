
#include "pkmn-tdef.h"
#include "input-p.h"

#ifndef BTLP_H
#define BTLP_H 1

#define PLAYER1 player[p1_p]
#define PLAYER2 player[p2_p]

// battlestate typedefs
typedef enum {
	curr_r = 0, othr_r = 1
} relid_t; // relative identification

typedef enum {
	p1_p = 0, p2_p = 1
} player_t;

typedef struct {
	player_s *players[2];
	
	player_s *rplayer[2]; // relative player
	pokemon_s *rapkmn[2]; // relative active pkmn

	int last_dmg;
	move_s *last_move;

	int round_num;
	action_t actions[2];
} battle_s;

player_t get_player(relid_t rid); // rtns 1 if curr is player1, 2 if player2

void set_active(player_t player);

#endif