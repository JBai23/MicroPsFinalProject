
#ifndef GLB_H
#define GLB_H 1

#include "types.h"

#define PLAYER1 battle.players[P1_P]
#define PLAYER2 battle.players[P2_P]

#define PLAYER1_ACTION PLAYER1->action
#define PLAYER2_ACTION PLAYER2->action

#define PLAYER1_POKEMON PLAYER1->pokemon[PLAYER1->pokemon_active]
#define PLAYER2_POKEMON PLAYER2->pokemon[PLAYER2->pokemon_active]

#define CURR_PLAYER battle.rplayer[CURR_R]
#define OTHR_PLAYER battle.rplayer[OTHR_R]

#define CURR_ACTION CURR_PLAYER->action
#define OTHR_ACTION OTHR_PLAYER->action

#define CURR_PKMN CURR_PLAYER->pokemon[CURR_PLAYER->pokemon_active]
#define OTHR_PKMN OTHR_PLAYER->pokemon[OTHR_PLAYER->pokemon_active]

// input phase globals
menu_s turn_menu;
menu_s fight_menu;
menu_s pkmn_menu; // switch
menu_s run_menu;
menu_s fpkmn_menu; // forced switch

effective_t echart[18][18];

trainer_s RED;
trainer_s BLUE;

battle_s battle;

pokemon_s* active_pokemon(trainer_s *trainer);
move_s* get_move(trainer_s *trainer, action_t action);

bool roll(double chance);
double rng();

// inits
void init_rng();
void init_menus();
void init_echart();
void init_pokemonspec();
void init_moves();
void init_trainers();
void init_battle();

#endif