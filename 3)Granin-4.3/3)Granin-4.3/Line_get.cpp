#include"Line.h"

char Line::get_char(int i) {
	return this->line[i];
}
char Line::get_mark() {
	return this->mark;
}

void Line::input() {
	ifstream f("mark_number.txt");
	char a, mark;
	mark = f.get();
	set_mark(mark);
	int i = 0;
	while (1) {
		a = f.get();
		if (f.eof()) break;
		set_char(i, a);
		i++;
		if (a == mark) break;
		
	}
	set_char(i, mark);
}