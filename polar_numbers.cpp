
#include "polar_numbers.h"

namespace variant9123 {
    // Считывание и вывод комплексных чисел
    numbers *InPolar(std::ifstream &ifstr) {
        bool bad_flag = false;
        polar_numbers *temp = new polar_numbers; // Создаем экземпляр структуры
        if(ifstr.eof()) return nullptr;
        ifstr >> temp->angle;
        if(ifstr.eof()) return nullptr;
        if(ifstr.fail()) bad_flag = true;
        if(ifstr.eof() || bad_flag) return nullptr;
        ifstr >> temp->radius; // Считываем мнимую и действительную часть
        if (!ifstr.eof()) ifstr.get(); // Переход на новую строку
        return (numbers *) temp; // Перевод указателя под numbers*
    }

    void OutPolar(polar_numbers *polar, std::ofstream &ofstr) {
        ofstr << "[POLAR NUMBER = (" << ToDouble(polar) << ") ";
        ofstr << polar->angle << ";" << polar->radius <<  " " << polar->measure << "]" << std::endl;
    }

    double variant9123::ToDouble(polar_numbers *polar) {
        return polar->radius*sin(polar->angle);
    }

}