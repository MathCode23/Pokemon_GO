#include <iostream>
#include <stdlib.h>
using namespace std;

#include "pokemon.h"
#include "pokemonTypes.h"
#include "bestiaire.h"
#include "pokedex.h"
#include "sauvegarde.h"
#include "historique.h"
#include "combat.h"


void Pokemon_a_progresser(Pokedex* MonPokedex, Ressource& reserve);
//Fonction qui permet de faire progresser un pokemon du pokedex.

void Pokemon_a_progresser(Pokedex* MonPokedex, Ressource& reserve) {
	//Affichage de ce que l'utilisateur peut faire dorénavant.
	cout << "4.1.1. Choisir un pokemon afin de le faire progresser (power-up)." << endl;
	cout << "4.1.2. Retour." << endl;

	int nb4a = 0;
	while (nb4a != 2) {
		nb4a = 0;
		while (nb4a != 1 && nb4a != 2) {
			char nb4a_utilisateur;
			cout << "Choisissez : ";
			cin >> nb4a_utilisateur;
			cout << endl;
			nb4a = nb4a_utilisateur - '0';
		}
		switch (nb4a) {
			case 1: {
				cout << "----------------------------------------------------------------------------" << endl;
				cout << "4.1.1. Choisissez le pokemon que vous souhaitez faire progresser (power-up)." << endl;
				cout << "----------------------------------------------------------------------------" << endl;
				cout << endl;

				//Affichage des pokemons que l'on possède pouvant progresser et de la possibilité de revenir en arrière.
				for (int i = 0; i < MonPokedex->nbpokemon; i++) {
					cout << i + 1 << ". " << MonPokedex->p[i].nom << "." << endl;
				}
				cout << MonPokedex->nbpokemon + 1 << ". Retour." << endl;

				//Choix du pokemon à faire progresser.
				int pokemon_choisi = 0;
				while ((pokemon_choisi > MonPokedex->nbpokemon + 1) || (pokemon_choisi < 1)) {
					char pokemon_choisi_utilisateur;
					cout << "Choisissez un pokemon : ";
					cin >> pokemon_choisi_utilisateur;
					cout << endl;
					pokemon_choisi = pokemon_choisi_utilisateur - '0';
				}

				if (pokemon_choisi == MonPokedex->nbpokemon + 1) {
					//Affichage du menu faire progresser pour savoir ce que l'utilisateur souhaite faire désormais.
					cout << endl;
					cout << "----------------------------" << endl;
					cout << "4.1. Power-up (progression)." << endl;
					cout << "----------------------------" << endl;
					cout << endl;
					cout << "4.1.1. Choisir un pokemon afin de le faire progresser (power-up)." << endl;
					cout << "4.1.2. Retour." << endl;
				}
				else {
					if (reserve.nb_bonbons >= 10 && reserve.poussieres >= 500) {
						//Si on possède assez de ressources pour pouvoir faire progresser un pokemon.
						powerup(MonPokedex->p[pokemon_choisi - 1]);
						reserve.nb_bonbons = reserve.nb_bonbons - 10;
						reserve.poussieres = reserve.poussieres - 500;
					
						//Affichage de ce que l'utilisateur peut faire dorénavant.
						cout << endl;
						cout << "----------------------------" << endl;
						cout << "4.1. Power-up (progression)." << endl;
						cout << "----------------------------" << endl;
						cout << endl;
						cout << "4.1.1. Choisir un pokemon afin de le faire progresser (power-up)." << endl;
						cout << "4.1.2. Retour." << endl;
					}
					else {
						cout << "Vous ne disposez pas de 10 bonbons et de 500 poussieres d'etoiles pour faire progresser " << MonPokedex->p[pokemon_choisi - 1].nom << "." << endl;
						cout << "Attraper plus de pokemons !" << endl;

						cout << endl;
						cout << "4.1.1. Choisir un pokemon afin de le faire progresser (power-up)." << endl;
						cout << "4.1.2. Retour." << endl;
					}
				}
				break;
			}
			case 2: {
				cout << "--------------" << endl;
				cout << "4.1.2. Retour." << endl;
				cout << "--------------" << endl;

				cout << endl;
				cout << "-------------------------" << endl;
				cout << "4. Power-up et evolution." << endl;
				cout << "-------------------------" << endl;
				cout << endl;
				cout << "4.1. Power-up (progression)." << endl;
				cout << "4.2. Evolution." << endl;
				cout << "4.3. Retour au menu principal." << endl;
				cout << endl;

				break;
			}
			default: {
				break;
			}
		}
	}
}


void Pokemon_a_evoluer(Pokedex* MonPokedex, EspecePokemon bestiaire[], Ressource& reserve,historique* evo_des_pokemons);

void Pokemon_a_evoluer(Pokedex* MonPokedex, EspecePokemon bestiaire[], Ressource& reserve,historique* evo_des_pokemons) {
	//Affichage de ce que l'utilisateur peut faire dorénavant.
	cout << "4.2.1. Choisir un pokemon afin de le faire evoluer." << endl;
	cout << "4.2.2. Historique des evolutions." << endl;
	cout << "4.2.3. Retour." << endl;

	int nb4b = 0;
	while (nb4b != 3) {
		nb4b = 0;
		while (nb4b != 1 && nb4b != 2 && nb4b != 3) {
			char nb4b_utilisateur;
			cout << "Choisissez : ";
			cin >> nb4b_utilisateur;
			cout << endl;
			nb4b = nb4b_utilisateur - '0';
		}
		switch (nb4b) {
			case 1: {
				cout << "--------------------------------------------------------------" << endl;
				cout << "4.2.1. Choisissez le pokemon que vous souhaitez faire evoluer." << endl;
				cout << "--------------------------------------------------------------" << endl;
				cout << endl;

				//Affichage des pokemons que l'on possède pouvant progresser et de la possibilité de revenir en arrière.
				for (int i = 0; i < MonPokedex->nbpokemon; i++) {
					EspecePokemon espece_pokemon_i = asso_espece_et_nompokemon(bestiaire, MonPokedex->p[i].nom);
					if (espece_pokemon_i.evolvesTo != nullptr) {
						cout << i + 1 << ". " << MonPokedex->p[i].nom << "." << endl;
					}
				}
				cout << MonPokedex->nbpokemon + 1 << ". Retour." << endl;

				//Choix du pokemon à faire progresser.
				int pokemon_choisi = 0;
				while ((pokemon_choisi > MonPokedex->nbpokemon + 1) || (pokemon_choisi < 1)) {
					char pokemon_choisi_utilisateur;
					cout << "Choisissez le pokemon que vous souhaitez faire evoluer (uniquement ceux-la, ne vous trompez pas !!!) : ";
					cin >> pokemon_choisi_utilisateur;
					cout << endl;
					pokemon_choisi = pokemon_choisi_utilisateur - '0';
				}

				if (pokemon_choisi == MonPokedex->nbpokemon + 1) {
					//Affichage du menu faire evoluer pour savoir ce que l'utilisateur souhaite faire désormais.
					cout << endl;
					cout << "---------------" << endl;
					cout << "4.2. Evolution." << endl;
					cout << "---------------" << endl;
					cout << endl;
					cout << "4.2.1. Choisir un pokemon afin de le faire evoluer." << endl;
					cout << "4.2.2. Historique des evolutions." << endl;
					cout << "4.2.3. Retour." << endl;
				}
				else {
					EspecePokemon espece_pokemon_choisi = asso_espece_et_nompokemon(bestiaire, MonPokedex->p[pokemon_choisi - 1].nom);
					if (reserve.nb_bonbons >= espece_pokemon_choisi.nbBonbonsPourEvoluer) {
						evolve(MonPokedex->p[pokemon_choisi - 1],bestiaire,evo_des_pokemons);
						reserve.nb_bonbons = reserve.nb_bonbons - espece_pokemon_choisi.nbBonbonsPourEvoluer;

						//Affichage de ce que l'utilisateur peut faire dorénavant.
						cout << endl;
						cout << "---------------" << endl;
						cout << "4.2. Evolution." << endl;
						cout << "---------------" << endl;
						cout << endl;
						cout << "4.2.1. Choisir un pokemon afin de le faire evoluer." << endl;
						cout << "4.2.2. Historique des evolutions." << endl;
						cout << "4.2.3. Retour." << endl;
					}
					else {
						cout << "Vous ne disposez pas assez de bonbons pour faire evoluer " << MonPokedex->p[pokemon_choisi - 1].nom << "." << endl;
						cout << "Attraper plus de pokemons !" << endl;

						cout << endl;
						cout << "4.2.1. Choisir un pokemon afin de le faire evoluer." << endl;
						cout << "4.2.2. Historique des evolutions." << endl;
						cout << "4.2.3. Retour." << endl;
					}
				}
				break;
			}
			case 2: {
				cout << "---------------------------------" << endl;
				cout << "4.2.2. Historique des evolutions." << endl;
				cout << "---------------------------------" << endl;
				cout << endl;

				//Affichage de l'historique des évolutions.
				afficher_evo(evo_des_pokemons);

				cout << endl;
				cout << "4.2.1. Choisir un pokemon afin de le faire evoluer." << endl;
				cout << "4.2.2. Historique des evolutions." << endl;
				cout << "4.2.3. Retour." << endl;

				break;
			}
			case 3: {
				cout << "--------------" << endl;
				cout << "4.2.3. Retour." << endl;
				cout << "--------------" << endl;

				cout << endl;
				cout << "-------------------------" << endl;
				cout << "4. Power-up et evolution." << endl;
				cout << "-------------------------" << endl;
				cout << endl;
				cout << "4.1. Power-up (progression)." << endl;
				cout << "4.2. Evolution." << endl;
				cout << "4.3. Retour au menu principal." << endl;
				cout << endl;

				break;
			}
			default: {
				break;
			}
		}
	}
}

int main() {
	// Initialisation des variables globales qui vont servir pendant toute la durée du jeu.
	srand(time(NULL)); //A rajouter obligatoirement pour pouvoir générer des nombres, ça s'appelle la seed ! Elle dépend de l'heure.
	
	char* typesLabel[18]{ "Normal", "Fighting", "Flying", "Poison", "Ground", "Rock", "Bug", "Ghost", "Steel", "Fire", "Grass", "Water", "Electric", "Psychic", "Ice", "Dragon", "Dark", "Fairy" };
	EspecePokemon bestiaire[150];
	initBestiaire(bestiaire);
	
	Ressource reserve;
	reserve.nb_bonbons = 0;
	reserve.poussieres = 0;
	
	double proba_capture_pokemon = 0.4;
	
	Pokedex* pokedex = initPokedex(3);

	historique* evo_des_pokemons = new historique;
	evo_des_pokemons->nombre = 0;
	evo_des_pokemons->debut = NULL;

	CombatHash* hashtable = initCombatHash();

	menu();
	// Permet à l'utilisateur de choisir ce qu'il souhaite faire.
	int nb = 0;
	while (nb != 7) {
		nb = 0; // Pour éviter une boucle infinie.
		while (nb <= 0 || nb >= 8) {
			char nb_utilisateur;
			cout << "Choisissez : ";
			cin >> nb_utilisateur;
			cout << endl;
			nb = nb_utilisateur - '0';
		}
		switch (nb) {
			case 1: {
				//Afichage de ce que l'utilisateur a choisi et de ce qu'il peut choisir désormais.
				cout << endl;
				cout << "--------------------------------" << endl;
				cout << "1. Index des pokemons :" << endl;
				cout << "--------------------------------" << endl;
				cout << endl;
				cout << "1.1. Bestiaire a l'etat sauvage." << endl;
				cout << "1.2. Bestiaire trie par ordre alphabetique." << endl;
				cout << "1.3. Retour au menu principal." << endl;
				cout << endl;

				//Permet à l'utilisateur de choisir ce qu'il souhaite faire dorénavant
				int nb1 = 0;
				while (nb1 != 3) {
					nb1 = 0;
					while (nb1 != 1 && nb1 != 2 && nb1 != 3) {
						char nb1_utilisateur;
						cout << "Choisissez : ";
						cin >> nb1_utilisateur;
						cout << endl;
						nb1 = nb1_utilisateur - '0';
					}
					switch (nb1) {
						case 1: {
							//Affichage de ce que l'utilisateur a choisi.
							cout << endl;
							cout << "--------------------------------" << endl;
							cout << "1.1. Bestiaire a l'etat sauvage." << endl;
							cout << "--------------------------------" << endl;
							cout << endl;
							affichageBestiaire(bestiaire,typesLabel);
							
							//Affichage du menu 1 pour savoir ce que l'utilisateur veut faire désormais.
							cout << endl;
							cout << "-----------------------" << endl;
							cout << "1. Index des pokemons :" << endl;
							cout << "-----------------------" << endl;
							cout << endl;
							cout << "1.1. Bestiaire a l'etat sauvage." << endl;
							cout << "1.2. Bestiaire trie par ordre alphabetique." << endl;
							cout << "1.3. Retour au menu principal." << endl;
							cout << endl;
							break;
						}
						case 2: {
							//Affichage de ce que l'utilisateur a choisi.
							cout << endl;
							cout << "-------------------------------------------" << endl;
							cout << "1.2. Bestiaire trie par ordre alphabetique." << endl;
							cout << "-------------------------------------------" << endl;
							cout << endl;
							affichageBestiairetrie(bestiaire,typesLabel);

							//Affichage du menu 1 pour savoir ce que l'utilisateur veut faire désormais.
							cout << endl;
							cout << "-----------------------" << endl;
							cout << "1. Index des pokemons :" << endl;
							cout << "-----------------------" << endl;
							cout << endl;
							cout << "1.1. Bestiaire a l'etat sauvage." << endl;
							cout << "1.2. Bestiaire trie par ordre alphabetique." << endl;
							cout << "1.3. Retour au menu principal." << endl;
							cout << endl;
							break;
						}
						case 3: {
							//Affichage de ce que l'utilsateur a choisi.
							cout << endl;
							cout << "------------------------------" << endl;
							cout << "1.3. Retour au menu principal." << endl;
							cout << "------------------------------" << endl;
							cout << endl;
							menu();
							break;
						}
						default: {
							break;
						}
					}
				}
				break;
			}
			case 2: {
				//Afichage de ce que l'utilisateur a choisi et de ce qu'il peut choisir désormais.
				cout << endl;
				cout << "---------------" << endl;
				cout << "2. Mon Pokedex." << endl;
				cout << "---------------" << endl;
				cout << endl;
				cout << "2.1. Afficher mon pokedex." << endl;
				cout << "2.2. Retour au menu principal." << endl;
				cout << endl;

				//Permet à l'utilisateur de choisir ce qu'il souhaite faire dorénavant
				int nb2 = 0;
				while (nb2 != 2) {
					nb2 = 0;
					while (nb2 != 1 && nb2 != 2) {
						char nb2_utilisateur;
						cout << "Choisissez : ";
						cin >> nb2_utilisateur;
						cout << endl;
						nb2 = nb2_utilisateur - '0';
					}
					switch (nb2) {
						case 1: {
							//Affichage de ce que l'utilisateur a choisi.
							cout << "-------------------------" << endl;
							cout << "2.1.Afficher mon pokedex." << endl;
							cout << "-------------------------" << endl;
							cout << endl;
							affichagePokedex(pokedex, bestiaire, typesLabel, reserve);

							//Affichage du menu 2 pour savoir ce que l'utilisateur souhaite faire désormais.
							cout << endl;
							cout << "---------------" << endl;
							cout << "2. Mon Pokedex." << endl;
							cout << "---------------" << endl;
							cout << endl;
							cout << "2.1. Afficher mon pokedex." << endl;
							cout << "2.2. Retour au menu principal." << endl;
							cout << endl;
							break;
						}
						case 2: {
							//Affichage de ce que l'utilsateur a choisi.
							cout << endl;
							cout << "------------------------------" << endl;
							cout << "2.2. Retour au menu principal." << endl;
							cout << "------------------------------" << endl;
							cout << endl;
							menu();
							break;
						}
						default: {
							break;
						}
					}
				}
				break;
			}
			case 3: {
				//Afichage de ce que l'utilisateur a choisi et de ce qu'il peut choisir désormais.
				cout << endl;
				cout << "-----------------------" << endl;
				cout << "3. Attraper un pokemon." << endl;
				cout << "-----------------------" << endl;
				cout << endl;
				cout << "3.1. Rencontrer un pokemon." << endl;
				cout << "3.2. Retour au menu principal." << endl;
				cout << endl;
				//Permet à l'utilisateur de choisir ce qu'il souhaite faire dorénavant
				int nb3 = 0;
				while (nb3 != 2) {
					nb3 = 0;
					while (nb3 != 1 && nb3 != 2) {
						char nb3_utilisateur;
						cout << "Choisissez : ";
						cin >> nb3_utilisateur;
						cout << endl;
						nb3 = nb3_utilisateur - '0';
					}
					switch (nb3) {
						case 1: {
							//Affichage de ce que l'utilisateur a choisi.
							cout << "---------------------------" << endl;
							cout << "3.1. Rencontrer un pokemon." << endl;
							cout << "---------------------------" << endl;
							cout << endl;
							Pokemon pokemon_sauvage = genererPokemon(bestiaire, typesLabel);
							attraperPokemon(pokemon_sauvage, pokedex, reserve, proba_capture_pokemon, bestiaire, typesLabel);

							//Affichage du menu 3 pour savoir ce que l'utilisateur souhaite faire désormais.
							cout << endl;
							cout << "-----------------------" << endl;
							cout << "3. Attraper un pokemon." << endl;
							cout << "-----------------------" << endl;
							cout << endl;
							cout << "3.1. Rencontrer un pokemon." << endl;
							cout << "3.2. Retour au menu principal." << endl;
							cout << endl;
							break;
						}
						case 2: {
							//Affichage de ce que l'utilsateur a choisi.
							cout << endl;
							cout << "------------------------------" << endl;
							cout << "3.2. Retour au menu principal." << endl;
							cout << "------------------------------" << endl;
							cout << endl;
							menu();
							break;
						}
						default: {
							break;
						}
					}
				}
				break;
			}
			case 4: {
				//Afichage de ce que l'utilisateur a choisi et de ce qu'il peut choisir désormais.
				cout << endl;
				cout << "-------------------------" << endl;
				cout << "4. Power-up et evolution." << endl;
				cout << "-------------------------" << endl;
				cout << endl;
				cout << "4.1. Power-up (progression)." << endl;
				cout << "4.2. Evolution." << endl;
				cout << "4.3. Retour au menu principal." << endl;
				cout << endl;

				//Permet à l'utilisateur de choisir ce qu'il souhaite faire dorénavant
				int nb4 = 0;
				while (nb4 != 3) {
					nb4 = 0;
					while (nb4 != 1 && nb4 != 2 && nb4 != 3) {
						char nb4_utilisateur;
						cout << "Choisissez : ";
						cin >> nb4_utilisateur;
						cout << endl;
						nb4 = nb4_utilisateur - '0';
					}
					switch (nb4) {
						case 1: {
							//Affichage de ce que l'utilisateur a choisi.
							cout << "----------------------------" << endl;
							cout << "4.1. Power-up (progression)." << endl;
							cout << "----------------------------" << endl;
							cout << endl;

							//On réalise ce que l'utilisateur a demandé.
							Pokemon_a_progresser(pokedex, reserve);

							break;
						}
						case 2: {
							//Affichage de ce que l'utilisateur a choisi.
							cout << "--------------" << endl;
							cout << "4.2.Evolution." << endl;
							cout << "--------------" << endl;
							cout << endl;

							//On réalise ce que l'utilisateur a demandé.
							Pokemon_a_evoluer(pokedex, bestiaire, reserve,evo_des_pokemons);
							
							break;
						}
						case 3: {
							//Affichage de ce que l'utilsateur a choisi.
							cout << endl;
							cout << "------------------------------" << endl;
							cout << "4.3. Retour au menu principal." << endl;
							cout << "------------------------------" << endl;
							cout << endl;
							menu();
							break;
						}
						default: {
							break;
						}
					}
				}
				break;
			}
			case 5: {
				cout << endl;
				cout << "----------" << endl;
				cout << "5. Combat." << endl;
				cout << "----------" << endl;
				cout << endl;
				cout << "5.1. Commencer un combat." << endl;
				cout << "5.2. Retour au menu principal." << endl;
				cout << endl;

				//Permet à l'utilisateur de choisir ce qu'il souhaite faire.
				int nb5 = 0;
				while (nb5 != 2) {
					nb5 = 0;
					while (nb5 != 1 && nb5 != 2) {
						char nb5_utilisateur;
						cout << "Choisissez : ";
						cin >> nb5_utilisateur;
						cout << endl;
						nb5 = nb5_utilisateur - '0';
					}
					switch (nb5) {
						case 1: {
							//Affichage de ce que l'utilisateur a choisi.
							cout << "-------------------------" << endl;
							cout << "5.1. Commencer un combat." << endl;
							cout << "-------------------------" << endl;

							affichagePokedex(pokedex, bestiaire, typesLabel, reserve);
							combat(hashtable, pokedex, bestiaire);

							//Affichage du menu 5.
							cout << endl;
							cout << "----------" << endl;
							cout << "5. Combat." << endl;
							cout << "----------" << endl;
							cout << endl;
							cout << "5.1. Commencer un combat." << endl;
							cout << "5.2. Retour au menu principal." << endl;
							cout << endl;
							break;
						}
						case 2: {
							//Affichage de ce que l'utilisateur a choisi.
							cout << "------------------------------" << endl;
							cout << "5.2. Retour au menu principal." << endl;
							cout << "------------------------------" << endl;
							cout << endl;
							menu();
							break;
						}
						default: {
							break;
						}
					}
				}
				break;
			}
			case 6: {
				cout << endl;
				cout << "-----------------------------------------" << endl;
				cout << "6. Sauvegarde et restauration de donnees." << endl;
				cout << "-----------------------------------------" << endl;
				cout << endl;
				cout << "6.1. Charger une partie." << endl;
				cout << "6.2. Sauvegarder une partie." << endl;
				cout << "6.3. Retour au menu principal." << endl;
				cout << endl;

				//Permet à l'utilisateur de choisir ce qu'il souhaite faire.
				int nb6 = 0;
				while (nb6 != 3) {
					nb6 = 0;
					while (nb6 != 1 && nb6 != 2 && nb6 != 3) {
						char nb6_utilisateur;
						cout << "Choisissez : ";
						cin >> nb6_utilisateur;
						cout << endl;
						nb6 = nb6_utilisateur - '0';
					}
					switch (nb6) {
						case 1: {
							//Affichage de ce que l'utilisateur a choisi.
							cout << "------------------------" << endl;
							cout << "6.1. Charger une partie." << endl;
							cout << "------------------------" << endl;
							cout << endl;

							chargementpartie(pokedex, reserve);

							//Affichage du menu 6.
							cout << endl;
							cout << "-----------------------------------------" << endl;
							cout << "6. Sauvegarde et restauration de donnees." << endl;
							cout << "-----------------------------------------" << endl;
							cout << endl;
							cout << "6.1. Charger une partie." << endl;
							cout << "6.2. Sauvegarder une partie." << endl;
							cout << "6.3. Retour au menu principal." << endl;
							cout << endl;
							break;
						}
						case 2: {
							//Affichage de ce que l'utilisateur a choisi.
							cout << "----------------------------" << endl;
							cout << "6.2. Sauvegarder une partie." << endl;
							cout << "----------------------------" << endl;
							cout << endl;

							//Sauvegarde des donnees.
							creationfichiersauvegarde(pokedex,reserve);

							//Affichage du menu 6.
							cout << endl;
							cout << "-----------------------------------------" << endl;
							cout << "6. Sauvegarde et restauration de donnees." << endl;
							cout << "-----------------------------------------" << endl;
							cout << endl;
							cout << "6.1. Charger une partie." << endl;
							cout << "6.2. Sauvegarder une partie." << endl;
							cout << "6.3. Retour au menu principal." << endl;
							cout << endl;
							break;
						}
						case 3: {
							//Affichage de ce que l'utilisateur a choisi.
							cout << "------------------------------" << endl;
							cout << "6.3. Retour au menu principal." << endl;
							cout << "------------------------------" << endl;
							cout << endl;
							menu();
							break;
						}
						default: {
							break;
						}
					}
				}
				break;
			}
			case 7: {
				system("cls");
				cout << " " << endl;
				cout << "********** Au revoir ! Nous les recupererons tous plus tard ! **********" << endl;
				cout << " " << endl;
				break;
			}
			default: {
				break;
			}
		}
	}

	//Désaffectation de la mémoire allouée.
	delete pokedex;

	Evolution* evo_actuelle = evo_des_pokemons->debut;
	while (evo_actuelle != NULL) {
			Evolution* a_suppr = evo_actuelle;
			evo_actuelle = evo_actuelle->suivant_evo;
			delete a_suppr;
	}
	delete evo_des_pokemons;
	return 0;
}