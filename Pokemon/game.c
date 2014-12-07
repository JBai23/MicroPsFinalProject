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
		printf("\n");
		printf("%s  HP: %i / %i\n", PLAYER1_POKEMON->species->name, PLAYER1_POKEMON->nv.hp, calc_hpmax(PLAYER1_POKEMON));
		printf("%s  HP: %i / %i\n", PLAYER2_POKEMON->species->name, PLAYER2_POKEMON->nv.hp, calc_hpmax(PLAYER2_POKEMON));
		printf("\n");
		input_phase();
		printf("\n");
		battle_phase();
		eor_phase();
	}

	switch (winner) {
		case P1WIN_W:
			printf("P1:%s wins!\n", PLAYER1->name);
			break;
		case P2WIN_W:
			printf("P2:%s wins!\n", PLAYER2->name);
			break;
		case DRAW_W:
			printf("Game is a draw!\n");
			break;
		case NON_W:
		default:
			break;
	}
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
	printf("Hello World\n");
	while (true) {
		printf("Init New Match\n");
		init();
		printf("P1:%s and P2:%s want to battle!\n", PLAYER1->name, PLAYER2->name);
		game();
	}
}