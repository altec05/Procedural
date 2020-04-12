
#include "polar_numbers.h"

namespace variant9123 {
    // Считывание и вывод комплексных чисел
    numbers *InPolar(std::ifstream &ifstr) {
        polar_numbers *temp = new polar_numbers; // Создаем экземпляр структуры
        ifstr >> temp->angle >> temp->radius; // Считываем мнимую и действительную часть
        if (!ifstr.eof()) ifstr.get(); // Переход на новую строку
        return (numbers *) temp; // Перевод указателя под numbers*
    }

    void OutPolar(polar_numbers *polar, std::ofstream &ofstr) {
        ofstr << "[POLAR NUMBER = ";
        ofstr << polar->angle << ";" << polar->radius << "]" << std::endl;
    }

}