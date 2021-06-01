//
// Created by esteb on 28/05/2021.
//

#include "bot.h"
#include "time.h"
#include "addtoken.h"

#include <stdlib.h>

void bot(grid *table,int ban_col){

    int buffer1,has_play;//buffer1 pour stocker l'endroit où jouer, has_play permet de savoir si le bot a joué

    do{
        has_play=0;//réinitialise le buffer

        buffer1=rand()%(*table).side;//gener une colonne aléatoire

        if((rand()/5)<4){

            if(valid_add_colonne(buffer1,*table) && buffer1!=ban_col){//vérifie si l'action peut être effectué
                addtoken('X',buffer1,table);
            }else{
                has_play=1; //empêche le programme de sortir de la boucle
            }

        }else{

            if(valid_remove_colonne(buffer1,*table)){//vérifie si l'action peut être effectué
                removetoken(buffer1,table);
            }else{
                has_play=1;//empêche le programme de sortir de la boucle
            }

        }


    } while (has_play);//vérifie que l'action a été effectué

    srand(time(0));





}