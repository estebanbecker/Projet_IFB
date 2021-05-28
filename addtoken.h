//
// Created by Yann Derré on 18/05/2021.
//

#ifndef PROJET_IFB_ADDTOKEN_H
#define PROJET_IFB_ADDTOKEN_H
#include "table.h"

char changetoken(char jeton);
int addtoken(char jeton, int input, grid *pgrid);
int removetoken(int input, grid *pgrid,int *buffer);

#endif //PROJET_IFB_ADDTOKEN_H
