
#include "win-p.h"

bool can_fight(player_s *player) {
	int i;
	for (i = 0; i < player->pokemon_count; ++i) {
		if (player->pokemon[i].nv.nvstatus != FNT_S) {
			return true;
		}
	}
	return false;
}

bool win_phase(win_t *winner) {
	return true;
}