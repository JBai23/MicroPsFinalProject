#include <stdio.h>
#include "gdefines.h"
#include "battle.h"
#include "pokemon.h"
#include "moves.h"
#include "rentals.h"

#include "battlestate.h"

// include phases
#include "inputphase.h"

#include "game.h"

// functions
bool can_fight(player_s *player) {
	size_t i;
	for (i = 0; i < player->pokemon_count; ++i) {
		if (player->pokemon[i].nv.nvstatus != FNT_S) {
			return true;
		}
	}
	return false;
}

int battle_phase() {
	return 1;
}

int end_phase() {
	return 1;
}

int win_phase() {
	return 1;
}


int game() {
	while (1) {
		input_phase();
		battle_phase();
		end_phase();
		win_phase();
	}
}

int debug_init() {

}

//effective_t echart[18][18];

int init() {
	init_menus();
	init_echart();
}

// main
int main()
{
	init();
	player_s RED = {"Red", {RED_PIKACHU, RED_LAPRAS, RED_SNORLAX, RED_VENUSAUR, RED_CHARIZARD, RED_BLASTOISE}, 6};
	player_s BLUE = {"Blue", {BLUE_PIDGEOT, BLUE_ALAKAZAM, BLUE_RHYDON, BLUE_ARCANINE, BLUE_EXEGGUTOR, BLUE_BLASTOISE}, 6};
    printf("Hello World\n");

    action_t out = get_action(&turn_menu);
    printf("%i", out);
}