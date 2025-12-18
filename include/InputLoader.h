#ifndef INPUTLOADER_H
#define INPUTLOADER_H

#include "Stack.h"
#include "WagonFactory.h"
#include <iostream>
#include <fstream>
#include <string>

class InputLoader {
public:
    // Load from keyboard
    void loadFromKeyboard(Stack& stack);

    // Load from file
    void loadFromFile(Stack& stack, const char* filename);
};
#endif
