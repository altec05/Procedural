#include "numbers.h"
#include "polar_numbers.h"
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
        } else if (std::string(data) == "3") { // Если вводим дробь
            element = InPolar(ifstr); // Считываем полярное число и сохраняем указатель
            element->num_type = types::POLAR;
        } else { // Если тип не найден
            delete element;
            std::cout << "Error has occurred while reading the file" << std::endl;
            return nullptr;
        }
        ifstr.getline(data, 255); // Считываем строку
        element->measure = std::string(data);
        return element;
    }

    double ToDouble(numbers *num) {
        switch(num->num_type) {
            case types::COMPLEX:
                return ToDouble((complex_numbers*)num);
            case types::FRACTION:
                return ToDouble((fractional_numbers*)num);
            default:
                return 0;
        }
    }

    bool Compare(numbers *num1, numbers *num2) {
        return ToDouble(num1) > ToDouble(num2);
    }

}