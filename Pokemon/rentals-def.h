#ifndef RNT_H
#define RNT_H 1

#include "pkmn-tdef.h"
#include "moves-def.h"
#include "pokemon-def.h"

#define PSTATS_DEFAULT {.level = 100, .hp_ev = 0, .hp_iv = 0, .attack_ev = 0, .attack_iv = 0, .defense_ev = 0, .defense_iv = 0, .sattack_ev = 0, .sattack_iv = 0, .sdefense_ev = 0, .sdefense_iv = 0, .speed_ev = 0, .speed_iv = 0, BASHFUL_N}
#define V_DEFAULT {.attack_stage = 0, .defense_stage = 0, .sattack_stage = 0, .sdefense_stage = 0, .speed_stage = 0, .is_flinch = 0, .is_confuse = 0, .is_recharge = 0}
#define NV_DEFAULT {.hp = 1, NON_S, 0}


// red
pokemon_s RED_PIKACHU;
pokemon_s RED_LAPRAS;
pokemon_s RED_SNORLAX;
pokemon_s RED_VENUSAUR;
pokemon_s RED_CHARIZARD;
pokemon_s RED_BLASTOISE;

// blue
pokemon_s BLUE_PIDGEOT;
pokemon_s BLUE_ALAKAZAM;
pokemon_s BLUE_RHYDON;
pokemon_s BLUE_ARCANINE;
pokemon_s BLUE_EXEGGUTOR;
pokemon_s BLUE_BLASTOISE;


// (pstats.hp_iv + (2 * species.bstats.hp_base) + pstats.hp_ev / 4 + 100) * pstats.level / 100 + 10

#endif
