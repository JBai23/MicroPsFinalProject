
//#include "pokemon-def.h"
//#include "moves-def.h"
#include "types.h"
#include <string.h>
#include "global.h"
//#include "dataload.h"
#include <stdlib.h>
#include <stdio.h>
//#include "rentals-def.h"

pokemon_s* get_activepokemon(trainer_s *trainer) {
	return trainer->pokemon[trainer->pokemon_active];
}

bool has_type(pokemon_s *pokemon, type_t type) {
	return (pokemon->species->type1 == type || pokemon->species->type2 == type);
}

bool has_pp(pokemon_s *pokemon) {
	bool has = false;
	int i;
	for (i = 0; i < 4; ++i) {
		if (pokemon->pp[i] > 0) {
			has = true;
			break;
		}
	}
	return has;
}

move_s* get_move(trainer_s *trainer, action_t action) {
	switch (action) {
		case MOVE1_A:
			return get_activepokemon(trainer)->moves[0];
		case MOVE2_A:
			return get_activepokemon(trainer)->moves[1];
		case MOVE3_A:
			return get_activepokemon(trainer)->moves[2];
		case MOVE4_A:
			return get_activepokemon(trainer)->moves[3];
		default:
			return NULL;
	}
}

bool is_move(action_t action) {
	switch (action) {
		case MOVE1_A:
		case MOVE2_A:
		case MOVE3_A:
		case MOVE4_A:
			return true;

		case PKMN1_A:
		case PKMN2_A:
		case PKMN3_A:
		case PKMN4_A:
		case PKMN5_A:
		case PKMN6_A:
			return false;

		case SURRENDER_A:
		case NON_A:
			return false;

		default: // should never happen
			return false;
	}
}

bool valid_action(trainer_s *trainer) {
	action_t action = trainer->action;
	pokemon_s *pokemon;
	int index = get_index(action);
	// printf("ACTION: %i\n", action);

	switch(action) {
		case MOVE1_A:
		case MOVE2_A:
		case MOVE3_A:
		case MOVE4_A:
			pokemon = get_activepokemon(trainer);
			if (has_pp(pokemon)) {
				if (pokemon->pp[index] <= 0) {
					printf("%s has no PP left for that move!\n", pokemon->species->name);
					return false;
				}
				return true;
			} else {
				return true;
			}
		case PKMN1_A:
		case PKMN2_A:
		case PKMN3_A:
		case PKMN4_A:
		case PKMN5_A:
		case PKMN6_A:
			pokemon = trainer->pokemon[index];
			if (!is_alive(pokemon)) {
				printf("%s has no will to fight!\n", pokemon->species->name);
				return false;
			}
			if (trainer->pokemon_active == index) {
				printf("%s is already out!\n", pokemon->species->name);
				return false;
			}
			return true;
		case SURRENDER_A:
			return true;
		case NON_A: // this shouldn't happen
		default:
			return false;
	}
}

char* get_statusname(nvstatus_t status) {
	switch(status) {
		case NON_S:
			return "   ";
		case FNT_S:
			return "FNT";
		case BRN_S:
			return "BRN";
		case FRZ_S:
			return "FRZ";
		case PAR_S:
			return "PAR";
		case PSN_S:
			return "PSN";
		case TXC_S:
			return "TXC";
		case SLP_S:
			return "SLP";
		default: // shouldn't happen
			return "   ";
	}
}

	

bool is_aggressive(move_s *move) {
	switch (move->movetype) {
		case PHYSICAL_MT:
			return true;
		case SPECIAL_MT:
			return true;
		case STATUS_MT:
			switch (move->effect) {
				case NON_E2:
				case APPLY_BRN_E2:
				case APPLY_FRZ_E2:
				case APPLY_PAR_E2:
				case APPLY_PSN_E2:
				case APPLY_TXC_E2:
				case APPLY_SLP_E2:
				case APPLY_FLINCH_E2:
				case APPLY_CONFUSE_E2:
				case HIGH_CRIT_E2:
				case SELF_KILL_E2:
				case OTHR_ATTACK_E2:
				case OTHR_DEFENSE_E2:
				case OTHR_SATTACK_E2:
				case OTHR_SDEFENSE_E2:
				case OTHR_SPEED_E2:
				case OTHR_ACCURACY_E2:
				case OTHR_EVASION_E2:
				case RECOIL_E2:
				case RECHARGE_E2:
					return true;

				case SELF_ATTACK_E2:
				case SELF_DEFENSE_E2:
				case SELF_SATTACK_E2:
				case SELF_SDEFENSE_E2:
				case SELF_SPEED_E2:
				case SELF_ACCURACY_E2:
				case SELF_EVASION_E2:
				case SELF_ATTACK_SATTACK_E2:
				case HAZE_E2:
					return false;
			}
	}
}

int get_index(action_t action) {
	switch (action) {
		case MOVE1_A:
			return 0;
		case MOVE2_A:
			return 1;
		case MOVE3_A:
			return 2;
		case MOVE4_A:
			return 3;

		case PKMN1_A:
			return 0;
		case PKMN2_A:
			return 1;
		case PKMN3_A:
			return 2;
		case PKMN4_A:
			return 3;
		case PKMN5_A:
			return 4;
		case PKMN6_A:
			return 5;

		default:
			return 0; // this shouldn't happen; maybe if called in valid_action
	}
}

void reset_v(pokemon_s *pokemon) {
	pokemon->v.attack_stage = 0;
	pokemon->v.defense_stage = 0;
	pokemon->v.sattack_stage = 0;
	pokemon->v.sdefense_stage = 0;
	pokemon->v.speed_stage = 0;

	pokemon->v.accuracy_stage = 0;
	pokemon->v.evasion_stage = 0;

	pokemon->v.is_flinch = false;
	pokemon->v.is_confuse = false;
	pokemon->v.is_recharge = false;
}

void switchto(trainer_s *trainer, int index) {
	reset_v(get_activepokemon(trainer));
	trainer->pokemon_active = index;
	reset_v(get_activepokemon(trainer));
}

bool roll(double chance) {
	return rng() <= chance;
}

double rng() {
	return (double)(rand() % 100 + 1) / 100.0;
}

#include "global-init.h"