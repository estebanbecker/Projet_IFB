//
// Created by esteb on 25/05/2021.
//

#ifndef PROJET_IFB_SAVE_H
#define PROJET_IFB_SAVE_H

#include "table.h"

/**
 * Sauvegarder la partie
 * @param turn Tour du joueur à qui c'est de jouer
 * @param colonne_no Colonne interdite
 * @param type_partie Partie IA ou JvJ
 * @param grille Grille à sauvegarder
 * @param slot Nom du fichier de sauvegarde
 */
void save(char turn, int colonne_no,int type_partie, grid grille, char slot[30]);

/**
 * Charger une sauvegarde
 * @param turn Pointeur pour stocker le tour en cours
 * @param colonne_no Pointeur pour stocker la colonne interdite
 * @param type_partie Pointeur pour stocker le type de partie JvJ/IA
 * @param grille Pointeur pour stocker la grille
 * @param slot Nom du ficher à charger
 */
void load(char *turn,int * colonne_no, int * type_partie, grid * grille, char slot[30]);

#endif //PROJET_IFB_SAVE_H
