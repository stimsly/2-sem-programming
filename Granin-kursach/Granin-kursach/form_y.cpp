#include "form_y.h"

void form_y::clear() {
	while (head != nullptr) {
		cur = head;
		cur->clear();
		head = head->get_next();
		delete cur;
	}
}

bool check(char a[100], char b[100], int aa, int bb) {

	if (aa != bb) return 0;
	for (int i = 0; i < aa; i++) if (a[i] != b[i]) return 0;
	return 1;
}

l_y* form_y::find_link(char a[100], int len) {
	cur = head;
	//cout << "now\n";
	//for (int i = 0; i < len; i++) cout << a[i];
	//cout << endl;
	while (cur != nullptr) {
		//cout << cur << endl;
		char b[100];
		int bb = 0;
		cur->get_all_line(b, bb);
		//cout << "cur\n";
		//for (int i = 0; i < bb; i++) cout << b[i];
		//cout << endl;
		if (check(a, b, len, bb)) {
			//cout << endl << endl;;
			return cur;
		}
		set_cur(cur->get_next());
	}
}

void form_y::output(ofstream& f) {
	cur = head;
	while (cur != nullptr) {
		cur->output(f);
		cur = cur->get_next();
	}
}

void form_y::output(int t) {
	cur = head;
	while (cur != nullptr) {
		cur->output(t);
		if (t == 1) cur->output(2);
		cur = cur->get_next();
	}
}
bool form_y::empty() { return head == nullptr; };

void form_y::push_back(int t, char a[100], int aa, int k, l_y* b[100], int bb, int amount[100]) {
	if (empty()) {
		head = new l_y(t, a, aa, k, b, bb, amount);
	}
	else {
		cur = head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		cur->set_next(new l_y(t, a, aa, k, b, bb, amount));
		last = cur;
	}
}

void form_y::add(ofstream &f) {
	cout << "Add\n";
	cur = head;
	while (cur != nullptr) {
		char a[100];
		int len = 0;
		cur->get_all_line(a, len);
		for (int i = 0; i < len; i++) {
			cout << a[i];
			f << a[i];
		}
		cout << ": ";
		int x;
		cin >> x;
		f << " " << x << endl;
		cur->set_amount(cur->get_amount() + x);
		cur = cur->get_next();
	}
}
