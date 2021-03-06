#include "table.h"
#include "addtoken.h"
#include "checkwinner.h"
#include "save.h"
#include "bot.h"
#include <stdio.h>

int main() {

    grid table;
    char turn='X';//Stock le jeton du joueur en cours
    int colonne_ban=-1;//Colonne interdite suite au retrait d'un jeton (-1 si aucune)
    int type_part;
    int action;
    int colonne_input;//Colonne entrée
    int quit;
    int ligne;//Ligne où le point a été ajouté
    int checkup;
    char name[30];//Nom du fichier de sauvegarde
    int size;//Taille de la grille
    int botmode=0;


    printf("                                                                                                                               \n"
           ",-.----.                                                                        ,--.                                      ,--. \n"
           "\\    /  \\                   ,---,  .--.--.    .--.--.      ,---,              ,--.'|  ,----..      ,---,.               ,--.'| \n"
           "|   :    \\          ,--, ,`--.' | /  /    '. /  /    '.   '  .' \\         ,--,:  : | /   /   \\   ,'  .' |           ,--,:  : | \n"
           "|   |  .\\ :       ,'_ /| |   :  :|  :  /`. /|  :  /`. /  /  ;    '.    ,`--.'`|  ' :|   :     :,---.'   |        ,`--.'`|  ' : \n"
           ".   :  |: |  .--. |  | : :   |  ';  |  |--` ;  |  |--`  :  :       \\   |   :  :  | |.   |  ;. /|   |   .'        |   :  :  | | \n"
           "|   |   \\ :,'_ /| :  . | |   :  ||  :  ;_   |  :  ;_    :  |   /\\   \\  :   |   \\ | :.   ; /--` :   :  |-,        :   |   \\ | : \n"
           "|   : .   /|  ' | |  . . '   '  ; \\  \\    `. \\  \\    `. |  :  ' ;.   : |   : '  '; |;   | ;    :   |  ;/|        |   : '  '; | \n"
           ";   | |`-' |  | ' |  | | |   |  |  `----.   \\ `----.   \\|  |  ;/  \\   \\'   ' ;.    ;|   : |    |   :   .'        '   ' ;.    ; \n"
           "|   | ;    :  | | :  ' ; '   :  ;  __ \\  \\  | __ \\  \\  |'  :  | \\  \\ ,'|   | | \\   |.   | '___ |   |  |-,        |   | | \\   | \n"
           ":   ' |    |  ; ' |  | ' |   |  ' /  /`--'  //  /`--'  /|  |  '  '--'  '   : |  ; .''   ; : .'|'   :  ;/|        '   : |  ; .' \n"
           ":   : :    :  | : ;  ; | '   :  |'--'.     /'--'.     / |  :  :        |   | '`--'  '   | '/  :|   |    \\        |   | '`--'   \n"
           "|   | :    '  :  `--'   \\;   |.'   `--'---'   `--'---'  |  | ,'        '   : |      |   :    / |   :   .'        '   : |       \n"
           "`---'.|    :  ,      .-./'---'                          `--''          ;   |.'       \\   \\ .'  |   | ,'          ;   |.'       \n"
           "  `---`     `--`----'                                                  '---'          `---`    `----'            '---'         \n"
           "                                                                                                                               \n");
    printf("(1) Nouvelle partie? - ");
    printf("(2) Charger partie\n");

    scanf("%d", &action);//Entrée du mode avec message d'erreur
    fflush(stdin);//Nettoyage de l'entrée au cas où l'utilisateur entre une lettre
    while (action<1 || 2<action){
        printf("L'action n'existe pas, veuillez saisir une valeur entre 1 et 2: ");
        scanf("%d", &action);
        fflush(stdin);
    }

    if(action==1){
        printf("Quelle taille puissance N\n");
        scanf("%d", &size);
        fflush(stdin);
        while (size<=3){
            printf("Veuillez entrer une valeur superieur a 3: ");
            scanf("%d", &size);
            fflush(stdin);
        }
        printf("Voulez-vous jouer en mode ordinnateur (0) ou JvJ (1)\n");
        scanf("%d", &botmode);
        while (botmode>1 || botmode<0){
            printf("Entez une valeur valide");
            scanf("%d", &botmode);
        }

        new_grid(size+2,&table);
    }
    else{
        if(action==2){
            do{
                printf("Nom de sauvegarde:\n");
                fflush(stdin);
                gets(name);
            }while(!load(&turn,&colonne_ban,&botmode,&table,name));
            size=table.side-2;
        }
    }

    while(checkdiag!=1 && checkcolonne != 1 && checkligne !=1){
        if(botmode==0){
            turn='O';
            printf("Bot réfléchit...\n");
            bot(&table, &colonne_ban);
        }else{
            if(botmode==1){
                turn=changetoken(turn);
            }
        }
        show_grid(table);
        printf("| (1) Jouer jeton?   ");
        printf(" (2) Effacer jeton? ");
        printf(" (3) Sauvegarder?  |\n");

        scanf("%d", &action);
        fflush(stdin);
        while (action<1 || 3<action){//Entrée du mode avec message d'erreur
            printf("L'action n'existe pas, veuillez saisir une valeur entre 1 et 3: ");
            scanf("%d", &action);
            fflush(stdin);
        }

        if(action==1){
            checkup=0;
            while(checkup!=1) {
                printf("Ou ajouter jeton? 1 - %d\n", size+2);
                scanf("%d", &colonne_input);//Aquisition de l'emplacement du jeton avec message d'erreur
                fflush(stdin);
                while (0>colonne_input-1 || colonne_input > table.side){
                    printf("La colonne n'existe pas \n");
                    printf("Ou ajouter jeton? 1 - %d\n", size+2);
                    scanf("%d", &colonne_input);
                    fflush(stdin);
                }

                if (colonne_input - 1 != colonne_ban  && valid_add_colonne(colonne_input-1,table)) {
                    checkup=1;
                    ligne=addtoken(turn, colonne_input-1, &table);
                }else{
                    printf("Vous ne pouvez pas jouer dans cette colonne.\n");
                }
            }
            colonne_ban=-1;

            show_grid(table);
            checkwinner(turn, size, ligne, colonne_input-1, table);
        }else  if(action==2){
            checkup=0;
            while(checkup!=1) {
                printf("Jeton à supprimer 1 - %d", size + 2);
                scanf("%d", &colonne_input);
                if(valid_remove_colonne(colonne_input-1, table)==1){
                    checkup = 1;
                    removetoken(colonne_input-1, &table);
                    show_grid(table);
                    colonne_ban = colonne_input - 1;
                }
                else{if(valid_remove_colonne(colonne_input-1, table)==0)
                    printf("La colonne est vide, choisir case valide\n");
                }
            }
        }else{
            if(action==3){
                printf("Nom de sauvegarde?\n");
                fflush(stdin);
                gets(name);
                save(turn, colonne_ban, botmode, table, name);
                printf("Quitter?  - 0/1\n");
                scanf("%d", &quit);
                if(quit==1){
                    return 0;
                }
            }
        }
    }
    printf("Rejouer?\n");
    scanf("%d", &action);
}
