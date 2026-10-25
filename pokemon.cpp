#include <iostream>
using namespace std;

#include "pokemon.h"
#include "pokemonTypes.h"
#include "bestiaire.h"
#include "historique.h"

// Fonction menu, affichage du menu.
void menu() {
	cout << "------------------------------------------------------------------------" << endl;
	cout << "                                   .::.                            " << endl;
	cout << "                                 .;:**'                            " << endl;
	cout << "                                 `                                 " << endl;
	cout << "     .:XHHHHk.              db.   .;;.     dH  MX                  " << endl;
	cout << "   oMMMMMMMMMMM       ~MM  dMMP :MMMMMR   MMM  MR      ~MRMN       " << endl;
	cout << "   QMMMMMb  \"MMX       MMMMMMP !MX' :M~   MMM MMM  .oo. XMMM 'MMM  " << endl;
	cout << "     `MMMM.  )M> :X!Hk. MMMM   XMM.o\"  .  MMMMMMM X?XMMM MMM>!MMP  " << endl;
	cout << "      'MMMb.dM! XM M'?M MMMMMX.`MMMMMMMM~ MM MMM XM `\" MX MMXXMM   " << endl;
	cout << "       ~MMMMM~ XMM. .XM XM`\"MMMb.~*?**~ .MMX M t MMbooMM XMMMMMP   " << endl;
	cout << "        ?MMM>  YMMMMMM! MM   `?MMRb.    `\"\"\"   !L\"MMMMM XM IMMM    " << endl;
	cout << "         MMMX   \"MMMM\"  MM       ~%:           !Mh.\"\"\" dMI IMMP    " << endl;
	cout << "         'MMM.                                             IMX     " << endl;
	cout << "          ~M!M                                             IMP     " << endl << endl;
	cout << "                            - TSE EDITION -                        " << endl;
	cout << "*** Auteur : Mathieu JULLIEN ***" << endl;
	cout << "------------------------------------------------------------------------" << endl;

	cout << endl;
	cout << endl;

	cout << "Menu." << endl;
	cout << endl;
	cout << "1. Index des pokemons." << endl;
	cout << "2. Mon Pokedex." << endl;
	cout << "3. Attraper un pokemon." << endl;
	cout << "4. Power-up et evolution." << endl;
	cout << "5. Combat." << endl;
	cout << "6. Sauvegarde et restauration de donnees." << endl;
	cout << "7. Quitter." << endl;
	cout << endl;
}

// Fonction evolve.
void evolve(Pokemon& p,EspecePokemon bestiaire[],historique* evo_des_pokemons) {
	//Evolution de l'espece
	char* ancien_nom = p.nom;
	EspecePokemon espece_de_p = asso_espece_et_nompokemon(bestiaire, p.nom);
	p.nom = espece_de_p.evolvesTo;
	p.evo += 1;
	cout << ancien_nom << " a evolue vers " << p.nom << "." << endl;

	//Suivi de l'évolution dans l'historique.
	Evolution* evo_de_p = new Evolution;
	evo_de_p->nom_avant = ancien_nom;
	evo_de_p->nom_apres = p.nom;
	evo_de_p->suivant_evo = NULL;
	inserer_evo(evo_des_pokemons,evo_de_p);
}

// Fonction powerup.
void powerup(Pokemon& p) {
	int cp = p.cp + floor(0.25 * p.pv);
	//On utilise floor la fonction qui prend la partie entière d'un réel double
	p.cp = cp;
	cout << p.nom << " a progresse : ses points de combats (CP) ont augmentes de 25 % de ses points de vie (PV)." << endl;
}

// Fonction display.
void display(const Pokemon p,EspecePokemon bestiaire[],char* typeLabel[]) {
	EspecePokemon espece_de_p = asso_espece_et_nompokemon(bestiaire, p.nom);
	int esp = espece_de_p.type;

	cout << endl;
	cout << "Statistiques du Pokemon. " << endl;
	cout << "Nom du Pokemon : " << p.nom << endl;
	cout << "Experience XP : " << p.xp << endl;
	cout << "Evolution : " << p.evo << endl;
	cout << "Points de vie PV : " << p.pv << endl;
	cout << "Points de vie de combat CP : " << p.cp << endl;
	cout << "Type : " << typeLabel[esp] << endl;
	cout << endl;
}