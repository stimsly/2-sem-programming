#include"list.h"
#include<iostream>
void List::input() {
	ifstream f2("mark_number.txt");
	char mark = f2.get();
	ifstream f("input.txt");
	int i = 0;
	char line[n + 1];
	while (1) {

		char a = f.get();
		if (f.eof()) break;
		if (a == '\n' or a == mark) {
			
			if (i != 0 or a == mark or i == 1000) {
				line[i] = mark;
				push_back(line, mark);
				Size++;	
			}
			
			i = 0;
			if (a == mark) {
				while (1) {
					a = f.get();
					if (f.eof()) break;
					if (a == '\n') break;
				}
			}
			if (f.eof()) break;
			continue;
		}
		line[i++] = a;

	}
}