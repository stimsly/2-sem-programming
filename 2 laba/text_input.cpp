#include "text.h"

void text::input(ifstream& f) {
	while (!f.eof()) {
		char a;
		int i = 0;
		while (1) {

			a = f.get();
			if (f.eof()) break;
			if (a == '\n' or i == N) break;
			textM[l].setchar(i++, a);
		}
		textM[l++].setlen(i);
		if (l == M) break;
	}
	return;
}