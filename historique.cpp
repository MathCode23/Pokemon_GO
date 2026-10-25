#include <iostream>
using namespace std;

#include "historique.h"

void inserer_evo(historique* evo_des_pokemons, Evolution* pokemon_evolue) {
	pokemon_evolue->suivant_evo = evo_des_pokemons->debut;
	evo_des_pokemons->debut = pokemon_evolue;
	evo_des_pokemons->nombre = evo_des_pokemons->nombre + 1;
}

void afficher_evo(historique* evo_des_pokemons) {
	Evolution* evo_actuelle = evo_des_pokemons->debut;
	if (evo_actuelle == NULL) {
		cout << "Vous avez fait evoluer aucun pokemon." << endl;
	}
	else {
		cout << "Vous avez fait evoluer " << evo_des_pokemons->nombre << " pokemons." << endl;
		while (evo_actuelle != NULL) {
			cout << evo_actuelle->nom_avant << " a evolue vers " << evo_actuelle->nom_apres << "." << endl;
			evo_actuelle = evo_actuelle->suivant_evo;
		}
	}
}