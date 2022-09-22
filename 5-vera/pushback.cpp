#include"ALPHA_LIST.h"

void push_back1(ALPHA* p, dopList* q) {
	dopHList* temp = new dopHList;
	temp->base = *q;
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

void push_back2(char a[], int size, dopList* p) {
	if (p->Country_N == nullptr) {
		p->Country_N = new Elem(a, size);
		p->c = p->Country_N;
	}
	else {
		p->c = p->Country_N;
		while (p->c->next != nullptr) {
			p->c = p->c->next;
		}
		p->c->next = new Elem(a, size);
	}
};

void push_back12(ALPHA* p, List* q) {
	hList* temp = new hList;
	temp->base = *q;
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

void push_back22(char a[], int size, List* p) {
	if (p->Letter == nullptr) {
		p->Letter = new Elem(a, size);
		p->c = p->Letter;
	}
	else {
		p->c = p->Letter;
		while (p->c->next != nullptr) {
			p->c = p->c->next;
		}
		p->c->next = new Elem(a, size);
	}
};

void push_back32(char a[], int size, List* p) {
	if (p->Country == nullptr) {
		p->Country = new Elem(a, size);
		p->c1 = p->Country;
	}
	else {
		p->c1 = p->Country;
		while (p->c1->next != nullptr) {
			p->c1 = p->c1->next;
		}
		p->c1->next = new Elem(a, size);
	}
};

void push_back13(ALPHA* p, marki* q) {
	markiList* temp = new markiList;
	temp->base = *q;
	if (p->h2 == nullptr) {
		p->h2 = temp;
	}
	else {
		p->c2 = p->h2;
		while (p->c2->next != nullptr) {
			p->c2 = p->c2->next;
		}
		p->c2->next = temp;
	}
}

void push_back23(char a[], int size, marki* p) {
	if (p->stoimost == nullptr) {
		p->stoimost = new Elem(a, size);
		p->c = p->stoimost;
	}
	else {
		p->c = p->stoimost;
		while (p->c->next != nullptr) {
			p->c = p->c->next;
		}
		p->c->next = new Elem(a, size);
	}
};

void push_back33(char a[], int size, marki* p) {
	if (p->kolvo == nullptr) {
		p->kolvo = new Elem(a, size);
		p->c1 = p->kolvo;
	}
	else {
		p->c1 = p->kolvo;
		while (p->c1->next != nullptr) {
			p->c1 = p->c1->next;
		}
		p->c1->next = new Elem(a, size);
	}
};

void push_back4(ALPHA* p, pomoch* q) {
	hpomoch* temp = new hpomoch;
	temp->base = *q;
	if (p->h3 == nullptr) {
		p->h3 = temp;
	}
	else {
		p->c3 = p->h3;
		while (p->c3->next != nullptr) {
			p->c3 = p->c3->next;
		}
		p->c3->next = temp;
	}
}

void push_back5(ALPHA* p, rezult* q) {
	hrezult* temp = new hrezult;
	temp->base = *q;
	if (p->h6 == nullptr) {
		p->h6 = temp;
	}
	else {
		p->c6 = p->h6;
		while (p->c6->next != nullptr) {
			p->c6 = p->c6->next;
		}
		p->c6->next = temp;
	}
}