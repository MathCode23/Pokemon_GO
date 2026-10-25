#ifndef _SAUVEGARDE_H_
#define _SAUVEGARDE_H_

#include "pokedex.h"

void creationfichiersauvegarde(Pokedex* MonPokedex,Ressource reserve);
//Fonction qui permet de creer un fichier de sauvegarde d'une partie.

void chargementpartie(Pokedex* MonPokedex, Ressource& reserve);
//Fonction qui permet de charger une partie (si elle existe).
//ON SUPPOSE QUE MonPokedex NE CONTIENT AUCUN POKEMON : L'UTILISATEUR VIENT JUSTE D'OUVRIR LE JEU !!!!!

#endif