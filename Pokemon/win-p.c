
#include "win-p.h"
#include "global.h"

bool can_fight(trainer_s *trainer) {
	int i;
	for (i = 0; i < trainer->pokemon_count; ++i) {
		if (trainer->pokemon[i]->nv.nvstatus != FNT_S) {
			return true;
		}
	}
	return false;
}

bool win_phase(win_t *winner) {
	bool p1_alive = can_fight(PLAYER1);
	bool p2_alive = can_fight(PLAYER2);

	if (p1_alive && p2_alive) { // keep going
		return true;
	}

	if (!p1_alive && !p2_alive) { // draw
		*winner = DRAW_W;
		return false;
	}

	if (p1_alive) {
		*winner = P1WIN_W; // player1 win
		return false;
	} else {
		*winner = P2WIN_W; // player2 win
		return false;
	}

}