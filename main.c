#include "table.h"
#include "addtoken.h"
#include "checkwinner.h"
#include "save.h"
#include <stdio.h>

int main() {

    grid table;
    grid *ptable;
    int buffer=-1;
    int *pbuffer;
    int type_part;
    char turn='X';
    int action;
    int input;
    int quit;
    int i;
    int checkup=0;
    char name[30];
    pbuffer=&buffer;
    ptable=&table;
    int size;
    printf("----- PUISSANCE N ----\n");
    printf("(1) Nouvelle partie? - ");
    printf("(2) Charger partie\n");
    scanf("%d", &action);
    if(action==1){
    printf("Quelle taille puissance N\n");
    scanf("%d", &size);
    new_grid(size+2,&table);
    }
    else{
        if(action==2){
            printf("Nom de sauvegarde??");
            gets(name);
            load(&turn,&buffer,&type_part,&table,name);
        }
    }

    do{
        turn=changetoken(turn);
        show_grid(table);
        printf("(1) Jouer jeton? - ");
        printf("(2) Effacer jeton? - ");
        printf("(3) Sauvegarder\n");
        scanf("%d", &action);
        if(action==1){
            while(checkup!=1) {
                printf("Ou ajouter jeton?? 1 - %d\n", size+2);
                scanf("%d", &input);
                if (input - 1 == buffer) {
                    printf("Vous ne pouvez pas jouer dans cette colonne.\n");
                }else{
                    checkup=1;
                }

            }
            buffer=-1;
            i=addtoken(turn, input-1, &table);
            show_grid(table);
            checkwinner(turn, size, i, input-1, table);
        }else{
            if(action==2){
                printf("Jeton à supprimer 1 - %d", size+2);
                scanf("%d", &input);
                buffer=input;
                removetoken(input-1, &table);
            }else{
                if(action==3){
                    printf("Nom de sauvegarde???\n");
                    gets(name);
                    save(turn, buffer, 1, table, name);
                    printf("Quitter?  - 0/1\n");
                    scanf("%d", &quit);
                    if(quit==1){
                        return 0;
                    }
                }
            }
        }
    } while (checkwinner(turn, size, i, input-1, table));
}
