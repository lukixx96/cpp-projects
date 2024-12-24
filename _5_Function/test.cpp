
#include <iostream>
#include "test.h"

//int globalVar;

int& printGlobalVar() {

    std::cout << globalVar << std::endl;
    return globalVar;

}

int *ptrGlobalVar() {

    std::cout << globalVar << std::endl;
    return &globalVar;

}

int overloads( int ) {

    std::cout << "Intero" << std::endl;
    return -1;

}

int overloads( double ) {

    std::cout << "Double" << std::endl;
    return -1;

}

int overloads( int, int ) {

    std::cout << "Intero e Intero" << std::endl;
    return -1;

}

int overloads( int, double ) {

    std::cout << "Intero e Double" << std::endl;
    return -1;

}

int overloads( double, int ) {

    std::cout << "Double e Intero" << std::endl;
    return -1;

}

/* float overloads( int ){
    return 1.1;
} */

float overloads( float ){

    std::cout << "Float" << std::endl;
    return 1.1;

}