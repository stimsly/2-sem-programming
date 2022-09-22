#include"ALPHA_LIST.h"
//введение горизонтального списка

void inpG1(ifstream& f, dopList* p)
{
	char b[200];
	int i = 0;
	char c;
	int k;
	while (1) {
		if (f.eof()) break;
		f.get(c);
		if (f.eof()) break;
		if (c == '_') break;
		b[i++] = c;
	}
	f.setf(ios::skipws);
	f.unsetf(ios::skipws);
	f >> k;
	p->NovTar = k;
	f.setf(ios::skipws);
	f.unsetf(ios::skipws);
	f.get(c);
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


void inpG2(ifstream& f1, List* p)
{
	char b[200];
	int i = 0;
	char c;
	int k;
	while (1) {
		if (f1.eof()) break;
		f1.get(c);
		if (f1.eof()) break;
		if (c == '_') break;
		b[i++] = c;
	}
	f1.setf(ios::skipws);
	f1.unsetf(ios::skipws);
	f1 >> k;
	p->number_of_letter = k;
	f1.setf(ios::skipws);
	f1.unsetf(ios::skipws);
	f1.get(c);
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
	char b1[200];
	i = 0;
	while (1) {
		if (f1.eof()) break;
		f1.get(c);
		if (f1.eof()) break;
		if (c == '_') break;
		b1[i++] = c;
	}
	f1.setf(ios::skipws);
	f1.unsetf(ios::skipws);
	f1 >> k;
	p->StarTar = k;
	f1.setf(ios::skipws);
	f1.unsetf(ios::skipws);
	f1.get(c);
	for (int j = 0; j < i;) {
		char a[N];
		int len = 0;
		for (int j2 = j; j2 < std::min(i, j + 5); j2++) {
			a[j2 - j] = b1[j2];
			len++;
		}
		j += 5;
		if (len) {
			push_back32(a, len, p);
		}
	}

}

void inpG3(ifstream& f1, marki* p)
{
	char b[200];
	int i = 0;
	char c;
	int k;
	while (1) {
		if (f1.eof()) break;
		f1.get(c);
		if (f1.eof()) break;
		if (c == '_') break;
		b[i++] = c;
	}
	f1.setf(ios::skipws);
	f1.unsetf(ios::skipws);
	f1 >> k;
	p->stoimost_int = k;
	f1.setf(ios::skipws);
	f1.unsetf(ios::skipws);
	f1.get(c);
	for (int j = 0; j < i;) {
		char a[N];
		int len = 0;
		for (int j2 = j; j2 < std::min(i, j + 5); j2++) {
			a[j2 - j] = b[j2];
			len++;
		}
		j += 5;
		if (len) {
			push_back23(a, len, p);
		}
	}
	char b1[200];
	i = 0;
	while (1) {
		if (f1.eof()) break;
		f1.get(c);
		if (f1.eof()) break;
		if (c == ':') break;
		b1[i++] = c;
	}
	f1.setf(ios::skipws);
	f1.unsetf(ios::skipws);
	f1 >> k;
	p->kolvo_int = k;
	f1.setf(ios::skipws);
	f1.unsetf(ios::skipws);
	f1.get(c);
	for (int j = 0; j < i;) {
		char a[N];
		int len = 0;
		for (int j2 = j; j2 < std::min(i, j + 5); j2++) {
			a[j2 - j] = b1[j2];
			len++;
		}
		j += 5;
		if (len) {
			push_back33(a, len, p);
		}
	}

}