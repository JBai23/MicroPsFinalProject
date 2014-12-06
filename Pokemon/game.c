#include "global.h"
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

int input_phase() {
	return 1;
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

int init() {
	
}

// main
int main()
{
	player_s RED = {"Red", {RED_PIKACHU, RED_LAPRAS, RED_SNORLAX, RED_VENUSAUR, RED_CHARIZARD, RED_BLASTOISE}, 6};
	player_s BLUE = {"Blue", {BLUE_PIDGEOT, BLUE_ALAKAZAM, BLUE_RHYDON, BLUE_ARCANINE, BLUE_EXEGGUTOR, BLUE_BLASTOISE}, 6};
    printf("Hello World\n");
}