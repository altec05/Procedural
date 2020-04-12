
#ifndef POLAR_H
#define POLAR_H

#include "numbers.h"

namespace variant9123 {

    // Структура дробных чисел
    struct polar_numbers {
        double angle; // угол [радиан]
        int radius; // Расстояние до точки
    };

    // Считывание и вывод дробных чисел
    void OutPolar(polar_numbers *fract, std::ofstream &ofstr);
    numbers *InPolar(std::ifstream &ifstr);

}

#endif //POLAR_H
