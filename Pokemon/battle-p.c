
#include "battle-p.h"
#include "global.h"
#include "math.h"

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

	int player1_priority = get_priority(PLAYER1);
	int player2_priority = get_priority(PLAYER2);

	if (player1_priority == player2_priority) {
		//check speed
	}

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

int calc_hpmax(pokemon_s *pokemon) {
	int ev = pokemon->pstats.hp_ev;
	int iv = pokemon->pstats.hp_iv;
	int level = pokemon->pstats.level;
	int base = pokemon->species->bstats.hp_base;
	return (iv + (2 * base) + ev / 4 + 100) * level / 100 + 10;
}

int calc_attack(pokemon_s *pokemon) {
	int ev = pokemon->pstats.attack_ev;
	int iv = pokemon->pstats.attack_iv;
	int level = pokemon->pstats.level;
	int base = pokemon->species->bstats.attack_base;
	int nature;
	switch (pokemon->pstats.nature) {
		case LONELY_N:
		case ADAMANT_N:
		case NAUGHTY_N:
		case BRAVE_N:
			nature = 11;
			break;
		case BOLD_N:
		case MODEST_N:
		case CALM_N:
		case TIMID_N:
			nature = 9;
			break;
		default:
			nature = 10;
			break;
	}
	int stage = pokemon->v.attack_stage;
	int stage_n = (stage > 0 ? 2 + stage : 2);
	int stage_d = (stage < 0 ? 2 - stage : 2);
	return ((iv + (2 * base) + ev / 4) * level / 100 + 5) * nature / 10 * stage_n / stage_d;
}

int calc_defense(pokemon_s *pokemon) {
	int ev = pokemon->pstats.defense_ev;
	int iv = pokemon->pstats.defense_iv;
	int level = pokemon->pstats.level;
	int base = pokemon->species->bstats.defense_base;
	int nature;
	switch (pokemon->pstats.nature) {
		case BOLD_N:
		case IMPISH_N:
		case LAX_N:
		case RELAXED_N:
			nature = 11;
			break;
		case LONELY_N:
		case MILD_N:
		case GENTLE_N:
		case HASTY_N:
			nature = 9;
			break;
		default:
			nature = 10;
			break;
	}
	int stage = pokemon->v.defense_stage;
	int stage_n = (stage > 0 ? 2 + stage : 2);
	int stage_d = (stage < 0 ? 2 - stage : 2);
	return ((iv + (2 * base) + ev / 4) * level / 100 + 5) * nature / 10 * stage_n / stage_d;
}

int calc_sattack(pokemon_s *pokemon) {
	int ev = pokemon->pstats.sattack_ev;
	int iv = pokemon->pstats.sattack_iv;
	int level = pokemon->pstats.level;
	int base = pokemon->species->bstats.sattack_base;
	int nature;
	switch (pokemon->pstats.nature) {
		case MODEST_N:
		case MILD_N:
		case RASH_N:
		case QUIET_N:
			nature = 11;
			break;
		case ADAMANT_N:
		case IMPISH_N:
		case CAREFUL_N:
		case JOLLY_N:
			nature = 9;
			break;
		default:
			nature = 10;
			break;
	}
	int stage = pokemon->v.sattack_stage;
	int stage_n = (stage > 0 ? 2 + stage : 2);
	int stage_d = (stage < 0 ? 2 - stage : 2);
	return ((iv + (2 * base) + ev / 4) * level / 100 + 5) * nature / 10 * stage_n / stage_d;
}

int calc_sdefense(pokemon_s *pokemon) {
	int ev = pokemon->pstats.sdefense_ev;
	int iv = pokemon->pstats.sdefense_iv;
	int level = pokemon->pstats.level;
	int base = pokemon->species->bstats.sdefense_base;
	int nature;
	switch (pokemon->pstats.nature) {
		case CALM_N:
		case GENTLE_N:
		case CAREFUL_N:
		case SASSY_N:
			nature = 11;
			break;
		case NAUGHTY_N:
		case LAX_N:
		case RASH_N:
		case NAIVE_N:
			nature = 9;
			break;
		default:
			nature = 10;
			break;
	}
	int stage = pokemon->v.sdefense_stage;
	int stage_n = (stage > 0 ? 2 + stage : 2);
	int stage_d = (stage < 0 ? 2 - stage : 2);
	return ((iv + (2 * base) + ev / 4) * level / 100 + 5) * nature / 10 * stage_n / stage_d;
}

int calc_speed(pokemon_s *pokemon) {
	int ev = pokemon->pstats.speed_ev;
	int iv = pokemon->pstats.speed_iv;
	int level = pokemon->pstats.level;
	int base = pokemon->species->bstats.speed_base;
	int nature;
	switch (pokemon->pstats.nature) {
		case TIMID_N:
		case HASTY_N:
		case JOLLY_N:
		case NAIVE_N:
			nature = 11;
			break;
		case BRAVE_N:
		case RELAXED_N:
		case QUIET_N:
		case SASSY_N:
			nature = 9;
			break;
		default:
			nature = 10;
			break;
	}
	int stage = pokemon->v.speed_stage;
	int stage_n = (stage > 0 ? 2 + stage : 2);
	int stage_d = (stage < 0 ? 2 - stage : 2);
	return ((iv + (2 * base) + ev / 4) * level / 100 + 5) * nature / 10 * stage_n / stage_d;
}





void battle_phase() {
	if (check_priority()) {

	}
}