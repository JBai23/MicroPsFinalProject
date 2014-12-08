
#include "pokemon-def.h"
#include "moves-def.h"
#include "types.h"
#include <string.h>
#include "global.h"
#include <stdlib.h>
#include <stdio.h>
#include "rentals-def.h"

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

void init_rng() {
	srand(0); // need to change seed
}

void init_menus() {
	// turn menu
	turn_menu.back = NULL;
	turn_menu.option_count = 3;
	strcpy(turn_menu.option_names[0], "Fight");
	strcpy(turn_menu.option_names[1], "Pokemon");
	strcpy(turn_menu.option_names[2], "Run");
	strcpy(turn_menu.option_names[3], "");
	strcpy(turn_menu.option_names[4], "");
	strcpy(turn_menu.option_names[5], "");
	turn_menu.action[0] = NON_A;
	turn_menu.action[1] = NON_A;
	turn_menu.action[2] = NON_A;
	turn_menu.action[3] = NON_A;
	turn_menu.action[4] = NON_A;
	turn_menu.action[5] = NON_A;
	turn_menu.submenu[0] = &fight_menu;
	turn_menu.submenu[1] = &pkmn_menu;
	turn_menu.submenu[2] = &run_menu;
	turn_menu.submenu[3] = NULL;
	turn_menu.submenu[4] = NULL;
	turn_menu.submenu[5] = NULL;

	// fight menu
	fight_menu.back = &turn_menu;
	fight_menu.option_count = 4;
	strcpy(fight_menu.option_names[0], "MOVE1");
	strcpy(fight_menu.option_names[1], "MOVE2");
	strcpy(fight_menu.option_names[2], "MOVE3");
	strcpy(fight_menu.option_names[3], "MOVE4");
	strcpy(fight_menu.option_names[4], "");
	strcpy(fight_menu.option_names[5], "");
	fight_menu.action[0] = MOVE1_A;
	fight_menu.action[1] = MOVE2_A;
	fight_menu.action[2] = MOVE3_A;
	fight_menu.action[3] = MOVE4_A;
	fight_menu.action[4] = NON_A;
	fight_menu.action[5] = NON_A;
	fight_menu.submenu[0] = NULL;
	fight_menu.submenu[1] = NULL;
	fight_menu.submenu[2] = NULL;
	fight_menu.submenu[3] = NULL;
	fight_menu.submenu[4] = NULL;
	fight_menu.submenu[5] = NULL;

	// pkmn menu
	pkmn_menu.back = &turn_menu;
	pkmn_menu.option_count = 6;
	strcpy(pkmn_menu.option_names[0], "PKMN1");
	strcpy(pkmn_menu.option_names[1], "PKMN2");
	strcpy(pkmn_menu.option_names[2], "PKMN3");
	strcpy(pkmn_menu.option_names[3], "PKMN4");
	strcpy(pkmn_menu.option_names[4], "PKMN5");
	strcpy(pkmn_menu.option_names[5], "PKMN6");
	pkmn_menu.action[0] = PKMN1_A;
	pkmn_menu.action[1] = PKMN2_A;
	pkmn_menu.action[2] = PKMN3_A;
	pkmn_menu.action[3] = PKMN4_A;
	pkmn_menu.action[4] = PKMN5_A;
	pkmn_menu.action[5] = PKMN6_A;
	pkmn_menu.submenu[0] = NULL;
	pkmn_menu.submenu[1] = NULL;
	pkmn_menu.submenu[2] = NULL;
	pkmn_menu.submenu[3] = NULL;
	pkmn_menu.submenu[4] = NULL;
	pkmn_menu.submenu[5] = NULL;

	// run menu
	run_menu.back = &turn_menu;
	run_menu.option_count = 1;
	strcpy(run_menu.option_names[0], "Confirm");
	strcpy(run_menu.option_names[1], "");
	strcpy(run_menu.option_names[2], "");
	strcpy(run_menu.option_names[3], "");
	strcpy(run_menu.option_names[4], "");
	strcpy(run_menu.option_names[5], "");
	run_menu.action[0] = SURRENDER_A;
	run_menu.action[1] = NON_A;
	run_menu.action[2] = NON_A;
	run_menu.action[3] = NON_A;
	run_menu.action[4] = NON_A;
	run_menu.action[5] = NON_A;
	run_menu.submenu[0] = NULL;
	run_menu.submenu[1] = NULL;
	run_menu.submenu[2] = NULL;
	run_menu.submenu[3] = NULL;
	run_menu.submenu[4] = NULL;
	run_menu.submenu[5] = NULL;

	// fpkmn menu
	//fpkmn_menu = pkmn_menu;
	fpkmn_menu.back = NULL;
	fpkmn_menu.option_count = 6;
	strcpy(fpkmn_menu.option_names[0], "PKMN1");
	strcpy(fpkmn_menu.option_names[1], "PKMN2");
	strcpy(fpkmn_menu.option_names[2], "PKMN3");
	strcpy(fpkmn_menu.option_names[3], "PKMN4");
	strcpy(fpkmn_menu.option_names[4], "PKMN5");
	strcpy(fpkmn_menu.option_names[5], "PKMN6");
	fpkmn_menu.action[0] = PKMN1_A;
	fpkmn_menu.action[1] = PKMN2_A;
	fpkmn_menu.action[2] = PKMN3_A;
	fpkmn_menu.action[3] = PKMN4_A;
	fpkmn_menu.action[4] = PKMN5_A;
	fpkmn_menu.action[5] = PKMN6_A;
	fpkmn_menu.submenu[0] = NULL;
	fpkmn_menu.submenu[1] = NULL;
	fpkmn_menu.submenu[2] = NULL;
	fpkmn_menu.submenu[3] = NULL;
	fpkmn_menu.submenu[4] = NULL;
	fpkmn_menu.submenu[5] = NULL;
}

void init_echart() {
	// NORMAL
	echart[0][0] = NORMAL_TE;
	echart[0][1] = NORMAL_TE;
	echart[0][2] = NORMAL_TE;
	echart[0][3] = NORMAL_TE;
	echart[0][4] = NORMAL_TE;
	echart[0][5] = NOTVERY_TE;
	echart[0][6] = NORMAL_TE;
	echart[0][7] = NOEFFECT_TE;
	echart[0][8] = NOTVERY_TE;
	echart[0][9] = NORMAL_TE;
	echart[0][10] = NORMAL_TE;
	echart[0][11] = NORMAL_TE;
	echart[0][12] = NORMAL_TE;
	echart[0][13] = NORMAL_TE;
	echart[0][14] = NORMAL_TE;
	echart[0][15] = NORMAL_TE;
	echart[0][16] = NORMAL_TE;
	echart[0][17] = NORMAL_TE;

	// FIGHTING
	echart[1][0] = SUPER_TE;
	echart[1][1] = NORMAL_TE;
	echart[1][2] = NOTVERY_TE;
	echart[1][3] = NOTVERY_TE;
	echart[1][4] = NORMAL_TE;
	echart[1][5] = SUPER_TE;
	echart[1][6] = NOTVERY_TE;
	echart[1][7] = NOEFFECT_TE;
	echart[1][8] = SUPER_TE;
	echart[1][9] = NORMAL_TE;
	echart[1][10] = NORMAL_TE;
	echart[1][11] = NORMAL_TE;
	echart[1][12] = NORMAL_TE;
	echart[1][13] = NOTVERY_TE;
	echart[1][14] = SUPER_TE;
	echart[1][15] = NORMAL_TE;
	echart[1][16] = SUPER_TE;
	echart[1][17] = NOTVERY_TE;

	// FLYING
	echart[2][0] = NORMAL_TE;
	echart[2][1] = SUPER_TE;
	echart[2][2] = NORMAL_TE;
	echart[2][3] = NORMAL_TE;
	echart[2][4] = NORMAL_TE;
	echart[2][5] = NOTVERY_TE;
	echart[2][6] = SUPER_TE;
	echart[2][7] = NORMAL_TE;
	echart[2][8] = NOTVERY_TE;
	echart[2][9] = NORMAL_TE;
	echart[2][10] = NORMAL_TE;
	echart[2][11] = SUPER_TE;
	echart[2][12] = NOTVERY_TE;
	echart[2][13] = NORMAL_TE;
	echart[2][14] = NORMAL_TE;
	echart[2][15] = NORMAL_TE;
	echart[2][16] = NORMAL_TE;
	echart[2][17] = NORMAL_TE;

	// POISON
	echart[3][0] = NORMAL_TE;
	echart[3][1] = NORMAL_TE;
	echart[3][2] = NORMAL_TE;
	echart[3][3] = NOTVERY_TE;
	echart[3][4] = NOTVERY_TE;
	echart[3][5] = NOTVERY_TE;
	echart[3][6] = NORMAL_TE;
	echart[3][7] = NOTVERY_TE;
	echart[3][8] = NOEFFECT_TE;
	echart[3][9] = NORMAL_TE;
	echart[3][10] = NORMAL_TE;
	echart[3][11] = SUPER_TE;
	echart[3][12] = NORMAL_TE;
	echart[3][13] = NORMAL_TE;
	echart[3][14] = NORMAL_TE;
	echart[3][15] = NORMAL_TE;
	echart[3][16] = NORMAL_TE;
	echart[3][17] = SUPER_TE;

	// GROUND
	echart[4][0] = NORMAL_TE;
	echart[4][1] = NORMAL_TE;
	echart[4][2] = NOEFFECT_TE;
	echart[4][3] = SUPER_TE;
	echart[4][4] = NORMAL_TE;
	echart[4][5] = SUPER_TE;
	echart[4][6] = NOTVERY_TE;
	echart[4][7] = NORMAL_TE;
	echart[4][8] = SUPER_TE;
	echart[4][9] = SUPER_TE;
	echart[4][10] = NORMAL_TE;
	echart[4][11] = NOTVERY_TE;
	echart[4][12] = SUPER_TE;
	echart[4][13] = NORMAL_TE;
	echart[4][14] = NORMAL_TE;
	echart[4][15] = NORMAL_TE;
	echart[4][16] = NORMAL_TE;
	echart[4][17] = NORMAL_TE;

	// ROCK
	echart[5][0] = NORMAL_TE;
	echart[5][1] = NOTVERY_TE;
	echart[5][2] = SUPER_TE;
	echart[5][3] = NORMAL_TE;
	echart[5][4] = NOTVERY_TE;
	echart[5][5] = NORMAL_TE;
	echart[5][6] = SUPER_TE;
	echart[5][7] = NORMAL_TE;
	echart[5][8] = NOTVERY_TE;
	echart[5][9] = SUPER_TE;
	echart[5][10] = NORMAL_TE;
	echart[5][11] = NORMAL_TE;
	echart[5][12] = NORMAL_TE;
	echart[5][13] = NORMAL_TE;
	echart[5][14] = SUPER_TE;
	echart[5][15] = NORMAL_TE;
	echart[5][16] = NORMAL_TE;
	echart[5][17] = NORMAL_TE;

	// BUG
	echart[6][0] = NORMAL_TE;
	echart[6][1] = NOTVERY_TE;
	echart[6][2] = NOTVERY_TE;
	echart[6][3] = NOTVERY_TE;
	echart[6][4] = NORMAL_TE;
	echart[6][5] = NORMAL_TE;
	echart[6][6] = NORMAL_TE;
	echart[6][7] = NOTVERY_TE;
	echart[6][8] = NOTVERY_TE;
	echart[6][9] = NOTVERY_TE;
	echart[6][10] = NORMAL_TE;
	echart[6][11] = SUPER_TE;
	echart[6][12] = NORMAL_TE;
	echart[6][13] = SUPER_TE;
	echart[6][14] = NORMAL_TE;
	echart[6][15] = NORMAL_TE;
	echart[6][16] = SUPER_TE;
	echart[6][17] = NOTVERY_TE;

	// GHOST
	echart[7][0] = NOEFFECT_TE;
	echart[7][1] = NORMAL_TE;
	echart[7][2] = NORMAL_TE;
	echart[7][3] = NORMAL_TE;
	echart[7][4] = NORMAL_TE;
	echart[7][5] = NORMAL_TE;
	echart[7][6] = NORMAL_TE;
	echart[7][7] = SUPER_TE;
	echart[7][8] = NORMAL_TE;
	echart[7][9] = NORMAL_TE;
	echart[7][10] = NORMAL_TE;
	echart[7][11] = NORMAL_TE;
	echart[7][12] = NORMAL_TE;
	echart[7][13] = SUPER_TE;
	echart[7][14] = NORMAL_TE;
	echart[7][15] = NORMAL_TE;
	echart[7][16] = NOTVERY_TE;
	echart[7][17] = NORMAL_TE;

	// STEEL
	echart[8][0] = NORMAL_TE;
	echart[8][1] = NORMAL_TE;
	echart[8][2] = NORMAL_TE;
	echart[8][3] = NORMAL_TE;
	echart[8][4] = NORMAL_TE;
	echart[8][5] = SUPER_TE;
	echart[8][6] = NORMAL_TE;
	echart[8][7] = NORMAL_TE;
	echart[8][8] = NOTVERY_TE;
	echart[8][9] = NOTVERY_TE;
	echart[8][10] = NOTVERY_TE;
	echart[8][11] = NORMAL_TE;
	echart[8][12] = NOTVERY_TE;
	echart[8][13] = NORMAL_TE;
	echart[8][14] = SUPER_TE;
	echart[8][15] = NORMAL_TE;
	echart[8][16] = NORMAL_TE;
	echart[8][17] = SUPER_TE;

	// FIRE
	echart[9][0] = NORMAL_TE;
	echart[9][1] = NORMAL_TE;
	echart[9][2] = NORMAL_TE;
	echart[9][3] = NORMAL_TE;
	echart[9][4] = NORMAL_TE;
	echart[9][5] = NOTVERY_TE;
	echart[9][6] = SUPER_TE;
	echart[9][7] = NORMAL_TE;
	echart[9][8] = SUPER_TE;
	echart[9][9] = NOTVERY_TE;
	echart[9][10] = NOTVERY_TE;
	echart[9][11] = SUPER_TE;
	echart[9][12] = NORMAL_TE;
	echart[9][13] = NORMAL_TE;
	echart[9][14] = SUPER_TE;
	echart[9][15] = NOTVERY_TE;
	echart[9][16] = NORMAL_TE;
	echart[9][17] = NORMAL_TE;

	// WATER
	echart[10][0] = NORMAL_TE;
	echart[10][1] = NORMAL_TE;
	echart[10][2] = NORMAL_TE;
	echart[10][3] = NORMAL_TE;
	echart[10][4] = SUPER_TE;
	echart[10][5] = SUPER_TE;
	echart[10][6] = NORMAL_TE;
	echart[10][7] = NORMAL_TE;
	echart[10][8] = NORMAL_TE;
	echart[10][9] = SUPER_TE;
	echart[10][10] = NOTVERY_TE;
	echart[10][11] = NOTVERY_TE;
	echart[10][12] = NORMAL_TE;
	echart[10][13] = NORMAL_TE;
	echart[10][14] = NORMAL_TE;
	echart[10][15] = NOTVERY_TE;
	echart[10][16] = NORMAL_TE;
	echart[10][17] = NORMAL_TE;

	// GRASS
	echart[11][0] = NORMAL_TE;
	echart[11][1] = NORMAL_TE;
	echart[11][2] = NOTVERY_TE;
	echart[11][3] = NOTVERY_TE;
	echart[11][4] = SUPER_TE;
	echart[11][5] = SUPER_TE;
	echart[11][6] = NOTVERY_TE;
	echart[11][7] = NORMAL_TE;
	echart[11][8] = NOTVERY_TE;
	echart[11][9] = NOTVERY_TE;
	echart[11][10] = SUPER_TE;
	echart[11][11] = NOTVERY_TE;
	echart[11][12] = NORMAL_TE;
	echart[11][13] = NORMAL_TE;
	echart[11][14] = NORMAL_TE;
	echart[11][15] = NOTVERY_TE;
	echart[11][16] = NORMAL_TE;
	echart[11][17] = NORMAL_TE;

	// ELECTRIC
	echart[12][0] = NORMAL_TE;
	echart[12][1] = NORMAL_TE;
	echart[12][2] = SUPER_TE;
	echart[12][3] = NORMAL_TE;
	echart[12][4] = NOEFFECT_TE;
	echart[12][5] = NORMAL_TE;
	echart[12][6] = NORMAL_TE;
	echart[12][7] = NORMAL_TE;
	echart[12][8] = NORMAL_TE;
	echart[12][9] = NORMAL_TE;
	echart[12][10] = SUPER_TE;
	echart[12][11] = NOTVERY_TE;
	echart[12][12] = NOTVERY_TE;
	echart[12][13] = NORMAL_TE;
	echart[12][14] = NORMAL_TE;
	echart[12][15] = NOTVERY_TE;
	echart[12][16] = NORMAL_TE;
	echart[12][17] = NORMAL_TE;

	// PHYCHIC
	echart[13][0] = NORMAL_TE;
	echart[13][1] = SUPER_TE;
	echart[13][2] = NORMAL_TE;
	echart[13][3] = SUPER_TE;
	echart[13][4] = NORMAL_TE;
	echart[13][5] = NORMAL_TE;
	echart[13][6] = NORMAL_TE;
	echart[13][7] = NORMAL_TE;
	echart[13][8] = NOTVERY_TE;
	echart[13][9] = NORMAL_TE;
	echart[13][10] = NORMAL_TE;
	echart[13][11] = NORMAL_TE;
	echart[13][12] = NORMAL_TE;
	echart[13][13] = NOTVERY_TE;
	echart[13][14] = NORMAL_TE;
	echart[13][15] = NORMAL_TE;
	echart[13][16] = NOEFFECT_TE;
	echart[13][17] = NORMAL_TE;

	// ICE
	echart[14][0] = NORMAL_TE;
	echart[14][1] = NORMAL_TE;
	echart[14][2] = SUPER_TE;
	echart[14][3] = NORMAL_TE;
	echart[14][4] = SUPER_TE;
	echart[14][5] = NORMAL_TE;
	echart[14][6] = NORMAL_TE;
	echart[14][7] = NORMAL_TE;
	echart[14][8] = NOTVERY_TE;
	echart[14][9] = NOTVERY_TE;
	echart[14][10] = NOTVERY_TE;
	echart[14][11] = SUPER_TE;
	echart[14][12] = NORMAL_TE;
	echart[14][13] = NORMAL_TE;
	echart[14][14] = NOTVERY_TE;
	echart[14][15] = SUPER_TE;
	echart[14][16] = NORMAL_TE;
	echart[14][17] = NORMAL_TE;

	// DRAGON
	echart[15][0] = NORMAL_TE;
	echart[15][1] = NORMAL_TE;
	echart[15][2] = NORMAL_TE;
	echart[15][3] = NORMAL_TE;
	echart[15][4] = NORMAL_TE;
	echart[15][5] = NORMAL_TE;
	echart[15][6] = NORMAL_TE;
	echart[15][7] = NORMAL_TE;
	echart[15][8] = NOTVERY_TE;
	echart[15][9] = NORMAL_TE;
	echart[15][10] = NORMAL_TE;
	echart[15][11] = NORMAL_TE;
	echart[15][12] = NORMAL_TE;
	echart[15][13] = NORMAL_TE;
	echart[15][14] = NORMAL_TE;
	echart[15][15] = SUPER_TE;
	echart[15][16] = NORMAL_TE;
	echart[15][17] = NOEFFECT_TE;

	// DARK
	echart[16][0] = NORMAL_TE;
	echart[16][1] = NOTVERY_TE;
	echart[16][2] = NORMAL_TE;
	echart[16][3] = NORMAL_TE;
	echart[16][4] = NORMAL_TE;
	echart[16][5] = NORMAL_TE;
	echart[16][6] = NORMAL_TE;
	echart[16][7] = SUPER_TE;
	echart[16][8] = NORMAL_TE;
	echart[16][9] = NORMAL_TE;
	echart[16][10] = NORMAL_TE;
	echart[16][11] = NORMAL_TE;
	echart[16][12] = NORMAL_TE;
	echart[16][13] = SUPER_TE;
	echart[16][14] = NORMAL_TE;
	echart[16][15] = NORMAL_TE;
	echart[16][16] = NOTVERY_TE;
	echart[16][17] = NOTVERY_TE;

	// FARIY
	echart[17][0] = NORMAL_TE;
	echart[17][1] = SUPER_TE;
	echart[17][2] = NORMAL_TE;
	echart[17][3] = NOTVERY_TE;
	echart[17][4] = NORMAL_TE;
	echart[17][5] = NORMAL_TE;
	echart[17][6] = NORMAL_TE;
	echart[17][7] = NORMAL_TE;
	echart[17][8] = NOTVERY_TE;
	echart[17][9] = NOTVERY_TE;
	echart[17][10] = NORMAL_TE;
	echart[17][11] = NORMAL_TE;
	echart[17][12] = NORMAL_TE;
	echart[17][13] = NORMAL_TE;
	echart[17][14] = NORMAL_TE;
	echart[17][15] = SUPER_TE;
	echart[17][16] = SUPER_TE;
	echart[17][17] = NORMAL_TE;
}

void init_pokemonspec() {
	// bulbasaur
	strcpy(BULBASAUR.name, "Bulbasaur");
	BULBASAUR.id = 1;
	BULBASAUR.type1 = GRASS_T;
	BULBASAUR.type2 = POISON_T;
	BULBASAUR.bstats.hp_base = 45;
	BULBASAUR.bstats.attack_base = 49;
	BULBASAUR.bstats.defense_base = 49;
	BULBASAUR.bstats.sattack_base = 65;
	BULBASAUR.bstats.sdefense_base = 65;
	BULBASAUR.bstats.speed_base = 45;

	// ivysaur
	strcpy(IVYSAUR.name, "Ivysaur");
	IVYSAUR.id = 2;
	IVYSAUR.type1 = GRASS_T;
	IVYSAUR.type2 = POISON_T;
	IVYSAUR.bstats.hp_base = 60;
	IVYSAUR.bstats.attack_base = 62;
	IVYSAUR.bstats.defense_base = 63;
	IVYSAUR.bstats.sattack_base = 80;
	IVYSAUR.bstats.sdefense_base = 80;
	IVYSAUR.bstats.speed_base = 60;

	// venusaur
	strcpy(VENUSAUR.name, "Venusaur");
	VENUSAUR.id = 3;
	VENUSAUR.type1 = GRASS_T;
	VENUSAUR.type2 = POISON_T;
	VENUSAUR.bstats.hp_base = 80;
	VENUSAUR.bstats.attack_base = 82;
	VENUSAUR.bstats.defense_base = 83;
	VENUSAUR.bstats.sattack_base = 100;
	VENUSAUR.bstats.sdefense_base = 100;
	VENUSAUR.bstats.speed_base = 80;

	// charmander
	strcpy(CHARMANDER.name, "Charmander");
	CHARMANDER.id = 4;
	CHARMANDER.type1 = FIRE_T;
	CHARMANDER.type2 = NON_T;
	CHARMANDER.bstats.hp_base = 39;
	CHARMANDER.bstats.attack_base = 52;
	CHARMANDER.bstats.defense_base = 43;
	CHARMANDER.bstats.sattack_base = 60;
	CHARMANDER.bstats.sdefense_base = 50;
	CHARMANDER.bstats.speed_base = 65;

	// charmeleon
	strcpy(CHARMELEON.name, "Charmeleon");
	CHARMELEON.id = 5;
	CHARMELEON.type1 = FIRE_T;
	CHARMELEON.type2 = NON_T;
	CHARMELEON.bstats.hp_base = 58;
	CHARMELEON.bstats.attack_base = 64;
	CHARMELEON.bstats.defense_base = 58;
	CHARMELEON.bstats.sattack_base = 80;
	CHARMELEON.bstats.sdefense_base = 65;
	CHARMELEON.bstats.speed_base = 80;

	// charizard
	strcpy(CHARIZARD.name, "Charizard");
	CHARIZARD.id = 6;
	CHARIZARD.type1 = FIRE_T;
	CHARIZARD.type2 = FLYING_T;
	CHARIZARD.bstats.hp_base = 78;
	CHARIZARD.bstats.attack_base = 84;
	CHARIZARD.bstats.defense_base = 78;
	CHARIZARD.bstats.sattack_base = 109;
	CHARIZARD.bstats.sdefense_base = 85;
	CHARIZARD.bstats.speed_base = 100;

	// squirtle
	strcpy(SQUIRTLE.name, "Squirtle");
	SQUIRTLE.id = 7;
	SQUIRTLE.type1 = WATER_T;
	SQUIRTLE.type2 = NON_T;
	SQUIRTLE.bstats.hp_base = 44;
	SQUIRTLE.bstats.attack_base = 48;
	SQUIRTLE.bstats.defense_base = 65;
	SQUIRTLE.bstats.sattack_base = 50;
	SQUIRTLE.bstats.sdefense_base = 64;
	SQUIRTLE.bstats.speed_base = 43;

	// wartortle
	strcpy(WARTORTLE.name, "Wartortle");
	WARTORTLE.id = 8;
	WARTORTLE.type1 = WATER_T;
	WARTORTLE.type2 = NON_T;
	WARTORTLE.bstats.hp_base = 59;
	WARTORTLE.bstats.attack_base = 63;
	WARTORTLE.bstats.defense_base = 80;
	WARTORTLE.bstats.sattack_base = 65;
	WARTORTLE.bstats.sdefense_base = 80;
	WARTORTLE.bstats.speed_base = 58;

	// blastoise
	strcpy(BLASTOISE.name, "Blastoise");
	BLASTOISE.id = 9;
	BLASTOISE.type1 = WATER_T;
	BLASTOISE.type2 = NON_T;
	BLASTOISE.bstats.hp_base = 79;
	BLASTOISE.bstats.attack_base = 83;
	BLASTOISE.bstats.defense_base = 100;
	BLASTOISE.bstats.sattack_base = 85;
	BLASTOISE.bstats.sdefense_base = 105;
	BLASTOISE.bstats.speed_base = 78;

	// caterpie
	strcpy(CATERPIE.name, "Caterpie");
	CATERPIE.id = 10;
	CATERPIE.type1 = BUG_T;
	CATERPIE.type2 = NON_T;
	CATERPIE.bstats.hp_base = 45;
	CATERPIE.bstats.attack_base = 30;
	CATERPIE.bstats.defense_base = 35;
	CATERPIE.bstats.sattack_base = 20;
	CATERPIE.bstats.sdefense_base = 20;
	CATERPIE.bstats.speed_base = 45;

	// metapod
	strcpy(METAPOD.name, "Metapod");
	METAPOD.id = 11;
	METAPOD.type1 = BUG_T;
	METAPOD.type2 = NON_T;
	METAPOD.bstats.hp_base = 50;
	METAPOD.bstats.attack_base = 20;
	METAPOD.bstats.defense_base = 55;
	METAPOD.bstats.sattack_base = 25;
	METAPOD.bstats.sdefense_base = 25;
	METAPOD.bstats.speed_base = 30;

	// butterfree
	strcpy(BUTTERFREE.name, "Butterfree");
	BUTTERFREE.id = 12;
	BUTTERFREE.type1 = BUG_T;
	BUTTERFREE.type2 = FLYING_T;
	BUTTERFREE.bstats.hp_base = 60;
	BUTTERFREE.bstats.attack_base = 45;
	BUTTERFREE.bstats.defense_base = 50;
	BUTTERFREE.bstats.sattack_base = 90;
	BUTTERFREE.bstats.sdefense_base = 80;
	BUTTERFREE.bstats.speed_base = 70;

	// weedle
	strcpy(WEEDLE.name, "Weedle");
	WEEDLE.id = 13;
	WEEDLE.type1 = BUG_T;
	WEEDLE.type2 = POISON_T;
	WEEDLE.bstats.hp_base = 40;
	WEEDLE.bstats.attack_base = 35;
	WEEDLE.bstats.defense_base = 30;
	WEEDLE.bstats.sattack_base = 20;
	WEEDLE.bstats.sdefense_base = 20;
	WEEDLE.bstats.speed_base = 50;

	// kakuna
	strcpy(KAKUNA.name, "Kakuna");
	KAKUNA.id = 14;
	KAKUNA.type1 = BUG_T;
	KAKUNA.type2 = POISON_T;
	KAKUNA.bstats.hp_base = 45;
	KAKUNA.bstats.attack_base = 25;
	KAKUNA.bstats.defense_base = 50;
	KAKUNA.bstats.sattack_base = 25;
	KAKUNA.bstats.sdefense_base = 25;
	KAKUNA.bstats.speed_base = 35;

	// beedrill
	strcpy(BEEDRILL.name, "Beedrill");
	BEEDRILL.id = 15;
	BEEDRILL.type1 = BUG_T;
	BEEDRILL.type2 = POISON_T;
	BEEDRILL.bstats.hp_base = 65;
	BEEDRILL.bstats.attack_base = 90;
	BEEDRILL.bstats.defense_base = 40;
	BEEDRILL.bstats.sattack_base = 45;
	BEEDRILL.bstats.sdefense_base = 80;
	BEEDRILL.bstats.speed_base = 75;

	// pidgey
	strcpy(PIDGEY.name, "Pidgey");
	PIDGEY.id = 16;
	PIDGEY.type1 = NORMAL_T;
	PIDGEY.type2 = FLYING_T;
	PIDGEY.bstats.hp_base = 40;
	PIDGEY.bstats.attack_base = 45;
	PIDGEY.bstats.defense_base = 40;
	PIDGEY.bstats.sattack_base = 35;
	PIDGEY.bstats.sdefense_base = 35;
	PIDGEY.bstats.speed_base = 56;

	// pidgeotto
	strcpy(PIDGEOTTO.name, "Pidgeotto");
	PIDGEOTTO.id = 17;
	PIDGEOTTO.type1 = NORMAL_T;
	PIDGEOTTO.type2 = FLYING_T;
	PIDGEOTTO.bstats.hp_base = 63;
	PIDGEOTTO.bstats.attack_base = 60;
	PIDGEOTTO.bstats.defense_base = 55;
	PIDGEOTTO.bstats.sattack_base = 50;
	PIDGEOTTO.bstats.sdefense_base = 50;
	PIDGEOTTO.bstats.speed_base = 71;

	// pidgeot
	strcpy(PIDGEOT.name, "Pidgeot");
	PIDGEOT.id = 18;
	PIDGEOT.type1 = NORMAL_T;
	PIDGEOT.type2 = FLYING_T;
	PIDGEOT.bstats.hp_base = 83;
	PIDGEOT.bstats.attack_base = 80;
	PIDGEOT.bstats.defense_base = 75;
	PIDGEOT.bstats.sattack_base = 70;
	PIDGEOT.bstats.sdefense_base = 70;
	PIDGEOT.bstats.speed_base = 101;

	// rattata
	strcpy(RATTATA.name, "Rattata");
	RATTATA.id = 19;
	RATTATA.type1 = NORMAL_T;
	RATTATA.type2 = NON_T;
	RATTATA.bstats.hp_base = 30;
	RATTATA.bstats.attack_base = 56;
	RATTATA.bstats.defense_base = 35;
	RATTATA.bstats.sattack_base = 25;
	RATTATA.bstats.sdefense_base = 35;
	RATTATA.bstats.speed_base = 72;

	// raticate
	strcpy(RATICATE.name, "Raticate");
	RATICATE.id = 20;
	RATICATE.type1 = NORMAL_T;
	RATICATE.type2 = NON_T;
	RATICATE.bstats.hp_base = 55;
	RATICATE.bstats.attack_base = 81;
	RATICATE.bstats.defense_base = 60;
	RATICATE.bstats.sattack_base = 50;
	RATICATE.bstats.sdefense_base = 70;
	RATICATE.bstats.speed_base = 97;

	// spearow
	strcpy(SPEAROW.name, "Spearow");
	SPEAROW.id = 21;
	SPEAROW.type1 = NORMAL_T;
	SPEAROW.type2 = FLYING_T;
	SPEAROW.bstats.hp_base = 40;
	SPEAROW.bstats.attack_base = 60;
	SPEAROW.bstats.defense_base = 30;
	SPEAROW.bstats.sattack_base = 31;
	SPEAROW.bstats.sdefense_base = 31;
	SPEAROW.bstats.speed_base = 70;

	// fearow
	strcpy(FEAROW.name, "Fearow");
	FEAROW.id = 22;
	FEAROW.type1 = NORMAL_T;
	FEAROW.type2 = FLYING_T;
	FEAROW.bstats.hp_base = 65;
	FEAROW.bstats.attack_base = 90;
	FEAROW.bstats.defense_base = 65;
	FEAROW.bstats.sattack_base = 61;
	FEAROW.bstats.sdefense_base = 61;
	FEAROW.bstats.speed_base = 100;

	// ekans
	strcpy(EKANS.name, "Ekans");
	EKANS.id = 23;
	EKANS.type1 = POISON_T;
	EKANS.type2 = NON_T;
	EKANS.bstats.hp_base = 35;
	EKANS.bstats.attack_base = 60;
	EKANS.bstats.defense_base = 44;
	EKANS.bstats.sattack_base = 40;
	EKANS.bstats.sdefense_base = 54;
	EKANS.bstats.speed_base = 55;

	// arbok
	strcpy(ARBOK.name, "Arbok");
	ARBOK.id = 24;
	ARBOK.type1 = POISON_T;
	ARBOK.type2 = NON_T;
	ARBOK.bstats.hp_base = 60;
	ARBOK.bstats.attack_base = 85;
	ARBOK.bstats.defense_base = 69;
	ARBOK.bstats.sattack_base = 65;
	ARBOK.bstats.sdefense_base = 79;
	ARBOK.bstats.speed_base = 80;

	// pikachu
	strcpy(PIKACHU.name, "Pikachu");
	PIKACHU.id = 25;
	PIKACHU.type1 = ELECTRIC_T;
	PIKACHU.type2 = NON_T;
	PIKACHU.bstats.hp_base = 35;
	PIKACHU.bstats.attack_base = 55;
	PIKACHU.bstats.defense_base = 40;
	PIKACHU.bstats.sattack_base = 50;
	PIKACHU.bstats.sdefense_base = 50;
	PIKACHU.bstats.speed_base = 90;

	// raichu
	strcpy(RAICHU.name, "Raichu");
	RAICHU.id = 26;
	RAICHU.type1 = ELECTRIC_T;
	RAICHU.type2 = NON_T;
	RAICHU.bstats.hp_base = 60;
	RAICHU.bstats.attack_base = 90;
	RAICHU.bstats.defense_base = 55;
	RAICHU.bstats.sattack_base = 90;
	RAICHU.bstats.sdefense_base = 80;
	RAICHU.bstats.speed_base = 110;

	// sandshrew
	strcpy(SANDSHREW.name, "Sandshrew");
	SANDSHREW.id = 27;
	SANDSHREW.type1 = GROUND_T;
	SANDSHREW.type2 = NON_T;
	SANDSHREW.bstats.hp_base = 50;
	SANDSHREW.bstats.attack_base = 75;
	SANDSHREW.bstats.defense_base = 85;
	SANDSHREW.bstats.sattack_base = 20;
	SANDSHREW.bstats.sdefense_base = 30;
	SANDSHREW.bstats.speed_base = 40;

	// sandslash
	strcpy(SANDSLASH.name, "Sandslash");
	SANDSLASH.id = 28;
	SANDSLASH.type1 = GROUND_T;
	SANDSLASH.type2 = NON_T;
	SANDSLASH.bstats.hp_base = 75;
	SANDSLASH.bstats.attack_base = 100;
	SANDSLASH.bstats.defense_base = 110;
	SANDSLASH.bstats.sattack_base = 45;
	SANDSLASH.bstats.sdefense_base = 55;
	SANDSLASH.bstats.speed_base = 65;

	// nidoran_f
	strcpy(NIDORAN_F.name, "Nidoran (F)");
	NIDORAN_F.id = 29;
	NIDORAN_F.type1 = POISON_T;
	NIDORAN_F.type2 = NON_T;
	NIDORAN_F.bstats.hp_base = 55;
	NIDORAN_F.bstats.attack_base = 47;
	NIDORAN_F.bstats.defense_base = 52;
	NIDORAN_F.bstats.sattack_base = 40;
	NIDORAN_F.bstats.sdefense_base = 40;
	NIDORAN_F.bstats.speed_base = 41;

	// nidorina
	strcpy(NIDORINA.name, "Nidorina");
	NIDORINA.id = 30;
	NIDORINA.type1 = POISON_T;
	NIDORINA.type2 = NON_T;
	NIDORINA.bstats.hp_base = 70;
	NIDORINA.bstats.attack_base = 62;
	NIDORINA.bstats.defense_base = 67;
	NIDORINA.bstats.sattack_base = 55;
	NIDORINA.bstats.sdefense_base = 55;
	NIDORINA.bstats.speed_base = 56;

	// nidoqueen
	strcpy(NIDOQUEEN.name, "Nidoqueen");
	NIDOQUEEN.id = 31;
	NIDOQUEEN.type1 = POISON_T;
	NIDOQUEEN.type2 = GROUND_T;
	NIDOQUEEN.bstats.hp_base = 90;
	NIDOQUEEN.bstats.attack_base = 92;
	NIDOQUEEN.bstats.defense_base = 87;
	NIDOQUEEN.bstats.sattack_base = 75;
	NIDOQUEEN.bstats.sdefense_base = 85;
	NIDOQUEEN.bstats.speed_base = 76;

	// nidoran_m
	strcpy(NIDORAN_M.name, "Nidoran (M)");
	NIDORAN_M.id = 32;
	NIDORAN_M.type1 = POISON_T;
	NIDORAN_M.type2 = NON_T;
	NIDORAN_M.bstats.hp_base = 46;
	NIDORAN_M.bstats.attack_base = 57;
	NIDORAN_M.bstats.defense_base = 40;
	NIDORAN_M.bstats.sattack_base = 40;
	NIDORAN_M.bstats.sdefense_base = 40;
	NIDORAN_M.bstats.speed_base = 50;

	// nidorino
	strcpy(NIDORINO.name, "Nidorino");
	NIDORINO.id = 33;
	NIDORINO.type1 = POISON_T;
	NIDORINO.type2 = NON_T;
	NIDORINO.bstats.hp_base = 61;
	NIDORINO.bstats.attack_base = 72;
	NIDORINO.bstats.defense_base = 57;
	NIDORINO.bstats.sattack_base = 55;
	NIDORINO.bstats.sdefense_base = 55;
	NIDORINO.bstats.speed_base = 65;

	// nidoking
	strcpy(NIDOKING.name, "Nidoking");
	NIDOKING.id = 34;
	NIDOKING.type1 = POISON_T;
	NIDOKING.type2 = GROUND_T;
	NIDOKING.bstats.hp_base = 81;
	NIDOKING.bstats.attack_base = 102;
	NIDOKING.bstats.defense_base = 77;
	NIDOKING.bstats.sattack_base = 85;
	NIDOKING.bstats.sdefense_base = 75;
	NIDOKING.bstats.speed_base = 85;

	// clefairy
	strcpy(CLEFAIRY.name, "Clefairy");
	CLEFAIRY.id = 35;
	CLEFAIRY.type1 = FAIRY_T;
	CLEFAIRY.type2 = NON_T;
	CLEFAIRY.bstats.hp_base = 70;
	CLEFAIRY.bstats.attack_base = 45;
	CLEFAIRY.bstats.defense_base = 48;
	CLEFAIRY.bstats.sattack_base = 60;
	CLEFAIRY.bstats.sdefense_base = 65;
	CLEFAIRY.bstats.speed_base = 35;

	// clefable
	strcpy(CLEFABLE.name, "Clefable");
	CLEFABLE.id = 36;
	CLEFABLE.type1 = FAIRY_T;
	CLEFABLE.type2 = NON_T;
	CLEFABLE.bstats.hp_base = 95;
	CLEFABLE.bstats.attack_base = 70;
	CLEFABLE.bstats.defense_base = 73;
	CLEFABLE.bstats.sattack_base = 95;
	CLEFABLE.bstats.sdefense_base = 90;
	CLEFABLE.bstats.speed_base = 60;

	// vulpix
	strcpy(VULPIX.name, "Vulpix");
	VULPIX.id = 37;
	VULPIX.type1 = FIRE_T;
	VULPIX.type2 = NON_T;
	VULPIX.bstats.hp_base = 38;
	VULPIX.bstats.attack_base = 41;
	VULPIX.bstats.defense_base = 40;
	VULPIX.bstats.sattack_base = 50;
	VULPIX.bstats.sdefense_base = 65;
	VULPIX.bstats.speed_base = 65;

	// ninetales
	strcpy(NINETALES.name, "Ninetales");
	NINETALES.id = 38;
	NINETALES.type1 = FIRE_T;
	NINETALES.type2 = NON_T;
	NINETALES.bstats.hp_base = 73;
	NINETALES.bstats.attack_base = 76;
	NINETALES.bstats.defense_base = 75;
	NINETALES.bstats.sattack_base = 81;
	NINETALES.bstats.sdefense_base = 100;
	NINETALES.bstats.speed_base = 100;

	// jigglypuff
	strcpy(JIGGLYPUFF.name, "Jigglypuff");
	JIGGLYPUFF.id = 39;
	JIGGLYPUFF.type1 = NORMAL_T;
	JIGGLYPUFF.type2 = FAIRY_T;
	JIGGLYPUFF.bstats.hp_base = 115;
	JIGGLYPUFF.bstats.attack_base = 45;
	JIGGLYPUFF.bstats.defense_base = 20;
	JIGGLYPUFF.bstats.sattack_base = 45;
	JIGGLYPUFF.bstats.sdefense_base = 25;
	JIGGLYPUFF.bstats.speed_base = 20;

	// wigglytuff
	strcpy(WIGGLYTUFF.name, "Wigglytuff");
	WIGGLYTUFF.id = 40;
	WIGGLYTUFF.type1 = NORMAL_T;
	WIGGLYTUFF.type2 = FAIRY_T;
	WIGGLYTUFF.bstats.hp_base = 140;
	WIGGLYTUFF.bstats.attack_base = 70;
	WIGGLYTUFF.bstats.defense_base = 45;
	WIGGLYTUFF.bstats.sattack_base = 85;
	WIGGLYTUFF.bstats.sdefense_base = 50;
	WIGGLYTUFF.bstats.speed_base = 45;

	// zubat
	strcpy(ZUBAT.name, "Zubat");
	ZUBAT.id = 41;
	ZUBAT.type1 = POISON_T;
	ZUBAT.type2 = FLYING_T;
	ZUBAT.bstats.hp_base = 40;
	ZUBAT.bstats.attack_base = 45;
	ZUBAT.bstats.defense_base = 35;
	ZUBAT.bstats.sattack_base = 30;
	ZUBAT.bstats.sdefense_base = 40;
	ZUBAT.bstats.speed_base = 55;

	// golbat
	strcpy(GOLBAT.name, "Golbat");
	GOLBAT.id = 42;
	GOLBAT.type1 = POISON_T;
	GOLBAT.type2 = FLYING_T;
	GOLBAT.bstats.hp_base = 75;
	GOLBAT.bstats.attack_base = 80;
	GOLBAT.bstats.defense_base = 70;
	GOLBAT.bstats.sattack_base = 65;
	GOLBAT.bstats.sdefense_base = 75;
	GOLBAT.bstats.speed_base = 90;

	// oddish
	strcpy(ODDISH.name, "Oddish");
	ODDISH.id = 43;
	ODDISH.type1 = GRASS_T;
	ODDISH.type2 = POISON_T;
	ODDISH.bstats.hp_base = 45;
	ODDISH.bstats.attack_base = 50;
	ODDISH.bstats.defense_base = 55;
	ODDISH.bstats.sattack_base = 75;
	ODDISH.bstats.sdefense_base = 65;
	ODDISH.bstats.speed_base = 30;

	// gloom
	strcpy(GLOOM.name, "Gloom");
	GLOOM.id = 44;
	GLOOM.type1 = GRASS_T;
	GLOOM.type2 = POISON_T;
	GLOOM.bstats.hp_base = 60;
	GLOOM.bstats.attack_base = 65;
	GLOOM.bstats.defense_base = 70;
	GLOOM.bstats.sattack_base = 85;
	GLOOM.bstats.sdefense_base = 75;
	GLOOM.bstats.speed_base = 40;

	// vileplume
	strcpy(VILEPLUME.name, "Vileplume");
	VILEPLUME.id = 45;
	VILEPLUME.type1 = GRASS_T;
	VILEPLUME.type2 = POISON_T;
	VILEPLUME.bstats.hp_base = 75;
	VILEPLUME.bstats.attack_base = 80;
	VILEPLUME.bstats.defense_base = 85;
	VILEPLUME.bstats.sattack_base = 110;
	VILEPLUME.bstats.sdefense_base = 90;
	VILEPLUME.bstats.speed_base = 50;

	// paras
	strcpy(PARAS.name, "Paras");
	PARAS.id = 46;
	PARAS.type1 = BUG_T;
	PARAS.type2 = GRASS_T;
	PARAS.bstats.hp_base = 35;
	PARAS.bstats.attack_base = 70;
	PARAS.bstats.defense_base = 55;
	PARAS.bstats.sattack_base = 45;
	PARAS.bstats.sdefense_base = 55;
	PARAS.bstats.speed_base = 25;

	// parasect
	strcpy(PARASECT.name, "Parasect");
	PARASECT.id = 47;
	PARASECT.type1 = BUG_T;
	PARASECT.type2 = GRASS_T;
	PARASECT.bstats.hp_base = 60;
	PARASECT.bstats.attack_base = 95;
	PARASECT.bstats.defense_base = 80;
	PARASECT.bstats.sattack_base = 60;
	PARASECT.bstats.sdefense_base = 80;
	PARASECT.bstats.speed_base = 30;

	// venonat
	strcpy(VENONAT.name, "Venonat");
	VENONAT.id = 48;
	VENONAT.type1 = BUG_T;
	VENONAT.type2 = POISON_T;
	VENONAT.bstats.hp_base = 60;
	VENONAT.bstats.attack_base = 55;
	VENONAT.bstats.defense_base = 50;
	VENONAT.bstats.sattack_base = 40;
	VENONAT.bstats.sdefense_base = 55;
	VENONAT.bstats.speed_base = 45;

	// venomoth
	strcpy(VENOMOTH.name, "Venomoth");
	VENOMOTH.id = 49;
	VENOMOTH.type1 = BUG_T;
	VENOMOTH.type2 = POISON_T;
	VENOMOTH.bstats.hp_base = 70;
	VENOMOTH.bstats.attack_base = 65;
	VENOMOTH.bstats.defense_base = 60;
	VENOMOTH.bstats.sattack_base = 90;
	VENOMOTH.bstats.sdefense_base = 75;
	VENOMOTH.bstats.speed_base = 90;

	// diglett
	strcpy(DIGLETT.name, "Diglett");
	DIGLETT.id = 50;
	DIGLETT.type1 = GROUND_T;
	DIGLETT.type2 = NON_T;
	DIGLETT.bstats.hp_base = 10;
	DIGLETT.bstats.attack_base = 55;
	DIGLETT.bstats.defense_base = 25;
	DIGLETT.bstats.sattack_base = 35;
	DIGLETT.bstats.sdefense_base = 45;
	DIGLETT.bstats.speed_base = 95;

	// dugtrio
	strcpy(DUGTRIO.name, "Dugtrio");
	DUGTRIO.id = 51;
	DUGTRIO.type1 = GROUND_T;
	DUGTRIO.type2 = NON_T;
	DUGTRIO.bstats.hp_base = 35;
	DUGTRIO.bstats.attack_base = 80;
	DUGTRIO.bstats.defense_base = 50;
	DUGTRIO.bstats.sattack_base = 50;
	DUGTRIO.bstats.sdefense_base = 70;
	DUGTRIO.bstats.speed_base = 120;

	// meowth
	strcpy(MEOWTH.name, "Meowth");
	MEOWTH.id = 52;
	MEOWTH.type1 = NORMAL_T;
	MEOWTH.type2 = NON_T;
	MEOWTH.bstats.hp_base = 40;
	MEOWTH.bstats.attack_base = 45;
	MEOWTH.bstats.defense_base = 35;
	MEOWTH.bstats.sattack_base = 40;
	MEOWTH.bstats.sdefense_base = 40;
	MEOWTH.bstats.speed_base = 90;

	// persian
	strcpy(PERSIAN.name, "Persian");
	PERSIAN.id = 53;
	PERSIAN.type1 = NORMAL_T;
	PERSIAN.type2 = NON_T;
	PERSIAN.bstats.hp_base = 65;
	PERSIAN.bstats.attack_base = 70;
	PERSIAN.bstats.defense_base = 60;
	PERSIAN.bstats.sattack_base = 65;
	PERSIAN.bstats.sdefense_base = 65;
	PERSIAN.bstats.speed_base = 115;

	// psyduck
	strcpy(PSYDUCK.name, "Psyduck");
	PSYDUCK.id = 54;
	PSYDUCK.type1 = WATER_T;
	PSYDUCK.type2 = NON_T;
	PSYDUCK.bstats.hp_base = 50;
	PSYDUCK.bstats.attack_base = 52;
	PSYDUCK.bstats.defense_base = 48;
	PSYDUCK.bstats.sattack_base = 65;
	PSYDUCK.bstats.sdefense_base = 50;
	PSYDUCK.bstats.speed_base = 55;

	// golduck
	strcpy(GOLDUCK.name, "Golduck");
	GOLDUCK.id = 55;
	GOLDUCK.type1 = WATER_T;
	GOLDUCK.type2 = NON_T;
	GOLDUCK.bstats.hp_base = 80;
	GOLDUCK.bstats.attack_base = 82;
	GOLDUCK.bstats.defense_base = 78;
	GOLDUCK.bstats.sattack_base = 95;
	GOLDUCK.bstats.sdefense_base = 80;
	GOLDUCK.bstats.speed_base = 85;

	// mankey
	strcpy(MANKEY.name, "Mankey");
	MANKEY.id = 56;
	MANKEY.type1 = FIGHTING_T;
	MANKEY.type2 = NON_T;
	MANKEY.bstats.hp_base = 40;
	MANKEY.bstats.attack_base = 80;
	MANKEY.bstats.defense_base = 35;
	MANKEY.bstats.sattack_base = 35;
	MANKEY.bstats.sdefense_base = 45;
	MANKEY.bstats.speed_base = 70;

	// primeape
	strcpy(PRIMEAPE.name, "Primeape");
	PRIMEAPE.id = 57;
	PRIMEAPE.type1 = FIGHTING_T;
	PRIMEAPE.type2 = NON_T;
	PRIMEAPE.bstats.hp_base = 65;
	PRIMEAPE.bstats.attack_base = 105;
	PRIMEAPE.bstats.defense_base = 60;
	PRIMEAPE.bstats.sattack_base = 60;
	PRIMEAPE.bstats.sdefense_base = 70;
	PRIMEAPE.bstats.speed_base = 95;

	// growlithe
	strcpy(GROWLITHE.name, "Growlithe");
	GROWLITHE.id = 58;
	GROWLITHE.type1 = FIRE_T;
	GROWLITHE.type2 = NON_T;
	GROWLITHE.bstats.hp_base = 55;
	GROWLITHE.bstats.attack_base = 70;
	GROWLITHE.bstats.defense_base = 45;
	GROWLITHE.bstats.sattack_base = 70;
	GROWLITHE.bstats.sdefense_base = 50;
	GROWLITHE.bstats.speed_base = 60;

	// arcanine
	strcpy(ARCANINE.name, "Arcanine");
	ARCANINE.id = 59;
	ARCANINE.type1 = FIRE_T;
	ARCANINE.type2 = NON_T;
	ARCANINE.bstats.hp_base = 90;
	ARCANINE.bstats.attack_base = 110;
	ARCANINE.bstats.defense_base = 80;
	ARCANINE.bstats.sattack_base = 100;
	ARCANINE.bstats.sdefense_base = 80;
	ARCANINE.bstats.speed_base = 95;

	// poliwag
	strcpy(POLIWAG.name, "Poliwag");
	POLIWAG.id = 60;
	POLIWAG.type1 = WATER_T;
	POLIWAG.type2 = NON_T;
	POLIWAG.bstats.hp_base = 40;
	POLIWAG.bstats.attack_base = 50;
	POLIWAG.bstats.defense_base = 40;
	POLIWAG.bstats.sattack_base = 40;
	POLIWAG.bstats.sdefense_base = 40;
	POLIWAG.bstats.speed_base = 90;

	// poliwhirl
	strcpy(POLIWHIRL.name, "Poliwhirl");
	POLIWHIRL.id = 61;
	POLIWHIRL.type1 = WATER_T;
	POLIWHIRL.type2 = NON_T;
	POLIWHIRL.bstats.hp_base = 65;
	POLIWHIRL.bstats.attack_base = 65;
	POLIWHIRL.bstats.defense_base = 65;
	POLIWHIRL.bstats.sattack_base = 50;
	POLIWHIRL.bstats.sdefense_base = 50;
	POLIWHIRL.bstats.speed_base = 90;

	// poliwrath
	strcpy(POLIWRATH.name, "Poliwrath");
	POLIWRATH.id = 62;
	POLIWRATH.type1 = WATER_T;
	POLIWRATH.type2 = FIGHTING_T;
	POLIWRATH.bstats.hp_base = 90;
	POLIWRATH.bstats.attack_base = 95;
	POLIWRATH.bstats.defense_base = 95;
	POLIWRATH.bstats.sattack_base = 70;
	POLIWRATH.bstats.sdefense_base = 90;
	POLIWRATH.bstats.speed_base = 70;

	// abra
	strcpy(ABRA.name, "Abra");
	ABRA.id = 63;
	ABRA.type1 = PSYCHIC_T;
	ABRA.type2 = NON_T;
	ABRA.bstats.hp_base = 25;
	ABRA.bstats.attack_base = 20;
	ABRA.bstats.defense_base = 15;
	ABRA.bstats.sattack_base = 105;
	ABRA.bstats.sdefense_base = 55;
	ABRA.bstats.speed_base = 90;

	// kadabra
	strcpy(KADABRA.name, "Kadabra");
	KADABRA.id = 64;
	KADABRA.type1 = PSYCHIC_T;
	KADABRA.type2 = NON_T;
	KADABRA.bstats.hp_base = 40;
	KADABRA.bstats.attack_base = 35;
	KADABRA.bstats.defense_base = 30;
	KADABRA.bstats.sattack_base = 120;
	KADABRA.bstats.sdefense_base = 70;
	KADABRA.bstats.speed_base = 105;

	// alakazam
	strcpy(ALAKAZAM.name, "Alakazam");
	ALAKAZAM.id = 65;
	ALAKAZAM.type1 = PSYCHIC_T;
	ALAKAZAM.type2 = NON_T;
	ALAKAZAM.bstats.hp_base = 55;
	ALAKAZAM.bstats.attack_base = 50;
	ALAKAZAM.bstats.defense_base = 45;
	ALAKAZAM.bstats.sattack_base = 135;
	ALAKAZAM.bstats.sdefense_base = 95;
	ALAKAZAM.bstats.speed_base = 120;

	// machop
	strcpy(MACHOP.name, "Machop");
	MACHOP.id = 66;
	MACHOP.type1 = FIGHTING_T;
	MACHOP.type2 = NON_T;
	MACHOP.bstats.hp_base = 70;
	MACHOP.bstats.attack_base = 80;
	MACHOP.bstats.defense_base = 50;
	MACHOP.bstats.sattack_base = 35;
	MACHOP.bstats.sdefense_base = 35;
	MACHOP.bstats.speed_base = 35;

	// machoke
	strcpy(MACHOKE.name, "Machoke");
	MACHOKE.id = 67;
	MACHOKE.type1 = FIGHTING_T;
	MACHOKE.type2 = NON_T;
	MACHOKE.bstats.hp_base = 80;
	MACHOKE.bstats.attack_base = 100;
	MACHOKE.bstats.defense_base = 70;
	MACHOKE.bstats.sattack_base = 50;
	MACHOKE.bstats.sdefense_base = 60;
	MACHOKE.bstats.speed_base = 45;

	// machamp
	strcpy(MACHAMP.name, "Machamp");
	MACHAMP.id = 68;
	MACHAMP.type1 = FIGHTING_T;
	MACHAMP.type2 = NON_T;
	MACHAMP.bstats.hp_base = 90;
	MACHAMP.bstats.attack_base = 130;
	MACHAMP.bstats.defense_base = 80;
	MACHAMP.bstats.sattack_base = 65;
	MACHAMP.bstats.sdefense_base = 85;
	MACHAMP.bstats.speed_base = 55;

	// bellsprout
	strcpy(BELLSPROUT.name, "Bellsprout");
	BELLSPROUT.id = 69;
	BELLSPROUT.type1 = GRASS_T;
	BELLSPROUT.type2 = POISON_T;
	BELLSPROUT.bstats.hp_base = 50;
	BELLSPROUT.bstats.attack_base = 75;
	BELLSPROUT.bstats.defense_base = 35;
	BELLSPROUT.bstats.sattack_base = 70;
	BELLSPROUT.bstats.sdefense_base = 30;
	BELLSPROUT.bstats.speed_base = 40;

	// weepinbell
	strcpy(WEEPINBELL.name, "Weepinbell");
	WEEPINBELL.id = 70;
	WEEPINBELL.type1 = GRASS_T;
	WEEPINBELL.type2 = POISON_T;
	WEEPINBELL.bstats.hp_base = 65;
	WEEPINBELL.bstats.attack_base = 90;
	WEEPINBELL.bstats.defense_base = 50;
	WEEPINBELL.bstats.sattack_base = 85;
	WEEPINBELL.bstats.sdefense_base = 45;
	WEEPINBELL.bstats.speed_base = 55;

	// victreebel
	strcpy(VICTREEBEL.name, "Victreebel");
	VICTREEBEL.id = 71;
	VICTREEBEL.type1 = GRASS_T;
	VICTREEBEL.type2 = POISON_T;
	VICTREEBEL.bstats.hp_base = 80;
	VICTREEBEL.bstats.attack_base = 105;
	VICTREEBEL.bstats.defense_base = 65;
	VICTREEBEL.bstats.sattack_base = 100;
	VICTREEBEL.bstats.sdefense_base = 70;
	VICTREEBEL.bstats.speed_base = 70;

	// tentacool
	strcpy(TENTACOOL.name, "Tentacool");
	TENTACOOL.id = 72;
	TENTACOOL.type1 = WATER_T;
	TENTACOOL.type2 = POISON_T;
	TENTACOOL.bstats.hp_base = 40;
	TENTACOOL.bstats.attack_base = 40;
	TENTACOOL.bstats.defense_base = 35;
	TENTACOOL.bstats.sattack_base = 50;
	TENTACOOL.bstats.sdefense_base = 100;
	TENTACOOL.bstats.speed_base = 70;

	// tentacruel
	strcpy(TENTACRUEL.name, "Tentacruel");
	TENTACRUEL.id = 73;
	TENTACRUEL.type1 = WATER_T;
	TENTACRUEL.type2 = POISON_T;
	TENTACRUEL.bstats.hp_base = 80;
	TENTACRUEL.bstats.attack_base = 70;
	TENTACRUEL.bstats.defense_base = 65;
	TENTACRUEL.bstats.sattack_base = 80;
	TENTACRUEL.bstats.sdefense_base = 120;
	TENTACRUEL.bstats.speed_base = 100;

	// geodude
	strcpy(GEODUDE.name, "Geodude");
	GEODUDE.id = 74;
	GEODUDE.type1 = ROCK_T;
	GEODUDE.type2 = GROUND_T;
	GEODUDE.bstats.hp_base = 40;
	GEODUDE.bstats.attack_base = 80;
	GEODUDE.bstats.defense_base = 100;
	GEODUDE.bstats.sattack_base = 30;
	GEODUDE.bstats.sdefense_base = 30;
	GEODUDE.bstats.speed_base = 20;

	// graveler
	strcpy(GRAVELER.name, "Graveler");
	GRAVELER.id = 75;
	GRAVELER.type1 = ROCK_T;
	GRAVELER.type2 = GROUND_T;
	GRAVELER.bstats.hp_base = 55;
	GRAVELER.bstats.attack_base = 95;
	GRAVELER.bstats.defense_base = 115;
	GRAVELER.bstats.sattack_base = 45;
	GRAVELER.bstats.sdefense_base = 45;
	GRAVELER.bstats.speed_base = 35;

	// golem
	strcpy(GOLEM.name, "Golem");
	GOLEM.id = 76;
	GOLEM.type1 = ROCK_T;
	GOLEM.type2 = GROUND_T;
	GOLEM.bstats.hp_base = 80;
	GOLEM.bstats.attack_base = 120;
	GOLEM.bstats.defense_base = 130;
	GOLEM.bstats.sattack_base = 55;
	GOLEM.bstats.sdefense_base = 65;
	GOLEM.bstats.speed_base = 45;

	// ponyta
	strcpy(PONYTA.name, "Ponyta");
	PONYTA.id = 77;
	PONYTA.type1 = FIRE_T;
	PONYTA.type2 = NON_T;
	PONYTA.bstats.hp_base = 50;
	PONYTA.bstats.attack_base = 85;
	PONYTA.bstats.defense_base = 55;
	PONYTA.bstats.sattack_base = 65;
	PONYTA.bstats.sdefense_base = 65;
	PONYTA.bstats.speed_base = 90;

	// rapidash
	strcpy(RAPIDASH.name, "Rapidash");
	RAPIDASH.id = 78;
	RAPIDASH.type1 = FIRE_T;
	RAPIDASH.type2 = NON_T;
	RAPIDASH.bstats.hp_base = 65;
	RAPIDASH.bstats.attack_base = 100;
	RAPIDASH.bstats.defense_base = 70;
	RAPIDASH.bstats.sattack_base = 80;
	RAPIDASH.bstats.sdefense_base = 80;
	RAPIDASH.bstats.speed_base = 105;

	// slowpoke
	strcpy(SLOWPOKE.name, "Slowpoke");
	SLOWPOKE.id = 79;
	SLOWPOKE.type1 = WATER_T;
	SLOWPOKE.type2 = PSYCHIC_T;
	SLOWPOKE.bstats.hp_base = 90;
	SLOWPOKE.bstats.attack_base = 65;
	SLOWPOKE.bstats.defense_base = 65;
	SLOWPOKE.bstats.sattack_base = 40;
	SLOWPOKE.bstats.sdefense_base = 40;
	SLOWPOKE.bstats.speed_base = 15;

	// slowbro
	strcpy(SLOWBRO.name, "Slowbro");
	SLOWBRO.id = 80;
	SLOWBRO.type1 = WATER_T;
	SLOWBRO.type2 = PSYCHIC_T;
	SLOWBRO.bstats.hp_base = 95;
	SLOWBRO.bstats.attack_base = 75;
	SLOWBRO.bstats.defense_base = 110;
	SLOWBRO.bstats.sattack_base = 100;
	SLOWBRO.bstats.sdefense_base = 80;
	SLOWBRO.bstats.speed_base = 30;

	// magnemite
	strcpy(MAGNEMITE.name, "Magnemite");
	MAGNEMITE.id = 81;
	MAGNEMITE.type1 = ELECTRIC_T;
	MAGNEMITE.type2 = STEEL_T;
	MAGNEMITE.bstats.hp_base = 25;
	MAGNEMITE.bstats.attack_base = 35;
	MAGNEMITE.bstats.defense_base = 70;
	MAGNEMITE.bstats.sattack_base = 95;
	MAGNEMITE.bstats.sdefense_base = 55;
	MAGNEMITE.bstats.speed_base = 45;

	// magneton
	strcpy(MAGNETON.name, "Magneton");
	MAGNETON.id = 82;
	MAGNETON.type1 = ELECTRIC_T;
	MAGNETON.type2 = STEEL_T;
	MAGNETON.bstats.hp_base = 50;
	MAGNETON.bstats.attack_base = 60;
	MAGNETON.bstats.defense_base = 95;
	MAGNETON.bstats.sattack_base = 120;
	MAGNETON.bstats.sdefense_base = 70;
	MAGNETON.bstats.speed_base = 70;

	// farfetch'd
	strcpy(FARFETCHD.name, "Farfetch'd");
	FARFETCHD.id = 83;
	FARFETCHD.type1 = NORMAL_T;
	FARFETCHD.type2 = FLYING_T;
	FARFETCHD.bstats.hp_base = 52;
	FARFETCHD.bstats.attack_base = 65;
	FARFETCHD.bstats.defense_base = 55;
	FARFETCHD.bstats.sattack_base = 58;
	FARFETCHD.bstats.sdefense_base = 62;
	FARFETCHD.bstats.speed_base = 60;

	// doduo
	strcpy(DODUO.name, "Doduo");
	DODUO.id = 84;
	DODUO.type1 = NORMAL_T;
	DODUO.type2 = FLYING_T;
	DODUO.bstats.hp_base = 35;
	DODUO.bstats.attack_base = 85;
	DODUO.bstats.defense_base = 45;
	DODUO.bstats.sattack_base = 35;
	DODUO.bstats.sdefense_base = 35;
	DODUO.bstats.speed_base = 75;

	// dodrio
	strcpy(DODRIO.name, "Dodrio");
	DODRIO.id = 85;
	DODRIO.type1 = NORMAL_T;
	DODRIO.type2 = FLYING_T;
	DODRIO.bstats.hp_base = 60;
	DODRIO.bstats.attack_base = 110;
	DODRIO.bstats.defense_base = 70;
	DODRIO.bstats.sattack_base = 60;
	DODRIO.bstats.sdefense_base = 60;
	DODRIO.bstats.speed_base = 100;

	// seel
	strcpy(SEEL.name, "Seel");
	SEEL.id = 86;
	SEEL.type1 = WATER_T;
	SEEL.type2 = NON_T;
	SEEL.bstats.hp_base = 65;
	SEEL.bstats.attack_base = 45;
	SEEL.bstats.defense_base = 55;
	SEEL.bstats.sattack_base = 45;
	SEEL.bstats.sdefense_base = 70;
	SEEL.bstats.speed_base = 45;

	// dewgong
	strcpy(DEWGONG.name, "Dewgong");
	DEWGONG.id = 87;
	DEWGONG.type1 = WATER_T;
	DEWGONG.type2 = ICE_T;
	DEWGONG.bstats.hp_base = 90;
	DEWGONG.bstats.attack_base = 70;
	DEWGONG.bstats.defense_base = 80;
	DEWGONG.bstats.sattack_base = 70;
	DEWGONG.bstats.sdefense_base = 95;
	DEWGONG.bstats.speed_base = 70;

	// grimer
	strcpy(GRIMER.name, "Grimer");
	GRIMER.id = 88;
	GRIMER.type1 = POISON_T;
	GRIMER.type2 = NON_T;
	GRIMER.bstats.hp_base = 80;
	GRIMER.bstats.attack_base = 80;
	GRIMER.bstats.defense_base = 50;
	GRIMER.bstats.sattack_base = 40;
	GRIMER.bstats.sdefense_base = 50;
	GRIMER.bstats.speed_base = 25;

	// muk
	strcpy(MUK.name, "Muk");
	MUK.id = 89;
	MUK.type1 = POISON_T;
	MUK.type2 = NON_T;
	MUK.bstats.hp_base = 105;
	MUK.bstats.attack_base = 105;
	MUK.bstats.defense_base = 75;
	MUK.bstats.sattack_base = 65;
	MUK.bstats.sdefense_base = 100;
	MUK.bstats.speed_base = 50;

	// shellder
	strcpy(SHELLDER.name, "Shellder");
	SHELLDER.id = 90;
	SHELLDER.type1 = WATER_T;
	SHELLDER.type2 = NON_T;
	SHELLDER.bstats.hp_base = 30;
	SHELLDER.bstats.attack_base = 65;
	SHELLDER.bstats.defense_base = 100;
	SHELLDER.bstats.sattack_base = 45;
	SHELLDER.bstats.sdefense_base = 25;
	SHELLDER.bstats.speed_base = 40;

	// cloyster
	strcpy(CLOYSTER.name, "Cloyster");
	CLOYSTER.id = 91;
	CLOYSTER.type1 = WATER_T;
	CLOYSTER.type2 = ICE_T;
	CLOYSTER.bstats.hp_base = 50;
	CLOYSTER.bstats.attack_base = 95;
	CLOYSTER.bstats.defense_base = 180;
	CLOYSTER.bstats.sattack_base = 85;
	CLOYSTER.bstats.sdefense_base = 45;
	CLOYSTER.bstats.speed_base = 70;

	// gastly
	strcpy(GASTLY.name, "Gastly");
	GASTLY.id = 92;
	GASTLY.type1 = GHOST_T;
	GASTLY.type2 = POISON_T;
	GASTLY.bstats.hp_base = 30;
	GASTLY.bstats.attack_base = 35;
	GASTLY.bstats.defense_base = 30;
	GASTLY.bstats.sattack_base = 100;
	GASTLY.bstats.sdefense_base = 35;
	GASTLY.bstats.speed_base = 80;

	// haunter
	strcpy(HAUNTER.name, "Haunter");
	HAUNTER.id = 93;
	HAUNTER.type1 = GHOST_T;
	HAUNTER.type2 = POISON_T;
	HAUNTER.bstats.hp_base = 45;
	HAUNTER.bstats.attack_base = 50;
	HAUNTER.bstats.defense_base = 45;
	HAUNTER.bstats.sattack_base = 115;
	HAUNTER.bstats.sdefense_base = 55;
	HAUNTER.bstats.speed_base = 95;

	// gengar
	strcpy(GENGAR.name, "Gengar");
	GENGAR.id = 94;
	GENGAR.type1 = GHOST_T;
	GENGAR.type2 = POISON_T;
	GENGAR.bstats.hp_base = 60;
	GENGAR.bstats.attack_base = 65;
	GENGAR.bstats.defense_base = 60;
	GENGAR.bstats.sattack_base = 130;
	GENGAR.bstats.sdefense_base = 75;
	GENGAR.bstats.speed_base = 110;

	// onix
	strcpy(ONIX.name, "Onix");
	ONIX.id = 95;
	ONIX.type1 = ROCK_T;
	ONIX.type2 = GROUND_T;
	ONIX.bstats.hp_base = 35;
	ONIX.bstats.attack_base = 45;
	ONIX.bstats.defense_base = 160;
	ONIX.bstats.sattack_base = 30;
	ONIX.bstats.sdefense_base = 45;
	ONIX.bstats.speed_base = 70;

	// drowzee
	strcpy(DROWZEE.name, "Drowzee");
	DROWZEE.id = 96;
	DROWZEE.type1 = PSYCHIC_T;
	DROWZEE.type2 = NON_T;
	DROWZEE.bstats.hp_base = 60;
	DROWZEE.bstats.attack_base = 48;
	DROWZEE.bstats.defense_base = 45;
	DROWZEE.bstats.sattack_base = 43;
	DROWZEE.bstats.sdefense_base = 90;
	DROWZEE.bstats.speed_base = 42;

	// hypno
	strcpy(HYPNO.name, "Hypno");
	HYPNO.id = 97;
	HYPNO.type1 = PSYCHIC_T;
	HYPNO.type2 = NON_T;
	HYPNO.bstats.hp_base = 85;
	HYPNO.bstats.attack_base = 73;
	HYPNO.bstats.defense_base = 70;
	HYPNO.bstats.sattack_base = 73;
	HYPNO.bstats.sdefense_base = 115;
	HYPNO.bstats.speed_base = 67;

	// krabby
	strcpy(KRABBY.name, "Krabby");
	KRABBY.id = 98;
	KRABBY.type1 = WATER_T;
	KRABBY.type2 = NON_T;
	KRABBY.bstats.hp_base = 30;
	KRABBY.bstats.attack_base = 105;
	KRABBY.bstats.defense_base = 90;
	KRABBY.bstats.sattack_base = 25;
	KRABBY.bstats.sdefense_base = 25;
	KRABBY.bstats.speed_base = 50;

	// kingler
	strcpy(KINGLER.name, "Kingler");
	KINGLER.id = 99;
	KINGLER.type1 = WATER_T;
	KINGLER.type2 = NON_T;
	KINGLER.bstats.hp_base = 55;
	KINGLER.bstats.attack_base = 130;
	KINGLER.bstats.defense_base = 115;
	KINGLER.bstats.sattack_base = 50;
	KINGLER.bstats.sdefense_base = 50;
	KINGLER.bstats.speed_base = 75;

	// voltorb
	strcpy(VOLTORB.name, "Voltorb");
	VOLTORB.id = 100;
	VOLTORB.type1 = ELECTRIC_T;
	VOLTORB.type2 = NON_T;
	VOLTORB.bstats.hp_base = 40;
	VOLTORB.bstats.attack_base = 30;
	VOLTORB.bstats.defense_base = 50;
	VOLTORB.bstats.sattack_base = 55;
	VOLTORB.bstats.sdefense_base = 55;
	VOLTORB.bstats.speed_base = 100;

	// electrode
	strcpy(ELECTRODE.name, "Electrode");
	ELECTRODE.id = 101;
	ELECTRODE.type1 = ELECTRIC_T;
	ELECTRODE.type2 = NON_T;
	ELECTRODE.bstats.hp_base = 60;
	ELECTRODE.bstats.attack_base = 50;
	ELECTRODE.bstats.defense_base = 70;
	ELECTRODE.bstats.sattack_base = 80;
	ELECTRODE.bstats.sdefense_base = 80;
	ELECTRODE.bstats.speed_base = 140;

	// exeggcute
	strcpy(EXEGGCUTE.name, "Exeggcute");
	EXEGGCUTE.id = 102;
	EXEGGCUTE.type1 = GRASS_T;
	EXEGGCUTE.type2 = PSYCHIC_T;
	EXEGGCUTE.bstats.hp_base = 60;
	EXEGGCUTE.bstats.attack_base = 40;
	EXEGGCUTE.bstats.defense_base = 80;
	EXEGGCUTE.bstats.sattack_base = 60;
	EXEGGCUTE.bstats.sdefense_base = 45;
	EXEGGCUTE.bstats.speed_base = 40;

	// exeggutor
	strcpy(EXEGGUTOR.name, "Exeggutor");
	EXEGGUTOR.id = 103;
	EXEGGUTOR.type1 = GRASS_T;
	EXEGGUTOR.type2 = PSYCHIC_T;
	EXEGGUTOR.bstats.hp_base = 95;
	EXEGGUTOR.bstats.attack_base = 95;
	EXEGGUTOR.bstats.defense_base = 85;
	EXEGGUTOR.bstats.sattack_base = 125;
	EXEGGUTOR.bstats.sdefense_base = 65;
	EXEGGUTOR.bstats.speed_base = 55;

	// cubone
	strcpy(CUBONE.name, "Cubone");
	CUBONE.id = 104;
	CUBONE.type1 = GROUND_T;
	CUBONE.type2 = NON_T;
	CUBONE.bstats.hp_base = 50;
	CUBONE.bstats.attack_base = 50;
	CUBONE.bstats.defense_base = 95;
	CUBONE.bstats.sattack_base = 40;
	CUBONE.bstats.sdefense_base = 50;
	CUBONE.bstats.speed_base = 35;

	// marowak
	strcpy(MAROWAK.name, "Marowak");
	MAROWAK.id = 105;
	MAROWAK.type1 = GROUND_T;
	MAROWAK.type2 = NON_T;
	MAROWAK.bstats.hp_base = 60;
	MAROWAK.bstats.attack_base = 80;
	MAROWAK.bstats.defense_base = 110;
	MAROWAK.bstats.sattack_base = 50;
	MAROWAK.bstats.sdefense_base = 80;
	MAROWAK.bstats.speed_base = 45;

	// hitmonlee
	strcpy(HITMONLEE.name, "Hitmonlee");
	HITMONLEE.id = 106;
	HITMONLEE.type1 = FIGHTING_T;
	HITMONLEE.type2 = NON_T;
	HITMONLEE.bstats.hp_base = 50;
	HITMONLEE.bstats.attack_base = 120;
	HITMONLEE.bstats.defense_base = 53;
	HITMONLEE.bstats.sattack_base = 35;
	HITMONLEE.bstats.sdefense_base = 110;
	HITMONLEE.bstats.speed_base = 87;

	// hitmonchan
	strcpy(HITMONCHAN.name, "Hitmonchan");
	HITMONCHAN.id = 107;
	HITMONCHAN.type1 = FIGHTING_T;
	HITMONCHAN.type2 = NON_T;
	HITMONCHAN.bstats.hp_base = 50;
	HITMONCHAN.bstats.attack_base = 105;
	HITMONCHAN.bstats.defense_base = 79;
	HITMONCHAN.bstats.sattack_base = 35;
	HITMONCHAN.bstats.sdefense_base = 110;
	HITMONCHAN.bstats.speed_base = 76;

	// lickitung
	strcpy(LICKITUNG.name, "Lickitung");
	LICKITUNG.id = 108;
	LICKITUNG.type1 = NORMAL_T;
	LICKITUNG.type2 = NON_T;
	LICKITUNG.bstats.hp_base = 90;
	LICKITUNG.bstats.attack_base = 55;
	LICKITUNG.bstats.defense_base = 75;
	LICKITUNG.bstats.sattack_base = 60;
	LICKITUNG.bstats.sdefense_base = 75;
	LICKITUNG.bstats.speed_base = 30;

	// koffing
	strcpy(KOFFING.name, "Koffing");
	KOFFING.id = 109;
	KOFFING.type1 = POISON_T;
	KOFFING.type2 = NON_T;
	KOFFING.bstats.hp_base = 40;
	KOFFING.bstats.attack_base = 65;
	KOFFING.bstats.defense_base = 95;
	KOFFING.bstats.sattack_base = 60;
	KOFFING.bstats.sdefense_base = 45;
	KOFFING.bstats.speed_base = 35;

	// weezing
	strcpy(WEEZING.name, "Weezing");
	WEEZING.id = 110;
	WEEZING.type1 = POISON_T;
	WEEZING.type2 = NON_T;
	WEEZING.bstats.hp_base = 65;
	WEEZING.bstats.attack_base = 90;
	WEEZING.bstats.defense_base = 120;
	WEEZING.bstats.sattack_base = 85;
	WEEZING.bstats.sdefense_base = 70;
	WEEZING.bstats.speed_base = 60;

	// rhyhorn
	strcpy(RHYHORN.name, "Rhyhorn");
	RHYHORN.id = 111;
	RHYHORN.type1 = GROUND_T;
	RHYHORN.type2 = ROCK_T;
	RHYHORN.bstats.hp_base = 80;
	RHYHORN.bstats.attack_base = 85;
	RHYHORN.bstats.defense_base = 95;
	RHYHORN.bstats.sattack_base = 30;
	RHYHORN.bstats.sdefense_base = 30;
	RHYHORN.bstats.speed_base = 25;

	// rhydon
	strcpy(RHYDON.name, "Rhydon");
	RHYDON.id = 112;
	RHYDON.type1 = GROUND_T;
	RHYDON.type2 = ROCK_T;
	RHYDON.bstats.hp_base = 105;
	RHYDON.bstats.attack_base = 130;
	RHYDON.bstats.defense_base = 120;
	RHYDON.bstats.sattack_base = 45;
	RHYDON.bstats.sdefense_base = 45;
	RHYDON.bstats.speed_base = 40;

	// chansey
	strcpy(CHANSEY.name, "Chansey");
	CHANSEY.id = 113;
	CHANSEY.type1 = NORMAL_T;
	CHANSEY.type2 = NON_T;
	CHANSEY.bstats.hp_base = 250;
	CHANSEY.bstats.attack_base = 5;
	CHANSEY.bstats.defense_base = 5;
	CHANSEY.bstats.sattack_base = 35;
	CHANSEY.bstats.sdefense_base = 105;
	CHANSEY.bstats.speed_base = 50;

	// tangela
	strcpy(TANGELA.name, "Tangela");
	TANGELA.id = 114;
	TANGELA.type1 = GRASS_T;
	TANGELA.type2 = NON_T;
	TANGELA.bstats.hp_base = 65;
	TANGELA.bstats.attack_base = 55;
	TANGELA.bstats.defense_base = 115;
	TANGELA.bstats.sattack_base = 100;
	TANGELA.bstats.sdefense_base = 40;
	TANGELA.bstats.speed_base = 60;

	// kangaskhan
	strcpy(KANGASKHAN.name, "Kangaskhan");
	KANGASKHAN.id = 115;
	KANGASKHAN.type1 = NORMAL_T;
	KANGASKHAN.type2 = NON_T;
	KANGASKHAN.bstats.hp_base = 105;
	KANGASKHAN.bstats.attack_base = 95;
	KANGASKHAN.bstats.defense_base = 80;
	KANGASKHAN.bstats.sattack_base = 40;
	KANGASKHAN.bstats.sdefense_base = 80;
	KANGASKHAN.bstats.speed_base = 90;

	// horsea
	strcpy(HORSEA.name, "Horsea");
	HORSEA.id = 116;
	HORSEA.type1 = WATER_T;
	HORSEA.type2 = NON_T;
	HORSEA.bstats.hp_base = 30;
	HORSEA.bstats.attack_base = 40;
	HORSEA.bstats.defense_base = 70;
	HORSEA.bstats.sattack_base = 70;
	HORSEA.bstats.sdefense_base = 25;
	HORSEA.bstats.speed_base = 60;

	// seadra
	strcpy(SEADRA.name, "Seadra");
	SEADRA.id = 117;
	SEADRA.type1 = WATER_T;
	SEADRA.type2 = NON_T;
	SEADRA.bstats.hp_base = 55;
	SEADRA.bstats.attack_base = 65;
	SEADRA.bstats.defense_base = 95;
	SEADRA.bstats.sattack_base = 95;
	SEADRA.bstats.sdefense_base = 45;
	SEADRA.bstats.speed_base = 85;

	// goldeen
	strcpy(GOLDEEN.name, "Goldeen");
	GOLDEEN.id = 118;
	GOLDEEN.type1 = WATER_T;
	GOLDEEN.type2 = NON_T;
	GOLDEEN.bstats.hp_base = 45;
	GOLDEEN.bstats.attack_base = 67;
	GOLDEEN.bstats.defense_base = 60;
	GOLDEEN.bstats.sattack_base = 35;
	GOLDEEN.bstats.sdefense_base = 50;
	GOLDEEN.bstats.speed_base = 63;

	// seaking
	strcpy(SEAKING.name, "Seaking");
	SEAKING.id = 119;
	SEAKING.type1 = WATER_T;
	SEAKING.type2 = NON_T;
	SEAKING.bstats.hp_base = 80;
	SEAKING.bstats.attack_base = 92;
	SEAKING.bstats.defense_base = 65;
	SEAKING.bstats.sattack_base = 65;
	SEAKING.bstats.sdefense_base = 80;
	SEAKING.bstats.speed_base = 68;

	// staryu
	strcpy(STARYU.name, "Staryu");
	STARYU.id = 120;
	STARYU.type1 = WATER_T;
	STARYU.type2 = NON_T;
	STARYU.bstats.hp_base = 30;
	STARYU.bstats.attack_base = 45;
	STARYU.bstats.defense_base = 55;
	STARYU.bstats.sattack_base = 70;
	STARYU.bstats.sdefense_base = 55;
	STARYU.bstats.speed_base = 85;

	// starmie
	strcpy(STARMIE.name, "Starmie");
	STARMIE.id = 121;
	STARMIE.type1 = WATER_T;
	STARMIE.type2 = PSYCHIC_T;
	STARMIE.bstats.hp_base = 60;
	STARMIE.bstats.attack_base = 75;
	STARMIE.bstats.defense_base = 85;
	STARMIE.bstats.sattack_base = 100;
	STARMIE.bstats.sdefense_base = 85;
	STARMIE.bstats.speed_base = 115;

	// mr. mime
	strcpy(MRMIME.name, "Mr. Mime");
	MRMIME.id = 122;
	MRMIME.type1 = PSYCHIC_T;
	MRMIME.type2 = NON_T;
	MRMIME.bstats.hp_base = 40;
	MRMIME.bstats.attack_base = 45;
	MRMIME.bstats.defense_base = 65;
	MRMIME.bstats.sattack_base = 100;
	MRMIME.bstats.sdefense_base = 120;
	MRMIME.bstats.speed_base = 90;

	// scyther
	strcpy(SCYTHER.name, "Scyther");
	SCYTHER.id = 123;
	SCYTHER.type1 = BUG_T;
	SCYTHER.type2 = FLYING_T;
	SCYTHER.bstats.hp_base = 70;
	SCYTHER.bstats.attack_base = 110;
	SCYTHER.bstats.defense_base = 80;
	SCYTHER.bstats.sattack_base = 55;
	SCYTHER.bstats.sdefense_base = 80;
	SCYTHER.bstats.speed_base = 105;

	// jynx
	strcpy(JYNX.name, "Jynx");
	JYNX.id = 124;
	JYNX.type1 = ICE_T;
	JYNX.type2 = PSYCHIC_T;
	JYNX.bstats.hp_base = 65;
	JYNX.bstats.attack_base = 50;
	JYNX.bstats.defense_base = 35;
	JYNX.bstats.sattack_base = 115;
	JYNX.bstats.sdefense_base = 95;
	JYNX.bstats.speed_base = 95;

	// electabuzz
	strcpy(ELECTABUZZ.name, "Electabuzz");
	ELECTABUZZ.id = 125;
	ELECTABUZZ.type1 = ELECTRIC_T;
	ELECTABUZZ.type2 = NON_T;
	ELECTABUZZ.bstats.hp_base = 65;
	ELECTABUZZ.bstats.attack_base = 83;
	ELECTABUZZ.bstats.defense_base = 57;
	ELECTABUZZ.bstats.sattack_base = 95;
	ELECTABUZZ.bstats.sdefense_base = 85;
	ELECTABUZZ.bstats.speed_base = 105;

	// magmar
	strcpy(MAGMAR.name, "Magmar");
	MAGMAR.id = 126;
	MAGMAR.type1 = FIRE_T;
	MAGMAR.type2 = NON_T;
	MAGMAR.bstats.hp_base = 65;
	MAGMAR.bstats.attack_base = 95;
	MAGMAR.bstats.defense_base = 57;
	MAGMAR.bstats.sattack_base = 100;
	MAGMAR.bstats.sdefense_base = 85;
	MAGMAR.bstats.speed_base = 93;

	// pinsir
	strcpy(PINSIR.name, "Pinsir");
	PINSIR.id = 127;
	PINSIR.type1 = BUG_T;
	PINSIR.type2 = NON_T;
	PINSIR.bstats.hp_base = 65;
	PINSIR.bstats.attack_base = 125;
	PINSIR.bstats.defense_base = 100;
	PINSIR.bstats.sattack_base = 55;
	PINSIR.bstats.sdefense_base = 70;
	PINSIR.bstats.speed_base = 85;

	// tauros
	strcpy(TAUROS.name, "Tauros");
	TAUROS.id = 128;
	TAUROS.type1 = NORMAL_T;
	TAUROS.type2 = NON_T;
	TAUROS.bstats.hp_base = 75;
	TAUROS.bstats.attack_base = 100;
	TAUROS.bstats.defense_base = 95;
	TAUROS.bstats.sattack_base = 40;
	TAUROS.bstats.sdefense_base = 70;
	TAUROS.bstats.speed_base = 110;

	// magikarp
	strcpy(MAGIKARP.name, "Magikarp");
	MAGIKARP.id = 129;
	MAGIKARP.type1 = WATER_T;
	MAGIKARP.type2 = NON_T;
	MAGIKARP.bstats.hp_base = 20;
	MAGIKARP.bstats.attack_base = 10;
	MAGIKARP.bstats.defense_base = 55;
	MAGIKARP.bstats.sattack_base = 15;
	MAGIKARP.bstats.sdefense_base = 20;
	MAGIKARP.bstats.speed_base = 80;

	// gyarados
	strcpy(GYARADOS.name, "Gyarados");
	GYARADOS.id = 130;
	GYARADOS.type1 = WATER_T;
	GYARADOS.type2 = FLYING_T;
	GYARADOS.bstats.hp_base = 95;
	GYARADOS.bstats.attack_base = 125;
	GYARADOS.bstats.defense_base = 79;
	GYARADOS.bstats.sattack_base = 60;
	GYARADOS.bstats.sdefense_base = 100;
	GYARADOS.bstats.speed_base = 81;

	// lapras
	strcpy(LAPRAS.name, "Lapras");
	LAPRAS.id = 131;
	LAPRAS.type1 = WATER_T;
	LAPRAS.type2 = ICE_T;
	LAPRAS.bstats.hp_base = 130;
	LAPRAS.bstats.attack_base = 85;
	LAPRAS.bstats.defense_base = 80;
	LAPRAS.bstats.sattack_base = 85;
	LAPRAS.bstats.sdefense_base = 95;
	LAPRAS.bstats.speed_base = 60;

	// ditto
	strcpy(DITTO.name, "Ditto");
	DITTO.id = 132;
	DITTO.type1 = NORMAL_T;
	DITTO.type2 = NON_T;
	DITTO.bstats.hp_base = 48;
	DITTO.bstats.attack_base = 48;
	DITTO.bstats.defense_base = 48;
	DITTO.bstats.sattack_base = 48;
	DITTO.bstats.sdefense_base = 48;
	DITTO.bstats.speed_base = 48;

	// eevee
	strcpy(EEVEE.name, "Eevee");
	EEVEE.id = 133;
	EEVEE.type1 = NORMAL_T;
	EEVEE.type2 = NON_T;
	EEVEE.bstats.hp_base = 55;
	EEVEE.bstats.attack_base = 55;
	EEVEE.bstats.defense_base = 50;
	EEVEE.bstats.sattack_base = 45;
	EEVEE.bstats.sdefense_base = 65;
	EEVEE.bstats.speed_base = 55;

	// vaporeon
	strcpy(VAPOREON.name, "Vaporeon");
	VAPOREON.id = 134;
	VAPOREON.type1 = WATER_T;
	VAPOREON.type2 = NON_T;
	VAPOREON.bstats.hp_base = 130;
	VAPOREON.bstats.attack_base = 65;
	VAPOREON.bstats.defense_base = 60;
	VAPOREON.bstats.sattack_base = 110;
	VAPOREON.bstats.sdefense_base = 95;
	VAPOREON.bstats.speed_base = 65;

	// jolteon
	strcpy(JOLTEON.name, "Jolteon");
	JOLTEON.id = 135;
	JOLTEON.type1 = ELECTRIC_T;
	JOLTEON.type2 = NON_T;
	JOLTEON.bstats.hp_base = 65;
	JOLTEON.bstats.attack_base = 65;
	JOLTEON.bstats.defense_base = 60;
	JOLTEON.bstats.sattack_base = 110;
	JOLTEON.bstats.sdefense_base = 95;
	JOLTEON.bstats.speed_base = 130;

	// flareon
	strcpy(FLAREON.name, "Flareon");
	FLAREON.id = 136;
	FLAREON.type1 = FIRE_T;
	FLAREON.type2 = NON_T;
	FLAREON.bstats.hp_base = 65;
	FLAREON.bstats.attack_base = 130;
	FLAREON.bstats.defense_base = 60;
	FLAREON.bstats.sattack_base = 95;
	FLAREON.bstats.sdefense_base = 110;
	FLAREON.bstats.speed_base = 65;

	// porygon
	strcpy(PORYGON.name, "Porygon");
	PORYGON.id = 137;
	PORYGON.type1 = NORMAL_T;
	PORYGON.type2 = NON_T;
	PORYGON.bstats.hp_base = 65;
	PORYGON.bstats.attack_base = 60;
	PORYGON.bstats.defense_base = 70;
	PORYGON.bstats.sattack_base = 85;
	PORYGON.bstats.sdefense_base = 75;
	PORYGON.bstats.speed_base = 40;

	// omanyte
	strcpy(OMANYTE.name, "Omanyte");
	OMANYTE.id = 138;
	OMANYTE.type1 = ROCK_T;
	OMANYTE.type2 = WATER_T;
	OMANYTE.bstats.hp_base = 35;
	OMANYTE.bstats.attack_base = 40;
	OMANYTE.bstats.defense_base = 100;
	OMANYTE.bstats.sattack_base = 90;
	OMANYTE.bstats.sdefense_base = 55;
	OMANYTE.bstats.speed_base = 35;

	// omastar
	strcpy(OMASTAR.name, "Omastar");
	OMASTAR.id = 139;
	OMASTAR.type1 = ROCK_T;
	OMASTAR.type2 = WATER_T;
	OMASTAR.bstats.hp_base = 70;
	OMASTAR.bstats.attack_base = 60;
	OMASTAR.bstats.defense_base = 125;
	OMASTAR.bstats.sattack_base = 115;
	OMASTAR.bstats.sdefense_base = 70;
	OMASTAR.bstats.speed_base = 55;

	// kabuto
	strcpy(KABUTO.name, "Kabuto");
	KABUTO.id = 140;
	KABUTO.type1 = ROCK_T;
	KABUTO.type2 = WATER_T;
	KABUTO.bstats.hp_base = 30;
	KABUTO.bstats.attack_base = 80;
	KABUTO.bstats.defense_base = 90;
	KABUTO.bstats.sattack_base = 55;
	KABUTO.bstats.sdefense_base = 45;
	KABUTO.bstats.speed_base = 55;

	// kabutops
	strcpy(KABUTOPS.name, "Kabutops");
	KABUTOPS.id = 141;
	KABUTOPS.type1 = ROCK_T;
	KABUTOPS.type2 = WATER_T;
	KABUTOPS.bstats.hp_base = 60;
	KABUTOPS.bstats.attack_base = 115;
	KABUTOPS.bstats.defense_base = 105;
	KABUTOPS.bstats.sattack_base = 65;
	KABUTOPS.bstats.sdefense_base = 70;
	KABUTOPS.bstats.speed_base = 80;

	// aerodactyl
	strcpy(AERODACTYL.name, "Aerodactyl");
	AERODACTYL.id = 142;
	AERODACTYL.type1 = ROCK_T;
	AERODACTYL.type2 = FLYING_T;
	AERODACTYL.bstats.hp_base = 80;
	AERODACTYL.bstats.attack_base = 105;
	AERODACTYL.bstats.defense_base = 65;
	AERODACTYL.bstats.sattack_base = 60;
	AERODACTYL.bstats.sdefense_base = 75;
	AERODACTYL.bstats.speed_base = 130;

	// snorlax
	strcpy(SNORLAX.name, "Snorlax");
	SNORLAX.id = 143;
	SNORLAX.type1 = NORMAL_T;
	SNORLAX.type2 = NON_T;
	SNORLAX.bstats.hp_base = 160;
	SNORLAX.bstats.attack_base = 110;
	SNORLAX.bstats.defense_base = 65;
	SNORLAX.bstats.sattack_base = 65;
	SNORLAX.bstats.sdefense_base = 110;
	SNORLAX.bstats.speed_base = 30;

	// articuno
	strcpy(ARTICUNO.name, "Articuno");
	ARTICUNO.id = 144;
	ARTICUNO.type1 = ICE_T;
	ARTICUNO.type2 = FLYING_T;
	ARTICUNO.bstats.hp_base = 90;
	ARTICUNO.bstats.attack_base = 85;
	ARTICUNO.bstats.defense_base = 100;
	ARTICUNO.bstats.sattack_base = 95;
	ARTICUNO.bstats.sdefense_base = 125;
	ARTICUNO.bstats.speed_base = 85;

	// zapdos
	strcpy(ZAPDOS.name, "Zapdos");
	ZAPDOS.id = 145;
	ZAPDOS.type1 = ELECTRIC_T;
	ZAPDOS.type2 = FLYING_T;
	ZAPDOS.bstats.hp_base = 90;
	ZAPDOS.bstats.attack_base = 90;
	ZAPDOS.bstats.defense_base = 85;
	ZAPDOS.bstats.sattack_base = 125;
	ZAPDOS.bstats.sdefense_base = 90;
	ZAPDOS.bstats.speed_base = 100;

	// moltres
	strcpy(MOLTRES.name, "Moltres");
	MOLTRES.id = 146;
	MOLTRES.type1 = FIRE_T;
	MOLTRES.type2 = FLYING_T;
	MOLTRES.bstats.hp_base = 90;
	MOLTRES.bstats.attack_base = 100;
	MOLTRES.bstats.defense_base = 90;
	MOLTRES.bstats.sattack_base = 125;
	MOLTRES.bstats.sdefense_base = 85;
	MOLTRES.bstats.speed_base = 90;

	// dratini
	strcpy(DRATINI.name, "Dratini");
	DRATINI.id = 147;
	DRATINI.type1 = DRAGON_T;
	DRATINI.type2 = NON_T;
	DRATINI.bstats.hp_base = 41;
	DRATINI.bstats.attack_base = 64;
	DRATINI.bstats.defense_base = 45;
	DRATINI.bstats.sattack_base = 50;
	DRATINI.bstats.sdefense_base = 50;
	DRATINI.bstats.speed_base = 50;

	// dragonair
	strcpy(DRAGONAIR.name, "Dragonair");
	DRAGONAIR.id = 148;
	DRAGONAIR.type1 = DRAGON_T;
	DRAGONAIR.type2 = NON_T;
	DRAGONAIR.bstats.hp_base = 61;
	DRAGONAIR.bstats.attack_base = 84;
	DRAGONAIR.bstats.defense_base = 65;
	DRAGONAIR.bstats.sattack_base = 70;
	DRAGONAIR.bstats.sdefense_base = 70;
	DRAGONAIR.bstats.speed_base = 70;

	// dragonite
	strcpy(DRAGONITE.name, "Dragonite");
	DRAGONITE.id = 149;
	DRAGONITE.type1 = DRAGON_T;
	DRAGONITE.type2 = FLYING_T;
	DRAGONITE.bstats.hp_base = 91;
	DRAGONITE.bstats.attack_base = 134;
	DRAGONITE.bstats.defense_base = 95;
	DRAGONITE.bstats.sattack_base = 100;
	DRAGONITE.bstats.sdefense_base = 100;
	DRAGONITE.bstats.speed_base = 80;

	// mewtwo
	strcpy(MEWTWO.name, "Mewtwo");
	MEWTWO.id = 150;
	MEWTWO.type1 = PSYCHIC_T;
	MEWTWO.type2 = NON_T;
	MEWTWO.bstats.hp_base = 106;
	MEWTWO.bstats.attack_base = 110;
	MEWTWO.bstats.defense_base = 90;
	MEWTWO.bstats.sattack_base = 154;
	MEWTWO.bstats.sdefense_base = 90;
	MEWTWO.bstats.speed_base = 130;

	// mewtwo
	strcpy(MEW.name, "Mew");
	MEW.id = 151;
	MEW.type1 = PSYCHIC_T;
	MEW.type2 = NON_T;
	MEW.bstats.hp_base = 100;
	MEW.bstats.attack_base = 100;
	MEW.bstats.defense_base = 100;
	MEW.bstats.sattack_base = 100;
	MEW.bstats.sdefense_base = 100;
	MEW.bstats.speed_base = 100;
}

void init_moves() {
	// absorb
	strcpy(ABSORB.name, "Absorb");
	ABSORB.damage = 20;
	ABSORB.accuracy = 1.0;
	ABSORB.type = GRASS_T;
	ABSORB.movetype = SPECIAL_MT;
	ABSORB.priority = 0;
	ABSORB.unique = 0;
	ABSORB.pp_max = 25;
	ABSORB.effect = RECOIL_E2;
	ABSORB.chance = 1.0;
	ABSORB.m_arg = -2;

	// acid
	strcpy(ACID.name, "Acid");
	ACID.damage = 40;
	ACID.accuracy = 1.0;
	ACID.type = POISON_T;
	ACID.movetype = SPECIAL_MT;
	ACID.priority = 0;
	ACID.unique = 0;
	ACID.pp_max = 30;
	ACID.effect = OTHR_SDEFENSE_E2;
	ACID.chance = 0.1;
	ACID.m_arg = -1;

	// acid armor
	strcpy(ACIDARMOR.name, "Acid Armor");
	ACIDARMOR.damage = 0;
	ACIDARMOR.accuracy = 1.0;
	ACIDARMOR.type = POISON_T;
	ACIDARMOR.movetype = STATUS_MT;
	ACIDARMOR.priority = 0;
	ACIDARMOR.unique = 0;
	ACIDARMOR.pp_max = 20;
	ACIDARMOR.effect = SELF_DEFENSE_E2;
	ACIDARMOR.chance = 1.0;
	ACIDARMOR.m_arg = 2;

	// agility
	strcpy(AGILITY.name, "Agility");
	AGILITY.damage = 0;
	AGILITY.accuracy = 1.0;
	AGILITY.type = PSYCHIC_T;
	AGILITY.movetype = STATUS_MT;
	AGILITY.priority = 0;
	AGILITY.unique = 0;
	AGILITY.pp_max = 30;
	AGILITY.effect = SELF_SPEED_E2;
	AGILITY.chance = 1.0;
	AGILITY.m_arg = 2;

	// amnesia
	strcpy(AMNESIA.name, "Amnesia");
	AMNESIA.damage = 0;
	AMNESIA.accuracy = 1.0;
	AMNESIA.type = PSYCHIC_T;
	AMNESIA.movetype = STATUS_MT;
	AMNESIA.priority = 0;
	AMNESIA.unique = 0;
	AMNESIA.pp_max = 20;
	AMNESIA.effect = SELF_SDEFENSE_E2;
	AMNESIA.chance = 1.0;
	AMNESIA.m_arg = 2;

	// aurora beam
	strcpy(AURORABEAM.name, "Aurora Beam");
	AURORABEAM.damage = 65;
	AURORABEAM.accuracy = 1.0;
	AURORABEAM.type = ICE_T;
	AURORABEAM.movetype = SPECIAL_MT;
	AURORABEAM.priority = 0;
	AURORABEAM.unique = 0;
	AURORABEAM.pp_max = 20;
	AURORABEAM.effect = OTHR_ATTACK_E2;
	AURORABEAM.chance = 0.1;
	AURORABEAM.m_arg = -1;

	// barrier
	strcpy(BARRIER.name, "Barrier");
	BARRIER.damage = 0;
	BARRIER.accuracy = 1.0;
	BARRIER.type = PSYCHIC_T;
	BARRIER.movetype = STATUS_MT;
	BARRIER.priority = 0;
	BARRIER.unique = 0;
	BARRIER.pp_max = 20;
	BARRIER.effect = SELF_DEFENSE_E2;
	BARRIER.chance = 1.0;
	BARRIER.m_arg = 2;

	// bite
	strcpy(BITE.name, "Bite");
	BITE.damage = 60;
	BITE.accuracy = 1.0;
	BITE.type = DARK_T;
	BITE.movetype = PHYSICAL_MT;
	BITE.priority = 0;
	BITE.unique = 0;
	BITE.pp_max = 25;
	BITE.effect = APPLY_FLINCH_E2;
	BITE.chance = 0.3;
	BITE.m_arg = 0;

	// blizzard
	strcpy(BLIZZARD.name, "Blizzard");
	BLIZZARD.damage = 110;
	BLIZZARD.accuracy = 0.7;
	BLIZZARD.type = ICE_T;
	BLIZZARD.movetype = SPECIAL_MT;
	BLIZZARD.priority = 0;
	BLIZZARD.unique = 0;
	BLIZZARD.pp_max = 5;
	BLIZZARD.effect = APPLY_FRZ_E2;
	BLIZZARD.chance = 0.1;
	BLIZZARD.m_arg = 0;

	// body slam
	strcpy(BODYSLAM.name, "Body Slam");
	BODYSLAM.damage = 85;
	BODYSLAM.accuracy = 1.0;
	BODYSLAM.type = NORMAL_T;
	BODYSLAM.movetype = PHYSICAL_MT;
	BODYSLAM.priority = 0;
	BODYSLAM.unique = 0;
	BODYSLAM.pp_max = 15;
	BODYSLAM.effect = APPLY_PAR_E2;
	BODYSLAM.chance = 0.3;
	BODYSLAM.m_arg = 0;

	// bone club
	strcpy(BONECLUB.name, "Bone Club");
	BONECLUB.damage = 65;
	BONECLUB.accuracy = 0.85;
	BONECLUB.type = GROUND_T;
	BONECLUB.movetype = PHYSICAL_MT;
	BONECLUB.priority = 0;
	BONECLUB.unique = 0;
	BONECLUB.pp_max = 20;
	BONECLUB.effect = APPLY_FLINCH_E2;
	BONECLUB.chance = 0.1;
	BONECLUB.m_arg = 0;

	// bubble
	strcpy(BUBBLE.name, "Bubble");
	BUBBLE.damage = 40;
	BUBBLE.accuracy = 1.0;
	BUBBLE.type = WATER_T;
	BUBBLE.movetype = SPECIAL_MT;
	BUBBLE.priority = 0;
	BUBBLE.unique = 0;
	BUBBLE.pp_max = 30;
	BUBBLE.effect = OTHR_SPEED_E2;
	BUBBLE.chance = 0.1;
	BUBBLE.m_arg = -1;

	// bubble beam
	strcpy(BUBBLEBEAM.name, "Bubble Beam");
	BUBBLEBEAM.damage = 65;
	BUBBLEBEAM.accuracy = 1.0;
	BUBBLEBEAM.type = WATER_T;
	BUBBLEBEAM.movetype = SPECIAL_MT;
	BUBBLEBEAM.priority = 0;
	BUBBLEBEAM.unique = 0;
	BUBBLEBEAM.pp_max = 20;
	BUBBLEBEAM.effect = OTHR_SPEED_E2;
	BUBBLEBEAM.chance = 0.1;
	BUBBLEBEAM.m_arg = -1;

	// confuse ray
	strcpy(CONFUSERAY.name, "Confuse Ray");
	CONFUSERAY.damage = 0;
	CONFUSERAY.accuracy = 1.0;
	CONFUSERAY.type = GHOST_T;
	CONFUSERAY.movetype = STATUS_MT;
	CONFUSERAY.priority = 0;
	CONFUSERAY.unique = 0;
	CONFUSERAY.pp_max = 10;
	CONFUSERAY.effect = APPLY_CONFUSE_E2;
	CONFUSERAY.chance = 1.0;
	CONFUSERAY.m_arg = 0;

	// confusion
	strcpy(CONFUSION.name, "Confusion");
	CONFUSION.damage = 50;
	CONFUSION.accuracy = 1.0;
	CONFUSION.type = PSYCHIC_T;
	CONFUSION.movetype = SPECIAL_MT;
	CONFUSION.priority = 0;
	CONFUSION.unique = 0;
	CONFUSION.pp_max = 25;
	CONFUSION.effect = APPLY_CONFUSE_E2;
	CONFUSION.chance = 0.1;
	CONFUSION.m_arg = 0;

	// constrict
	strcpy(CONSTRICT.name, "Constrict");
	CONSTRICT.damage = 10;
	CONSTRICT.accuracy = 1.0;
	CONSTRICT.type = NORMAL_T;
	CONSTRICT.movetype = PHYSICAL_MT;
	CONSTRICT.priority = 0;
	CONSTRICT.unique = 0;
	CONSTRICT.pp_max = 35;
	CONSTRICT.effect = OTHR_SPEED_E2;
	CONSTRICT.chance = 0.1;
	CONSTRICT.m_arg = -1;

	// crabhammer
	strcpy(CRABHAMMER.name, "Crabhammer");
	CRABHAMMER.damage = 100;
	CRABHAMMER.accuracy = 0.9;
	CRABHAMMER.type = WATER_T;
	CRABHAMMER.movetype = PHYSICAL_MT;
	CRABHAMMER.priority = 0;
	CRABHAMMER.unique = 0;
	CRABHAMMER.pp_max = 10;
	CRABHAMMER.effect = HIGH_CRIT_E2;
	CRABHAMMER.chance = 1.0;
	CRABHAMMER.m_arg = 0;

	// cut
	strcpy(CUT.name, "Cut");
	CUT.damage = 50;
	CUT.accuracy = 0.95;
	CUT.type = NORMAL_T;
	CUT.movetype = PHYSICAL_MT;
	CUT.priority = 0;
	CUT.unique = 0;
	CUT.pp_max = 30;
	CUT.effect = NON_E2;
	CUT.chance = 1.0;
	CUT.m_arg = 0;

	// defense curl
	strcpy(DEFENSECURL.name, "Defense Curl");
	DEFENSECURL.damage = 0;
	DEFENSECURL.accuracy = 1.0;
	DEFENSECURL.type = NORMAL_T;
	DEFENSECURL.movetype = STATUS_MT;
	DEFENSECURL.priority = 0;
	DEFENSECURL.unique = 0;
	DEFENSECURL.pp_max = 40;
	DEFENSECURL.effect = SELF_DEFENSE_E2;
	DEFENSECURL.chance = 1.0;
	DEFENSECURL.m_arg = 1;

	// dizzy punch
	strcpy(DIZZYPUNCH.name, "Dizzy Punch");
	DIZZYPUNCH.damage = 70;
	DIZZYPUNCH.accuracy = 1.0;
	DIZZYPUNCH.type = NORMAL_T;
	DIZZYPUNCH.movetype = PHYSICAL_MT;
	DIZZYPUNCH.priority = 0;
	DIZZYPUNCH.unique = 0;
	DIZZYPUNCH.pp_max = 10;
	DIZZYPUNCH.effect = APPLY_CONFUSE_E2;
	DIZZYPUNCH.chance = 0.2;
	DIZZYPUNCH.m_arg = 0;

	// double team
	strcpy(DOUBLETEAM.name, "Double Team");
	DOUBLETEAM.damage = 0;
	DOUBLETEAM.accuracy = 1.0;
	DOUBLETEAM.type = NORMAL_T;
	DOUBLETEAM.movetype = STATUS_MT;
	DOUBLETEAM.priority = 0;
	DOUBLETEAM.unique = 0;
	DOUBLETEAM.pp_max = 15;
	DOUBLETEAM.effect = SELF_EVASION_E2;
	DOUBLETEAM.chance = 1.0;
	DOUBLETEAM.m_arg = 1;

	// double-edge
	strcpy(DOUBLEEDGE.name, "Double-Edge");
	DOUBLEEDGE.damage = 120;
	DOUBLEEDGE.accuracy = 1.0;
	DOUBLEEDGE.type = NORMAL_T;
	DOUBLEEDGE.movetype = PHYSICAL_MT;
	DOUBLEEDGE.priority = 0;
	DOUBLEEDGE.unique = 0;
	DOUBLEEDGE.pp_max = 15;
	DOUBLEEDGE.effect = RECOIL_E2;
	DOUBLEEDGE.chance = 1.0;
	DOUBLEEDGE.m_arg = 3;

	// drill peck
	strcpy(DRILLPECK.name, "Drill Peck");
	DRILLPECK.damage = 80;
	DRILLPECK.accuracy = 1.0;
	DRILLPECK.type = FLYING_T;
	DRILLPECK.movetype = PHYSICAL_MT;
	DRILLPECK.priority = 0;
	DRILLPECK.unique = 0;
	DRILLPECK.pp_max = 20;
	DRILLPECK.effect = NON_E2;
	DRILLPECK.chance = 1.0;
	DRILLPECK.m_arg = 0;

	// earthquake
	strcpy(EARTHQUAKE.name, "Earthquake");
	EARTHQUAKE.damage = 100;
	EARTHQUAKE.accuracy = 1.0;
	EARTHQUAKE.type = GROUND_T;
	EARTHQUAKE.movetype = PHYSICAL_MT;
	EARTHQUAKE.priority = 0;
	EARTHQUAKE.unique = 0;
	EARTHQUAKE.pp_max = 10;
	EARTHQUAKE.effect = NON_E2;
	EARTHQUAKE.chance = 1.0;
	EARTHQUAKE.m_arg = 0;

	// egg bomb
	strcpy(EGGBOMB.name, "Egg Bomb");
	EGGBOMB.damage = 100;
	EGGBOMB.accuracy = 0.75;
	EGGBOMB.type = NORMAL_T;
	EGGBOMB.movetype = PHYSICAL_MT;
	EGGBOMB.priority = 0;
	EGGBOMB.unique = 0;
	EGGBOMB.pp_max = 10;
	EGGBOMB.effect = NON_E2;
	EGGBOMB.chance = 1.0;
	EGGBOMB.m_arg = 0;

	// ember
	strcpy(EMBER.name, "Ember");
	EMBER.damage = 40;
	EMBER.accuracy = 1.0;
	EMBER.type = FIRE_T;
	EMBER.movetype = SPECIAL_MT;
	EMBER.priority = 0;
	EMBER.unique = 0;
	EMBER.pp_max = 25;
	EMBER.effect = APPLY_BRN_E2;
	EMBER.chance = 0.1;
	EMBER.m_arg = 0;

	// explosion
	strcpy(EXPLOSION.name, "Explosion");
	EXPLOSION.damage = 250;
	EXPLOSION.accuracy = 1.0;
	EXPLOSION.type = NORMAL_T;
	EXPLOSION.movetype = PHYSICAL_MT;
	EXPLOSION.priority = 0;
	EXPLOSION.unique = 0;
	EXPLOSION.pp_max = 5;
	EXPLOSION.effect = SELF_KILL_E2;
	EXPLOSION.chance = 1.0;
	EXPLOSION.m_arg = 0;

	// fire blast
	strcpy(FIREBLAST.name, "Fire Blast");
	FIREBLAST.damage = 110;
	FIREBLAST.accuracy = 0.85;
	FIREBLAST.type = FIRE_T;
	FIREBLAST.movetype = SPECIAL_MT;
	FIREBLAST.priority = 0;
	FIREBLAST.unique = 0;
	FIREBLAST.pp_max = 5;
	FIREBLAST.effect = APPLY_BRN_E2;
	FIREBLAST.chance = 0.1;
	FIREBLAST.m_arg = 0;

	// fire punch
	strcpy(FIREPUNCH.name, "Fire Punch");
	FIREPUNCH.damage = 75;
	FIREPUNCH.accuracy = 1.0;
	FIREPUNCH.type = FIRE_T;
	FIREPUNCH.movetype = PHYSICAL_MT;
	FIREPUNCH.priority = 0;
	FIREPUNCH.unique = 0;
	FIREPUNCH.pp_max = 15;
	FIREPUNCH.effect = APPLY_BRN_E2;
	FIREPUNCH.chance = 0.1;
	FIREPUNCH.m_arg = 0;

	// fissure
	strcpy(FISSURE.name, "Fissure");
	FISSURE.damage = 100000;
	FISSURE.accuracy = 1.0;
	FISSURE.type = GROUND_T;
	FISSURE.movetype = PHYSICAL_MT;
	FISSURE.priority = 0;
	FISSURE.unique = 0;
	FISSURE.pp_max = 5;
	FISSURE.effect = NON_E2;
	FISSURE.chance = 1.0;
	FISSURE.m_arg = 0;

	// flamethrower
	strcpy(FLAMETHROWER.name, "Flamethrower");
	FLAMETHROWER.damage = 90;
	FLAMETHROWER.accuracy = 1.0;
	FLAMETHROWER.type = FIRE_T;
	FLAMETHROWER.movetype = SPECIAL_MT;
	FLAMETHROWER.priority = 0;
	FLAMETHROWER.unique = 0;
	FLAMETHROWER.pp_max = 15;
	FLAMETHROWER.effect = APPLY_BRN_E2;
	FLAMETHROWER.chance = 0.1;
	FLAMETHROWER.m_arg = 0;

	// flash
	strcpy(FLASH.name, "Flash");
	FLASH.damage = 0;
	FLASH.accuracy = 1.0;
	FLASH.type = NORMAL_T;
	FLASH.movetype = STATUS_MT;
	FLASH.priority = 0;
	FLASH.unique = 0;
	FLASH.pp_max = 20;
	FLASH.effect = OTHR_ACCURACY_E2;
	FLASH.chance = 1.0;
	FLASH.m_arg = -1;

	// glare
	strcpy(GLARE.name, "Glare");
	GLARE.damage = 0;
	GLARE.accuracy = 1.0;
	GLARE.type = NORMAL_T;
	GLARE.movetype = STATUS_MT;
	GLARE.priority = 0;
	GLARE.unique = 0;
	GLARE.pp_max = 30;
	GLARE.effect = APPLY_PAR_E2;
	GLARE.chance = 1.0;
	GLARE.m_arg = 0;

	// growl
	strcpy(GROWL.name, "Growl");
	GROWL.damage = 0;
	GROWL.accuracy = 1.0;
	GROWL.type = NORMAL_T;
	GROWL.movetype = STATUS_MT;
	GROWL.priority = 0;
	GROWL.unique = 0;
	GROWL.pp_max = 40;
	GROWL.effect = OTHR_ATTACK_E2;
	GROWL.chance = 1.0;
	GROWL.m_arg = -1;

	// growth
	strcpy(GROWTH.name, "Growth");
	GROWTH.damage = 0;
	GROWTH.accuracy = 1.0;
	GROWTH.type = NORMAL_T;
	GROWTH.movetype = STATUS_MT;
	GROWTH.priority = 0;
	GROWTH.unique = 0;
	GROWTH.pp_max = 40;
	GROWTH.effect = SELF_ATTACK_SATTACK_E2;
	GROWTH.chance = 1.0;
	GROWTH.m_arg = 1;

	// guillotine
	strcpy(GUILLOTINE.name, "Guillotine");
	GUILLOTINE.damage = 10000;
	GUILLOTINE.accuracy = 1.0;
	GUILLOTINE.type = NORMAL_T;
	GUILLOTINE.movetype = PHYSICAL_MT;
	GUILLOTINE.priority = 0;
	GUILLOTINE.unique = 0;
	GUILLOTINE.pp_max = 5;
	GUILLOTINE.effect = NON_E2;
	GUILLOTINE.chance = 1.0;
	GUILLOTINE.m_arg = 0;

	// gust
	strcpy(GUST.name, "Gust");
	GUST.damage = 40;
	GUST.accuracy = 1.0;
	GUST.type = FLYING_T;
	GUST.movetype = SPECIAL_MT;
	GUST.priority = 0;
	GUST.unique = 0;
	GUST.pp_max = 35;
	GUST.effect = NON_E2;
	GUST.chance = 1.0;
	GUST.m_arg = 0;

	// harden
	strcpy(HARDEN.name, "Harden");
	HARDEN.damage = 0;
	HARDEN.accuracy = 1.0;
	HARDEN.type = NORMAL_T;
	HARDEN.movetype = STATUS_MT;
	HARDEN.priority = 0;
	HARDEN.unique = 0;
	HARDEN.pp_max = 30;
	HARDEN.effect = SELF_DEFENSE_E2;
	HARDEN.chance = 1.0;
	HARDEN.m_arg = 1;

	// haze
	strcpy(HAZE.name, "Haze");
	HAZE.damage = 0;
	HAZE.accuracy = 1.0;
	HAZE.type = ICE_T;
	HAZE.movetype = STATUS_MT;
	HAZE.priority = 0;
	HAZE.unique = 0;
	HAZE.pp_max = 30;
	HAZE.effect = HAZE_E2;
	HAZE.chance = 1.0;
	HAZE.m_arg = 0;

	// headbutt
	strcpy(HEADBUTT.name, "Headbutt");
	HEADBUTT.damage = 70;
	HEADBUTT.accuracy = 1.0;
	HEADBUTT.type = NORMAL_T;
	HEADBUTT.movetype = PHYSICAL_MT;
	HEADBUTT.priority = 0;
	HEADBUTT.unique = 0;
	HEADBUTT.pp_max = 15;
	HEADBUTT.effect = APPLY_FLINCH_E2;
	HEADBUTT.chance = 0.3;
	HEADBUTT.m_arg = 0;

	// horn attack
	strcpy(HORNATTACK.name, "Horn Attack");
	HORNATTACK.damage = 65;
	HORNATTACK.accuracy = 1.0;
	HORNATTACK.type = NORMAL_T;
	HORNATTACK.movetype = PHYSICAL_MT;
	HORNATTACK.priority = 0;
	HORNATTACK.unique = 0;
	HORNATTACK.pp_max = 25;
	HORNATTACK.effect = NON_E2;
	HORNATTACK.chance = 1.0;
	HORNATTACK.m_arg = 0;

	// horn drill
	strcpy(HORNDRILL.name, "Horn Drill");
	HORNDRILL.damage = 10000;
	HORNDRILL.accuracy = 0.3;
	HORNDRILL.type = NORMAL_T;
	HORNDRILL.movetype = PHYSICAL_MT;
	HORNDRILL.priority = 0;
	HORNDRILL.unique = 0;
	HORNDRILL.pp_max = 5;
	HORNDRILL.effect = NON_E2;
	HORNDRILL.chance = 1.0;
	HORNDRILL.m_arg = 0;

	// hydro pump
	strcpy(HYDROPUMP.name, "Hydro Pump");
	HYDROPUMP.damage = 110;
	HYDROPUMP.accuracy = 0.8;
	HYDROPUMP.type = WATER_T;
	HYDROPUMP.movetype = SPECIAL_MT;
	HYDROPUMP.priority = 0;
	HYDROPUMP.unique = 0;
	HYDROPUMP.pp_max = 5;
	HYDROPUMP.effect = NON_E2;
	HYDROPUMP.chance = 1.0;
	HYDROPUMP.m_arg = 0;

	// hyper beam
	strcpy(HYPERBEAM.name, "Hyper Beam");
	HYPERBEAM.damage = 150;
	HYPERBEAM.accuracy = 0.9;
	HYPERBEAM.type = NORMAL_T;
	HYPERBEAM.movetype = SPECIAL_MT;
	HYPERBEAM.priority = 0;
	HYPERBEAM.unique = 0;
	HYPERBEAM.pp_max = 5;
	HYPERBEAM.effect = RECHARGE_E2;
	HYPERBEAM.chance = 1.0;
	HYPERBEAM.m_arg = 0;

	// hyper fang
	strcpy(HYPERFANG.name, "Hyper Fang");
	HYPERFANG.damage = 80;
	HYPERFANG.accuracy = 0.9;
	HYPERFANG.type = NORMAL_T;
	HYPERFANG.movetype = PHYSICAL_MT;
	HYPERFANG.priority = 0;
	HYPERFANG.unique = 0;
	HYPERFANG.pp_max = 15;
	HYPERFANG.effect = APPLY_FLINCH_E2;
	HYPERFANG.chance = 0.1;
	HYPERFANG.m_arg = 0;

	// hypnosis
	strcpy(HYPNOSIS.name, "Hypnosis");
	HYPNOSIS.damage = 0;
	HYPNOSIS.accuracy = 0.6;
	HYPNOSIS.type = PSYCHIC_T;
	HYPNOSIS.movetype = STATUS_MT;
	HYPNOSIS.priority = 0;
	HYPNOSIS.unique = 0;
	HYPNOSIS.pp_max = 20;
	HYPNOSIS.effect = APPLY_SLP_E2;
	HYPNOSIS.chance = 1.0;
	HYPNOSIS.m_arg = 0;

	// ice beam
	strcpy(ICEBEAM.name, "Ice Beam");
	ICEBEAM.damage = 90;
	ICEBEAM.accuracy = 1.0;
	ICEBEAM.type = ICE_T;
	ICEBEAM.movetype = SPECIAL_MT;
	ICEBEAM.priority = 0;
	ICEBEAM.unique = 0;
	ICEBEAM.pp_max = 10;
	ICEBEAM.effect = APPLY_FRZ_E2;
	ICEBEAM.chance = 0.1;
	ICEBEAM.m_arg = 0;

	// ice punch
	strcpy(ICEPUNCH.name, "Ice Punch");
	ICEPUNCH.damage = 75;
	ICEPUNCH.accuracy = 1.0;
	ICEPUNCH.type = ICE_T;
	ICEPUNCH.movetype = PHYSICAL_MT;
	ICEPUNCH.priority = 0;
	ICEPUNCH.unique = 0;
	ICEPUNCH.pp_max = 15;
	ICEPUNCH.effect = APPLY_FRZ_E2;
	ICEPUNCH.chance = 0.1;
	ICEPUNCH.m_arg = 0;

	// karate chop
	strcpy(KARATECHOP.name, "Karate Chop");
	KARATECHOP.damage = 50;
	KARATECHOP.accuracy = 1.0;
	KARATECHOP.type = FIGHTING_T;
	KARATECHOP.movetype = PHYSICAL_MT;
	KARATECHOP.priority = 0;
	KARATECHOP.unique = 0;
	KARATECHOP.pp_max = 25;
	KARATECHOP.effect = HIGH_CRIT_E2;
	KARATECHOP.chance = 1.0;
	KARATECHOP.m_arg = 0;

	// kinesis
	strcpy(KINESIS.name, "Kinesis");
	KINESIS.damage = 0;
	KINESIS.accuracy = 0.8;
	KINESIS.type = PSYCHIC_T;
	KINESIS.movetype = STATUS_MT;
	KINESIS.priority = 0;
	KINESIS.unique = 0;
	KINESIS.pp_max = 15;
	KINESIS.effect = OTHR_ACCURACY_E2;
	KINESIS.chance = 1.0;
	KINESIS.m_arg = -1;

	// leech life
	strcpy(LEECHLIFE.name, "Leech Life");
	LEECHLIFE.damage = 20;
	LEECHLIFE.accuracy = 1.0;
	LEECHLIFE.type = BUG_T;
	LEECHLIFE.movetype = PHYSICAL_MT;
	LEECHLIFE.priority = 0;
	LEECHLIFE.unique = 0;
	LEECHLIFE.pp_max = 15;
	LEECHLIFE.effect = RECOIL_E2;
	LEECHLIFE.chance = 1.0;
	LEECHLIFE.m_arg = -2;

	// leer
	strcpy(LEER.name, "Leer");
	LEER.damage = 0;
	LEER.accuracy = 1.0;
	LEER.type = NORMAL_T;
	LEER.movetype = STATUS_MT;
	LEER.priority = 0;
	LEER.unique = 0;
	LEER.pp_max = 30;
	LEER.effect = OTHR_DEFENSE_E2;
	LEER.chance = 1.0;
	LEER.m_arg = -1;

	// lick
	strcpy(LICK.name, "Lick");
	LICK.damage = 30;
	LICK.accuracy = 1.0;
	LICK.type = GHOST_T;
	LICK.movetype = PHYSICAL_MT;
	LICK.priority = 0;
	LICK.unique = 0;
	LICK.pp_max = 30;
	LICK.effect = APPLY_PAR_E2;
	LICK.chance = 0.3;
	LICK.m_arg = 0;

	// lovely kiss
	strcpy(LOVELYKISS.name, "Lovely Kiss");
	LOVELYKISS.damage = 0;
	LOVELYKISS.accuracy = 0.75;
	LOVELYKISS.type = NORMAL_T;
	LOVELYKISS.movetype = STATUS_MT;
	LOVELYKISS.priority = 0;
	LOVELYKISS.unique = 0;
	LOVELYKISS.pp_max = 10;
	LOVELYKISS.effect = APPLY_SLP_E2;
	LOVELYKISS.chance = 1.0;
	LOVELYKISS.m_arg = 0;

	// meditate
	strcpy(MEDITATE.name, "Meditate");
	MEDITATE.damage = 0;
	MEDITATE.accuracy = 1.0;
	MEDITATE.type = PSYCHIC_T;
	MEDITATE.movetype = STATUS_MT;
	MEDITATE.priority = 0;
	MEDITATE.unique = 0;
	MEDITATE.pp_max = 40;
	MEDITATE.effect = SELF_ATTACK_E2;
	MEDITATE.chance = 1.0;
	MEDITATE.m_arg = 1;

	// mega drain
	strcpy(MEGADRAIN.name, "Mega Drain");
	MEGADRAIN.damage = 40;
	MEGADRAIN.accuracy = 1.0;
	MEGADRAIN.type = GRASS_T;
	MEGADRAIN.movetype = SPECIAL_MT;
	MEGADRAIN.priority = 0;
	MEGADRAIN.unique = 0;
	MEGADRAIN.pp_max = 15;
	MEGADRAIN.effect = RECOIL_E2;
	MEGADRAIN.chance = 1.0;
	MEGADRAIN.m_arg = -2;

	// mega kick
	strcpy(MEGAKICK.name, "Mega Kick");
	MEGAKICK.damage = 120;
	MEGAKICK.accuracy = 0.75;
	MEGAKICK.type = NORMAL_T;
	MEGAKICK.movetype = PHYSICAL_MT;
	MEGAKICK.priority = 0;
	MEGAKICK.unique = 0;
	MEGAKICK.pp_max = 5;
	MEGAKICK.effect = NON_E2;
	MEGAKICK.chance = 1.0;
	MEGAKICK.m_arg = 0;

	// mega punch
	strcpy(MEGAPUNCH.name, "Mega Punch");
	MEGAPUNCH.damage = 80;
	MEGAPUNCH.accuracy = 0.85;
	MEGAPUNCH.type = NORMAL_T;
	MEGAPUNCH.movetype = PHYSICAL_MT;
	MEGAPUNCH.priority = 0;
	MEGAPUNCH.unique = 0;
	MEGAPUNCH.pp_max = 20;
	MEGAPUNCH.effect = NON_E2;
	MEGAPUNCH.chance = 1.0;
	MEGAPUNCH.m_arg = 0;

	// minimize
	strcpy(MINIMIZE.name, "Minimize");
	MINIMIZE.damage = 0;
	MINIMIZE.accuracy = 1.0;
	MINIMIZE.type = NORMAL_T;
	MINIMIZE.movetype = STATUS_MT;
	MINIMIZE.priority = 0;
	MINIMIZE.unique = 0;
	MINIMIZE.pp_max = 10;
	MINIMIZE.effect = SELF_EVASION_E2;
	MINIMIZE.chance = 1.0;
	MINIMIZE.m_arg = 2;

	// pay day
	strcpy(PAYDAY.name, "Pay Day");
	PAYDAY.damage = 40;
	PAYDAY.accuracy = 1.0;
	PAYDAY.type = NORMAL_T;
	PAYDAY.movetype = PHYSICAL_MT;
	PAYDAY.priority = 0;
	PAYDAY.unique = 0;
	PAYDAY.pp_max = 20;
	PAYDAY.effect = NON_E2;
	PAYDAY.chance = 1.0;
	PAYDAY.m_arg = 0;

	// peck
	strcpy(PECK.name, "Peck");
	PECK.damage = 35;
	PECK.accuracy = 1.0;
	PECK.type = FLYING_T;
	PECK.movetype = PHYSICAL_MT;
	PECK.priority = 0;
	PECK.unique = 0;
	PECK.pp_max = 35;
	PECK.effect = NON_E2;
	PECK.chance = 1.0;
	PECK.m_arg = 0;

	// pin missile
	strcpy(PINMISSILE.name, "Pin Missile");
	PINMISSILE.damage = 25;
	PINMISSILE.accuracy = 0.85;
	PINMISSILE.type = BUG_T;
	PINMISSILE.movetype = PHYSICAL_MT;
	PINMISSILE.priority = 0;
	PINMISSILE.unique = 0;
	PINMISSILE.pp_max = 20;
	PINMISSILE.effect = NON_E2;
	PINMISSILE.chance = 1.0;
	PINMISSILE.m_arg = 0;

	// poison gas
	strcpy(POISONGAS.name, "Poison Gas");
	POISONGAS.damage = 0;
	POISONGAS.accuracy = 0.9;
	POISONGAS.type = POISON_T;
	POISONGAS.movetype = STATUS_MT;
	POISONGAS.priority = 0;
	POISONGAS.unique = 0;
	POISONGAS.pp_max = 40;
	POISONGAS.effect = APPLY_PSN_E2;
	POISONGAS.chance = 1.0;
	POISONGAS.m_arg = 0;

	// poison powder
	strcpy(POISONPOWDER.name, "PoisonPowder");
	POISONPOWDER.damage = 0;
	POISONPOWDER.accuracy = 0.75;
	POISONPOWDER.type = POISON_T;
	POISONPOWDER.movetype = STATUS_MT;
	POISONPOWDER.priority = 0;
	POISONPOWDER.unique = 0;
	POISONPOWDER.pp_max = 35;
	POISONPOWDER.effect = APPLY_PSN_E2;
	POISONPOWDER.chance = 1.0;
	POISONPOWDER.m_arg = 0;

	// poison sting
	strcpy(POISONSTING.name, "Poison Sting");
	POISONSTING.damage = 15;
	POISONSTING.accuracy = 1.0;
	POISONSTING.type = POISON_T;
	POISONSTING.movetype = PHYSICAL_MT;
	POISONSTING.priority = 0;
	POISONSTING.unique = 0;
	POISONSTING.pp_max = 35;
	POISONSTING.effect = APPLY_PSN_E2;
	POISONSTING.chance = 0.3;
	POISONSTING.m_arg = 0;

	// pound
	strcpy(POUND.name, "Pound");
	POUND.damage = 40;
	POUND.accuracy = 1.0;
	POUND.type = NORMAL_T;
	POUND.movetype = PHYSICAL_MT;
	POUND.priority = 0;
	POUND.unique = 0;
	POUND.pp_max = 35;
	POUND.effect = NON_E2;
	POUND.chance = 1.0;
	POUND.m_arg = 0;

	// psybeam
	strcpy(PSYBEAM.name, "Psybeam");
	PSYBEAM.damage = 65;
	PSYBEAM.accuracy = 1.0;
	PSYBEAM.type = PSYCHIC_T;
	PSYBEAM.movetype = SPECIAL_MT;
	PSYBEAM.priority = 0;
	PSYBEAM.unique = 0;
	PSYBEAM.pp_max = 20;
	PSYBEAM.effect = APPLY_CONFUSE_E2;
	PSYBEAM.chance = 0.1;
	PSYBEAM.m_arg = 0;

	// psychic
	strcpy(PSYCHIC.name, "Psychic");
	PSYCHIC.damage = 90;
	PSYCHIC.accuracy = 1.0;
	PSYCHIC.type = PSYCHIC_T;
	PSYCHIC.movetype = SPECIAL_MT;
	PSYCHIC.priority = 0;
	PSYCHIC.unique = 0;
	PSYCHIC.pp_max = 10;
	PSYCHIC.effect = OTHR_SDEFENSE_E2;
	PSYCHIC.chance = 0.1;
	PSYCHIC.m_arg = -1;

	// quick attack
	strcpy(QUICKATTACK.name, "Quick Attack");
	QUICKATTACK.damage = 40;
	QUICKATTACK.accuracy = 1.0;
	QUICKATTACK.type = NORMAL_T;
	QUICKATTACK.movetype = PHYSICAL_MT;
	QUICKATTACK.priority = 1;
	QUICKATTACK.unique = 0;
	QUICKATTACK.pp_max = 30;
	QUICKATTACK.effect = NON_E2;
	QUICKATTACK.chance = 1.0;
	QUICKATTACK.m_arg = 0;

	// razor leaf
	strcpy(RAZORLEAF.name, "Razor Leaf");
	RAZORLEAF.damage = 55;
	RAZORLEAF.accuracy = 0.95;
	RAZORLEAF.type = GRASS_T;
	RAZORLEAF.movetype = PHYSICAL_MT;
	RAZORLEAF.priority = 0;
	RAZORLEAF.unique = 0;
	RAZORLEAF.pp_max = 25;
	RAZORLEAF.effect = HIGH_CRIT_E2;
	RAZORLEAF.chance = 1.0;
	RAZORLEAF.m_arg = 0;

	// rock slide
	strcpy(ROCKSLIDE.name, "Rock Slide");
	ROCKSLIDE.damage = 75;
	ROCKSLIDE.accuracy = 0.9;
	ROCKSLIDE.type = ROCK_T;
	ROCKSLIDE.movetype = PHYSICAL_MT;
	ROCKSLIDE.priority = 0;
	ROCKSLIDE.unique = 0;
	ROCKSLIDE.pp_max = 10;
	ROCKSLIDE.effect = APPLY_FLINCH_E2;
	ROCKSLIDE.chance = 0.3;
	ROCKSLIDE.m_arg = 0;

	// rock throw
	strcpy(ROCKTHROW.name, "Rock Throw");
	ROCKTHROW.damage = 50;
	ROCKTHROW.accuracy = 0.9;
	ROCKTHROW.type = ROCK_T;
	ROCKTHROW.movetype = PHYSICAL_MT;
	ROCKTHROW.priority = 0;
	ROCKTHROW.unique = 0;
	ROCKTHROW.pp_max = 15;
	ROCKTHROW.effect = NON_E2;
	ROCKTHROW.chance = 1.0;
	ROCKTHROW.m_arg = 0;

	// rolling kick
	strcpy(ROLLINGKICK.name, "Rolling Kick");
	ROLLINGKICK.damage = 60;
	ROLLINGKICK.accuracy = 0.85;
	ROLLINGKICK.type = FIGHTING_T;
	ROLLINGKICK.movetype = PHYSICAL_MT;
	ROLLINGKICK.priority = 0;
	ROLLINGKICK.unique = 0;
	ROLLINGKICK.pp_max = 15;
	ROLLINGKICK.effect = APPLY_FLINCH_E2;
	ROLLINGKICK.chance = 0.3;
	ROLLINGKICK.m_arg = 0;

	// sand attack
	strcpy(SANDATTACK.name, "Sand Attack");
	SANDATTACK.damage = 0;
	SANDATTACK.accuracy = 1.0;
	SANDATTACK.type = GROUND_T;
	SANDATTACK.movetype = STATUS_MT;
	SANDATTACK.priority = 0;
	SANDATTACK.unique = 0;
	SANDATTACK.pp_max = 15;
	SANDATTACK.effect = OTHR_ACCURACY_E2;
	SANDATTACK.chance = 1.0;
	SANDATTACK.m_arg = -1;

	// scratch
	strcpy(SCRATCH.name, "Scratch");
	SCRATCH.damage = 40;
	SCRATCH.accuracy = 1.0;
	SCRATCH.type = NORMAL_T;
	SCRATCH.movetype = PHYSICAL_MT;
	SCRATCH.priority = 0;
	SCRATCH.unique = 0;
	SCRATCH.pp_max = 35;
	SCRATCH.effect = NON_E2;
	SCRATCH.chance = 1.0;
	SCRATCH.m_arg = 0;

	// screech
	strcpy(SCREECH.name, "Screech");
	SCREECH.damage = 0;
	SCREECH.accuracy = 0.85;
	SCREECH.type = NORMAL_T;
	SCREECH.movetype = STATUS_MT;
	SCREECH.priority = 0;
	SCREECH.unique = 0;
	SCREECH.pp_max = 40;
	SCREECH.effect = OTHR_DEFENSE_E2;
	SCREECH.chance = 1.0;
	SCREECH.m_arg = -2;

	// self-destruct
	strcpy(SELFDESTRUCT.name, "SelfDestruct");
	SELFDESTRUCT.damage = 200;
	SELFDESTRUCT.accuracy = 1.0;
	SELFDESTRUCT.type = NORMAL_T;
	SELFDESTRUCT.movetype = PHYSICAL_MT;
	SELFDESTRUCT.priority = 0;
	SELFDESTRUCT.unique = 0;
	SELFDESTRUCT.pp_max = 5;
	SELFDESTRUCT.effect = SELF_KILL_E2;
	SELFDESTRUCT.chance = 1.0;
	SELFDESTRUCT.m_arg = 0;

	// sharpen
	strcpy(SHARPEN.name, "Sharpen");
	SHARPEN.damage = 0;
	SHARPEN.accuracy = 1.0;
	SHARPEN.type = NORMAL_T;
	SHARPEN.movetype = STATUS_MT;
	SHARPEN.priority = 0;
	SHARPEN.unique = 0;
	SHARPEN.pp_max = 30;
	SHARPEN.effect = SELF_ATTACK_E2;
	SHARPEN.chance = 1.0;
	SHARPEN.m_arg = 1;

	// sing
	strcpy(SING.name, "Sing");
	SING.damage = 0;
	SING.accuracy = 0.55;
	SING.type = NORMAL_T;
	SING.movetype = STATUS_MT;
	SING.priority = 0;
	SING.unique = 0;
	SING.pp_max = 15;
	SING.effect = APPLY_SLP_E2;
	SING.chance = 1.0;
	SING.m_arg = 0;

	// slam
	strcpy(SLAM.name, "Slam");
	SLAM.damage = 80;
	SLAM.accuracy = 0.75;
	SLAM.type = NORMAL_T;
	SLAM.movetype = PHYSICAL_MT;
	SLAM.priority = 0;
	SLAM.unique = 0;
	SLAM.pp_max = 20;
	SLAM.effect = NON_E2;
	SLAM.chance = 1.0;
	SLAM.m_arg = 0;

	// slash
	strcpy(SLASH.name, "Slash");
	SLASH.damage = 70;
	SLASH.accuracy = 1.0;
	SLASH.type = NORMAL_T;
	SLASH.movetype = PHYSICAL_MT;
	SLASH.priority = 0;
	SLASH.unique = 0;
	SLASH.pp_max = 20;
	SLASH.effect = HIGH_CRIT_E2;
	SLASH.chance = 1.0;
	SLASH.m_arg = 0;

	// sleep powder
	strcpy(SLEEPPOWDER.name, "Sleep Powder");
	SLEEPPOWDER.damage = 0;
	SLEEPPOWDER.accuracy = 0.75;
	SLEEPPOWDER.type = GRASS_T;
	SLEEPPOWDER.movetype = STATUS_MT;
	SLEEPPOWDER.priority = 0;
	SLEEPPOWDER.unique = 0;
	SLEEPPOWDER.pp_max = 15;
	SLEEPPOWDER.effect = APPLY_SLP_E2;
	SLEEPPOWDER.chance = 1.0;
	SLEEPPOWDER.m_arg = 0;

	// sludge
	strcpy(SLUDGE.name, "Sludge");
	SLUDGE.damage = 65;
	SLUDGE.accuracy = 1.0;
	SLUDGE.type = POISON_T;
	SLUDGE.movetype = SPECIAL_MT;
	SLUDGE.priority = 0;
	SLUDGE.unique = 0;
	SLUDGE.pp_max = 20;
	SLUDGE.effect = APPLY_PSN_E2;
	SLUDGE.chance = 0.3;
	SLUDGE.m_arg = 0;

	// smog
	strcpy(SMOG.name, "Smog");
	SMOG.damage = 30;
	SMOG.accuracy = 0.7;
	SMOG.type = POISON_T;
	SMOG.movetype = SPECIAL_MT;
	SMOG.priority = 0;
	SMOG.unique = 0;
	SMOG.pp_max = 20;
	SMOG.effect = APPLY_PSN_E2;
	SMOG.chance = 0.4;
	SMOG.m_arg = 0;

	// smokescreen
	strcpy(SMOKESCREEN.name, "Smokescreen");
	SMOKESCREEN.damage = 0;
	SMOKESCREEN.accuracy = 1.0;
	SMOKESCREEN.type = NORMAL_T;
	SMOKESCREEN.movetype = STATUS_MT;
	SMOKESCREEN.priority = 0;
	SMOKESCREEN.unique = 0;
	SMOKESCREEN.pp_max = 20;
	SMOKESCREEN.effect = OTHR_ACCURACY_E2;
	SMOKESCREEN.chance = 1.0;
	SMOKESCREEN.m_arg = -1;

	// splash
	strcpy(SPLASH.name, "Splash");
	SPLASH.damage = 0;
	SPLASH.accuracy = 1.0;
	SPLASH.type = NORMAL_T;
	SPLASH.movetype = STATUS_MT;
	SPLASH.priority = 0;
	SPLASH.unique = 0;
	SPLASH.pp_max = 40;
	SPLASH.effect = NON_E2;
	SPLASH.chance = 1.0;
	SPLASH.m_arg = 0;

	// spore
	strcpy(SPORE.name, "Spore");
	SPORE.damage = 0;
	SPORE.accuracy = 1.0;
	SPORE.type = GRASS_T;
	SPORE.movetype = STATUS_MT;
	SPORE.priority = 0;
	SPORE.unique = 0;
	SPORE.pp_max = 15;
	SPORE.effect = APPLY_SLP_E2;
	SPORE.chance = 1.0;
	SPORE.m_arg = 0;

	// stomp
	strcpy(STOMP.name, "Stomp");
	STOMP.damage = 65;
	STOMP.accuracy = 1.0;
	STOMP.type = NORMAL_T;
	STOMP.movetype = PHYSICAL_MT;
	STOMP.priority = 0;
	STOMP.unique = 0;
	STOMP.pp_max = 20;
	STOMP.effect = APPLY_FLINCH_E2;
	STOMP.chance = 0.3;
	STOMP.m_arg = 0;

	// strength
	strcpy(STRENGTH.name, "Strength");
	STRENGTH.damage = 80;
	STRENGTH.accuracy = 1.0;
	STRENGTH.type = NORMAL_T;
	STRENGTH.movetype = PHYSICAL_MT;
	STRENGTH.priority = 0;
	STRENGTH.unique = 0;
	STRENGTH.pp_max = 15;
	STRENGTH.effect = NON_E2;
	STRENGTH.chance = 1.0;
	STRENGTH.m_arg = 0;

	// string shot
	strcpy(STRINGSHOT.name, "String Shot");
	STRINGSHOT.damage = 0;
	STRINGSHOT.accuracy = 0.95;
	STRINGSHOT.type = BUG_T;
	STRINGSHOT.movetype = STATUS_MT;
	STRINGSHOT.priority = 0;
	STRINGSHOT.unique = 0;
	STRINGSHOT.pp_max = 40;
	STRINGSHOT.effect = OTHR_SPEED_E2;
	STRINGSHOT.chance = 1.0;
	STRINGSHOT.m_arg = -2;

	// struggle
	strcpy(STRUGGLE.name, "Struggle");
	STRUGGLE.damage = 50;
	STRUGGLE.accuracy = 1.0;
	STRUGGLE.type = NORMAL_T;
	STRUGGLE.movetype = PHYSICAL_MT;
	STRUGGLE.priority = 0;
	STRUGGLE.unique = 0;
	STRUGGLE.pp_max = 0;
	STRUGGLE.effect = RECOIL_E2;
	STRUGGLE.chance = 1.0;
	STRUGGLE.m_arg = 2;

	// stun spore
	strcpy(STUNSPORE.name, "Stun Spore");
	STUNSPORE.damage = 0;
	STUNSPORE.accuracy = 0.75;
	STUNSPORE.type = GRASS_T;
	STUNSPORE.movetype = STATUS_MT;
	STUNSPORE.priority = 0;
	STUNSPORE.unique = 0;
	STUNSPORE.pp_max = 30;
	STUNSPORE.effect = APPLY_PAR_E2;
	STUNSPORE.chance = 1.0;
	STUNSPORE.m_arg = 0;

	// submission
	strcpy(SUBMISSION.name, "Submission");
	SUBMISSION.damage = 80;
	SUBMISSION.accuracy = 0.8;
	SUBMISSION.type = FIGHTING_T;
	SUBMISSION.movetype = PHYSICAL_MT;
	SUBMISSION.priority = 0;
	SUBMISSION.unique = 0;
	SUBMISSION.pp_max = 25;
	SUBMISSION.effect = RECOIL_E2;
	SUBMISSION.chance = 1.0;
	SUBMISSION.m_arg = 4;

	// supersonic
	strcpy(SUPERSONIC.name, "Supersonic");
	SUPERSONIC.damage = 0;
	SUPERSONIC.accuracy = 0.55;
	SUPERSONIC.type = NORMAL_T;
	SUPERSONIC.movetype = STATUS_MT;
	SUPERSONIC.priority = 0;
	SUPERSONIC.unique = 0;
	SUPERSONIC.pp_max = 20;
	SUPERSONIC.effect = APPLY_CONFUSE_E2;
	SUPERSONIC.chance = 1.0;
	SUPERSONIC.m_arg = 0;

	// surf
	strcpy(SURF.name, "Surf");
	SURF.damage = 90;
	SURF.accuracy = 1.0;
	SURF.type = WATER_T;
	SURF.movetype = SPECIAL_MT;
	SURF.priority = 0;
	SURF.unique = 0;
	SURF.pp_max = 15;
	SURF.effect = NON_E2;
	SURF.chance = 1.0;
	SURF.m_arg = 0;

	// swords dance
	strcpy(SWORDSDANCE.name, "Swords Dance");
	SWORDSDANCE.damage = 0;
	SWORDSDANCE.accuracy = 1.0;
	SWORDSDANCE.type = NORMAL_T;
	SWORDSDANCE.movetype = STATUS_MT;
	SWORDSDANCE.priority = 0;
	SWORDSDANCE.unique = 0;
	SWORDSDANCE.pp_max = 20;
	SWORDSDANCE.effect = SELF_ATTACK_E2;
	SWORDSDANCE.chance = 1.0;
	SWORDSDANCE.m_arg = 2;

	// tackle
	strcpy(TACKLE.name, "Tackle");
	TACKLE.damage = 50;
	TACKLE.accuracy = 1.0;
	TACKLE.type = NORMAL_T;
	TACKLE.movetype = PHYSICAL_MT;
	TACKLE.priority = 0;
	TACKLE.unique = 0;
	TACKLE.pp_max = 35;
	TACKLE.effect = NON_E2;
	TACKLE.chance = 1.0;
	TACKLE.m_arg = 0;

	// tail whip
	strcpy(TAILWHIP.name, "Tail Whip");
	TAILWHIP.damage = 0;
	TAILWHIP.accuracy = 1.0;
	TAILWHIP.type = NORMAL_T;
	TAILWHIP.movetype = STATUS_MT;
	TAILWHIP.priority = 0;
	TAILWHIP.unique = 0;
	TAILWHIP.pp_max = 30;
	TAILWHIP.effect = OTHR_DEFENSE_E2;
	TAILWHIP.chance = 1.0;
	TAILWHIP.m_arg = -1;

	// take down
	strcpy(TAKEDOWN.name, "Take Down");
	TAKEDOWN.damage = 90;
	TAKEDOWN.accuracy = 0.85;
	TAKEDOWN.type = NORMAL_T;
	TAKEDOWN.movetype = PHYSICAL_MT;
	TAKEDOWN.priority = 0;
	TAKEDOWN.unique = 0;
	TAKEDOWN.pp_max = 20;
	TAKEDOWN.effect = RECOIL_E2;
	TAKEDOWN.chance = 1.0;
	TAKEDOWN.m_arg = 4;

	// thunder
	strcpy(THUNDER.name, "Thunder");
	THUNDER.damage = 110;
	THUNDER.accuracy = 0.7;
	THUNDER.type = ELECTRIC_T;
	THUNDER.movetype = SPECIAL_MT;
	THUNDER.priority = 0;
	THUNDER.unique = 0;
	THUNDER.pp_max = 10;
	THUNDER.effect = APPLY_PAR_E2;
	THUNDER.chance = 0.3;
	THUNDER.m_arg = 0;

	// thunder punch
	strcpy(THUNDERPUNCH.name, "ThunderPunch");
	THUNDERPUNCH.damage = 75;
	THUNDERPUNCH.accuracy = 1.0;
	THUNDERPUNCH.type = ELECTRIC_T;
	THUNDERPUNCH.movetype = PHYSICAL_MT;
	THUNDERPUNCH.priority = 0;
	THUNDERPUNCH.unique = 0;
	THUNDERPUNCH.pp_max = 15;
	THUNDERPUNCH.effect = APPLY_PAR_E2;
	THUNDERPUNCH.chance = 0.1;
	THUNDERPUNCH.m_arg = 0;

	// thunder shock
	strcpy(THUNDERSHOCK.name, "ThunderShock");
	THUNDERSHOCK.damage = 40;
	THUNDERSHOCK.accuracy = 1.0;
	THUNDERSHOCK.type = ELECTRIC_T;
	THUNDERSHOCK.movetype = SPECIAL_MT;
	THUNDERSHOCK.priority = 0;
	THUNDERSHOCK.unique = 0;
	THUNDERSHOCK.pp_max = 30;
	THUNDERSHOCK.effect = APPLY_PAR_E2;
	THUNDERSHOCK.chance = 0.1;
	THUNDERSHOCK.m_arg = 0;

	// thunder wave
	strcpy(THUNDERWAVE.name, "Thunder Wave");
	THUNDERWAVE.damage = 0;
	THUNDERWAVE.accuracy = 1.0;
	THUNDERWAVE.type = ELECTRIC_T;
	THUNDERWAVE.movetype = STATUS_MT;
	THUNDERWAVE.priority = 0;
	THUNDERWAVE.unique = 0;
	THUNDERWAVE.pp_max = 20;
	THUNDERWAVE.effect = APPLY_PAR_E2;
	THUNDERWAVE.chance = 1.0;
	THUNDERWAVE.m_arg = 0;

	// thunderbolt
	strcpy(THUNDERBOLT.name, "Thunderbolt");
	THUNDERBOLT.damage = 90;
	THUNDERBOLT.accuracy = 1.0;
	THUNDERBOLT.type = ELECTRIC_T;
	THUNDERBOLT.movetype = SPECIAL_MT;
	THUNDERBOLT.priority = 0;
	THUNDERBOLT.unique = 0;
	THUNDERBOLT.pp_max = 15;
	THUNDERBOLT.effect = APPLY_PAR_E2;
	THUNDERBOLT.chance = 0.1;
	THUNDERBOLT.m_arg = 0;

	// toxic
	strcpy(TOXIC.name, "Toxic");
	TOXIC.damage = 0;
	TOXIC.accuracy = 0.9;
	TOXIC.type = POISON_T;
	TOXIC.movetype = STATUS_MT;
	TOXIC.priority = 0;
	TOXIC.unique = 0;
	TOXIC.pp_max = 10;
	TOXIC.effect = APPLY_TXC_E2;
	TOXIC.chance = 1.0;
	TOXIC.m_arg = 0;

	// vice grip
	strcpy(VICEGRIP.name, "Vice Grip");
	VICEGRIP.damage = 55;
	VICEGRIP.accuracy = 1.0;
	VICEGRIP.type = NORMAL_T;
	VICEGRIP.movetype = PHYSICAL_MT;
	VICEGRIP.priority = 0;
	VICEGRIP.unique = 0;
	VICEGRIP.pp_max = 30;
	VICEGRIP.effect = NON_E2;
	VICEGRIP.chance = 1.0;
	VICEGRIP.m_arg = 0;

	// vine whip
	strcpy(VINEWHIP.name, "Vine Whip");
	VINEWHIP.damage = 45;
	VINEWHIP.accuracy = 1.0;
	VINEWHIP.type = GRASS_T;
	VINEWHIP.movetype = PHYSICAL_MT;
	VINEWHIP.priority = 0;
	VINEWHIP.unique = 0;
	VINEWHIP.pp_max = 25;
	VINEWHIP.effect = NON_E2;
	VINEWHIP.chance = 1.0;
	VINEWHIP.m_arg = 0;

	// water gun
	strcpy(WATERGUN.name, "Water Gun");
	WATERGUN.damage = 40;
	WATERGUN.accuracy = 1.0;
	WATERGUN.type = WATER_T;
	WATERGUN.movetype = SPECIAL_MT;
	WATERGUN.priority = 0;
	WATERGUN.unique = 0;
	WATERGUN.pp_max = 25;
	WATERGUN.effect = NON_E2;
	WATERGUN.chance = 1.0;
	WATERGUN.m_arg = 0;

	// waterfall
	strcpy(WATERFALL.name, "Waterfall");
	WATERFALL.damage = 80;
	WATERFALL.accuracy = 1.0;
	WATERFALL.type = WATER_T;
	WATERFALL.movetype = PHYSICAL_MT;
	WATERFALL.priority = 0;
	WATERFALL.unique = 0;
	WATERFALL.pp_max = 15;
	WATERFALL.effect = APPLY_FLINCH_E2;
	WATERFALL.chance = 0.2;
	WATERFALL.m_arg = 0;

	// wing attack
	strcpy(WINGATTACK.name, "Wing Attack");
	WINGATTACK.damage = 60;
	WINGATTACK.accuracy = 1.0;
	WINGATTACK.type = FLYING_T;
	WINGATTACK.movetype = PHYSICAL_MT;
	WINGATTACK.priority = 0;
	WINGATTACK.unique = 0;
	WINGATTACK.pp_max = 35;
	WINGATTACK.effect = NON_E2;
	WINGATTACK.chance = 1.0;
	WINGATTACK.m_arg = 0;

	// withdraw
	strcpy(WITHDRAW.name, "Withdraw");
	WITHDRAW.damage = 0;
	WITHDRAW.accuracy = 1.0;
	WITHDRAW.type = WATER_T;
	WITHDRAW.movetype = STATUS_MT;
	WITHDRAW.priority = 0;
	WITHDRAW.unique = 0;
	WITHDRAW.pp_max = 40;
	WITHDRAW.effect = SELF_DEFENSE_E2;
	WITHDRAW.chance = 1.0;
	WITHDRAW.m_arg = 1;
}

void init_rentals() {
	RED_PIKACHU.species = &PIKACHU;
	RED_PIKACHU.pstats.level = 100;
	RED_PIKACHU.pstats.hp_ev = 0;
	RED_PIKACHU.pstats.hp_iv = 0;
	RED_PIKACHU.pstats.attack_ev = 0;
	RED_PIKACHU.pstats.attack_iv = 0;
	RED_PIKACHU.pstats.defense_ev = 0;
	RED_PIKACHU.pstats.defense_iv = 0;
	RED_PIKACHU.pstats.sattack_ev = 0;
	RED_PIKACHU.pstats.sattack_iv = 0;
	RED_PIKACHU.pstats.sdefense_ev = 0;
	RED_PIKACHU.pstats.speed_ev = 0;
	RED_PIKACHU.pstats.speed_iv = 0;
	RED_PIKACHU.pstats.nature = BASHFUL_N;
	RED_PIKACHU.v.attack_stage = 0;
	RED_PIKACHU.v.defense_stage = 0;
	RED_PIKACHU.v.sattack_stage = 0;
	RED_PIKACHU.v.sdefense_stage = 0;
	RED_PIKACHU.v.speed_stage = 0;
	RED_PIKACHU.v.accuracy_stage = 0;
	RED_PIKACHU.v.evasion_stage = 0;
	RED_PIKACHU.v.is_flinch = false;
	RED_PIKACHU.v.is_recharge = false;
	RED_PIKACHU.v.is_confuse = false;
	RED_PIKACHU.nv.hp = calc_hpmax(&RED_PIKACHU);
	RED_PIKACHU.nv.nvstatus = NON_S;
	RED_PIKACHU.nv.nv_arg = 0;
	RED_PIKACHU.moves[0] = &THUNDER;
	RED_PIKACHU.moves[1] = &THUNDERBOLT;
	RED_PIKACHU.moves[2] = &THUNDERWAVE;
	RED_PIKACHU.moves[3] = &QUICKATTACK;
	RED_PIKACHU.pp[0] = RED_PIKACHU.moves[0]->pp_max;
	RED_PIKACHU.pp[1] = RED_PIKACHU.moves[1]->pp_max;
	RED_PIKACHU.pp[2] = RED_PIKACHU.moves[2]->pp_max;
	RED_PIKACHU.pp[3] = RED_PIKACHU.moves[3]->pp_max;
	RED_PIKACHU.move_count = 4;

	RED_LAPRAS.species = &LAPRAS;
	RED_LAPRAS.pstats.level = 100;
	RED_LAPRAS.pstats.hp_ev = 0;
	RED_LAPRAS.pstats.hp_iv = 0;
	RED_LAPRAS.pstats.attack_ev = 0;
	RED_LAPRAS.pstats.attack_iv = 0;
	RED_LAPRAS.pstats.defense_ev = 0;
	RED_LAPRAS.pstats.defense_iv = 0;
	RED_LAPRAS.pstats.sattack_ev = 0;
	RED_LAPRAS.pstats.sattack_iv = 0;
	RED_LAPRAS.pstats.sdefense_ev = 0;
	RED_LAPRAS.pstats.speed_ev = 0;
	RED_LAPRAS.pstats.speed_iv = 0;
	RED_LAPRAS.pstats.nature = BASHFUL_N;
	RED_LAPRAS.v.attack_stage = 0;
	RED_LAPRAS.v.defense_stage = 0;
	RED_LAPRAS.v.sattack_stage = 0;
	RED_LAPRAS.v.sdefense_stage = 0;
	RED_LAPRAS.v.speed_stage = 0;
	RED_LAPRAS.v.accuracy_stage = 0;
	RED_LAPRAS.v.evasion_stage = 0;
	RED_LAPRAS.v.is_flinch = false;
	RED_LAPRAS.v.is_recharge = false;
	RED_LAPRAS.v.is_confuse = false;
	RED_LAPRAS.nv.hp = calc_hpmax(&RED_LAPRAS);
	RED_LAPRAS.nv.nvstatus = NON_S;
	RED_LAPRAS.nv.nv_arg = 0;
	RED_LAPRAS.moves[0] = &SURF;
	RED_LAPRAS.moves[1] = &ICEBEAM;
	RED_LAPRAS.moves[2] = &CONFUSERAY;
	RED_LAPRAS.moves[3] = &BODYSLAM;
	RED_LAPRAS.pp[0] = RED_LAPRAS.moves[0]->pp_max;
	RED_LAPRAS.pp[1] = RED_LAPRAS.moves[1]->pp_max;
	RED_LAPRAS.pp[2] = RED_LAPRAS.moves[2]->pp_max;
	RED_LAPRAS.pp[3] = RED_LAPRAS.moves[3]->pp_max;
	RED_LAPRAS.move_count = 4;

	RED_SNORLAX.species = &SNORLAX;
	RED_SNORLAX.pstats.level = 100;
	RED_SNORLAX.pstats.hp_ev = 0;
	RED_SNORLAX.pstats.hp_iv = 0;
	RED_SNORLAX.pstats.attack_ev = 0;
	RED_SNORLAX.pstats.attack_iv = 0;
	RED_SNORLAX.pstats.defense_ev = 0;
	RED_SNORLAX.pstats.defense_iv = 0;
	RED_SNORLAX.pstats.sattack_ev = 0;
	RED_SNORLAX.pstats.sattack_iv = 0;
	RED_SNORLAX.pstats.sdefense_ev = 0;
	RED_SNORLAX.pstats.speed_ev = 0;
	RED_SNORLAX.pstats.speed_iv = 0;
	RED_SNORLAX.pstats.nature = BASHFUL_N;
	RED_SNORLAX.v.attack_stage = 0;
	RED_SNORLAX.v.defense_stage = 0;
	RED_SNORLAX.v.sattack_stage = 0;
	RED_SNORLAX.v.sdefense_stage = 0;
	RED_SNORLAX.v.speed_stage = 0;
	RED_SNORLAX.v.accuracy_stage = 0;
	RED_SNORLAX.v.evasion_stage = 0;
	RED_SNORLAX.v.is_flinch = false;
	RED_SNORLAX.v.is_recharge = false;
	RED_SNORLAX.v.is_confuse = false;
	RED_SNORLAX.nv.hp = calc_hpmax(&RED_SNORLAX);
	RED_SNORLAX.nv.nvstatus = NON_S;
	RED_SNORLAX.nv.nv_arg = 0;
	RED_SNORLAX.moves[0] = &BODYSLAM;
	RED_SNORLAX.moves[1] = &STRENGTH;
	RED_SNORLAX.moves[2] = &HYPERBEAM;
	RED_SNORLAX.moves[3] = &AMNESIA;
	RED_SNORLAX.pp[0] = RED_SNORLAX.moves[0]->pp_max;
	RED_SNORLAX.pp[1] = RED_SNORLAX.moves[1]->pp_max;
	RED_SNORLAX.pp[2] = RED_SNORLAX.moves[2]->pp_max;
	RED_SNORLAX.pp[3] = RED_SNORLAX.moves[3]->pp_max;
	RED_SNORLAX.move_count = 4;

	RED_VENUSAUR.species = &VENUSAUR;
	RED_VENUSAUR.pstats.level = 100;
	RED_VENUSAUR.pstats.hp_ev = 0;
	RED_VENUSAUR.pstats.hp_iv = 0;
	RED_VENUSAUR.pstats.attack_ev = 0;
	RED_VENUSAUR.pstats.attack_iv = 0;
	RED_VENUSAUR.pstats.defense_ev = 0;
	RED_VENUSAUR.pstats.defense_iv = 0;
	RED_VENUSAUR.pstats.sattack_ev = 0;
	RED_VENUSAUR.pstats.sattack_iv = 0;
	RED_VENUSAUR.pstats.sdefense_ev = 0;
	RED_VENUSAUR.pstats.speed_ev = 0;
	RED_VENUSAUR.pstats.speed_iv = 0;
	RED_VENUSAUR.pstats.nature = BASHFUL_N;
	RED_VENUSAUR.v.attack_stage = 0;
	RED_VENUSAUR.v.defense_stage = 0;
	RED_VENUSAUR.v.sattack_stage = 0;
	RED_VENUSAUR.v.sdefense_stage = 0;
	RED_VENUSAUR.v.speed_stage = 0;
	RED_VENUSAUR.v.accuracy_stage = 0;
	RED_VENUSAUR.v.evasion_stage = 0;
	RED_VENUSAUR.v.is_flinch = false;
	RED_VENUSAUR.v.is_recharge = false;
	RED_VENUSAUR.v.is_confuse = false;
	RED_VENUSAUR.nv.hp = calc_hpmax(&RED_VENUSAUR);
	RED_VENUSAUR.nv.nvstatus = NON_S;
	RED_VENUSAUR.nv.nv_arg = 0;
	RED_VENUSAUR.moves[0] = &RAZORLEAF;
	RED_VENUSAUR.moves[1] = &GROWTH;
	RED_VENUSAUR.moves[2] = &SLEEPPOWDER;
	RED_VENUSAUR.moves[3] = &TOXIC;
	RED_VENUSAUR.pp[0] = RED_VENUSAUR.moves[0]->pp_max;
	RED_VENUSAUR.pp[1] = RED_VENUSAUR.moves[1]->pp_max;
	RED_VENUSAUR.pp[2] = RED_VENUSAUR.moves[2]->pp_max;
	RED_VENUSAUR.pp[3] = RED_VENUSAUR.moves[3]->pp_max;
	RED_VENUSAUR.move_count = 4;

	RED_CHARIZARD.species = &CHARIZARD;
	RED_CHARIZARD.pstats.level = 100;
	RED_CHARIZARD.pstats.hp_ev = 0;
	RED_CHARIZARD.pstats.hp_iv = 0;
	RED_CHARIZARD.pstats.attack_ev = 0;
	RED_CHARIZARD.pstats.attack_iv = 0;
	RED_CHARIZARD.pstats.defense_ev = 0;
	RED_CHARIZARD.pstats.defense_iv = 0;
	RED_CHARIZARD.pstats.sattack_ev = 0;
	RED_CHARIZARD.pstats.sattack_iv = 0;
	RED_CHARIZARD.pstats.sdefense_ev = 0;
	RED_CHARIZARD.pstats.speed_ev = 0;
	RED_CHARIZARD.pstats.speed_iv = 0;
	RED_CHARIZARD.pstats.nature = BASHFUL_N;
	RED_CHARIZARD.v.attack_stage = 0;
	RED_CHARIZARD.v.defense_stage = 0;
	RED_CHARIZARD.v.sattack_stage = 0;
	RED_CHARIZARD.v.sdefense_stage = 0;
	RED_CHARIZARD.v.speed_stage = 0;
	RED_CHARIZARD.v.accuracy_stage = 0;
	RED_CHARIZARD.v.evasion_stage = 0;
	RED_CHARIZARD.v.is_flinch = false;
	RED_CHARIZARD.v.is_recharge = false;
	RED_CHARIZARD.v.is_confuse = false;
	RED_CHARIZARD.nv.hp = calc_hpmax(&RED_CHARIZARD);
	RED_CHARIZARD.nv.nvstatus = NON_S;
	RED_CHARIZARD.nv.nv_arg = 0;
	RED_CHARIZARD.moves[0] = &FLAMETHROWER;
	RED_CHARIZARD.moves[1] = &WINGATTACK;
	RED_CHARIZARD.moves[2] = &SLASH;
	RED_CHARIZARD.moves[3] = &FIREBLAST;
	RED_CHARIZARD.pp[0] = RED_CHARIZARD.moves[0]->pp_max;
	RED_CHARIZARD.pp[1] = RED_CHARIZARD.moves[1]->pp_max;
	RED_CHARIZARD.pp[2] = RED_CHARIZARD.moves[2]->pp_max;
	RED_CHARIZARD.pp[3] = RED_CHARIZARD.moves[3]->pp_max;
	RED_CHARIZARD.move_count = 4;

	RED_BLASTOISE.species = &BLASTOISE;
	RED_BLASTOISE.pstats.level = 100;
	RED_BLASTOISE.pstats.hp_ev = 0;
	RED_BLASTOISE.pstats.hp_iv = 0;
	RED_BLASTOISE.pstats.attack_ev = 0;
	RED_BLASTOISE.pstats.attack_iv = 0;
	RED_BLASTOISE.pstats.defense_ev = 0;
	RED_BLASTOISE.pstats.defense_iv = 0;
	RED_BLASTOISE.pstats.sattack_ev = 0;
	RED_BLASTOISE.pstats.sattack_iv = 0;
	RED_BLASTOISE.pstats.sdefense_ev = 0;
	RED_BLASTOISE.pstats.speed_ev = 0;
	RED_BLASTOISE.pstats.speed_iv = 0;
	RED_BLASTOISE.pstats.nature = BASHFUL_N;
	RED_BLASTOISE.v.attack_stage = 0;
	RED_BLASTOISE.v.defense_stage = 0;
	RED_BLASTOISE.v.sattack_stage = 0;
	RED_BLASTOISE.v.sdefense_stage = 0;
	RED_BLASTOISE.v.speed_stage = 0;
	RED_BLASTOISE.v.accuracy_stage = 0;
	RED_BLASTOISE.v.evasion_stage = 0;
	RED_BLASTOISE.v.is_flinch = false;
	RED_BLASTOISE.v.is_recharge = false;
	RED_BLASTOISE.v.is_confuse = false;
	RED_BLASTOISE.nv.hp = calc_hpmax(&RED_BLASTOISE);
	RED_BLASTOISE.nv.nvstatus = NON_S;
	RED_BLASTOISE.nv.nv_arg = 0;
	RED_BLASTOISE.moves[0] = &SURF;
	RED_BLASTOISE.moves[1] = &HYDROPUMP;
	RED_BLASTOISE.moves[2] = &WITHDRAW;
	RED_BLASTOISE.moves[3] = &MEGAPUNCH;
	RED_BLASTOISE.pp[0] = RED_BLASTOISE.moves[0]->pp_max;
	RED_BLASTOISE.pp[1] = RED_BLASTOISE.moves[1]->pp_max;
	RED_BLASTOISE.pp[2] = RED_BLASTOISE.moves[2]->pp_max;
	RED_BLASTOISE.pp[3] = RED_BLASTOISE.moves[3]->pp_max;
	RED_BLASTOISE.move_count = 4;

	BLUE_PIDGEOT.species = &PIDGEOT;
	BLUE_PIDGEOT.pstats.level = 100;
	BLUE_PIDGEOT.pstats.hp_ev = 0;
	BLUE_PIDGEOT.pstats.hp_iv = 0;
	BLUE_PIDGEOT.pstats.attack_ev = 0;
	BLUE_PIDGEOT.pstats.attack_iv = 0;
	BLUE_PIDGEOT.pstats.defense_ev = 0;
	BLUE_PIDGEOT.pstats.defense_iv = 0;
	BLUE_PIDGEOT.pstats.sattack_ev = 0;
	BLUE_PIDGEOT.pstats.sattack_iv = 0;
	BLUE_PIDGEOT.pstats.sdefense_ev = 0;
	BLUE_PIDGEOT.pstats.speed_ev = 0;
	BLUE_PIDGEOT.pstats.speed_iv = 0;
	BLUE_PIDGEOT.pstats.nature = BASHFUL_N;
	BLUE_PIDGEOT.v.attack_stage = 0;
	BLUE_PIDGEOT.v.defense_stage = 0;
	BLUE_PIDGEOT.v.sattack_stage = 0;
	BLUE_PIDGEOT.v.sdefense_stage = 0;
	BLUE_PIDGEOT.v.speed_stage = 0;
	BLUE_PIDGEOT.v.accuracy_stage = 0;
	BLUE_PIDGEOT.v.evasion_stage = 0;
	BLUE_PIDGEOT.v.is_flinch = false;
	BLUE_PIDGEOT.v.is_recharge = false;
	BLUE_PIDGEOT.v.is_confuse = false;
	BLUE_PIDGEOT.nv.hp = calc_hpmax(&BLUE_PIDGEOT);
	BLUE_PIDGEOT.nv.nvstatus = NON_S;
	BLUE_PIDGEOT.nv.nv_arg = 0;
	BLUE_PIDGEOT.moves[0] = &GUST;
	BLUE_PIDGEOT.moves[1] = &WINGATTACK;
	BLUE_PIDGEOT.moves[2] = &AGILITY;
	BLUE_PIDGEOT.moves[3] = &SANDATTACK;
	BLUE_PIDGEOT.pp[0] = BLUE_PIDGEOT.moves[0]->pp_max;
	BLUE_PIDGEOT.pp[1] = BLUE_PIDGEOT.moves[1]->pp_max;
	BLUE_PIDGEOT.pp[2] = BLUE_PIDGEOT.moves[2]->pp_max;
	BLUE_PIDGEOT.pp[3] = BLUE_PIDGEOT.moves[3]->pp_max;
	BLUE_PIDGEOT.move_count = 4;

	BLUE_ALAKAZAM.species = &ALAKAZAM;
	BLUE_ALAKAZAM.pstats.level = 100;
	BLUE_ALAKAZAM.pstats.hp_ev = 0;
	BLUE_ALAKAZAM.pstats.hp_iv = 0;
	BLUE_ALAKAZAM.pstats.attack_ev = 0;
	BLUE_ALAKAZAM.pstats.attack_iv = 0;
	BLUE_ALAKAZAM.pstats.defense_ev = 0;
	BLUE_ALAKAZAM.pstats.defense_iv = 0;
	BLUE_ALAKAZAM.pstats.sattack_ev = 0;
	BLUE_ALAKAZAM.pstats.sattack_iv = 0;
	BLUE_ALAKAZAM.pstats.sdefense_ev = 0;
	BLUE_ALAKAZAM.pstats.speed_ev = 0;
	BLUE_ALAKAZAM.pstats.speed_iv = 0;
	BLUE_ALAKAZAM.pstats.nature = BASHFUL_N;
	BLUE_ALAKAZAM.v.attack_stage = 0;
	BLUE_ALAKAZAM.v.defense_stage = 0;
	BLUE_ALAKAZAM.v.sattack_stage = 0;
	BLUE_ALAKAZAM.v.sdefense_stage = 0;
	BLUE_ALAKAZAM.v.speed_stage = 0;
	BLUE_ALAKAZAM.v.accuracy_stage = 0;
	BLUE_ALAKAZAM.v.evasion_stage = 0;
	BLUE_ALAKAZAM.v.is_flinch = false;
	BLUE_ALAKAZAM.v.is_recharge = false;
	BLUE_ALAKAZAM.v.is_confuse = false;
	BLUE_ALAKAZAM.nv.hp = calc_hpmax(&BLUE_ALAKAZAM);
	BLUE_ALAKAZAM.nv.nvstatus = NON_S;
	BLUE_ALAKAZAM.nv.nv_arg = 0;
	BLUE_ALAKAZAM.moves[0] = &PSYCHIC;
	BLUE_ALAKAZAM.moves[1] = &PSYBEAM;
	BLUE_ALAKAZAM.moves[2] = &CONFUSION;
	BLUE_ALAKAZAM.moves[3] = &TOXIC;
	BLUE_ALAKAZAM.pp[0] = BLUE_ALAKAZAM.moves[0]->pp_max;
	BLUE_ALAKAZAM.pp[1] = BLUE_ALAKAZAM.moves[1]->pp_max;
	BLUE_ALAKAZAM.pp[2] = BLUE_ALAKAZAM.moves[2]->pp_max;
	BLUE_ALAKAZAM.pp[3] = BLUE_ALAKAZAM.moves[3]->pp_max;
	BLUE_ALAKAZAM.move_count = 4;

	BLUE_RHYDON.species = &RHYDON;
	BLUE_RHYDON.pstats.level = 100;
	BLUE_RHYDON.pstats.hp_ev = 0;
	BLUE_RHYDON.pstats.hp_iv = 0;
	BLUE_RHYDON.pstats.attack_ev = 0;
	BLUE_RHYDON.pstats.attack_iv = 0;
	BLUE_RHYDON.pstats.defense_ev = 0;
	BLUE_RHYDON.pstats.defense_iv = 0;
	BLUE_RHYDON.pstats.sattack_ev = 0;
	BLUE_RHYDON.pstats.sattack_iv = 0;
	BLUE_RHYDON.pstats.sdefense_ev = 0;
	BLUE_RHYDON.pstats.speed_ev = 0;
	BLUE_RHYDON.pstats.speed_iv = 0;
	BLUE_RHYDON.pstats.nature = BASHFUL_N;
	BLUE_RHYDON.v.attack_stage = 0;
	BLUE_RHYDON.v.defense_stage = 0;
	BLUE_RHYDON.v.sattack_stage = 0;
	BLUE_RHYDON.v.sdefense_stage = 0;
	BLUE_RHYDON.v.speed_stage = 0;
	BLUE_RHYDON.v.accuracy_stage = 0;
	BLUE_RHYDON.v.evasion_stage = 0;
	BLUE_RHYDON.v.is_flinch = false;
	BLUE_RHYDON.v.is_recharge = false;
	BLUE_RHYDON.v.is_confuse = false;
	BLUE_RHYDON.nv.hp = calc_hpmax(&BLUE_RHYDON);
	BLUE_RHYDON.nv.nvstatus = NON_S;
	BLUE_RHYDON.nv.nv_arg = 0;
	BLUE_RHYDON.moves[0] = &EARTHQUAKE;
	BLUE_RHYDON.moves[1] = &HORNDRILL;
	BLUE_RHYDON.moves[2] = &ROCKSLIDE;
	BLUE_RHYDON.moves[3] = &TAKEDOWN;
	BLUE_RHYDON.pp[0] = BLUE_RHYDON.moves[0]->pp_max;
	BLUE_RHYDON.pp[1] = BLUE_RHYDON.moves[1]->pp_max;
	BLUE_RHYDON.pp[2] = BLUE_RHYDON.moves[2]->pp_max;
	BLUE_RHYDON.pp[3] = BLUE_RHYDON.moves[3]->pp_max;
	BLUE_RHYDON.move_count = 4;

	BLUE_ARCANINE.species = &ARCANINE;
	BLUE_ARCANINE.pstats.level = 100;
	BLUE_ARCANINE.pstats.hp_ev = 0;
	BLUE_ARCANINE.pstats.hp_iv = 0;
	BLUE_ARCANINE.pstats.attack_ev = 0;
	BLUE_ARCANINE.pstats.attack_iv = 0;
	BLUE_ARCANINE.pstats.defense_ev = 0;
	BLUE_ARCANINE.pstats.defense_iv = 0;
	BLUE_ARCANINE.pstats.sattack_ev = 0;
	BLUE_ARCANINE.pstats.sattack_iv = 0;
	BLUE_ARCANINE.pstats.sdefense_ev = 0;
	BLUE_ARCANINE.pstats.speed_ev = 0;
	BLUE_ARCANINE.pstats.speed_iv = 0;
	BLUE_ARCANINE.pstats.nature = BASHFUL_N;
	BLUE_ARCANINE.v.attack_stage = 0;
	BLUE_ARCANINE.v.defense_stage = 0;
	BLUE_ARCANINE.v.sattack_stage = 0;
	BLUE_ARCANINE.v.sdefense_stage = 0;
	BLUE_ARCANINE.v.speed_stage = 0;
	BLUE_ARCANINE.v.accuracy_stage = 0;
	BLUE_ARCANINE.v.evasion_stage = 0;
	BLUE_ARCANINE.v.is_flinch = false;
	BLUE_ARCANINE.v.is_recharge = false;
	BLUE_ARCANINE.v.is_confuse = false;
	BLUE_ARCANINE.nv.hp = calc_hpmax(&BLUE_ARCANINE);
	BLUE_ARCANINE.nv.nvstatus = NON_S;
	BLUE_ARCANINE.nv.nv_arg = 0;
	BLUE_ARCANINE.moves[0] = &FLAMETHROWER;
	BLUE_ARCANINE.moves[1] = &TAKEDOWN;
	BLUE_ARCANINE.moves[2] = &BITE;
	BLUE_ARCANINE.moves[3] = &FIREBLAST;
	BLUE_ARCANINE.pp[0] = BLUE_ARCANINE.moves[0]->pp_max;
	BLUE_ARCANINE.pp[1] = BLUE_ARCANINE.moves[1]->pp_max;
	BLUE_ARCANINE.pp[2] = BLUE_ARCANINE.moves[2]->pp_max;
	BLUE_ARCANINE.pp[3] = BLUE_ARCANINE.moves[3]->pp_max;
	BLUE_ARCANINE.move_count = 4;

	BLUE_EXEGGUTOR.species = &EXEGGUTOR;
	BLUE_EXEGGUTOR.pstats.level = 100;
	BLUE_EXEGGUTOR.pstats.hp_ev = 0;
	BLUE_EXEGGUTOR.pstats.hp_iv = 0;
	BLUE_EXEGGUTOR.pstats.attack_ev = 0;
	BLUE_EXEGGUTOR.pstats.attack_iv = 0;
	BLUE_EXEGGUTOR.pstats.defense_ev = 0;
	BLUE_EXEGGUTOR.pstats.defense_iv = 0;
	BLUE_EXEGGUTOR.pstats.sattack_ev = 0;
	BLUE_EXEGGUTOR.pstats.sattack_iv = 0;
	BLUE_EXEGGUTOR.pstats.sdefense_ev = 0;
	BLUE_EXEGGUTOR.pstats.speed_ev = 0;
	BLUE_EXEGGUTOR.pstats.speed_iv = 0;
	BLUE_EXEGGUTOR.pstats.nature = BASHFUL_N;
	BLUE_EXEGGUTOR.v.attack_stage = 0;
	BLUE_EXEGGUTOR.v.defense_stage = 0;
	BLUE_EXEGGUTOR.v.sattack_stage = 0;
	BLUE_EXEGGUTOR.v.sdefense_stage = 0;
	BLUE_EXEGGUTOR.v.speed_stage = 0;
	BLUE_EXEGGUTOR.v.accuracy_stage = 0;
	BLUE_EXEGGUTOR.v.evasion_stage = 0;
	BLUE_EXEGGUTOR.v.is_flinch = false;
	BLUE_EXEGGUTOR.v.is_recharge = false;
	BLUE_EXEGGUTOR.v.is_confuse = false;
	BLUE_EXEGGUTOR.nv.hp = calc_hpmax(&BLUE_EXEGGUTOR);
	BLUE_EXEGGUTOR.nv.nvstatus = NON_S;
	BLUE_EXEGGUTOR.nv.nv_arg = 0;
	BLUE_EXEGGUTOR.moves[0] = &EGGBOMB;
	BLUE_EXEGGUTOR.moves[1] = &RAZORLEAF;
	BLUE_EXEGGUTOR.moves[2] = &SLEEPPOWDER;
	BLUE_EXEGGUTOR.moves[3] = &PSYCHIC;
	BLUE_EXEGGUTOR.pp[0] = BLUE_EXEGGUTOR.moves[0]->pp_max;
	BLUE_EXEGGUTOR.pp[1] = BLUE_EXEGGUTOR.moves[1]->pp_max;
	BLUE_EXEGGUTOR.pp[2] = BLUE_EXEGGUTOR.moves[2]->pp_max;
	BLUE_EXEGGUTOR.pp[3] = BLUE_EXEGGUTOR.moves[3]->pp_max;
	BLUE_EXEGGUTOR.move_count = 4;

	BLUE_BLASTOISE.species = &BLASTOISE;
	BLUE_BLASTOISE.pstats.level = 100;
	BLUE_BLASTOISE.pstats.hp_ev = 0;
	BLUE_BLASTOISE.pstats.hp_iv = 0;
	BLUE_BLASTOISE.pstats.attack_ev = 0;
	BLUE_BLASTOISE.pstats.attack_iv = 0;
	BLUE_BLASTOISE.pstats.defense_ev = 0;
	BLUE_BLASTOISE.pstats.defense_iv = 0;
	BLUE_BLASTOISE.pstats.sattack_ev = 0;
	BLUE_BLASTOISE.pstats.sattack_iv = 0;
	BLUE_BLASTOISE.pstats.sdefense_ev = 0;
	BLUE_BLASTOISE.pstats.speed_ev = 0;
	BLUE_BLASTOISE.pstats.speed_iv = 0;
	BLUE_BLASTOISE.pstats.nature = BASHFUL_N;
	BLUE_BLASTOISE.v.attack_stage = 0;
	BLUE_BLASTOISE.v.defense_stage = 0;
	BLUE_BLASTOISE.v.sattack_stage = 0;
	BLUE_BLASTOISE.v.sdefense_stage = 0;
	BLUE_BLASTOISE.v.speed_stage = 0;
	BLUE_BLASTOISE.v.accuracy_stage = 0;
	BLUE_BLASTOISE.v.evasion_stage = 0;
	BLUE_BLASTOISE.v.is_flinch = false;
	BLUE_BLASTOISE.v.is_recharge = false;
	BLUE_BLASTOISE.v.is_confuse = false;
	BLUE_BLASTOISE.nv.hp = calc_hpmax(&BLUE_BLASTOISE);
	BLUE_BLASTOISE.nv.nvstatus = NON_S;
	BLUE_BLASTOISE.nv.nv_arg = 0;
	BLUE_BLASTOISE.moves[0] = &SURF;
	BLUE_BLASTOISE.moves[1] = &EARTHQUAKE;
	BLUE_BLASTOISE.moves[2] = &HYDROPUMP;
	BLUE_BLASTOISE.moves[3] = &BLIZZARD;
	BLUE_BLASTOISE.pp[0] = BLUE_BLASTOISE.moves[0]->pp_max;
	BLUE_BLASTOISE.pp[1] = BLUE_BLASTOISE.moves[1]->pp_max;
	BLUE_BLASTOISE.pp[2] = BLUE_BLASTOISE.moves[2]->pp_max;
	BLUE_BLASTOISE.pp[3] = BLUE_BLASTOISE.moves[3]->pp_max;
	BLUE_BLASTOISE.move_count = 4;
}

void init_trainers() {
	strcpy(RED.name, "Red");
	RED.pokemon[0] = &RED_PIKACHU;
	RED.pokemon[1] = &RED_LAPRAS;
	RED.pokemon[2] = &RED_SNORLAX;
	RED.pokemon[3] = &RED_VENUSAUR;
	RED.pokemon[4] = &RED_CHARIZARD;
	RED.pokemon[5] = &RED_BLASTOISE;
	RED.pokemon_active = 0;
	RED.action = NON_A;
	RED.pokemon_count = 6;

	strcpy(BLUE.name, "Blue");
	BLUE.pokemon[0] = &BLUE_PIDGEOT;
	BLUE.pokemon[1] = &BLUE_ALAKAZAM;
	BLUE.pokemon[2] = &BLUE_RHYDON;
	BLUE.pokemon[3] = &BLUE_ARCANINE;
	BLUE.pokemon[4] = &BLUE_EXEGGUTOR;
	BLUE.pokemon[5] = &BLUE_BLASTOISE;
	BLUE.pokemon_active = 0;
	BLUE.action = NON_A;
	BLUE.pokemon_count = 6;
}

void init_battle() {
	PLAYER1 = &RED;
	PLAYER2 = &BLUE;

	CURR_PLAYER = PLAYER1;
	OTHR_PLAYER = PLAYER2;

	battle.last_dmg = 0;
	//battle.last_move = &STRUGGLE; // maybe make this NULL? this only matters for things like counter and mirror coat

	battle.round_num = 1;
	
}