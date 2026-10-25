#ifndef _POKEMON_H_
#define _POKEMON_H_

#include "pokemonTypes.h"
#include "historique.h"

void menu();

typedef struct Pokemon {
	char* nom;
	int xp;
	int evo;
	int pv;
	int cp;
} Pokemon;

typedef struct EspecePokemon {
	char* nom;
	PokemonType type;
	int nbBonbonsPourEvoluer;
	char* evolvesTo;
	bool estEvolue;
} EspecePokemon;

void powerup(Pokemon& p);

void evolve(Pokemon& p, EspecePokemon bestiaire[], historique* evo_des_pokemons);

void display(const Pokemon p, EspecePokemon bestiaire[], char* typelabel[]);

#endif