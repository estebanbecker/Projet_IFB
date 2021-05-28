//
// Created by Yann Derré on 18/05/2021.
//

#ifndef PROJET_IFB_ADDTOKEN_H
#define PROJET_IFB_ADDTOKEN_H
#include "table.h"

/**
 * Ajoute un jeton dans une colonne
 * @param jeton Le jteon à ajouter (X ou O)
 * @param input La colonne ou ajouter le jeton
 * @param pgrid Le pointeur de la grille à modifier
 * @return Renvoit la ligne ou le jeton a été ajouté
 */
int addtoken(char jeton, int input, grid *pgrid);

/**
 * Retire un jeton d'une colonne
 * @param input La colonne où il faut retirer le jeton
 * @param pgrid Le pointeur de la grille à modifier
 * @return Numero de la ligne qui a été modifié
 */
int removetoken(int input, grid *pgrid);

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
