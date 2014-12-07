
#ifndef BTLP_H
#define BTLP_H 1

#include "types.h"


player_t get_rplayer(relid_t rid); // rtns 1 if curr is player1, 2 if player2

void set_curr(trainer_s *trainer);
void swap_curr();

bool check_priority();
int get_priority(trainer_s *trainer);

int get_switchindex();

int calc_hpmax(pokemon_s *pokemon);
int calc_attack(pokemon_s *pokemon);
int calc_defense(pokemon_s *pokemon);
int calc_sattack(pokemon_s *pokemon);
int calc_sdefense(pokemon_s *pokemon);
int calc_speed(pokemon_s *pokemon);

double calc_accuracy(pokemon_s *attacker, pokemon_s *defender);
int calc_accuracy_n(pokemon_s *attacker, pokemon_s *defender);
int calc_accuracy_d(pokemon_s *attacker, pokemon_s *defender);

void curr_exe();
move_s* curr_move();
void curr_switchto();
void curr_attack();

void battle_phase();

#endif