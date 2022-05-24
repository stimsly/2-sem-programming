#include "text.h"

void text::input(ifstream& f) {
	for (int i = 0; i < M; i++) {
		char a;
		int j = 0;
		while (1) {
			a = f.get();
			if (i == N or f.eof() or a == '\n') break;
			textM[i].set_char(j, a);
			j++;
		}
		if (j) {
			textM[i].set_len(j);
			l++;
		}
		if (f.eof()) break;
	}
	return;
}