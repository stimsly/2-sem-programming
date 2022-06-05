#include <iostream>
#include <fstream>
#include <Windows.h>
#include "all.h"

using namespace std;

all a;
ifstream fbooks("books.txt");
ofstream fout_rep("report.txt");

void find_by() {
    system("cls");
    cout << "Выберите действие:\n" <<
        "1.Поиск по названию книги\n" <<
        "2.Поиск по автору\n" <<
        "0.Выход" << endl;
    int t = -1;
    cin >> t;
    if (t < 0 or t > 2) {
        system("cls");
        cout << "Введите пожалуйста корректный номер.\n\n";
        find_by();
    }
    if (t == 1) {
        fout_rep << "Пользователь начал поиск по книгам\n";
        system("cls");
        char a1;
        cout << "Введите первую букву книги: \n" <<
            "Доступные буквы: (";
        for (int i = 0; i < 26; i++) {
            if (a.get_b(i)) cout << char(i + 'a') << " ";
        }
        cout << "): ";
        cin >> a1;
        if (a1 >= 'A' and a1 <= 'Z') a1 = a1 - 'A' + 'a';
        a.output_books(a1, fout_rep);
        system("pause");
        fout_rep << "Пользователь искал книги начинающееся с буквы " << a1 << endl;

        system("cls");
        find_by();
    }
    else if (t == 2) {
        fout_rep << "Пользователь начал поиск по авторам\n";
        system("cls");
        char a1;
        cout << "Введите первую букву фамилии: \n"<<
            "Доступные буквы: (";
        for (int i = 0; i < 26; i++) {
            if (a.get_w(i)) cout << char(i + 'a') << " ";
        }
        cout << "): ";
        cin >> a1;
        if (a1 >= 'А' and a1 <= 'Я') a1 = a1 - 'А' + 'а';
        a.output_writers(a1, fout_rep);

        system("pause");
        system("cls");
        fout_rep << "Пользователь искал фамилии начинающееся с буквы " << a1 << endl;
        find_by();
    }

    else if (t == 0) {
        fout_rep << "Пользователь завершил поиск книг\n";
        return;
    }
}

void menu() {
    cout << "Выберите действие:\n" <<
       "1.Посмотерть список книг\n" <<
       "2.Посмотреть список авторов\n" <<
        "3.Найти книгу\n" <<
        "0.Выход" << endl;
    int t = -1;
    cin >> t;
    if (t < 0 or t > 3) {
        system("cls");
        cout << "Введите пожалуйста корректный номер.\n\n";
        menu();
    }
    if (t == 1) {
        fout_rep << "Пользователь ввел 1(Посмотреть список книг)\n";
        system("cls");
        a.output_books();
        system("pause");
        system("cls");
    }
    else if (t == 2) {
        fout_rep << "Пользователь ввел 2(Посмотреть список авторов)\n";
        system("cls");
        a.output_writers();
        system("pause");
        system("cls");
    }
    else if (t == 3) {
        fout_rep << "Пользователь ввел 3(Поиск наличия книг)\n";
        find_by();
        system("cls");
    }
    else if (t == 0) {
        fout_rep << "Пользователь вышел из программы!!\n";
        return;
    }
    menu();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    a.input(fbooks);
    menu();
    a.clear();
}