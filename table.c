//
// Created by esteb on 18/05/2021.
//

#include <malloc.h>
#include "table.h"
#include <stdlib.h>
#include <stdio.h>


void new_grid(int n,grid *table){


    (*table).side=n; //Attribution de la valeur d'un coté

    (*table).data = (char **)malloc(n * sizeof(int *)); //création d'un tableau de n pointeur
    if ((*table).data == NULL){
        printf("\nEchec lors de l'allocation memoire!!!");//erreur en cas de problème d'attribution
    }


    for (int i=0;i<n;i++)
    {
        (*table).data[i] = (char *)malloc(n * sizeof(int)); //allocation d'un tableau de caractère dans chaque ligne de tableau
        if ((*table).data[i] == NULL)
        {
            for (int j=0;j<i;j++)
            {
                free((*table).data[j]); //liberation du tableau en cas d'erreur

                printf("\n Echec lors de l'allocation memoire!!!");//erreur en cas de problème d'attribution
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            (*table).data[i][j]='-'; //Remplissage du tableau vide
        }
    }

}

void show_grid(grid table){

    int nb_char=1,mem=table.side+1,mem2; //nb_char est le nombre de caractère que doit prendre une colonne+1

    while (mem>=10){
        mem=mem/10;
        ++nb_char;
    } //calcule du nombre de caractère que va prendre une colonne+1

    for (int i = 0; i < table.side; ++i) {
        printf("%d",i+1);
        mem=i+1;
        mem2=0;
        while (mem>=10){
            mem=mem/10;
            ++mem2;
        }//calcule du nombre de case que va prendre le nombre de la colonne

        for (int j = 0; j < nb_char-mem2; ++j) {
            printf(" ");//Ajout du nombre d'espace pour que chaque colonne soit identique
        }
    }

    printf("\n");

    for (int i = 0; i < table.side; ++i) {

        for (int j = 0; j < table.side; ++j) {
            printf("%c",table.data[i][j]);

            for (int k = 0; k < nb_char; ++k) {
                printf(" "); //ajout des espaces entre les colonnes
            }
        }

        printf("\n");

    }
    printf("\n");

}