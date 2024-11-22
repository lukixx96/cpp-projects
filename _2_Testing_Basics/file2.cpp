
#include <iostream>
#include "header.h"

void func2() {
    
    if( sharedMem < 15 ) std::cout << "shm < 15" << std::endl;
    else  std::cout << "shm > 15" << std::endl;

}