
#include "inputphase.h"

#ifndef BST_H
#define BST_H 1

// battlestate typedefs
struct battlestate_s;


// global battlestate
//battlestate_s curr;

void init_battlestate();

int get_currplayer(); // rtns 1 if curr is player1, 2 if player2

#endif