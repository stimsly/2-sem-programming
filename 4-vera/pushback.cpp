#include"FormV.h"

void push_back1(FormV* p, FormG* q) {
	ListV* temp = new ListV;
	temp->G = *q;
	if (p->h == nullptr) {
		p->h = temp;
	}
	else {
		p->c = p->h;
		while (p->c->next != nullptr) {
			p->c = p->c->next;
		}
		p->c->next = temp;
	}
}

void push_back2(char a[], int size, FormG* p) {
	if (p->h == nullptr) {
		p->h = new ListG(a, size);
		p->c = p->h;
	}
	else {
		p->c = p->h;
		while (p->c->next != nullptr) {
			p->c = p->c->next;
		}
		p->c->next = new ListG(a, size);
	}
};

void push_back12(FormV* p, FormG* q) {
	ListV* temp = new ListV;
	temp->G = *q;
	if (p->h1 == nullptr) {
		p->h1 = temp;
	}
	else {
		p->c1 = p->h1;
		while (p->c1->next != nullptr) {
			p->c1 = p->c1->next;
		}
		p->c1->next = temp;
	}
}

void push_back22(char a[], int size, FormG* p) {
	if (p->h == nullptr) {
		p->h = new ListG(a, size);
		p->c = p->h;
	}
	else {
		p->c = p->h;
		while (p->c->next != nullptr) {
			p->c = p->c->next;
		}
		p->c->next = new ListG(a, size);
	}
};