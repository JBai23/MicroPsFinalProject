#include "inputphase.h"

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
	pkmn_menu.option_count = 4;
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
	pkmn_menu.option_count = 1;
	strcpy(pkmn_menu.option_names[0], "Confirm");
	strcpy(pkmn_menu.option_names[1], "");
	strcpy(pkmn_menu.option_names[2], "");
	strcpy(pkmn_menu.option_names[3], "");
	strcpy(pkmn_menu.option_names[4], "");
	strcpy(pkmn_menu.option_names[5], "");
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
	fpkmn_menu.option_count = 4;
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