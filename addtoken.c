//
// Created by Yann Derré on 18/05/2021.
//

#include "addtoken.h"

int tableau[10][10], i=0;


int addtoken(int jeton, int input) {
    while (tableau[i][input] != '-') {
        i = i + 1;
    }
    tableau[i][input]=jeton;
}

int removetoken(int jeton, int input){
    while (tableau[i][input] != 'X' && tableau[i][input] != 'O'){
        i=i+1;
    }
    int buffer_y = i;
    int buffer_x = input;
}