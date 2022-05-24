#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "list.h"

using namespace std;

int InputLoop(int a, int b, log_normal& _log) {
    _log.PutMessageOutConsole(L"");
    int action = -1;
    do {
        _log.ErrorMenu(a, b);
        wcin >> action;
        _log.PutMessageLog(L"Попытка ввода: ", action);
    } while (action < a || action > b);

    _log.PutMessageOutConsole(L"Ввод: ", action);
    _log.PutMessageOutConsole(L"");

    return action;
}

void InputString(list_wrapper& dist) {
    char c = '\0';
    int i = 0;
    c = wcin.get(); c = '\0';

    while (c != '\n') {
        c = wcin.get();
        if (c != '\n')
            AddSymb(dist, c);
    }
}

void MainFunc(list* data_base, log_normal& _log) {

    int _action = -1, __action = -1;

    _log.ShowActionMenu2();             // Показать меню выбора домов на покупку

    _action = InputLoop(0, 4, _log);

    if (_action == 1) {
        LogList(data_base, _log);
    }
    else if (_action == 2) {
        _log.PutMessageOutConsoleLog(L"Дома по площади (10 - 50'000):");
        _log.PutMessageConsole(L"Введите площадь интервалом: a b");
        int area1, area2;
        wcin >> area1 >> area2;

        // Создать список по площади
        multi_list* data_base_sorted = new multi_list;  // не копирует inf
        SortListBy(data_base_sorted, data_base, area1, area2, 3);

        _log.ShowActionMenu3();
        __action = InputLoop(0, 3, _log);

        if (__action == 1) {
            _log.PutMessageConsole(L"Выберите район: ");
            ListSortedDistricts(data_base_sorted, _log);
            // ... функция на вывод районов

            int index;
            wcin >> index;

            list_wrapper dist =
                GetDistrictByIndex(data_base_sorted, index);
            SortListByDistrict(&data_base_sorted, dist);

            // Готовый список
            OutputSorted(data_base_sorted, _log);
            FreeSorted(&data_base_sorted);

        }
        else if (__action == 2) {
            _log.PutMessageConsole(L"Введите район: ");
            // ... функция на считывание из консоли

            list_wrapper dist;
            InputString(dist);

            SortListByDistrict(&data_base_sorted, dist);

            // Готовый список
            OutputSorted(data_base_sorted, _log);
            FreeSorted(&data_base_sorted);
        }
        else if (__action == 3) {
            // Готовый список
            OutputSorted(data_base_sorted, _log);
            FreeSorted(&data_base_sorted);
        }

    }
    else if (_action == 3) {
        _log.PutMessageOutConsoleLog(L"Дома по цене (500'000 - 100'000'000):");

        _log.PutMessageConsole(L"Введите цену интервалом: a b");
        // Введите цену
        long price1, price2;
        wcin >> price1 >> price2;

        // Создать список по цене
        multi_list* data_base_sorted = new multi_list;  // не копирует inf
        SortListBy(data_base_sorted, data_base, price1, price2, 4);

        _log.ShowActionMenu3();
        __action = InputLoop(0, 3, _log);

        if (__action == 1) {
            _log.PutMessageConsole(L"Выберите район: ");
            ListSortedDistricts(data_base_sorted, _log);
            // ... функция на вывод районов

            int index;
            wcin >> index;

            list_wrapper dist =
                GetDistrictByIndex(data_base_sorted, index);
            SortListByDistrict(&data_base_sorted, dist);

            OutputSorted(data_base_sorted, _log);

        }
        else if (__action == 2) {
            _log.PutMessageConsole(L"Введите район: ");
            // ... функция на считывание из консоли

            list_wrapper dist;
            InputString(dist);

            SortListByDistrict(&data_base_sorted, dist);

            OutputSorted(data_base_sorted, _log);
        }
        if (__action != 0) {
            // Доп. характеристики

            _log.ShowActionMenu1();
            int additional = InputLoop(0, 3, _log);
            _log.PutMessageConsole(L"Введите интервал: a b");
            int a, b;
            wcin >> a >> b;
            if (additional != 0) {
                // Поиск с нужными хар-ками, вывод домов
                SortListRepeat(&data_base_sorted, a, b, additional);
                OutputSorted(data_base_sorted, _log);
                FreeSorted(&data_base_sorted);
            }
        }

    }
    else if (_action == 4) {
        _log.PutMessageOutConsoleLog(L"Дома по кол-ву комнат:");

        _log.PutMessageConsole(L"Введите кол-во комнат (1-100) интервалом: a b");
        // Введите цену
        int rooms1, rooms2;
        wcin >> rooms1 >> rooms2;

        // Создать список по кол-ву комнат
        multi_list* data_base_sorted = new multi_list;  // не копирует inf
        SortListBy(data_base_sorted, data_base, rooms1, rooms2, 2);

        _log.ShowActionMenu3();
        __action = InputLoop(0, 3, _log);

        if (__action == 1) {
            _log.PutMessageConsole(L"Выберите район: ");
            ListSortedDistricts(data_base_sorted, _log);
            // ... функция на вывод районов

            int index;
            wcin >> index;

            list_wrapper dist =
                GetDistrictByIndex(data_base_sorted, index);
            SortListByDistrict(&data_base_sorted, dist);

            // Готовый список
            OutputSorted(data_base_sorted, _log);
            FreeSorted(&data_base_sorted);

        }
        else if (__action == 2) {
            _log.PutMessageConsole(L"Введите район: ");
            // ... функция на считывание из консоли

            list_wrapper dist;
            InputString(dist);

            SortListByDistrict(&data_base_sorted, dist);

            // Готовый список
            OutputSorted(data_base_sorted, _log);
            FreeSorted(&data_base_sorted);
        }
        else if (__action == 3) {
            // Готовый список
            OutputSorted(data_base_sorted, _log);
            FreeSorted(&data_base_sorted);
        }
    }
}

int main() {
    fstream result;
    result.open("result.txt", ios::out);
    log_normal _log;   // Инициализировали логгер
    list* data_base_buy = new list;
    list* data_base_sell = new list;

    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stderr), _O_U16TEXT);

    // Загрузка базы данных квартир
    // ...

    fstream in_buy("in_buy.txt");
    if (!in_buy) {
        _log.PutMessageLog(L"Неудача при попытке открыть in_but.txt на чтение. Завершение работы.");
        _log.PutMessageConsole(L"Неудача при попытке открыть in_buy.txt на чтение. Завершение работы.");
        exit(3);
    }

    _log.PutMessageLog(L"Считываем дома на покупку");
    ReadList(data_base_buy, in_buy, _log);

    fstream in_sell("in_sell.txt");
    if (!in_sell) {
        _log.PutMessageLog(L"Неудача при попытке открыть in_sell.txt на чтение. Завершение работы.");
        _log.PutMessageConsole(L"Неудача при попытке открыть in_sell.txt на чтение. Завершение работы.");
        exit(4);
    }

    _log.PutMessageLog(L"Считываем дома на продажу");
    ReadList(data_base_sell, in_sell, _log);

    // ...

    int action = -1;
    while (action != 0) {
        _log.ShowActionMenu0();             // Показать меню выбора действий со справочником

        action = InputLoop(0, 4, _log); // Выдаёт только верные значения

        if (action == 1) {
            _log.PutMessageLog(L"Показываем все дома");
            _log.PutMessageOutConsoleLog(L"Дома на покупку:");
            LogList(data_base_buy, _log);
            _log.PutMessageOutConsoleLog(L"Дома на продажу:");
            LogList(data_base_sell, _log);
        }
        else if (action == 2) {
            _log.PutMessageLog(L"Выбор домов на покупку");
            MainFunc(data_base_buy, _log);  // Алгоритм обработки базы данных домов на покупку
        }
        else if (action == 3) {
            _log.PutMessageLog(L"Выбор домов на продажу");
            MainFunc(data_base_sell, _log);  // Алгоритм обработки базы данных домов на продажу
        }
        else if (action == 4) {
            _log.PutMessageOutConsoleLog(L"Показываем встречные предложения");
            //... функция поиска встречных предложений
            OutputEquals(data_base_buy, data_base_sell, _log);
        }
    }

    in_buy.close();
    in_sell.close();
    _log.PutMessageOutConsoleLog(L"Программа успешно завершила работу. Возвращайтесь ещё!");
    return 0;
}