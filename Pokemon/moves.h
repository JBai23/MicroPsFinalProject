
#include "battle.h"

#ifndef MVS_H
#define MVS_H 1

//absorb
const move_s ABSORB = {
.name = "Absorb",
.damage = 20,
.accuracy = 1.0,
.type = GRASS_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 25,
.effect = RECOIL_E2,
.chance = 1.0,
.m_arg = -2
};

//acid
const move_s ACID = {
.name = "Acid",
.damage = 40,
.accuracy = 1.0,
.type = POISON_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = OTHR_SDEFENSE_E2,
.chance = 0.1,
.m_arg = -1
};

//acid armor
const move_s ACIDARMOR = {
.name = "Acid Armor",
.damage = 0,
.accuracy = 1.0,
.type = POISON_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = SELF_DEFENSE_E2,
.chance = 1.0,
.m_arg = 2
};

//agility
const move_s AGILITY = {
.name = "Agility",
.damage = 0,
.accuracy = 1.0,
.type = PSYCHIC_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = SELF_SPEED_E2,
.chance = 1.0,
.m_arg = 2
};

//amnesia
const move_s AMNESIA = {
.name = "Amnesia",
.damage = 0,
.accuracy = 1.0,
.type = PSYCHIC_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = SELF_SDEFENSE_E2,
.chance = 1.0,
.m_arg = 2
};

//aurora beam
const move_s AURORABEAM = {
.name = "Aurora Beam",
.damage = 65,
.accuracy = 1.0,
.type = ICE_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = OTHR_ATTACK_E2,
.chance = 0.1,
.m_arg = -1
};

//barrier
const move_s BARRIER = {
.name = "Barrier",
.damage = 0,
.accuracy = 1.0,
.type = PSYCHIC_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = SELF_DEFENSE_E2,
.chance = 1.0,
.m_arg = 2
};

//bite
const move_s BITE = {
.name = "Bite",
.damage = 60,
.accuracy = 1.0,
.type = DARK_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 25,
.effect = APPLY_FLINCH_E2,
.chance = 0.3,
.m_arg = 0
};

//blizzard
const move_s BLIZZARD = {
.name = "Blizzard",
.damage = 110,
.accuracy = 0.7,
.type = ICE_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 5,
.effect = APPLY_FRZ_E2,
.chance = 0.1,
.m_arg = 0
};

//body slam
const move_s BODYSLAM = {
.name = "Body Slam",
.damage = 85,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_PAR_E2,
.chance = 0.3,
.m_arg = 0
};

//bone club
const move_s BONECLUB = {
.name = "Bone Club",
.damage = 65,
.accuracy = 0.85,
.type = GROUND_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = APPLY_FLINCH_E2,
.chance = 0.1,
.m_arg = 0
};

//bubble
const move_s BUBBLE = {
.name = "Bubble",
.damage = 40,
.accuracy = 1.0,
.type = WATER_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = OTHR_SPEED_E2,
.chance = 0.1,
.m_arg = -1
};

//bubble beam
const move_s BUBBLEBEAM = {
.name = "Bubble Beam",
.damage = 65,
.accuracy = 1.0,
.type = WATER_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = OTHR_SPEED_E2,
.chance = 0.1,
.m_arg = -1
};

//confuse ray
const move_s CONFUSERAY = {
.name = "Confuse Ray",
.damage = 0,
.accuracy = 1.0,
.type = GHOST_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 10,
.effect = APPLY_CONFUSE_E2,
.chance = 1.0,
.m_arg = 0
};

//confusion
const move_s CONFUSION = {
.name = "Confusion",
.damage = 50,
.accuracy = 1.0,
.type = PSYCHIC_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 25,
.effect = APPLY_CONFUSE_E2,
.chance = 0.1,
.m_arg = 0
};

//constrict
const move_s CONSTRICT = {
.name = "Constrict",
.damage = 10,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 35,
.effect = OTHR_SPEED_E2,
.chance = 0.1,
.m_arg = -1
};

//crabhammer
const move_s CRABHAMMER = {
.name = "Crabhammer",
.damage = 100,
.accuracy = 0.9,
.type = WATER_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 10,
.effect = HIGH_CRIT_E2,
.chance = 1.0,
.m_arg = 0
};

//cut
const move_s CUT = {
.name = "Cut",
.damage = 50,
.accuracy = 0.95,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//defense curl
const move_s DEFENSECURL = {
.name = "Defense Curl",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 40,
.effect = SELF_DEFENSE_E2,
.chance = 1.0,
.m_arg = 1
};

//dizzy punch
const move_s DIZZYPUNCH = {
.name = "Dizzy Punch",
.damage = 70,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 10,
.effect = APPLY_CONFUSE_E2,
.chance = 0.2,
.m_arg = 0
};

//double team
const move_s DOUBLETEAM = {
.name = "Double Team",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = SELF_EVASION_E2,
.chance = 1.0,
.m_arg = 1
};

//double-edge
const move_s DOUBLEEDGE = {
.name = "Double-Edge",
.damage = 120,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = RECOIL_E2,
.chance = 1.0,
.m_arg = 3
};

//drill peck
const move_s DRILLPECK = {
.name = "Drill Peck",
.damage = 80,
.accuracy = 1.0,
.type = FLYING_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//earthquake
const move_s EARTHQUAKE = {
.name = "Earthquake",
.damage = 100,
.accuracy = 1.0,
.type = GROUND_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 10,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//egg bomb
const move_s EGGBOMB = {
.name = "Egg Bomb",
.damage = 100,
.accuracy = 0.75,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 10,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//ember
const move_s EMBER = {
.name = "Ember",
.damage = 40,
.accuracy = 1.0,
.type = FIRE_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 25,
.effect = APPLY_BRN_E2,
.chance = 0.1,
.m_arg = 0
};

//explosion
const move_s EXPLOSION = {
.name = "Explosion",
.damage = 250,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 5,
.effect = SELF_KILL_E2,
.chance = 1.0,
.m_arg = 0
};

//fire blast
const move_s FIREBLAST = {
.name = "Fire Blast",
.damage = 110,
.accuracy = 0.85,
.type = FIRE_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 5,
.effect = APPLY_BRN_E2,
.chance = 0.1,
.m_arg = 0
};

//fire punch
const move_s FIREPUNCH = {
.name = "Fire Punch",
.damage = 75,
.accuracy = 1.0,
.type = FIRE_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_BRN_E2,
.chance = 0.1,
.m_arg = 0
};

//fissure
const move_s FISSURE = {
.name = "Fissure",
.damage = 100000,
.accuracy = 1.0,
.type = GROUND_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 5,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//flamethrower
const move_s FLAMETHROWER = {
.name = "Flamethrower",
.damage = 90,
.accuracy = 1.0,
.type = FIRE_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_BRN_E2,
.chance = 0.1,
.m_arg = 0
};

//flash
const move_s FLASH = {
.name = "Flash",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = OTHR_ACCURACY_E2,
.chance = 1.0,
.m_arg = -1
};

//glare
const move_s GLARE = {
.name = "Glare",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = APPLY_PAR_E2,
.chance = 1.0,
.m_arg = 0
};

//growl
const move_s GROWL = {
.name = "Growl",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 40,
.effect = OTHR_ATTACK_E2,
.chance = 1.0,
.m_arg = -1
};

//growth
const move_s GROWTH = {
.name = "Growth",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 40,
.effect = SELF_ATTACK_SATTACK_E2,
.chance = 1.0,
.m_arg = 1
};

//guillotine
const move_s GUILLOTINE = {
.name = "Guillotine",
.damage = 10000,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 5,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//gust
const move_s GUST = {
.name = "Gust",
.damage = 40,
.accuracy = 1.0,
.type = FLYING_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 35,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//harden
const move_s HARDEN = {
.name = "Harden",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = SELF_DEFENSE_E2,
.chance = 1.0,
.m_arg = 1
};

//haze
const move_s HAZE = {
.name = "Haze",
.damage = 0,
.accuracy = 1.0,
.type = ICE_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = HAZE_E2,
.chance = 1.0,
.m_arg = 0
};

//headbutt
const move_s HEADBUTT = {
.name = "Headbutt",
.damage = 70,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_FLINCH_E2,
.chance = 0.3,
.m_arg = 0
};

//horn attack
const move_s HORNATTACK = {
.name = "Horn Attack",
.damage = 65,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 25,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//horn drill
const move_s HORNDRILL = {
.name = "Horn Drill",
.damage = 10000,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 5,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//hydro pump
const move_s HYDROPUMP = {
.name = "Hydro Pump",
.damage = 110,
.accuracy = 0.8,
.type = WATER_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 5,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//hyper beam
const move_s HYPERBEAM = {
.name = "Hyper Beam",
.damage = 150,
.accuracy = 0.9,
.type = NORMAL_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 5,
.effect = RECHARGE_E2,
.chance = 1.0,
.m_arg = 0
};

//hyper fang
const move_s HYPERFANG = {
.name = "Hyper Fang",
.damage = 80,
.accuracy = 0.9,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_FLINCH_E2,
.chance = 0.1,
.m_arg = 0
};

//hypnosis
const move_s HYPNOSIS = {
.name = "Hypnosis",
.damage = 0,
.accuracy = 0.6,
.type = PSYCHIC_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = APPLY_SLP_E2,
.chance = 1.0,
.m_arg = 0
};

//ice beam
const move_s ICEBEAM = {
.name = "Ice Beam",
.damage = 90,
.accuracy = 1.0,
.type = ICE_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 10,
.effect = APPLY_FRZ_E2,
.chance = 0.1,
.m_arg = 0
};

//ice punch
const move_s ICEPUNCH = {
.name = "Ice Punch",
.damage = 75,
.accuracy = 1.0,
.type = ICE_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_FRZ_E2,
.chance = 0.1,
.m_arg = 0
};

//karate chop
const move_s KARATECHOP = {
.name = "Karate Chop",
.damage = 50,
.accuracy = 1.0,
.type = FIGHTING_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 25,
.effect = HIGH_CRIT_E2,
.chance = 1.0,
.m_arg = 0
};

//kinesis
const move_s KINESIS = {
.name = "Kinesis",
.damage = 0,
.accuracy = 0.8,
.type = PSYCHIC_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = OTHR_ACCURACY_E2,
.chance = 1.0,
.m_arg = -1
};

//leech life
const move_s LEECHLIFE = {
.name = "Leech Life",
.damage = 20,
.accuracy = 1.0,
.type = BUG_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = RECOIL_E2,
.chance = 1.0,
.m_arg = -2
};

//leer
const move_s LEER = {
.name = "Leer",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = OTHR_DEFENSE_E2,
.chance = 1.0,
.m_arg = -1
};

//lick
const move_s LICK = {
.name = "Lick",
.damage = 30,
.accuracy = 1.0,
.type = GHOST_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = APPLY_PAR_E2,
.chance = 0.3,
.m_arg = 0
};

//lovely kiss
const move_s LOVELYKISS = {
.name = "Lovely Kiss",
.damage = 0,
.accuracy = 0.75,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 10,
.effect = APPLY_SLP_E2,
.chance = 1.0,
.m_arg = 0
};

//meditate
const move_s MEDITATE = {
.name = "Meditate",
.damage = 0,
.accuracy = 1.0,
.type = PSYCHIC_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 40,
.effect = SELF_ATTACK_E2,
.chance = 1.0,
.m_arg = 1
};

//mega drain
const move_s MEGADRAIN = {
.name = "Mega Drain",
.damage = 40,
.accuracy = 1.0,
.type = GRASS_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = RECOIL_E2,
.chance = 1.0,
.m_arg = -2
};

//mega kick
const move_s MEGAKICK = {
.name = "Mega Kick",
.damage = 120,
.accuracy = 0.75,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 5,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//mega punch
const move_s MEGAPUNCH = {
.name = "Mega Punch",
.damage = 80,
.accuracy = 0.85,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//minimize
const move_s MINIMIZE = {
.name = "Minimize",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 10,
.effect = SELF_EVASION_E2,
.chance = 1.0,
.m_arg = 2
};

//pay day
const move_s PAYDAY = {
.name = "Pay Day",
.damage = 40,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//peck
const move_s PECK = {
.name = "Peck",
.damage = 35,
.accuracy = 1.0,
.type = FLYING_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 35,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//pin missile
const move_s PINMISSILE = {
.name = "Pin Missile",
.damage = 25,
.accuracy = 0.85,
.type = BUG_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//poison gas
const move_s POISONGAS = {
.name = "Poison Gas",
.damage = 0,
.accuracy = 0.9,
.type = POISON_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 40,
.effect = APPLY_PSN_E2,
.chance = 1.0,
.m_arg = 0
};

//poison powder
const move_s POISONPOWDER = {
.name = "Poison Powder",
.damage = 0,
.accuracy = 0.75,
.type = POISON_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 35,
.effect = APPLY_PSN_E2,
.chance = 1.0,
.m_arg = 0
};

//poison sting
const move_s POISONSTING = {
.name = "Poison Sting",
.damage = 15,
.accuracy = 1.0,
.type = POISON_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 35,
.effect = APPLY_PSN_E2,
.chance = 0.3,
.m_arg = 0
};

//pound
const move_s POUND = {
.name = "Pound",
.damage = 40,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 35,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//psybeam
const move_s PSYBEAM = {
.name = "Psybeam",
.damage = 65,
.accuracy = 1.0,
.type = PSYCHIC_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = APPLY_CONFUSE_E2,
.chance = 0.1,
.m_arg = 0
};

//psychic
const move_s PSYCHIC = {
.name = "Psychic",
.damage = 90,
.accuracy = 1.0,
.type = PSYCHIC_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 10,
.effect = OTHR_SDEFENSE_E2,
.chance = 0.1,
.m_arg = -1
};

//quick attack
const move_s QUICKATTACK = {
.name = "Quick Attack",
.damage = 40,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 1,
.unique = 0,
.pp_max = 30,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//razor leaf
const move_s RAZORLEAF = {
.name = "Razor Leaf",
.damage = 55,
.accuracy = 0.95,
.type = GRASS_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 25,
.effect = HIGH_CRIT_E2,
.chance = 1.0,
.m_arg = 0
};

//rock slide
const move_s ROCKSLIDE = {
.name = "Rock Slide",
.damage = 75,
.accuracy = 0.9,
.type = ROCK_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 10,
.effect = APPLY_FLINCH_E2,
.chance = 0.3,
.m_arg = 0
};

//rock throw
const move_s ROCKTHROW = {
.name = "Rock Throw",
.damage = 50,
.accuracy = 0.9,
.type = ROCK_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//rolling kick
const move_s ROLLINGKICK = {
.name = "Rolling Kick",
.damage = 60,
.accuracy = 0.85,
.type = FIGHTING_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_FLINCH_E2,
.chance = 0.3,
.m_arg = 0
};

//sand attack
const move_s SANDATTACK = {
.name = "Sand Attack",
.damage = 0,
.accuracy = 1.0,
.type = GROUND_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = OTHR_ACCURACY_E2,
.chance = 1.0,
.m_arg = -1
};

//scratch
const move_s SCRATCH = {
.name = "Scratch",
.damage = 40,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 35,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//screech
const move_s SCREECH = {
.name = "Screech",
.damage = 0,
.accuracy = 0.85,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 40,
.effect = OTHR_DEFENSE_E2,
.chance = 1.0,
.m_arg = -2
};

//self-destruct
const move_s SELFDESTRUCT = {
.name = "Self-Destruct",
.damage = 200,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 5,
.effect = SELF_KILL_E2,
.chance = 1.0,
.m_arg = 0
};

//sharpen
const move_s SHARPEN = {
.name = "Sharpen",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = SELF_ATTACK_E2,
.chance = 1.0,
.m_arg = 1
};

//sing
const move_s SING = {
.name = "Sing",
.damage = 0,
.accuracy = 0.55,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_SLP_E2,
.chance = 1.0,
.m_arg = 0
};

//slam
const move_s SLAM = {
.name = "Slam",
.damage = 80,
.accuracy = 0.75,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//slash
const move_s SLASH = {
.name = "Slash",
.damage = 70,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = HIGH_CRIT_E2,
.chance = 1.0,
.m_arg = 0
};

//sleep powder
const move_s SLEEPPOWDER = {
.name = "Sleep Powder",
.damage = 0,
.accuracy = 0.75,
.type = GRASS_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_SLP_E2,
.chance = 1.0,
.m_arg = 0
};

//sludge
const move_s SLUDGE = {
.name = "Sludge",
.damage = 65,
.accuracy = 1.0,
.type = POISON_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = APPLY_PSN_E2,
.chance = 0.3,
.m_arg = 0
};

//smog
const move_s SMOG = {
.name = "Smog",
.damage = 30,
.accuracy = 0.7,
.type = POISON_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = APPLY_PSN_E2,
.chance = 0.4,
.m_arg = 0
};

//smokescreen
const move_s SMOKESCREEN = {
.name = "Smokescreen",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = OTHR_ACCURACY_E2,
.chance = 1.0,
.m_arg = -1
};

//splash
const move_s SPLASH = {
.name = "Splash",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 40,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//spore
const move_s SPORE = {
.name = "Spore",
.damage = 0,
.accuracy = 1.0,
.type = GRASS_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_SLP_E2,
.chance = 1.0,
.m_arg = 0
};

//stomp
const move_s STOMP = {
.name = "Stomp",
.damage = 65,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = APPLY_FLINCH_E2,
.chance = 0.3,
.m_arg = 0
};

//strength
const move_s STRENGTH = {
.name = "Strength",
.damage = 80,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//string shot
const move_s STRINGSHOT = {
.name = "String Shot",
.damage = 0,
.accuracy = 0.95,
.type = BUG_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 40,
.effect = OTHR_SPEED_E2,
.chance = 1.0,
.m_arg = -2
};

//struggle
const move_s STRUGGLE = {
.name = "Struggle",
.damage = 50,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 0,
.effect = RECOIL_E2,
.chance = 1.0,
.m_arg = 2
};

//stun spore
const move_s STUNSPORE = {
.name = "Stun Spore",
.damage = 0,
.accuracy = 0.75,
.type = GRASS_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = APPLY_PAR_E2,
.chance = 1.0,
.m_arg = 0
};

//submission
const move_s SUBMISSION = {
.name = "Submission",
.damage = 80,
.accuracy = 0.8,
.type = FIGHTING_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 25,
.effect = RECOIL_E2,
.chance = 1.0,
.m_arg = 4
};

//supersonic
const move_s SUPERSONIC = {
.name = "Supersonic",
.damage = 0,
.accuracy = 0.55,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = APPLY_CONFUSE_E2,
.chance = 1.0,
.m_arg = 0
};

//surf
const move_s SURF = {
.name = "Surf",
.damage = 90,
.accuracy = 1.0,
.type = WATER_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//swords dance
const move_s SWORDSDANCE = {
.name = "Swords Dance",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = SELF_ATTACK_E2,
.chance = 1.0,
.m_arg = 2
};

//tackle
const move_s TACKLE = {
.name = "Tackle",
.damage = 50,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 35,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//tail whip
const move_s TAILWHIP = {
.name = "Tail Whip",
.damage = 0,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = OTHR_DEFENSE_E2,
.chance = 1.0,
.m_arg = -1
};

//take down
const move_s TAKEDOWN = {
.name = "Take Down",
.damage = 90,
.accuracy = 0.85,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = RECOIL_E2,
.chance = 1.0,
.m_arg = 4
};

//thunder
const move_s THUNDER = {
.name = "Thunder",
.damage = 110,
.accuracy = 0.7,
.type = ELECTRIC_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 10,
.effect = APPLY_PAR_E2,
.chance = 0.3,
.m_arg = 0
};

//thunder punch
const move_s THUNDERPUNCH = {
.name = "Thunder Punch",
.damage = 75,
.accuracy = 1.0,
.type = ELECTRIC_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_PAR_E2,
.chance = 0.1,
.m_arg = 0
};

//thunder shock
const move_s THUNDERSHOCK = {
.name = "Thunder Shock",
.damage = 40,
.accuracy = 1.0,
.type = ELECTRIC_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = APPLY_PAR_E2,
.chance = 0.1,
.m_arg = 0
};

//thunder wave
const move_s THUNDERWAVE = {
.name = "Thunder Wave",
.damage = 0,
.accuracy = 1.0,
.type = ELECTRIC_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 20,
.effect = APPLY_PAR_E2,
.chance = 1.0,
.m_arg = 0
};

//thunderbolt
const move_s THUNDERBOLT = {
.name = "Thunderbolt",
.damage = 90,
.accuracy = 1.0,
.type = ELECTRIC_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_PAR_E2,
.chance = 0.1,
.m_arg = 0
};

//toxic
const move_s TOXIC = {
.name = "Toxic",
.damage = 0,
.accuracy = 0.9,
.type = POISON_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 10,
.effect = APPLY_TXC_E2,
.chance = 1.0,
.m_arg = 0
};

//vice grip
const move_s VICEGRIP = {
.name = "Vice Grip",
.damage = 55,
.accuracy = 1.0,
.type = NORMAL_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 30,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//vine whip
const move_s VINEWHIP = {
.name = "Vine Whip",
.damage = 45,
.accuracy = 1.0,
.type = GRASS_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 25,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//water gun
const move_s WATERGUN = {
.name = "Water Gun",
.damage = 40,
.accuracy = 1.0,
.type = WATER_T,
.movetype = SPECIAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 25,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//waterfall
const move_s WATERFALL = {
.name = "Waterfall",
.damage = 80,
.accuracy = 1.0,
.type = WATER_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 15,
.effect = APPLY_FLINCH_E2,
.chance = 0.2,
.m_arg = 0
};

//wing attack
const move_s WINGATTACK = {
.name = "Wing Attack",
.damage = 60,
.accuracy = 1.0,
.type = FLYING_T,
.movetype = PHYSICAL_MT,
.priority = 0,
.unique = 0,
.pp_max = 35,
.effect = NON_E2,
.chance = 1.0,
.m_arg = 0
};

//withdraw
const move_s WITHDRAW = {
.name = "Withdraw",
.damage = 0,
.accuracy = 1.0,
.type = WATER_T,
.movetype = STATUS_MT,
.priority = 0,
.unique = 0,
.pp_max = 40,
.effect = SELF_DEFENSE_E2,
.chance = 1.0,
.m_arg = 1
};

#endif
