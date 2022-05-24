#include "all.h"

void form_y::input(ifstream& f) {
	int i = 0;
	int b[25];
	int a;
	while (f >> a) {
		b[i] = a;
		i++;
		if (i == N * N) {
			push_back(b, N * N);
			i = 0;
		}
	}
	if (i) push_back(b, i);
}

void form_y::clear() {
	while (head != nullptr) {
		cur = head;
		cur->clear();
		head = head->get_next();
		delete cur;
	}
}

void form_y::find(int(&a)[N * N], int& s, int k) {
	cur = head;
	while (k--) {
		if (cur == nullptr) {
			s = N * N * 2;
			return;
		}
		cur = cur->get_next();

	}
	if (cur == nullptr) {
		s = N * N * 2;
		return;
	}
	cur->count(a, s);
}

void form_y::output(ofstream& f) {

	cur = head;
	int i = 1;
	while (cur != nullptr) {
		f << "Номер блока: " << i << endl;
		i++;
		//for (int i = 0; i < this->cur->get_size(); i++) {
		cur->output(f);
		//}
		f << endl;
		cur = cur->get_next();
	}
}
bool form_y::empty() { return head == nullptr; };

void form_y::push_back(int a[], int size) {
	if (empty()) {
		head = new l_y(a, size);
	}
	else {
		cur = head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		cur->set_next(new l_y(a, size));
	}
}