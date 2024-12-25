
#include <iostream>
#include "test.h"
#include "test2.h"


void switch_by_value( int, int );
void switch_by_pointer( int *, int * );
void switch_by_reference( int&, int& );

// the defualt parameters must be contiguos from the right in the definition
int trisum_default_2( int, int = 0, int = 7 );
int trisum_default_3( int, int, int = 0 );

// variable number of parameters
// Variadic template function ( C++11 ) **see body
template< typename... Args >
void printNumbers( Args... args ); 

void printNumbersHEADRecursive( int );
void printNumbersTAILRecursive( int );
int fibonacci( int );

bool isEven( int ); // prototyping 'isEven' only: 'isOdd' is masked to final user of hypothetical header file
int ackermann( int, int );



int main(){

    int a,b;
    
    a = 25, b = 100;
    switch_by_value( a, b );
    std::cout << "outside switch_by_value: a = " << a << ", b = " << b << std::endl << std::endl;

    a = 25, b = 100;
    switch_by_pointer( &a, &b );
    std::cout << "outside switch_by_pointer: *a = " << a << ", *b = " << b 
        << " and a = " << &a << ", b = " << &b << std::endl << std::endl;

    a = 25, b = 100;
    switch_by_reference( a, b );
    std::cout << "outside switch_by_reference: a = " << a << ", b = " << b << std::endl << std::endl;

    int c = 10;
    int sum2 = 0, sum3 = 0;
    
    sum2 = trisum_default_2( a, b, c );
    std::cout << "( #0 default )trisum_default_2 = " << sum2 << std::endl;
    sum2 = trisum_default_2( a, b );
    std::cout << "( #1 default )trisum_default_2 = " << sum2 << std::endl;
    sum2 = trisum_default_2( a );
    std::cout << "( #2 default )trisum_default_2 = " << sum2 << std::endl << std::endl;

    sum3 = trisum_default_3( a, b, c );
    std::cout << "( #0 default )trisum_default_3 = " << sum3 << std::endl;
    sum3 = trisum_default_3( a, b );
    std::cout << "( #1 default )trisum_default_3 = " << sum3 << std::endl << std::endl;

    std::cout << "( 1 )printNumbers: ";
    printNumbers( sum2 );
    std::cout << "( 2 )printNumbers: ";
    printNumbers( sum2, sum3 );
    std::cout << "( 3 )printNumbers: ";
    printNumbers( sum2, sum3, "prova" ); // test
    std::cout << std::endl;

    std::cout << "[DIRECT] RECURSION" << std::endl;
    std::cout << "printNumbersHEADRecursive( 5 ): ";
    printNumbersHEADRecursive( 5 );
    std::cout << std::endl; 
    std::cout << "printNumbersTAILRecursive( 5 ): ";
    printNumbersTAILRecursive( 5 );
    std::cout << std::endl; 
    std::cout << "fibonacci( 10 ): " << fibonacci( 10 ) << std::endl;
    std::cout << std::endl;     

    std::cout << "[INDIRECT] RECURSION" << std::endl;
    std::cout << "isEven( 11 ): " << std::boolalpha << isEven( 11 ) << std::endl;
    std::cout << "isEven( 14 ): " << std::boolalpha << isEven( 14 ) << std::endl;
    int m = 2, n = 3;
    std::cout << "Ackermann( " << m << ", " << n << " ) = " << ackermann( m, n ) << std::endl;
    std::cout << std::endl; 

    std::cout << "REFERENCE RETURNING FUNCTION" << std::endl;
    std::cout << "(main.cpp scoped) globalVar = " << globalVar << std::endl;
    globalVar = 15;
    std::cout << "(main.cpp scoped) new assignment: globalVar = " << globalVar << std::endl;
    std::cout << "(in main.cpp by reference to test.cpp scoped) globalVar = "; 
    printGlobalVar() = 20; // Using int& returning function as left hand side
    std::cout << "(in main.cpp by reference to test.cpp scoped) new assignment: globalVar = ";
    printGlobalVar();
    std::cout << std::endl;
    // by means of reference-returning function a static global variable can be shared and modified

    std::cout << "POINTER RETURNING FUNCTION" << std::endl;
    std::cout << "(main.cpp scoped) globalVar = " << globalVar << std::endl;
    globalVar = 35;
    std::cout << "(main.cpp scoped) new assignment: globalVar = " << globalVar << std::endl;
    std::cout << "(in main.cpp by reference to test.cpp scoped) globalVar = ";
    *ptrGlobalVar() = 60;
    //printGlobalVar() = 20; // Using int& returning function as left hand side
    std::cout << "(in main.cpp by reference to test.cpp scoped) new assignment: globalVar = ";
    *ptrGlobalVar();
    std::cout << std::endl;
    // by means of pointer-returning function a static global variable can be shared and modified

    std::cout << "OVERLOAD" << std::endl;
    overloads( 1 );
    overloads( 1.1 );
    overloads( 1, 2 );
    overloads( 1, 2.1 );
    overloads( 1.1, 2 );
    overloads( 1.1f );
    std::cout << std::endl;

    std::cout << "OVERRIDING" << std::endl;
    Shape *shapePtr;
    Shape shape;
    Circle circle;
    Square square;

    std::cout << "Calling draw() by derived objects" << std::endl;
    circle.draw();
    square.draw();

    std::cout << "Calling draw() by base objects" << std::endl;
    shape = square;
    shape.draw();    
    shape = circle;
    shape.draw();
 
    std::cout << "Calling draw() by base pointers" << std::endl;
    shapePtr = &square;
    shapePtr->draw();
    shapePtr = &circle;
    shapePtr->draw();

    return 0;

}

void switch_by_value( int a, int b ){

    int temp = a;
    a = b;
    b = temp;
    std::cout << "inside switch_by_value: a = " << a << ", b = " << b << std::endl;

}

void switch_by_pointer( int *a, int *b ){

    //the following changes pointers direction of pointing, but at return the locals are destroyed
    /*
    int *temp = a;
    a = b;
    b = temp;
    */ 

    //to make it work the pointed content need to be changed rather then pointing direction
    int temp = *a;
    *a = *b;
    *b = temp;

    std::cout << "inside switch_by_pointer: *a = " << *a << ", *b = " << *b 
        << " and a = " << a << ", b = " << b << std::endl;

}

void switch_by_reference( int& a, int& b ){

    int temp = a;
    a = b;
    b = temp;
    std::cout << "inside switch_by_reference: a = " << a << ", b = " << b << std::endl;

}

// int trisum_default_2( int a, int b = 0, int c ){ 
int trisum_default_2( int a, int b, int c ){

    return a + b + c;

}

int trisum_default_3( int a, int b, int c ){

    return a + b + c;

}

// Variadic template function
template< typename... Args >
void printNumbers( Args... args ) {

    bool first = true;
    ( ( std::cout << ( first ? ( first = false, "" ) : ", " ) << args ), ... ) << std::endl; // fold expression ( C++17 )

}

// Linear recursion: each function generates exactly ONE recursive call
void printNumbersHEADRecursive( int n ) {

    if ( n > 0 ) {

        printNumbersHEADRecursive( n - 1 );  // Recursive call first
        std::cout << n << " ";     // Processing after recursive call

    }

}

void printNumbersTAILRecursive( int n ) {

    if ( n > 0 ) {

        std::cout << n << " "; // Processing before recursive call
        printNumbersTAILRecursive( n - 1 );  // Recursive call last

    }

}

// NonLinear recursion
int fibonacci( int n ) {

   if( n <= 1 ) return n;
   return fibonacci( n - 1 ) + fibonacci( n - 2 ); // More then one recursive call

}

bool isOdd( int n ){

    if( n == 0 ) return false;
    else return isEven( n - 1 );

}

bool isEven( int n ){

    if( n == 0 ) return true;
    else return isOdd( n - 1 );

}

// Funzione di Ackermann
int ackermann( int m, int n ) {

    if ( m == 0 ) return n + 1;
    else if ( m > 0 && n == 0 ) return ackermann( m - 1, 1 ); // Ricorsione semplice
    else return ackermann( m - 1, ackermann( m, n - 1 ) ); // Ricorsione innestata
    
}