
#ifndef GLB_H
#define GLB_H 1

#include "types.h"

#define PLAYER1 battle.players[P1_P]
#define PLAYER2 battle.players[P2_P]

#define PLAYER1_NAME PLAYER1->name
#define PLAYER2_NAME PLAYER2->name

#define PLAYER1_ACTION PLAYER1->action
#define PLAYER2_ACTION PLAYER2->action

#define PLAYER1_POKEMON PLAYER1->pokemon[PLAYER1->pokemon_active]
#define PLAYER2_POKEMON PLAYER2->pokemon[PLAYER2->pokemon_active]

#define PLAYER1_PNAME PLAYER1_POKEMON->species->name
#define PLAYER2_PNAME PLAYER2_POKEMON->species->name

#define CURR_PLAYER battle.rplayer[CURR_R]
#define OTHR_PLAYER battle.rplayer[OTHR_R]

#define CURR_NAME CURR_PLAYER->name
#define OTHR_NAME OTHR_PLAYER->name

#define CURR_ACTION CURR_PLAYER->action
#define OTHR_ACTION OTHR_PLAYER->action

#define CURR_POKEMON CURR_PLAYER->pokemon[CURR_PLAYER->pokemon_active]
#define OTHR_POKEMON OTHR_PLAYER->pokemon[OTHR_PLAYER->pokemon_active]

#define CURR_PNAME CURR_POKEMON->species->name
#define OTHR_PNAME OTHR_POKEMON->species->name

// input phase globals
menu_s turn_menu;
menu_s fight_menu;
menu_s pkmn_menu; // switch
menu_s run_menu;
menu_s fpkmn_menu; // forced switch

effective_t echart[18][18];

pokemonspec_s specs_all[151];
move_s moves_all[111];
pokemon_s rentals_all[12];

trainer_s RED;
trainer_s BLUE;

battle_s battle;

pokemon_s* get_activepokemon(trainer_s *trainer);
bool has_type(pokemon_s *pokemon, type_t type);
bool has_pp(pokemon_s *pokemon);
move_s* get_move(trainer_s *trainer, action_t action);
bool valid_action(trainer_s *trainer);
bool is_move(action_t action);
bool is_aggressive(move_s *move);
int get_index(action_t action);

void switchto(trainer_s *trainer, int index);
void reset_v(pokemon_s *pokemon);
char* get_statusname(nvstatus_t status);

bool roll(double chance);
double rng();

// inits
void init_rng();
void init_menus();
void init_echart();
void init_pokemonspec();
void init_moves();
// void init_rentals();
void init_trainers();
void init_battle();

void loadTrainer(trainer_s *trainer, char *file);

#endif