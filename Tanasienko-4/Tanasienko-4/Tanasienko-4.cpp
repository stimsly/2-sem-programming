#include <iostream>
#include "all.h"

int main()
{
    ofstream fout("output.txt");
    ifstream f1("l1.txt");
    ifstream f2("l2.txt");
    all a;
    a.l1.input(f1);
    a.l2.input(f2);
    fout << "Первый список:\n";
    a.l1.output(fout);
    fout << "Второй список:\n";
    a.l2.output(fout);
    fout << endl << "\tНачалась проверка на то что l1 это подмножество l2...\n\n";
    fout << "\tЗавершенно: 10%\n";
    fout << "\tЗавершенно: 23%\n";
    fout << "\tЗавершенно: 37%\n";
    fout << "\tЗавершенно: 54%\n";
    fout << "\tЗавершенно: 67%\n";
    fout << "\tЗавершенно: 90%\n\n";
    fout << "\tПроверка завершена!!\n\n";
    if (a.progress()) {
        fout << "\tl1 это подмножество l2!";
    }
    else fout << "\tl1 не является подмножеством l2!";
    a.clear();
    return 0;
}
