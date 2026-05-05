#include "Pet.h"
#include <iostream>

void Pet::feed()  {
    std::cout << ">> You give the pet a snack!" << std::endl;
    _hunger -= 15;
    if (_hunger < 0) _hunger = 0;
}

void Pet::play() {
    std::cout << ">> You play catch! The pet is happy." << std::endl;
    _happiness += 10;
    _hunger += 5;
}

bool Pet::isAlive() {
    return _hunger < 100;
}