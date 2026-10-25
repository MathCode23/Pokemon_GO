#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Le module string pour getline

#include "sauvegarde.h"

#pragma warning(suppress : 4996) //Pour éviter que la ligne74 bogue.
//Desactivation dans Propriétés de configuration>C/C++>Avancé>Désactiver les avertissements spécifiques pour ajouter 4996.
//Normalement, il n'y a aucune désactivation à cet endroit précis.

void creationfichiersauvegarde(Pokedex* MonPokedex, Ressource reserve) {
	//Ouverture du flux de sortie.
	ofstream myfile;

	//Creation du ficher ainsi que son ouverture.
	cout << "Creation de votre fichier de sauvegarde." << endl;
	myfile.open("sauvegarde_partie.txt");

	//Ecriture de la première ligne : nombre de pokemons capturés.
	myfile << MonPokedex->nbpokemon << endl;
	myfile << reserve.nb_bonbons << endl;
	myfile << reserve.poussieres << endl;

	//Ecriture des informations pour chaque pokemon ligne par ligne.
	for (int i = 0; i < MonPokedex->nbpokemon; i++) {
		myfile << MonPokedex->p[i].nom << endl;
		myfile << MonPokedex->p[i].xp << endl;
		myfile << MonPokedex->p[i].evo << endl;
		myfile << MonPokedex->p[i].pv << endl;
		myfile << MonPokedex->p[i].cp << endl;
	}

	//Fermeture du fichier.
	myfile.close();

	cout << "** Votre partie a bien ete enregistree. **" << endl;
}

void chargementpartie(Pokedex* MonPokedex, Ressource& reserve) {
	//ON SUPPOSE QUE MonPokedex NE CONTIENT AUCUN POKEMON : L'UTILISATEUR VIENT JUSTE D'OUVRIR LE JEU !!!!!

	//Ouverture du fichier de sauvegarde en lecture seule.
	ifstream file("sauvegarde_partie.txt");

	if (file.is_open()) {
		//Si le fichier a été ouvert alors il existe.

		//Lecture 1ere ligne : Nombre de pokemons captures.
		string ligne1;
		getline(file, ligne1); //Ce qui est lu est stocké dans la variable string ligne1.
		int nb_captures = stoi(ligne1); //Convertion de string à int via la fonction stoi du module string.
		//Prise en compte de la lecture de la première ligne.

		//Lecture 2eme ligne : Nombre de bonbons
		getline(file, ligne1); //Puisqu'on a lu la première ligne, getline va directement à la deuxième ligne, puis etc...
		int nb = stoi(ligne1);
		reserve.nb_bonbons = nb;

		//Lecture 3eme ligne : Nombre de poussières d'étoiles
		getline(file, ligne1);
		nb = stoi(ligne1);
		reserve.poussieres = nb;

		//Lecture pokemon par pokemon via une boucle while.
		for (int i = 0; i < nb_captures; i++) {
			Pokemon pokemon_lu; //Initialisation du pokemon que l'on va lire puis insérer dans le pokedex.

			getline(file, ligne1); //Lecture du nom.
			const char* nom_lu = ligne1.c_str(); //Conversion d'un string en const char avec .data() ou avec .c_str()
			char* nom_lu_modifiable = new char[strlen(nom_lu) + 1]; //strlen renvoie la longueur d'un tableau sans compter le caractère nul (d'où le +1).
			strcpy(nom_lu_modifiable, nom_lu); //On copie nom_lu dans nom_lu_modifiable afin de convertir un const char* en char*
			pokemon_lu.nom = nom_lu_modifiable;
			
			getline(file, ligne1); //Lecture de xp
			nb = stoi(ligne1);
			pokemon_lu.xp = nb;

			getline(file, ligne1); //Lecture de evo
			nb = stoi(ligne1);
			pokemon_lu.evo = nb;

			getline(file, ligne1); //Lecture de pv
			nb = stoi(ligne1);
			pokemon_lu.pv = nb;

			getline(file, ligne1); //Lecture de cp
			nb = stoi(ligne1);
			pokemon_lu.cp = nb;

			insertPokemon(MonPokedex, pokemon_lu); //Insersion du pokemon lu dans le pokedex.
		}

		file.close();

		cout << "La partie est chargee." << endl;
	}
	else {
		//Si le fichier n'a pas pu être ouvert alors il n'existe pas.
		cout << "Il n'existe aucun fichier de sauvegarde. Votre partie ne peut etre chargee." << endl;
	}
}