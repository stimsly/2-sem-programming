#include"ALPHA_LIST.h"
//введение вертикального списка

void inpV(ALPHA* p)
{
	ifstream f3("novTarif.txt");
	while (1) {
		if (f3.eof()) break;
		dopList* q = new dopList;
		inpG1(f3, q);
		push_back1(p, q);
		if (f3.eof()) break;
	}
	f3.close();
	ifstream f1("pisma.txt");
	while (1) {
		if (f1.eof()) break;
		List* q1 = new List;
		inpG2(f1, q1);
		push_back12(p, q1);
		if (f1.eof()) break;
	}
	f1.close();
	ifstream f2("marki.txt");
	while (1) {
		if (f2.eof()) break;
		marki* q2 = new marki;
		inpG3(f2, q2);
		push_back13(p, q2);
		if (f2.eof()) break;
	}
	f2.close();
}