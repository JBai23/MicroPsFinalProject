
#include "battle.h"
#include "inputphase.h"
#include "battlestate.h"

typedef struct {
	player_s *player1;
	player_s *player2;

	player_s *curr_player;
	player_s *othr_player;

	pokemon_s *curr_pokemon;
	pokemon_s *othr_pokemon;

	int last_dmg;
	move_s *last_move;

	int turn;
	action_t player1_action;
	action_t player2_action;
} battlestate_s;