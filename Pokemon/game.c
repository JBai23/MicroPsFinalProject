#include <stdio.h>

#include "types.h"

#include "pokemon-def.h"
#include "moves-def.h"
// #include "rentals-def.h"

// include phases
#include "input-p.h"
#include "battle-p.h"
#include "eor-p.h"
#include "win-p.h"

#include "global.h" // needs everything else before it

#include "game.h"

// functions


void game() {
	win_t winner = NON_W;

	while (win_phase(&winner)) {
		printf("==================================================\n");
		printf("\n");
		printf("--------------------------------------------------\n");
		printf("%s  HP: %i / %i  %s\n", PLAYER1_PNAME, PLAYER1_POKEMON->nv.hp, calc_hpmax(PLAYER1_POKEMON), get_statusname(PLAYER1_POKEMON->nv.nvstatus));
		printf("%s  HP: %i / %i  %s\n", PLAYER2_PNAME, PLAYER2_POKEMON->nv.hp, calc_hpmax(PLAYER2_POKEMON), get_statusname(PLAYER2_POKEMON->nv.nvstatus));
		printf("--------------------------------------------------\n");
		printf("\n");
		input_phase();
		printf("\n");
		battle_phase();
		eor_phase();
		
	}

	switch (winner) {
		case P1WIN_W:
			printf("%s wins!\n", PLAYER1->name);
			break;
		case P2WIN_W:
			printf("%s wins!\n", PLAYER2->name);
			break;
		case DRAW_W:
			printf("Game is a draw!\n");
			break;
		case NON_W:
		default:
			break;
	}
	printf("\n\n\n");
}

void init() {
	init_menus();
	init_echart();
	init_pokemonspec();
	init_moves();
	init_rentals();
	init_trainers();
	init_battle();
}

// main
int main()
{
	void init_rng();
	printf("Oak: Are you a boy or girl?\n\n");
	while (true) {
		init();
		printf("%s and %s want to battle!\n\n", PLAYER1_NAME, PLAYER2_NAME);
		game();
	}
}