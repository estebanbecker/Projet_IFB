//
// Created by Yann Derré on 18/05/2021.
//

#include "addtoken.h"


char changetoken(char jeton){
    if(jeton=='X'){
        jeton='O';
    }else{
        if(jeton=='O'){
            jeton='X';
        }
    }
    return jeton;
}

int addtoken(char jeton, int input, grid *pgrid) {
    int i=(*pgrid).side-1;

    //Parcours la colonne de bas en haut jusqu'à trouver une case vide
    while ((*pgrid).data[i][input] != '-') {
        --i;
    }
    (*pgrid).data[i][input]=jeton;

    return i;
}

int removetoken(int input, grid *pgrid){
    int i=0;

    //parcours la grille de haut en bas jusqu'à ce que la case soit vide
    while ((*pgrid).data[i][input] == '-'){
        ++i;

    }
    (*pgrid).data[i][input] = '-';
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