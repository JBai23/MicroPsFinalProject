
#include "battle-p.h"
#include "global.h"

void set_curr(trainer_s *trainer) {
	CURR_PLAYER = trainer;
	OTHR_PLAYER = (trainer == PLAYER1 ? PLAYER2 : PLAYER1);
}

void swap_curr() {
	set_curr(OTHR_PLAYER);
}



bool check_priority() { // true if battle, false if surrender
	if (PLAYER1_ACTION == SURRENDER_A || PLAYER2_ACTION == SURRENDER_A) {
		return false;
	}

	int player1_priority;
	int player2_priority;
	//if ()

	return true;
}

int get_priority(trainer_s *trainer) {
	action_t action = trainer->action;
	switch (action) {
		case MOVE1_A:
		case MOVE2_A:
		case MOVE3_A:
		case MOVE4_A:
			return get_move(trainer, action)->priority;

		case PKMN1_A:
		case PKMN2_A:
		case PKMN3_A:
		case PKMN4_A:
		case PKMN5_A:
		case PKMN6_A:
			return 6;

		default:
			return 0; // this shouldn't happen, should always check for surrender before calling this function
	}
}

void battle_phase() {
	if (check_priority()) {

	}
}