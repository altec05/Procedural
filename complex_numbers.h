

#ifndef COMP_H
#define COMP_H

#include "numbers.h"

namespace variant9123 {

    // Структура комплексных чисел
    struct complex_numbers {
        types num_type; // Тип объекта
        // Комплексные (действительная и мнимая части – пара действительных чисел)
        double real;
        double imaginary;
    };

    // Считывание и вывод комплексных чисел
    void OutComplex(complex_numbers *complex, std::ofstream &ofstr);
    numbers *InComplex(std::ifstream &ifstr);
    double ToDouble(complex_numbers *complex);
}

#endif //COMP_H
