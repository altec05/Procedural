
#ifndef NUMB_H
#define NUMB_H
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

namespace variant9123 {

    // Перечисляемый тип
    enum types {
        NONE = 0,
        COMPLEX = 1, //Комплексные числа
        FRACTION = 2, // Простые дроби
        POLAR = 3 // Полярные координаты
    };

    struct numbers {
        types num_type; // Тип объекта
        std::string measure; // Единица измерения
    };

    // Считывание числа из файла
    numbers *In(std::ifstream &ifstr);
    double ToDouble(numbers *num);
    bool Compare(numbers *num1, numbers *num2);
}

#endif //NUMB_H
