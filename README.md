# Задание 1 по ООП(С++)
## Текст задания
1.	Множественное наследование. Порядок разрешения методов (MRO)
2.	Спроектировать класс, реализующий стек. Построить диаграмму классов.
3.	Написать программу, использующую этот класс для моделирования Т-образного сортировочного узла на железной дороге. Программа должна разделять на два направления состав, состоящий из вагонов двух типов (на каждое направление формируется состав из вагонов одного типа). Предусмотреть возможность формирования состава из файла и с клавиатуры.
4.	Порождающие паттерны проектирования. Фабричный метод (Factory method)


## Структура проекта
```
Zadanie_OOP/
├── include/
    ├── InputLoader.h      # Класс ввода данных с клавиатуры и файла
    ├── Menu.h             # Меню
    ├── Sorting.h          # Класс сортировки
    ├── Stack.h            # Класс стек без использования std::stack
    ├── Wagon.h            # Класс вагон. Хранит информацию о вагне
    ├── WagonFactory.h     # Фабричный метод. Создаёт объекты в зависимости от типа
├── src/
    ├── InputLoader.cpp    # Реализация методов загрузки данных/множественное наследование
    ├── Menu.cpp           # Реализация меню
    ├── Sorting.cpp        # Реализация методов сортировки
    ├── Stack.cpp          # Реализация методов стека
    ├── Wagon.cpp          # Реализация методов класса Wagon
    ├── WagonFactory.cpp   # Реализация фабричного метода
├── main.cpp               # Главная программа
├── in.txt                 # Тестовые данные
```

## 1. Множественное наследование и MRO
### Схема множественного наследования и MRO
``` 
      ┌────────────┐
      │   Stack    │  <- push, pop, isEmpty, isFull
      └────────────┘
            ▲
            │
      ┌────────────┐
      │  Sorting   │  <- process, display
      └────────────┘
            │
            ▼
      ┌────────────┐
      │ InputLoader│  <- loadFromKeyboard, loadFromFile
      └────────────┘
```
### Пояснения 
1. **Sorting** наследует два базовых класса:
   - **Stack** - стек для потока вагонов
   - **InputLoader** - функционал ввода вагонов
2. MRO - порядок поиска методов при вызове из **Sorting**:
   - Компилятор ищет сначала в **Sorting**
   - Если метода нет, ищет в **Stack**
   - Если нет, ищет в **InputLoader**
## 2. Диаграмма классов
``` mermaid
classDiagram
direction RB

Stack <|-- Sorting : Наследование
InputLoader <|-- Sorting : Наследование

Sorting *-- Stack : trackA
Sorting *-- Stack : trackB
Sorting o-- WagonFactory

class Wagon {
    - type : string
    + getType() : string
}

class WagonFactory {
    + createWagon(type : string) : Wagon*
}

class Stack {
    - data[MAX_SIZE] : Wagon*
    - top : int
    + push(Wagon* w) : void
    + pop() : Wagon*
    + isEmpty() : bool
    + isFull() : bool
}

class InputLoader {
    + loadFromKeyboard() : void
    + loadFromFile(filename : const char*) : void
}

class Sorting {
    - trackA : Stack
    - trackB : Stack
    + process() : void
    + display() : void
}
```
## 3. Класс Stack
Стек реализован на основе обычного массива:
``` C++
class Stack {
protected:
	Wagon* data[MAX_SIZE];
	int top;
public:
	Stack(); // Конструктор
	~Stack(); // Деструктор
	bool isEmpty() const; // Проверка на пустоту стека
	bool isFull() const; // Проверка на заполненность стека
	void push(Wagon* w); // Добавление вагона в стек
	Wagon* pop();// Удаление вагона из стека
};
```
### Работа стека
  - Реализован без std::stack
  - Принцип LIFO - последний зашёл, первый вышел
## 4. Т-образный сортировочный узел
### Принцип решения:
**Входные данные**: массив или последовательность вагонов (**Wagon**):
  - Реализуется через методы класса **InputLoader**
  - Ввод может быть с клавиатуры (**loadFromKeyboard()**) или из файла (**loadFromFile()**)
  - Вагоны поступают последовательно и добавляются в стек **Sorting** методом **push()**

**T-образный сортировочный узел**: класс **Sorting**:
  - Содержит два внутренних стека: **trackA** и **trackB** (массивы фиксированного размера)
  - Метод **process()** сортирует вагоны по типу:
      - Вагон типа “A” → **trackA**
      - Вагон типа “B” → **trackB**
## 5. Паттерн Factory Method
### Структура:
### 1. Абстрактный продукт
``` C++
class InputLoader {
public:
    void loadFromKeyboard();          // ввод вагонов с клавиатуры
    void loadFromFile(const char*);   // ввод вагонов из файла
};
```
### Конкретные продукты
``` C++
void loadFromKeyboard();          // ввод вагонов с клавиатуры
void loadFromFile(const char*);   // ввод вагонов из файла
```
### Фабрика
Класс **WagonFactory** создаёт объекты Wagon:
``` C++
class WagonFactory {
public:
    static Wagon* createWagon(const std::string& type); // тип A или B
};
```
##Исходные данные
``` text
A A B A B #Ввод с клавиатуры
```
## Пример работы
``` text
Menu:
1 - Load from keyboard
2 - Load from file
3 - Display result
4 - Exit
Enter action number: 1

Enter number of wagons: 5
Enter wagon type (A/B): A
Enter wagon type (A/B): A
Enter wagon type (A/B): B
Enter wagon type (A/B): A
Enter wagon type (A/B): B

Menu:
1 - Load from keyboard
2 - Load from file
3 - Display result
4 - Exit
Enter action number: 3

Wagons in track A:
A A A
Wagons in track B:
B B
```
