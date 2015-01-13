
#include "pkmn-tdef.h"
#include "types.h"
#include <stdio.h>
#include "eor-p.h"
#include "global.h"

void do_eoreffects() {
	do_brn(PLAYER1_POKEMON);
	do_psn(PLAYER1_POKEMON);
	do_txc(PLAYER1_POKEMON);

	do_brn(PLAYER2_POKEMON);
	do_psn(PLAYER2_POKEMON);
	do_txc(PLAYER2_POKEMON);
}

void do_brn(pokemon_s *pokemon) { // 1/8 dmg
	if (pokemon->nv.nvstatus == BRN_S) {
		int damage = calc_hpmax(pokemon) / 8;
		// printf("%s is hurt by burn!", pokemon->species->name);
		// printf("[%s took %i burn damage]", pokemon->species->name, damage);
		apply_damage(pokemon, damage);
		// printf("");
	}
}

void do_psn(pokemon_s *pokemon) { // 1/8 dmg
	if (pokemon->nv.nvstatus == PSN_S) {
		int damage = calc_hpmax(pokemon) / 8;
		// printf("%s is hurt by poison!", pokemon->species->name);
		// printf("[%s took %i poison damage]", pokemon->species->name, damage);
		apply_damage(pokemon, damage);
		// printf("");
	}
}

void do_txc(pokemon_s *pokemon) { // 1/16 * nv_arg
	if (pokemon->nv.nvstatus == TXC_S) {
		int damage = calc_hpmax(pokemon) * pokemon->nv.nv_arg / 16;
		// printf("%s is hurt by toxic!", pokemon->species->name);
		// printf("[%s took %i toxic damage]", pokemon->species->name, damage);
		apply_damage(pokemon, damage);
		pokemon->nv.nv_arg++; // this should reset on switch out
		// printf("");
	}
}

void eor_phase() {
	do_eoreffects();
}