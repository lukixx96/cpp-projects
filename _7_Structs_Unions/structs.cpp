
#include <string>
#include <iostream>
#include "structs.h"

// Function implementations
void processByValue( Register person ) {
    std::cout << "Processing by value: " << person.name << ", " << person.age << std::endl;
    person.age += 1; // Modifies only the local copy
}

void processByPointer( Register* person ) {
    if ( person ) { // !!!VERY IMPORTANT: ALWAYS CHECK POINTER IS POINTING!!!
        std::cout << "Processing by pointer: " << person->name << ", " << person->age << std::endl;
        person->age += 1; // Modifies the original object via pointer
    }
}

void processByReference( Register& person ) {
    std::cout << "Processing by reference: " << person.name << ", " << person.age << std::endl;
    person.age += 1; // Modifies the original object via reference
}

void MutableStruct::mutateValue() const {
            mutableValue++;
            std::cout << "Derived value: " << getValue() << ", Mutated value: " << getMutableValue() << std::endl;
        } // Although the method is declared to work without modifying members, actually it can modify mutable members
