#include <iostream>
#include "list.h"

using namespace std;

int main() {
	ofstream f("output.txt");
	List l;
	Line a;
	a.input();
	l.input();
	f << ">>>>>>>>>>>>>>>>>>Ввели:\n";	
	l.print(f);
	f << ">>>>>>>>>>>>>>>>>>Конец\n";
	l.progress(a, f);

	l.clear();
	return 0;

}
