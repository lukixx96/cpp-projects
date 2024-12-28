
#include <iostream>
#include <iomanip>
#include "arrfun.h"


int main() {

    const int size = 5;

    // acceptable declarations
    int array_1[ 5 ];
    int array_2[ DIM ];     // DIM is textually equivalent to 5 (preprocessor directive) OK
    int array_3[ size ];    // size value is known at compile time OK
    int test_1[ 5 ], test_2[ DIM ], test_3[ size ];

    // acceptable definitions
    double arr_1[ 5 ] = { 1.1, 2, 3.5, 4.01, 5.9 };
    double arr_2[ ] = { 1.1, 2, 3.5, 4.01, 5.9 };    // compiler can count the number of elements at compile time OK
    double arr_3[ size ] = { 1 };

    // accessing array elements in both writing...
    for( int i = 0; i < DIM; i++ ) 
        arr_1[ i ] *= 2;
    std::cout << std::setw( 7 ) << "Element" << std::setw( 13 ) << "Value" << std::endl;
    // ... and reading
    for( int i = 0; i < DIM; i++ )
        std::cout << std::setw( 7 ) << i << std::setw( 13 ) << arr_1[ i ] << std::endl;
    std::cout << std::endl;

    // array size
    std::cout << "arr_1[] size is " << sizeof( arr_1 )/sizeof( arr_1[ 0 ] ) << std::endl;
    std::cout << "arr_3[] size is " << sizeof( arr_3 )/sizeof( arr_1[ 0 ] ) << std::endl;
    // the dimension of sizeof depends on compile time size, not on the number of initialized values
    std::cout << std::endl;

    double matrix_1[ ROW_N ][ COL_N ];
    double matrix_2[ ROW_N ][ COL_N ] = {
        { 1.1, 2.2, 3.3, 2.2, 1.1 }, // [0][j]
        { 4.4, 5.5, 6.6, 5.5, 4.4 }, // [1][j]
        { 7.7, 8.8, 9.9, 8.8, 7.7 }  // [2][j]
    }; // C++ works by rows
    double matrix_3[ ][ COL_N ] = {
        { 1.1, 2.2, 3.3 }, // [0][j]
        { 4.4, 5.5, 6.6 }, // [1][j]
        { 7.7, 8.8, 9.9 }  // [2][j]
    }; //Only THE FIRST dimension may be omitted 
    double matrix_4[ ROW_N ][ COL_N - 2 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    // again C++ works by rows

    // accessing matrix elements in both writing...
    for( int i = 0; i < ROW_N; i++ ){
        for( int j = 0; j < COL_N; j++ ){
            matrix_1[ i ][ j ] = i + j;
        }
    }

    // ...and reading
    std::cout << "matrix_1 =" << std::endl;
    for( int i = 0; i < ROW_N; i++ ){
        for( int j = 0; j < COL_N; j++ ){
            std::cout << std::setw( 7 ) << matrix_1[ i ][ j ];
        }
        std::cout << std::endl;
    } 

    std::cout << "matrix_2 =" << std::endl;
    for( int i = 0; i < ROW_N; i++ ){
        for( int j = 0; j < COL_N; j++ ){
            std::cout << std::setw( 7 ) << matrix_2[ i ][ j ];
        }
        std::cout << std::endl;
    }

    std::cout << "matrix_3 =" << std::endl;
    for( int i = 0; i < ROW_N; i++ ){
        for( int j = 0; j < COL_N; j++ ){
            std::cout << std::setw( 7 ) << matrix_3[ i ][ j ];
        }
        std::cout << std::endl;
    }

    std::cout << "matrix_4 =" << std::endl;
    for( int i = 0; i < ROW_N; i++ ){
        for( int j = 0; j < COL_N - 2; j++ ){
            std::cout << std::setw( 7 ) << matrix_4[ i ][ j ];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // array decaing 
    double dblArr[ ] = { 8, 16, 15, 13.5, 6.3 };
    double *dblPtr = NULL;

    dblPtr = dblArr; // decaying: double * const dblArr = &dblArr[0] 
    std::cout << "dblArr = " << dblArr << std::endl;
    std::cout << "&dblArr = " << &dblArr << std::endl; // type: double (*) [5] (pointer to double arrays of size 5)
    std::cout << "&dblArr[ 0 ] = " << &dblArr[ 0 ] << std::endl;
    std::cout << "dblPtr = " << dblPtr << std::endl;
    std::cout << "&dblArr[ 2 ] = " << &dblArr[ 2 ] << std::endl;
    std::cout << "dblPtr + 2 = " << dblArr + 2 << std::endl;
    std::cout << "dblPtr = dblArr => dblPtr + i <-> dblArr + i <-> &dblArr[ i ]" << std::endl;

    double (* sizedArrPtr )[ ] = &dblArr;
    std::cout << std::endl;

    int intArr[ ] = { 1, 2, 55, 6, 77, 8, 7 };
    int sizeArr = sizeof( intArr )/sizeof( intArr[ 0 ] );
    std::cout << "Passing array to function" << std::endl;
    passingTo( intArr, sizeArr );
    std::cout << std::endl;

    // matrix decaying: matrix[R][C] is a 1D array of R elements => double (* const matrix)[C] = &matrix[0]
    // the 1st dimension only decays AND A POINTER DOESNT DECAY!!
    std::cout << "Passing matrix to function: sum of element is "
        << passingMatrixTo( matrix_2, ROW_N, COL_N ) << std::endl; // -> decays into double (*) [5] (see .cpp, .h)

    // Since pointers dont decay, when allocating dynamic N-dim arrays a N-pointer should be passed       

    return 0;

}