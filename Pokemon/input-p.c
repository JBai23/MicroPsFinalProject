

#include "types.h"
#include "input-p.h"
#include "global.h"
#include <stdio.h>
#include <string.h>

action_t get_action(menu_s *menu) {
	while (true) {
		printf("1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n6. %s\n", menu->option_names[0], menu->option_names[1], menu->option_names[2], menu->option_names[3], menu->option_names[4], menu->option_names[5]);

		input_t in = get_input();

		switch(in) {
			case BTN1_I:
			case BTN2_I:
			case BTN3_I:
			case BTN4_I:
			case BTN5_I:
			case BTN6_I:
				if (in < menu->option_count) {
					if (menu->action[in] != NON_A) {
						return menu->action[in];
					} else {
						if (menu->submenu[in]) {
							menu = menu->submenu[in];
						}
					}
				}
				break;
			case BTNB_I:
				if (menu->back) {
					menu = menu->back;
				}
				break;

			default:
				break;
		}
	}
}

input_t get_input() {
	while (true) {
		char c[32]; // don't overflow this

		printf(">> ");
		scanf("%s", c);

		switch (c[0]) {
			case '1':
				return BTN1_I;
			case '2':
				return BTN2_I;
			case '3':
				return BTN3_I;
			case '4':
				return BTN4_I;
			case '5':
				return BTN5_I;
			case '6':
				return BTN6_I;
			case 'B':
			case 'b':
				return BTNB_I;
			default:
				break;
		}
	}
}

// menu_s fight_menu;
// menu_s pkmn_menu; // switch
// menu_s fpkmn_menu; // forced switch

void set_menus(trainer_s *trainer) {
	// fight menu
	strcpy(fight_menu.option_names[0], trainer->pokemon[trainer->pokemon_active]->moves[0]->name);
	strcpy(fight_menu.option_names[1], trainer->pokemon[trainer->pokemon_active]->moves[1]->name);
	strcpy(fight_menu.option_names[2], trainer->pokemon[trainer->pokemon_active]->moves[2]->name);
	strcpy(fight_menu.option_names[3], trainer->pokemon[trainer->pokemon_active]->moves[3]->name);

	// pkmn menu
	strcpy(pkmn_menu.option_names[0], trainer->pokemon[0]->species->name);
	strcpy(pkmn_menu.option_names[1], trainer->pokemon[1]->species->name);
	strcpy(pkmn_menu.option_names[2], trainer->pokemon[2]->species->name);
	strcpy(pkmn_menu.option_names[3], trainer->pokemon[3]->species->name);
	strcpy(pkmn_menu.option_names[4], trainer->pokemon[4]->species->name);
	strcpy(pkmn_menu.option_names[5], trainer->pokemon[5]->species->name);

	// fpkmn menu
	strcpy(fpkmn_menu.option_names[0], trainer->pokemon[0]->species->name);
	strcpy(fpkmn_menu.option_names[1], trainer->pokemon[1]->species->name);
	strcpy(fpkmn_menu.option_names[2], trainer->pokemon[2]->species->name);
	strcpy(fpkmn_menu.option_names[3], trainer->pokemon[3]->species->name);
	strcpy(fpkmn_menu.option_names[4], trainer->pokemon[4]->species->name);
	strcpy(fpkmn_menu.option_names[5], trainer->pokemon[5]->species->name);
}

void input_phase() {
	printf("P1:%s's turn to input a move!\n", PLAYER1->name);
	set_menus(PLAYER1);
	PLAYER1_ACTION = get_action(&turn_menu);

	printf("P2:%s's turn to input a move!\n", PLAYER2->name);
	set_menus(PLAYER2);
	PLAYER2_ACTION = get_action(&turn_menu);
}