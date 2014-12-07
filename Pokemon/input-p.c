

#include "types.h"
#include "input-p.h"
#include "global.h"
#include <stdio.h>
#include <string.h>

action_t get_action(menu_s *menu) {
	while (true) {
		printf("1.%s\n2.%s\n3.%s\n4.%s\n5.%s\n6.%s\n", menu->option_names[0], menu->option_names[1], menu->option_names[2], menu->option_names[3], menu->option_names[4], menu->option_names[5]);

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

void input_phase() {
	
	battle.actions[p1_p] = get_action(&turn_menu);

	battle.actions[p2_p] = get_action(&turn_menu);
}