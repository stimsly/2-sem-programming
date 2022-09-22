#include"FormV.h"

void outputV(FormV* p, ofstream& r) {
	p->c = p->h;
	while (p->c != nullptr) {
		output(p->c->G, r);
		r << endl;
		p->c = p->c->next;
		r << endl << "||" << endl << "\\/" << endl;
	}
	r << "NULL" << "\n\n";
}

void output(FormG p, ofstream& r) {
	p.c = p.h;
	if (p.c != nullptr) {
		while (p.c != nullptr) {
			for (int i = 0; i < p.c->el.l; i++)
			{
				cout << p.c->el.stroka[i];
				r << p.c->el.stroka[i];
			}
			cout << endl;
			r << " -> ";
			p.c = p.c->next;
		}
		r << "NULL";
	}
	else
		r << "пустой элемент";
	cout << endl;

}

void outputV2(FormV* p, ofstream& r) {
	p->c1 = p->h1;
	while (p->c1 != nullptr) {
		output2(p->c1->G, r);
		r << endl;
		p->c1 = p->c1->next;
		r << endl << "||" << endl << "\\/" << endl;
	}
	r << "NULL";
}

void output2(FormG p, ofstream& r) {
	p.c = p.h;
	if (p.c != nullptr) {
		while (p.c != nullptr) {
			for (int i = 0; i < p.c->el.l; i++)
			{
				cout << p.c->el.stroka[i];
				r << p.c->el.stroka[i];
			}
			cout << endl;
			r << " -> ";
			p.c = p.c->next;
		}
		r << "NULL";
	}
	else
		r << "пустой элемент";
	cout << endl;

}