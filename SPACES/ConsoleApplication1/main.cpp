#include <iostream>
#include <fstream>
#include "text.h"
using namespace std;

int main() {
	ifstream f("input.txt");
	ofstream f2("output.txt");
	text a;
	a.input(f);
	f2 << ">>>>>>>>>>>>>>>>>>>>>>>>>>>Вот че ввели\n";
	a.output(f2);
	a.progress();
	f2 << ">>>>>>>>>>>>>>>>>>>>>>>>>>Вот че получилось\n";
	a.output(f2);

	return 0;

}




