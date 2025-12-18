#include "WagonFactory.h"
#include "Sorting.h"
#include <iostream>
#include <fstream>

// Сортировка вагонов
void Sorting::process() {
	while (!isEmpty()) {
		Wagon* w = this->pop();

		if (w->getType() == "A") {
			trackA.push(w);
		}
		else {
			trackB.push(w);
		}
	}
}

void Sorting::display() {
	std::cout << "Вагоны на треке A:" << std::endl;
	while (!trackA.isEmpty()) {
		Wagon* w = trackA.pop();
		std::cout << w->getType() << " " ;
		delete w;
	}

	std::cout << "\nВагоны на треке B:" << std::endl;
	while (!trackB.isEmpty()) {
		Wagon* w = trackB.pop();
		std::cout << w->getType() << " ";
		delete w;
	}
	std::cout << std::endl;
}