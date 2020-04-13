
#include "container.h"

namespace variant9123 {

    // Проверка на переполнение
    bool Overflow_test(numbers_array &c) {
        bool res = c.len >= c.max_len;
        if(res) { // При переполнении
            std::cout << "Container is full. Stopping reading." << std::endl;
        }
        return res;
    }

    // Считывание и вывод всех чисел в контейнер
    void In(numbers_array &c, std::ifstream &ifstr) {
        while (!ifstr.eof()) {
            if(!Overflow_test(c)) {
                numbers *num = In(ifstr);
                if (!num) { // При ошибке
                    Clear(c); // Очистка контейнера
                    return;
                }
                c.arr[c.len] = num;
                c.len++;
            } else return;
        }
    }

    void Out(numbers_array &c, std::ofstream &ofstr) {
        if(c.len == 0) {
            ofstr << "Container is empty. " << std::endl;
            return;
        }
        for(int i = 0; i < c.len; i++) {
            // Выводим элементы исходя из их типа
            switch(c.arr[i]->num_type) {
                case types::COMPLEX:
                    OutComplex((complex_numbers*)c.arr[i], ofstr);
                    break;
                case types::FRACTION:
                    OutFractional((fractional_numbers*)c.arr[i], ofstr);
                    break;
            }
        }
        std::cout << "Writing is finished." << std::endl;
    }

    // Очистка контейнера "c"
    void Clear(numbers_array &c) {
        for(int i = 0; i < c.len; i++) {
            switch(c.arr[i]->num_type) {
                case types::COMPLEX:
                    delete (complex_numbers*)c.arr[i];
                    break;
                case types::FRACTION:
                    delete (fractional_numbers*)c.arr[i];
                    break;
            }
        }
    }

    void Sort(numbers_array &c) {
        for(int i = 0; i < c.len-1; i++) {
            for(int j = i+1; j < c.len; j++) {
                if (Compare(c.arr[i], c.arr[j])) {
                    numbers* temp = c.arr[i];
                    c.arr[i] = c.arr[j];
                    c.arr[j] = temp;
                }
            }
        }
    }

}