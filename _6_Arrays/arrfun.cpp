
#include <iostream>
#include <iomanip>
#include "arrfun.h"

void passingTo( int *array, int size ) {

    std::cout << "array = " << std::setw( 17 ) << array 
        << std::setw( 25 ) << "*array = " << *array 
        << std::setw( 25 ) << "array[ 0 ] = " << array[ 0 ] << std::endl;
    if( size == 1 ) return;
    for( int i = 1; i < size; i++ ){
        std::cout << "array + " << i << " = " << array + i 
        << std::setw( 25 ) << "*( array + " << i << " )= " << *( array + i ) 
        << std::setw( 25 ) << "array[ " << i << " ] = " << array[ i ] << std::endl;
    }

}
/* void passingTo( int [ ] ){
    std::cout << "2" << std::endl;
}
void passingTo( int [ SIZE ] ){
    std::cout << "3" << std::endl;
} */
// on passing C++ compiler will always decay an array of T into a pointer to T REGARDLESS OF THE SIZE !!WARNING!!
/* 


double passingMatrixTo( double (*matrix)[ 5 ], int row, int col ) 
double passingMatrixTo( double [][ COL_N ], int, int ); */
double passingMatrixTo( double matrix[  ][ COL_N ], int row, int col ) {

    double sum = 0;
    for( int i = 0; i < row; i++ ){
        for( int j = 0; j < col; j++ ){
            sum += matrix[ i ][ j ];
        }
    }
    return sum;

}
