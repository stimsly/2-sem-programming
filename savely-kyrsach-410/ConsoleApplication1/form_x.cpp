#include "form_x.h"

bool form_x::empty() { return head == nullptr; };

void form_x::add() {
	cout << "Enter the number u want to add (x >= 0) for the next products:\n";
	cur = head;
	while (cur != nullptr) {
		for (int i = 0; i < cur->get_size(); i++) {
			cout << cur->get_i(i);
		}
		cout << " ";
		int x;
		cin >> x;
	//	cur->add_(x);

		cur = cur->get_next();
	}
}

void form_x::push_back(int t, char a[N], int size, l_y* name, int amount) {
	if (empty()) {
		this->head = new l_x(t, a, size, name, amount);
		cur = head;
	}
	else {
		cur = head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		cur->set_next(new l_x(t, a, size, name, amount));
	}



};

void form_x::clear() {
	while (head != nullptr) {
		cur = head;
		head = head->get_next();
		delete cur;
	}
}

void form_x::output(int t) {
	if (t == 0 or t == 1 or t == 3) {
		cur = head;
		while (cur != nullptr) {
			for (int i = 0; i < cur->get_size(); i++) {
				cout << cur->get_i(i);
			}
			cur = cur->get_next();
		}
		if (t == 1) cout << endl;
	}
	else {
		cur = head;
		while (cur != nullptr) {
			cur->output(3);
			cout << " " << cur->get_amount() << endl;
			cur = cur->get_next();
		}
		
	}

};





l_x* form_x::get_head() { return head; };
l_x* form_x::get_cur() { return cur; };
void form_x::set_cur(l_x* a) { cur = a; };
void form_x::set_head(l_x* a) { head = a; };
