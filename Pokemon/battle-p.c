
#include "battle-p.h"
#include "global.h"
#include "math.h"
#include <stdio.h>

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
		int player1_speed = calc_speed(PLAYER1_POKEMON);
		int player2_speed = calc_speed(PLAYER2_POKEMON);

		if (player1_speed == player2_speed) {
			set_curr((roll(.5) ? PLAYER1 : PLAYER2));
			return true;
		} else {
			set_curr((player1_speed > player2_speed ? PLAYER1 : PLAYER2));
			return true;
		}
	} else {
		set_curr((player1_priority > player2_priority ? PLAYER1 : PLAYER2));
		return true;
	}

	return true;
}

int get_priority(trainer_s *trainer) {
	action_t action = trainer->action;
	return (is_move(action) ? get_move(trainer, action)->priority : 6); // if isn't move it is switch
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
	int status = (pokemon->nv.nvstatus == PAR_S ? 3 : 4);
	return ((iv + (2 * base) + ev / 4) * level / 100 + 5) * nature / 10 * stage_n / stage_d * status / 4;
}

double calc_accuracy(pokemon_s *attacker, pokemon_s *defender) {
	return (double) calc_accuracy_n(attacker, defender) / (double) calc_accuracy_d(attacker, defender);
}

int calc_accuracy_n(pokemon_s *attacker, pokemon_s *defender) {
	int acc = attacker->v.accuracy_stage;
	int eva = defender->v.evasion_stage;

	int sum = acc + eva;
	if (sum > 6) {
		sum = 6;
	} else if (sum < -6) {
		sum = -6;
	}

	return (sum > 0 ? 3 + sum : 3);
}

int calc_accuracy_d(pokemon_s *attacker, pokemon_s *defender) {
	int acc = attacker->v.accuracy_stage;
	int eva = defender->v.evasion_stage;

	int sum = acc + eva;
	if (sum > 6) {
		sum = 6;
	} else if (sum < -6) {
		sum = -6;
	}

	return (sum < 0 ? 3 + sum : 3);
}

void curr_exe() {
	if (CURR_POKEMON->nv.nvstatus != FNT_S) {
		if (is_move(CURR_ACTION)) {
			curr_attack();
		} else {
			curr_switchto();
		}
	}
}

move_s* curr_move() {
	return get_move(CURR_PLAYER, CURR_ACTION);
}

void curr_switchto() {
	switchto(CURR_PLAYER, get_switchindex(CURR_ACTION));
}

void curr_attack() {
	switch (CURR_POKEMON->nv.nvstatus) {
		case NON_S:
		case BRN_S:
		case PSN_S:
		case TXC_S:
			break;
		
		case FRZ_S:
			if (roll(.2)) {
				printf("%s thawed out!", CURR_PNAME);
				CURR_POKEMON->nv.nvstatus = NON_S;
				break;
			} else {
				printf("%s is frozen solid!", CURR_PNAME);
				return;
			}
		case PAR_S:
			if (roll(.25)) {
				printf("%s is fully paralyzed!", CURR_PNAME);
				return;
			} else {
				break;
			}
		case SLP_S:
			if (CURR_POKEMON->nv.nv_arg > 0) {
				printf("%s is fast asleep!", CURR_PNAME);
				CURR_POKEMON->nv.nv_arg--;
			} else {
				printf("%s woke up!", CURR_PNAME);
				CURR_POKEMON->nv.nvstatus = NON_S;
			}
		case FNT_S: // should never happen
			return;
	}

	move_s *move = curr_move();
	printf("%s used %s!", CURR_PNAME, move->name);

	if (move->unique) {
		switch (move->unique) {
			default: // no unique moves at the moment
				return;
		}
	}

	if (is_aggressive(move)) {

	}
}

void battle_phase() {
	if (check_priority()) {
		curr_exe();
		swap_curr();
		curr_exe();
	}
}