#include "WagonFactory.h"

// Factory method for creating wagons by type
Wagon* WagonFactory::createWagon(const std::string& type) { 
	if (type == "A" || type == "B") {
		return new Wagon(type);
	}

	return nullptr;
}
