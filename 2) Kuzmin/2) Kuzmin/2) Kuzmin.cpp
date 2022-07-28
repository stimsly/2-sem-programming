#include <iostream>
#include <fstream>
#include "text.h"

using namespace std;


int main() {
	setlocale(LC_ALL, "Russian");
	ifstream f("input.txt");
	text a;

	a.input(f);

	
	a.output();

	a.progress();

	return 0;
}