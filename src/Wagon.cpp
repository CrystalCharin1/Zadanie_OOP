#include "Wagon.h"

Wagon::Wagon(const std::string t) : type(t) {} // constructor

std::string Wagon::getType() const { return type; } // return wagon type
