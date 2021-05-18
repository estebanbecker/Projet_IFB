//
// Created by Yann Derré on 18/05/2021.
//

#include "addtoken.h"
#include "table.h"



int addtoken(int jeton, int input, grid *pgrid) {
    int i=0;
    while ((*pgrid).data[i][input] != '-') {
        i = i + 1;
    }
    (*pgrid).data[i][input]=jeton;
}

int removetoken(int jeton, int input, grid *pgrid){
    int i=0;
    while ((*pgrid).data[i][input] != 'X' && (*pgrid).data[i][input] != 'O'){
        i=i+1;
    }
    int buffer_y = i;
    int buffer_x = input;
}