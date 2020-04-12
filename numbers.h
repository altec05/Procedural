
#ifndef NUMB_H
#define NUMB_H
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>

namespace variant9123 {

    // Перечисляемый тип
    enum types {
        COMPLEX = 1, //Комплексные числа
        FRACTION = 2, // Простые дроби
        POLAR = 3 // Полярные координаты
    };

    struct numbers {
        types num_type; // Тип объекта
    };

    // Считывание числа из файла
    numbers *In(std::ifstream &ifstr);

}

#endif //NUMB_H
