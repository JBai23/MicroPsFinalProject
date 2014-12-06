
#include "battle.h"
#include "battlestate.h"

#ifndef GLB_H
#define GLB_H 1

// input phase globals
menu_s turn_menu;
menu_s fight_menu;
menu_s pkmn_menu; // switch
menu_s run_menu;
menu_s fpkmn_menu; // forced switch

effective_t echart[18][18];

battlestate_s curr;

// inits
void init_menus();
void init_echart();
void init_battlestate();

#endif