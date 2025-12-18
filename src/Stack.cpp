#include "Stack.h"
#include <iostream>

// Конструктор
Stack::Stack() : top(-1) {}

// Деструктор
Stack::~Stack() {
	while (!isEmpty()) {
		pop();
	}
}
bool Stack::isEmpty() const { return top == -1; } // Проверка на пустоту стека

bool Stack::isFull() const { return top == MAX_SIZE - 1; } // Проверка на заполненность стека

// Добавление вагона в стек
void Stack::push(Wagon* w) {
	if (isFull()) {
		std::cout << "Стек заполнен. Невозможно добавить вагон - " << w->getType() << std::endl;
	}
	else {
		data[++top] = w;
	}
}

// Удаление вагона из стека
Wagon* Stack::pop() {
	if (isEmpty()) {
		std::cout << "Стек пустой!!" << std::endl;
		return nullptr;
	}
	else {
		return data[top--];
	}
}