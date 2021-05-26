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




    //show_grid(table);


    load(&turn,pbuffer,&type_part,ptable,"a");
    printf("Buffer: %d\n",buffer);
    printf("Type part: %d\n",type_part);
    printf("Turn: %c\n",turn);

    show_grid(table);

}
