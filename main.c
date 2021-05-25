#include <stdio.h>
#include "table.h"
#include "addtoken.h"

int main() {

    grid table;
    grid *ptable;

    ptable=&table;



    new_grid(12,ptable);

    addtoken('X',3,ptable);
    show_grid(table);
    addtoken('O',5,ptable);
    show_grid(table);
    addtoken('X',3,ptable);
    show_grid(table);
    removetoken(3,ptable);
    show_grid(table);


}
