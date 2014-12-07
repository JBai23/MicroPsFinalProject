
#ifndef GLB_H
#define GLB_H 1

#include "types.h"

#define PLAYER1 battle.players[P1_P]
#define PLAYER2 battle.players[P2_P]

// input phase globals
menu_s turn_menu;
menu_s fight_menu;
menu_s pkmn_menu; // switch
menu_s run_menu;
menu_s fpkmn_menu; // forced switch

effective_t echart[18][18];

//
trainer_s RED;
trainer_s BLUE;
// trainer_s RED = {"Red", {RED_PIKACHU, RED_LAPRAS, RED_SNORLAX, RED_VENUSAUR, RED_CHARIZARD, RED_BLASTOISE}, 6};
// trainer_s BLUE = {"Blue", {BLUE_PIDGEOT, BLUE_ALAKAZAM, BLUE_RHYDON, BLUE_ARCANINE, BLUE_EXEGGUTOR, BLUE_BLASTOISE}, 6};
battle_s battle;

// inits
void init_menus();
void init_echart();
void init_pokemonspec();
void init_moves();
void init_trainers();
void init_battle();

#endif