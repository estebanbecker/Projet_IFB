//
// Created by esteb on 18/05/2021.
//

#include "table.h"
#include <stdlib.h>
#include <stdio.h>


void new_grid(int n,grid *table){


    (*table).side=n;

    (*table).data = (char **)malloc(n * sizeof(int *));
    if ((*table).data == NULL){
        printf("\nEchec lors de l'allocation memoire!!!");
    }


    for (int i=0;i<n;i++)
    {
        (*table).data[i] = (char *)malloc(n * sizeof(int));
        if ((*table).data[i] == NULL)
        {
            for (int j=0;j<i;j++)
            {
                free((*table).data[j]);

                printf("\n Echec lors de l'allocation memoire!!!");
            }

            free((*table).data);
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            (*table).data[i][j]='-';
        }
    }

}

void show_grid(grid table){

    int nb_char=1,mem=table.side+1,mem2;
    while (mem>=10){
        mem=mem/10;
        ++nb_char;
    }

    for (int i = 0; i < table.side; ++i) {
        printf("%d",i+1);
        mem=i+1;
        mem2=0;
        while (mem>=10){
            mem=mem/10;
            ++mem2;
        }

        for (int j = 0; j < nb_char-mem2; ++j) {
            printf(" ");
        }
    }

    printf("\n");

    for (int i = 0; i < table.side; ++i) {

        for (int j = 0; j < table.side; ++j) {
            printf("%c",table.data[i][j]);

            for (int k = 0; k < nb_char; ++k) {
                printf(" ");
            }
        }

        printf("\n");

    }

}

void del_grid(grid * table){



        for (int i = 0; i < (*table).side; ++i) {

            free((*table).data[i]);

        }

        free((*table).data);


}