#include <stdio.h>
#include "definitions/defs.h"

Tableau tab  = { 4, 4, {                     // Size of tableau [4 rows x 5 columns ]
    {  0.0 , -0.5 , -3.0 ,-1.0 ,   },  // Max: z = 0.5*x + 3*y + z,
    { 40.0 ,  1.0 ,  1.0 , 1.0 ,   },  //    x + y + z <= 40 .. b1
    { 10.0 , -2.0 , -1.0 , 1.0 ,   },  //  -2x - y + z <= 10 .. b2
    { 10.0 ,  0.0 ,  1.0 , 0.0 ,   },  //        y <= 10 .. b3
  }
};

int main(int argc, char *argv[]){
    if (argc > 1) { // usage: cmd datafile
        readTableau(&tab, argv[1]);
    } else {
        userInputTableau(&tab);
    }
    printTableau(&tab,"Initial");
    simplex(&tab);
    printf("\n");
    return 0;
}
