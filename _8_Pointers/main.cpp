
#include <iostream>
#include <ctime>
#include <iomanip>
#include "ptrfun.h"

#define DIM 20
#define MAX 3


int main() {

    int *intPtr = NULL; 
    if( intPtr ) std::cout << "intPtr is not NULL" << std::endl;
    else std::cout << "intPtr is NULL" << std::endl;
    std::cout << std::endl;

    srand( ( unsigned ) time( NULL ) );
    int intArr[ DIM ];
    for( int i= 0; i < DIM; i++ ) intArr[ i ] = rand();
    intPtr = &intArr[ 7 ];
    std::cout << std::setw( 7 ) << "Element" << std::setw( 13 ) << "Value" << std::endl;
    for( int i = 0; i < DIM; i++ )
        std::cout << std::setw( 7 ) << i << std::setw( 13 ) << intArr[ i ] << std::endl;
    std::cout << std::endl;
    std::cout << "intPtr points to position 7 -> intPtr = " << intPtr << ", *intPtr = " << *intPtr << std::endl;

    // Pointer arithmetics
    int k = 5;
    intPtr++;
    std::cout << "intPtr++ -> intPtr = " << intPtr << ", *intPtr = " << *intPtr << std::endl;
    intPtr += k;
    std::cout << "intPtr+=" << k << " -> intPtr = " << intPtr << ", *intPtr = " << *intPtr << std::endl;
    intPtr--;
    std::cout << "intPtr-- -> intPtr = " << intPtr << ", *intPtr = " << *intPtr << std::endl;
    intPtr -= k; 
    std::cout << "intPtr-=" << k << " -> intPtr = " << intPtr << ", *intPtr = " << *intPtr << std::endl;
    std::cout << std::endl;

    // Pointer comparison
    int *cmpPtr = intArr; // eqv = &intArr[ 0 ]
    for( int i = 0; i < DIM; i++ ) {

        std::cout << "cmpPtr -> [" << i << "], intPtr -> [7] => ";
        if( cmpPtr < intPtr ) std::cout << "cmpPtr < intPtr" << std::endl;
        else if( cmpPtr == intPtr ) std::cout << "cmpPtr == intPtr" << std::endl;
        else std::cout << "cmpPtr > intPtr" << std::endl;
        cmpPtr++;

    }
    std::cout << std::endl;

    // Arrays VS Pointers
    // int intArr[ DIM ]; intArr decays into "int * const intArr = &intArr[0]" so...
    int *newPtr = ( intArr + 1 ); // ... this is acceptable ( arithmetic without updating )
    int temp = *newPtr; // backup previous value
    *( intArr + 1 ) = 0; // ... this is acceptable ( arithmetic without updating and modifying dereferenced value )
    // intArr++; // ... this is NOT accepatble since intArr decays to a constant pointer ( pointing direction cannot be changed )
    *( intArr + 1 ) = temp; 

    // Array of Pointers
    const char* names[ MAX ] = { "First", "Second", "Third" }; // can have different-length strings
    for( int i = 0; i < MAX; i++ ) {
        std::cout << "Value of names[ " << i << " ] = ";
        std::cout << ( names + i ) << std::endl;
    }
    std::cout << std::endl;

    // Pointers to Pointers: Multiple Indirection
    int *tempPtr = &temp;
    int **tempPtrPtr = &tempPtr;
    std::cout << "tempPtrPtr -> " << *tempPtrPtr << " -> [1]:" << **tempPtrPtr << std::endl;
    std::cout << std::endl;

    // Pointer as input parameter
    double dblVal = 0.1*rand();
    double *dblPtr = &dblVal;
    std::cout << "dblPtr -> " << *dblPtr << std::endl;
    std::cout << "Select a value: "; 
    double newDblVal;
    std::cin >> newDblVal;
    passByPtr( dblPtr, newDblVal );
    std::cout << "now dblPtr -> " << *dblPtr << std::endl;
    double dblArr[ MAX ];
    for( int i = 0; i < MAX; i++ ) dblArr[ i ] = rand();
    std::cout << "dblArr = { ";
    for( int i = 0; i < MAX - 1; i++ ) std::cout << dblArr[ i ] << ", ";
    std::cout << dblArr[ MAX - 1 ] << " }" << std::endl;
    std::cout << "Select an index: ";
    int index = 0;
    std::cin >> index;
    passByPtr( dblArr, newDblVal, index, MAX );
    std::cout << "new dblArr = { ";
    for( int i = 0; i < MAX - 1; i++ ) std::cout << dblArr[ i ] << ", ";
    std::cout << dblArr[ MAX - 1 ] << " }" << std::endl;
    std::cout << std::endl;

    // Pointer as return
    double *rtnPtr;
    rtnPtr = returnPtr( 0.01 );
    std::cout << "returned value at 0.01 scaling factor: " << *rtnPtr << std::endl;
    rtnPtr = returnPtr( 0.01, 1 );
    std::cout << "returned array at 0.01 scaling factor: { ";
    for( int i = 0; i < 9; i++ ) std::cout << *( rtnPtr + i ) << ", ";
    std::cout << *( rtnPtr + 9 ) << " }" << std::endl;

    return 0;

}