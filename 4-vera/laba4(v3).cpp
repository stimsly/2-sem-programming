#include <iostream>
#include <fstream>
#include "FormV.h"

int main()
{
    setlocale(0, "ru");
    ofstream r("out.txt");
    ifstream f("inp1.txt");
    FormV* p1 = new FormV;
    int k;
    inpV(f, p1);
    r << "Контрольный вывод: \n\n" << "Первый список: \n";
    outputV(p1,r);
    f.close();
    ifstream f1("inp2.txt");
    inpV2(f1, p1);
    r << "\n\n" << "Второй список: \n";
    outputV2(p1, r);
    k = obrabotka3(p1);
    if (k == -1)
        r << "\n\n" << "ОТВЕТ: МНОЖЕСТВА, ПРЕДСТАВЛЕННЫЕ СПИСКАМИ 1 И 2 РАВНЫ" << "\n\n";
    else
        r << "\n\n" << "ОТВЕТ: МНОЖЕСТВА, ПРЕДСТАВЛЕННЫЕ СПИСКАМИ 1 И 2 НЕ РАВНЫ" << "\n\n";
    deleteHead(p1, r);
    r << "\n\n" << "ПОСЛЕ УДАЛЕНИЯ: " << endl;
    r << "\n\n" << "Первый список: \n";
    outputV(p1, r);
    r << "\n\n" << "Второй список: \n";
    outputV2(p1, r);
    f1.close();
    r.close();
}