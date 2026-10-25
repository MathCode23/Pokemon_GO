#ifndef COMBAT_H
#define COMBAT_H

#include "pokemonTypes.h"
#include "pokedex.h"

typedef struct CombatEspece {
	char* nature; 
	char* strongAgainst[5];
	char* weakAgainst[5];
	CombatEspece* suivant;
} CombatEspece;

typedef struct CombatHash {
	int taille;
	CombatEspece* element[26];
} CombatHash;

int hashage(const char* str, CombatHash* hashtable);

char* pokemonTypeToString(PokemonType t);

CombatEspece* get(CombatHash* hashtable, char* cle);
//Cette fonction permet de trouver le pointeur vers un CombatEspece dont la nature vaut key.

bool contains(CombatHash* hashtable, CombatEspece* c);
//Cette fonction permet de savoir si un CombatEspece pointé par le pointeur c appartient à la table de hachage.

void insert(CombatEspece* c, CombatHash* hashtable);
//Cette fonction permet d'insérer un nouvel élément à la table de hachage.

CombatHash* initCombatHash();
//Cette fonction permet d'initialiser la table de hachage.

bool est_dans(char* tableau[5], char* val);
//Cette fonction permet de tester si une chaîne de caractère appartient à un tableau statique.

void combat(CombatHash* hashtable, Pokedex* MonPokedex, EspecePokemon bestiaire[]);
//Cette fonction permet de choisir deux pokemons et de les faire se battre entre eux.

#endif	