
#include "battle-p.h"
#include "global.h"
#include <stdio.h>

void set_curr(trainer_s *trainer) {
	CURR_PLAYER = trainer;
	OTHR_PLAYER = (trainer == PLAYER1 ? PLAYER2 : PLAYER1);
}

void swap_curr() {
	set_curr(OTHR_PLAYER);
}



bool check_priority() { // true if battle, false if surrender
	if (PLAYER1_ACTION == SURRENDER_A || PLAYER2_ACTION == SURRENDER_A) {
		return false;
	}

	int player1_priority = get_priority(PLAYER1);
	int player2_priority = get_priority(PLAYER2);

	if (player1_priority == player2_priority) {
		int player1_speed = calc_speed(PLAYER1_POKEMON);
		int player2_speed = calc_speed(PLAYER2_POKEMON);

		if (player1_speed == player2_speed) {
			set_curr((roll(.5) ? PLAYER1 : PLAYER2));
			return true;
		} else {
			set_curr((player1_speed > player2_speed ? PLAYER1 : PLAYER2));
			return true;
		}
	} else {
		set_curr((player1_priority > player2_priority ? PLAYER1 : PLAYER2));
		return true;
	}

	return true;
}

int get_priority(trainer_s *trainer) {
	action_t action = trainer->action;
	return (is_move(action) ? get_move(trainer, action)->priority : 6); // if isn't move it is switch
}

int calc_hpmax(pokemon_s *pokemon) {
	int ev = pokemon->pstats.hp_ev;
	int iv = pokemon->pstats.hp_iv;
	int level = pokemon->pstats.level;
	int base = pokemon->species->bstats.hp_base;
	return (iv + (2 * base) + ev / 4 + 100) * level / 100 + 10;
}

int calc_attack(pokemon_s *pokemon) {
	int ev = pokemon->pstats.attack_ev;
	int iv = pokemon->pstats.attack_iv;
	int level = pokemon->pstats.level;
	int base = pokemon->species->bstats.attack_base;
	int nature;
	switch (pokemon->pstats.nature) {
		case LONELY_N:
		case ADAMANT_N:
		case NAUGHTY_N:
		case BRAVE_N:
			nature = 11;
			break;
		case BOLD_N:
		case MODEST_N:
		case CALM_N:
		case TIMID_N:
			nature = 9;
			break;
		default:
			nature = 10;
			break;
	}
	int stage = pokemon->v.attack_stage;
	int stage_n = (stage > 0 ? 2 + stage : 2);
	int stage_d = (stage < 0 ? 2 - stage : 2);
	return ((iv + (2 * base) + ev / 4) * level / 100 + 5) * nature / 10 * stage_n / stage_d;
}

int calc_defense(pokemon_s *pokemon) {
	int ev = pokemon->pstats.defense_ev;
	int iv = pokemon->pstats.defense_iv;
	int level = pokemon->pstats.level;
	int base = pokemon->species->bstats.defense_base;
	int nature;
	switch (pokemon->pstats.nature) {
		case BOLD_N:
		case IMPISH_N:
		case LAX_N:
		case RELAXED_N:
			nature = 11;
			break;
		case LONELY_N:
		case MILD_N:
		case GENTLE_N:
		case HASTY_N:
			nature = 9;
			break;
		default:
			nature = 10;
			break;
	}
	int stage = pokemon->v.defense_stage;
	int stage_n = (stage > 0 ? 2 + stage : 2);
	int stage_d = (stage < 0 ? 2 - stage : 2);
	return ((iv + (2 * base) + ev / 4) * level / 100 + 5) * nature / 10 * stage_n / stage_d;
}

int calc_sattack(pokemon_s *pokemon) {
	int ev = pokemon->pstats.sattack_ev;
	int iv = pokemon->pstats.sattack_iv;
	int level = pokemon->pstats.level;
	int base = pokemon->species->bstats.sattack_base;
	int nature;
	switch (pokemon->pstats.nature) {
		case MODEST_N:
		case MILD_N:
		case RASH_N:
		case QUIET_N:
			nature = 11;
			break;
		case ADAMANT_N:
		case IMPISH_N:
		case CAREFUL_N:
		case JOLLY_N:
			nature = 9;
			break;
		default:
			nature = 10;
			break;
	}
	int stage = pokemon->v.sattack_stage;
	int stage_n = (stage > 0 ? 2 + stage : 2);
	int stage_d = (stage < 0 ? 2 - stage : 2);
	return ((iv + (2 * base) + ev / 4) * level / 100 + 5) * nature / 10 * stage_n / stage_d;
}

int calc_sdefense(pokemon_s *pokemon) {
	int ev = pokemon->pstats.sdefense_ev;
	int iv = pokemon->pstats.sdefense_iv;
	int level = pokemon->pstats.level;
	int base = pokemon->species->bstats.sdefense_base;
	int nature;
	switch (pokemon->pstats.nature) {
		case CALM_N:
		case GENTLE_N:
		case CAREFUL_N:
		case SASSY_N:
			nature = 11;
			break;
		case NAUGHTY_N:
		case LAX_N:
		case RASH_N:
		case NAIVE_N:
			nature = 9;
			break;
		default:
			nature = 10;
			break;
	}
	int stage = pokemon->v.sdefense_stage;
	int stage_n = (stage > 0 ? 2 + stage : 2);
	int stage_d = (stage < 0 ? 2 - stage : 2);
	return ((iv + (2 * base) + ev / 4) * level / 100 + 5) * nature / 10 * stage_n / stage_d;
}

int calc_speed(pokemon_s *pokemon) {
	int ev = pokemon->pstats.speed_ev;
	int iv = pokemon->pstats.speed_iv;
	int level = pokemon->pstats.level;
	int base = pokemon->species->bstats.speed_base;
	int nature;
	switch (pokemon->pstats.nature) {
		case TIMID_N:
		case HASTY_N:
		case JOLLY_N:
		case NAIVE_N:
			nature = 11;
			break;
		case BRAVE_N:
		case RELAXED_N:
		case QUIET_N:
		case SASSY_N:
			nature = 9;
			break;
		default:
			nature = 10;
			break;
	}
	int stage = pokemon->v.speed_stage;
	int stage_n = (stage > 0 ? 2 + stage : 2);
	int stage_d = (stage < 0 ? 2 - stage : 2);
	int status = (pokemon->nv.nvstatus == PAR_S ? 3 : 4);
	return ((iv + (2 * base) + ev / 4) * level / 100 + 5) * nature / 10 * stage_n / stage_d * status / 4;
}

double calc_accuracy(pokemon_s *attacker, pokemon_s *defender) {
	double c = (double) calc_accuracy_n(attacker, defender) / (double) calc_accuracy_d(attacker, defender);
	return c;
}

int calc_accuracy_n(pokemon_s *attacker, pokemon_s *defender) {
	int acc = attacker->v.accuracy_stage;
	int eva = defender->v.evasion_stage;

	int sum = acc + eva;
	if (sum > 6) {
		sum = 6;
	} else if (sum < -6) {
		sum = -6;
	}

	return (sum > 0 ? 3 + sum : 3);
}

int calc_accuracy_d(pokemon_s *attacker, pokemon_s *defender) {
	int acc = attacker->v.accuracy_stage;
	int eva = defender->v.evasion_stage;

	int sum = acc + eva;
	if (sum > 6) {
		sum = 6;
	} else if (sum < -6) {
		sum = -6;
	}

	return (sum < 0 ? 3 + sum : 3);
}

void curr_exe() {
	if (is_alive(CURR_POKEMON) && is_alive(OTHR_POKEMON)) {
		if (is_move(CURR_ACTION)) {
			curr_attack();
		} else {
			curr_switchto();
		}
	}
}

move_s* curr_move() {
	return get_move(CURR_PLAYER, CURR_ACTION);
}

void curr_switchto() {
	printf("%s: %s, that's enough!\n", CURR_NAME, CURR_PNAME);
	switchto(CURR_PLAYER, get_index(CURR_ACTION));
	printf("%s: Go, %s!\n", CURR_NAME, CURR_PNAME);
}

void curr_attack() {
	// see if nv status allow for attack
	switch (CURR_POKEMON->nv.nvstatus) {
		case NON_S:
		case BRN_S:
		case PSN_S:
		case TXC_S:
			break;
		
		case FRZ_S:
			if (roll(.2)) {
				printf("%s thawed out!\n", CURR_PNAME);
				CURR_POKEMON->nv.nvstatus = NON_S;
				break;
			} else {
				printf("%s is frozen solid!\n", CURR_PNAME);
				return;
			}
		case PAR_S:
			if (roll(.25)) {
				printf("%s is fully paralyzed!\n", CURR_PNAME);
				return;
			} else {
				break;
			}
		case SLP_S:
			if (CURR_POKEMON->nv.nv_arg > 0) {
				printf("%s is fast asleep!\n", CURR_PNAME);
				CURR_POKEMON->nv.nv_arg--;
				return;
			} else {
				printf("%s woke up!\n", CURR_PNAME);
				CURR_POKEMON->nv.nvstatus = NON_S;
				break;
			}
		case FNT_S: // should never happen
		default:
			return;
	}

	// see if v status allows for attack
	if (CURR_POKEMON->v.is_flinch) {
		printf("%s flinched!\n", CURR_PNAME);
		CURR_POKEMON->v.is_flinch = false;
		return;
	}
	if (CURR_POKEMON->v.is_recharge) {
		printf("%s is recharging!\n", CURR_PNAME);
		CURR_POKEMON->v.is_recharge = false;
		return;
	}
	if (CURR_POKEMON->v.is_confuse) {
		printf("%s is confused!\n", CURR_PNAME);
		if (roll(.25)) { // this is not quite how it works in Pokemon
			printf("%s snapped out of confusion!\n", CURR_PNAME);
			CURR_POKEMON->v.is_confuse = false;
		} else {
			if (roll(.5)) {
				printf("%s hurt itself in confusion!\n", CURR_PNAME);
				int damage = calc_damage(CURR_POKEMON, CURR_POKEMON, 40, PHYSICAL_MT);
				printf("[%s applied %i damage to himself]\n", CURR_PNAME, damage);
				apply_damage(CURR_POKEMON, damage);
				return;
			}
		}
	}

	move_s *move = curr_move();
	printf("%s used %s!\n", CURR_PNAME, move->name);

	// check if unique
	if (move->unique) {
		switch (move->unique) {
			default: // no unique moves at the moment
				return;
		}
	}

	// check accuracy
	if (is_aggressive(move)) {
		if (!roll(move->accuracy * calc_accuracy(CURR_POKEMON, OTHR_POKEMON))) { // swift support?
			printf("It missed!\n");
			return;
		}

		if (move->movetype != STATUS_MT) {
			int damage = calc_damage(CURR_POKEMON, OTHR_POKEMON, move->damage, move->movetype);

			double stab_bonus = (has_type(CURR_POKEMON, move->type) ? 1.5 : 1); // STAB bonus
			double effective_bonus = calc_effective(move->type, OTHR_POKEMON); // type bonus

			double crit_chance = (move->effect == HIGH_CRIT_E2 ? .125 : .0625);
			double crit_bonus = (roll(crit_chance) ? 1.5 : 1.0); // this is not quite how it works in Pokemon

			double rndm = (rand() % 16 + 85) / 100.0;

			// printf("%i, %lf, %lf, %lf, %lf\n", damage, stab_bonus, effective_bonus, crit_bonus, rndm);
			int total_damage = (int)(damage * stab_bonus * effective_bonus * crit_bonus * rndm);

			// if burnt, physical damage output is halfed
			if (CURR_POKEMON->nv.nvstatus == BRN_S && move->movetype == PHYSICAL_MT) {
				total_damage /= 2;
			}

			if (effective_bonus > 1) {
				printf("It's super effective!\n");
			} else if (effective_bonus == 0) {
				printf("It has no effect!\n");
			} else if (effective_bonus < 1) {
				printf("It's not very effective!\n");
			}

			if (crit_bonus > 1) {
				printf("Critical hit!\n");
			}

			printf("[%s applies %i damage to %s]\n", CURR_PNAME, total_damage, OTHR_PNAME);
			apply_damage(OTHR_POKEMON, total_damage);
		} else {
			if (calc_effective(move->type, OTHR_POKEMON) == 0) { // thunder wave can't work on ground
				printf("It has no effect!\n");
				return;
			}
		}
	}

	int calculation; // can be used for some of the switch cases

	// check secondary effect
	if (move->effect != NON_E2) {
		if (roll(move->chance)) {
			switch (move->effect) {
				case APPLY_BRN_E2:
					apply_nvstatus(OTHR_POKEMON, BRN_S);
					break;
				case APPLY_FRZ_E2:
					apply_nvstatus(OTHR_POKEMON, FRZ_S);
					break;
				case APPLY_PAR_E2:
					apply_nvstatus(OTHR_POKEMON, PAR_S);
					break;
				case APPLY_PSN_E2:
					apply_nvstatus(OTHR_POKEMON, PSN_S);
					break;
				case APPLY_TXC_E2:
					apply_nvstatus(OTHR_POKEMON, TXC_S);
					break;
				case APPLY_SLP_E2:
					apply_nvstatus(OTHR_POKEMON, SLP_S);
					break;
				case APPLY_FLINCH_E2:
					OTHR_POKEMON->v.is_flinch = true;
					break;
				case APPLY_CONFUSE_E2:
					printf("%s became confused!\n", OTHR_PNAME);
					OTHR_POKEMON->v.is_confuse = true;
					break;
				case HIGH_CRIT_E2:
					break; // this doesn't happen here
				case SELF_KILL_E2:
					apply_nvstatus(CURR_POKEMON, FNT_S);
					break;
				case SELF_ATTACK_E2:
					apply_attackstage(CURR_POKEMON, move->m_arg);
					break;
				case SELF_DEFENSE_E2:
					apply_defensestage(CURR_POKEMON, move->m_arg);
					break;
				case SELF_SATTACK_E2:
					apply_sattackstage(CURR_POKEMON, move->m_arg);
					break;
				case SELF_SDEFENSE_E2:
					apply_sdefensestage(CURR_POKEMON, move->m_arg);
					break;
				case SELF_SPEED_E2:
					apply_speedstage(CURR_POKEMON, move->m_arg);
					break;
				case SELF_ACCURACY_E2:
					apply_accuracystage(CURR_POKEMON, move->m_arg);
					break;
				case SELF_EVASION_E2:
					apply_evasionstage(CURR_POKEMON, move->m_arg);
					break;
				case OTHR_ATTACK_E2:
					apply_attackstage(OTHR_POKEMON, move->m_arg);
					break;
				case OTHR_DEFENSE_E2:
					apply_defensestage(OTHR_POKEMON, move->m_arg);
					break;
				case OTHR_SATTACK_E2:
					apply_sattackstage(OTHR_POKEMON, move->m_arg);
					break;
				case OTHR_SDEFENSE_E2:
					apply_sdefensestage(OTHR_POKEMON, move->m_arg);
					break;
				case OTHR_SPEED_E2:
					apply_speedstage(OTHR_POKEMON, move->m_arg);
					break;
				case OTHR_ACCURACY_E2:
					apply_accuracystage(OTHR_POKEMON, move->m_arg);
					break;
				case OTHR_EVASION_E2:
					apply_evasionstage(OTHR_POKEMON, move->m_arg);
					break;
				case SELF_ATTACK_SATTACK_E2:
					apply_attackstage(CURR_POKEMON, move->m_arg);
					apply_sattackstage(CURR_POKEMON, move->m_arg);
					break;
				case HAZE_E2:
					reset_stages(CURR_POKEMON);
					reset_stages(OTHR_POKEMON);
					break;
				case RECOIL_E2:
					calculation = battle.last_dmg / move->m_arg; // pos is recoil, neg is heal
					if (calculation > 0) {
						printf("%s was hit with recoil!\n", CURR_PNAME);
						printf("[%s took %i damage in recoil]\n", CURR_PNAME, calculation);
					} else if (calculation < 0) {
						printf("%s regained health!", CURR_PNAME);
						printf("[%s restored %i damage]\n", CURR_PNAME, calculation);
					}
					apply_damage(CURR_POKEMON, calculation);
					break; // this doesn't happen here
				case RECHARGE_E2:
					CURR_POKEMON->v.is_recharge = true;
					break;
				case NON_E2: // shouldn't happen
					break;
			}
		}
	}
}

int calc_damage(pokemon_s *attacker, pokemon_s *defender, int base, move_t type) {
	int level = attacker->pstats.level;
	int attack = (type == PHYSICAL_MT ? calc_attack(attacker) : calc_sattack(attacker));
	int defense = (type == PHYSICAL_MT ? calc_defense(defender) : calc_sdefense(defender));
	return (2 * level + 10) / 250.0 * attack / defense * base + 2;
}

double calc_effective(type_t type, pokemon_s *defender) {
	double multiplier = 1;
	type_t type1 = defender->species->type1;
	type_t type2 = defender->species->type2;
	if (type1 != NON_T) {
		multiplier *= get_effective(type, type1);
	}
	if (type2 != NON_T) {
		multiplier *= get_effective(type, type2);
	}
	return multiplier;
}

double get_effective(type_t atype, type_t dtype) {
	switch (echart[atype][dtype]) {
		case SUPER_TE:
			return 2;
		case NORMAL_TE:
			return 1;
		case NOTVERY_TE:
			return 0.5;
		case NOEFFECT_TE: 
			return 0;
	}
}

void apply_damage(pokemon_s *pokemon, int damage) {
	if (damage == 0) {
		damage = 1; // must always deal some damage
	}

	if (damage > 0) { // inflict damage
		if (damage < pokemon->nv.hp) {
			pokemon->nv.hp -= damage;
			battle.last_dmg = damage;
		} else {
			battle.last_dmg = pokemon->nv.hp;
			apply_nvstatus(pokemon, FNT_S);
		}
	} else { // heal
		pokemon->nv.hp -= damage;
		int hpmax = calc_hpmax(pokemon);
		if (pokemon->nv.hp > hpmax) {
			pokemon->nv.hp = hpmax;
		}
	}
}

// todo: change stats to array so I can combine these to an enum called func
void apply_attackstage(pokemon_s *pokemon, int stages) {
	if (stages > 0 && pokemon->v.attack_stage == 6) {
		printf("%s's attack cannot go any higher!\n", pokemon->species->name);
		return;
	}
	if (stages < 0 && pokemon->v.attack_stage == -6) {
		printf("%s's attack cannot go any lower!\n", pokemon->species->name);
		return;
	}

	pokemon->v.attack_stage += stages;
	if (pokemon->v.attack_stage > 6) {
		pokemon->v.attack_stage = 6;
	} else if (pokemon->v.attack_stage < -6) {
		pokemon->v.attack_stage = -6;
	}

	if (stages == 1) {
		printf("%s's attack rose!\n", pokemon->species->name);
	} else if (stages == 2) {
		printf("%s's attack rose sharply!\n", pokemon->species->name);
	} else if (stages >= 3) {
		printf("%s's attack rose drastically!\n", pokemon->species->name);
	} else if (stages == -1) {
		printf("%s's attack fell!\n", pokemon->species->name);
	} else if (stages == -2) {
		printf("%s's attack fell sharply!\n", pokemon->species->name);
	} else if (stages <= -3) {
		printf("%s's attack fell drastically!\n", pokemon->species->name);
	} 
}

void apply_defensestage(pokemon_s *pokemon, int stages) {
	if (stages > 0 && pokemon->v.defense_stage == 6) {
		printf("%s's defense cannot go any higher!\n", pokemon->species->name);
		return;
	}
	if (stages < 0 && pokemon->v.defense_stage == -6) {
		printf("%s's defense cannot go any lower!\n", pokemon->species->name);
		return;
	}

	pokemon->v.defense_stage += stages;
	if (pokemon->v.defense_stage > 6) {
		pokemon->v.defense_stage = 6;
	} else if (pokemon->v.defense_stage < -6) {
		pokemon->v.defense_stage = -6;
	}

	if (stages == 1) {
		printf("%s's defense rose!\n", pokemon->species->name);
	} else if (stages == 2) {
		printf("%s's defense rose sharply!\n", pokemon->species->name);
	} else if (stages >= 3) {
		printf("%s's defense rose drastically!\n", pokemon->species->name);
	} else if (stages == -1) {
		printf("%s's defense fell!\n", pokemon->species->name);
	} else if (stages == -2) {
		printf("%s's defense fell sharply!\n", pokemon->species->name);
	} else if (stages <= -3) {
		printf("%s's defense fell drastically!\n", pokemon->species->name);
	} 
}

void apply_sattackstage(pokemon_s *pokemon, int stages) {
	if (stages > 0 && pokemon->v.sattack_stage == 6) {
		printf("%s's special attack cannot go any higher!\n", pokemon->species->name);
		return;
	}
	if (stages < 0 && pokemon->v.sattack_stage == -6) {
		printf("%s's special attack cannot go any lower!\n", pokemon->species->name);
		return;
	}

	pokemon->v.sattack_stage += stages;
	if (pokemon->v.sattack_stage > 6) {
		pokemon->v.sattack_stage = 6;
	} else if (pokemon->v.sattack_stage < -6) {
		pokemon->v.sattack_stage = -6;
	}

	if (stages == 1) {
		printf("%s's special attack rose!\n", pokemon->species->name);
	} else if (stages == 2) {
		printf("%s's special attack rose sharply!\n", pokemon->species->name);
	} else if (stages >= 3) {
		printf("%s's special attack rose drastically!\n", pokemon->species->name);
	} else if (stages == -1) {
		printf("%s's special attack fell!\n", pokemon->species->name);
	} else if (stages == -2) {
		printf("%s's special attack fell sharply!\n", pokemon->species->name);
	} else if (stages <= -3) {
		printf("%s's special attack fell drastically!\n", pokemon->species->name);
	} 
}

void apply_sdefensestage(pokemon_s *pokemon, int stages) {
	if (stages > 0 && pokemon->v.sdefense_stage == 6) {
		printf("%s's special defense cannot go any higher!\n", pokemon->species->name);
		return;
	}
	if (stages < 0 && pokemon->v.sdefense_stage == -6) {
		printf("%s's special defense cannot go any lower!\n", pokemon->species->name);
		return;
	}

	pokemon->v.sdefense_stage += stages;
	if (pokemon->v.sdefense_stage > 6) {
		pokemon->v.sdefense_stage = 6;
	} else if (pokemon->v.sdefense_stage < -6) {
		pokemon->v.sdefense_stage = -6;
	}

	if (stages == 1) {
		printf("%s's special defense rose!\n", pokemon->species->name);
	} else if (stages == 2) {
		printf("%s's special defense rose sharply!\n", pokemon->species->name);
	} else if (stages >= 3) {
		printf("%s's special defense rose drastically!\n", pokemon->species->name);
	} else if (stages == -1) {
		printf("%s's special defense fell!\n", pokemon->species->name);
	} else if (stages == -2) {
		printf("%s's special defense fell sharply!\n", pokemon->species->name);
	} else if (stages <= -3) {
		printf("%s's special defense fell drastically!\n", pokemon->species->name);
	} 
}

void apply_speedstage(pokemon_s *pokemon, int stages) {
	if (stages > 0 && pokemon->v.speed_stage == 6) {
		printf("%s's speed cannot go any higher!\n", pokemon->species->name);
		return;
	}
	if (stages < 0 && pokemon->v.speed_stage == -6) {
		printf("%s's speed cannot go any lower!\n", pokemon->species->name);
		return;
	}

	pokemon->v.speed_stage += stages;
	if (pokemon->v.speed_stage > 6) {
		pokemon->v.speed_stage = 6;
	} else if (pokemon->v.speed_stage < -6) {
		pokemon->v.speed_stage = -6;
	}

	if (stages == 1) {
		printf("%s's speed rose!\n", pokemon->species->name);
	} else if (stages == 2) {
		printf("%s's speed rose sharply!\n", pokemon->species->name);
	} else if (stages >= 3) {
		printf("%s's speed rose drastically!\n", pokemon->species->name);
	} else if (stages == -1) {
		printf("%s's speed fell!\n", pokemon->species->name);
	} else if (stages == -2) {
		printf("%s's speed fell sharply!\n", pokemon->species->name);
	} else if (stages <= -3) {
		printf("%s's speed fell drastically!\n", pokemon->species->name);
	} 
}

void apply_accuracystage(pokemon_s *pokemon, int stages) {
	if (stages > 0 && pokemon->v.accuracy_stage == 6) {
		printf("%s's accuracy cannot go any higher!\n", pokemon->species->name);
		return;
	}
	if (stages < 0 && pokemon->v.accuracy_stage == -6) {
		printf("%s's accuracy cannot go any lower!\n", pokemon->species->name);
		return;
	}

	pokemon->v.accuracy_stage += stages;
	if (pokemon->v.accuracy_stage > 6) {
		pokemon->v.accuracy_stage = 6;
	} else if (pokemon->v.accuracy_stage < -6) {
		pokemon->v.accuracy_stage = -6;
	}

	if (stages == 1) {
		printf("%s's accuracy rose!\n", pokemon->species->name);
	} else if (stages == 2) {
		printf("%s's accuracy rose sharply!\n", pokemon->species->name);
	} else if (stages >= 3) {
		printf("%s's accuracy rose drastically!\n", pokemon->species->name);
	} else if (stages == -1) {
		printf("%s's accuracy fell!\n", pokemon->species->name);
	} else if (stages == -2) {
		printf("%s's accuracy fell sharply!\n", pokemon->species->name);
	} else if (stages <= -3) {
		printf("%s's accuracy fell drastically!\n", pokemon->species->name);
	} 
}

void apply_evasionstage(pokemon_s *pokemon, int stages) {
	if (stages > 0 && pokemon->v.evasion_stage == 6) {
		printf("%s's evasion cannot go any higher!\n", pokemon->species->name);
		return;
	}
	if (stages < 0 && pokemon->v.evasion_stage == -6) {
		printf("%s's evasion cannot go any lower!\n", pokemon->species->name);
		return;
	}

	pokemon->v.evasion_stage += stages;
	if (pokemon->v.evasion_stage > 6) {
		pokemon->v.evasion_stage = 6;
	} else if (pokemon->v.evasion_stage < -6) {
		pokemon->v.evasion_stage = -6;
	}

	if (stages == 1) {
		printf("%s's evasion rose!\n", pokemon->species->name);
	} else if (stages == 2) {
		printf("%s's evasion rose sharply!\n", pokemon->species->name);
	} else if (stages >= 3) {
		printf("%s's evasion rose drastically!\n", pokemon->species->name);
	} else if (stages == -1) {
		printf("%s's evasion fell!\n", pokemon->species->name);
	} else if (stages == -2) {
		printf("%s's evasion fell sharply!\n", pokemon->species->name);
	} else if (stages <= -3) {
		printf("%s's evasion fell drastically!\n", pokemon->species->name);
	} 
}

void reset_stages(pokemon_s *pokemon) {
	printf("%s's stat modifiers reset!\n", pokemon->species->name);
	pokemon->v.attack_stage = 0;
	pokemon->v.defense_stage = 0;
	pokemon->v.sattack_stage = 0;
	pokemon->v.sdefense_stage = 0;
	pokemon->v.speed_stage = 0;
	pokemon->v.accuracy_stage = 0;
	pokemon->v.evasion_stage = 0;
}

void apply_nvstatus(pokemon_s *pokemon, nvstatus_t status) {
	if (status == FNT_S) {
		printf("%s fainted!\n", pokemon->species->name);
		pokemon->nv.nvstatus = FNT_S;
		pokemon->nv.hp = 0;
		return;
	}
	if (pokemon->nv.nvstatus == NON_S) {
		switch (status) {
			case BRN_S: // cant burn fire
				if (!has_type(pokemon, FIRE_T)) {
					printf("%s was burnt!\n", pokemon->species->name);	
					pokemon->nv.nvstatus = BRN_S;
				} else {
					printf("%s is immune to burns!\n", pokemon->species->name);	
				}
				break;
			case PSN_S: // cant poison poison
				if (!has_type(pokemon, POISON_T)) {
					printf("%s was poisoned!\n", pokemon->species->name);	
					pokemon->nv.nvstatus = PSN_S;
				} else {
					printf("%s is immune to poison!\n", pokemon->species->name);	
				}
				break;
			case TXC_S: // cant toxic poison
				if (!has_type(pokemon, POISON_T)) {
					printf("%s was badly poisoned!\n", pokemon->species->name);	
					pokemon->nv.nvstatus = TXC_S;
					pokemon->nv.nv_arg = 1;
				} else {
					printf("%s is immune to toxic!\n", pokemon->species->name);	
				}
				break;
			case FRZ_S: // cant freeze ice
				if (!has_type(pokemon, ICE_T)) {
					printf("%s was frozen solid!\n", pokemon->species->name);	
					pokemon->nv.nvstatus = FRZ_S;
				} else {
					printf("%s is immune to freezing!\n", pokemon->species->name);	
				}
				break;
			case PAR_S: // cant paralyze electric
				if (!has_type(pokemon, ELECTRIC_T)) {
					printf("%s was paralyzed!\n", pokemon->species->name);	
					pokemon->nv.nvstatus = PAR_S;
				} else {
					printf("%s is immune to paralysis!\n", pokemon->species->name);	
				}
				break;
			case SLP_S:
				printf("%s fell asleep!\n", pokemon->species->name);	
				pokemon->nv.nvstatus = SLP_S;
				pokemon->nv.nv_arg = rand() % 3 + 1;
			case FNT_S: // shouldn't happen
			case NON_S:
			default:
				return;
		}
	} else {
		printf("%s is already %s!\n", pokemon->species->name, get_statusname(pokemon->nv.nvstatus));
	}
}

void battle_phase() {
	if (check_priority()) {
		curr_exe();
		printf("\n");
		swap_curr();
		curr_exe();
		printf("\n");
	}
}