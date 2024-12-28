
#include <iostream>
#include <iomanip>
#include <ctime>
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

/* double passingMatrixTo( double (*matrix)[ 5 ], int row, int col ) 
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


// functions MAY NOT return arrays ( [] ), just pointers
int* returningStaticArray() {

    static int arr[ ROW_N ];
    srand( ( unsigned ) time( NULL ) );
    for( int i = 0; i < ROW_N; i++ ) arr[ i ] = rand();
    return arr; // it's ok because arr will decay into a pointer

}

void printStaticArray( int *arr ) {

    std::cout << "{ ";
    for( int i = 0; i < ROW_N - 1; i++ ) {
        std::cout << arr[ i ] << ", ";
    }
    std::cout << arr[ ROW_N - 1 ] << " }"; 

}

ArrayCOL* returningStaticMatrix() { // in this case it's ok because returning a pointer independently of to what

    static ArrayCOL mat[ ROW_N ];
    srand( ( unsigned ) time( NULL ) );
    for( int i = 0; i < ROW_N; i++ ) 
        for( int j = 0; j < COL_N; j++ )
            mat[ i ][ j ] = rand();
    return mat;

}

void printStaticMatrix( ArrayCOL* mat ) {

    std::cout << "{\n";
    for (int i = 0; i < ROW_N; i++) {
        std::cout << "  { ";
        for (int j = 0; j < COL_N; j++) {
            std::cout << std::setw(5) << mat[i][j]; // Allinea i numeri in colonne larghe 5
            if (j < COL_N - 1) {
                std::cout << ", ";
            }
        }
        std::cout << " }";
        if (i < ROW_N - 1) {
            std::cout << ",";
        }
        std::cout << "\n";
    }
    std::cout << "}";

}
