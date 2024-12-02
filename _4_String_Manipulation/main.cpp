
#include <iostream>

#define DIM 100

int main() {

    // C-Style strings are char arrays where last char is '\0':
    char greeting[ 6 ] = { 'H', 'e', 'l', 'l', 'o', '\0' }; // '\0' is manually put as last element 
    char greeting2[] = "Hello2";   // compiler automatically puts the null character to string literals end
    // compiler has all the infos to calculate how many elements the arrays have at compile time so it is allowed "[]"
    // the C-Style strings are treated differently in '<<' and '>>' stream operations and recognized in cstring implementation
    int vector[] = { 1, 2, 3, 4 };

    char *charPtr = greeting;
    int *intPtr = vector;

    std::cout << "vector: " << vector << std::endl; // DECAYS: compiler treats a int vector as a int* to first element
    std::cout << "greeting: " << greeting << std::endl; // Does not decay because it prints the content and not the address of 1st elem
    std::cout << "greeting2: " << greeting2 << std::endl;
    std::cout << "intPtr:" << intPtr << std::endl;
    std::cout << "charPtr: " << charPtr << std::endl;
    /*  
    char notstr[2] = { 'H', 'i' }; // does not have '\0' so it is not C-Style string -> its cout << wont print "Hi"
    charPtr = notstr;
    std::cout << "notstr: " << notstr << std::endl; 
    */ //commented as it has impredictable behavior 

    std::cout << "charPtr - truncated: " << &greeting[ 1 ] << std::endl;
    // &char is lvalue for a char* so it is treated as C-Style string (compiler treats &greeting[0] as char*)
    // if i wanted to print the address of the first element i should do a static cast:
    // std::cout << static_cast< const void* >( &greeting[ 0 ] ) << std::endl;
    std::cout << std::endl;

    char inputStr[ DIM ];
    std::cin >> inputStr;
    for( int i = 0; i < DIM; i++ ){
        if( inputStr[ i ] == '\0' ) {
            std::cout << "Terminator \'\\0\' found" << std::endl;
            break;
        }
    } 
    //eqv without break:
    /*     
    int i = 0;
    while( i < DIM && prova[ i ] != '\0' ) {
        i++;
    }
    if( prova[ i ] == '\0' ) std::cout << "Terminator \'\\0\' found" << std::endl;
    */
    std::cout << "inputStr: " << inputStr << std::endl << std::endl;


    char *inputCharPtr = new char[ DIM ]; //per inserire una stringa da tastiera devo avere memoria allocata
    // OSS: è allocazione dinamica ma inutile perchè DIM è conosciuto a tempo di compilazione
    // std::cin >> *inputCharPtr; // se lascio così sto derefernziando, quindi sto puntando al primo elemento
    std::cin >> inputCharPtr;
    for( int i = 0; i < DIM; i++ ){
        if( inputCharPtr[ i ] == '\0' ) {
            std::cout << "Terminator \'\\0\' found" << std::endl;
            break;
        }
    }
    std::cout << "inputCharPtr: " << inputCharPtr 
        << ", *( inputCharPtr + 1 ): " << *( inputCharPtr + 1 ) << std::endl; 
    // *( inputCharPtr + 1 ) ritorna il secondo carattere (dereferenziazione del 2 elemento puntato dall'arr)

    char *testCharPtr = "Hello"; // -> warning since ISO C++ forbids converting a string constant to 'char*'
    const char *testCharPtr2 = "Hello"; // ok!

    return 0;

}