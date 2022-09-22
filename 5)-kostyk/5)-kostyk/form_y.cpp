#include "form_y.h"
#include <iostream>

void form_y::input(ifstream& f) {
	int i = 0;
	char b[100];
	char a;
	int x = 0;
	int num;
	while (1) {
	
		if (f.eof()) break;
		if (!x) {
			x = 1;
			f >> num;
		}
		if (f.eof()) break;
		a = f.get();
		if (f.eof()) break;
		b[i] = a;
		i++;
		if ( (i == 100 or a == '\n')) {
			if(i)push_back(b, i, num);
			i = 0;
			x = 0;
		}
	}
	if (i) push_back(b, i, num);
}

void form_y::clear() {
	while (head != nullptr) {
		cur = head;
		cur->clear();
		head = head->get_next();
		delete cur;
	}
}

void form_y::output(ofstream& f, int t) {

	cur = head;
	int i = 1;
	while (cur != nullptr) {
		f << i << ") " << "����: " << cur->get_cost() << "\n�������: ";
		cur->output(f);
		if (t) {
			if (cur->get_c()) f << "������� ���������\n\n";
			if (!cur->get_c()) f << "������� �� ���������\n\n";
		}
		cur = cur->get_next();
		i++;
	}
}
bool form_y::empty() { return head == nullptr; };

void form_y::push_back(char a[], int size, int num) {
	cout << endl;
	if (empty()) {
		head = new l_y(a, size, num);
	}
	else {
		cur = head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		cur->set_next(new l_y(a, size, num));
		last = cur;
	}
}