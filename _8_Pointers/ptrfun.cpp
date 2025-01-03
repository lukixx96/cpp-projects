
#include <iostream>
#include <ctime>
#include "ptrfun.h"


double passByPtr( double *ptr, double newVal ) {

    if( !ptr ) return -1;
    *ptr *=  newVal;
    return *ptr;

}

double passByPtr( double *ptr, double newVal, int index, int DIM ) {

    if( index < 0 || index >= DIM ) return -1;
    *( ptr + index ) = newVal;
    return -1;

}

double *returnPtr( double scalingFactor ) {

    static double value  =  scalingFactor*rand();
    return &value;

}

double *returnPtr( double scalingFactor, int isArray ) {
    
    if( !isArray ) return NULL;
    static double array[ 10 ];
    for( int i = 0; i < 10; i++ ) array[ i ] = scalingFactor*rand();
    return array;

}