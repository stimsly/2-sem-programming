#include <iostream>
#include "all.h"

int main()
{
    ofstream fout("output.txt");
    ifstream f1("l1.txt");
    ifstream f2("element.txt");
    all a;
    a.a.input(f1);
    a.b.input(f2);
    fout << "Список:\n";
    a.a.output(fout);
    fout << "Число e:\n";
    a.b.output(fout);
    fout << endl << "\tНачалось удаление...\n\n";
    a.progress();
    int s = 1;
    while (1) {
        int d = rand() % (100 - s - 1) + 1;
        d = min(d, 10);
        s += d;
        fout << "\tЗавершенно: " <<  s << "%\n";
        if (s == 99) break;
    }
    fout << "\tПрогресс завершен!!\n\n";
    fout << "Конечный результат:\n";
    a.a.output(fout);
    a.a.clear();
    a.b.clear();
    return 0;
}
