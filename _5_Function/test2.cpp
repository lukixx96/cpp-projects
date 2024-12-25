
#include <iostream>
#include "test2.h"

void Shape::draw() const {
    std::cout << "Drawing a Shape" << std::endl;
}

void Circle::draw() const {
    std::cout << "Drawing a Circle" << std::endl;
}

void Square::draw() const {
    std::cout << "Drawing a Square" << std::endl;
}