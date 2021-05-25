#include "table.h"
#include "addtoken.h"
#include "checkwinner.h"
#include "save.h"

int main() {

    grid table;
    grid *ptable;
    int buffer,*pbuffer;

    pbuffer=&buffer;

    ptable=&table;



    new_grid(2,ptable);

    addtoken('X',1,ptable);
    show_grid(table);
    addtoken('O',1,ptable);
    show_grid(table);
    addtoken('X',0,ptable);
    show_grid(table);

    save('_',5,1,table,'a');

}
