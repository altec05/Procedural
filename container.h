
#ifndef CONT_H
#define CONT_H

#include "complex_numbers.h"
#include "fractional_numbers.h"
#include "polar_numbers.h"

namespace variant9123 {

    // Контейнер на основе одномерного массива элементов с проверкой на переполнение.
    struct numbers_array {
        enum {max_len = 100}; // Максимальная длина
        int len; // Текущая длина
        numbers *arr[max_len];
    };

    // Очистка контейнера "c"
    void Clear(numbers_array &c);

    // Проверка на переполнение
    bool Overflow_test(numbers_array &c);

    // Считывание и вывод всех чисел в контейнер
    void In(numbers_array &c, std::ifstream &ifstr);
    void Out(numbers_array &c, std::ofstream &ofstr);
}

#endif //CONT_H
