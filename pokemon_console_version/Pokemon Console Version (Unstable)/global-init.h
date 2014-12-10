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
	strcpy(specs_all[0].name, "Bulbasaur");
	specs_all[0].id = 1;
	specs_all[0].type1 = GRASS_T;
	specs_all[0].type2 = POISON_T;
	specs_all[0].bstats.hp_base = 45;
	specs_all[0].bstats.attack_base = 49;
	specs_all[0].bstats.defense_base = 49;
	specs_all[0].bstats.sattack_base = 65;
	specs_all[0].bstats.sdefense_base = 65;
	specs_all[0].bstats.speed_base = 45;

	// ivysaur
	strcpy(specs_all[1].name, "Ivysaur");
	specs_all[1].id = 2;
	specs_all[1].type1 = GRASS_T;
	specs_all[1].type2 = POISON_T;
	specs_all[1].bstats.hp_base = 60;
	specs_all[1].bstats.attack_base = 62;
	specs_all[1].bstats.defense_base = 63;
	specs_all[1].bstats.sattack_base = 80;
	specs_all[1].bstats.sdefense_base = 80;
	specs_all[1].bstats.speed_base = 60;

	// venusaur
	strcpy(specs_all[2].name, "Venusaur");
	specs_all[2].id = 3;
	specs_all[2].type1 = GRASS_T;
	specs_all[2].type2 = POISON_T;
	specs_all[2].bstats.hp_base = 80;
	specs_all[2].bstats.attack_base = 82;
	specs_all[2].bstats.defense_base = 83;
	specs_all[2].bstats.sattack_base = 100;
	specs_all[2].bstats.sdefense_base = 100;
	specs_all[2].bstats.speed_base = 80;

	// charmander
	strcpy(specs_all[3].name, "Charmander");
	specs_all[3].id = 4;
	specs_all[3].type1 = FIRE_T;
	specs_all[3].type2 = NON_T;
	specs_all[3].bstats.hp_base = 39;
	specs_all[3].bstats.attack_base = 52;
	specs_all[3].bstats.defense_base = 43;
	specs_all[3].bstats.sattack_base = 60;
	specs_all[3].bstats.sdefense_base = 50;
	specs_all[3].bstats.speed_base = 65;

	// charmeleon
	strcpy(specs_all[4].name, "Charmeleon");
	specs_all[4].id = 5;
	specs_all[4].type1 = FIRE_T;
	specs_all[4].type2 = NON_T;
	specs_all[4].bstats.hp_base = 58;
	specs_all[4].bstats.attack_base = 64;
	specs_all[4].bstats.defense_base = 58;
	specs_all[4].bstats.sattack_base = 80;
	specs_all[4].bstats.sdefense_base = 65;
	specs_all[4].bstats.speed_base = 80;

	// charizard
	strcpy(specs_all[5].name, "Charizard");
	specs_all[5].id = 6;
	specs_all[5].type1 = FIRE_T;
	specs_all[5].type2 = FLYING_T;
	specs_all[5].bstats.hp_base = 78;
	specs_all[5].bstats.attack_base = 84;
	specs_all[5].bstats.defense_base = 78;
	specs_all[5].bstats.sattack_base = 109;
	specs_all[5].bstats.sdefense_base = 85;
	specs_all[5].bstats.speed_base = 100;

	// squirtle
	strcpy(specs_all[6].name, "Squirtle");
	specs_all[6].id = 7;
	specs_all[6].type1 = WATER_T;
	specs_all[6].type2 = NON_T;
	specs_all[6].bstats.hp_base = 44;
	specs_all[6].bstats.attack_base = 48;
	specs_all[6].bstats.defense_base = 65;
	specs_all[6].bstats.sattack_base = 50;
	specs_all[6].bstats.sdefense_base = 64;
	specs_all[6].bstats.speed_base = 43;

	// wartortle
	strcpy(specs_all[7].name, "Wartortle");
	specs_all[7].id = 8;
	specs_all[7].type1 = WATER_T;
	specs_all[7].type2 = NON_T;
	specs_all[7].bstats.hp_base = 59;
	specs_all[7].bstats.attack_base = 63;
	specs_all[7].bstats.defense_base = 80;
	specs_all[7].bstats.sattack_base = 65;
	specs_all[7].bstats.sdefense_base = 80;
	specs_all[7].bstats.speed_base = 58;

	// blastoise
	strcpy(specs_all[8].name, "Blastoise");
	specs_all[8].id = 9;
	specs_all[8].type1 = WATER_T;
	specs_all[8].type2 = NON_T;
	specs_all[8].bstats.hp_base = 79;
	specs_all[8].bstats.attack_base = 83;
	specs_all[8].bstats.defense_base = 100;
	specs_all[8].bstats.sattack_base = 85;
	specs_all[8].bstats.sdefense_base = 105;
	specs_all[8].bstats.speed_base = 78;

	// caterpie
	strcpy(specs_all[9].name, "Caterpie");
	specs_all[9].id = 10;
	specs_all[9].type1 = BUG_T;
	specs_all[9].type2 = NON_T;
	specs_all[9].bstats.hp_base = 45;
	specs_all[9].bstats.attack_base = 30;
	specs_all[9].bstats.defense_base = 35;
	specs_all[9].bstats.sattack_base = 20;
	specs_all[9].bstats.sdefense_base = 20;
	specs_all[9].bstats.speed_base = 45;

	// metapod
	strcpy(specs_all[10].name, "Metapod");
	specs_all[10].id = 11;
	specs_all[10].type1 = BUG_T;
	specs_all[10].type2 = NON_T;
	specs_all[10].bstats.hp_base = 50;
	specs_all[10].bstats.attack_base = 20;
	specs_all[10].bstats.defense_base = 55;
	specs_all[10].bstats.sattack_base = 25;
	specs_all[10].bstats.sdefense_base = 25;
	specs_all[10].bstats.speed_base = 30;

	// butterfree
	strcpy(specs_all[11].name, "Butterfree");
	specs_all[11].id = 12;
	specs_all[11].type1 = BUG_T;
	specs_all[11].type2 = FLYING_T;
	specs_all[11].bstats.hp_base = 60;
	specs_all[11].bstats.attack_base = 45;
	specs_all[11].bstats.defense_base = 50;
	specs_all[11].bstats.sattack_base = 90;
	specs_all[11].bstats.sdefense_base = 80;
	specs_all[11].bstats.speed_base = 70;

	// weedle
	strcpy(specs_all[12].name, "Weedle");
	specs_all[12].id = 13;
	specs_all[12].type1 = BUG_T;
	specs_all[12].type2 = POISON_T;
	specs_all[12].bstats.hp_base = 40;
	specs_all[12].bstats.attack_base = 35;
	specs_all[12].bstats.defense_base = 30;
	specs_all[12].bstats.sattack_base = 20;
	specs_all[12].bstats.sdefense_base = 20;
	specs_all[12].bstats.speed_base = 50;

	// kakuna
	strcpy(specs_all[13].name, "Kakuna");
	specs_all[13].id = 14;
	specs_all[13].type1 = BUG_T;
	specs_all[13].type2 = POISON_T;
	specs_all[13].bstats.hp_base = 45;
	specs_all[13].bstats.attack_base = 25;
	specs_all[13].bstats.defense_base = 50;
	specs_all[13].bstats.sattack_base = 25;
	specs_all[13].bstats.sdefense_base = 25;
	specs_all[13].bstats.speed_base = 35;

	// beedrill
	strcpy(specs_all[14].name, "Beedrill");
	specs_all[14].id = 15;
	specs_all[14].type1 = BUG_T;
	specs_all[14].type2 = POISON_T;
	specs_all[14].bstats.hp_base = 65;
	specs_all[14].bstats.attack_base = 90;
	specs_all[14].bstats.defense_base = 40;
	specs_all[14].bstats.sattack_base = 45;
	specs_all[14].bstats.sdefense_base = 80;
	specs_all[14].bstats.speed_base = 75;

	// pidgey
	strcpy(specs_all[15].name, "Pidgey");
	specs_all[15].id = 16;
	specs_all[15].type1 = NORMAL_T;
	specs_all[15].type2 = FLYING_T;
	specs_all[15].bstats.hp_base = 40;
	specs_all[15].bstats.attack_base = 45;
	specs_all[15].bstats.defense_base = 40;
	specs_all[15].bstats.sattack_base = 35;
	specs_all[15].bstats.sdefense_base = 35;
	specs_all[15].bstats.speed_base = 56;

	// pidgeotto
	strcpy(specs_all[16].name, "Pidgeotto");
	specs_all[16].id = 17;
	specs_all[16].type1 = NORMAL_T;
	specs_all[16].type2 = FLYING_T;
	specs_all[16].bstats.hp_base = 63;
	specs_all[16].bstats.attack_base = 60;
	specs_all[16].bstats.defense_base = 55;
	specs_all[16].bstats.sattack_base = 50;
	specs_all[16].bstats.sdefense_base = 50;
	specs_all[16].bstats.speed_base = 71;

	// pidgeot
	strcpy(specs_all[17].name, "Pidgeot");
	specs_all[17].id = 18;
	specs_all[17].type1 = NORMAL_T;
	specs_all[17].type2 = FLYING_T;
	specs_all[17].bstats.hp_base = 83;
	specs_all[17].bstats.attack_base = 80;
	specs_all[17].bstats.defense_base = 75;
	specs_all[17].bstats.sattack_base = 70;
	specs_all[17].bstats.sdefense_base = 70;
	specs_all[17].bstats.speed_base = 101;

	// rattata
	strcpy(specs_all[18].name, "Rattata");
	specs_all[18].id = 19;
	specs_all[18].type1 = NORMAL_T;
	specs_all[18].type2 = NON_T;
	specs_all[18].bstats.hp_base = 30;
	specs_all[18].bstats.attack_base = 56;
	specs_all[18].bstats.defense_base = 35;
	specs_all[18].bstats.sattack_base = 25;
	specs_all[18].bstats.sdefense_base = 35;
	specs_all[18].bstats.speed_base = 72;

	// raticate
	strcpy(specs_all[19].name, "Raticate");
	specs_all[19].id = 20;
	specs_all[19].type1 = NORMAL_T;
	specs_all[19].type2 = NON_T;
	specs_all[19].bstats.hp_base = 55;
	specs_all[19].bstats.attack_base = 81;
	specs_all[19].bstats.defense_base = 60;
	specs_all[19].bstats.sattack_base = 50;
	specs_all[19].bstats.sdefense_base = 70;
	specs_all[19].bstats.speed_base = 97;

	// spearow
	strcpy(specs_all[20].name, "Spearow");
	specs_all[20].id = 21;
	specs_all[20].type1 = NORMAL_T;
	specs_all[20].type2 = FLYING_T;
	specs_all[20].bstats.hp_base = 40;
	specs_all[20].bstats.attack_base = 60;
	specs_all[20].bstats.defense_base = 30;
	specs_all[20].bstats.sattack_base = 31;
	specs_all[20].bstats.sdefense_base = 31;
	specs_all[20].bstats.speed_base = 70;

	// fearow
	strcpy(specs_all[21].name, "Fearow");
	specs_all[21].id = 22;
	specs_all[21].type1 = NORMAL_T;
	specs_all[21].type2 = FLYING_T;
	specs_all[21].bstats.hp_base = 65;
	specs_all[21].bstats.attack_base = 90;
	specs_all[21].bstats.defense_base = 65;
	specs_all[21].bstats.sattack_base = 61;
	specs_all[21].bstats.sdefense_base = 61;
	specs_all[21].bstats.speed_base = 100;

	// ekans
	strcpy(specs_all[22].name, "Ekans");
	specs_all[22].id = 23;
	specs_all[22].type1 = POISON_T;
	specs_all[22].type2 = NON_T;
	specs_all[22].bstats.hp_base = 35;
	specs_all[22].bstats.attack_base = 60;
	specs_all[22].bstats.defense_base = 44;
	specs_all[22].bstats.sattack_base = 40;
	specs_all[22].bstats.sdefense_base = 54;
	specs_all[22].bstats.speed_base = 55;

	// arbok
	strcpy(specs_all[23].name, "Arbok");
	specs_all[23].id = 24;
	specs_all[23].type1 = POISON_T;
	specs_all[23].type2 = NON_T;
	specs_all[23].bstats.hp_base = 60;
	specs_all[23].bstats.attack_base = 85;
	specs_all[23].bstats.defense_base = 69;
	specs_all[23].bstats.sattack_base = 65;
	specs_all[23].bstats.sdefense_base = 79;
	specs_all[23].bstats.speed_base = 80;

	// pikachu
	strcpy(specs_all[24].name, "Pikachu");
	specs_all[24].id = 25;
	specs_all[24].type1 = ELECTRIC_T;
	specs_all[24].type2 = NON_T;
	specs_all[24].bstats.hp_base = 35;
	specs_all[24].bstats.attack_base = 55;
	specs_all[24].bstats.defense_base = 40;
	specs_all[24].bstats.sattack_base = 50;
	specs_all[24].bstats.sdefense_base = 50;
	specs_all[24].bstats.speed_base = 90;

	// raichu
	strcpy(specs_all[25].name, "Raichu");
	specs_all[25].id = 26;
	specs_all[25].type1 = ELECTRIC_T;
	specs_all[25].type2 = NON_T;
	specs_all[25].bstats.hp_base = 60;
	specs_all[25].bstats.attack_base = 90;
	specs_all[25].bstats.defense_base = 55;
	specs_all[25].bstats.sattack_base = 90;
	specs_all[25].bstats.sdefense_base = 80;
	specs_all[25].bstats.speed_base = 110;

	// sandshrew
	strcpy(specs_all[26].name, "Sandshrew");
	specs_all[26].id = 27;
	specs_all[26].type1 = GROUND_T;
	specs_all[26].type2 = NON_T;
	specs_all[26].bstats.hp_base = 50;
	specs_all[26].bstats.attack_base = 75;
	specs_all[26].bstats.defense_base = 85;
	specs_all[26].bstats.sattack_base = 20;
	specs_all[26].bstats.sdefense_base = 30;
	specs_all[26].bstats.speed_base = 40;

	// sandslash
	strcpy(specs_all[27].name, "Sandslash");
	specs_all[27].id = 28;
	specs_all[27].type1 = GROUND_T;
	specs_all[27].type2 = NON_T;
	specs_all[27].bstats.hp_base = 75;
	specs_all[27].bstats.attack_base = 100;
	specs_all[27].bstats.defense_base = 110;
	specs_all[27].bstats.sattack_base = 45;
	specs_all[27].bstats.sdefense_base = 55;
	specs_all[27].bstats.speed_base = 65;

	// nidoran_f
	strcpy(specs_all[28].name, "Nidoran (F)");
	specs_all[28].id = 29;
	specs_all[28].type1 = POISON_T;
	specs_all[28].type2 = NON_T;
	specs_all[28].bstats.hp_base = 55;
	specs_all[28].bstats.attack_base = 47;
	specs_all[28].bstats.defense_base = 52;
	specs_all[28].bstats.sattack_base = 40;
	specs_all[28].bstats.sdefense_base = 40;
	specs_all[28].bstats.speed_base = 41;

	// nidorina
	strcpy(specs_all[29].name, "Nidorina");
	specs_all[29].id = 30;
	specs_all[29].type1 = POISON_T;
	specs_all[29].type2 = NON_T;
	specs_all[29].bstats.hp_base = 70;
	specs_all[29].bstats.attack_base = 62;
	specs_all[29].bstats.defense_base = 67;
	specs_all[29].bstats.sattack_base = 55;
	specs_all[29].bstats.sdefense_base = 55;
	specs_all[29].bstats.speed_base = 56;

	// nidoqueen
	strcpy(specs_all[30].name, "Nidoqueen");
	specs_all[30].id = 31;
	specs_all[30].type1 = POISON_T;
	specs_all[30].type2 = GROUND_T;
	specs_all[30].bstats.hp_base = 90;
	specs_all[30].bstats.attack_base = 92;
	specs_all[30].bstats.defense_base = 87;
	specs_all[30].bstats.sattack_base = 75;
	specs_all[30].bstats.sdefense_base = 85;
	specs_all[30].bstats.speed_base = 76;

	// nidoran_m
	strcpy(specs_all[31].name, "Nidoran (M)");
	specs_all[31].id = 32;
	specs_all[31].type1 = POISON_T;
	specs_all[31].type2 = NON_T;
	specs_all[31].bstats.hp_base = 46;
	specs_all[31].bstats.attack_base = 57;
	specs_all[31].bstats.defense_base = 40;
	specs_all[31].bstats.sattack_base = 40;
	specs_all[31].bstats.sdefense_base = 40;
	specs_all[31].bstats.speed_base = 50;

	// nidorino
	strcpy(specs_all[32].name, "Nidorino");
	specs_all[32].id = 33;
	specs_all[32].type1 = POISON_T;
	specs_all[32].type2 = NON_T;
	specs_all[32].bstats.hp_base = 61;
	specs_all[32].bstats.attack_base = 72;
	specs_all[32].bstats.defense_base = 57;
	specs_all[32].bstats.sattack_base = 55;
	specs_all[32].bstats.sdefense_base = 55;
	specs_all[32].bstats.speed_base = 65;

	// nidoking
	strcpy(specs_all[33].name, "Nidoking");
	specs_all[33].id = 34;
	specs_all[33].type1 = POISON_T;
	specs_all[33].type2 = GROUND_T;
	specs_all[33].bstats.hp_base = 81;
	specs_all[33].bstats.attack_base = 102;
	specs_all[33].bstats.defense_base = 77;
	specs_all[33].bstats.sattack_base = 85;
	specs_all[33].bstats.sdefense_base = 75;
	specs_all[33].bstats.speed_base = 85;

	// clefairy
	strcpy(specs_all[34].name, "Clefairy");
	specs_all[34].id = 35;
	specs_all[34].type1 = FAIRY_T;
	specs_all[34].type2 = NON_T;
	specs_all[34].bstats.hp_base = 70;
	specs_all[34].bstats.attack_base = 45;
	specs_all[34].bstats.defense_base = 48;
	specs_all[34].bstats.sattack_base = 60;
	specs_all[34].bstats.sdefense_base = 65;
	specs_all[34].bstats.speed_base = 35;

	// clefable
	strcpy(specs_all[35].name, "Clefable");
	specs_all[35].id = 36;
	specs_all[35].type1 = FAIRY_T;
	specs_all[35].type2 = NON_T;
	specs_all[35].bstats.hp_base = 95;
	specs_all[35].bstats.attack_base = 70;
	specs_all[35].bstats.defense_base = 73;
	specs_all[35].bstats.sattack_base = 95;
	specs_all[35].bstats.sdefense_base = 90;
	specs_all[35].bstats.speed_base = 60;

	// vulpix
	strcpy(specs_all[36].name, "Vulpix");
	specs_all[36].id = 37;
	specs_all[36].type1 = FIRE_T;
	specs_all[36].type2 = NON_T;
	specs_all[36].bstats.hp_base = 38;
	specs_all[36].bstats.attack_base = 41;
	specs_all[36].bstats.defense_base = 40;
	specs_all[36].bstats.sattack_base = 50;
	specs_all[36].bstats.sdefense_base = 65;
	specs_all[36].bstats.speed_base = 65;

	// ninetales
	strcpy(specs_all[37].name, "Ninetales");
	specs_all[37].id = 38;
	specs_all[37].type1 = FIRE_T;
	specs_all[37].type2 = NON_T;
	specs_all[37].bstats.hp_base = 73;
	specs_all[37].bstats.attack_base = 76;
	specs_all[37].bstats.defense_base = 75;
	specs_all[37].bstats.sattack_base = 81;
	specs_all[37].bstats.sdefense_base = 100;
	specs_all[37].bstats.speed_base = 100;

	// jigglypuff
	strcpy(specs_all[38].name, "Jigglypuff");
	specs_all[38].id = 39;
	specs_all[38].type1 = NORMAL_T;
	specs_all[38].type2 = FAIRY_T;
	specs_all[38].bstats.hp_base = 115;
	specs_all[38].bstats.attack_base = 45;
	specs_all[38].bstats.defense_base = 20;
	specs_all[38].bstats.sattack_base = 45;
	specs_all[38].bstats.sdefense_base = 25;
	specs_all[38].bstats.speed_base = 20;

	// wigglytuff
	strcpy(specs_all[39].name, "Wigglytuff");
	specs_all[39].id = 40;
	specs_all[39].type1 = NORMAL_T;
	specs_all[39].type2 = FAIRY_T;
	specs_all[39].bstats.hp_base = 140;
	specs_all[39].bstats.attack_base = 70;
	specs_all[39].bstats.defense_base = 45;
	specs_all[39].bstats.sattack_base = 85;
	specs_all[39].bstats.sdefense_base = 50;
	specs_all[39].bstats.speed_base = 45;

	// zubat
	strcpy(specs_all[40].name, "Zubat");
	specs_all[40].id = 41;
	specs_all[40].type1 = POISON_T;
	specs_all[40].type2 = FLYING_T;
	specs_all[40].bstats.hp_base = 40;
	specs_all[40].bstats.attack_base = 45;
	specs_all[40].bstats.defense_base = 35;
	specs_all[40].bstats.sattack_base = 30;
	specs_all[40].bstats.sdefense_base = 40;
	specs_all[40].bstats.speed_base = 55;

	// golbat
	strcpy(specs_all[41].name, "Golbat");
	specs_all[41].id = 42;
	specs_all[41].type1 = POISON_T;
	specs_all[41].type2 = FLYING_T;
	specs_all[41].bstats.hp_base = 75;
	specs_all[41].bstats.attack_base = 80;
	specs_all[41].bstats.defense_base = 70;
	specs_all[41].bstats.sattack_base = 65;
	specs_all[41].bstats.sdefense_base = 75;
	specs_all[41].bstats.speed_base = 90;

	// oddish
	strcpy(specs_all[42].name, "Oddish");
	specs_all[42].id = 43;
	specs_all[42].type1 = GRASS_T;
	specs_all[42].type2 = POISON_T;
	specs_all[42].bstats.hp_base = 45;
	specs_all[42].bstats.attack_base = 50;
	specs_all[42].bstats.defense_base = 55;
	specs_all[42].bstats.sattack_base = 75;
	specs_all[42].bstats.sdefense_base = 65;
	specs_all[42].bstats.speed_base = 30;

	// gloom
	strcpy(specs_all[43].name, "Gloom");
	specs_all[43].id = 44;
	specs_all[43].type1 = GRASS_T;
	specs_all[43].type2 = POISON_T;
	specs_all[43].bstats.hp_base = 60;
	specs_all[43].bstats.attack_base = 65;
	specs_all[43].bstats.defense_base = 70;
	specs_all[43].bstats.sattack_base = 85;
	specs_all[43].bstats.sdefense_base = 75;
	specs_all[43].bstats.speed_base = 40;

	// vileplume
	strcpy(specs_all[44].name, "Vileplume");
	specs_all[44].id = 45;
	specs_all[44].type1 = GRASS_T;
	specs_all[44].type2 = POISON_T;
	specs_all[44].bstats.hp_base = 75;
	specs_all[44].bstats.attack_base = 80;
	specs_all[44].bstats.defense_base = 85;
	specs_all[44].bstats.sattack_base = 110;
	specs_all[44].bstats.sdefense_base = 90;
	specs_all[44].bstats.speed_base = 50;

	// paras
	strcpy(specs_all[45].name, "Paras");
	specs_all[45].id = 46;
	specs_all[45].type1 = BUG_T;
	specs_all[45].type2 = GRASS_T;
	specs_all[45].bstats.hp_base = 35;
	specs_all[45].bstats.attack_base = 70;
	specs_all[45].bstats.defense_base = 55;
	specs_all[45].bstats.sattack_base = 45;
	specs_all[45].bstats.sdefense_base = 55;
	specs_all[45].bstats.speed_base = 25;

	// parasect
	strcpy(specs_all[46].name, "Parasect");
	specs_all[46].id = 47;
	specs_all[46].type1 = BUG_T;
	specs_all[46].type2 = GRASS_T;
	specs_all[46].bstats.hp_base = 60;
	specs_all[46].bstats.attack_base = 95;
	specs_all[46].bstats.defense_base = 80;
	specs_all[46].bstats.sattack_base = 60;
	specs_all[46].bstats.sdefense_base = 80;
	specs_all[46].bstats.speed_base = 30;

	// venonat
	strcpy(specs_all[47].name, "Venonat");
	specs_all[47].id = 48;
	specs_all[47].type1 = BUG_T;
	specs_all[47].type2 = POISON_T;
	specs_all[47].bstats.hp_base = 60;
	specs_all[47].bstats.attack_base = 55;
	specs_all[47].bstats.defense_base = 50;
	specs_all[47].bstats.sattack_base = 40;
	specs_all[47].bstats.sdefense_base = 55;
	specs_all[47].bstats.speed_base = 45;

	// venomoth
	strcpy(specs_all[48].name, "Venomoth");
	specs_all[48].id = 49;
	specs_all[48].type1 = BUG_T;
	specs_all[48].type2 = POISON_T;
	specs_all[48].bstats.hp_base = 70;
	specs_all[48].bstats.attack_base = 65;
	specs_all[48].bstats.defense_base = 60;
	specs_all[48].bstats.sattack_base = 90;
	specs_all[48].bstats.sdefense_base = 75;
	specs_all[48].bstats.speed_base = 90;

	// diglett
	strcpy(specs_all[49].name, "Diglett");
	specs_all[49].id = 50;
	specs_all[49].type1 = GROUND_T;
	specs_all[49].type2 = NON_T;
	specs_all[49].bstats.hp_base = 10;
	specs_all[49].bstats.attack_base = 55;
	specs_all[49].bstats.defense_base = 25;
	specs_all[49].bstats.sattack_base = 35;
	specs_all[49].bstats.sdefense_base = 45;
	specs_all[49].bstats.speed_base = 95;

	// dugtrio
	strcpy(specs_all[50].name, "Dugtrio");
	specs_all[50].id = 51;
	specs_all[50].type1 = GROUND_T;
	specs_all[50].type2 = NON_T;
	specs_all[50].bstats.hp_base = 35;
	specs_all[50].bstats.attack_base = 80;
	specs_all[50].bstats.defense_base = 50;
	specs_all[50].bstats.sattack_base = 50;
	specs_all[50].bstats.sdefense_base = 70;
	specs_all[50].bstats.speed_base = 120;

	// meowth
	strcpy(specs_all[51].name, "Meowth");
	specs_all[51].id = 52;
	specs_all[51].type1 = NORMAL_T;
	specs_all[51].type2 = NON_T;
	specs_all[51].bstats.hp_base = 40;
	specs_all[51].bstats.attack_base = 45;
	specs_all[51].bstats.defense_base = 35;
	specs_all[51].bstats.sattack_base = 40;
	specs_all[51].bstats.sdefense_base = 40;
	specs_all[51].bstats.speed_base = 90;

	// persian
	strcpy(specs_all[52].name, "Persian");
	specs_all[52].id = 53;
	specs_all[52].type1 = NORMAL_T;
	specs_all[52].type2 = NON_T;
	specs_all[52].bstats.hp_base = 65;
	specs_all[52].bstats.attack_base = 70;
	specs_all[52].bstats.defense_base = 60;
	specs_all[52].bstats.sattack_base = 65;
	specs_all[52].bstats.sdefense_base = 65;
	specs_all[52].bstats.speed_base = 115;

	// psyduck
	strcpy(specs_all[53].name, "Psyduck");
	specs_all[53].id = 54;
	specs_all[53].type1 = WATER_T;
	specs_all[53].type2 = NON_T;
	specs_all[53].bstats.hp_base = 50;
	specs_all[53].bstats.attack_base = 52;
	specs_all[53].bstats.defense_base = 48;
	specs_all[53].bstats.sattack_base = 65;
	specs_all[53].bstats.sdefense_base = 50;
	specs_all[53].bstats.speed_base = 55;

	// golduck
	strcpy(specs_all[54].name, "Golduck");
	specs_all[54].id = 55;
	specs_all[54].type1 = WATER_T;
	specs_all[54].type2 = NON_T;
	specs_all[54].bstats.hp_base = 80;
	specs_all[54].bstats.attack_base = 82;
	specs_all[54].bstats.defense_base = 78;
	specs_all[54].bstats.sattack_base = 95;
	specs_all[54].bstats.sdefense_base = 80;
	specs_all[54].bstats.speed_base = 85;

	// mankey
	strcpy(specs_all[55].name, "Mankey");
	specs_all[55].id = 56;
	specs_all[55].type1 = FIGHTING_T;
	specs_all[55].type2 = NON_T;
	specs_all[55].bstats.hp_base = 40;
	specs_all[55].bstats.attack_base = 80;
	specs_all[55].bstats.defense_base = 35;
	specs_all[55].bstats.sattack_base = 35;
	specs_all[55].bstats.sdefense_base = 45;
	specs_all[55].bstats.speed_base = 70;

	// primeape
	strcpy(specs_all[56].name, "Primeape");
	specs_all[56].id = 57;
	specs_all[56].type1 = FIGHTING_T;
	specs_all[56].type2 = NON_T;
	specs_all[56].bstats.hp_base = 65;
	specs_all[56].bstats.attack_base = 105;
	specs_all[56].bstats.defense_base = 60;
	specs_all[56].bstats.sattack_base = 60;
	specs_all[56].bstats.sdefense_base = 70;
	specs_all[56].bstats.speed_base = 95;

	// growlithe
	strcpy(specs_all[57].name, "Growlithe");
	specs_all[57].id = 58;
	specs_all[57].type1 = FIRE_T;
	specs_all[57].type2 = NON_T;
	specs_all[57].bstats.hp_base = 55;
	specs_all[57].bstats.attack_base = 70;
	specs_all[57].bstats.defense_base = 45;
	specs_all[57].bstats.sattack_base = 70;
	specs_all[57].bstats.sdefense_base = 50;
	specs_all[57].bstats.speed_base = 60;

	// arcanine
	strcpy(specs_all[58].name, "Arcanine");
	specs_all[58].id = 59;
	specs_all[58].type1 = FIRE_T;
	specs_all[58].type2 = NON_T;
	specs_all[58].bstats.hp_base = 90;
	specs_all[58].bstats.attack_base = 110;
	specs_all[58].bstats.defense_base = 80;
	specs_all[58].bstats.sattack_base = 100;
	specs_all[58].bstats.sdefense_base = 80;
	specs_all[58].bstats.speed_base = 95;

	// poliwag
	strcpy(specs_all[59].name, "Poliwag");
	specs_all[59].id = 60;
	specs_all[59].type1 = WATER_T;
	specs_all[59].type2 = NON_T;
	specs_all[59].bstats.hp_base = 40;
	specs_all[59].bstats.attack_base = 50;
	specs_all[59].bstats.defense_base = 40;
	specs_all[59].bstats.sattack_base = 40;
	specs_all[59].bstats.sdefense_base = 40;
	specs_all[59].bstats.speed_base = 90;

	// poliwhirl
	strcpy(specs_all[60].name, "Poliwhirl");
	specs_all[60].id = 61;
	specs_all[60].type1 = WATER_T;
	specs_all[60].type2 = NON_T;
	specs_all[60].bstats.hp_base = 65;
	specs_all[60].bstats.attack_base = 65;
	specs_all[60].bstats.defense_base = 65;
	specs_all[60].bstats.sattack_base = 50;
	specs_all[60].bstats.sdefense_base = 50;
	specs_all[60].bstats.speed_base = 90;

	// poliwrath
	strcpy(specs_all[61].name, "Poliwrath");
	specs_all[61].id = 62;
	specs_all[61].type1 = WATER_T;
	specs_all[61].type2 = FIGHTING_T;
	specs_all[61].bstats.hp_base = 90;
	specs_all[61].bstats.attack_base = 95;
	specs_all[61].bstats.defense_base = 95;
	specs_all[61].bstats.sattack_base = 70;
	specs_all[61].bstats.sdefense_base = 90;
	specs_all[61].bstats.speed_base = 70;

	// abra
	strcpy(specs_all[62].name, "Abra");
	specs_all[62].id = 63;
	specs_all[62].type1 = PSYCHIC_T;
	specs_all[62].type2 = NON_T;
	specs_all[62].bstats.hp_base = 25;
	specs_all[62].bstats.attack_base = 20;
	specs_all[62].bstats.defense_base = 15;
	specs_all[62].bstats.sattack_base = 105;
	specs_all[62].bstats.sdefense_base = 55;
	specs_all[62].bstats.speed_base = 90;

	// kadabra
	strcpy(specs_all[63].name, "Kadabra");
	specs_all[63].id = 64;
	specs_all[63].type1 = PSYCHIC_T;
	specs_all[63].type2 = NON_T;
	specs_all[63].bstats.hp_base = 40;
	specs_all[63].bstats.attack_base = 35;
	specs_all[63].bstats.defense_base = 30;
	specs_all[63].bstats.sattack_base = 120;
	specs_all[63].bstats.sdefense_base = 70;
	specs_all[63].bstats.speed_base = 105;

	// alakazam
	strcpy(specs_all[64].name, "Alakazam");
	specs_all[64].id = 65;
	specs_all[64].type1 = PSYCHIC_T;
	specs_all[64].type2 = NON_T;
	specs_all[64].bstats.hp_base = 55;
	specs_all[64].bstats.attack_base = 50;
	specs_all[64].bstats.defense_base = 45;
	specs_all[64].bstats.sattack_base = 135;
	specs_all[64].bstats.sdefense_base = 95;
	specs_all[64].bstats.speed_base = 120;

	// machop
	strcpy(specs_all[65].name, "Machop");
	specs_all[65].id = 66;
	specs_all[65].type1 = FIGHTING_T;
	specs_all[65].type2 = NON_T;
	specs_all[65].bstats.hp_base = 70;
	specs_all[65].bstats.attack_base = 80;
	specs_all[65].bstats.defense_base = 50;
	specs_all[65].bstats.sattack_base = 35;
	specs_all[65].bstats.sdefense_base = 35;
	specs_all[65].bstats.speed_base = 35;

	// machoke
	strcpy(specs_all[66].name, "Machoke");
	specs_all[66].id = 67;
	specs_all[66].type1 = FIGHTING_T;
	specs_all[66].type2 = NON_T;
	specs_all[66].bstats.hp_base = 80;
	specs_all[66].bstats.attack_base = 100;
	specs_all[66].bstats.defense_base = 70;
	specs_all[66].bstats.sattack_base = 50;
	specs_all[66].bstats.sdefense_base = 60;
	specs_all[66].bstats.speed_base = 45;

	// machamp
	strcpy(specs_all[67].name, "Machamp");
	specs_all[67].id = 68;
	specs_all[67].type1 = FIGHTING_T;
	specs_all[67].type2 = NON_T;
	specs_all[67].bstats.hp_base = 90;
	specs_all[67].bstats.attack_base = 130;
	specs_all[67].bstats.defense_base = 80;
	specs_all[67].bstats.sattack_base = 65;
	specs_all[67].bstats.sdefense_base = 85;
	specs_all[67].bstats.speed_base = 55;

	// bellsprout
	strcpy(specs_all[68].name, "Bellsprout");
	specs_all[68].id = 69;
	specs_all[68].type1 = GRASS_T;
	specs_all[68].type2 = POISON_T;
	specs_all[68].bstats.hp_base = 50;
	specs_all[68].bstats.attack_base = 75;
	specs_all[68].bstats.defense_base = 35;
	specs_all[68].bstats.sattack_base = 70;
	specs_all[68].bstats.sdefense_base = 30;
	specs_all[68].bstats.speed_base = 40;

	// weepinbell
	strcpy(specs_all[69].name, "Weepinbell");
	specs_all[69].id = 70;
	specs_all[69].type1 = GRASS_T;
	specs_all[69].type2 = POISON_T;
	specs_all[69].bstats.hp_base = 65;
	specs_all[69].bstats.attack_base = 90;
	specs_all[69].bstats.defense_base = 50;
	specs_all[69].bstats.sattack_base = 85;
	specs_all[69].bstats.sdefense_base = 45;
	specs_all[69].bstats.speed_base = 55;

	// victreebel
	strcpy(specs_all[70].name, "Victreebel");
	specs_all[70].id = 71;
	specs_all[70].type1 = GRASS_T;
	specs_all[70].type2 = POISON_T;
	specs_all[70].bstats.hp_base = 80;
	specs_all[70].bstats.attack_base = 105;
	specs_all[70].bstats.defense_base = 65;
	specs_all[70].bstats.sattack_base = 100;
	specs_all[70].bstats.sdefense_base = 70;
	specs_all[70].bstats.speed_base = 70;

	// tentacool
	strcpy(specs_all[71].name, "Tentacool");
	specs_all[71].id = 72;
	specs_all[71].type1 = WATER_T;
	specs_all[71].type2 = POISON_T;
	specs_all[71].bstats.hp_base = 40;
	specs_all[71].bstats.attack_base = 40;
	specs_all[71].bstats.defense_base = 35;
	specs_all[71].bstats.sattack_base = 50;
	specs_all[71].bstats.sdefense_base = 100;
	specs_all[71].bstats.speed_base = 70;

	// tentacruel
	strcpy(specs_all[72].name, "Tentacruel");
	specs_all[72].id = 73;
	specs_all[72].type1 = WATER_T;
	specs_all[72].type2 = POISON_T;
	specs_all[72].bstats.hp_base = 80;
	specs_all[72].bstats.attack_base = 70;
	specs_all[72].bstats.defense_base = 65;
	specs_all[72].bstats.sattack_base = 80;
	specs_all[72].bstats.sdefense_base = 120;
	specs_all[72].bstats.speed_base = 100;

	// geodude
	strcpy(specs_all[73].name, "Geodude");
	specs_all[73].id = 74;
	specs_all[73].type1 = ROCK_T;
	specs_all[73].type2 = GROUND_T;
	specs_all[73].bstats.hp_base = 40;
	specs_all[73].bstats.attack_base = 80;
	specs_all[73].bstats.defense_base = 100;
	specs_all[73].bstats.sattack_base = 30;
	specs_all[73].bstats.sdefense_base = 30;
	specs_all[73].bstats.speed_base = 20;

	// graveler
	strcpy(specs_all[74].name, "Graveler");
	specs_all[74].id = 75;
	specs_all[74].type1 = ROCK_T;
	specs_all[74].type2 = GROUND_T;
	specs_all[74].bstats.hp_base = 55;
	specs_all[74].bstats.attack_base = 95;
	specs_all[74].bstats.defense_base = 115;
	specs_all[74].bstats.sattack_base = 45;
	specs_all[74].bstats.sdefense_base = 45;
	specs_all[74].bstats.speed_base = 35;

	// golem
	strcpy(specs_all[75].name, "Golem");
	specs_all[75].id = 76;
	specs_all[75].type1 = ROCK_T;
	specs_all[75].type2 = GROUND_T;
	specs_all[75].bstats.hp_base = 80;
	specs_all[75].bstats.attack_base = 120;
	specs_all[75].bstats.defense_base = 130;
	specs_all[75].bstats.sattack_base = 55;
	specs_all[75].bstats.sdefense_base = 65;
	specs_all[75].bstats.speed_base = 45;

	// ponyta
	strcpy(specs_all[76].name, "Ponyta");
	specs_all[76].id = 77;
	specs_all[76].type1 = FIRE_T;
	specs_all[76].type2 = NON_T;
	specs_all[76].bstats.hp_base = 50;
	specs_all[76].bstats.attack_base = 85;
	specs_all[76].bstats.defense_base = 55;
	specs_all[76].bstats.sattack_base = 65;
	specs_all[76].bstats.sdefense_base = 65;
	specs_all[76].bstats.speed_base = 90;

	// rapidash
	strcpy(specs_all[77].name, "Rapidash");
	specs_all[77].id = 78;
	specs_all[77].type1 = FIRE_T;
	specs_all[77].type2 = NON_T;
	specs_all[77].bstats.hp_base = 65;
	specs_all[77].bstats.attack_base = 100;
	specs_all[77].bstats.defense_base = 70;
	specs_all[77].bstats.sattack_base = 80;
	specs_all[77].bstats.sdefense_base = 80;
	specs_all[77].bstats.speed_base = 105;

	// slowpoke
	strcpy(specs_all[78].name, "Slowpoke");
	specs_all[78].id = 79;
	specs_all[78].type1 = WATER_T;
	specs_all[78].type2 = PSYCHIC_T;
	specs_all[78].bstats.hp_base = 90;
	specs_all[78].bstats.attack_base = 65;
	specs_all[78].bstats.defense_base = 65;
	specs_all[78].bstats.sattack_base = 40;
	specs_all[78].bstats.sdefense_base = 40;
	specs_all[78].bstats.speed_base = 15;

	// slowbro
	strcpy(specs_all[79].name, "Slowbro");
	specs_all[79].id = 80;
	specs_all[79].type1 = WATER_T;
	specs_all[79].type2 = PSYCHIC_T;
	specs_all[79].bstats.hp_base = 95;
	specs_all[79].bstats.attack_base = 75;
	specs_all[79].bstats.defense_base = 110;
	specs_all[79].bstats.sattack_base = 100;
	specs_all[79].bstats.sdefense_base = 80;
	specs_all[79].bstats.speed_base = 30;

	// magnemite
	strcpy(specs_all[80].name, "Magnemite");
	specs_all[80].id = 81;
	specs_all[80].type1 = ELECTRIC_T;
	specs_all[80].type2 = STEEL_T;
	specs_all[80].bstats.hp_base = 25;
	specs_all[80].bstats.attack_base = 35;
	specs_all[80].bstats.defense_base = 70;
	specs_all[80].bstats.sattack_base = 95;
	specs_all[80].bstats.sdefense_base = 55;
	specs_all[80].bstats.speed_base = 45;

	// magneton
	strcpy(specs_all[81].name, "Magneton");
	specs_all[81].id = 82;
	specs_all[81].type1 = ELECTRIC_T;
	specs_all[81].type2 = STEEL_T;
	specs_all[81].bstats.hp_base = 50;
	specs_all[81].bstats.attack_base = 60;
	specs_all[81].bstats.defense_base = 95;
	specs_all[81].bstats.sattack_base = 120;
	specs_all[81].bstats.sdefense_base = 70;
	specs_all[81].bstats.speed_base = 70;

	// farfetch'd
	strcpy(specs_all[82].name, "Farfetch'd");
	specs_all[82].id = 83;
	specs_all[82].type1 = NORMAL_T;
	specs_all[82].type2 = FLYING_T;
	specs_all[82].bstats.hp_base = 52;
	specs_all[82].bstats.attack_base = 65;
	specs_all[82].bstats.defense_base = 55;
	specs_all[82].bstats.sattack_base = 58;
	specs_all[82].bstats.sdefense_base = 62;
	specs_all[82].bstats.speed_base = 60;

	// doduo
	strcpy(specs_all[83].name, "Doduo");
	specs_all[83].id = 84;
	specs_all[83].type1 = NORMAL_T;
	specs_all[83].type2 = FLYING_T;
	specs_all[83].bstats.hp_base = 35;
	specs_all[83].bstats.attack_base = 85;
	specs_all[83].bstats.defense_base = 45;
	specs_all[83].bstats.sattack_base = 35;
	specs_all[83].bstats.sdefense_base = 35;
	specs_all[83].bstats.speed_base = 75;

	// dodrio
	strcpy(specs_all[84].name, "Dodrio");
	specs_all[84].id = 85;
	specs_all[84].type1 = NORMAL_T;
	specs_all[84].type2 = FLYING_T;
	specs_all[84].bstats.hp_base = 60;
	specs_all[84].bstats.attack_base = 110;
	specs_all[84].bstats.defense_base = 70;
	specs_all[84].bstats.sattack_base = 60;
	specs_all[84].bstats.sdefense_base = 60;
	specs_all[84].bstats.speed_base = 100;

	// seel
	strcpy(specs_all[85].name, "Seel");
	specs_all[85].id = 86;
	specs_all[85].type1 = WATER_T;
	specs_all[85].type2 = NON_T;
	specs_all[85].bstats.hp_base = 65;
	specs_all[85].bstats.attack_base = 45;
	specs_all[85].bstats.defense_base = 55;
	specs_all[85].bstats.sattack_base = 45;
	specs_all[85].bstats.sdefense_base = 70;
	specs_all[85].bstats.speed_base = 45;

	// dewgong
	strcpy(specs_all[86].name, "Dewgong");
	specs_all[86].id = 87;
	specs_all[86].type1 = WATER_T;
	specs_all[86].type2 = ICE_T;
	specs_all[86].bstats.hp_base = 90;
	specs_all[86].bstats.attack_base = 70;
	specs_all[86].bstats.defense_base = 80;
	specs_all[86].bstats.sattack_base = 70;
	specs_all[86].bstats.sdefense_base = 95;
	specs_all[86].bstats.speed_base = 70;

	// grimer
	strcpy(specs_all[87].name, "Grimer");
	specs_all[87].id = 88;
	specs_all[87].type1 = POISON_T;
	specs_all[87].type2 = NON_T;
	specs_all[87].bstats.hp_base = 80;
	specs_all[87].bstats.attack_base = 80;
	specs_all[87].bstats.defense_base = 50;
	specs_all[87].bstats.sattack_base = 40;
	specs_all[87].bstats.sdefense_base = 50;
	specs_all[87].bstats.speed_base = 25;

	// muk
	strcpy(specs_all[88].name, "Muk");
	specs_all[88].id = 89;
	specs_all[88].type1 = POISON_T;
	specs_all[88].type2 = NON_T;
	specs_all[88].bstats.hp_base = 105;
	specs_all[88].bstats.attack_base = 105;
	specs_all[88].bstats.defense_base = 75;
	specs_all[88].bstats.sattack_base = 65;
	specs_all[88].bstats.sdefense_base = 100;
	specs_all[88].bstats.speed_base = 50;

	// shellder
	strcpy(specs_all[89].name, "Shellder");
	specs_all[89].id = 90;
	specs_all[89].type1 = WATER_T;
	specs_all[89].type2 = NON_T;
	specs_all[89].bstats.hp_base = 30;
	specs_all[89].bstats.attack_base = 65;
	specs_all[89].bstats.defense_base = 100;
	specs_all[89].bstats.sattack_base = 45;
	specs_all[89].bstats.sdefense_base = 25;
	specs_all[89].bstats.speed_base = 40;

	// cloyster
	strcpy(specs_all[90].name, "Cloyster");
	specs_all[90].id = 91;
	specs_all[90].type1 = WATER_T;
	specs_all[90].type2 = ICE_T;
	specs_all[90].bstats.hp_base = 50;
	specs_all[90].bstats.attack_base = 95;
	specs_all[90].bstats.defense_base = 180;
	specs_all[90].bstats.sattack_base = 85;
	specs_all[90].bstats.sdefense_base = 45;
	specs_all[90].bstats.speed_base = 70;

	// gastly
	strcpy(specs_all[91].name, "Gastly");
	specs_all[91].id = 92;
	specs_all[91].type1 = GHOST_T;
	specs_all[91].type2 = POISON_T;
	specs_all[91].bstats.hp_base = 30;
	specs_all[91].bstats.attack_base = 35;
	specs_all[91].bstats.defense_base = 30;
	specs_all[91].bstats.sattack_base = 100;
	specs_all[91].bstats.sdefense_base = 35;
	specs_all[91].bstats.speed_base = 80;

	// haunter
	strcpy(specs_all[92].name, "Haunter");
	specs_all[92].id = 93;
	specs_all[92].type1 = GHOST_T;
	specs_all[92].type2 = POISON_T;
	specs_all[92].bstats.hp_base = 45;
	specs_all[92].bstats.attack_base = 50;
	specs_all[92].bstats.defense_base = 45;
	specs_all[92].bstats.sattack_base = 115;
	specs_all[92].bstats.sdefense_base = 55;
	specs_all[92].bstats.speed_base = 95;

	// gengar
	strcpy(specs_all[93].name, "Gengar");
	specs_all[93].id = 94;
	specs_all[93].type1 = GHOST_T;
	specs_all[93].type2 = POISON_T;
	specs_all[93].bstats.hp_base = 60;
	specs_all[93].bstats.attack_base = 65;
	specs_all[93].bstats.defense_base = 60;
	specs_all[93].bstats.sattack_base = 130;
	specs_all[93].bstats.sdefense_base = 75;
	specs_all[93].bstats.speed_base = 110;

	// onix
	strcpy(specs_all[94].name, "Onix");
	specs_all[94].id = 95;
	specs_all[94].type1 = ROCK_T;
	specs_all[94].type2 = GROUND_T;
	specs_all[94].bstats.hp_base = 35;
	specs_all[94].bstats.attack_base = 45;
	specs_all[94].bstats.defense_base = 160;
	specs_all[94].bstats.sattack_base = 30;
	specs_all[94].bstats.sdefense_base = 45;
	specs_all[94].bstats.speed_base = 70;

	// drowzee
	strcpy(specs_all[95].name, "Drowzee");
	specs_all[95].id = 96;
	specs_all[95].type1 = PSYCHIC_T;
	specs_all[95].type2 = NON_T;
	specs_all[95].bstats.hp_base = 60;
	specs_all[95].bstats.attack_base = 48;
	specs_all[95].bstats.defense_base = 45;
	specs_all[95].bstats.sattack_base = 43;
	specs_all[95].bstats.sdefense_base = 90;
	specs_all[95].bstats.speed_base = 42;

	// hypno
	strcpy(specs_all[96].name, "Hypno");
	specs_all[96].id = 97;
	specs_all[96].type1 = PSYCHIC_T;
	specs_all[96].type2 = NON_T;
	specs_all[96].bstats.hp_base = 85;
	specs_all[96].bstats.attack_base = 73;
	specs_all[96].bstats.defense_base = 70;
	specs_all[96].bstats.sattack_base = 73;
	specs_all[96].bstats.sdefense_base = 115;
	specs_all[96].bstats.speed_base = 67;

	// krabby
	strcpy(specs_all[97].name, "Krabby");
	specs_all[97].id = 98;
	specs_all[97].type1 = WATER_T;
	specs_all[97].type2 = NON_T;
	specs_all[97].bstats.hp_base = 30;
	specs_all[97].bstats.attack_base = 105;
	specs_all[97].bstats.defense_base = 90;
	specs_all[97].bstats.sattack_base = 25;
	specs_all[97].bstats.sdefense_base = 25;
	specs_all[97].bstats.speed_base = 50;

	// kingler
	strcpy(specs_all[98].name, "Kingler");
	specs_all[98].id = 99;
	specs_all[98].type1 = WATER_T;
	specs_all[98].type2 = NON_T;
	specs_all[98].bstats.hp_base = 55;
	specs_all[98].bstats.attack_base = 130;
	specs_all[98].bstats.defense_base = 115;
	specs_all[98].bstats.sattack_base = 50;
	specs_all[98].bstats.sdefense_base = 50;
	specs_all[98].bstats.speed_base = 75;

	// voltorb
	strcpy(specs_all[99].name, "Voltorb");
	specs_all[99].id = 100;
	specs_all[99].type1 = ELECTRIC_T;
	specs_all[99].type2 = NON_T;
	specs_all[99].bstats.hp_base = 40;
	specs_all[99].bstats.attack_base = 30;
	specs_all[99].bstats.defense_base = 50;
	specs_all[99].bstats.sattack_base = 55;
	specs_all[99].bstats.sdefense_base = 55;
	specs_all[99].bstats.speed_base = 100;

	// electrode
	strcpy(specs_all[100].name, "Electrode");
	specs_all[100].id = 101;
	specs_all[100].type1 = ELECTRIC_T;
	specs_all[100].type2 = NON_T;
	specs_all[100].bstats.hp_base = 60;
	specs_all[100].bstats.attack_base = 50;
	specs_all[100].bstats.defense_base = 70;
	specs_all[100].bstats.sattack_base = 80;
	specs_all[100].bstats.sdefense_base = 80;
	specs_all[100].bstats.speed_base = 140;

	// exeggcute
	strcpy(specs_all[101].name, "Exeggcute");
	specs_all[101].id = 102;
	specs_all[101].type1 = GRASS_T;
	specs_all[101].type2 = PSYCHIC_T;
	specs_all[101].bstats.hp_base = 60;
	specs_all[101].bstats.attack_base = 40;
	specs_all[101].bstats.defense_base = 80;
	specs_all[101].bstats.sattack_base = 60;
	specs_all[101].bstats.sdefense_base = 45;
	specs_all[101].bstats.speed_base = 40;

	// exeggutor
	strcpy(specs_all[102].name, "Exeggutor");
	specs_all[102].id = 103;
	specs_all[102].type1 = GRASS_T;
	specs_all[102].type2 = PSYCHIC_T;
	specs_all[102].bstats.hp_base = 95;
	specs_all[102].bstats.attack_base = 95;
	specs_all[102].bstats.defense_base = 85;
	specs_all[102].bstats.sattack_base = 125;
	specs_all[102].bstats.sdefense_base = 65;
	specs_all[102].bstats.speed_base = 55;

	// cubone
	strcpy(specs_all[103].name, "Cubone");
	specs_all[103].id = 104;
	specs_all[103].type1 = GROUND_T;
	specs_all[103].type2 = NON_T;
	specs_all[103].bstats.hp_base = 50;
	specs_all[103].bstats.attack_base = 50;
	specs_all[103].bstats.defense_base = 95;
	specs_all[103].bstats.sattack_base = 40;
	specs_all[103].bstats.sdefense_base = 50;
	specs_all[103].bstats.speed_base = 35;

	// marowak
	strcpy(specs_all[104].name, "Marowak");
	specs_all[104].id = 105;
	specs_all[104].type1 = GROUND_T;
	specs_all[104].type2 = NON_T;
	specs_all[104].bstats.hp_base = 60;
	specs_all[104].bstats.attack_base = 80;
	specs_all[104].bstats.defense_base = 110;
	specs_all[104].bstats.sattack_base = 50;
	specs_all[104].bstats.sdefense_base = 80;
	specs_all[104].bstats.speed_base = 45;

	// hitmonlee
	strcpy(specs_all[105].name, "Hitmonlee");
	specs_all[105].id = 106;
	specs_all[105].type1 = FIGHTING_T;
	specs_all[105].type2 = NON_T;
	specs_all[105].bstats.hp_base = 50;
	specs_all[105].bstats.attack_base = 120;
	specs_all[105].bstats.defense_base = 53;
	specs_all[105].bstats.sattack_base = 35;
	specs_all[105].bstats.sdefense_base = 110;
	specs_all[105].bstats.speed_base = 87;

	// hitmonchan
	strcpy(specs_all[106].name, "Hitmonchan");
	specs_all[106].id = 107;
	specs_all[106].type1 = FIGHTING_T;
	specs_all[106].type2 = NON_T;
	specs_all[106].bstats.hp_base = 50;
	specs_all[106].bstats.attack_base = 105;
	specs_all[106].bstats.defense_base = 79;
	specs_all[106].bstats.sattack_base = 35;
	specs_all[106].bstats.sdefense_base = 110;
	specs_all[106].bstats.speed_base = 76;

	// lickitung
	strcpy(specs_all[107].name, "Lickitung");
	specs_all[107].id = 108;
	specs_all[107].type1 = NORMAL_T;
	specs_all[107].type2 = NON_T;
	specs_all[107].bstats.hp_base = 90;
	specs_all[107].bstats.attack_base = 55;
	specs_all[107].bstats.defense_base = 75;
	specs_all[107].bstats.sattack_base = 60;
	specs_all[107].bstats.sdefense_base = 75;
	specs_all[107].bstats.speed_base = 30;

	// koffing
	strcpy(specs_all[108].name, "Koffing");
	specs_all[108].id = 109;
	specs_all[108].type1 = POISON_T;
	specs_all[108].type2 = NON_T;
	specs_all[108].bstats.hp_base = 40;
	specs_all[108].bstats.attack_base = 65;
	specs_all[108].bstats.defense_base = 95;
	specs_all[108].bstats.sattack_base = 60;
	specs_all[108].bstats.sdefense_base = 45;
	specs_all[108].bstats.speed_base = 35;

	// weezing
	strcpy(specs_all[109].name, "Weezing");
	specs_all[109].id = 110;
	specs_all[109].type1 = POISON_T;
	specs_all[109].type2 = NON_T;
	specs_all[109].bstats.hp_base = 65;
	specs_all[109].bstats.attack_base = 90;
	specs_all[109].bstats.defense_base = 120;
	specs_all[109].bstats.sattack_base = 85;
	specs_all[109].bstats.sdefense_base = 70;
	specs_all[109].bstats.speed_base = 60;

	// rhyhorn
	strcpy(specs_all[110].name, "Rhyhorn");
	specs_all[110].id = 111;
	specs_all[110].type1 = GROUND_T;
	specs_all[110].type2 = ROCK_T;
	specs_all[110].bstats.hp_base = 80;
	specs_all[110].bstats.attack_base = 85;
	specs_all[110].bstats.defense_base = 95;
	specs_all[110].bstats.sattack_base = 30;
	specs_all[110].bstats.sdefense_base = 30;
	specs_all[110].bstats.speed_base = 25;

	// rhydon
	strcpy(specs_all[111].name, "Rhydon");
	specs_all[111].id = 112;
	specs_all[111].type1 = GROUND_T;
	specs_all[111].type2 = ROCK_T;
	specs_all[111].bstats.hp_base = 105;
	specs_all[111].bstats.attack_base = 130;
	specs_all[111].bstats.defense_base = 120;
	specs_all[111].bstats.sattack_base = 45;
	specs_all[111].bstats.sdefense_base = 45;
	specs_all[111].bstats.speed_base = 40;

	// chansey
	strcpy(specs_all[112].name, "Chansey");
	specs_all[112].id = 113;
	specs_all[112].type1 = NORMAL_T;
	specs_all[112].type2 = NON_T;
	specs_all[112].bstats.hp_base = 250;
	specs_all[112].bstats.attack_base = 5;
	specs_all[112].bstats.defense_base = 5;
	specs_all[112].bstats.sattack_base = 35;
	specs_all[112].bstats.sdefense_base = 105;
	specs_all[112].bstats.speed_base = 50;

	// tangela
	strcpy(specs_all[113].name, "Tangela");
	specs_all[113].id = 114;
	specs_all[113].type1 = GRASS_T;
	specs_all[113].type2 = NON_T;
	specs_all[113].bstats.hp_base = 65;
	specs_all[113].bstats.attack_base = 55;
	specs_all[113].bstats.defense_base = 115;
	specs_all[113].bstats.sattack_base = 100;
	specs_all[113].bstats.sdefense_base = 40;
	specs_all[113].bstats.speed_base = 60;

	// kangaskhan
	strcpy(specs_all[114].name, "Kangaskhan");
	specs_all[114].id = 115;
	specs_all[114].type1 = NORMAL_T;
	specs_all[114].type2 = NON_T;
	specs_all[114].bstats.hp_base = 105;
	specs_all[114].bstats.attack_base = 95;
	specs_all[114].bstats.defense_base = 80;
	specs_all[114].bstats.sattack_base = 40;
	specs_all[114].bstats.sdefense_base = 80;
	specs_all[114].bstats.speed_base = 90;

	// horsea
	strcpy(specs_all[115].name, "Horsea");
	specs_all[115].id = 116;
	specs_all[115].type1 = WATER_T;
	specs_all[115].type2 = NON_T;
	specs_all[115].bstats.hp_base = 30;
	specs_all[115].bstats.attack_base = 40;
	specs_all[115].bstats.defense_base = 70;
	specs_all[115].bstats.sattack_base = 70;
	specs_all[115].bstats.sdefense_base = 25;
	specs_all[115].bstats.speed_base = 60;

	// seadra
	strcpy(specs_all[116].name, "Seadra");
	specs_all[116].id = 117;
	specs_all[116].type1 = WATER_T;
	specs_all[116].type2 = NON_T;
	specs_all[116].bstats.hp_base = 55;
	specs_all[116].bstats.attack_base = 65;
	specs_all[116].bstats.defense_base = 95;
	specs_all[116].bstats.sattack_base = 95;
	specs_all[116].bstats.sdefense_base = 45;
	specs_all[116].bstats.speed_base = 85;

	// goldeen
	strcpy(specs_all[117].name, "Goldeen");
	specs_all[117].id = 118;
	specs_all[117].type1 = WATER_T;
	specs_all[117].type2 = NON_T;
	specs_all[117].bstats.hp_base = 45;
	specs_all[117].bstats.attack_base = 67;
	specs_all[117].bstats.defense_base = 60;
	specs_all[117].bstats.sattack_base = 35;
	specs_all[117].bstats.sdefense_base = 50;
	specs_all[117].bstats.speed_base = 63;

	// seaking
	strcpy(specs_all[118].name, "Seaking");
	specs_all[118].id = 119;
	specs_all[118].type1 = WATER_T;
	specs_all[118].type2 = NON_T;
	specs_all[118].bstats.hp_base = 80;
	specs_all[118].bstats.attack_base = 92;
	specs_all[118].bstats.defense_base = 65;
	specs_all[118].bstats.sattack_base = 65;
	specs_all[118].bstats.sdefense_base = 80;
	specs_all[118].bstats.speed_base = 68;

	// staryu
	strcpy(specs_all[119].name, "Staryu");
	specs_all[119].id = 120;
	specs_all[119].type1 = WATER_T;
	specs_all[119].type2 = NON_T;
	specs_all[119].bstats.hp_base = 30;
	specs_all[119].bstats.attack_base = 45;
	specs_all[119].bstats.defense_base = 55;
	specs_all[119].bstats.sattack_base = 70;
	specs_all[119].bstats.sdefense_base = 55;
	specs_all[119].bstats.speed_base = 85;

	// starmie
	strcpy(specs_all[120].name, "Starmie");
	specs_all[120].id = 121;
	specs_all[120].type1 = WATER_T;
	specs_all[120].type2 = PSYCHIC_T;
	specs_all[120].bstats.hp_base = 60;
	specs_all[120].bstats.attack_base = 75;
	specs_all[120].bstats.defense_base = 85;
	specs_all[120].bstats.sattack_base = 100;
	specs_all[120].bstats.sdefense_base = 85;
	specs_all[120].bstats.speed_base = 115;

	// mr. mime
	strcpy(specs_all[121].name, "Mr. Mime");
	specs_all[121].id = 122;
	specs_all[121].type1 = PSYCHIC_T;
	specs_all[121].type2 = NON_T;
	specs_all[121].bstats.hp_base = 40;
	specs_all[121].bstats.attack_base = 45;
	specs_all[121].bstats.defense_base = 65;
	specs_all[121].bstats.sattack_base = 100;
	specs_all[121].bstats.sdefense_base = 120;
	specs_all[121].bstats.speed_base = 90;

	// scyther
	strcpy(specs_all[122].name, "Scyther");
	specs_all[122].id = 123;
	specs_all[122].type1 = BUG_T;
	specs_all[122].type2 = FLYING_T;
	specs_all[122].bstats.hp_base = 70;
	specs_all[122].bstats.attack_base = 110;
	specs_all[122].bstats.defense_base = 80;
	specs_all[122].bstats.sattack_base = 55;
	specs_all[122].bstats.sdefense_base = 80;
	specs_all[122].bstats.speed_base = 105;

	// jynx
	strcpy(specs_all[123].name, "Jynx");
	specs_all[123].id = 124;
	specs_all[123].type1 = ICE_T;
	specs_all[123].type2 = PSYCHIC_T;
	specs_all[123].bstats.hp_base = 65;
	specs_all[123].bstats.attack_base = 50;
	specs_all[123].bstats.defense_base = 35;
	specs_all[123].bstats.sattack_base = 115;
	specs_all[123].bstats.sdefense_base = 95;
	specs_all[123].bstats.speed_base = 95;

	// electabuzz
	strcpy(specs_all[124].name, "Electabuzz");
	specs_all[124].id = 125;
	specs_all[124].type1 = ELECTRIC_T;
	specs_all[124].type2 = NON_T;
	specs_all[124].bstats.hp_base = 65;
	specs_all[124].bstats.attack_base = 83;
	specs_all[124].bstats.defense_base = 57;
	specs_all[124].bstats.sattack_base = 95;
	specs_all[124].bstats.sdefense_base = 85;
	specs_all[124].bstats.speed_base = 105;

	// magmar
	strcpy(specs_all[125].name, "Magmar");
	specs_all[125].id = 126;
	specs_all[125].type1 = FIRE_T;
	specs_all[125].type2 = NON_T;
	specs_all[125].bstats.hp_base = 65;
	specs_all[125].bstats.attack_base = 95;
	specs_all[125].bstats.defense_base = 57;
	specs_all[125].bstats.sattack_base = 100;
	specs_all[125].bstats.sdefense_base = 85;
	specs_all[125].bstats.speed_base = 93;

	// pinsir
	strcpy(specs_all[126].name, "Pinsir");
	specs_all[126].id = 127;
	specs_all[126].type1 = BUG_T;
	specs_all[126].type2 = NON_T;
	specs_all[126].bstats.hp_base = 65;
	specs_all[126].bstats.attack_base = 125;
	specs_all[126].bstats.defense_base = 100;
	specs_all[126].bstats.sattack_base = 55;
	specs_all[126].bstats.sdefense_base = 70;
	specs_all[126].bstats.speed_base = 85;

	// tauros
	strcpy(specs_all[127].name, "Tauros");
	specs_all[127].id = 128;
	specs_all[127].type1 = NORMAL_T;
	specs_all[127].type2 = NON_T;
	specs_all[127].bstats.hp_base = 75;
	specs_all[127].bstats.attack_base = 100;
	specs_all[127].bstats.defense_base = 95;
	specs_all[127].bstats.sattack_base = 40;
	specs_all[127].bstats.sdefense_base = 70;
	specs_all[127].bstats.speed_base = 110;

	// magikarp
	strcpy(specs_all[128].name, "Magikarp");
	specs_all[128].id = 129;
	specs_all[128].type1 = WATER_T;
	specs_all[128].type2 = NON_T;
	specs_all[128].bstats.hp_base = 20;
	specs_all[128].bstats.attack_base = 10;
	specs_all[128].bstats.defense_base = 55;
	specs_all[128].bstats.sattack_base = 15;
	specs_all[128].bstats.sdefense_base = 20;
	specs_all[128].bstats.speed_base = 80;

	// gyarados
	strcpy(specs_all[129].name, "Gyarados");
	specs_all[129].id = 130;
	specs_all[129].type1 = WATER_T;
	specs_all[129].type2 = FLYING_T;
	specs_all[129].bstats.hp_base = 95;
	specs_all[129].bstats.attack_base = 125;
	specs_all[129].bstats.defense_base = 79;
	specs_all[129].bstats.sattack_base = 60;
	specs_all[129].bstats.sdefense_base = 100;
	specs_all[129].bstats.speed_base = 81;

	// lapras
	strcpy(specs_all[130].name, "Lapras");
	specs_all[130].id = 131;
	specs_all[130].type1 = WATER_T;
	specs_all[130].type2 = ICE_T;
	specs_all[130].bstats.hp_base = 130;
	specs_all[130].bstats.attack_base = 85;
	specs_all[130].bstats.defense_base = 80;
	specs_all[130].bstats.sattack_base = 85;
	specs_all[130].bstats.sdefense_base = 95;
	specs_all[130].bstats.speed_base = 60;

	// ditto
	strcpy(specs_all[131].name, "Ditto");
	specs_all[131].id = 132;
	specs_all[131].type1 = NORMAL_T;
	specs_all[131].type2 = NON_T;
	specs_all[131].bstats.hp_base = 48;
	specs_all[131].bstats.attack_base = 48;
	specs_all[131].bstats.defense_base = 48;
	specs_all[131].bstats.sattack_base = 48;
	specs_all[131].bstats.sdefense_base = 48;
	specs_all[131].bstats.speed_base = 48;

	// eevee
	strcpy(specs_all[132].name, "Eevee");
	specs_all[132].id = 133;
	specs_all[132].type1 = NORMAL_T;
	specs_all[132].type2 = NON_T;
	specs_all[132].bstats.hp_base = 55;
	specs_all[132].bstats.attack_base = 55;
	specs_all[132].bstats.defense_base = 50;
	specs_all[132].bstats.sattack_base = 45;
	specs_all[132].bstats.sdefense_base = 65;
	specs_all[132].bstats.speed_base = 55;

	// vaporeon
	strcpy(specs_all[133].name, "Vaporeon");
	specs_all[133].id = 134;
	specs_all[133].type1 = WATER_T;
	specs_all[133].type2 = NON_T;
	specs_all[133].bstats.hp_base = 130;
	specs_all[133].bstats.attack_base = 65;
	specs_all[133].bstats.defense_base = 60;
	specs_all[133].bstats.sattack_base = 110;
	specs_all[133].bstats.sdefense_base = 95;
	specs_all[133].bstats.speed_base = 65;

	// jolteon
	strcpy(specs_all[134].name, "Jolteon");
	specs_all[134].id = 135;
	specs_all[134].type1 = ELECTRIC_T;
	specs_all[134].type2 = NON_T;
	specs_all[134].bstats.hp_base = 65;
	specs_all[134].bstats.attack_base = 65;
	specs_all[134].bstats.defense_base = 60;
	specs_all[134].bstats.sattack_base = 110;
	specs_all[134].bstats.sdefense_base = 95;
	specs_all[134].bstats.speed_base = 130;

	// flareon
	strcpy(specs_all[135].name, "Flareon");
	specs_all[135].id = 136;
	specs_all[135].type1 = FIRE_T;
	specs_all[135].type2 = NON_T;
	specs_all[135].bstats.hp_base = 65;
	specs_all[135].bstats.attack_base = 130;
	specs_all[135].bstats.defense_base = 60;
	specs_all[135].bstats.sattack_base = 95;
	specs_all[135].bstats.sdefense_base = 110;
	specs_all[135].bstats.speed_base = 65;

	// porygon
	strcpy(specs_all[136].name, "Porygon");
	specs_all[136].id = 137;
	specs_all[136].type1 = NORMAL_T;
	specs_all[136].type2 = NON_T;
	specs_all[136].bstats.hp_base = 65;
	specs_all[136].bstats.attack_base = 60;
	specs_all[136].bstats.defense_base = 70;
	specs_all[136].bstats.sattack_base = 85;
	specs_all[136].bstats.sdefense_base = 75;
	specs_all[136].bstats.speed_base = 40;

	// omanyte
	strcpy(specs_all[137].name, "Omanyte");
	specs_all[137].id = 138;
	specs_all[137].type1 = ROCK_T;
	specs_all[137].type2 = WATER_T;
	specs_all[137].bstats.hp_base = 35;
	specs_all[137].bstats.attack_base = 40;
	specs_all[137].bstats.defense_base = 100;
	specs_all[137].bstats.sattack_base = 90;
	specs_all[137].bstats.sdefense_base = 55;
	specs_all[137].bstats.speed_base = 35;

	// omastar
	strcpy(specs_all[138].name, "Omastar");
	specs_all[138].id = 139;
	specs_all[138].type1 = ROCK_T;
	specs_all[138].type2 = WATER_T;
	specs_all[138].bstats.hp_base = 70;
	specs_all[138].bstats.attack_base = 60;
	specs_all[138].bstats.defense_base = 125;
	specs_all[138].bstats.sattack_base = 115;
	specs_all[138].bstats.sdefense_base = 70;
	specs_all[138].bstats.speed_base = 55;

	// kabuto
	strcpy(specs_all[139].name, "Kabuto");
	specs_all[139].id = 140;
	specs_all[139].type1 = ROCK_T;
	specs_all[139].type2 = WATER_T;
	specs_all[139].bstats.hp_base = 30;
	specs_all[139].bstats.attack_base = 80;
	specs_all[139].bstats.defense_base = 90;
	specs_all[139].bstats.sattack_base = 55;
	specs_all[139].bstats.sdefense_base = 45;
	specs_all[139].bstats.speed_base = 55;

	// kabutops
	strcpy(specs_all[140].name, "Kabutops");
	specs_all[140].id = 141;
	specs_all[140].type1 = ROCK_T;
	specs_all[140].type2 = WATER_T;
	specs_all[140].bstats.hp_base = 60;
	specs_all[140].bstats.attack_base = 115;
	specs_all[140].bstats.defense_base = 105;
	specs_all[140].bstats.sattack_base = 65;
	specs_all[140].bstats.sdefense_base = 70;
	specs_all[140].bstats.speed_base = 80;

	// aerodactyl
	strcpy(specs_all[141].name, "Aerodactyl");
	specs_all[141].id = 142;
	specs_all[141].type1 = ROCK_T;
	specs_all[141].type2 = FLYING_T;
	specs_all[141].bstats.hp_base = 80;
	specs_all[141].bstats.attack_base = 105;
	specs_all[141].bstats.defense_base = 65;
	specs_all[141].bstats.sattack_base = 60;
	specs_all[141].bstats.sdefense_base = 75;
	specs_all[141].bstats.speed_base = 130;

	// snorlax
	strcpy(specs_all[142].name, "Snorlax");
	specs_all[142].id = 143;
	specs_all[142].type1 = NORMAL_T;
	specs_all[142].type2 = NON_T;
	specs_all[142].bstats.hp_base = 160;
	specs_all[142].bstats.attack_base = 110;
	specs_all[142].bstats.defense_base = 65;
	specs_all[142].bstats.sattack_base = 65;
	specs_all[142].bstats.sdefense_base = 110;
	specs_all[142].bstats.speed_base = 30;

	// articuno
	strcpy(specs_all[143].name, "Articuno");
	specs_all[143].id = 144;
	specs_all[143].type1 = ICE_T;
	specs_all[143].type2 = FLYING_T;
	specs_all[143].bstats.hp_base = 90;
	specs_all[143].bstats.attack_base = 85;
	specs_all[143].bstats.defense_base = 100;
	specs_all[143].bstats.sattack_base = 95;
	specs_all[143].bstats.sdefense_base = 125;
	specs_all[143].bstats.speed_base = 85;

	// zapdos
	strcpy(specs_all[144].name, "Zapdos");
	specs_all[144].id = 145;
	specs_all[144].type1 = ELECTRIC_T;
	specs_all[144].type2 = FLYING_T;
	specs_all[144].bstats.hp_base = 90;
	specs_all[144].bstats.attack_base = 90;
	specs_all[144].bstats.defense_base = 85;
	specs_all[144].bstats.sattack_base = 125;
	specs_all[144].bstats.sdefense_base = 90;
	specs_all[144].bstats.speed_base = 100;

	// moltres
	strcpy(specs_all[145].name, "Moltres");
	specs_all[145].id = 146;
	specs_all[145].type1 = FIRE_T;
	specs_all[145].type2 = FLYING_T;
	specs_all[145].bstats.hp_base = 90;
	specs_all[145].bstats.attack_base = 100;
	specs_all[145].bstats.defense_base = 90;
	specs_all[145].bstats.sattack_base = 125;
	specs_all[145].bstats.sdefense_base = 85;
	specs_all[145].bstats.speed_base = 90;

	// dratini
	strcpy(specs_all[146].name, "Dratini");
	specs_all[146].id = 147;
	specs_all[146].type1 = DRAGON_T;
	specs_all[146].type2 = NON_T;
	specs_all[146].bstats.hp_base = 41;
	specs_all[146].bstats.attack_base = 64;
	specs_all[146].bstats.defense_base = 45;
	specs_all[146].bstats.sattack_base = 50;
	specs_all[146].bstats.sdefense_base = 50;
	specs_all[146].bstats.speed_base = 50;

	// dragonair
	strcpy(specs_all[147].name, "Dragonair");
	specs_all[147].id = 148;
	specs_all[147].type1 = DRAGON_T;
	specs_all[147].type2 = NON_T;
	specs_all[147].bstats.hp_base = 61;
	specs_all[147].bstats.attack_base = 84;
	specs_all[147].bstats.defense_base = 65;
	specs_all[147].bstats.sattack_base = 70;
	specs_all[147].bstats.sdefense_base = 70;
	specs_all[147].bstats.speed_base = 70;

	// dragonite
	strcpy(specs_all[148].name, "Dragonite");
	specs_all[148].id = 149;
	specs_all[148].type1 = DRAGON_T;
	specs_all[148].type2 = FLYING_T;
	specs_all[148].bstats.hp_base = 91;
	specs_all[148].bstats.attack_base = 134;
	specs_all[148].bstats.defense_base = 95;
	specs_all[148].bstats.sattack_base = 100;
	specs_all[148].bstats.sdefense_base = 100;
	specs_all[148].bstats.speed_base = 80;

	// mewtwo
	strcpy(specs_all[149].name, "Mewtwo");
	specs_all[149].id = 150;
	specs_all[149].type1 = PSYCHIC_T;
	specs_all[149].type2 = NON_T;
	specs_all[149].bstats.hp_base = 106;
	specs_all[149].bstats.attack_base = 110;
	specs_all[149].bstats.defense_base = 90;
	specs_all[149].bstats.sattack_base = 154;
	specs_all[149].bstats.sdefense_base = 90;
	specs_all[149].bstats.speed_base = 130;

	// mewtwo
	strcpy(specs_all[150].name, "Mew");
	specs_all[150].id = 151;
	specs_all[150].type1 = PSYCHIC_T;
	specs_all[150].type2 = NON_T;
	specs_all[150].bstats.hp_base = 100;
	specs_all[150].bstats.attack_base = 100;
	specs_all[150].bstats.defense_base = 100;
	specs_all[150].bstats.sattack_base = 100;
	specs_all[150].bstats.sdefense_base = 100;
	specs_all[150].bstats.speed_base = 100;
}

void init_moves() {
	// absorb
	strcpy(moves_all[0].name, "Absorb");
	moves_all[0].damage = 20;
	moves_all[0].accuracy = 1.0;
	moves_all[0].type = GRASS_T;
	moves_all[0].movetype = SPECIAL_MT;
	moves_all[0].priority = 0;
	moves_all[0].unique = 0;
	moves_all[0].pp_max = 25;
	moves_all[0].effect = RECOIL_E2;
	moves_all[0].chance = 1.0;
	moves_all[0].m_arg = -2;

	// acid
	strcpy(moves_all[1].name, "Acid");
	moves_all[1].damage = 40;
	moves_all[1].accuracy = 1.0;
	moves_all[1].type = POISON_T;
	moves_all[1].movetype = SPECIAL_MT;
	moves_all[1].priority = 0;
	moves_all[1].unique = 0;
	moves_all[1].pp_max = 30;
	moves_all[1].effect = OTHR_SDEFENSE_E2;
	moves_all[1].chance = 0.1;
	moves_all[1].m_arg = -1;

	// acid armor
	strcpy(moves_all[2].name, "Acid Armor");
	moves_all[2].damage = 0;
	moves_all[2].accuracy = 1.0;
	moves_all[2].type = POISON_T;
	moves_all[2].movetype = STATUS_MT;
	moves_all[2].priority = 0;
	moves_all[2].unique = 0;
	moves_all[2].pp_max = 20;
	moves_all[2].effect = SELF_DEFENSE_E2;
	moves_all[2].chance = 1.0;
	moves_all[2].m_arg = 2;

	// agility
	strcpy(moves_all[3].name, "Agility");
	moves_all[3].damage = 0;
	moves_all[3].accuracy = 1.0;
	moves_all[3].type = PSYCHIC_T;
	moves_all[3].movetype = STATUS_MT;
	moves_all[3].priority = 0;
	moves_all[3].unique = 0;
	moves_all[3].pp_max = 30;
	moves_all[3].effect = SELF_SPEED_E2;
	moves_all[3].chance = 1.0;
	moves_all[3].m_arg = 2;

	// amnesia
	strcpy(moves_all[4].name, "Amnesia");
	moves_all[4].damage = 0;
	moves_all[4].accuracy = 1.0;
	moves_all[4].type = PSYCHIC_T;
	moves_all[4].movetype = STATUS_MT;
	moves_all[4].priority = 0;
	moves_all[4].unique = 0;
	moves_all[4].pp_max = 20;
	moves_all[4].effect = SELF_SDEFENSE_E2;
	moves_all[4].chance = 1.0;
	moves_all[4].m_arg = 2;

	// aurora beam
	strcpy(moves_all[5].name, "Aurora Beam");
	moves_all[5].damage = 65;
	moves_all[5].accuracy = 1.0;
	moves_all[5].type = ICE_T;
	moves_all[5].movetype = SPECIAL_MT;
	moves_all[5].priority = 0;
	moves_all[5].unique = 0;
	moves_all[5].pp_max = 20;
	moves_all[5].effect = OTHR_ATTACK_E2;
	moves_all[5].chance = 0.1;
	moves_all[5].m_arg = -1;

	// barrier
	strcpy(moves_all[6].name, "Barrier");
	moves_all[6].damage = 0;
	moves_all[6].accuracy = 1.0;
	moves_all[6].type = PSYCHIC_T;
	moves_all[6].movetype = STATUS_MT;
	moves_all[6].priority = 0;
	moves_all[6].unique = 0;
	moves_all[6].pp_max = 20;
	moves_all[6].effect = SELF_DEFENSE_E2;
	moves_all[6].chance = 1.0;
	moves_all[6].m_arg = 2;

	// bite
	strcpy(moves_all[7].name, "Bite");
	moves_all[7].damage = 60;
	moves_all[7].accuracy = 1.0;
	moves_all[7].type = DARK_T;
	moves_all[7].movetype = PHYSICAL_MT;
	moves_all[7].priority = 0;
	moves_all[7].unique = 0;
	moves_all[7].pp_max = 25;
	moves_all[7].effect = APPLY_FLINCH_E2;
	moves_all[7].chance = 0.3;
	moves_all[7].m_arg = 0;

	// blizzard
	strcpy(moves_all[8].name, "Blizzard");
	moves_all[8].damage = 110;
	moves_all[8].accuracy = 0.7;
	moves_all[8].type = ICE_T;
	moves_all[8].movetype = SPECIAL_MT;
	moves_all[8].priority = 0;
	moves_all[8].unique = 0;
	moves_all[8].pp_max = 5;
	moves_all[8].effect = APPLY_FRZ_E2;
	moves_all[8].chance = 0.1;
	moves_all[8].m_arg = 0;

	// body slam
	strcpy(moves_all[9].name, "Body Slam");
	moves_all[9].damage = 85;
	moves_all[9].accuracy = 1.0;
	moves_all[9].type = NORMAL_T;
	moves_all[9].movetype = PHYSICAL_MT;
	moves_all[9].priority = 0;
	moves_all[9].unique = 0;
	moves_all[9].pp_max = 15;
	moves_all[9].effect = APPLY_PAR_E2;
	moves_all[9].chance = 0.3;
	moves_all[9].m_arg = 0;

	// bone club
	strcpy(moves_all[10].name, "Bone Club");
	moves_all[10].damage = 65;
	moves_all[10].accuracy = 0.85;
	moves_all[10].type = GROUND_T;
	moves_all[10].movetype = PHYSICAL_MT;
	moves_all[10].priority = 0;
	moves_all[10].unique = 0;
	moves_all[10].pp_max = 20;
	moves_all[10].effect = APPLY_FLINCH_E2;
	moves_all[10].chance = 0.1;
	moves_all[10].m_arg = 0;

	// bubble
	strcpy(moves_all[11].name, "Bubble");
	moves_all[11].damage = 40;
	moves_all[11].accuracy = 1.0;
	moves_all[11].type = WATER_T;
	moves_all[11].movetype = SPECIAL_MT;
	moves_all[11].priority = 0;
	moves_all[11].unique = 0;
	moves_all[11].pp_max = 30;
	moves_all[11].effect = OTHR_SPEED_E2;
	moves_all[11].chance = 0.1;
	moves_all[11].m_arg = -1;

	// bubble beam
	strcpy(moves_all[12].name, "Bubble Beam");
	moves_all[12].damage = 65;
	moves_all[12].accuracy = 1.0;
	moves_all[12].type = WATER_T;
	moves_all[12].movetype = SPECIAL_MT;
	moves_all[12].priority = 0;
	moves_all[12].unique = 0;
	moves_all[12].pp_max = 20;
	moves_all[12].effect = OTHR_SPEED_E2;
	moves_all[12].chance = 0.1;
	moves_all[12].m_arg = -1;

	// confuse ray
	strcpy(moves_all[13].name, "Confuse Ray");
	moves_all[13].damage = 0;
	moves_all[13].accuracy = 1.0;
	moves_all[13].type = GHOST_T;
	moves_all[13].movetype = STATUS_MT;
	moves_all[13].priority = 0;
	moves_all[13].unique = 0;
	moves_all[13].pp_max = 10;
	moves_all[13].effect = APPLY_CONFUSE_E2;
	moves_all[13].chance = 1.0;
	moves_all[13].m_arg = 0;

	// confusion
	strcpy(moves_all[14].name, "Confusion");
	moves_all[14].damage = 50;
	moves_all[14].accuracy = 1.0;
	moves_all[14].type = PSYCHIC_T;
	moves_all[14].movetype = SPECIAL_MT;
	moves_all[14].priority = 0;
	moves_all[14].unique = 0;
	moves_all[14].pp_max = 25;
	moves_all[14].effect = APPLY_CONFUSE_E2;
	moves_all[14].chance = 0.1;
	moves_all[14].m_arg = 0;

	// constrict
	strcpy(moves_all[15].name, "Constrict");
	moves_all[15].damage = 10;
	moves_all[15].accuracy = 1.0;
	moves_all[15].type = NORMAL_T;
	moves_all[15].movetype = PHYSICAL_MT;
	moves_all[15].priority = 0;
	moves_all[15].unique = 0;
	moves_all[15].pp_max = 35;
	moves_all[15].effect = OTHR_SPEED_E2;
	moves_all[15].chance = 0.1;
	moves_all[15].m_arg = -1;

	// crabhammer
	strcpy(moves_all[16].name, "Crabhammer");
	moves_all[16].damage = 100;
	moves_all[16].accuracy = 0.9;
	moves_all[16].type = WATER_T;
	moves_all[16].movetype = PHYSICAL_MT;
	moves_all[16].priority = 0;
	moves_all[16].unique = 0;
	moves_all[16].pp_max = 10;
	moves_all[16].effect = HIGH_CRIT_E2;
	moves_all[16].chance = 1.0;
	moves_all[16].m_arg = 0;

	// cut
	strcpy(moves_all[17].name, "Cut");
	moves_all[17].damage = 50;
	moves_all[17].accuracy = 0.95;
	moves_all[17].type = NORMAL_T;
	moves_all[17].movetype = PHYSICAL_MT;
	moves_all[17].priority = 0;
	moves_all[17].unique = 0;
	moves_all[17].pp_max = 30;
	moves_all[17].effect = NON_E2;
	moves_all[17].chance = 1.0;
	moves_all[17].m_arg = 0;

	// defense curl
	strcpy(moves_all[18].name, "Defense Curl");
	moves_all[18].damage = 0;
	moves_all[18].accuracy = 1.0;
	moves_all[18].type = NORMAL_T;
	moves_all[18].movetype = STATUS_MT;
	moves_all[18].priority = 0;
	moves_all[18].unique = 0;
	moves_all[18].pp_max = 40;
	moves_all[18].effect = SELF_DEFENSE_E2;
	moves_all[18].chance = 1.0;
	moves_all[18].m_arg = 1;

	// dizzy punch
	strcpy(moves_all[19].name, "Dizzy Punch");
	moves_all[19].damage = 70;
	moves_all[19].accuracy = 1.0;
	moves_all[19].type = NORMAL_T;
	moves_all[19].movetype = PHYSICAL_MT;
	moves_all[19].priority = 0;
	moves_all[19].unique = 0;
	moves_all[19].pp_max = 10;
	moves_all[19].effect = APPLY_CONFUSE_E2;
	moves_all[19].chance = 0.2;
	moves_all[19].m_arg = 0;

	// double team
	strcpy(moves_all[20].name, "Double Team");
	moves_all[20].damage = 0;
	moves_all[20].accuracy = 1.0;
	moves_all[20].type = NORMAL_T;
	moves_all[20].movetype = STATUS_MT;
	moves_all[20].priority = 0;
	moves_all[20].unique = 0;
	moves_all[20].pp_max = 15;
	moves_all[20].effect = SELF_EVASION_E2;
	moves_all[20].chance = 1.0;
	moves_all[20].m_arg = 1;

	// double-edge
	strcpy(moves_all[21].name, "Double-Edge");
	moves_all[21].damage = 120;
	moves_all[21].accuracy = 1.0;
	moves_all[21].type = NORMAL_T;
	moves_all[21].movetype = PHYSICAL_MT;
	moves_all[21].priority = 0;
	moves_all[21].unique = 0;
	moves_all[21].pp_max = 15;
	moves_all[21].effect = RECOIL_E2;
	moves_all[21].chance = 1.0;
	moves_all[21].m_arg = 3;

	// drill peck
	strcpy(moves_all[22].name, "Drill Peck");
	moves_all[22].damage = 80;
	moves_all[22].accuracy = 1.0;
	moves_all[22].type = FLYING_T;
	moves_all[22].movetype = PHYSICAL_MT;
	moves_all[22].priority = 0;
	moves_all[22].unique = 0;
	moves_all[22].pp_max = 20;
	moves_all[22].effect = NON_E2;
	moves_all[22].chance = 1.0;
	moves_all[22].m_arg = 0;

	// earthquake
	strcpy(moves_all[23].name, "Earthquake");
	moves_all[23].damage = 100;
	moves_all[23].accuracy = 1.0;
	moves_all[23].type = GROUND_T;
	moves_all[23].movetype = PHYSICAL_MT;
	moves_all[23].priority = 0;
	moves_all[23].unique = 0;
	moves_all[23].pp_max = 10;
	moves_all[23].effect = NON_E2;
	moves_all[23].chance = 1.0;
	moves_all[23].m_arg = 0;

	// egg bomb
	strcpy(moves_all[24].name, "Egg Bomb");
	moves_all[24].damage = 100;
	moves_all[24].accuracy = 0.75;
	moves_all[24].type = NORMAL_T;
	moves_all[24].movetype = PHYSICAL_MT;
	moves_all[24].priority = 0;
	moves_all[24].unique = 0;
	moves_all[24].pp_max = 10;
	moves_all[24].effect = NON_E2;
	moves_all[24].chance = 1.0;
	moves_all[24].m_arg = 0;

	// ember
	strcpy(moves_all[25].name, "Ember");
	moves_all[25].damage = 40;
	moves_all[25].accuracy = 1.0;
	moves_all[25].type = FIRE_T;
	moves_all[25].movetype = SPECIAL_MT;
	moves_all[25].priority = 0;
	moves_all[25].unique = 0;
	moves_all[25].pp_max = 25;
	moves_all[25].effect = APPLY_BRN_E2;
	moves_all[25].chance = 0.1;
	moves_all[25].m_arg = 0;

	// explosion
	strcpy(moves_all[26].name, "Explosion");
	moves_all[26].damage = 250;
	moves_all[26].accuracy = 1.0;
	moves_all[26].type = NORMAL_T;
	moves_all[26].movetype = PHYSICAL_MT;
	moves_all[26].priority = 0;
	moves_all[26].unique = 0;
	moves_all[26].pp_max = 5;
	moves_all[26].effect = SELF_KILL_E2;
	moves_all[26].chance = 1.0;
	moves_all[26].m_arg = 0;

	// fire blast
	strcpy(moves_all[27].name, "Fire Blast");
	moves_all[27].damage = 110;
	moves_all[27].accuracy = 0.85;
	moves_all[27].type = FIRE_T;
	moves_all[27].movetype = SPECIAL_MT;
	moves_all[27].priority = 0;
	moves_all[27].unique = 0;
	moves_all[27].pp_max = 5;
	moves_all[27].effect = APPLY_BRN_E2;
	moves_all[27].chance = 0.1;
	moves_all[27].m_arg = 0;

	// fire punch
	strcpy(moves_all[28].name, "Fire Punch");
	moves_all[28].damage = 75;
	moves_all[28].accuracy = 1.0;
	moves_all[28].type = FIRE_T;
	moves_all[28].movetype = PHYSICAL_MT;
	moves_all[28].priority = 0;
	moves_all[28].unique = 0;
	moves_all[28].pp_max = 15;
	moves_all[28].effect = APPLY_BRN_E2;
	moves_all[28].chance = 0.1;
	moves_all[28].m_arg = 0;

	// fissure
	strcpy(moves_all[29].name, "Fissure");
	moves_all[29].damage = 100000;
	moves_all[29].accuracy = 1.0;
	moves_all[29].type = GROUND_T;
	moves_all[29].movetype = PHYSICAL_MT;
	moves_all[29].priority = 0;
	moves_all[29].unique = 0;
	moves_all[29].pp_max = 5;
	moves_all[29].effect = NON_E2;
	moves_all[29].chance = 1.0;
	moves_all[29].m_arg = 0;

	// flamethrower
	strcpy(moves_all[30].name, "Flamethrower");
	moves_all[30].damage = 90;
	moves_all[30].accuracy = 1.0;
	moves_all[30].type = FIRE_T;
	moves_all[30].movetype = SPECIAL_MT;
	moves_all[30].priority = 0;
	moves_all[30].unique = 0;
	moves_all[30].pp_max = 15;
	moves_all[30].effect = APPLY_BRN_E2;
	moves_all[30].chance = 0.1;
	moves_all[30].m_arg = 0;

	// flash
	strcpy(moves_all[31].name, "Flash");
	moves_all[31].damage = 0;
	moves_all[31].accuracy = 1.0;
	moves_all[31].type = NORMAL_T;
	moves_all[31].movetype = STATUS_MT;
	moves_all[31].priority = 0;
	moves_all[31].unique = 0;
	moves_all[31].pp_max = 20;
	moves_all[31].effect = OTHR_ACCURACY_E2;
	moves_all[31].chance = 1.0;
	moves_all[31].m_arg = -1;

	// glare
	strcpy(moves_all[32].name, "Glare");
	moves_all[32].damage = 0;
	moves_all[32].accuracy = 1.0;
	moves_all[32].type = NORMAL_T;
	moves_all[32].movetype = STATUS_MT;
	moves_all[32].priority = 0;
	moves_all[32].unique = 0;
	moves_all[32].pp_max = 30;
	moves_all[32].effect = APPLY_PAR_E2;
	moves_all[32].chance = 1.0;
	moves_all[32].m_arg = 0;

	// growl
	strcpy(moves_all[33].name, "Growl");
	moves_all[33].damage = 0;
	moves_all[33].accuracy = 1.0;
	moves_all[33].type = NORMAL_T;
	moves_all[33].movetype = STATUS_MT;
	moves_all[33].priority = 0;
	moves_all[33].unique = 0;
	moves_all[33].pp_max = 40;
	moves_all[33].effect = OTHR_ATTACK_E2;
	moves_all[33].chance = 1.0;
	moves_all[33].m_arg = -1;

	// growth
	strcpy(moves_all[34].name, "Growth");
	moves_all[34].damage = 0;
	moves_all[34].accuracy = 1.0;
	moves_all[34].type = NORMAL_T;
	moves_all[34].movetype = STATUS_MT;
	moves_all[34].priority = 0;
	moves_all[34].unique = 0;
	moves_all[34].pp_max = 40;
	moves_all[34].effect = SELF_ATTACK_SATTACK_E2;
	moves_all[34].chance = 1.0;
	moves_all[34].m_arg = 1;

	// guillotine
	strcpy(moves_all[35].name, "Guillotine");
	moves_all[35].damage = 10000;
	moves_all[35].accuracy = 1.0;
	moves_all[35].type = NORMAL_T;
	moves_all[35].movetype = PHYSICAL_MT;
	moves_all[35].priority = 0;
	moves_all[35].unique = 0;
	moves_all[35].pp_max = 5;
	moves_all[35].effect = NON_E2;
	moves_all[35].chance = 1.0;
	moves_all[35].m_arg = 0;

	// gust
	strcpy(moves_all[36].name, "Gust");
	moves_all[36].damage = 40;
	moves_all[36].accuracy = 1.0;
	moves_all[36].type = FLYING_T;
	moves_all[36].movetype = SPECIAL_MT;
	moves_all[36].priority = 0;
	moves_all[36].unique = 0;
	moves_all[36].pp_max = 35;
	moves_all[36].effect = NON_E2;
	moves_all[36].chance = 1.0;
	moves_all[36].m_arg = 0;

	// harden
	strcpy(moves_all[37].name, "Harden");
	moves_all[37].damage = 0;
	moves_all[37].accuracy = 1.0;
	moves_all[37].type = NORMAL_T;
	moves_all[37].movetype = STATUS_MT;
	moves_all[37].priority = 0;
	moves_all[37].unique = 0;
	moves_all[37].pp_max = 30;
	moves_all[37].effect = SELF_DEFENSE_E2;
	moves_all[37].chance = 1.0;
	moves_all[37].m_arg = 1;

	// haze
	strcpy(moves_all[38].name, "Haze");
	moves_all[38].damage = 0;
	moves_all[38].accuracy = 1.0;
	moves_all[38].type = ICE_T;
	moves_all[38].movetype = STATUS_MT;
	moves_all[38].priority = 0;
	moves_all[38].unique = 0;
	moves_all[38].pp_max = 30;
	moves_all[38].effect = HAZE_E2;
	moves_all[38].chance = 1.0;
	moves_all[38].m_arg = 0;

	// headbutt
	strcpy(moves_all[39].name, "Headbutt");
	moves_all[39].damage = 70;
	moves_all[39].accuracy = 1.0;
	moves_all[39].type = NORMAL_T;
	moves_all[39].movetype = PHYSICAL_MT;
	moves_all[39].priority = 0;
	moves_all[39].unique = 0;
	moves_all[39].pp_max = 15;
	moves_all[39].effect = APPLY_FLINCH_E2;
	moves_all[39].chance = 0.3;
	moves_all[39].m_arg = 0;

	// horn attack
	strcpy(moves_all[40].name, "Horn Attack");
	moves_all[40].damage = 65;
	moves_all[40].accuracy = 1.0;
	moves_all[40].type = NORMAL_T;
	moves_all[40].movetype = PHYSICAL_MT;
	moves_all[40].priority = 0;
	moves_all[40].unique = 0;
	moves_all[40].pp_max = 25;
	moves_all[40].effect = NON_E2;
	moves_all[40].chance = 1.0;
	moves_all[40].m_arg = 0;

	// horn drill
	strcpy(moves_all[41].name, "Horn Drill");
	moves_all[41].damage = 10000;
	moves_all[41].accuracy = 0.3;
	moves_all[41].type = NORMAL_T;
	moves_all[41].movetype = PHYSICAL_MT;
	moves_all[41].priority = 0;
	moves_all[41].unique = 0;
	moves_all[41].pp_max = 5;
	moves_all[41].effect = NON_E2;
	moves_all[41].chance = 1.0;
	moves_all[41].m_arg = 0;

	// hydro pump
	strcpy(moves_all[42].name, "Hydro Pump");
	moves_all[42].damage = 110;
	moves_all[42].accuracy = 0.8;
	moves_all[42].type = WATER_T;
	moves_all[42].movetype = SPECIAL_MT;
	moves_all[42].priority = 0;
	moves_all[42].unique = 0;
	moves_all[42].pp_max = 5;
	moves_all[42].effect = NON_E2;
	moves_all[42].chance = 1.0;
	moves_all[42].m_arg = 0;

	// hyper beam
	strcpy(moves_all[43].name, "Hyper Beam");
	moves_all[43].damage = 150;
	moves_all[43].accuracy = 0.9;
	moves_all[43].type = NORMAL_T;
	moves_all[43].movetype = SPECIAL_MT;
	moves_all[43].priority = 0;
	moves_all[43].unique = 0;
	moves_all[43].pp_max = 5;
	moves_all[43].effect = RECHARGE_E2;
	moves_all[43].chance = 1.0;
	moves_all[43].m_arg = 0;

	// hyper fang
	strcpy(moves_all[44].name, "Hyper Fang");
	moves_all[44].damage = 80;
	moves_all[44].accuracy = 0.9;
	moves_all[44].type = NORMAL_T;
	moves_all[44].movetype = PHYSICAL_MT;
	moves_all[44].priority = 0;
	moves_all[44].unique = 0;
	moves_all[44].pp_max = 15;
	moves_all[44].effect = APPLY_FLINCH_E2;
	moves_all[44].chance = 0.1;
	moves_all[44].m_arg = 0;

	// hypnosis
	strcpy(moves_all[45].name, "Hypnosis");
	moves_all[45].damage = 0;
	moves_all[45].accuracy = 0.6;
	moves_all[45].type = PSYCHIC_T;
	moves_all[45].movetype = STATUS_MT;
	moves_all[45].priority = 0;
	moves_all[45].unique = 0;
	moves_all[45].pp_max = 20;
	moves_all[45].effect = APPLY_SLP_E2;
	moves_all[45].chance = 1.0;
	moves_all[45].m_arg = 0;

	// ice beam
	strcpy(moves_all[46].name, "Ice Beam");
	moves_all[46].damage = 90;
	moves_all[46].accuracy = 1.0;
	moves_all[46].type = ICE_T;
	moves_all[46].movetype = SPECIAL_MT;
	moves_all[46].priority = 0;
	moves_all[46].unique = 0;
	moves_all[46].pp_max = 10;
	moves_all[46].effect = APPLY_FRZ_E2;
	moves_all[46].chance = 0.1;
	moves_all[46].m_arg = 0;

	// ice punch
	strcpy(moves_all[47].name, "Ice Punch");
	moves_all[47].damage = 75;
	moves_all[47].accuracy = 1.0;
	moves_all[47].type = ICE_T;
	moves_all[47].movetype = PHYSICAL_MT;
	moves_all[47].priority = 0;
	moves_all[47].unique = 0;
	moves_all[47].pp_max = 15;
	moves_all[47].effect = APPLY_FRZ_E2;
	moves_all[47].chance = 0.1;
	moves_all[47].m_arg = 0;

	// karate chop
	strcpy(moves_all[48].name, "Karate Chop");
	moves_all[48].damage = 50;
	moves_all[48].accuracy = 1.0;
	moves_all[48].type = FIGHTING_T;
	moves_all[48].movetype = PHYSICAL_MT;
	moves_all[48].priority = 0;
	moves_all[48].unique = 0;
	moves_all[48].pp_max = 25;
	moves_all[48].effect = HIGH_CRIT_E2;
	moves_all[48].chance = 1.0;
	moves_all[48].m_arg = 0;

	// kinesis
	strcpy(moves_all[49].name, "Kinesis");
	moves_all[49].damage = 0;
	moves_all[49].accuracy = 0.8;
	moves_all[49].type = PSYCHIC_T;
	moves_all[49].movetype = STATUS_MT;
	moves_all[49].priority = 0;
	moves_all[49].unique = 0;
	moves_all[49].pp_max = 15;
	moves_all[49].effect = OTHR_ACCURACY_E2;
	moves_all[49].chance = 1.0;
	moves_all[49].m_arg = -1;

	// leech life
	strcpy(moves_all[50].name, "Leech Life");
	moves_all[50].damage = 20;
	moves_all[50].accuracy = 1.0;
	moves_all[50].type = BUG_T;
	moves_all[50].movetype = PHYSICAL_MT;
	moves_all[50].priority = 0;
	moves_all[50].unique = 0;
	moves_all[50].pp_max = 15;
	moves_all[50].effect = RECOIL_E2;
	moves_all[50].chance = 1.0;
	moves_all[50].m_arg = -2;

	// leer
	strcpy(moves_all[51].name, "Leer");
	moves_all[51].damage = 0;
	moves_all[51].accuracy = 1.0;
	moves_all[51].type = NORMAL_T;
	moves_all[51].movetype = STATUS_MT;
	moves_all[51].priority = 0;
	moves_all[51].unique = 0;
	moves_all[51].pp_max = 30;
	moves_all[51].effect = OTHR_DEFENSE_E2;
	moves_all[51].chance = 1.0;
	moves_all[51].m_arg = -1;

	// lick
	strcpy(moves_all[52].name, "Lick");
	moves_all[52].damage = 30;
	moves_all[52].accuracy = 1.0;
	moves_all[52].type = GHOST_T;
	moves_all[52].movetype = PHYSICAL_MT;
	moves_all[52].priority = 0;
	moves_all[52].unique = 0;
	moves_all[52].pp_max = 30;
	moves_all[52].effect = APPLY_PAR_E2;
	moves_all[52].chance = 0.3;
	moves_all[52].m_arg = 0;

	// lovely kiss
	strcpy(moves_all[53].name, "Lovely Kiss");
	moves_all[53].damage = 0;
	moves_all[53].accuracy = 0.75;
	moves_all[53].type = NORMAL_T;
	moves_all[53].movetype = STATUS_MT;
	moves_all[53].priority = 0;
	moves_all[53].unique = 0;
	moves_all[53].pp_max = 10;
	moves_all[53].effect = APPLY_SLP_E2;
	moves_all[53].chance = 1.0;
	moves_all[53].m_arg = 0;

	// meditate
	strcpy(moves_all[54].name, "Meditate");
	moves_all[54].damage = 0;
	moves_all[54].accuracy = 1.0;
	moves_all[54].type = PSYCHIC_T;
	moves_all[54].movetype = STATUS_MT;
	moves_all[54].priority = 0;
	moves_all[54].unique = 0;
	moves_all[54].pp_max = 40;
	moves_all[54].effect = SELF_ATTACK_E2;
	moves_all[54].chance = 1.0;
	moves_all[54].m_arg = 1;

	// mega drain
	strcpy(moves_all[55].name, "Mega Drain");
	moves_all[55].damage = 40;
	moves_all[55].accuracy = 1.0;
	moves_all[55].type = GRASS_T;
	moves_all[55].movetype = SPECIAL_MT;
	moves_all[55].priority = 0;
	moves_all[55].unique = 0;
	moves_all[55].pp_max = 15;
	moves_all[55].effect = RECOIL_E2;
	moves_all[55].chance = 1.0;
	moves_all[55].m_arg = -2;

	// mega kick
	strcpy(moves_all[56].name, "Mega Kick");
	moves_all[56].damage = 120;
	moves_all[56].accuracy = 0.75;
	moves_all[56].type = NORMAL_T;
	moves_all[56].movetype = PHYSICAL_MT;
	moves_all[56].priority = 0;
	moves_all[56].unique = 0;
	moves_all[56].pp_max = 5;
	moves_all[56].effect = NON_E2;
	moves_all[56].chance = 1.0;
	moves_all[56].m_arg = 0;

	// mega punch
	strcpy(moves_all[57].name, "Mega Punch");
	moves_all[57].damage = 80;
	moves_all[57].accuracy = 0.85;
	moves_all[57].type = NORMAL_T;
	moves_all[57].movetype = PHYSICAL_MT;
	moves_all[57].priority = 0;
	moves_all[57].unique = 0;
	moves_all[57].pp_max = 20;
	moves_all[57].effect = NON_E2;
	moves_all[57].chance = 1.0;
	moves_all[57].m_arg = 0;

	// minimize
	strcpy(moves_all[58].name, "Minimize");
	moves_all[58].damage = 0;
	moves_all[58].accuracy = 1.0;
	moves_all[58].type = NORMAL_T;
	moves_all[58].movetype = STATUS_MT;
	moves_all[58].priority = 0;
	moves_all[58].unique = 0;
	moves_all[58].pp_max = 10;
	moves_all[58].effect = SELF_EVASION_E2;
	moves_all[58].chance = 1.0;
	moves_all[58].m_arg = 2;

	// pay day
	strcpy(moves_all[59].name, "Pay Day");
	moves_all[59].damage = 40;
	moves_all[59].accuracy = 1.0;
	moves_all[59].type = NORMAL_T;
	moves_all[59].movetype = PHYSICAL_MT;
	moves_all[59].priority = 0;
	moves_all[59].unique = 0;
	moves_all[59].pp_max = 20;
	moves_all[59].effect = NON_E2;
	moves_all[59].chance = 1.0;
	moves_all[59].m_arg = 0;

	// peck
	strcpy(moves_all[60].name, "Peck");
	moves_all[60].damage = 35;
	moves_all[60].accuracy = 1.0;
	moves_all[60].type = FLYING_T;
	moves_all[60].movetype = PHYSICAL_MT;
	moves_all[60].priority = 0;
	moves_all[60].unique = 0;
	moves_all[60].pp_max = 35;
	moves_all[60].effect = NON_E2;
	moves_all[60].chance = 1.0;
	moves_all[60].m_arg = 0;

	// pin missile
	strcpy(moves_all[61].name, "Pin Missile");
	moves_all[61].damage = 25;
	moves_all[61].accuracy = 0.85;
	moves_all[61].type = BUG_T;
	moves_all[61].movetype = PHYSICAL_MT;
	moves_all[61].priority = 0;
	moves_all[61].unique = 0;
	moves_all[61].pp_max = 20;
	moves_all[61].effect = NON_E2;
	moves_all[61].chance = 1.0;
	moves_all[61].m_arg = 0;

	// poison gas
	strcpy(moves_all[62].name, "Poison Gas");
	moves_all[62].damage = 0;
	moves_all[62].accuracy = 0.9;
	moves_all[62].type = POISON_T;
	moves_all[62].movetype = STATUS_MT;
	moves_all[62].priority = 0;
	moves_all[62].unique = 0;
	moves_all[62].pp_max = 40;
	moves_all[62].effect = APPLY_PSN_E2;
	moves_all[62].chance = 1.0;
	moves_all[62].m_arg = 0;

	// poison powder
	strcpy(moves_all[63].name, "PoisonPowder");
	moves_all[63].damage = 0;
	moves_all[63].accuracy = 0.75;
	moves_all[63].type = POISON_T;
	moves_all[63].movetype = STATUS_MT;
	moves_all[63].priority = 0;
	moves_all[63].unique = 0;
	moves_all[63].pp_max = 35;
	moves_all[63].effect = APPLY_PSN_E2;
	moves_all[63].chance = 1.0;
	moves_all[63].m_arg = 0;

	// poison sting
	strcpy(moves_all[64].name, "Poison Sting");
	moves_all[64].damage = 15;
	moves_all[64].accuracy = 1.0;
	moves_all[64].type = POISON_T;
	moves_all[64].movetype = PHYSICAL_MT;
	moves_all[64].priority = 0;
	moves_all[64].unique = 0;
	moves_all[64].pp_max = 35;
	moves_all[64].effect = APPLY_PSN_E2;
	moves_all[64].chance = 0.3;
	moves_all[64].m_arg = 0;

	// pound
	strcpy(moves_all[65].name, "Pound");
	moves_all[65].damage = 40;
	moves_all[65].accuracy = 1.0;
	moves_all[65].type = NORMAL_T;
	moves_all[65].movetype = PHYSICAL_MT;
	moves_all[65].priority = 0;
	moves_all[65].unique = 0;
	moves_all[65].pp_max = 35;
	moves_all[65].effect = NON_E2;
	moves_all[65].chance = 1.0;
	moves_all[65].m_arg = 0;

	// psybeam
	strcpy(moves_all[66].name, "Psybeam");
	moves_all[66].damage = 65;
	moves_all[66].accuracy = 1.0;
	moves_all[66].type = PSYCHIC_T;
	moves_all[66].movetype = SPECIAL_MT;
	moves_all[66].priority = 0;
	moves_all[66].unique = 0;
	moves_all[66].pp_max = 20;
	moves_all[66].effect = APPLY_CONFUSE_E2;
	moves_all[66].chance = 0.1;
	moves_all[66].m_arg = 0;

	// psychic
	strcpy(moves_all[67].name, "Psychic");
	moves_all[67].damage = 90;
	moves_all[67].accuracy = 1.0;
	moves_all[67].type = PSYCHIC_T;
	moves_all[67].movetype = SPECIAL_MT;
	moves_all[67].priority = 0;
	moves_all[67].unique = 0;
	moves_all[67].pp_max = 10;
	moves_all[67].effect = OTHR_SDEFENSE_E2;
	moves_all[67].chance = 0.1;
	moves_all[67].m_arg = -1;

	// quick attack
	strcpy(moves_all[68].name, "Quick Attack");
	moves_all[68].damage = 40;
	moves_all[68].accuracy = 1.0;
	moves_all[68].type = NORMAL_T;
	moves_all[68].movetype = PHYSICAL_MT;
	moves_all[68].priority = 1;
	moves_all[68].unique = 0;
	moves_all[68].pp_max = 30;
	moves_all[68].effect = NON_E2;
	moves_all[68].chance = 1.0;
	moves_all[68].m_arg = 0;

	// razor leaf
	strcpy(moves_all[69].name, "Razor Leaf");
	moves_all[69].damage = 55;
	moves_all[69].accuracy = 0.95;
	moves_all[69].type = GRASS_T;
	moves_all[69].movetype = PHYSICAL_MT;
	moves_all[69].priority = 0;
	moves_all[69].unique = 0;
	moves_all[69].pp_max = 25;
	moves_all[69].effect = HIGH_CRIT_E2;
	moves_all[69].chance = 1.0;
	moves_all[69].m_arg = 0;

	// rock slide
	strcpy(moves_all[70].name, "Rock Slide");
	moves_all[70].damage = 75;
	moves_all[70].accuracy = 0.9;
	moves_all[70].type = ROCK_T;
	moves_all[70].movetype = PHYSICAL_MT;
	moves_all[70].priority = 0;
	moves_all[70].unique = 0;
	moves_all[70].pp_max = 10;
	moves_all[70].effect = APPLY_FLINCH_E2;
	moves_all[70].chance = 0.3;
	moves_all[70].m_arg = 0;

	// rock throw
	strcpy(moves_all[71].name, "Rock Throw");
	moves_all[71].damage = 50;
	moves_all[71].accuracy = 0.9;
	moves_all[71].type = ROCK_T;
	moves_all[71].movetype = PHYSICAL_MT;
	moves_all[71].priority = 0;
	moves_all[71].unique = 0;
	moves_all[71].pp_max = 15;
	moves_all[71].effect = NON_E2;
	moves_all[71].chance = 1.0;
	moves_all[71].m_arg = 0;

	// rolling kick
	strcpy(moves_all[72].name, "Rolling Kick");
	moves_all[72].damage = 60;
	moves_all[72].accuracy = 0.85;
	moves_all[72].type = FIGHTING_T;
	moves_all[72].movetype = PHYSICAL_MT;
	moves_all[72].priority = 0;
	moves_all[72].unique = 0;
	moves_all[72].pp_max = 15;
	moves_all[72].effect = APPLY_FLINCH_E2;
	moves_all[72].chance = 0.3;
	moves_all[72].m_arg = 0;

	// sand attack
	strcpy(moves_all[73].name, "Sand Attack");
	moves_all[73].damage = 0;
	moves_all[73].accuracy = 1.0;
	moves_all[73].type = GROUND_T;
	moves_all[73].movetype = STATUS_MT;
	moves_all[73].priority = 0;
	moves_all[73].unique = 0;
	moves_all[73].pp_max = 15;
	moves_all[73].effect = OTHR_ACCURACY_E2;
	moves_all[73].chance = 1.0;
	moves_all[73].m_arg = -1;

	// scratch
	strcpy(moves_all[74].name, "Scratch");
	moves_all[74].damage = 40;
	moves_all[74].accuracy = 1.0;
	moves_all[74].type = NORMAL_T;
	moves_all[74].movetype = PHYSICAL_MT;
	moves_all[74].priority = 0;
	moves_all[74].unique = 0;
	moves_all[74].pp_max = 35;
	moves_all[74].effect = NON_E2;
	moves_all[74].chance = 1.0;
	moves_all[74].m_arg = 0;

	// screech
	strcpy(moves_all[75].name, "Screech");
	moves_all[75].damage = 0;
	moves_all[75].accuracy = 0.85;
	moves_all[75].type = NORMAL_T;
	moves_all[75].movetype = STATUS_MT;
	moves_all[75].priority = 0;
	moves_all[75].unique = 0;
	moves_all[75].pp_max = 40;
	moves_all[75].effect = OTHR_DEFENSE_E2;
	moves_all[75].chance = 1.0;
	moves_all[75].m_arg = -2;

	// self-destruct
	strcpy(moves_all[76].name, "SelfDestruct");
	moves_all[76].damage = 200;
	moves_all[76].accuracy = 1.0;
	moves_all[76].type = NORMAL_T;
	moves_all[76].movetype = PHYSICAL_MT;
	moves_all[76].priority = 0;
	moves_all[76].unique = 0;
	moves_all[76].pp_max = 5;
	moves_all[76].effect = SELF_KILL_E2;
	moves_all[76].chance = 1.0;
	moves_all[76].m_arg = 0;

	// sharpen
	strcpy(moves_all[77].name, "Sharpen");
	moves_all[77].damage = 0;
	moves_all[77].accuracy = 1.0;
	moves_all[77].type = NORMAL_T;
	moves_all[77].movetype = STATUS_MT;
	moves_all[77].priority = 0;
	moves_all[77].unique = 0;
	moves_all[77].pp_max = 30;
	moves_all[77].effect = SELF_ATTACK_E2;
	moves_all[77].chance = 1.0;
	moves_all[77].m_arg = 1;

	// sing
	strcpy(moves_all[78].name, "Sing");
	moves_all[78].damage = 0;
	moves_all[78].accuracy = 0.55;
	moves_all[78].type = NORMAL_T;
	moves_all[78].movetype = STATUS_MT;
	moves_all[78].priority = 0;
	moves_all[78].unique = 0;
	moves_all[78].pp_max = 15;
	moves_all[78].effect = APPLY_SLP_E2;
	moves_all[78].chance = 1.0;
	moves_all[78].m_arg = 0;

	// slam
	strcpy(moves_all[79].name, "Slam");
	moves_all[79].damage = 80;
	moves_all[79].accuracy = 0.75;
	moves_all[79].type = NORMAL_T;
	moves_all[79].movetype = PHYSICAL_MT;
	moves_all[79].priority = 0;
	moves_all[79].unique = 0;
	moves_all[79].pp_max = 20;
	moves_all[79].effect = NON_E2;
	moves_all[79].chance = 1.0;
	moves_all[79].m_arg = 0;

	// slash
	strcpy(moves_all[80].name, "Slash");
	moves_all[80].damage = 70;
	moves_all[80].accuracy = 1.0;
	moves_all[80].type = NORMAL_T;
	moves_all[80].movetype = PHYSICAL_MT;
	moves_all[80].priority = 0;
	moves_all[80].unique = 0;
	moves_all[80].pp_max = 20;
	moves_all[80].effect = HIGH_CRIT_E2;
	moves_all[80].chance = 1.0;
	moves_all[80].m_arg = 0;

	// sleep powder
	strcpy(moves_all[81].name, "Sleep Powder");
	moves_all[81].damage = 0;
	moves_all[81].accuracy = 0.75;
	moves_all[81].type = GRASS_T;
	moves_all[81].movetype = STATUS_MT;
	moves_all[81].priority = 0;
	moves_all[81].unique = 0;
	moves_all[81].pp_max = 15;
	moves_all[81].effect = APPLY_SLP_E2;
	moves_all[81].chance = 1.0;
	moves_all[81].m_arg = 0;

	// sludge
	strcpy(moves_all[82].name, "Sludge");
	moves_all[82].damage = 65;
	moves_all[82].accuracy = 1.0;
	moves_all[82].type = POISON_T;
	moves_all[82].movetype = SPECIAL_MT;
	moves_all[82].priority = 0;
	moves_all[82].unique = 0;
	moves_all[82].pp_max = 20;
	moves_all[82].effect = APPLY_PSN_E2;
	moves_all[82].chance = 0.3;
	moves_all[82].m_arg = 0;

	// smog
	strcpy(moves_all[83].name, "Smog");
	moves_all[83].damage = 30;
	moves_all[83].accuracy = 0.7;
	moves_all[83].type = POISON_T;
	moves_all[83].movetype = SPECIAL_MT;
	moves_all[83].priority = 0;
	moves_all[83].unique = 0;
	moves_all[83].pp_max = 20;
	moves_all[83].effect = APPLY_PSN_E2;
	moves_all[83].chance = 0.4;
	moves_all[83].m_arg = 0;

	// smokescreen
	strcpy(moves_all[84].name, "Smokescreen");
	moves_all[84].damage = 0;
	moves_all[84].accuracy = 1.0;
	moves_all[84].type = NORMAL_T;
	moves_all[84].movetype = STATUS_MT;
	moves_all[84].priority = 0;
	moves_all[84].unique = 0;
	moves_all[84].pp_max = 20;
	moves_all[84].effect = OTHR_ACCURACY_E2;
	moves_all[84].chance = 1.0;
	moves_all[84].m_arg = -1;

	// splash
	strcpy(moves_all[85].name, "Splash");
	moves_all[85].damage = 0;
	moves_all[85].accuracy = 1.0;
	moves_all[85].type = NORMAL_T;
	moves_all[85].movetype = STATUS_MT;
	moves_all[85].priority = 0;
	moves_all[85].unique = 0;
	moves_all[85].pp_max = 40;
	moves_all[85].effect = NON_E2;
	moves_all[85].chance = 1.0;
	moves_all[85].m_arg = 0;

	// spore
	strcpy(moves_all[86].name, "Spore");
	moves_all[86].damage = 0;
	moves_all[86].accuracy = 1.0;
	moves_all[86].type = GRASS_T;
	moves_all[86].movetype = STATUS_MT;
	moves_all[86].priority = 0;
	moves_all[86].unique = 0;
	moves_all[86].pp_max = 15;
	moves_all[86].effect = APPLY_SLP_E2;
	moves_all[86].chance = 1.0;
	moves_all[86].m_arg = 0;

	// stomp
	strcpy(moves_all[87].name, "Stomp");
	moves_all[87].damage = 65;
	moves_all[87].accuracy = 1.0;
	moves_all[87].type = NORMAL_T;
	moves_all[87].movetype = PHYSICAL_MT;
	moves_all[87].priority = 0;
	moves_all[87].unique = 0;
	moves_all[87].pp_max = 20;
	moves_all[87].effect = APPLY_FLINCH_E2;
	moves_all[87].chance = 0.3;
	moves_all[87].m_arg = 0;

	// strength
	strcpy(moves_all[88].name, "Strength");
	moves_all[88].damage = 80;
	moves_all[88].accuracy = 1.0;
	moves_all[88].type = NORMAL_T;
	moves_all[88].movetype = PHYSICAL_MT;
	moves_all[88].priority = 0;
	moves_all[88].unique = 0;
	moves_all[88].pp_max = 15;
	moves_all[88].effect = NON_E2;
	moves_all[88].chance = 1.0;
	moves_all[88].m_arg = 0;

	// string shot
	strcpy(moves_all[89].name, "String Shot");
	moves_all[89].damage = 0;
	moves_all[89].accuracy = 0.95;
	moves_all[89].type = BUG_T;
	moves_all[89].movetype = STATUS_MT;
	moves_all[89].priority = 0;
	moves_all[89].unique = 0;
	moves_all[89].pp_max = 40;
	moves_all[89].effect = OTHR_SPEED_E2;
	moves_all[89].chance = 1.0;
	moves_all[89].m_arg = -2;

	// struggle
	strcpy(moves_all[90].name, "Struggle");
	moves_all[90].damage = 50;
	moves_all[90].accuracy = 1.0;
	moves_all[90].type = NORMAL_T;
	moves_all[90].movetype = PHYSICAL_MT;
	moves_all[90].priority = 0;
	moves_all[90].unique = 0;
	moves_all[90].pp_max = 0;
	moves_all[90].effect = RECOIL_E2;
	moves_all[90].chance = 1.0;
	moves_all[90].m_arg = 2;

	// stun spore
	strcpy(moves_all[91].name, "Stun Spore");
	moves_all[91].damage = 0;
	moves_all[91].accuracy = 0.75;
	moves_all[91].type = GRASS_T;
	moves_all[91].movetype = STATUS_MT;
	moves_all[91].priority = 0;
	moves_all[91].unique = 0;
	moves_all[91].pp_max = 30;
	moves_all[91].effect = APPLY_PAR_E2;
	moves_all[91].chance = 1.0;
	moves_all[91].m_arg = 0;

	// submission
	strcpy(moves_all[92].name, "Submission");
	moves_all[92].damage = 80;
	moves_all[92].accuracy = 0.8;
	moves_all[92].type = FIGHTING_T;
	moves_all[92].movetype = PHYSICAL_MT;
	moves_all[92].priority = 0;
	moves_all[92].unique = 0;
	moves_all[92].pp_max = 25;
	moves_all[92].effect = RECOIL_E2;
	moves_all[92].chance = 1.0;
	moves_all[92].m_arg = 4;

	// supersonic
	strcpy(moves_all[93].name, "Supersonic");
	moves_all[93].damage = 0;
	moves_all[93].accuracy = 0.55;
	moves_all[93].type = NORMAL_T;
	moves_all[93].movetype = STATUS_MT;
	moves_all[93].priority = 0;
	moves_all[93].unique = 0;
	moves_all[93].pp_max = 20;
	moves_all[93].effect = APPLY_CONFUSE_E2;
	moves_all[93].chance = 1.0;
	moves_all[93].m_arg = 0;

	// surf
	strcpy(moves_all[94].name, "Surf");
	moves_all[94].damage = 90;
	moves_all[94].accuracy = 1.0;
	moves_all[94].type = WATER_T;
	moves_all[94].movetype = SPECIAL_MT;
	moves_all[94].priority = 0;
	moves_all[94].unique = 0;
	moves_all[94].pp_max = 15;
	moves_all[94].effect = NON_E2;
	moves_all[94].chance = 1.0;
	moves_all[94].m_arg = 0;

	// swords dance
	strcpy(moves_all[95].name, "Swords Dance");
	moves_all[95].damage = 0;
	moves_all[95].accuracy = 1.0;
	moves_all[95].type = NORMAL_T;
	moves_all[95].movetype = STATUS_MT;
	moves_all[95].priority = 0;
	moves_all[95].unique = 0;
	moves_all[95].pp_max = 20;
	moves_all[95].effect = SELF_ATTACK_E2;
	moves_all[95].chance = 1.0;
	moves_all[95].m_arg = 2;

	// tackle
	strcpy(moves_all[96].name, "Tackle");
	moves_all[96].damage = 50;
	moves_all[96].accuracy = 1.0;
	moves_all[96].type = NORMAL_T;
	moves_all[96].movetype = PHYSICAL_MT;
	moves_all[96].priority = 0;
	moves_all[96].unique = 0;
	moves_all[96].pp_max = 35;
	moves_all[96].effect = NON_E2;
	moves_all[96].chance = 1.0;
	moves_all[96].m_arg = 0;

	// tail whip
	strcpy(moves_all[97].name, "Tail Whip");
	moves_all[97].damage = 0;
	moves_all[97].accuracy = 1.0;
	moves_all[97].type = NORMAL_T;
	moves_all[97].movetype = STATUS_MT;
	moves_all[97].priority = 0;
	moves_all[97].unique = 0;
	moves_all[97].pp_max = 30;
	moves_all[97].effect = OTHR_DEFENSE_E2;
	moves_all[97].chance = 1.0;
	moves_all[97].m_arg = -1;

	// take down
	strcpy(moves_all[98].name, "Take Down");
	moves_all[98].damage = 90;
	moves_all[98].accuracy = 0.85;
	moves_all[98].type = NORMAL_T;
	moves_all[98].movetype = PHYSICAL_MT;
	moves_all[98].priority = 0;
	moves_all[98].unique = 0;
	moves_all[98].pp_max = 20;
	moves_all[98].effect = RECOIL_E2;
	moves_all[98].chance = 1.0;
	moves_all[98].m_arg = 4;

	// thunder
	strcpy(moves_all[99].name, "Thunder");
	moves_all[99].damage = 110;
	moves_all[99].accuracy = 0.7;
	moves_all[99].type = ELECTRIC_T;
	moves_all[99].movetype = SPECIAL_MT;
	moves_all[99].priority = 0;
	moves_all[99].unique = 0;
	moves_all[99].pp_max = 10;
	moves_all[99].effect = APPLY_PAR_E2;
	moves_all[99].chance = 0.3;
	moves_all[99].m_arg = 0;

	// thunder punch
	strcpy(moves_all[100].name, "ThunderPunch");
	moves_all[100].damage = 75;
	moves_all[100].accuracy = 1.0;
	moves_all[100].type = ELECTRIC_T;
	moves_all[100].movetype = PHYSICAL_MT;
	moves_all[100].priority = 0;
	moves_all[100].unique = 0;
	moves_all[100].pp_max = 15;
	moves_all[100].effect = APPLY_PAR_E2;
	moves_all[100].chance = 0.1;
	moves_all[100].m_arg = 0;

	// thunder shock
	strcpy(moves_all[101].name, "ThunderShock");
	moves_all[101].damage = 40;
	moves_all[101].accuracy = 1.0;
	moves_all[101].type = ELECTRIC_T;
	moves_all[101].movetype = SPECIAL_MT;
	moves_all[101].priority = 0;
	moves_all[101].unique = 0;
	moves_all[101].pp_max = 30;
	moves_all[101].effect = APPLY_PAR_E2;
	moves_all[101].chance = 0.1;
	moves_all[101].m_arg = 0;

	// thunder wave
	strcpy(moves_all[102].name, "Thunder Wave");
	moves_all[102].damage = 0;
	moves_all[102].accuracy = 1.0;
	moves_all[102].type = ELECTRIC_T;
	moves_all[102].movetype = STATUS_MT;
	moves_all[102].priority = 0;
	moves_all[102].unique = 0;
	moves_all[102].pp_max = 20;
	moves_all[102].effect = APPLY_PAR_E2;
	moves_all[102].chance = 1.0;
	moves_all[102].m_arg = 0;

	// thunderbolt
	strcpy(moves_all[103].name, "Thunderbolt");
	moves_all[103].damage = 90;
	moves_all[103].accuracy = 1.0;
	moves_all[103].type = ELECTRIC_T;
	moves_all[103].movetype = SPECIAL_MT;
	moves_all[103].priority = 0;
	moves_all[103].unique = 0;
	moves_all[103].pp_max = 15;
	moves_all[103].effect = APPLY_PAR_E2;
	moves_all[103].chance = 0.1;
	moves_all[103].m_arg = 0;

	// toxic
	strcpy(moves_all[104].name, "Toxic");
	moves_all[104].damage = 0;
	moves_all[104].accuracy = 0.9;
	moves_all[104].type = POISON_T;
	moves_all[104].movetype = STATUS_MT;
	moves_all[104].priority = 0;
	moves_all[104].unique = 0;
	moves_all[104].pp_max = 10;
	moves_all[104].effect = APPLY_TXC_E2;
	moves_all[104].chance = 1.0;
	moves_all[104].m_arg = 0;

	// vice grip
	strcpy(moves_all[105].name, "Vice Grip");
	moves_all[105].damage = 55;
	moves_all[105].accuracy = 1.0;
	moves_all[105].type = NORMAL_T;
	moves_all[105].movetype = PHYSICAL_MT;
	moves_all[105].priority = 0;
	moves_all[105].unique = 0;
	moves_all[105].pp_max = 30;
	moves_all[105].effect = NON_E2;
	moves_all[105].chance = 1.0;
	moves_all[105].m_arg = 0;

	// vine whip
	strcpy(moves_all[106].name, "Vine Whip");
	moves_all[106].damage = 45;
	moves_all[106].accuracy = 1.0;
	moves_all[106].type = GRASS_T;
	moves_all[106].movetype = PHYSICAL_MT;
	moves_all[106].priority = 0;
	moves_all[106].unique = 0;
	moves_all[106].pp_max = 25;
	moves_all[106].effect = NON_E2;
	moves_all[106].chance = 1.0;
	moves_all[106].m_arg = 0;

	// water gun
	strcpy(moves_all[107].name, "Water Gun");
	moves_all[107].damage = 40;
	moves_all[107].accuracy = 1.0;
	moves_all[107].type = WATER_T;
	moves_all[107].movetype = SPECIAL_MT;
	moves_all[107].priority = 0;
	moves_all[107].unique = 0;
	moves_all[107].pp_max = 25;
	moves_all[107].effect = NON_E2;
	moves_all[107].chance = 1.0;
	moves_all[107].m_arg = 0;

	// waterfall
	strcpy(moves_all[108].name, "Waterfall");
	moves_all[108].damage = 80;
	moves_all[108].accuracy = 1.0;
	moves_all[108].type = WATER_T;
	moves_all[108].movetype = PHYSICAL_MT;
	moves_all[108].priority = 0;
	moves_all[108].unique = 0;
	moves_all[108].pp_max = 15;
	moves_all[108].effect = APPLY_FLINCH_E2;
	moves_all[108].chance = 0.2;
	moves_all[108].m_arg = 0;

	// wing attack
	strcpy(moves_all[109].name, "Wing Attack");
	moves_all[109].damage = 60;
	moves_all[109].accuracy = 1.0;
	moves_all[109].type = FLYING_T;
	moves_all[109].movetype = PHYSICAL_MT;
	moves_all[109].priority = 0;
	moves_all[109].unique = 0;
	moves_all[109].pp_max = 35;
	moves_all[109].effect = NON_E2;
	moves_all[109].chance = 1.0;
	moves_all[109].m_arg = 0;

	// withdraw
	strcpy(moves_all[110].name, "Withdraw");
	moves_all[110].damage = 0;
	moves_all[110].accuracy = 1.0;
	moves_all[110].type = WATER_T;
	moves_all[110].movetype = STATUS_MT;
	moves_all[110].priority = 0;
	moves_all[110].unique = 0;
	moves_all[110].pp_max = 40;
	moves_all[110].effect = SELF_DEFENSE_E2;
	moves_all[110].chance = 1.0;
	moves_all[110].m_arg = 1;
}

/*
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
}*/


void loadTrainer(trainer_s *trainer, char *file) { // load pkmn prior
	FILE *f = fopen(file, "rb");
	char data[DATASIZE + 10];
	fread(data, DATASIZE, 1, f);
	fclose(f);

	strcpy(trainer->name, data);
	trainer->pokemon_active = 0;
	trainer->action = NON_A;

	trainer->pokemon_count = (int)data[16];

	int i;
	for (i = 0; i < 6; ++i) {
		trainer->pokemon[i]->species 				= &specs_all[(int)data[17 + 20 * i] - 1];
		trainer->pokemon[i]->pstats.level 			= (int)data[18 + 20 * i];
		trainer->pokemon[i]->pstats.hp_ev 			= (int)data[19 + 20 * i];
		trainer->pokemon[i]->pstats.hp_iv 			= (int)data[20 + 20 * i];
		trainer->pokemon[i]->pstats.attack_ev 		= (int)data[21 + 20 * i];
		trainer->pokemon[i]->pstats.attack_iv 		= (int)data[22 + 20 * i];
		trainer->pokemon[i]->pstats.defense_ev 		= (int)data[23 + 20 * i];
		trainer->pokemon[i]->pstats.defense_iv 		= (int)data[24 + 20 * i];
		trainer->pokemon[i]->pstats.sattack_ev 		= (int)data[25 + 20 * i];
		trainer->pokemon[i]->pstats.sattack_iv 		= (int)data[26 + 20 * i];
		trainer->pokemon[i]->pstats.sdefense_ev 	= (int)data[27 + 20 * i];
		trainer->pokemon[i]->pstats.sdefense_iv 	= (int)data[28 + 20 * i];
		trainer->pokemon[i]->pstats.speed_ev 		= (int)data[29 + 20 * i];
		trainer->pokemon[i]->pstats.speed_iv 		= (int)data[30 + 20 * i];
		trainer->pokemon[i]->pstats.nature 			= (int)data[31 + 20 * i];

		trainer->pokemon[i]->v.attack_stage 		= 0;
		trainer->pokemon[i]->v.defense_stage 		= 0;
		trainer->pokemon[i]->v.sattack_stage 		= 0;
		trainer->pokemon[i]->v.sdefense_stage 		= 0;
		trainer->pokemon[i]->v.speed_stage 			= 0;
		trainer->pokemon[i]->v.accuracy_stage 		= 0;
		trainer->pokemon[i]->v.evasion_stage 		= 0;
		trainer->pokemon[i]->v.is_flinch 			= false;
		trainer->pokemon[i]->v.is_recharge 			= false;
		trainer->pokemon[i]->v.is_confuse 			= false;
		trainer->pokemon[i]->nv.hp 					= calc_hpmax(&trainer->pokemon[i]);
		trainer->pokemon[i]->nv.nvstatus 			= NON_S;
		trainer->pokemon[i]->nv.nv_arg 				= 0;

		trainer->pokemon[i]->move_count 			= (int)data[32 + 20 * i];
		trainer->pokemon[i]->moves[0] 				= &moves_all[(int)data[33 + 20 * i]];
		trainer->pokemon[i]->moves[1] 				= &moves_all[(int)data[34 + 20 * i]];
		trainer->pokemon[i]->moves[2] 				= &moves_all[(int)data[35 + 20 * i]];
		trainer->pokemon[i]->moves[3] 				= &moves_all[(int)data[36 + 20 * i]];

		trainer->pokemon[i]->pp[0] 					= trainer->pokemon[i]->moves[0]->pp_max;
		trainer->pokemon[i]->pp[1] 					= trainer->pokemon[i]->moves[1]->pp_max;
		trainer->pokemon[i]->pp[2] 					= trainer->pokemon[i]->moves[2]->pp_max;
		trainer->pokemon[i]->pp[3] 					= trainer->pokemon[i]->moves[3]->pp_max;
	}
	printf("%i\n", i * 20 + 37);
}

void debugTeam() {
	strcpy(RED.name, "RED");
	strcpy(BLUE.name, "BLUE");

	RED.pokemon_count = 6;
	BLUE.pokemon_count = 6;

	RED.pokemon_active = 0;
	RED.action = NON_A;

	BLUE.pokemon_active = 0;
	BLUE.action = NON_A;

	int i;
	for (i = 0; i < 12; ++i) {
		rentals_all[i].species 				= &specs_all[0];
		rentals_all[i].pstats.level 			= 100;
		rentals_all[i].pstats.hp_ev 			= 0;
		rentals_all[i].pstats.hp_iv 			= 0;
		rentals_all[i].pstats.attack_ev 		= 0;
		rentals_all[i].pstats.attack_iv 		= 0;
		rentals_all[i].pstats.defense_ev 	= 0;
		rentals_all[i].pstats.defense_iv 	= 0;
		rentals_all[i].pstats.sattack_ev 	= 0;
		rentals_all[i].pstats.sattack_iv 	= 0;
		rentals_all[i].pstats.sdefense_ev 	= 0;
		rentals_all[i].pstats.sdefense_iv 	= 0;
		rentals_all[i].pstats.speed_ev 		= 0;
		rentals_all[i].pstats.speed_iv 		= 0;
		rentals_all[i].pstats.nature 		= 0;

		rentals_all[i].v.attack_stage 		= 0;
		rentals_all[i].v.defense_stage 		= 0;
		rentals_all[i].v.sattack_stage 		= 0;
		rentals_all[i].v.sdefense_stage 		= 0;
		rentals_all[i].v.speed_stage 		= 0;
		rentals_all[i].v.accuracy_stage 		= 0;
		rentals_all[i].v.evasion_stage 		= 0;
		rentals_all[i].v.is_flinch 			= false;
		rentals_all[i].v.is_recharge 		= false;
		rentals_all[i].v.is_confuse 			= false;
		rentals_all[i].nv.hp 				= calc_hpmax(&rentals_all[i]);
		rentals_all[i].nv.nvstatus 			= NON_S;
		rentals_all[i].nv.nv_arg 			= 0;

		rentals_all[i].move_count 			= 4;
		rentals_all[i].moves[0] 				= &moves_all[0];
		rentals_all[i].moves[1] 				= &moves_all[1];
		rentals_all[i].moves[2] 				= &moves_all[2];
		rentals_all[i].moves[3] 				= &moves_all[3];

		rentals_all[i].pp[0] 				= rentals_all[i].moves[0]->pp_max;
		rentals_all[i].pp[1] 				= rentals_all[i].moves[1]->pp_max;
		rentals_all[i].pp[2] 				= rentals_all[i].moves[2]->pp_max;
		rentals_all[i].pp[3] 				= rentals_all[i].moves[3]->pp_max;
	}
}

void init_trainers() {
	RED.pokemon[0] = &rentals_all[0];
	RED.pokemon[1] = &rentals_all[1];
	RED.pokemon[2] = &rentals_all[2];
	RED.pokemon[3] = &rentals_all[3];
	RED.pokemon[4] = &rentals_all[4];
	RED.pokemon[5] = &rentals_all[5];

	BLUE.pokemon[0] = &rentals_all[6];
	BLUE.pokemon[1] = &rentals_all[7];
	BLUE.pokemon[2] = &rentals_all[8];
	BLUE.pokemon[3] = &rentals_all[9];
	BLUE.pokemon[4] = &rentals_all[10];
	BLUE.pokemon[5] = &rentals_all[11];

	//debugTeam();
	//RED.action = NON_A;
	//BLUE.action = NON_A;

	loadTrainer(&RED, "RED");
	loadTrainer(&BLUE, "BLUE");
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