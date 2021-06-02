#include <stdio.h>
#include "../definitions/defs.h"

void printTableau(Tableau *tab, const char* mes) {
  static int counter=0;
  int i, j;
  printf("\n%d. Tableau %s:\n", ++counter, mes);
  nl(70);

  printf("%-6s%5s", "col:", "b[i]");
  for(j=1;j<tab->n; j++) { printf("    x%d,", j); } printf("\n");

  for(i=0;i<tab->m; i++) {
    if (i==0) printf("max:"); else
    printf("b%d: ", i);
    for(j=0;j<tab->n; j++) {
      if (equal((int)tab->mat[i][j], tab->mat[i][j]))
        printf(" %6d", (int)tab->mat[i][j]);
      else
        printf(" %6.2lf", tab->mat[i][j]);
      }
    printf("\n");
  }
  nl(70);
}

/* Example input file for readTableau:
     4 5
      0   -0.5  -3 -1  -4 
     40    1     1  1   1 
     10   -2    -1  1   1 
     10    0     1  0  -1  
*/
void readTableau(Tableau *tab, const char * filename) {
  int err, i, j;
  FILE * fp;

  fp  = fopen(filename, "r" );
  if( !fp ) {
    printf("Cannot read %s\n", filename); exit(1);
  }
  memset(tab, 0, sizeof(*tab));
  err = fscanf(fp, "%d %d", &tab->m, &tab->n);
  if (err == 0 || err == EOF) {
    printf("Cannot read m or n\n"); exit(1);
  }
  for(i=0;i<tab->m; i++) {
    for(j=0;j<tab->n; j++) {
      err = fscanf(fp, "%lf", &tab->mat[i][j]);
      if (err == 0 || err == EOF) {
        printf("Cannot read A[%d][%d]\n", i, j); exit(1);
      }
    }
  }
  printf("Read tableau [%d rows x %d columns] from file '%s'.\n",
    tab->m, tab->n, filename);
  fclose(fp);
}

void userInputTableau(Tableau *tab) {
  double a1, a2, a3;
        printf("Enter the coefficients:\n");
        printf("c1: ");
        scanf("%lf", &a1);
        tab->mat[0][1] = -a1;
        printf("c2: ");
        scanf("%lf", &a2);
        tab->mat[0][2] = -a2;
        printf("c3: ");
        scanf("%lf", &a3);
        tab->mat[0][3] = -a3;
        printf("rhs: ");
        scanf("%lf", &tab->mat[0][0]);
        printf("Enter the constraint coefficients 1:\n");
        printf("a11: ");
        scanf("%lf", &tab->mat[1][1]);
        printf("a12: ");
        scanf("%lf", &tab->mat[1][2]);
        printf("a13: ");
        scanf("%lf", &tab->mat[1][3]);
        printf("rhs: ");
        scanf("%lf", &tab->mat[1][0]);
        printf("Enter the constraint coefficients 2:\n");
        printf("a21: ");
        scanf("%lf", &tab->mat[2][1]);
        printf("a22: ");
        scanf("%lf", &tab->mat[2][2]);
        printf("a23: ");
        scanf("%lf", &tab->mat[2][3]);
        printf("rhs: ");
        scanf("%lf", &tab->mat[2][0]);
        printf("Enter the constraint coefficients 3:\n");
        printf("a31: ");
        scanf("%lf", &tab->mat[3][1]);
        printf("a31: ");
        scanf("%lf", &tab->mat[3][2]);
        printf("a31: ");
        scanf("%lf", &tab->mat[3][3]);
        printf("rhs: ");
        scanf("%lf", &tab->mat[3][0]);
}

void print_optimal_vector(Tableau *tab, char *message) {
  int j, xi;
  printf("%s: %3.2lf at ", message, tab->mat[0][0]);

  for(j=1;j<tab->n;j++) { // for each column.
    xi = find_basis_variable(tab, j);
    if (xi != -1)
      printf("x%d=%3.2lf, ", j, tab->mat[xi][0] );
    else
      printf("x%d=0, ", j);
  }
  printf("\n");
} 