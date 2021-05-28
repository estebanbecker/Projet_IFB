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

int valid_add_colonne(int colonne, grid table){

    if (table.data[colonne][0]=='-'){ //Verifie que la case en haut est libre
        return 1;
    }else{
        return 0;
    }

}

int valid_remove_colonne(int colonne, grid table){

    if(table.data[colonne][table.side-1]=='-'){ //Verifie que la case en bat est pleine
        return 0;
    }else {
        return 1;
    }
}