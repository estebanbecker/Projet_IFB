#include "table.h"
#include "addtoken.h"
#include "checkwinner.h"
#include "save.h"
#include <stdio.h>

int main() {

    grid table;
    grid *ptable;
    int buffer;
    int *pbuffer;
    int type_part;
    char turn;

    pbuffer=&buffer;

    ptable=&table;




    new_grid(12,ptable);


    addtoken('X',4,ptable);
    show_grid(table);
    addtoken('O',5,ptable);
    show_grid(table);
    addtoken('X',4,ptable);
    show_grid(table);
    printf("%d",checkcolonne('X', 2, 10, 4, table));


}
