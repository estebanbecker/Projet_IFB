//
// Created by esteb on 25/05/2021.
//
#include <stdio.h>
#include "table.h"


void save(char turn, int colonne_no,int type_partie, grid grille,char slot[30]){

    FILE* file= fopen(slot,"w");//Crée un fichier

    fprintf(file,"%d\n",grille.side);//Erengistre le nombre de case de la grille
    fprintf(file,"%c\n",turn);//Enrengistre le tour du joueur
    fprintf(file,"%d\n",type_partie);//Enrengistre JvJ ou IA
    fprintf(file,"%d\n",colonne_no);//Enrengistre la colonne interdite
    for (int i = 0; i < grille.side; ++i) {

        for (int j = 0; j < grille.side; ++j) {

            fprintf(file,"%c",grille.data[i][j]); //Enrengistre les valeurs de la grille

        }

    }
    fclose(file);
}

int load(char *turn,int * colonne_no, int * type_partie, grid * pgrille, char slot[30]){

    FILE* file= fopen(slot, "r");//Ouverture du fichier

    if (file==NULL){
        printf("Fichier inexistant\n");
        return 0;//Vérifie que le fichier à bien été ouvert
    }else{

        char buffer_string[11];int buffer_int;//Memoire d'un string et d'un integrer

        fgets(buffer_string,10,file); //Recuperation de la taille de la grille
        sscanf((const char *) &buffer_string, "%d", &buffer_int);
        new_grid(buffer_int,pgrille);//Creation de la grille
        *turn=fgetc(file);//Recuperation du tour de la personne qui doit jouer
        fgetc(file);
        fgets(buffer_string,5,file);//Recuperation du type de partie (JvJ ou IA)
        sscanf((const char *) &buffer_string, "%d", type_partie);

        fgets(buffer_string,5,file);//Recuperation de la colonne interdite
        sscanf((const char *) &buffer_string, "%d", colonne_no);

        for (int i = 0; i < (*pgrille).side; ++i) {

            for (int j = 0; j < (*pgrille).side; ++j) {

                (*pgrille).data[i][j]=fgetc(file);//Récuperation des valeurs du tableau

            }

        }
    }
    fclose(file);
    return 1;
}
