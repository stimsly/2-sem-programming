#include "all.h"

bool form_x::empty() { return head == nullptr; };

void form_x::push_back(int a[], int size) {
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

void form_x::count(int(&a)[N * N], int& s) {
	cur = head;
	s = 0;
	while (cur != nullptr) {

		for (int i = 0; i < this->cur->size_cur(); i++) {
			a[s++] = this->cur->get_i(i);
		}
		cur = cur->get_next();
	}
}

void form_x::output(ofstream& f) {
	cur = head;
	while (cur != nullptr) {

		for (int i = 0; i < this->cur->size_cur(); i++) {
			f << this->cur->get_i(i) << " ";
		}
		f << endl;
		cur = cur->get_next();
	}
};