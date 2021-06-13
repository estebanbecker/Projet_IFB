//
// Created by Yann Derré on 18/05/2021.
//

#include "table.h"

#ifndef PROJET_IFB_CHECKWINNER_H
#define PROJET_IFB_CHECKWINNER_H

#endif //PROJET_IFB_CHECKWINNER_H

int checkwinner(char jeton, int n, int i, int input, grid table);
int checkligne(char jeton, int n, int i, int input, grid table);
int checkdiag(char jeton, int n, int i, int input, grid table);
int checkcolonne(char jeton, int n, int i, int input, grid table);
int restart(grid table);