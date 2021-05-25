//
// Created by esteb on 25/05/2021.
//
#include <stdio.h>
#include "save.h"

void save(char turn, int buffer,int type_partie, grid grille,char slot){

    FILE* file= fopen(&slot,"w");

    fprintf(file,"%d\n",grille.side);
    fprintf(file,"%c\n",turn);
    fprintf(file,"%d\n",type_partie);
    fprintf(file,"%d\n",buffer);
    for (int i = 0; i < grille.side; ++i) {

        for (int j = 0; j < grille.side; ++j) {

            fprintf(file,"%c\n",grille.data[i][j]);

        }

    }
}