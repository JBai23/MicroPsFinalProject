
#include "pokemon-def.h"
#include "moves-def.h"
#include "types.h"
#include <string.h>
#include "global.h"
#include <stdlib.h>
#include <stdio.h>
#include "rentals-def.h"
#include "bitbang.h"

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
	// printf("ACTION: %i", action);

	switch(action) {
		case MOVE1_A:
		case MOVE2_A:
		case MOVE3_A:
		case MOVE4_A:
			pokemon = get_activepokemon(trainer);
			if (has_pp(pokemon)) {
				if (pokemon->pp[index] <= 0) {
					// printf("%s has no PP left for that move!", pokemon->species->name);
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
				// sprintf(msg, "%s has no will to fight!", pokemon->species->name); send();
				return false;
			}
			if (trainer->pokemon_active == index) {
				// sprintf(msg, "%s is already out!", pokemon->species->name); send();
				/*int i = 0;
				if (i) {
					sprintf(msg, "%s is already out!", pokemon->species->name); send();
				}*/
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
	display_pokemon();
	display_hp();
}

bool roll(double chance) {
	return rng() <= chance;
}

double rng() {
	return (double)(rand() % 100 + 1) / 100.0;
}

void display_pokemon() {
	char buff[64];

	sendText(11, PLAYER1_PNAME);
	sendText(12, PLAYER2_PNAME);

	get_spritepath(buff, PLAYER1_POKEMON, P1_P);
	sendCompressedSpriteFile(0, 2112, buff);

	get_spritepath(buff, PLAYER2_POKEMON, P2_P);
	sendCompressedSpriteFile(1, 2112, buff);
}

void close_menu() {
	updateMenuState(0, VGATURN);
}

void display_menu(menu_s *menu) {
	if (menu == &turn_menu) {
		close_menu();
	} else if (menu == &fight_menu) {
		updateMenuState(4, VGATURN);
	} else if (menu == &pkmn_menu || menu == &fpkmn_menu) {
		updateMenuState(2, VGATURN);
	} else if (menu == &run_menu) {
		updateMenuState(1, VGATURN);
	} else {
		close_menu();
	}
}

player_t get_pnum(trainer_s *trainer) {
	if (trainer == PLAYER1) {
		return P1_P;
	} else if (trainer == PLAYER2) {
		return P2_P;
	} else {
		return NON_P;
	}
}

void display_hp() {
	char b[BSIZE]; 

	int p1_hp_n = PLAYER1_POKEMON->nv.hp;
	int p1_hp_d = calc_hpmax(PLAYER1_POKEMON);
	int p1_hp = 100 * p1_hp_n / p1_hp_d;

	sprintf(b, "%i/%i  %s", p1_hp_n, p1_hp_d, get_statusname(PLAYER1_POKEMON->nv.nvstatus));
	sendText(7, b);

	int p2_hp_n = PLAYER2_POKEMON->nv.hp;
	int p2_hp_d = calc_hpmax(PLAYER2_POKEMON);
	int p2_hp = 100 * p2_hp_n / p2_hp_d;

	sprintf(b, "%i/%i  %s", p2_hp_n, p2_hp_d, get_statusname(PLAYER2_POKEMON->nv.nvstatus));
	sendText(8, b);	

	updateHealthBarImages(p1_hp, p2_hp);
}

void toUpper(char* str) {
	int i = 0;
	while (str[i]) {
		str[i] = toupper(str[i]);
		++i;
	}
}

void get_spritepath(char* buff, pokemon_s *pokemon, player_t player) {
	char b[64];
	strcpy(buff, "");
	strcpy(b, buff);
	char id[4];
	int i_id = pokemon->species->id;
	if (i_id < 10) {
		sprintf(id, "00%i", i_id);
	} else if (i_id < 100) {
		sprintf(id, "0%i", i_id);
	} else {
		sprintf(id, "%i", i_id);
	}
	strcpy(b, id);
	strcat(buff, id);
	strcpy(b, buff);
	strcpy(b, buff);
	if (player == P1_P) {
		strcat(buff, "_R");
	} else {
		strcat(buff, "_L");
	}
	strcpy(b, buff);
	noop();
	//strcat(buff, pokemon->species->name);
}

void noop() {
	// do nothing, this is used for breakpoint debugging
}

/*
void strpad(char *dest, char *src, int len) {
	strcpy(dest, src);
	int size = strlen(dest);
	for (; size < len; ++size) {
		dest[size] = ' ';
		++size;
	}
	dest[size] = '\0';
}
*/

void text_update(int i) {
	int starti = i * 80;
	int endi = (i + 1) * 80;
	char c = text[endi];
	text[endi] = '\0';
	char *txt = text;
	char *str = txt + starti;
	sendFullScreenMessage(i, str);
	text[endi] = c;
}

void text_clear() {
	if (text_count > 0) {
		strcpy(text, SPACE80);
		strcpy(text, "");
		int i;
		for (i = 0; i < 3; ++i) {
			text_update(i);
		}
		text_count = 0;
	}
}

void text_send(char *str) {
	noop();
	if (text_count >= 240) { // should never be > 240
		return;
	}

	int start_text_count = text_count;
	char *itr = str;
	MKDB;
	DB(str);

	/*while (*itr && text_count < 240) {
		char c = *itr;
		text[text_count] = c;
		++itr;
		++text_count;
	}
	text[text_count] = '\0';*/

	strcat(text, str);
	text_count = strlen(text);

	int i;
	// for (i = 0; i < 3; ++i) {
	for (i = start_text_count / 80; i <= text_count / 80; ++i) {
		text_update(i);
	}
}

void send() {
	strcat(msg, " "); // if msg is 240 chars long, this could cause problem, but they should never be that long
	text_send(msg);
}

#include "global-init.txt"