#include "form_y.h"

void form_y::input(ifstream& f) {
	int n;
	f >> n;
	char c;
	c = f.get();
	for (int i = 0; i < n; i++) {
		int size[30]{};
		int amount[30]{};
		char a[30][30];
		
		while (1) {
			c = f.get();
			if (c == '\n') break;
			
			a[0][size[0]++] = c;
		}
		int k;
		f >> k;
		c = f.get();
		for (int i = 0; i < k; i++) {
			f >> amount[i + 1];
			f.get();
			while (1) {
				c = f.get();
				if (c == '\n') break;
				a[i + 1][size[i + 1]++] = c;
			}

		}
		push_back(k, amount, a, size);
	}
	
}

void form_y::clear() {
	while (head != nullptr) {
		cur = head;
		cur->clear();
		head = head->get_next();
		delete cur;
	}
}

void form_y::output() {

	cur = head;
	int i = 1;
	while (cur != nullptr) {
		cur->output();
		cur = cur->get_next();
	}
}
bool form_y::empty() { return head == nullptr; };

void form_y::push_back(int n, int amount[30], char a[30][30], int size[30]) {
	if (empty()) {
		head = new l_y(n, amount, a, size);
	}
	else {
		cur = head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		cur->set_next(new l_y(n, amount, a, size));
		last = cur;
	}
}


void form_y::calc(char(&a)[100][30], int(&was)[100], int(&s)[100], int(&len)) {
	cur = head;
	while (cur != nullptr) {
		cur->calc2(a, was, s, len);
		cur = cur->get_next();

	}
}