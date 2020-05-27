
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

    void OutPairs(numbers_array &c, std::ofstream &ofstr) {
        ofstr << "-----Printing-pairs-with-multimethod-----" << std::endl;
        for(int i = 0; i < c.len-1; i++) {
            for(int j = 0; j < c.len; j++) {
                if(i == j) continue;
                switch(c.arr[i]->num_type) {
                    case types::COMPLEX:
                        switch(c.arr[j]->num_type) {
                            case types::COMPLEX:
                                ofstr << "--complex-and-complex--" << std::endl;
                                OutComplex((complex_numbers*)c.arr[j], ofstr);
                                break;
                            case types::FRACTION:
                                ofstr << "--complex-and-fractional--" << std::endl;
                                OutFractional((fractional_numbers*)c.arr[j], ofstr);
                                break;
                        }
                        OutComplex((complex_numbers*)c.arr[i], ofstr);
                        break;
                    case types::FRACTION:
                        switch(c.arr[j]->num_type) {
                            case types::COMPLEX:
                                ofstr << "--fractional-and-complex--" << std::endl;
                                OutComplex((complex_numbers*)c.arr[j], ofstr);
                                break;
                            case types::FRACTION:
                                ofstr << "--fractional-and-fractional--" << std::endl;
                                OutFractional((fractional_numbers*)c.arr[j], ofstr);
                                break;
                        }
                        OutFractional((fractional_numbers*)c.arr[i], ofstr);
                        break;
                }
            }
        }
    }

}