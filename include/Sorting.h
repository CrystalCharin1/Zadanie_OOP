#ifndef SORTING_H
#define SORTING_H

#include "Stack.h"
#include "InputLoader.h"

class Sorting : public Stack, public InputLoader {
private:
    Stack trackA;
    Stack trackB;

public:
    void process();
    void display();
};

#endif
