#ifndef _BESTIAIRE_H_
#define _BESTIAIRE_H_

#include "pokemon.h"

void initBestiaire(EspecePokemon bestiaire[]);

void affichageBestiaire(EspecePokemon bestiaire[], char* typesLabel[]);
//Fonction qui affiche le nom des pokemons present dans le bestiaire

void triBestiaire(EspecePokemon bestiaire[],int n);
//Fonction qui trie le bestiaire mis en argument les noms des pokemons par ordre alphabétique

void affichageBestiairetrie(EspecePokemon bestiaire[], char* typesLabel[]);
//Fonction qui affiche le bestiaire trie mis en argument

EspecePokemon asso_espece_et_nompokemon(EspecePokemon bestiaire[], char* nompokemon);
//Fonction qui renvoie l'espece Pokemon associee au pokemon mis en argument si son nom existe dans le bestiaire
//On cherche le pokemon correspondant dans le bestiaire.

#endif