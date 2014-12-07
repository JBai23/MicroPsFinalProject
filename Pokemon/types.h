
#ifndef TYPES_H
#define TYPES_H 1

#include "gdefines.h"
#include "pkmn-tdef.h"

// input-p typedef
typedef enum {
	BTN1_I = 0, BTN2_I = 1, BTN3_I = 2,
	BTN4_I = 3, BTN5_I = 4, BTN6_I = 5,
	BTNA_I, BTNB_I, NON_I
} input_t;

typedef enum {
	MOVE1_A, MOVE2_A, MOVE3_A, MOVE4_A,
	PKMN1_A, PKMN2_A, PKMN3_A, PKMN4_A, PKMN5_A, PKMN6_A,
	SURRENDER_A, NON_A
} action_t;

typedef struct menu_s {
	struct menu_s *back;

	int option_count;
	
	char option_names[6][STRSIZE];
	action_t action[6];
	struct menu_s *submenu[6];
} menu_s;


// battle-p typedefs
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

// eor-p typedefs

// win-p typedefs
typedef enum {
	NON_W, P1WIN_W, P2WIN_W, DRAW_W
} win_t;

#endif