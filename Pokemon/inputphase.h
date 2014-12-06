
#include "global.h"
#include "battlestate.h"
#include <stdio.h>

#ifndef INP_H
#define INP_H 1

// input phase typedef
typedef enum {
	BTN1_I = 0, BTN2_I = 1, BTN3_I = 2, BTN4_I = 3, BTN5_I = 4, BTN6_I = 5, BTNA_I, BTNB_I, NON_I
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


// input phase declares
menu_s turn_menu;
menu_s fight_menu;
menu_s pkmn_menu; // switch
menu_s run_menu;

menu_s fpkmn_menu; // forced switch

void init_menus();


// input phase func
action_t get_action(menu_s *menu);

input_t get_input();

// phase
void input_phase();

#endif