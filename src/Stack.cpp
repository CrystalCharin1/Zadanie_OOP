#include "Stack.h"
#include <iostream>

// Constructor
Stack::Stack() : top(-1) {}

// Destructor
Stack::~Stack() {
	while (!isEmpty()) {
		pop();
	}
}
bool Stack::isEmpty() const { return top == -1; } // Check if stack is empty

bool Stack::isFull() const { return top == MAX_SIZE - 1; } // Check if stack is full

// Push wagon into the stack
void Stack::push(Wagon* w) {
	if (isFull()) {
		std::cout << "Stack is full. Cannot push wagon - " << w->getType() << std::endl;
	}
	else {
		data[++top] = w;
	}
}

// Pop wagon from the stack
Wagon* Stack::pop() {
	if (isEmpty()) {
		std::cout << "Stack is empty!!" << std::endl;
		return nullptr;
	}
	else {
		return data[top--];
	}
}
