#include "numbers.h"
#include "complex_numbers.h"
#include "fractional_numbers.h"
namespace variant9123 {

    // Считывание числа из файла
    numbers *In(std::ifstream &ifstr) {
        numbers *element = nullptr; // Объявление экземпляра структуры
        char data[255]; // Буфер для считывания
        ifstr.getline(data, 255); // Считываем строку
        if (std::string(data) == "1") { // Если вводим комплексное число
            element = InComplex(ifstr); // Считываем комплексное число и сохраняем указатель
            element->num_type = types::COMPLEX;
        } else if (std::string(data) == "2") { // Если вводим дробь
            element = InFractional(ifstr); // Считываем дробное число и сохраняем указатель
            element->num_type = types::FRACTION;
        } else { // Если тип не найден
            delete element;
            std::cout << "Error has occurred while reading the file" << std::endl;
            return nullptr;
        }
        return element;
    }

}