#include <iostream>
#include "list.h"

using namespace std;

int main() {
	ofstream f("output.txt");
	ifstream f2("mark_number.txt");
	List l;
	Line a, b;
	a.input(f2);
	b.input(f2);
	l.input();

	f << ">>>>>>>>>>>>>>>>>>Ввели:\n";
	l.print(f);
	f << ">>>>>>>>>>>>>>>>>>Конец\n";
	l.progress(a, b, f);
	f << ">>>>>>>>>>>>>>>>>>Получилось:\n";
	l.print(f);
	f << ">>>>>>>>>>>>>>>>>>Конец\n";
	l.clear();
	return 0;

}
