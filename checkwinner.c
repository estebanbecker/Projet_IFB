//
// Created by Yann Derré on 18/05/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "checkwinner.h"
#include "table.h"

int tableau[10][10], aligned = 1, consent = 0, buffery, bufferx;

/**
 * Décomposition de la fonction check winner dans les différentes directions
 */

int checkwinner(char jeton, int n, int i, int input, grid table){

    checkdiag(jeton, n, i, input, table);
    checkcolonne(jeton, n, i, input, table);
    checkligne(jeton, n, i, input, table);
}

/**
 * Vérification de la victoire sur l'axe X
 * @param jeton
 * @param n
 * @param i
 * @param input
 * @param table
 * @return
 */

int checkligne(char jeton, int n, int i, int input, grid table) {
    int bufferx = input;
    int aligned = 0;
    while (bufferx != 0 && bufferx != table.side && table.data[table.side-1][bufferx] == jeton){ //Vefification sur l'axe X-
        bufferx = bufferx - 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            restart(table);
        } else {
            exit(0);
        }
    }
    aligned = 0;
    bufferx = input;
    while (bufferx != 0 && bufferx != table.side && table.data[table.side-1][bufferx] == jeton) { //Vérification sur X+
        bufferx = bufferx + 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            restart(table);
        } else {
            exit(0);
        }
    }
} //n le mode de jeu sélectionné par l'utilisateur

int checkdiag(char jeton, int n, int i, int input, grid table) {
    int aligned = 0;
    int buffery = i;
    int bufferx = input;
    while (bufferx != table.side && buffery!=0 && buffery!=table.side && bufferx != 0 && table.data[buffery][bufferx] == jeton) {
        bufferx = bufferx + 1;
        buffery = buffery + 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            restart(table);
        } else {
            exit(0);
        }
    }
    bufferx = input;
    buffery = i;
    aligned = 0;
    while (bufferx != 0 && bufferx != table.side && buffery!=0 && buffery!=table.side && table.data[buffery][bufferx] == jeton) {
        bufferx = bufferx - 1;
        buffery = buffery - 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            restart(table);
        } else {
            exit(0);
        }
    }
    aligned = 0;
    bufferx = input;
    buffery = i;
    while (bufferx != 0 && bufferx != table.side && buffery!=0 && buffery!=table.side && table.data[buffery][bufferx] == jeton) {
        bufferx = bufferx + 1;
        buffery = buffery - 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            restart(table);
        } else {
            exit(0);
        }
    }
    bufferx = input;
    buffery = i;
    aligned=0;
    while (bufferx != 0 && bufferx != table.side && buffery!=0 && buffery!=table.side && table.data[buffery][bufferx] == jeton) {
        bufferx = bufferx - 1;
        buffery = buffery + 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            restart(table);
        } else {
            exit(0);
        }
    }
}

int checkcolonne(char jeton, int n, int i, int input, grid table) {
    int buffery = i;
    int aligned = 0;
    while (buffery != 0 && buffery != table.side && table.data[buffery][input] == jeton){
        buffery = buffery - 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        scanf("%d", &consent);
        if (consent == 1) {
            restart(table);
        } else {
            exit(0);
        }
    }
    aligned = 0;
    buffery = i;
    while (buffery != 0 && buffery != table.side && table.data[buffery][input] == jeton) {
        buffery = buffery + 1;
        aligned = aligned + 1;
    }
    if (aligned >= n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if (consent == 1) {
            restart(table);
        } else {
            exit(0);
        }
    }
}

int restart(grid table){
    int j=0;
    int i=0;
    while(j<table.side) {
            table.data[i][j] = '-';
            i=i+1;
            if(i==table.side-1){
                table.data[i][j] = '-';
                j=j+1;
                i=0;
            }
        }
}