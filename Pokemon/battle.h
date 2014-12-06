
#ifndef BTL_H
#define BTL_H 1

typedef enum {
	BASHFUL_N, DOCILE_N, HARDY_N, QUIRKY_N, SERIOUS_N, // neutral
	LONELY_N, ADAMANT_N, NAUGHTY_N, BRAVE_N, // +attack
	BOLD_N, IMPISH_N, LAX_N, RELAXED_N, // +sattack
	MODEST_N, MILD_N, RASH_N, QUIET_N, // +defense
	CALM_N, GENTLE_N, CAREFUL_N, SASSY_N, // +sdefense
	TIMID_N, HASTY_N, JOLLY_N, NAIVE_N // +speed
} nature_t; // N = Nature

typedef struct {
	int hp_base;
	int attack_base;
	int defense_base;
	int sattack_base;
	int sdefence_base;
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
	NON_T, NORMAL_T, FIRE_T, FIGHTING_T, WATER_T, FLYING_T, GRASS_T, POISON_T,
	ELECTRIC_T, GROUND_T, PSYCHIC_T, ROCK_T, ICE_T, BUG_T, DRAGON_T, GHOST_T,
	DARK_T, STEEL_T, FAIRY_T
} type_t; // types

typedef enum {
	SUPER_TE, NORMAL_TE, NOTVERY_TE, NOEFFECT_TE // TE = TYPE EFFECTIVENESS
} effective_t; // typing effectiveness

typedef struct {

} condition_s; // 

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
	char name[32];
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

	bool is_flinch;
	bool is_confuse;
	bool is_rechage;
} volitile_s;

typedef struct {
	char name[32];
	int id;
	type_t type1;
	type_t type2;
	basestats_s bstats;
} pokemonspec_s;

typedef struct {
	const pokemonspec_s* species;
	const personalstats_s pstats;

	volitile_s v;
	nonvolitile_s nv;

	const move_s* moves[4];
	const int move_count;
} pokemon_s;

typedef struct {
	const char name[32];
	pokemon_s pokemon[6];
	const int pokemon_count;
} player_s;

#endif
