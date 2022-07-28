#include "form_x.h"

void form_x::write() {
	cur = head;
	while (cur != nullptr) {
		cur->write();
		cur = cur->get_next();
	}
}

void form_x::push_back(int n, char b[]) {
	if (head == nullptr) {
		head = new l_x(n, b);
	}
	else {
		cur = head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		cur->set_next(new l_x(n, b));
	}
}

form_x::form_x() {
	head = nullptr;
	cur = nullptr;
}