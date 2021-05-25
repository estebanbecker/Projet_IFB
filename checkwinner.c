//
// Created by Yann Derré on 18/05/2021.
//

#include <stdio.h>
#include "checkwinner.h"


int tableau[10][10], aligned=1, consent=0, buffer;

//penser à stocker input dans un buffer pour pouvoir le faire évolluer dans les differents while's

int checkligne(char jeton, int n, int i, int input){
    aligned = 1;
    while(tableau[i][input] = jeton){
        input = input - 1;
        aligned = aligned +1;
    }
    if(aligned>n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if(consent = 1){
            //lancer la fonction new game
        }else{
            return -1;
        }
    }
    aligned = 1;
    while(tableau[i][input] = jeton){
        input = input + 1;
        aligned = aligned+1;
    }
    if(aligned>n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if(consent = 1){
            //lancer la fonction new game
        }else{
            return -1;
        }
    }
} //n le mode de jeu sélectionné par l'utilisateur

int checkdiag(char jeton, int n, int i, int input){
    aligned = 1;
    buffer = i;
    while(tableau[i][input] = jeton){
        input = input + 1;
        buffer = buffer + 1;
        aligned = aligned +1;
    }
    if(aligned>n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if(consent = 1){
            //lancer la fonction new game
        }else{
            return -1;
        }
    }
    aligned = 1;
    while(tableau[i][input] = jeton){
        input = input - 1;
        buffer = buffer - 1;
        aligned = aligned+1;
    }
    if(aligned>n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if(consent = 1){
            //lancer la fonction new game
        }else{
            return -1;
        }
    }
    aligned = 1;
    while(tableau[i][input] = jeton){
        input = input + 1;
        buffer = buffer - 1;
        aligned = aligned +1;
    }
    if(aligned>n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if(consent = 1){
            //lancer la fonction new game
        }else{
            return -1;
        }
    }
    aligned = 1;
    while(tableau[i][input] = jeton){
        input = input + 1;
        buffer = buffer - 1;
        aligned = aligned+1;
    }
    if(aligned>n) {
        printf("le joueur %c à Gagné\n", jeton);
        printf("Rejouer? 1/0\n");
        scanf("%d", &consent);
        if(consent = 1){
            //lancer la fonction new game
        }else{
            return -1;
        }
    }
}

int checkcolonne(char jeton){

}
