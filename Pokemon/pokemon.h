
#include "battle.h"

#ifndef PKM_H
#define PKM_H 1

//bulbasaur
const pokemonspec_s BULBASAUR = {
.name = "Bulbasaur",
.id = 1,
.type1 = GRASS_T,
.type2 = POISON_T,
.bstats = {45, 49, 49, 65, 65, 45}
};

//ivysaur
const pokemonspec_s IVYSAUR = {
.name = "Ivysaur",
.id = 2,
.type1 = GRASS_T,
.type2 = POISON_T,
.bstats = {60, 62, 63, 80, 80, 60}
};

//venusaur
const pokemonspec_s VENUSAUR = {
.name = "Venusaur",
.id = 3,
.type1 = GRASS_T,
.type2 = POISON_T,
.bstats = {80, 82, 83, 100, 100, 80}
};

//charmander
const pokemonspec_s CHARMANDER = {
.name = "Charmander",
.id = 4,
.type1 = FIRE_T,
.type2 = NON_T,
.bstats = {39, 52, 43, 60, 50, 65}
};

//charmeleon
const pokemonspec_s CHARMELEON = {
.name = "Charmeleon",
.id = 5,
.type1 = FIRE_T,
.type2 = NON_T,
.bstats = {58, 64, 58, 80, 65, 80}
};

//charizard
const pokemonspec_s CHARIZARD = {
.name = "Charizard",
.id = 6,
.type1 = FIRE_T,
.type2 = FLYING_T,
.bstats = {78, 84, 78, 109, 85, 100}
};

//squirtle
const pokemonspec_s SQUIRTLE = {
.name = "Squirtle",
.id = 7,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {44, 48, 65, 50, 64, 43}
};

//wartortle
const pokemonspec_s WARTORTLE = {
.name = "Wartortle",
.id = 8,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {59, 63, 80, 65, 80, 58}
};

//blastoise
const pokemonspec_s BLASTOISE = {
.name = "Blastoise",
.id = 9,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {79, 83, 100, 85, 105, 78}
};

//caterpie
const pokemonspec_s CATERPIE = {
.name = "Caterpie",
.id = 10,
.type1 = BUG_T,
.type2 = NON_T,
.bstats = {45, 30, 35, 20, 20, 45}
};

//metapod
const pokemonspec_s METAPOD = {
.name = "Metapod",
.id = 11,
.type1 = BUG_T,
.type2 = NON_T,
.bstats = {50, 20, 55, 25, 25, 30}
};

//butterfree
const pokemonspec_s BUTTERFREE = {
.name = "Butterfree",
.id = 12,
.type1 = BUG_T,
.type2 = FLYING_T,
.bstats = {60, 45, 50, 90, 80, 70}
};

//weedle
const pokemonspec_s WEEDLE = {
.name = "Weedle",
.id = 13,
.type1 = BUG_T,
.type2 = POISON_T,
.bstats = {40, 35, 30, 20, 20, 50}
};

//kakuna
const pokemonspec_s KAKUNA = {
.name = "Kakuna",
.id = 14,
.type1 = BUG_T,
.type2 = POISON_T,
.bstats = {45, 25, 50, 25, 25, 35}
};

//beedrill
const pokemonspec_s BEEDRILL = {
.name = "Beedrill",
.id = 15,
.type1 = BUG_T,
.type2 = POISON_T,
.bstats = {65, 90, 40, 45, 80, 75}
};

//pidgey
const pokemonspec_s PIDGEY = {
.name = "Pidgey",
.id = 16,
.type1 = NORMAL_T,
.type2 = FLYING_T,
.bstats = {40, 45, 40, 35, 35, 56}
};

//pidgeotto
const pokemonspec_s PIDGEOTTO = {
.name = "Pidgeotto",
.id = 17,
.type1 = NORMAL_T,
.type2 = FLYING_T,
.bstats = {63, 60, 55, 50, 50, 71}
};

//pidgeot
const pokemonspec_s PIDGEOT = {
.name = "Pidgeot",
.id = 18,
.type1 = NORMAL_T,
.type2 = FLYING_T,
.bstats = {83, 80, 75, 70, 70, 101}
};

//rattata
const pokemonspec_s RATTATA = {
.name = "Rattata",
.id = 19,
.type1 = NORMAL_T,
.type2 = NON_T,
.bstats = {30, 56, 35, 25, 35, 72}
};

//raticate
const pokemonspec_s RATICATE = {
.name = "Raticate",
.id = 20,
.type1 = NORMAL_T,
.type2 = NON_T,
.bstats = {55, 81, 60, 50, 70, 97}
};

//spearow
const pokemonspec_s SPEAROW = {
.name = "Spearow",
.id = 21,
.type1 = NORMAL_T,
.type2 = FLYING_T,
.bstats = {40, 60, 30, 31, 31, 70}
};

//fearow
const pokemonspec_s FEAROW = {
.name = "Fearow",
.id = 22,
.type1 = NORMAL_T,
.type2 = FLYING_T,
.bstats = {65, 90, 65, 61, 61, 100}
};

//ekans
const pokemonspec_s EKANS = {
.name = "Ekans",
.id = 23,
.type1 = POISON_T,
.type2 = NON_T,
.bstats = {35, 60, 44, 40, 54, 55}
};

//arbok
const pokemonspec_s ARBOK = {
.name = "Arbok",
.id = 24,
.type1 = POISON_T,
.type2 = NON_T,
.bstats = {60, 85, 69, 65, 79, 80}
};

//pikachu
const pokemonspec_s PIKACHU = {
.name = "Pikachu",
.id = 25,
.type1 = ELECTRIC_T,
.type2 = NON_T,
.bstats = {35, 55, 40, 50, 50, 90}
};

//raichu
const pokemonspec_s RAICHU = {
.name = "Raichu",
.id = 26,
.type1 = ELECTRIC_T,
.type2 = NON_T,
.bstats = {60, 90, 55, 90, 80, 110}
};

//sandshrew
const pokemonspec_s SANDSHREW = {
.name = "Sandshrew",
.id = 27,
.type1 = GROUND_T,
.type2 = NON_T,
.bstats = {50, 75, 85, 20, 30, 40}
};

//sandslash
const pokemonspec_s SANDSLASH = {
.name = "Sandslash",
.id = 28,
.type1 = GROUND_T,
.type2 = NON_T,
.bstats = {75, 100, 110, 45, 55, 65}
};

//nidoran_f
const pokemonspec_s NIDORAN_F = {
.name = "Nidoran (F)",
.id = 29,
.type1 = POISON_T,
.type2 = NON_T,
.bstats = {55, 47, 52, 40, 40, 41}
};

//nidorina
const pokemonspec_s NIDORINA = {
.name = "Nidorina",
.id = 30,
.type1 = POISON_T,
.type2 = NON_T,
.bstats = {70, 62, 67, 55, 55, 56}
};

//nidoqueen
const pokemonspec_s NIDOQUEEN = {
.name = "Nidoqueen",
.id = 31,
.type1 = POISON_T,
.type2 = GROUND_T,
.bstats = {90, 92, 87, 75, 85, 76}
};

//nidoran_m
const pokemonspec_s NIDORAN_M = {
.name = "Nidoran (M)",
.id = 32,
.type1 = POISON_T,
.type2 = NON_T,
.bstats = {46, 57, 40, 40, 40, 50}
};

//nidorino
const pokemonspec_s NIDORINO = {
.name = "Nidorino",
.id = 33,
.type1 = POISON_T,
.type2 = NON_T,
.bstats = {61, 72, 57, 55, 55, 65}
};

//nidoking
const pokemonspec_s NIDOKING = {
.name = "Nidoking",
.id = 34,
.type1 = POISON_T,
.type2 = GROUND_T,
.bstats = {81, 102, 77, 85, 75, 85}
};

//clefairy
const pokemonspec_s CLEFAIRY = {
.name = "Clefairy",
.id = 35,
.type1 = FAIRY_T,
.type2 = NON_T,
.bstats = {70, 45, 48, 60, 65, 35}
};

//clefable
const pokemonspec_s CLEFABLE = {
.name = "Clefable",
.id = 36,
.type1 = FAIRY_T,
.type2 = NON_T,
.bstats = {95, 70, 73, 95, 90, 60}
};

//vulpix
const pokemonspec_s VULPIX = {
.name = "Vulpix",
.id = 37,
.type1 = FIRE_T,
.type2 = NON_T,
.bstats = {38, 41, 40, 50, 65, 65}
};

//ninetales
const pokemonspec_s NINETALES = {
.name = "Ninetales",
.id = 38,
.type1 = FIRE_T,
.type2 = NON_T,
.bstats = {73, 76, 75, 81, 100, 100}
};

//jigglypuff
const pokemonspec_s JIGGLYPUFF = {
.name = "Jigglypuff",
.id = 39,
.type1 = NORMAL_T,
.type2 = FAIRY_T,
.bstats = {115, 45, 20, 45, 25, 20}
};

//wigglytuff
const pokemonspec_s WIGGLYTUFF = {
.name = "Wigglytuff",
.id = 40,
.type1 = NORMAL_T,
.type2 = FAIRY_T,
.bstats = {140, 70, 45, 85, 50, 45}
};

//zubat
const pokemonspec_s ZUBAT = {
.name = "Zubat",
.id = 41,
.type1 = POISON_T,
.type2 = FLYING_T,
.bstats = {40, 45, 35, 30, 40, 55}
};

//golbat
const pokemonspec_s GOLBAT = {
.name = "Golbat",
.id = 42,
.type1 = POISON_T,
.type2 = FLYING_T,
.bstats = {75, 80, 70, 65, 75, 90}
};

//oddish
const pokemonspec_s ODDISH = {
.name = "Oddish",
.id = 43,
.type1 = GRASS_T,
.type2 = POISON_T,
.bstats = {45, 50, 55, 75, 65, 30}
};

//gloom
const pokemonspec_s GLOOM = {
.name = "Gloom",
.id = 44,
.type1 = GRASS_T,
.type2 = POISON_T,
.bstats = {60, 65, 70, 85, 75, 40}
};

//vileplume
const pokemonspec_s VILEPLUME = {
.name = "Vileplume",
.id = 45,
.type1 = GRASS_T,
.type2 = POISON_T,
.bstats = {75, 80, 85, 110, 90, 50}
};

//paras
const pokemonspec_s PARAS = {
.name = "Paras",
.id = 46,
.type1 = BUG_T,
.type2 = GRASS_T,
.bstats = {35, 70, 55, 45, 55, 25}
};

//parasect
const pokemonspec_s PARASECT = {
.name = "Parasect",
.id = 47,
.type1 = BUG_T,
.type2 = GRASS_T,
.bstats = {60, 95, 80, 60, 80, 30}
};

//venonat
const pokemonspec_s VENONAT = {
.name = "Venonat",
.id = 48,
.type1 = BUG_T,
.type2 = POISON_T,
.bstats = {60, 55, 50, 40, 55, 45}
};

//venomoth
const pokemonspec_s VENOMOTH = {
.name = "Venomoth",
.id = 49,
.type1 = BUG_T,
.type2 = POISON_T,
.bstats = {70, 65, 60, 90, 75, 90}
};

//diglett
const pokemonspec_s DIGLETT = {
.name = "Diglett",
.id = 50,
.type1 = GROUND_T,
.type2 = NON_T,
.bstats = {10, 55, 25, 35, 45, 95}
};

//dugtrio
const pokemonspec_s DUGTRIO = {
.name = "Dugtrio",
.id = 51,
.type1 = GROUND_T,
.type2 = NON_T,
.bstats = {35, 80, 50, 50, 70, 120}
};

//meowth
const pokemonspec_s MEOWTH = {
.name = "Meowth",
.id = 52,
.type1 = NORMAL_T,
.type2 = NON_T,
.bstats = {40, 45, 35, 40, 40, 90}
};

//persian
const pokemonspec_s PERSIAN = {
.name = "Persian",
.id = 53,
.type1 = NORMAL_T,
.type2 = NON_T,
.bstats = {65, 70, 60, 65, 65, 115}
};

//psyduck
const pokemonspec_s PSYDUCK = {
.name = "Psyduck",
.id = 54,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {50, 52, 48, 65, 50, 55}
};

//golduck
const pokemonspec_s GOLDUCK = {
.name = "Golduck",
.id = 55,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {80, 82, 78, 95, 80, 85}
};

//mankey
const pokemonspec_s MANKEY = {
.name = "Mankey",
.id = 56,
.type1 = FIGHTING_T,
.type2 = NON_T,
.bstats = {40, 80, 35, 35, 45, 70}
};

//primeape
const pokemonspec_s PRIMEAPE = {
.name = "Primeape",
.id = 57,
.type1 = FIGHTING_T,
.type2 = NON_T,
.bstats = {65, 105, 60, 60, 70, 95}
};

//growlithe
const pokemonspec_s GROWLITHE = {
.name = "Growlithe",
.id = 58,
.type1 = FIRE_T,
.type2 = NON_T,
.bstats = {55, 70, 45, 70, 50, 60}
};

//arcanine
const pokemonspec_s ARCANINE = {
.name = "Arcanine",
.id = 59,
.type1 = FIRE_T,
.type2 = NON_T,
.bstats = {90, 110, 80, 100, 80, 95}
};

//poliwag
const pokemonspec_s POLIWAG = {
.name = "Poliwag",
.id = 60,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {40, 50, 40, 40, 40, 90}
};

//poliwhirl
const pokemonspec_s POLIWHIRL = {
.name = "Poliwhirl",
.id = 61,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {65, 65, 65, 50, 50, 90}
};

//poliwrath
const pokemonspec_s POLIWRATH = {
.name = "Poliwrath",
.id = 62,
.type1 = WATER_T,
.type2 = FIGHTING_T,
.bstats = {90, 95, 95, 70, 90, 70}
};

//abra
const pokemonspec_s ABRA = {
.name = "Abra",
.id = 63,
.type1 = PSYCHIC_T,
.type2 = NON_T,
.bstats = {25, 20, 15, 105, 55, 90}
};

//kadabra
const pokemonspec_s KADABRA = {
.name = "Kadabra",
.id = 64,
.type1 = PSYCHIC_T,
.type2 = NON_T,
.bstats = {40, 35, 30, 120, 70, 105}
};

//alakazam
const pokemonspec_s ALAKAZAM = {
.name = "Alakazam",
.id = 65,
.type1 = PSYCHIC_T,
.type2 = NON_T,
.bstats = {55, 50, 45, 135, 95, 120}
};

//machop
const pokemonspec_s MACHOP = {
.name = "Machop",
.id = 66,
.type1 = FIGHTING_T,
.type2 = NON_T,
.bstats = {70, 80, 50, 35, 35, 35}
};

//machoke
const pokemonspec_s MACHOKE = {
.name = "Machoke",
.id = 67,
.type1 = FIGHTING_T,
.type2 = NON_T,
.bstats = {80, 100, 70, 50, 60, 45}
};

//machamp
const pokemonspec_s MACHAMP = {
.name = "Machamp",
.id = 68,
.type1 = FIGHTING_T,
.type2 = NON_T,
.bstats = {90, 130, 80, 65, 85, 55}
};

//bellsprout
const pokemonspec_s BELLSPROUT = {
.name = "Bellsprout",
.id = 69,
.type1 = GRASS_T,
.type2 = POISON_T,
.bstats = {50, 75, 35, 70, 30, 40}
};

//weepinbell
const pokemonspec_s WEEPINBELL = {
.name = "Weepinbell",
.id = 70,
.type1 = GRASS_T,
.type2 = POISON_T,
.bstats = {65, 90, 50, 85, 45, 55}
};

//victreebel
const pokemonspec_s VICTREEBEL = {
.name = "Victreebel",
.id = 71,
.type1 = GRASS_T,
.type2 = POISON_T,
.bstats = {80, 105, 65, 100, 70, 70}
};

//tentacool
const pokemonspec_s TENTACOOL = {
.name = "Tentacool",
.id = 72,
.type1 = WATER_T,
.type2 = POISON_T,
.bstats = {40, 40, 35, 50, 100, 70}
};

//tentacruel
const pokemonspec_s TENTACRUEL = {
.name = "Tentacruel",
.id = 73,
.type1 = WATER_T,
.type2 = POISON_T,
.bstats = {80, 70, 65, 80, 120, 100}
};

//geodude
const pokemonspec_s GEODUDE = {
.name = "Geodude",
.id = 74,
.type1 = ROCK_T,
.type2 = GROUND_T,
.bstats = {40, 80, 100, 30, 30, 20}
};

//graveler
const pokemonspec_s GRAVELER = {
.name = "Graveler",
.id = 75,
.type1 = ROCK_T,
.type2 = GROUND_T,
.bstats = {55, 95, 115, 45, 45, 35}
};

//golem
const pokemonspec_s GOLEM = {
.name = "Golem",
.id = 76,
.type1 = ROCK_T,
.type2 = GROUND_T,
.bstats = {80, 120, 130, 55, 65, 45}
};

//ponyta
const pokemonspec_s PONYTA = {
.name = "Ponyta",
.id = 77,
.type1 = FIRE_T,
.type2 = NON_T,
.bstats = {50, 85, 55, 65, 65, 90}
};

//rapidash
const pokemonspec_s RAPIDASH = {
.name = "Rapidash",
.id = 78,
.type1 = FIRE_T,
.type2 = NON_T,
.bstats = {65, 100, 70, 80, 80, 105}
};

//slowpoke
const pokemonspec_s SLOWPOKE = {
.name = "Slowpoke",
.id = 79,
.type1 = WATER_T,
.type2 = PSYCHIC_T,
.bstats = {90, 65, 65, 40, 40, 15}
};

//slowbro
const pokemonspec_s SLOWBRO = {
.name = "Slowbro",
.id = 80,
.type1 = WATER_T,
.type2 = PSYCHIC_T,
.bstats = {95, 75, 110, 100, 80, 30}
};

//magnemite
const pokemonspec_s MAGNEMITE = {
.name = "Magnemite",
.id = 81,
.type1 = ELECTRIC_T,
.type2 = STEEL_T,
.bstats = {25, 35, 70, 95, 55, 45}
};

//magneton
const pokemonspec_s MAGNETON = {
.name = "Magneton",
.id = 82,
.type1 = ELECTRIC_T,
.type2 = STEEL_T,
.bstats = {50, 60, 95, 120, 70, 70}
};

//farfetch'd
const pokemonspec_s FARFETCHD = {
.name = "Farfetch'd",
.id = 83,
.type1 = NORMAL_T,
.type2 = FLYING_T,
.bstats = {52, 65, 55, 58, 62, 60}
};

//doduo
const pokemonspec_s DODUO = {
.name = "Doduo",
.id = 84,
.type1 = NORMAL_T,
.type2 = FLYING_T,
.bstats = {35, 85, 45, 35, 35, 75}
};

//dodrio
const pokemonspec_s DODRIO = {
.name = "Dodrio",
.id = 85,
.type1 = NORMAL_T,
.type2 = FLYING_T,
.bstats = {60, 110, 70, 60, 60, 100}
};

//seel
const pokemonspec_s SEEL = {
.name = "Seel",
.id = 86,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {65, 45, 55, 45, 70, 45}
};

//dewgong
const pokemonspec_s DEWGONG = {
.name = "Dewgong",
.id = 87,
.type1 = WATER_T,
.type2 = ICE_T,
.bstats = {90, 70, 80, 70, 95, 70}
};

//grimer
const pokemonspec_s GRIMER = {
.name = "Grimer",
.id = 88,
.type1 = POISON_T,
.type2 = NON_T,
.bstats = {80, 80, 50, 40, 50, 25}
};

//muk
const pokemonspec_s MUK = {
.name = "Muk",
.id = 89,
.type1 = POISON_T,
.type2 = NON_T,
.bstats = {105, 105, 75, 65, 100, 50}
};

//shellder
const pokemonspec_s SHELLDER = {
.name = "Shellder",
.id = 90,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {30, 65, 100, 45, 25, 40}
};

//cloyster
const pokemonspec_s CLOYSTER = {
.name = "Cloyster",
.id = 91,
.type1 = WATER_T,
.type2 = ICE_T,
.bstats = {50, 95, 180, 85, 45, 70}
};

//gastly
const pokemonspec_s GASTLY = {
.name = "Gastly",
.id = 92,
.type1 = GHOST_T,
.type2 = POISON_T,
.bstats = {30, 35, 30, 100, 35, 80}
};

//haunter
const pokemonspec_s HAUNTER = {
.name = "Haunter",
.id = 93,
.type1 = GHOST_T,
.type2 = POISON_T,
.bstats = {45, 50, 45, 115, 55, 95}
};

//gengar
const pokemonspec_s GENGAR = {
.name = "Gengar",
.id = 94,
.type1 = GHOST_T,
.type2 = POISON_T,
.bstats = {60, 65, 60, 130, 75, 110}
};

//onix
const pokemonspec_s ONIX = {
.name = "Onix",
.id = 95,
.type1 = ROCK_T,
.type2 = GROUND_T,
.bstats = {35, 45, 160, 30, 45, 70}
};

//drowzee
const pokemonspec_s DROWZEE = {
.name = "Drowzee",
.id = 96,
.type1 = PSYCHIC_T,
.type2 = NON_T,
.bstats = {60, 48, 45, 43, 90, 42}
};

//hypno
const pokemonspec_s HYPNO = {
.name = "Hypno",
.id = 97,
.type1 = PSYCHIC_T,
.type2 = NON_T,
.bstats = {85, 73, 70, 73, 115, 67}
};

//krabby
const pokemonspec_s KRABBY = {
.name = "Krabby",
.id = 98,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {30, 105, 90, 25, 25, 50}
};

//kingler
const pokemonspec_s KINGLER = {
.name = "Kingler",
.id = 99,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {55, 130, 115, 50, 50, 75}
};

//voltorb
const pokemonspec_s VOLTORB = {
.name = "Voltorb",
.id = 100,
.type1 = ELECTRIC_T,
.type2 = NON_T,
.bstats = {40, 30, 50, 55, 55, 100}
};

//electrode
const pokemonspec_s ELECTRODE = {
.name = "Electrode",
.id = 101,
.type1 = ELECTRIC_T,
.type2 = NON_T,
.bstats = {60, 50, 70, 80, 80, 140}
};

//exeggcute
const pokemonspec_s EXEGGCUTE = {
.name = "Exeggcute",
.id = 102,
.type1 = GRASS_T,
.type2 = PSYCHIC_T,
.bstats = {60, 40, 80, 60, 45, 40}
};

//exeggutor
const pokemonspec_s EXEGGUTOR = {
.name = "Exeggutor",
.id = 103,
.type1 = GRASS_T,
.type2 = PSYCHIC_T,
.bstats = {95, 95, 85, 125, 65, 55}
};

//cubone
const pokemonspec_s CUBONE = {
.name = "Cubone",
.id = 104,
.type1 = GROUND_T,
.type2 = NON_T,
.bstats = {50, 50, 95, 40, 50, 35}
};

//marowak
const pokemonspec_s MAROWAK = {
.name = "Marowak",
.id = 105,
.type1 = GROUND_T,
.type2 = NON_T,
.bstats = {60, 80, 110, 50, 80, 45}
};

//hitmonlee
const pokemonspec_s HITMONLEE = {
.name = "Hitmonlee",
.id = 106,
.type1 = FIGHTING_T,
.type2 = NON_T,
.bstats = {50, 120, 53, 35, 110, 87}
};

//hitmonchan
const pokemonspec_s HITMONCHAN = {
.name = "Hitmonchan",
.id = 107,
.type1 = FIGHTING_T,
.type2 = NON_T,
.bstats = {50, 105, 79, 35, 110, 76}
};

//lickitung
const pokemonspec_s LICKITUNG = {
.name = "Lickitung",
.id = 108,
.type1 = NORMAL_T,
.type2 = NON_T,
.bstats = {90, 55, 75, 60, 75, 30}
};

//koffing
const pokemonspec_s KOFFING = {
.name = "Koffing",
.id = 109,
.type1 = POISON_T,
.type2 = NON_T,
.bstats = {40, 65, 95, 60, 45, 35}
};

//weezing
const pokemonspec_s WEEZING = {
.name = "Weezing",
.id = 110,
.type1 = POISON_T,
.type2 = NON_T,
.bstats = {65, 90, 120, 85, 70, 60}
};

//rhyhorn
const pokemonspec_s RHYHORN = {
.name = "Rhyhorn",
.id = 111,
.type1 = GROUND_T,
.type2 = ROCK_T,
.bstats = {80, 85, 95, 30, 30, 25}
};

//rhydon
const pokemonspec_s RHYDON = {
.name = "Rhydon",
.id = 112,
.type1 = GROUND_T,
.type2 = ROCK_T,
.bstats = {105, 130, 120, 45, 45, 40}
};

//chansey
const pokemonspec_s CHANSEY = {
.name = "Chansey",
.id = 113,
.type1 = NORMAL_T,
.type2 = NON_T,
.bstats = {250, 5, 5, 35, 105, 50}
};

//tangela
const pokemonspec_s TANGELA = {
.name = "Tangela",
.id = 114,
.type1 = GRASS_T,
.type2 = NON_T,
.bstats = {65, 55, 115, 100, 40, 60}
};

//kangaskhan
const pokemonspec_s KANGASKHAN = {
.name = "Kangaskhan",
.id = 115,
.type1 = NORMAL_T,
.type2 = NON_T,
.bstats = {105, 95, 80, 40, 80, 90}
};

//horsea
const pokemonspec_s HORSEA = {
.name = "Horsea",
.id = 116,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {30, 40, 70, 70, 25, 60}
};

//seadra
const pokemonspec_s SEADRA = {
.name = "Seadra",
.id = 117,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {55, 65, 95, 95, 45, 85}
};

//goldeen
const pokemonspec_s GOLDEEN = {
.name = "Goldeen",
.id = 118,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {45, 67, 60, 35, 50, 63}
};

//seaking
const pokemonspec_s SEAKING = {
.name = "Seaking",
.id = 119,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {80, 92, 65, 65, 80, 68}
};

//staryu
const pokemonspec_s STARYU = {
.name = "Staryu",
.id = 120,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {30, 45, 55, 70, 55, 85}
};

//starmie
const pokemonspec_s STARMIE = {
.name = "Starmie",
.id = 121,
.type1 = WATER_T,
.type2 = PSYCHIC_T,
.bstats = {60, 75, 85, 100, 85, 115}
};

//mr. mime
const pokemonspec_s MRMIME = {
.name = "Mr. Mime",
.id = 122,
.type1 = PSYCHIC_T,
.type2 = NON_T,
.bstats = {40, 45, 65, 100, 120, 90}
};

//scyther
const pokemonspec_s SCYTHER = {
.name = "Scyther",
.id = 123,
.type1 = BUG_T,
.type2 = FLYING_T,
.bstats = {70, 110, 80, 55, 80, 105}
};

//jynx
const pokemonspec_s JYNX = {
.name = "Jynx",
.id = 124,
.type1 = ICE_T,
.type2 = PSYCHIC_T,
.bstats = {65, 50, 35, 115, 95, 95}
};

//electabuzz
const pokemonspec_s ELECTABUZZ = {
.name = "Electabuzz",
.id = 125,
.type1 = ELECTRIC_T,
.type2 = NON_T,
.bstats = {65, 83, 57, 95, 85, 105}
};

//magmar
const pokemonspec_s MAGMAR = {
.name = "Magmar",
.id = 126,
.type1 = FIRE_T,
.type2 = NON_T,
.bstats = {65, 95, 57, 100, 85, 93}
};

//pinsir
const pokemonspec_s PINSIR = {
.name = "Pinsir",
.id = 127,
.type1 = BUG_T,
.type2 = NON_T,
.bstats = {65, 125, 100, 55, 70, 85}
};

//tauros
const pokemonspec_s TAUROS = {
.name = "Tauros",
.id = 128,
.type1 = NORMAL_T,
.type2 = NON_T,
.bstats = {75, 100, 95, 40, 70, 110}
};

//magikarp
const pokemonspec_s MAGIKARP = {
.name = "Magikarp",
.id = 129,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {20, 10, 55, 15, 20, 80}
};

//gyarados
const pokemonspec_s GYARADOS = {
.name = "Gyarados",
.id = 130,
.type1 = WATER_T,
.type2 = FLYING_T,
.bstats = {95, 125, 79, 60, 100, 81}
};

//lapras
const pokemonspec_s LAPRAS = {
.name = "Lapras",
.id = 131,
.type1 = WATER_T,
.type2 = ICE_T,
.bstats = {130, 85, 80, 85, 95, 60}
};

//ditto
const pokemonspec_s DITTO = {
.name = "Ditto",
.id = 132,
.type1 = NORMAL_T,
.type2 = NON_T,
.bstats = {48, 48, 48, 48, 48, 48}
};

//eevee
const pokemonspec_s EEVEE = {
.name = "Eevee",
.id = 133,
.type1 = NORMAL_T,
.type2 = NON_T,
.bstats = {55, 55, 50, 45, 65, 55}
};

//vaporeon
const pokemonspec_s VAPOREON = {
.name = "Vaporeon",
.id = 134,
.type1 = WATER_T,
.type2 = NON_T,
.bstats = {130, 65, 60, 110, 95, 65}
};

//jolteon
const pokemonspec_s JOLTEON = {
.name = "Jolteon",
.id = 135,
.type1 = ELECTRIC_T,
.type2 = NON_T,
.bstats = {65, 65, 60, 110, 95, 130}
};

//flareon
const pokemonspec_s FLAREON = {
.name = "Flareon",
.id = 136,
.type1 = FIRE_T,
.type2 = NON_T,
.bstats = {65, 130, 60, 95, 110, 65}
};

//porygon
const pokemonspec_s PORYGON = {
.name = "Porygon",
.id = 137,
.type1 = NORMAL_T,
.type2 = NON_T,
.bstats = {65, 60, 70, 85, 75, 40}
};

//omanyte
const pokemonspec_s OMANYTE = {
.name = "Omanyte",
.id = 138,
.type1 = ROCK_T,
.type2 = WATER_T,
.bstats = {35, 40, 100, 90, 55, 35}
};

//omastar
const pokemonspec_s OMASTAR = {
.name = "Omastar",
.id = 139,
.type1 = ROCK_T,
.type2 = WATER_T,
.bstats = {70, 60, 125, 115, 70, 55}
};

//kabuto
const pokemonspec_s KABUTO = {
.name = "Kabuto",
.id = 140,
.type1 = ROCK_T,
.type2 = WATER_T,
.bstats = {30, 80, 90, 55, 45, 55}
};

//kabutops
const pokemonspec_s KABUTOPS = {
.name = "Kabutops",
.id = 141,
.type1 = ROCK_T,
.type2 = WATER_T,
.bstats = {60, 115, 105, 65, 70, 80}
};

//aerodactyl
const pokemonspec_s AERODACTYL = {
.name = "Aerodactyl",
.id = 142,
.type1 = ROCK_T,
.type2 = FLYING_T,
.bstats = {80, 105, 65, 60, 75, 130}
};

//snorlax
const pokemonspec_s SNORLAX = {
.name = "Snorlax",
.id = 143,
.type1 = NORMAL_T,
.type2 = NON_T,
.bstats = {160, 110, 65, 65, 110, 30}
};

//articuno
const pokemonspec_s ARTICUNO = {
.name = "Articuno",
.id = 144,
.type1 = ICE_T,
.type2 = FLYING_T,
.bstats = {90, 85, 100, 95, 125, 85}
};

//zapdos
const pokemonspec_s ZAPDOS = {
.name = "Zapdos",
.id = 145,
.type1 = ELECTRIC_T,
.type2 = FLYING_T,
.bstats = {90, 90, 85, 125, 90, 100}
};

//moltres
const pokemonspec_s MOLTRES = {
.name = "Moltres",
.id = 146,
.type1 = FIRE_T,
.type2 = FLYING_T,
.bstats = {90, 100, 90, 125, 85, 90}
};

//dratini
const pokemonspec_s DRATINI = {
.name = "Dratini",
.id = 147,
.type1 = DRAGON_T,
.type2 = NON_T,
.bstats = {41, 64, 45, 50, 50, 50}
};

//dragonair
const pokemonspec_s DRAGONAIR = {
.name = "Dragonair",
.id = 148,
.type1 = DRAGON_T,
.type2 = NON_T,
.bstats = {61, 84, 65, 70, 70, 70}
};

//dragonite
const pokemonspec_s DRAGONITE = {
.name = "Dragonite",
.id = 149,
.type1 = DRAGON_T,
.type2 = FLYING_T,
.bstats = {91, 134, 95, 100, 100, 80}
};

//mewtwo
const pokemonspec_s MEWTWO = {
.name = "Mewtwo",
.id = 150,
.type1 = PSYCHIC_T,
.type2 = NON_T,
.bstats = {106, 110, 90, 154, 90, 130}
};

//mewtwo
const pokemonspec_s MEW = {
.name = "Mew",
.id = 151,
.type1 = PSYCHIC_T,
.type2 = NON_T,
.bstats = {100, 100, 100, 100, 100, 100}
};

#endif
