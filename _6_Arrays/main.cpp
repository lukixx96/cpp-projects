
#include <iostream>
#include <iomanip>

#define DIM 5

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

    return 0;

}