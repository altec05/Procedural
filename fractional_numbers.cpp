
#include "fractional_numbers.h"

namespace variant9123 {

    // Считывание и вывод дробных чисел
    void OutFractional(fractional_numbers *fract, std::ofstream &ofstr) {
        ofstr << "[FRACTIONAL NUMBER = ";
        // Вывод комплексного числа в виде x/y
        ofstr << fract->numerator << "/"; // Вывод числителя
        if(fract->denominator >= 0) ofstr << fract->denominator << "]" << std::endl; // Вывод положительного знаменателя
        else ofstr << "(" << fract->denominator << ")]" << std::endl; // Вывод знаменателя в скобках
    }

    numbers *InFractional(std::ifstream &ifstr) {
        fractional_numbers *temp = new fractional_numbers; // Создаем экземпляр структуры
        ifstr >> temp->numerator >> temp->denominator; // Считываем числитель и знаменатель
        if(!ifstr.eof()) ifstr.get(); // Переход на новую строку
        return (numbers*) temp; // Перевод указателя под numbers*
    }

}