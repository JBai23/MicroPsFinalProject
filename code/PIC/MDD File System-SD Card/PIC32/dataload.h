#include "types.h"

pokemonspec_s specs_all[151];
move_s moves_all[111];
pokemon_s rentals_all[12];

void init_trainers();
void loadTrainer(trainer_s *trainer, char *file);