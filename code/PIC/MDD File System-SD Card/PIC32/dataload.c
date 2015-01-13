#include "dataload.h"


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