//
// Created by Yann Derré on 18/05/2021.
//

#include "addtoken.h"




int addtoken(char jeton, int input, grid *pgrid) {
    int i=(*pgrid).side-1;
    while ((*pgrid).data[i][input] != '-') {
        --i;
    }
    (*pgrid).data[i][input]=jeton;

    return i;
}

int removetoken(int input, grid *pgrid,int *buffer){
    int i=0;
    while ((*pgrid).data[i][input] != 'X' && (*pgrid).data[i][input] != 'O'){
        ++i;

    }
    (*pgrid).data[i][input] = '-';

    *buffer=input;
    return i;

}