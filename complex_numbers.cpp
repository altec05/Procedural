
#include "complex_numbers.h"

namespace variant9123 {
    // Считывание и вывод комплексных чисел
    numbers *InComplex(std::ifstream &ifstr) {
        complex_numbers *temp = new complex_numbers; // Создаем экземпляр структуры
        ifstr >> temp->real >> temp->imaginary; // Считываем мнимую и действительную часть
        if (!ifstr.eof()) ifstr.get(); // Переход на новую строку
        return (numbers *) temp; // Перевод указателя под numbers*
    }

    void OutComplex(complex_numbers *complex, std::ofstream &ofstr) {
        ofstr << "[COMPLEX NUMBER = ";
        // Вывод комплексного числа в виде xi + y
        ofstr << complex->imaginary << "i"; // xi
        // Вывод действительного числа со знаком "+"
        if (complex->real >= 0) ofstr << "+" << complex->real << " " << complex->measure << "]" << std::endl;
        else ofstr << complex->real << " " << complex->measure << "]" << std::endl; // Со знаком "-"
    }

}