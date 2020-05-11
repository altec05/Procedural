#include "gtest/gtest.h"
#include "numbers.h"
#include "container.h"

const bool is_testing = true;

using namespace testing;
using namespace std;

int main(int argc, char* argv[]) {
    if(is_testing) {
        InitGoogleTest();
        RUN_ALL_TESTS();
        return 0;
    }
    if(argc !=3) {
        cout << "incorrect command line! " << endl
             << "Waited: command in_file out_file"
             << endl;
        exit(1);
    }
    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    cout << "Program started"<< endl;
    // Объявление numbers_array
    variant9123::numbers_array c{};
    // Считывание из файла
    variant9123::In(c, ifst);
    // Вывод в файл
    variant9123::Out(c, ofst);
    // Сортировка
    variant9123::Sort(c);
    ofst << "-----------Sorted-----------" << std::endl;
    variant9123::Out(c, ofst);
    // Вывод без Complex
    ofst << "----------No complex writing---------"<< endl;
    variant9123::Out(c, ofst, variant9123::types::COMPLEX);
    // Очистка контейнера
    variant9123::Clear(c);
    cout << "Program ended"<< endl;
    return 0;
}
