//
// Created by esteb on 18/05/2021.
//

#include <malloc.h>
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
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            (*table).data[i][j]='-';
        }
    }

    printf ("%c",(*table).data[1][1]);
}