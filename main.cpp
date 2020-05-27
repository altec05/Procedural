#include "numbers.h"
#include "container.h"

using namespace std;

int main(int argc, char* argv[]) {
    // Если некорректно введены аргументы
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
    variant9123::OutPairs(c, ofst);
    // Очистка контейнера
    variant9123::Clear(c);
    cout << "Program ended"<< endl;
    return 0;
}
