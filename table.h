//
// Created by esteb on 18/05/2021.
//

#ifndef PROJET_IFB_TABLE_H
#define PROJET_IFB_TABLE_H

typedef struct{
    int side;
    char **data;
}grid;


void new_grid(int side,grid *table);

void show_grid(grid table);

#endif //PROJET_IFB_TABLE_H
