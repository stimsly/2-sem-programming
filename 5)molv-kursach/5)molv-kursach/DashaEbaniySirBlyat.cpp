#include "fun.h"
#include "f_elem.h"
#include "f_SL.h"
#include <fstream>
#include <iostream>
#include "form.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");
	fstream fo, fo2, f, f2, f3;

	fo.open("output.txt", ios::out);
	fo2.open("output2.txt", ios::out);

	f.open("input.txt", ios::in);
	f.unsetf(ios::skipws);
	R_Channel* ch = new R_Channel;
	InputC(&ch, f);

	f2.open("input2.txt", ios::in);
	f2.unsetf(ios::skipws);
	ads* ad = new ads;
	InputA(&ad, f2);

	f3.open("input3.txt", ios::in);
	f3.unsetf(ios::skipws);
	filling(&ch, &ad, f3);

	fo << "Контрольный вывод: " << endl;
	OutputMain(ch, fo);

	fo << "\nВспомогательный список рекламы:" << endl;
	OutputAssistive(ad, fo);

	R_Channel* curC = new R_Channel;
	curC = ch;
	int i = 0;
	while (2 + 2 == 4) {
		i++;
		if (GetNextC(curC) == NULL) break;
		else curC = GetNextC(curC);
	}

	cout << "Выберите радиоканал, расписание реклам которого вы хотите увидеть:\n";
	fo2 << "Выберите радиоканал, расписание реклам которого вы хотите увидеть:\n";
	OutputInterface(ch, fo2);

	int n;
	cin >> n;
	fo2 << n << endl;
	int j = 0;

	curC = ch;

	while (n != 0) {
		if (n > i || n < 0) {
			cout << "Канала под таким номером не существует\n";
			fo2 << "Канала под таким номером не существует\n";
		}
		else if (n == 0) break;
		else {
			while (j < n - 1) {
				curC = GetNextC(curC);
				j++;
			}
			OutputSchedule(curC, fo2);
			j = 0;
		}
		cin >> n;
		fo2 << n << endl;
		curC = ch;
	}

	f.close();
	f2.close();
	f3.close();
	fo.close();
	fo2.close();

	while (IfEmpty(ch->Channel) == 0) Delete(&(ch->Channel));
	while (IfEmpty(ad->ad) == 0) Delete(&(ad->ad));
	while (IfEmptyG(ch->goa) == 0) DeleteG(&(ch->goa));
	while (IfEmptyT(ch->t) == 0) DeleteT(&(ch->t));
	while (IfEmptyC(ch) == 0) DeleteC(&(ch));
	while (IfEmptyA(ad) == 0) DeleteA(&(ad));

	return 0;
}