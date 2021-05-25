//
// Created by esteb on 18/05/2021.
//

#ifndef PROJET_IFB_TABLE_H
#define PROJET_IFB_TABLE_H

typedef struct{
    int side;
    char **data;
}grid;

/**
 * Créer une grille en deux dimension
 * @param side Nombre de case par coté de la grille
 * @param table Pointeur de la structure grid a modifier
 */

void new_grid(int side,grid *table);

/**
 * Affiche la grille
 * @param table structure grille de la grille à afficher
 */

void show_grid(grid table);

#endif //PROJET_IFB_TABLE_H
