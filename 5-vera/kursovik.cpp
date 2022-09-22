#include <iostream>
#include <fstream>
#include"ALPHA_LIST.h"

int main()
{
    setlocale(0, "ru");
    ofstream r1("out.txt");
    ofstream r("protokol.txt");
    ALPHA* p1 = new ALPHA;
    inpV(p1);
    int ptr = 0;
    r << "Контрольный вывод: " << "\n\n" << "Списочное представление текста: \n\n" << "Первый список : \n";
    outputV(p1, r, ptr, r1);
    r << "\n\n" << "Второй список: \n";
    outputV2(p1, r, ptr, r1);
    r << "\n\n" << "Третий список: \n";
    outputV3(p1, r, ptr, r1);
    ptr = 1;
    r1 << "Контрольный вывод: \n\n";
    r1 << "\n\nПИСЬСМА\n\n";
    r << "\n\nКонтрольный вывод: " << "\n\n" << "Список в виде, представленном в файле: \n\n" << "Первый список : \n";
    outputV(p1, r, ptr, r1);
    r << "\n\n" << "Второй список: \n";
    r1 << "\n\nТАРИФ\n\n";
    outputV2(p1, r, ptr, r1);
    r << "\n\n" << "Третий список: \n";
    r1 << "\n\nМАРКИ\n\n";
    outputV3(p1, r, ptr, r1);
    sortirovka1(p1, r);
    r << "УДАЛЯЕМ СПИСОК ПИСЕМ И СПИСОК НОВЫХ ТАРИФОВ, ЧТОБЫ ОНИ НЕ ЗАНИМАЛИ ЛИШНИЙ РАЗ МЕСТО\n\n";
    deleteHead(p1, r);
    ptr = 0;
    r << "Первый список : \n" << "ПОСЛЕ УДАЛЕНИЯ \n\n" << "\n\nПИСЬСМА\n\n";
    outputV(p1, r, ptr, r1);
    r << "\n\n" << "Второй список: \n" << "ПОСЛЕ УДАЛЕНИЯ \n\n";
    r << "\n\nТАРИФ\n\n";
    outputV2(p1, r, ptr, r1);
    sort_rovka(p1, r);
    sort_rovka_marok(p1, r, ptr, r1);
    obrabotka(p1, r, r1);
    outputV5(p1, r, ptr);
    deleteHead2(p1);
    ptr = 1;
    r << "\n\nПИСЬМА В ОТСОРТИРОВАННОМ ПОРЯДКЕ: \n\n";
    bubble_pisma(p1, r);
    outputV5(p1, r,ptr);
    r1 << "\nРЕЗУЛЬТАТ НАКЛЕЙКИ МАРОК\n\n";
    outputV5(p1, r1,ptr);
    r1 << "\nСАМОЕ БОЛЬШОЕ КОЛИЧЕСТВО МАРОК НА ОДНОМ КОНВЕРТЕ:\n";
    r << "\nСАМОЕ БОЛЬШОЕ КОЛИЧЕСТВО МАРОК НА ОДНОМ КОНВЕРТЕ:\n";
    int y = 0;
    y = minimum(p1);
    r1 << y << endl << endl;
    r << y << endl << endl;
    deleteHead3(p1);
    r << "ВСЕ СПИСКИ ПОСЛЕ УДАЛЕНИЯ: \n\n";
    r << "\n\nСПИСОК МАРОК\n\n";
    ptr = 0;
    outputV3(p1,r,ptr,r1);
    ptr = 0;
    r << "\n\nВСПОМОГАТЕЛЬНЫЙ СПИСОК\n\n";
    outputV4(p1,r, ptr);
    r << "\n\nРЕЗУЛЬТИРУЮЩИЙ СПИСОК\n\n";
    outputV5(p1,r,ptr);
    r.close();
    r1.close();
}