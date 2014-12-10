#ifndef PKMTD_H
#define PKMTD_H 1


#include "gdefines.h"



typedef enum {
	BASHFUL_N = 0, DOCILE_N = 1, HARDY_N = 2, QUIRKY_N = 3, SERIOUS_N = 4, // neutral
	LONELY_N = 5, ADAMANT_N = 6, NAUGHTY_N = 7, BRAVE_N = 8, // +attack
	BOLD_N = 9, IMPISH_N = 10, LAX_N = 11, RELAXED_N = 12, // +sattack
	MODEST_N = 13, MILD_N = 14, RASH_N = 15, QUIET_N = 16, // +defense
	CALM_N = 17, GENTLE_N = 18, CAREFUL_N = 19, SASSY_N = 20, // +sdefense
	TIMID_N = 21, HASTY_N = 22, JOLLY_N = 23, NAIVE_N = 24 // +speed
} nature_t; // N = Nature

typedef struct {
	int hp_base;
	int attack_base;
	int defense_base;
	int sattack_base;
	int sdefense_base;
	int speed_base;
} basestats_s; // stats

typedef struct {
	int level;

	int hp_ev;
	int hp_iv;

	int attack_ev;
	int attack_iv;

	int defense_ev;
	int defense_iv;

	int sattack_ev;
	int sattack_iv;

	int sdefense_ev;
	int sdefense_iv;

	int speed_ev;
	int speed_iv;

	nature_t nature;
} personalstats_s;

typedef enum {
	NON_S, FNT_S, BRN_S, FRZ_S, PAR_S, PSN_S, TXC_S, SLP_S // S = NON-VOLITILE STATUS
} nvstatus_t; // nonvolitile statuses

typedef enum {
	NON_T, 
	NORMAL_T = 0, FIGHTING_T = 1, FLYING_T = 2, POISON_T = 3,
	GROUND_T = 4, ROCK_T = 5, BUG_T = 6, GHOST_T = 7,
	STEEL_T = 8, FIRE_T = 9, WATER_T = 10 , GRASS_T = 11,
	ELECTRIC_T = 12, PSYCHIC_T = 13, ICE_T = 14, DRAGON_T = 15,
	DARK_T = 16, FAIRY_T = 17
} type_t; // types

typedef enum {
	SUPER_TE, NORMAL_TE, NOTVERY_TE, NOEFFECT_TE // TE = TYPE EFFECTIVENESS
} effective_t; // typing effectiveness

typedef enum {
	NON_E2, APPLY_BRN_E2, APPLY_FRZ_E2, APPLY_PAR_E2, APPLY_PSN_E2, APPLY_TXC_E2, APPLY_SLP_E2,
	APPLY_FLINCH_E2, APPLY_CONFUSE_E2,
	HIGH_CRIT_E2, SELF_KILL_E2,
	SELF_ATTACK_E2, SELF_DEFENSE_E2, SELF_SATTACK_E2, SELF_SDEFENSE_E2, SELF_SPEED_E2, SELF_ACCURACY_E2, SELF_EVASION_E2,
	OTHR_ATTACK_E2, OTHR_DEFENSE_E2, OTHR_SATTACK_E2, OTHR_SDEFENSE_E2, OTHR_SPEED_E2, OTHR_ACCURACY_E2, OTHR_EVASION_E2,
	SELF_ATTACK_SATTACK_E2, HAZE_E2,
	RECOIL_E2, RECHARGE_E2
	// E2 = SECONDARY EFFECT
} move2nd_t;

typedef enum {
	PHYSICAL_MT, SPECIAL_MT, STATUS_MT // MT = MOVE TYPE
} move_t;

typedef struct {
	char name[STRSIZE];
	int damage;
	double accuracy;
	type_t type;
	move_t movetype;
	int priority;

	int unique;
	int pp_max;

	move2nd_t effect;
	double chance;
	int m_arg;
} move_s;

typedef struct {
	int hp;
	nvstatus_t nvstatus;
	int nv_arg;
} nonvolitile_s;

typedef struct {
	int attack_stage;
	int defense_stage;
	int sattack_stage;
	int sdefense_stage;
	int speed_stage;

	int accuracy_stage;
	int evasion_stage;

	bool is_flinch;
	bool is_recharge;
	bool is_confuse;
} volitile_s;

typedef struct {
	char name[STRSIZE];
	int id;
	type_t type1;
	type_t type2;
	basestats_s bstats;
} pokemonspec_s;

typedef struct {
	pokemonspec_s* species; // const
	personalstats_s pstats; // const

	volitile_s v;
	nonvolitile_s nv;

	move_s *moves[4]; // const
	int pp[4];
	int move_count; // const
} pokemon_s;

typedef enum {
	MOVE1_A, MOVE2_A, MOVE3_A, MOVE4_A,
	PKMN1_A, PKMN2_A, PKMN3_A, PKMN4_A, PKMN5_A, PKMN6_A,
	SURRENDER_A, NON_A
} action_t;

typedef struct {
	char name[STRSIZE]; // const
	pokemon_s *pokemon[6];
	int pokemon_active;
	action_t action;
	int pokemon_count; // const
} trainer_s;

#endif
