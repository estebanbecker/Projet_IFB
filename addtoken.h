//
// Created by Yann Derré on 18/05/2021.
//

#ifndef PROJET_IFB_ADDTOKEN_H
#define PROJET_IFB_ADDTOKEN_H
#include "table.h"

char changetoken(char jeton);
int addtoken(char jeton, int input, grid *pgrid);

int removetoken(int input, grid *pgrid,int *buffer);

/**
 * Vérifie que la colonne n'est pas pleine
 * @param colonne Numero de la colonne à vérifier
 * @param table Tableau à controller
 * @return 0 si impossible, 1 si possible
 */
int valid_add_colonne(int colonne, grid table);

/**
 * Verifie qu'il existe un jeton à supprimer
 * @param colonne Colonne à verifier
 * @param table Grille à verifier
 * @return 0 si impossible, 1 si possible
 */
int valid_remove_colonne(int colonne, grid table);

#endif //PROJET_IFB_ADDTOKEN_H
