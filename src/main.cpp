#include "Sorting.h"
#include "Menu.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
	setlocale(LC_ALL, "Russian"); // Поддержка русского языка
	Sorting sorting;
	int choice;

	//Цикл работает пока не вернётся False(0)
	while (true) {
		displayMenu();
		std::cout << "Введите номер действия: " << std::endl;
		std::cin >> choice;

		switch (choice) {
		case 1:
			system("cls"); //Чистка терминала
			sorting.loadFromKeyboard(sorting);
			sorting.process(); // сортировка
			system("cls");
			break;
		case 2:
			system("cls");
			sorting.loadFromFile(sorting, "in.txt");
			sorting.process();
			system("cls");
			break;
		case 3:
			system("cls");
			sorting.display();
			std::this_thread::sleep_for(std::chrono::seconds(5));
			system("cls");
			break;
		case 4:
			return 0;
		}
	}
}