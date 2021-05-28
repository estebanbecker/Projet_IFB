#include "table.h"
#include "addtoken.h"
#include "checkwinner.h"
#include "save.h"
#include <stdio.h>

int main() {

    grid table; //La grille de la partie
    int buffer=-1;
    int type_part;
    char turn='X';






    new_grid(12,&table);


    addtoken('X',4,&table);
    show_grid(table);
    addtoken('O',5,&table);
    show_grid(table);
    addtoken('X',4,&table);
    show_grid(table);
    printf("%d",checkcolonne('X', 2, 10, 4, table));


}
