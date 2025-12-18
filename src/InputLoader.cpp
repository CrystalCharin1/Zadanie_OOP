#include "InputLoader.h"

// Load wagons from keyboard
void InputLoader::loadFromKeyboard(Stack& stack) {
    int n;
    std::string type;

    std::cout << "Enter number of wagons: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "Enter wagon type (A/B): ";
        std::cin >> type;

        Wagon* w = WagonFactory::createWagon(type); // create wagon
        if (w) stack.push(w);
        else std::cout << "Invalid type: " << type << std::endl;
    }
}

// Load wagons from file
void InputLoader::loadFromFile(Stack& stack, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Cannot open file: " << filename << std::endl;
        return;
    }

    std::string type;
    while (file >> type) {
        Wagon* w = WagonFactory::createWagon(type); // create wagon
        if (w) stack.push(w);
        else std::cout << "Invalid type: " << type << std::endl;
    }
}
