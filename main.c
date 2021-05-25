#include <stdio.h>
#include "table.h"
#include "addtoken.h"
#include "checkwinner.h"

int main() {

    grid table;
    grid *ptable;
    int buffer,*pbuffer;

    pbuffer=&buffer;

    ptable=&table;



    new_grid(12,ptable);

    addtoken('X',3,ptable);
    show_grid(table);
    addtoken('O',5,ptable);
    show_grid(table);
    addtoken('X',4,ptable);
    show_grid(table);
    checkligne('X', 2, 4, addtoken);


}
