//
// Created by Yann Derré on 18/05/2021.
//

#include <stdio.h>
#include "checkwinner.h"
#include "table.h"

int tableau[10][10], aligned = 1, consent = 0, buffery, bufferx;

//penser à stocker input dans un buffer pour pouvoir le faire évolluer dans les differents while's

int checkwinner(char jeton, int n, int i, int input, grid table){
    checkligne(jeton, n, i, input, table);
    checkdiag(jeton, n, i, input, table);
    checkcolonne(jeton, n, i, input, table);
}

int checkligne(char jeton, int n, int i, int input, grid table) {
    int bufferx = input;
    int aligned = 0;
    while (table.data[table.side-1][bufferx] == jeton && bufferx != 0 && bufferx != table.side){
        bufferx = bufferx - 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        scanf("%d", &consent);
        if (consent == 1) {
            //lancer la fonction new game
        } else {
            return -1;
        }
    }
    aligned = 0;
    bufferx = input;
    while (table.data[table.side-1][bufferx] == jeton && bufferx != 0 && bufferx != table.side) {
        bufferx = bufferx + 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            //lancer la fonction new game
        } else {
            return -1;
        }
    }
} //n le mode de jeu sélectionné par l'utilisateur

int checkdiag(char jeton, int n, int i, int input, grid table) {
    int aligned = 0;
    int buffery = i;
    int bufferx = input;
    while (table.data[buffery][bufferx] == jeton && bufferx != 0 && bufferx != table.side && buffery!=0 && buffery!=table.side) {
        bufferx = bufferx + 1;
        buffery = buffery + 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            //lancer la fonction new game
        } else {
            return -1;
        }
    }
    bufferx = input;
    buffery = i;
    aligned = 0;
    while (table.data[buffery][bufferx] == jeton && bufferx != 0 && bufferx != table.side && buffery!=0 && buffery!=table.side) {
        bufferx = bufferx - 1;
        buffery = buffery - 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            //lancer la fonction new game
        } else {
            return -1;
        }
    }
    aligned = 0;
    bufferx = input;
    buffery = i;
    while (table.data[buffery][bufferx] == jeton && bufferx != 0 && bufferx != table.side && buffery!=0 && buffery!=table.side) {
        bufferx = bufferx + 1;
        buffery = buffery - 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            //lancer la fonction new game
        } else {
            return -1;
        }
    }
    bufferx = input;
    buffery = i;
    aligned=0;
    while (table.data[buffery][bufferx] == jeton && bufferx != 0 && bufferx != table.side && buffery!=0 && buffery!=table.side) {
        bufferx = bufferx - 1;
        buffery = buffery + 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            //lancer la fonction new game
        } else {
            return -1;
        }
    }
}

int checkcolonne(char jeton, int n, int i, int input, grid table) {
    int buffery = i;
    int aligned = 0;
    while (table.data[buffery][input] == jeton && buffery != 0 && buffery != table.side){
        buffery = buffery - 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        scanf("%d", &consent);
        if (consent == 1) {
            //lancer la fonction new game
        } else {
            return -1;
        }
    }
    aligned = 0;
    buffery = i;
    while (table.data[buffery][input] == jeton && buffery != 0 && buffery != table.side) {
        buffery = buffery + 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            //lancer la fonction new game
        } else {
            return -1;
        }
    }
}
