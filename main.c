#include <stdio.h>
#include "table.h"

int main() {

    grid table;
    grid *ptable;

    ptable=&table;



    new_grid(12,ptable);


    show_grid(table);
}
