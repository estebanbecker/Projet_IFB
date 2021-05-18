//
// Created by esteb on 18/05/2021.
//

#ifndef PROJET_IFB_TABLE_H
#define PROJET_IFB_TABLE_H

typedef struct{
    int side;
    char data[25][25];
}grid;

grid new_grid(int side);

#endif //PROJET_IFB_TABLE_H
