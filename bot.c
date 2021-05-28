//
// Created by esteb on 28/05/2021.
//

#include "bot.h"
#include "time.h"
#include "addtoken.h"

#include <stdlib.h>

void bot(grid *table,int ban_col){

    int buffer1,buffer2;//buffer1 pour ctocker l'endroit où jouer, buffer2 permet de savoir si le bot a joué

    do{
        buffer2=0//réinitialise le buffer

        buffer1=rand()%(*table).side;//gener une colonne aléatoire

        if((rand()/5)<4){

            if(valid_add_colonne(buffer1,*table)){//vérifie si l'action peut être effectué
                addtoken('X',buffer1,table)
            }else{
                buffer2=1 //empêche le programme de sortir de la boucle
            }

        }else{

            if(valid_remove_colonne(buffer1,*table)){//vérifie si l'action peut être effectué
                removetoken(buffer1,table)
            }else{
                buffer2=1//empêche le programme de sortir de la boucle
            }

        }


    } while (buffer2);//vérifie que l'action a été effectué

    srand(time(0));





}