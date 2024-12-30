#ifndef UNIONS_H
#define UNIONS_H

#include <string>
#include <iostream>
#include <cstring> // For memcpy

// Basic union declaration
union BasicUnion {
    int intValue;
    float floatValue;
    char charArray[20]; // Large enough to explore memory usage
};

// Function declarations
void printUnionSize();
void demonstrateAccess();
void passUnionByValue( BasicUnion u );
void passUnionByReference( BasicUnion& u );
void passUnionByPointer( BasicUnion* u );
void demonstrateUndefinedBehavior(); // Decomment in unions.cpp to force errors
void demonstrateAnonymousUnion();
void demonstrateUnionLikeClass();

#endif // UNIONS_H
