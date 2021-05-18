//
// Created by Yann Derré on 18/05/2021.
//

#include <printf.h>
#include "checkwinner.h"

int tableau[10][10], input, aligned=1, i=0, n, consent=0;

//penser à stocker input dans un buffer pour pouvoir le faire évolluer dans les differents while's

int checkligne(int jeton){
    while(tableau[i][input] = jeton){
        input = input - 1;
        aligned = aligned +1;
    }
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

    }//n le mode de jeu sélectionné par l'utilisateur
}

int checkdiag(int jeton){

}

int checkcolonne(){

}
