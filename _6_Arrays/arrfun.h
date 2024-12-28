
#ifndef ARRFUN_H
#define ARRFUN_H

#define DIM 5
#define ROW_N 3
#define COL_N 5


void passingTo( int *, int );
/* void passingTo( int [ ] );
void passingTo( int [ SIZE ] ); */

double passingMatrixTo( double [][ COL_N ], int, int );
/* double passingMatrixTo( double (*)[ COL_N ], int, int );
double passingMatrixTo( double [ ROW_N ][ COL_N ], int, int ); */

#endif