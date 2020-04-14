
#ifndef POLAR_H
#define POLAR_H

#include "numbers.h"

namespace variant9123 {

    // Структура дробных чисел
    struct polar_numbers {
        types num_type; // Тип объекта
        std::string measure; // Единица измерения
        double angle; // угол [радиан]
        int radius; // Расстояние до точки
    };

    // Считывание и вывод дробных чисел
    void OutPolar(polar_numbers *fract, std::ofstream &ofstr);
    double ToDouble(polar_numbers *fract);
    numbers *InPolar(std::ifstream &ifstr);

}

#endif //POLAR_H
