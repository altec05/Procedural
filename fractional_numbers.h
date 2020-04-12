
#ifndef FRACT_H
#define FRACT_H

#include "numbers.h"

namespace variant9123 {

    // Структура дробных чисел
    struct fractional_numbers {
        types num_type; // Тип объекта
        std::string measure; // Единица измерения
        // Простые дроби (числитель, знаменатель – пара целых чисел)
        int numerator; // Числитель
        int denominator; // Знаменатель
    };

    // Считывание и вывод дробных чисел
    void OutFractional(fractional_numbers *fract, std::ofstream &ofstr);
    numbers *InFractional(std::ifstream &ifstr);

}

#endif //FRACT_H
