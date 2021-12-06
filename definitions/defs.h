#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>

#define DEBUG

#define M 20
#define N 20

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n)                         \
    if (!(n))                             \
    {                                     \
        printf("%s - Failed ", #n);        \
        printf("On %s ", __DATE__);       \
        printf("At %s ", __TIME__);       \
        printf("In File %s ", __FILE__);  \
        printf("At Line %d\n", __LINE__); \
        exit(1);                          \
    }
#endif

static const double epsilon   = 1.0*10^-8;
extern int equal(double , double );

typedef struct {
  int m, n; // m=rows, n=columns, mat[m x n]
  double mat[M][N];
} Tableau;

// Tableau/Tableau.c
extern void printTableau(Tableau *, const char* );
extern void readTableau(Tableau *, const char * );
extern void print_optimal_vector(Tableau *, char *);
void userInputTableau(Tableau *);

// Tableau/Pivot.c
extern void pivot_on(Tableau *, int , int );
extern int find_pivot_column(Tableau *);
extern int find_pivot_row(Tableau *, int );

// Tableau/Solver.c
extern void simplex(Tableau *);
extern int find_basis_variable(Tableau *, int);
extern void check_b_positive(Tableau *);
extern void add_slack_variables(Tableau *);
extern void nl(int);

#endif // DEFS_H
