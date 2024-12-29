
#include <iostream>
#include <cstring>
#include "structs.h"

struct Point {
    float x, y, z;
} A, B, C;

int main() {

    Point D;
    D.x = 10; 
    D.y = 20.5; 
    D.z = 30;
    std::cout << "Point D = ( " << D.x << ", " << D.y << ", " << D.z << " )" << std::endl;
    A = D; // can assign D to A because struct has an identifier ( Point ) <-> A and D are of the same struct
    std::cout << "Assigning D -> A" << std::endl; 
    std::cout << "Point A = ( " << A.x << ", " << A.y << ", " << A.z << " )" << std::endl;
    std::cout << std::endl;

    // Example showing unnamed structs cannot be reused
    struct {
        int x, y, z;
    } unnamed1;
    unnamed1.x = 1;
    unnamed1.y = 2;
    unnamed1.z = 3;

    struct {
        int x, y, z;
    } unnamed2;
    // unnamed2 = unnamed1; // Uncommenting the following will cause a compilation error because they are not of the same type (/struct)

    // Using typedef to reuse struct definition
    typedef struct {
        int x, y, z;
    } NamedStruct;
    // Basically typedef is giving an unnamed struct an identifier

    NamedStruct named1 = { 4, 5, 6 };
    NamedStruct named2 = { 7, 8, 9 };

    std::cout << "NamedStruct named1: ( " << named1.x << ", " << named1.y << ", " << named1.z << " )" << std::endl;
    std::cout << "NamedStruct named2: ( " << named2.x << ", " << named2.y << ", " << named2.z << " )" << std::endl;
    named1 = named2;
    std::cout << "After named2 -> named1; named1: ( " << named1.x << ", " << named1.y << ", " << named1.z << " )" << std::endl;
    std::cout << std::endl;

    // Testing Register functions
    Register person = { "John Doe", 30 };

    processByValue( person );
    std::cout << "After processByValue: " << person.name << ", " << person.age << std::endl;
    processByPointer( &person );
    std::cout << "After processByPointer: " << person.name << ", " << person.age << std::endl;
    processByReference( person );
    std::cout << "After processByReference: " << person.name << ", " << person.age << std::endl;
    std::cout << std::endl;

    // Testing PrivateStruct and DerivedStruct
    PrivateStruct privateObj( 42 );
    std::cout << "PrivateStruct value: " << privateObj.getValue() << std::endl;
    privateObj.setValue( 84 );
    std::cout << "PrivateStruct updated value: " << privateObj.getValue() << std::endl;

    DerivedStruct derivedObj( 100 );
    derivedObj.displayValue();
    derivedObj.setValue( 200 );
    derivedObj.displayValue();
    
    MutableStruct mutableObj( 100, 1 );
    mutableObj.displayValue();
    mutableObj.setValue( 200 );
    mutableObj.displayAllValue();  
    mutableObj.mutateValue();    

    return 0;

}