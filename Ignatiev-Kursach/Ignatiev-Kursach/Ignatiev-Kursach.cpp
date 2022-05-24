#include <iostream>
#include <windows.h>
#include "all.h"

using namespace std;

void menu() {
    system("cls");
    cout << "Добро пожаловать в библиоткеку Валерия Игнатьева!\n" <<
        "Выберите действие:\n" <<
        "1.Взять книгу\n" <<
        "2.Вернуть книгу\n" << 
        "0.Завершение взаимодействия \n";
    int n;
    cin >> n;
    if (n == 0) {
        system("cls");
        return;
    }
    if (n < 0 or n > 2) {
        cout << "Вы выбрали не коректное действие попробуйте снова!\n";
        system("pause");
        menu();
    }
    if (n == 1) {

    }
    else if (n == 2) {

    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    all a;
    a.input();
    menu();
}