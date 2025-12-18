#ifndef WAGONFACTORY_H
#define WAGONFACTORY_H

#include "Wagon.h"
#include <string>

class WagonFactory {
public:
	static Wagon* createWagon(const std::string& type);
};

#endif 
