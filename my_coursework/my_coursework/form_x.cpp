#include "form_x.h"

bool form_x::empty() { return head == nullptr; };


void form_x::push_back(char a[], int size) {
	if (empty()) {
		this->head = new l_x(a, size);
		cur = head;
	}
	else {
		cur = head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		cur->set_next(new l_x(a, size));
	}



};

bool cc(char a[30], char b[30], int aa, int bb) {
	if (aa != bb) return 0;
	for (int i = 0; i < aa; i++) if (a[i] != b[i]) return 0;
	return 1;
}

void form_x::delete_book(char a[100], int aa, int d) {
	cur = head;
	while (cur != nullptr) {
		char b[100];
		int bb = 0;
		cur->get_all(b, bb);
		if (cc(a, b, aa, bb)) {
			cur->set_e(d);
		}
		cur = cur->get_next();
	}
}


void form_x::clear() {
	while (head != nullptr) {
		cur = head;
		head = head->get_next();
		delete cur;
	}
}



void form_x::output(int a, int b) {
	if (head == nullptr) return;
	if (b == 0) {
		cur = head;
		if (!cur->get_e()) {
			cur = cur->get_next();
			return;
		}

		for (int i = 0; i < cur->get_size(); i++) {
			cout << cur->get_i(i);
		}
		cout << endl << endl;
	}
	else {
		cur = head;
		cur = cur->get_next();
		while (cur != nullptr) {
			if (!cur->get_e()) {
				cur = cur->get_next();
				continue;
			}
			for (int i = 0; i < cur->get_size(); i++) {
				cout << cur->get_i(i);
			}
			cout << endl << endl;
			cur = cur->get_next();

		}
	}
	
};
