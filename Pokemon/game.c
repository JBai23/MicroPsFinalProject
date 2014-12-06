#include <stdio.h>
#include "battle.h"
#include "pokemon.h"
#include "moves.h"
#include "rentals.h"

typedef int bool;
#define true 1
#define false 0

player_s *player1;
player_s *player2;

player_s *curr_player;
player_s *othr_player;

pokemon_s *curr_pokemon;
pokemon_s *othr_pokemon;

int last_dmg;
move_s *last_move;

bool can_fight(player_s& player) {
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


int main()
{
	player_s RED = {"Red", {RED_PIKACHU, RED_LAPRAS, RED_SNORLAX, RED_VENUSAUR, RED_CHARIZARD, RED_BLASTOISE}, 6};
	player_s BLUE = {"Blue", {BLUE_PIDGEOT, BLUE_ALAKAZAM, BLUE_RHYDON, BLUE_ARCANINE, BLUE_EXEGGUTOR, BLUE_BLASTOISE}, 6};
    printf("Hello World\n");
}