#include"FormV.h"
//введение вертикального списка

void inpV(ifstream& f, FormV* p)
{

	while (1) {
		if (f.eof()) break;
		FormG* q = new FormG;
		inpG(f, q);
		push_back1(p, q);
		if (f.eof()) break;
	}
}

void inpV2(ifstream& f1, FormV* p)
{

	while (1) {
		if (f1.eof()) break;
		FormG* q = new FormG;
		inpG2(f1, q);
		push_back12(p, q);
		if (f1.eof()) break;
	}
}