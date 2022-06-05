#include "form_y.h"

void form_y::clear() {
	while (head != nullptr) {
		cur = head;
		cur->clear();
		head = head->get_next();
		delete cur;
	}
}

bool c(char a[100], char b[100], int aa, int bb) {

	if (aa != bb) return 0;
	for (int i = 0; i < aa; i++) if (a[i] != b[i]) return 0;
	return 1;
}

void form_y::push_back_w(char name[30], int a, char book[30], int b) {
	cur = head;
	int x = 0;
	while (cur != nullptr) {
		char cur_w[100];
		int len;
		cur->get_first(cur_w, len);
		if (c(cur_w, name, len, a)) {
			x = 1;
			cur->push_back(book, b);
		}
		cur = cur->get_next();
	}
	if (!x) {
		if (empty()) {
			head = new l_y(name, a);
			push_back_w(name, a, book, b);
		}
		else {
			cur = head;
			while (cur->get_next() != nullptr) {
				cur = cur->get_next();
			}
			cur->set_next(new l_y(name, a));
			last = cur;
		}
	}
}

void form_y::remove_book(char a[100], int aa, int d) {
	cur = head;
	while (cur != nullptr) {
		cur -> delete_book(a, aa, d);
		cur = cur->get_next();
	}
}


void form_y::output(int t) {
	int calc = 1;
	cur = head;
	int i = 1;
	while (cur != nullptr) {
		if(!t)cout << calc << ".";
		//cout << cur << endl;
		cur->output(0,0);
		cur = cur->get_next();
		calc++;
	}
}

bool form_y::empty() { return head == nullptr; };

void form_y::push_back(int n, char a[30][30], int size[30]) {
	if (empty()) {
		head = new l_y(n, a, size);
	}
	else {
		cur = head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		cur->set_next(new l_y(n, a, size));
		last = cur;
	}
}

