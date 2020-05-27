#include "gtest/gtest.h"
#include "numbers.h"
#include "container.h"

const bool is_testing = false;

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

    if(ifst.is_open() && ofst.is_open()) {
        cout << "Program started" << endl;
        // Объявление numbers_array
        variant9123::numbers_array c{};
        // Считывание из файла
        variant9123::In(c, ifst);
        // Вывод в файл
        variant9123::Out(c, ofst);
        variant9123::OutPairs(c, ofst);
        variant9123::Clear(c);
        cout << "Program ended" << endl;
    } else  {
        cout << "Error has occured while reading file." << std::endl;
    }
    return 0;
}
