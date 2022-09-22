#include <iostream>
#include <fstream>
#include <Windows.h>
#include "all.h"
using namespace std;

all a;

ifstream f("f.txt");
ifstream g("g.txt");
ofstream fout("output.txt");

void menu() {
	cout << "1.Добавить элемент в F(1)\n";
	cout << "2.Удалить элемент из F(1)\n";
	cout << "3.Проверка на принадлежность элемента в F(1)\n";
	cout << "4.Является ли F подмножеством G(1)\n";
	cout << "5.Обьеденить F и G(0)\n";
	cout << "6.Пересечь множества F и G(1)\n";
	cout << "7.Разность множеств F и G(1)\n";
	cout << "8.Симметрическая разность F и G(0)\n";
	cout << "9.конкатенация множеств F и G(1)\n";
	cout << "10.Расщепить множество F по элементу(1)\n";
	cout << "11.Выбрать максимальный из F(1)\n";
	cout << "12.Выбрать минимальный из F(1)\n";
	cout << "13.Посмотреть весь список(1)\n";
	cout << "0.Выход\n";
	int t;
	cout << "Выберите номер: ";
	cin >> t;
	if (!t) {
		return;
	}
	system("cls");
	if (t == 1) {
		a.plus(fout);
	}
	if (t == 2) {
		a.remove(fout);
	}
	if (t == 3) {
		a.in(fout);
	}
	if (t == 4) {
		a.is_f_in_g(fout);
	}
	if (t == 5) {
		a.f_plus_g(fout);
	}
	if (t == 6) {
		a.intersect(fout);
	}
	if (t == 7) {
		a.minus(fout);
	}
	if (t == 8) {
		a.symmetric_difference(fout);
	}
	if (t == 9) {
		a.un(fout);
	}
	if (t == 10) {
		a.split(fout);
	}
	if (t == 11) {
		a.nmax(fout);
	}
	if (t == 12) {
		a.nmin(fout);
	}
	if (t == 13) {
		a.output(fout);
	}
	if (t > 13 or t < 0) {
		cout << "Не стоит вводить другие номера\n";
		fout << "Ввели не тот номер(УЖААААС)\n";
	}

	system("pause");
	system("cls");
	menu();
	return;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	a.input(f, g);

	menu();
	cout << "Конечное множество: \n";
	fout << "Конечное множество: \n";
	a.output(fout);
	cout << "Выход из программы!";
	fout << "Выход из программы!";
}