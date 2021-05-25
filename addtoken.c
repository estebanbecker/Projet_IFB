//
// Created by Yann Derré on 18/05/2021.
//

#include "addtoken.h"
#include "table.h"



int addtoken(char jeton, int input, grid *pgrid) {
    int i=(*pgrid).side-1;
    while ((*pgrid).data[i][input] != '-') {
        --i;
    }
    (*pgrid).data[i][input]=jeton;
}

int removetoken(int input, grid *pgrid){
    int i=0;
    while ((*pgrid).data[i][input] != 'X' && (*pgrid).data[i][input] != 'O'){
        ++i;

    }
    (*pgrid).data[i][input] = '-';
    return input;
}