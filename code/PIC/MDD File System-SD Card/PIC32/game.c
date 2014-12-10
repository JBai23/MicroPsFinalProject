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

#include "bitbang.h"

// functions


void game() {
	win_t winner = NON_W;

	display_pokemon();
	display_hp();
	
	while (win_phase(&winner)) {
		//text_clear();
		input_phase();
		text_clear();
		battle_phase();
		eor_phase();
		//text_clear();
	}

	switch (winner) {
		case P1WIN_W:
			// printf("%s wins!", PLAYER1->name);
			sendCompressedSpriteFile(1, 2112, "EmptySprite");
			break;
		case P2WIN_W:
			// printf("%s wins!", PLAYER2->name);
			sendCompressedSpriteFile(0, 2112, "EmptySprite");
			break;
		case DRAW_W:
			// printf("Game is a draw!");
			sendCompressedSpriteFile(0, 2112, "EmptySprite");
			sendCompressedSpriteFile(1, 2112, "EmptySprite");
			break;
		case NON_W:
		default:
			break;
	}
	while(1);
	// printf("\n\n");
}

void init() {
	init_menus();
	init_echart();
	init_pokemonspec();
	init_moves();
	init_rentals();
	init_trainers();
	init_battle();
	init_textbox();
}

#include <P32xxxx.h>
// main
int begin()
{
    //TMR1 = 52732572;
	//T1CON = 0b1001000000000000;
	init_rng();
	// printf("Oak: Are you a boy or girl?\n");
	while (true) {
		init();
		sprintf(msg, "%s and %s want to battle!", PLAYER1_NAME, PLAYER2_NAME); send();
		text_clear();
		game();
	}
}