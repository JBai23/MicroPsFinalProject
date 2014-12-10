
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

typedef struct menu_s {
	struct menu_s *back;

	int option_count;
	
	char option_names[6][STRSIZE];
	action_t action[6];
	struct menu_s *submenu[6];
} menu_s;


// battle-p typedefs
typedef enum {
	CURR_R = 0, OTHR_R = 1
} relid_t; // relative identification

typedef enum {
	P1_P = 0, P2_P = 1
} player_t;

typedef struct {
	trainer_s *players[2];
	
	trainer_s *rplayer[2]; // relative player

	int last_dmg;
	//move_s *last_move;  // reset at beginning of battle phase? use for mirror move/counter

	int round_num;
} battle_s;

// eor-p typedefs

// win-p typedefs
typedef enum {
	NON_W, P1WIN_W, P2WIN_W, DRAW_W
} win_t;

#endif