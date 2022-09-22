#include"ALPHA_LIST.h"


void deleteHead(ALPHA* p, ofstream& r) {
	while (p->h != nullptr) {
		hList* l = p->h->next;
		delete p->h;
		p->h = l;
	}
	while (p->h1 != nullptr) {
		dopHList* l = p->h1->next;
		delete p->h1;
		p->h1 = l;
	}
}

void deleteHead2(ALPHA* p) {
	while (p->h3 != nullptr) {
		hpomoch* l = p->h3->next;
		delete p->h3;
		p->h3 = l;
	}
	while (p->h4 != nullptr) {
		hpomoch* l = p->h4->next;
		delete p->h4;
		p->h4 = l;
	}
}

void deleteHead3(ALPHA* p) {
	while (p->h2 != nullptr) {
		markiList* l = p->h2->next;
		delete p->h2;
		p->h2 = l;
	}
	while (p->h5 != nullptr) {
		markiList* l = p->h5->next;
		delete p->h5;
		p->h5 = l;
	}
	while (p->h6 != nullptr) {
		hrezult* l = p->h6->next;
		delete p->h6;
		p->h6 = l;
	}
	while (p->h7 != nullptr) {
		hrezult* l = p->h7->next;
		delete p->h7;
		p->h7 = l;
	}
}