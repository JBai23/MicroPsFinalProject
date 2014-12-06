
#include "battle.h"
#include "moves.h"
#include "pokemon.h"

#ifndef RNT_H
#define RNT_H 1

#define PSTATS_DEFAULT {.level = 100, .hp_ev = 0, .hp_iv = 0, .attack_ev = 0, .attack_iv = 0, .defense_ev = 0, .defense_iv = 0, .sattack_ev = 0, .sattack_iv = 0, .sdefense_ev = 0, .sdefense_iv = 0, .speed_ev = 0, .speed_iv = 0, BASHFUL_N}
#define V_DEFAULT {.attack_stage = 0, .defense_stage = 0, .sattack_stage = 0, .sdefense_stage = 0, .speed_stage = 0, .is_flinch = 0, .is_confuse = 0, .is_rechage = 0}
#define NV_DEFAULT {.hp = 1, NON_S, 0}


// red
pokemon_s_s RED_PIKACHU = {
.species = &PIKACHU,
.pstats = PSTATS_DEFAULT,
.v = V_DEFAULT,
.nv = NV_DEFAULT,
.moves = {&THUNDER, &THUNDERBOLT, &THUNDERWAVE, &QUICKATTACK},
.move_count = 4
};

pokemon_s_s RED_LAPRAS = {
.species = &LAPRAS,
.pstats = PSTATS_DEFAULT,
.v = V_DEFAULT,
.nv = NV_DEFAULT,
.moves = {&SURF, &ICEBEAM, &CONFUSERAY, &BODYSLAM},
.move_count = 4
};

pokemon_s_s RED_SNORLAX = {
.species = &SNORLAX,
.pstats = PSTATS_DEFAULT,
.v = V_DEFAULT,
.nv = NV_DEFAULT,
.moves = {&BODYSLAM, &STRENGTH, &HYPERBEAM, &AMNESIA},
.move_count = 4
};

pokemon_s_s RED_VENUSAUR = {
.species = &VENUSAUR,
.pstats = PSTATS_DEFAULT,
.v = V_DEFAULT,
.nv = NV_DEFAULT,
.moves = {&RAZORLEAF, &GROWTH, &SLEEPPOWDER, &TOXIC},
.move_count = 4
};

pokemon_s_s RED_CHARIZARD = {
.species = &CHARIZARD,
.pstats = PSTATS_DEFAULT,
.v = V_DEFAULT,
.nv = NV_DEFAULT,
.moves = {&FLAMETHROWER, &WINGATTACK, &SLASH, &FIREBLAST},
.move_count = 4
};

pokemon_s_s RED_BLASTOISE = {
.species = &BLASTOISE,
.pstats = PSTATS_DEFAULT,
.v = V_DEFAULT,
.nv = NV_DEFAULT,
.moves = {&SURF, &HYDROPUMP, &WITHDRAW, &MEGAPUNCH},
.move_count = 4
};

// blue
pokemon_s_s BLUE_PIDGEOT = {
.species = &PIDGEOT,
.pstats = PSTATS_DEFAULT,
.v = V_DEFAULT,
.nv = NV_DEFAULT,
.moves = {&GUST, &WINGATTACK, &AGILITY, &SANDATTACK},
.move_count = 4
};

pokemon_s_s BLUE_ALAKAZAM = {
.species = &ALAKAZAM,
.pstats = PSTATS_DEFAULT,
.v = V_DEFAULT,
.nv = NV_DEFAULT,
.moves = {&PSYCHIC, &PSYBEAM, &CONFUSION, &TOXIC},
.move_count = 4
};

pokemon_s_s BLUE_RHYDON = {
.species = &RHYDON,
.pstats = PSTATS_DEFAULT,
.v = V_DEFAULT,
.nv = NV_DEFAULT,
.moves = {&EARTHQUAKE, &HORNDRILL, &ROCKSLIDE, &TAKEDOWN},
.move_count = 4
};

pokemon_s_s BLUE_ARCANINE = {
.species = &ARCANINE,
.pstats = PSTATS_DEFAULT,
.v = V_DEFAULT,
.nv = NV_DEFAULT,
.moves = {&FLAMETHROWER, &TAKEDOWN, &BITE, &FIREBLAST},
.move_count = 4
};

pokemon_s_s BLUE_EXEGGUTOR = {
.species = &EXEGGUTOR,
.pstats = PSTATS_DEFAULT,
.v = V_DEFAULT,
.nv = NV_DEFAULT,
.moves = {&EGGBOMB, &RAZORLEAF, &SLEEPPOWDER, &PSYCHIC},
.move_count = 4
};

pokemon_s_s BLUE_BLASTOISE = {
.species = &BLASTOISE,
.pstats = PSTATS_DEFAULT,
.v = V_DEFAULT,
.nv = NV_DEFAULT,
.moves = {&SURF, &EARTHQUAKE, &HYDROPUMP, &BLIZZARD},
.move_count = 4
};


// (pstats.hp_iv + (2 * species.bstats.hp_base) + pstats.hp_ev / 4 + 100) * pstats.level / 100 + 10

#endif
