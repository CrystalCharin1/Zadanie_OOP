#include "InputLoader.h"

// Ввод вагонов с клавиатуры
void InputLoader::loadFromKeyboard(Stack& stack) {
    int n;
    std::string type;

    std::cout << "Введите кол-во вагонов: ";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "Введите тип вагона (A/B): ";
        std::cin >> type;

        Wagon* w = WagonFactory::createWagon(type); // фабричный метод
        if (w) stack.push(w);
        else std::cout << "Неизвестный тип: " << type << std::endl;
    }
}

// Ввод вагонов из файла
void InputLoader::loadFromFile(Stack& stack, const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Не удалось открыть файл: " << filename << std::endl;
        return;
    }

    std::string type;
    while (file >> type) {
        Wagon* w = WagonFactory::createWagon(type); // фабричный метод
        if (w) stack.push(w);
        else std::cout << "Неизвестный тип: " << type << std::endl;
    }
}