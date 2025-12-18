#include "WagonFactory.h"

// Фабричный метод для создания вагонов
Wagon* WagonFactory::createWagon(const std::string& type) { 
	if (type == "A" || type == "B") {
		return new Wagon(type);
	}

	return nullptr;
}