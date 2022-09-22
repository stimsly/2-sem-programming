#include"FormV.h"
//введение горизонтального списка

void inpG(ifstream& f, FormG* p)
{
	char b[200];
	int i = 0;
	char c;
	while (1) {
		if (f.eof()) break;
		f.get(c);
		if (f.eof()) break;
		if (c == '\n') break;
		b[i++] = c;
	}
	for (int j = 0; j < i;) {
		char a[N];
		int len = 0;
		for (int j2 = j; j2 < std::min(i, j + 5); j2++) {
			a[j2 - j] = b[j2];
			len++;
		}
		j += 5;
		if (len) {
			push_back2(a, len, p);
		}
	}

}

void inpG2(ifstream& f1, FormG* p)
{
	char b[200];
	int i = 0;
	char c;
	while (1) {
		if (f1.eof()) break;
		f1.get(c);
		if (f1.eof()) break;
		if (c == '\n') break;
		b[i++] = c;
	}
	for (int j = 0; j < i;) {
		char a[N];
		int len = 0;
		for (int j2 = j; j2 < std::min(i, j + 5); j2++) {
			a[j2 - j] = b[j2];
			len++;
		}
		j += 5;
		if (len) {
			push_back22(a, len, p);
		}
	}

}