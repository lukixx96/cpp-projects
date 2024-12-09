
#include <iostream>
//#include <cstring> // std namespace
#include <string.h> // global namespce -> no qualificator:: needed
#include "header.h"

#define DIM 100
#define MAX 3

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
    strcpy( inputStr, "Stringa1" );//std::cin >> inputStr;
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
    strcpy( inputCharPtr, "Stringa2" ); //std::cin >> inputCharPtr;
    for( int i = 0; i < DIM; i++ ){
        if( inputCharPtr[ i ] == '\0' ) {
            std::cout << "Terminator \'\\0\' found" << std::endl;
            break;
        }
    }
    std::cout << "inputCharPtr: " << inputCharPtr 
        << ", *( inputCharPtr + 1 ): " << *( inputCharPtr + 1 ) << std::endl; 
    // *( inputCharPtr + 1 ) ritorna il secondo carattere (dereferenziazione del 2 elemento puntato dall'arr)
    delete [] inputCharPtr;

    char *testCharPtr = "HelloWorld"; // -> warning since ISO C++ forbids converting a string constant to 'char*'
    const char *testCharPtr2 = "HelloWorld"; // ok!
    std::cout << std::endl;

    // per il significato del const leggi da dx verso sx:
    char base[ MAX ] = "Hi";
    char *basePtr = base;

    // puntatore a char costante (AKA stringa C-Style) ->
    const char *constBasePtr = base;
    std::cout << "constBasePtr: " << constBasePtr;
    // -> POSSO riassegnare
    constBasePtr = greeting;
    std::cout << " => " << constBasePtr << std::endl;
    // -> NON POSSO modificare il contenuto puntato mediante dereferenziazione
    // *( constBasePtr + 1 ) = 'o'; -> compile error: assignment to read-only location

    // puntatore costante a char ->
    char *const baseConstPtr = base;
    std::cout << "baseConstPtr: " << baseConstPtr;
    // -> POSSO modificare il contenuton puntato mediante dereferenziazione
    *( baseConstPtr + 1 ) = 'o';
    std::cout << " => " << baseConstPtr << std::endl;
    // -> NON POSSO riassegnare
    // baseConstPtr = greeting; -> compile error: assignment to read-only location
    std::cout << std::endl;

    // array of MAX pointers to char costant (AKA array di stringhe C-Style)
    const char *arrOf_CharPtr[MAX] = { "hello", "world", "cinque" }; // a fourth string (4>MAX) results in compiler error
    char *arrOf_nonconst_CharPtr[MAX] = { "hello", "world", "cinque" };
    // ^ non-constant throws a warning because "ISO C++ forbids converting a string constant to 'char*'"
    // a warning for each string, since each of them is going to be converted to 'char*'
    std::cout << "arrOf_CharPtr: {";
    for( int i = 0; i < MAX; i++ ){
       if( !( i == MAX - 1 ) ) std::cout << arrOf_CharPtr[i] << ",";
       else std::cout << arrOf_CharPtr[i];
    }
    std::cout << "}" << std::endl;
    // since it is a array of strings and not a string, printing the handler result in array decay
    std::cout << "arrOf_CharPtr = " << arrOf_CharPtr << std::endl << std::endl;

    // pointer to (a whole) array of MAX char constants
    const char ( *ptr_ArrayOfChar )[MAX] = &"hi"; //error: "hii" or "h"
    //"hii" is a const char [4] while &"hii" is a const char (*)[4]: 
    // 1. const is needed in declaration because it refers to pointed value which is const;
    // 2. MAX and litteral dimension must be EXACTLY EQUAL, neither bigger nor smaller.
    // this clarifies '&' operator: &x returns a pointer to the same type of x, thus if x is 'int []' &x is 'int (*)[]'
    std::cout << "ptr_ArrayOfChar: " << ptr_ArrayOfChar << " -> " << *ptr_ArrayOfChar << std::endl;
    // *ptr_ArrayOfChar is a const char [MAX] which  

    // like strings, when initializing, the compiler has information to know the correct dimension so it is possible:
    const char ( *ptr_ArrayOfChar_nodim )[] = &"Many Chars You Want";
    std::cout << "ptr_ArrayOfChar_nodim: " << ptr_ArrayOfChar_nodim << " -> " << *ptr_ArrayOfChar_nodim << std::endl;
    std::cout << std::endl;

/*     const char *(*ptr_CharPtr) = (const char**)&"hi";
    std::cout << ptr_CharPtr << " -> " << *ptr_CharPtr << " -> " << **ptr_CharPtr << std::endl;

    ----> unpredictable behaviors

    DOES NOT MAKE SENSE: &"hi" is not a const char **
    Think of a const char (*)[3] as a box containing a row of three letters, while a const char ** is a box containing 
    a note with the address of another box. You cannot directly treat a box of letters as a box of addresses—they 
    represent fundamentally different layouts.
    The incompatibility arises because:
    Type mismatch: A const char (*)[3] points to an array of exactly 3 const char, while a const char ** points 
    to a const char * (a pointer to a single character). The memory layout and interpretation are entirely different.
    Dereferencing issues: Treating a const char (*)[3] as a const char ** and dereferencing it would interpret the data 
    incorrectly, leading to undefined behavior. */

    // with <string.h> -> no need of std::<string_function>
    char str1[] = "Hello";
    char str2[] = "World";
    char str3[ DIM ];

    strcpy( str3, str1 ); // copied str1 into str3 <-> ASSIGNMENT STR3 = STR1
    std::cout << "str1 copied into str3: " << str3 << std::endl;

    strcat( str3, str2 ); // concatenates str2 to str3 and modifies str3 <-> STR3 = STR3 + STR2
    std::cout << "str2 concatenated to str3: " << str3 << std::endl;

    int length3 = strlen( str3 );
    std::cout << "str3 length: " << length3 << std::endl;

    int more11, more31, more13;
    strcpy( str1, "HelLo" );
    std::cout << "new str1: " << str1 << " -> ";
    more11 = strcmp( str1, str1 );  // compares 2 string and returns 0 if their are the same or
    more13 = strcmp( str1, str3 );  // 1 (int)leftStr[i] > (int)rightStr
    more31 = strcmp( str3, str1 );  // -1 (int)leftStr[i] < (int)rightStr
    std::cout << "\n\tstr1 > str1 ? " << more11 << " \t<->\t str1 == str1" 
        << "\n\tstr1 > str3 ? " << more13 << " \t<->\t NO ( because (int)L < (int)l )"
        << "\n\tstr3 > str1 ? " << more31 << " \t<->\t YES ( because (int)L < (int)l )" << std::endl;

    char *firstCharOcc, *firstStrOcc;
    firstCharOcc = strchr( str3, 'l' );
    firstStrOcc = strstr( str3, "loW" );
    std::cout << "firstCharOcc of 'l': " << firstCharOcc << std::endl;
    std::cout << "firstStrOcc of \"loW\": " << firstStrOcc << std::endl;
    firstCharOcc = strchr( str3, 'M' );
    firstStrOcc = strstr( str3, "low" );
    if( firstCharOcc == NULL ) std::cout << "firstCharOcc of 'M': NULL" << std::endl;
    if( firstStrOcc == 0 ) std::cout << "firstStrOcc of \"low\": NULL" << std::endl;

    std::cout << std::endl << std::endl;
    string_procedure();

    return 0;

}