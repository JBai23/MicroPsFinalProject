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
	init_battle();
}

// main
int main()
{
	init();
    printf("Hello World\n");

    action_t out = get_action(&turn_menu);
    printf("%i", out);
}