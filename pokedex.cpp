//Importation bibliothèque
#include <iostream>
using namespace std;
#include <string>

//Importation fichiers d'en-tête
#include "pokemon.h"
#include "pokedex.h"
#include "utils.h"


Pokedex* initPokedex(const int size) {
	Pokedex* Mon_pokedex = new Pokedex;
	Mon_pokedex->nbpokemon = 0; //Le point se transforme tout seul en une flèche, il ne faut pas chercher à comprendre
	Mon_pokedex->maxpokemon = size;
	Mon_pokedex->p = new Pokemon[size];
	return Mon_pokedex;
}

void insertPokemon(Pokedex* MonPokedex, Pokemon p) {
	//Comme lorsque l'on initialise une variable de manière dynamique, on ne sait pas ce qu'il y avait avant dans l'espace mémoire, nous sommes obligés de rester dans le domaine que l'on connait afin d'éviter les erreurs
	//Cas où MonPokedex est vide, on ne connait pas ce qu'il y a dans les cases mémoires que l'ordinateur nous a dit d'utiliser.
	//L'ordinateur nous donne des cases dont il ne sert pas, mais ces cases mémoires ne sont pas obligatoires propres.
	if (MonPokedex->nbpokemon == 0) {
		MonPokedex->p[0] = p;
		MonPokedex->nbpokemon = MonPokedex->nbpokemon + 1;
	}
	else {
		int k = 0;
		//k est l'indice où le pokemon p doit etre inserer dans MonPokedex pour que les Pokemons soient rangés par ordre alphabétique
		//On suppose que le Pokedex est déjà rangé par ordre alphabétique
		for (int i = 0; i < MonPokedex->nbpokemon;i++) {
			if (strcmp(p.nom, MonPokedex->p[k].nom) > 0) {
				//Dans le cas où le nom du Pokemon p se place après le nom du kème Pokemon
				k++;
			}
		}
		//On connait désormais à quelle place se situe le nom du pokemon p dans l'ordre alphabétique
		if (MonPokedex->nbpokemon == MonPokedex->maxpokemon) {
			//Il faut augmenter la taille du Pokedex de 50 %
			MonPokedex->maxpokemon = MonPokedex->maxpokemon + MonPokedex->maxpokemon / 2;
			Pokemon* nouveau_tableauPokemon = new Pokemon[MonPokedex->maxpokemon];
			for (int i = 0; i < k; i++) {
				nouveau_tableauPokemon[i] = MonPokedex->p[i];
			}
			//La boucle for copie les Pokemons qui se place avant le pokemon dans l'ordre alphabétique dans le nouveau tableau de Pokemon
			nouveau_tableauPokemon[k] = p; //On insère le nouveau Pokemon
			for (int i = k; i < MonPokedex->nbpokemon; i++) {
				nouveau_tableauPokemon[i + 1] = MonPokedex->p[i];
			}
			delete[] MonPokedex->p;
			MonPokedex->p = nouveau_tableauPokemon;
			MonPokedex->nbpokemon = MonPokedex->nbpokemon + 1;
		}
		else {
			// Il est nécessaire de se demander si le pokemon p que l'on va insérer se place en dernier dans l'ordre alphabétique.
			// Si c'est le cas, il n'y a pas besoin 
			if (k == MonPokedex->nbpokemon) {
				MonPokedex->p[k] = p;
			}
			else {
				Pokemon inter1 = MonPokedex->p[k];
				MonPokedex->p[k] = p;
				for (int i = k + 1; i < MonPokedex->nbpokemon + 1; i++) {
					Pokemon inter2 = MonPokedex->p[i];
					MonPokedex->p[i] = inter1;
					inter1 = inter2;
				}
			}
			MonPokedex->nbpokemon = MonPokedex->nbpokemon + 1;
		}
	}
}

void affichagePokedex(Pokedex* MonPokedex, EspecePokemon bestiaire[150], char* typesLabel[18],Ressource reserve) {
	cout << endl << "Contenu du Pokedex (Actuellement ";
	cout << MonPokedex->nbpokemon << " pokemons captures)" << endl;
	for (int i = 0; i < MonPokedex->nbpokemon; i++) {
		cout << endl;
		cout << "Pokemon " << i << "." << endl;
		display(MonPokedex->p[i], bestiaire, typesLabel);
	}
	cout << "On possede " << reserve.nb_bonbons << " bonbon(s) et " << reserve.poussieres << " poussiere(s) d'etoiles." << endl;
}

Pokemon genererPokemon(EspecePokemon bestiaire[150], char* typesLabel[18]) {
	//Tirage aléatoire d'un pokemon non évolué dans le bestiaire.
	int nb_aleatoire = random_at_most(149);
	while (bestiaire[nb_aleatoire].estEvolue != 0) {
		nb_aleatoire = random_at_most(149);
	}
	//Initialisation et déclaration du pokemon généré.
	Pokemon p;
	p.nom = bestiaire[nb_aleatoire].nom;
	p.evo = 1;
	p.xp = 0;
	int cp = random_at_most(1000);
	while (cp < 200) {
		cp = random_at_most(1000);
	}
	p.cp = cp;
	int pv = random_at_most(500);
	while (pv < 30) {
		pv = random_at_most(500);
	}
	p.pv = pv;
	return p;
}

void attraperPokemon(Pokemon Pokemon_sauvage,Pokedex* MonPokedex, Ressource& reserve, double proba_de_capture,EspecePokemon bestiaire[150],char* typesLabel[18]) {
	//On affiche les caractéristiques du Pokemon sauvage, et on demande à l'utilisateur ce qu'il souhaite faire.
	display(Pokemon_sauvage, bestiaire, typesLabel);
	cout << "1. Lancer une pokeball pour tenter de le capturer." << endl;
	cout << "2. Partir. Finalement, " << Pokemon_sauvage.nom << " ne m'interesse pas." << endl;
	int nb = 0;
	while (nb != 1 && nb != 2) {
		cout << "Choisissez : ";
		cin >> nb;
		cout << endl;
	}
	cout << endl;

	//On réalise ce que l'utilisateur souhaite faire.
	switch (nb) {
		case 1: {
			cout << "Vous avez choisi de lancer une pokeball sur " << Pokemon_sauvage.nom << " afin de le capturer." << endl;
			int n = random_at_most(100);
			if (n <= proba_de_capture * 100) {
				//Si on capture le pokemon sauvage.
				cout << " ---------- " << Pokemon_sauvage.nom << " a ete capture avec succes !" << " ---------- " << endl;
				cout << "Vous gagnez ainsi 3 bonbons et 100 poussieres d'etoiles." << endl;
				insertPokemon(MonPokedex, Pokemon_sauvage);
				reserve.nb_bonbons = reserve.nb_bonbons + 3;
				reserve.poussieres = reserve.poussieres + 100;
			}
			else {
				//Si on ne peut pas capturer le pokemon sauvage.
				cout << "----------" << Pokemon_sauvage.nom << " n'a pas ete capture !" << "----------" << endl;
				cout << Pokemon_sauvage.nom << " est plus malin que ce que vous pensiez. Il n'est pas tombe dans votre piege." << endl;
				cout << "En effet, il est toujours libre !" << endl;
				double proba_de_s_enfuir = 0.25;
				n = random_at_most(100);
				if (n <= proba_de_s_enfuir * 100) {
					//Si le pokemon sauvage parvient à s'enfuir après qu'on ait essayé de l'attraper.
					cout << Pokemon_sauvage.nom << " s'enfuit rapidement. Il n'est plus possible de tenter de le capturer, il est parti tres loin." << endl;
				}
				else {
					cout << Pokemon_sauvage.nom << " est toujours ici !" << endl;
					attraperPokemon(Pokemon_sauvage, MonPokedex, reserve, proba_de_capture, bestiaire, typesLabel);
				}
			}
			break;
		}
		case 2: {
			cout << "Vous avez choisi de vous en aller." << endl;
			break;
		}
		default: {
			break;
		}
	}
}