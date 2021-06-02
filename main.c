#include <stdio.h>
#include "definitions/defs.h"

    /*
  What: Simplex in C
  AUTHOR: GPL(C) moshahmed/at/gmail.

  What: Solves LP Problem with Simplex:
    { maximize cx : Ax <= b, x >= 0 }.
  Input: { m, n, Mat[m x n] }, where:
    b = mat[1..m,0] .. column 0 is b >= 0, so x=0 is a basic feasible solution.
    c = mat[0,1..n] .. row 0 is z to maximize, note c is negated in input.
    A = mat[1..m,1..n] .. constraints.
    x = [x1..xm] are the named variables in the problem.
    Slack variables are in columns [m+1..m+n]

  USAGE:
    1. Problem can be specified before main function in source code:
      c:\> vim mosplex.c  
      Tableau tab  = { m, n, {   // tableau size, row x columns.
          {  0 , -c1, -c2,  },  // Max: z = c1 x1 + c2 x2,
          { b1 , a11, a12,  },  //  b1 >= a11 x1 + a12 x2
          { b2 , a21, a22,  },  //  b2 >= a21 x1 + a22 x2
        }
      };
      c:\> cl /W4 mosplex.c  ... compile this file.
      c:\> mosplex.exe problem.txt > solution.txt

    2. OR Read the problem data from a file:
      $ cat problem.txt
            m n
            0  -c1 -c2
            b1 a11 a12
            b2 a21 a11 
      $ gcc -Wall -g mosplex.c  -o mosplex
      $ mosplex problem.txt > solution.txt
*/

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
        int a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3;
        int rhs1, rhs2, rhs3;
        printf("Enter the coefficients")
    }
    printTableau(&tab,"Initial");
    simplex(&tab);
    printf("\n");
    return 0;
}
