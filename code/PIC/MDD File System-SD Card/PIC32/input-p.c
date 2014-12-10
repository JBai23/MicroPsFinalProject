

#include "types.h"
#include "input-p.h"
#include "global.h"
#include "buttons.h"
#include <stdio.h>
#include <string.h>

action_t get_action(menu_s *menu) {
	while (true) {
		// printf("1. %s\n2. %s\n3. %s\n4. %s\n5. %s\n6. %s", menu->option_names[0], menu->option_names[1], menu->option_names[2], menu->option_names[3], menu->option_names[4], menu->option_names[5]);
		
		display_menu(menu);
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
		char c; // don't overflow this

		// printf(">> ");
		// scanf("%s", c);

		c = getButtonInput();
		switch (c) {
			case 1:
				return BTN1_I;
			case 2:
				return BTN2_I;
			case 3:
				return BTN3_I;
			case 4:
				return BTN4_I;
			case 5:
				return BTN5_I;
			case 6:
				return BTN6_I;
			case 13:
				return BTNB_I;
			default:
				break;
		}
	}
}

void set_menus(trainer_s *trainer) {
	input_player = trainer;
	close_menu();

	pokemon_s *pokemon = get_activepokemon(trainer);

	int pokemon_count = trainer->pokemon_count;
	int move_count = pokemon->move_count;
	int i;

	// fight menu
	for (i = 0; i < 4; ++i) {
		strcpy(fight_menu.option_names[i], (i < move_count ? pokemon->moves[i]->name : ""));
	}
	fight_menu.option_count = move_count;

	// pkmn & fpkmn menu
	for (i = 0; i < 6; ++i) {
		strcpy(pkmn_menu.option_names[i], (i < pokemon_count ? trainer->pokemon[i]->species->name : ""));
		strcpy(fpkmn_menu.option_names[i], (i < pokemon_count ? trainer->pokemon[i]->species->name : ""));
	}
	pkmn_menu.option_count = pokemon_count;
	fpkmn_menu.option_count = pokemon_count;

	// display vga
	// moves
	for (i = 0; i < 4; ++i) {
		if (i < move_count) {
			sendText(i, pokemon->moves[i]->name);
		} else {
			sendText(i, "");
		}
		
	}

	// pokemon
	char buff[BSIZE];
	for (i = 0; i < 6; ++i) {
		if (i < pokemon_count) {
			get_spritepath(buff, trainer->pokemon[i], get_pnum(trainer));
			sendCompressedSpriteFile(2 + i, 2112, buff);
		} else {
			sendCompressedSpriteFile(2 + i, 2112, "EmptySprite");
		}
	}
}

void input_phase() {
	set_menus(PLAYER1);
	do {
		// printf("%s's turn to input a move!", PLAYER1_NAME);
		PLAYER1_ACTION = get_action(&turn_menu);
	} while (!valid_action(PLAYER1));
	
	// printf("");

	set_menus(PLAYER2);
	do {
		// printf("%s's turn to input a move!", PLAYER2_NAME);
		PLAYER2_ACTION = get_action(&turn_menu);
	} while (!valid_action(PLAYER2));
}