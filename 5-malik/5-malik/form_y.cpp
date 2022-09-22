#include "form_y.h"
#include <iostream>

void form_y::input(ifstream& f) {
	int i = 0;
	char b[100];
	char a;
	while (1) {
		if (f.eof()) break;
		a = f.get();
		if (f.eof()) break;

		if ((i == 100 or a == '\n')) {
			if (i)push_back(b, i);
			i = 0;
		}
		else {
			b[i] = a;
			i++;
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

void form_y::output(ofstream& f) {

	cur = head;
	int i = 1;
	if (head == nullptr) {
		cout << "Список пуст\n";
		f << "Список пуст\n";
		return;
	}
	while (cur != nullptr) {
		f << i << ") ";
		i++;
		//for (int i = 0; i < this->cur->get_size(); i++) {
		cur->output(f);
		//}
		cur = cur->get_next();
	}
}
bool form_y::empty() { return head == nullptr; };

void form_y::push_back(char a[], int size) {
	if (empty()) {
		head = new l_y(a, size);
	}
	else {
		cur = head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		cur->set_next(new l_y(a, size));
		last = cur;
	}
}