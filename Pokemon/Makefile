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

game: game.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# ------ Dependences (.cpp -> .o using default Makefile rule) -----
# gcc -MM *.c

game.o: game.c global.h game.h battle.h pokemon.h moves.h rentals.h \
 inputphase.h
inputphase.o: inputphase.c inputphase.h
