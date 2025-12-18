#include "Wagon.h"

Wagon::Wagon(const std::string t) : type(t) {} // Конструктор

std::string Wagon::getType() const { return type; } // геттер типа вагона
