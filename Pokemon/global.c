
#include "gdefines.h"
#include "inputphase.h"
#include "battle.h"
#include "battlestate.h"
#include <string.h>
#include "global.h"

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

void init_battlestate() {
	
}