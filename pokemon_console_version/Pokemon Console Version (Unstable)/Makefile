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

game: game.o global.o input-p.o battle-p.o eor-p.o win-p.o
	$(CXX) $(CXXFLAGS) -o $@ $^

dependancies:
	gcc -MM *.c

# ------ Dependences (.cpp -> .o using default Makefile rule) -----
# gcc -MM *.c

battle-p.o: battle-p.c battle-p.h types.h gdefines.h pkmn-tdef.h global.h
eor-p.o: eor-p.c pkmn-tdef.h gdefines.h types.h eor-p.h global.h
game.o: game.c types.h gdefines.h pkmn-tdef.h input-p.h battle-p.h \
 eor-p.h win-p.h global.h game.h
global.o: global.c types.h gdefines.h pkmn-tdef.h global.h global-init.h
input-p.o: input-p.c types.h gdefines.h pkmn-tdef.h input-p.h global.h
win-p.o: win-p.c win-p.h types.h gdefines.h pkmn-tdef.h global.h
