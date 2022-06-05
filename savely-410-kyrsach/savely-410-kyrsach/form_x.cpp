#include "form_x.h"

bool form_x::empty() { return head == nullptr; };

void form_x::push_back(char a[N], int size) {
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

void form_x::clear() {
	while (head != nullptr) {
		cur = head;
		head = head->get_next();
		delete cur;
	}
}





l_x* form_x::get_head() { return head; };
l_x* form_x::get_cur() { return cur; };
void form_x::set_cur(l_x* a) { cur = a; };
void form_x::set_head(l_x* a) { head = a; };
