#ifndef STACK_H
#define STACK_H
#define MAX_SIZE 100

#include "Wagon.h"

class Stack {
protected:
	Wagon* data[MAX_SIZE];
	int top;
public:
	Stack();
	~Stack();
	bool isEmpty() const;
	bool isFull() const;
	void push(Wagon* w);
	Wagon* pop();
};

#endif
