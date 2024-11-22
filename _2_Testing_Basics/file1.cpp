
#include <iostream>
#include "header.h"

int sharedMem = 10;

void func1( int inc ) {
    sharedMem = sharedMem + inc;
}