#include "Sorting.h"
#include "Menu.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
	Sorting sorting;
	int choice;

	// Main program loop (runs until exit)
	while (true) {
		displayMenu();
		std::cout << "Enter menu choice: " << std::endl;
		std::cin >> choice;

		switch (choice) {
		case 1:
			system("cls"); // clear console
			sorting.loadFromKeyboard(sorting);
			sorting.process(); // process sorting
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
