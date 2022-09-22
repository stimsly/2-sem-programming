#include"FormV.h"


void deleteHead(FormV* p, ofstream& r) {
	while (p->h != nullptr) {
		deletelist(p->h->G, r);
		ListV* l = p->h->next;
		delete p->h;
		p->h = l;
	}
	while (p->h1 != nullptr) {
		deletelist(p->h1->G, r);
		ListV* l = p->h1->next;
		delete p->h1;
		p->h1 = l;
	}
}

void deletelist(FormG p, ofstream& r) {
	while(p.h != nullptr)
	{
		ListG *l = p.h->next;
		delete p.h;
		p.h = l;
	}
}