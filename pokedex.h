#ifndef _POKEDEX_H
#define _POKEDEX_H

#include "pokemon.h"

typedef struct Ressource {
	int poussieres;
	int nb_bonbons;
} Ressource;

typedef struct Pokedex {
	Pokemon* p; //Tableau dynamique de pokemon
	int nbpokemon;
	int maxpokemon;
} Pokedex;

Pokedex* initPokedex(const int size);
//Fonction qui initialise un pokedex de taille size

void insertPokemon(Pokedex* MonPokedex, Pokemon p);

void affichagePokedex(Pokedex* MonPokedex, EspecePokemon bestiaire[150], char* typesLabel[18],Ressource reserve);

Pokemon genererPokemon(EspecePokemon bestiaire[150], char* typesLabel[18]);

void attraperPokemon(Pokemon Pokemon_sauvage, Pokedex* MonPokedex, Ressource& reserve,double proba_de_capture, EspecePokemon bestiaire[150], char* typesLabel[18]);
//Fonction qui permet d'attraper un pokemon sauvage (qui a été généré).

#endif

