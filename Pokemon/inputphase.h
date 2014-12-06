
#include "global.h"

#ifndef INP_H
#define INP_H 1

// input phase typedef
typedef enum {
	BTN1_I, BTN2_I, BTN3_I, BTN4_I, BTN5_I, BTN6_I, BTNA_I, BTNB_I, NON_I
} input_t;

typedef struct {
	struct menu_s *back;

	int option_count;
	
	char option_names[6][STRSIZE];
	input_t input[6];
	struct menu_s *submenu[6];
} menu_s;

typedef struct {
	int temp;
} command_s;


// input phase declares

menu_s fight_menu = {
.option_count = 4,
.input = {BTN1_I, BTN2_I, BTN3_I, BTN4_I, NON_I, NON_I}
};


// input phase func
command_s get_command(menu_s *menu);

input_t get_input();

// phase
int input_phase();

#endif