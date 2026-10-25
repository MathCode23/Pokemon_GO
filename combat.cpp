#include <iostream>
#include <string>
using namespace std;

#include "combat.h"
#include "pokemon.h"
#include "bestiaire.h"
#include "utils.h"

int hashage(const char* str, CombatHash* hashtable) {
	unsigned long hash = 5381;
	int c;
	while (c = *str++) {
		hash = ((hash << 5) + hash) + c; /* hash*33 + c */
	}
	return hash%hashtable->taille;
}

char* pokemonTypeToString(PokemonType t) {
	if (t == Normal) {
		return "Normal";
	}
	else if (t == Fighting) {
		return "Fighting";
	}
	else if (t == Flying) {
		return "Flying";
	}
	else if (t == Poison) {
		return "Poison";
	}
	else if (t == Ground) {
		return "Ground";
	}
	else if (t == Rock) {
		return "Rock";
	}
	else if (t == Bug) {
		return "Bug";
	}
	else if (t == Ghost) {
		return "Ghost";
	}
	else if (t == Steel) {
		return "Steel";
	}
	else if (t == Fire) {
		return "Fire";
	}
	else if (t == Grass) {
		return "Grass";
	}
	else if (t == Water) {
		return "Water";
	}
	else if (t == Electric) {
		return "Electric";
	}
	else if (t == Psychic) {
		return "Psychic";
	}
	else if (t == Ice) {
		return "Ice";
	}
	else if (t == Dragon) {
		return "Dragon";
	}
	else if (t == Dark) {
		return "Dark";
	}
	else {
		return "Fairy";
	}
}


CombatEspece* get(CombatHash* hashtable, char* cle) {
	int alveole = hashage(cle, hashtable);
	CombatEspece* element_actuel = hashtable->element[alveole];
	while (element_actuel != nullptr && strcmp(element_actuel->nature, cle) != 0) {
		element_actuel = element_actuel->suivant;
	}
	return element_actuel;
}

bool contains(CombatHash* hashtable, CombatEspece* c) {
	CombatEspece* element = get(hashtable, c->nature);
	return (element != NULL);
}


void insert(CombatEspece* c, CombatHash* hashtable) {
	if (!contains(hashtable, c)) {
		int alveole = hashage(c->nature, hashtable);
		CombatEspece* element_actuel = hashtable->element[alveole];
		if (element_actuel == NULL) {
			hashtable->element[alveole] = c;
		}
		else {
			while (element_actuel->suivant != NULL) {
				element_actuel = element_actuel->suivant;
			}
			element_actuel->suivant = c;
		}
	}
}

CombatHash* initCombatHash()
{
	CombatHash* hashtable = new CombatHash;
	hashtable->taille = 18;
	// Initialisation
	for (int k = 0; k < 26; k++)
	{
		hashtable->element[k] = nullptr;
	}

	// Insertions successives
	int i = -1;
	CombatEspece* bug = new CombatEspece;
	bug->nature = "Bug";
	bug->suivant = nullptr;
	bug->strongAgainst[0] = "Dark";
	bug->strongAgainst[1] = "Grass";
	bug->strongAgainst[2] = "Psychic";
	bug->weakAgainst[0] = "Fire";
	bug->weakAgainst[1] = "Flying";
	bug->weakAgainst[2] = "Rock";
	insert(bug, hashtable);

	CombatEspece* dark = new CombatEspece;
	dark->nature = "Dark";
	dark->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		dark->strongAgainst[i] = nullptr;
		dark->weakAgainst[i] = nullptr;
	}
	dark->strongAgainst[0] = "Ghost";
	dark->strongAgainst[1] = "Psychic";
	dark->weakAgainst[0] = "Bug";
	dark->weakAgainst[1] = "Fairy";
	dark->weakAgainst[2] = "Fight";
	insert(dark, hashtable);

	CombatEspece* dragon = new CombatEspece;
	dragon->nature = "Dragon";
	dragon->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		dragon->strongAgainst[i] = nullptr;
		dragon->weakAgainst[i] = nullptr;
	}
	dragon->strongAgainst[0] = "Dragon";
	dragon->weakAgainst[0] = "Dragon";
	dragon->weakAgainst[1] = "Fairy";
	dragon->weakAgainst[2] = "Ice";
	insert(dragon, hashtable);

	CombatEspece* electric = new CombatEspece;
	electric->nature = "Electric";
	electric->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		electric->strongAgainst[i] = nullptr;
		electric->weakAgainst[i] = nullptr;
	}
	electric->strongAgainst[0] = "Flying";
	electric->strongAgainst[1] = "Water";
	electric->weakAgainst[0] = "Ground";
	insert(electric, hashtable);

	CombatEspece* fairy = new CombatEspece;
	fairy->nature = "Fairy";
	fairy->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		fairy->strongAgainst[i] = nullptr;
		fairy->weakAgainst[i] = nullptr;
	}
	fairy->strongAgainst[0] = "Dark";
	fairy->strongAgainst[1] = "Dragon";
	fairy->strongAgainst[2] = "Fight";
	fairy->weakAgainst[0] = "Poison";
	fairy->weakAgainst[1] = "Steel";
	insert(fairy, hashtable);

	CombatEspece* fighting = new CombatEspece;
	fighting->nature = "Fighting";
	fighting->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		fighting->strongAgainst[i] = nullptr;
		fighting->weakAgainst[i] = nullptr;
	}
	fighting->strongAgainst[0] = "Dark";
	fighting->strongAgainst[1] = "Ice";
	fighting->strongAgainst[2] = "Normal";
	fighting->strongAgainst[3] = "Rock";
	fighting->strongAgainst[4] = "Steel";
	fighting->weakAgainst[0] = "Fairly";
	fighting->weakAgainst[1] = "Flying";
	fighting->weakAgainst[2] = "Psychic";
	insert(fighting, hashtable);

	CombatEspece* fire = new CombatEspece;
	fire->nature = "Fire";
	fire->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		fire->strongAgainst[i] = nullptr;
		fire->weakAgainst[i] = nullptr;
	}
	fire->strongAgainst[0] = "Bug";
	fire->strongAgainst[1] = "Grass";
	fire->strongAgainst[2] = "Ice";
	fire->strongAgainst[3] = "Steel";
	fire->weakAgainst[0] = "Ground";
	fire->weakAgainst[1] = "Rock";
	fire->weakAgainst[2] = "Water";
	insert(fire, hashtable);

	CombatEspece* flying = new CombatEspece;
	flying->nature = "Flying";
	flying->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		flying->strongAgainst[i] = nullptr;
		flying->weakAgainst[i] = nullptr;
	}
	flying->strongAgainst[0] = "Bug";
	flying->strongAgainst[1] = "Fight";
	flying->strongAgainst[2] = "Grass";
	flying->weakAgainst[0] = "Electric";
	flying->weakAgainst[1] = "Ice";
	flying->weakAgainst[2] = "Rock";
	insert(flying, hashtable);

	CombatEspece* ghost = new CombatEspece;
	ghost->nature = "Ghost";
	ghost->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		ghost->strongAgainst[i] = nullptr;
		ghost->weakAgainst[i] = nullptr;
	}
	ghost->strongAgainst[0] = "Ghost";
	ghost->strongAgainst[1] = "Psychic";
	ghost->weakAgainst[0] = "Dark";
	ghost->weakAgainst[1] = "Ghost";
	insert(ghost, hashtable);

	CombatEspece* grass = new CombatEspece;
	grass->nature = "Grass";
	grass->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		grass->strongAgainst[i] = nullptr;
		grass->weakAgainst[i] = nullptr;
	}
	grass->strongAgainst[0] = "Ground";
	grass->strongAgainst[1] = "Rock";
	grass->strongAgainst[2] = "Water";
	grass->weakAgainst[0] = "Bug";
	grass->weakAgainst[1] = "Fire";
	grass->weakAgainst[2] = "Flying";
	grass->weakAgainst[3] = "Ice";
	grass->weakAgainst[4] = "Poison";
	insert(grass, hashtable);

	CombatEspece* ground = new CombatEspece;
	ground->nature = "Ground";
	ground->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		ground->strongAgainst[i] = nullptr;
		ground->weakAgainst[i] = nullptr;
	}
	ground->strongAgainst[0] = "Electric";
	ground->strongAgainst[1] = "Fire";
	ground->strongAgainst[2] = "Poison";
	ground->strongAgainst[3] = "Rock";
	ground->strongAgainst[4] = "Steel";
	ground->weakAgainst[0] = "Grass";
	ground->weakAgainst[1] = "Ice";
	ground->weakAgainst[2] = "Water";
	insert(ground, hashtable);

	CombatEspece* ice = new CombatEspece;
	ice->nature = "Ice";
	ice->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		ice->strongAgainst[i] = nullptr;
		ice->weakAgainst[i] = nullptr;
	}
	ice->strongAgainst[0] = "Dragon";
	ice->strongAgainst[1] = "Flying";
	ice->strongAgainst[2] = "Grass";
	ice->strongAgainst[3] = "Ground";
	ice->weakAgainst[0] = "Fight";
	ice->weakAgainst[1] = "Fire";
	ice->weakAgainst[2] = "Rock";
	ice->weakAgainst[3] = "Steel";
	insert(ice, hashtable);

	CombatEspece* normal = new CombatEspece;
	normal->nature = "Normal";
	normal->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		normal->strongAgainst[i] = nullptr;
		normal->weakAgainst[i] = nullptr;
	}
	normal->weakAgainst[0] = "Fight";
	insert(normal, hashtable); // correction ici.

	CombatEspece* poison = new CombatEspece;
	poison->nature = "Poison";
	poison->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		poison->strongAgainst[i] = nullptr;
		poison->weakAgainst[i] = nullptr;
	}
	poison->strongAgainst[0] = "Fairy";
	poison->strongAgainst[1] = "Grass";
	poison->weakAgainst[0] = "Ground";
	poison->weakAgainst[1] = "Psychic";
	insert(poison, hashtable);

	CombatEspece* psychic = new CombatEspece;
	psychic->nature = "Psychic";
	psychic->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		psychic->strongAgainst[i] = nullptr;
		psychic->weakAgainst[i] = nullptr;
	}
	psychic->strongAgainst[0] = "Fight";
	psychic->strongAgainst[1] = "Poison";
	psychic->weakAgainst[0] = "Bug";
	psychic->weakAgainst[1] = "Dark";
	psychic->weakAgainst[2] = "Ghost";
	insert(psychic, hashtable);

	CombatEspece* rock = new CombatEspece;
	rock->nature = "Rock";
	rock->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		rock->strongAgainst[i] = nullptr;
		rock->weakAgainst[i] = nullptr;
	}
	rock->strongAgainst[0] = "Bug";
	rock->strongAgainst[1] = "Fire";
	rock->strongAgainst[2] = "Flying";
	rock->strongAgainst[3] = "Ice";
	rock->weakAgainst[0] = "Fight";
	rock->weakAgainst[1] = "Grass";
	rock->weakAgainst[2] = "Ground";
	rock->weakAgainst[3] = "Steel";
	rock->weakAgainst[4] = "Water";
	insert(rock, hashtable);

	CombatEspece* steel = new CombatEspece;
	steel->nature = "Steel";
	steel->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		steel->strongAgainst[i] = nullptr;
		steel->weakAgainst[i] = nullptr;
	}
	steel->strongAgainst[0] = "Fairy";
	steel->strongAgainst[1] = "Ice";
	steel->strongAgainst[2] = "Rock";
	steel->weakAgainst[0] = "Fight";
	steel->weakAgainst[1] = "Fire";
	steel->weakAgainst[2] = "Ground";
	insert(steel, hashtable);

	CombatEspece* water = new CombatEspece;
	water->nature = "Water";
	water->suivant = nullptr;
	for (i = 0; i < 5; i++)
	{
		water->strongAgainst[i] = nullptr;
		water->weakAgainst[i] = nullptr;
	}
	water->strongAgainst[0] = "Fire";
	water->strongAgainst[1] = "Ground";
	water->strongAgainst[2] = "Rock";
	water->weakAgainst[0] = "Electric";
	water->weakAgainst[1] = "Grass";
	insert(water, hashtable);

	return hashtable;
}

bool est_dans(char* tableau[5], char* val) {
	for (int i = 0; i < 5; i++) {
		if (tableau[i] != NULL && strcmp(tableau[i], val) != 0) {
			return true;
		}
	}
	return false;
}

void combat(CombatHash* hashtable, Pokedex* MonPokedex, EspecePokemon bestiaire[]) {
	// Préparation du combat.
	// Choix des pokemons qui vont se battre.
	int indice_pokemon1 = -1;
	int indice_pokemon2 = -1;
	while (indice_pokemon1 < 0) {
		cout << "Choisir l'identifiant du premier pokemon : ";
		cin >> indice_pokemon1;
		cout << endl;
	}
	while (indice_pokemon2 < 0) {;
		cout << "Choisir l'identifiant du deuxieme pokemon : ";
		cin >> indice_pokemon2;
		cout << endl;
	}
	Pokemon* pokemon1 = &MonPokedex->p[indice_pokemon1];
	Pokemon* pokemon2 = &MonPokedex->p[indice_pokemon2];
	cout << "AFFRONTEMENT : " << pokemon1->nom << " contre " << pokemon2->nom << " ! " << endl;

	//Préparation du combat.
	//Un pokemon a-t-il des avantages ?
	EspecePokemon espece1 = asso_espece_et_nompokemon(bestiaire, pokemon1->nom);
	EspecePokemon espece2 = asso_espece_et_nompokemon(bestiaire, pokemon2->nom);
	char* type1 = pokemonTypeToString(espece1.type);
	char* type2 = pokemonTypeToString(espece2.type);
	CombatEspece* c1 = get(hashtable, type1);
	CombatEspece* c2 = get(hashtable, type2);
	if (c1 == nullptr || c2 == nullptr) {
		cerr << "Erreur : les pokemons a combattre sont introuvables !" << endl;
		return;
	}
	bool pokemon1_fort_devant_pokemon2 = est_dans(c1->strongAgainst, type2);
	bool pokemon2_fort_devant_pokemon1 = est_dans(c2->strongAgainst, type1);
	if (pokemon1_fort_devant_pokemon2) {
		cout << pokemon1->nom << " est fort contre " << pokemon2->nom << "." << endl;
	}
	if (pokemon2_fort_devant_pokemon1) {
		cout << pokemon2->nom << " est fort contre " << pokemon1->nom << "." << endl;
	}

	//Début du combat.
	int n = random_at_most(100) % 2;
	bool attaque1 = n == 0;
	if (attaque1) {
		cout << pokemon1->nom << " commence !" << endl;
	}
	else {
		cout << pokemon2->nom << " commence !" << endl;
	}

	//Déroulement du combat.
	int degats_mini = 30;
	while (pokemon1->pv > 0 && pokemon2->pv > 0) {
		if (attaque1) {
			int degats;
			if (pokemon1_fort_devant_pokemon2) {
				degats = 3 * degats_mini;
			}
			else {
				degats = degats_mini;
			}
			pokemon2->pv = pokemon2->pv - degats;
			//La boucle if/else peut se remplacer en une ligne par : degats = (int)(degats_mini + 2*degats_mini*pokemon1_fort_devant_pokemon2);
			cout << pokemon1->nom << " inflige " << degats << " a " << pokemon2->nom << "." << endl;
		}
		else {
			int degats;
			if (pokemon2_fort_devant_pokemon1) {
				degats = 3 * degats_mini;
			}
			else {
				degats = degats_mini;
			}
			pokemon1->pv = pokemon1->pv - degats;
			//La boucle if/else peut se remplacer en une ligne par : degats = (int)(degats_mini + 2*degats_mini*pokemon2_fort_devant_pokemon1);
			cout << pokemon2->nom << " inflige " << degats << " a " << pokemon1->nom << "." << endl;
		}
		attaque1 = !attaque1; //pour alterner à chaque tour le pokemon qui attaque.
	}

	//Fin du combat.
	if (pokemon1->pv <= 0) {
		cout << endl;
		cout << pokemon2->nom << " gagne !" << endl;
		pokemon1->pv = 0; //dans le cas où ces points de vie sont négatifs.
	}
	else {
		cout << endl;
		cout << pokemon1->nom << " gagne !" << endl;
		pokemon2->pv = 0; //dans le cas où ces points de vie sont négatifs.
	}
}