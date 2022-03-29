#include <iostream>
#include "list.h"

using namespace std;

int main() {
	ifstream f2("mark_number.txt");
	int delete_number;
	ofstream f("output.txt");
	List l;
	l.input(f2);
	f2 >> delete_number;
	f << ">>>>>>>>>>>>>>>>>>Was input:\n";
	l.print(f);
	f << ">>>>>>>>>>>>>>>>>>End\n";
	l.progress(delete_number);
	f << ">>>>>>>>>>>>>>>>>>Result:\n";
	l.print(f);
	f << ">>>>>>>>>>>>>>>>>>End\n";
	l.clear();
	return 0;

}







