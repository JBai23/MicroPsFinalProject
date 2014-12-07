
#ifndef INP_H
#define INP_H 1

#include "types.h"




// input phase func
action_t get_action(menu_s *menu);
input_t get_input();

// set menus
//void set_menus(player_t player);

// phase
void input_phase();

#endif