
#include "fractional_numbers.h"

namespace variant9123 {

    // Считывание и вывод дробных чисел
    void OutFractional(fractional_numbers *fract, std::ofstream &ofstr) {
        ofstr << "[FRACTIONAL NUMBER = ";
        // Вывод комплексного числа в виде x/y
        ofstr << "(" << ToDouble(fract) << ") "; // Вывод числителя
        ofstr << fract->numerator << "/"; // Вывод числителя
        if(fract->denominator >= 0) ofstr << fract->denominator << " " << fract->measure << "]" << std::endl; // Вывод положительного знаменателя
        else ofstr << "(" << fract->denominator << ") " << fract->measure << "]" << std::endl; // Вывод знаменателя в скобках
    }

    numbers *InFractional(std::ifstream &ifstr) {
        bool bad_flag = false;
        fractional_numbers *temp = new fractional_numbers; // Создаем экземпляр структуры
        if(ifstr.eof()) return nullptr;
        ifstr >> temp->numerator;
        if(ifstr.fail()) bad_flag = true;
        if(ifstr.eof() || bad_flag) return nullptr;
        ifstr >> temp->denominator; // Считываем числитель и знаменатель
        if(temp->denominator == 0) {
            std::cout << "Error: division by zero!" << std::endl;
            return nullptr;
        }
        if(ifstr.fail()) bad_flag = true;
        if(!ifstr.eof() && !bad_flag) ifstr.get(); // Переход на новую строку
        else return nullptr;
        return (numbers*) temp; // Перевод указателя под numbers*
    }

    // Приведение каждого значения к действительному числу, эквивалентному записанному.
    double ToDouble(fractional_numbers *fract) {
        return (double)(fract->numerator)/(fract->denominator);
    }

}