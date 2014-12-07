#
# Makefile for Pokemon
#
# Andrew Fishberg
# 

# ----- Make Variables -----

#OPTFLAGS  = -O3
OPTFLAGS  = -O0
#DEFINES   =
#VERSION   = -std=c++11
CXXFLAGS  =	-g $(OPTFLAGS) -Wall -Wextra -pedantic \
                $(DEFINES) $(VERSION)
CXX	  =	gcc
#GTEST_LIB =	-lgtest -lgtest_main

#TESTS     =     node_test heap_test map_test tokenizer_test
TARGETS   = 	game
#TARGETS are things with mains

# ----- Make Rules -----
all:	$(TARGETS)

clean:
	rm -f $(TARGETS) *.o

game: game.o input-p.o global.o
	$(CXX) $(CXXFLAGS) -o $@ $^

depend:
	gcc -MM *.c

# ------ Dependences (.cpp -> .o using default Makefile rule) -----
# gcc -MM *.c

game.o: game.c gdefines.h types.h pkmn-tdef.h pokemon-def.h moves-def.h \
 rentals-def.h input-p.h battle-p.h global.h game.h
global.o: global.c types.h gdefines.h pkmn-tdef.h pokemon-def.h \
 moves-def.h global.h
input-p.o: input-p.c types.h gdefines.h pkmn-tdef.h pokemon-def.h \
 moves-def.h input-p.h

