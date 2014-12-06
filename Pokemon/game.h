#include <stdio.h>
#include "battle.h"
#include "pokemon.h"
#include "moves.h"
#include "rentals.h"


// globals
player_s *player1;
player_s *player2;

player_s *curr_player;
player_s *othr_player;

pokemon_s *curr_pokemon;
pokemon_s *othr_pokemon;

int last_dmg = 0;
move_s *last_move;


// typedefs and defines
typedef int bool;
#define true 1
#define false 0



// input phase func

// battle phase func

// end phase func

// win phase func
bool can_fight(player_s *player); // rtns tru if player has pkmn left

// phases
int input_phase();
int battle_phase();
int end_phase();
int win_phase();

// main game func
int game();