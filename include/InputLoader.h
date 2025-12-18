#ifndef INPUTLOADER_H
#define INPUTLOADER_H

#include "Stack.h"
#include "WagonFactory.h"
#include <iostream>
#include <fstream>
#include <string>

class InputLoader {
public:
    // ¬вод с клавиатуры
    void loadFromKeyboard(Stack& stack);

    // ¬вод из файла
    void loadFromFile(Stack& stack, const char* filename);
};
#endif