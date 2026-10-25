#ifndef HISTORIQUE_H
#define HISTORIQUE_H

typedef struct Evolution {
	char* nom_avant;
	char* nom_apres;
	Evolution* suivant_evo;
} Evolution;

typedef struct historique {
	int nombre;
	Evolution* debut;
} historique;

#include "pokemon.h"

void inserer_evo(historique* evo_des_pokemons, Evolution* pokemon_evolue);

void afficher_evo(historique* evo_des_pokemons);

#endif