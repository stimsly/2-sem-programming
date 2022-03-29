#include"list.h"
#include<iostream>
void List::input(ifstream &f2) {
	char mark = f2.get();
	ifstream f("input.txt");
	int i = 0;
	char line[n + 1];

	while (1) {
		

		char a = f.get();
		if (f.eof()) break;
		//std::cout << a;
		if (a == '\n' or a == mark) {
			
			if (i != 0 or a == mark or i == n + 1) {
				line[i] = mark;
				push_back(line, mark);
				Size++;	
			}
			
			i = 0;
			if (a == mark) {
				while (1) {
					a = f.get();
					if (a == '\n') break;
				}
			}
			continue;
		}
		line[i++] = a;

	}
}