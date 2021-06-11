//
// Created by esteb on 28/05/2021.
//

#include "bot.h"
#include "time.h"
#include "addtoken.h"

#include <stdlib.h>
#include <stdio.h>


void bot(grid *table,int *ban_col){

    int buffer1,has_play;//buffer1 pour stocker l'endroit où jouer, has_play permet de savoir si le bot a joué
    srand(time(0));
    do{
        has_play=0;//réinitialise le buffer

        buffer1=rand()%(*table).side;//gener une colonne aléatoire

        if((rand()%10)<8){

            if(valid_add_colonne(buffer1,*table) && buffer1!=*ban_col){//vérifie si l'action peut être effectué
                addtoken('X',buffer1,table);
                printf("Bot a joué dans la colonne %d\n", buffer1+1);
                *ban_col=-1;
            }else{
                has_play=1; //empêche le programme de sortir de la boucle
            }

        }else{

            if(valid_remove_colonne(buffer1,*table)){//vérifie si l'action peut être effectué
                removetoken(buffer1,table);
                printf("Bot a supprimé un jeton dans la colonne %d\n", buffer1+1);
                *ban_col=buffer1;
            }else{
                has_play=1;//empêche le programme de sortir de la boucle
            }

        }


    } while (has_play);//vérifie que l'action a été effectué







}