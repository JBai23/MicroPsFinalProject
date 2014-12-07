#include <stdio.h>

#include "types.h"

#include "pokemon-def.h"
#include "moves-def.h"
#include "rentals-def.h"

// include phases
#include "input-p.h"
#include "battle-p.h"
#include "eor-p.h"
#include "win-p.h"

#include "global.h" // needs everything else before it

#include "game.h"

// functions


int game() {

	win_t winner = NON_W;

	while (win_phase(&winner)) {
		input_phase();
		battle_phase();
		eor_phase();
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