#include "form_x.h"

bool form_x::empty() { return head == nullptr; };

void form_x::push_back(char a[], int size, int amount) {
	if (empty()) {
		this->head = new l_x(a, size, amount);
		cur = head;
	}
	else {
		cur = head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		cur->set_next(new l_x(a, size, amount));
	}



};

void form_x::clear() {
	while (head != nullptr) {
		cur = head;
		head = head->get_next();
		delete cur;
	}
}

void form_x::calc(char (&a)[100][30], int (&was)[100], int (&s)[100], int &len) {
	cur = head;
	int j = 0;
	while (cur != nullptr) {
		if (cur->get_amount() == 0) {
			cur = cur->get_next();
			continue;
		}
		for (int i = 0; i < cur->get_size(); i++) {
			a[j][i] =  cur->get_i(i);
			a[j][i + 1] = '#';
		}
		s[j] = cur->get_size();
		was[j] = cur->get_amount();
		cur = cur->get_next();
		j++;
	}
	len = j;
}


void form_x::output() {
	cur = head;
	while (cur != nullptr) {

		for (int i = 0; i < cur->get_size(); i++) {
			cout << cur->get_i(i);
		}
		cout << ' ';
		if (cur->get_amount()) cout << cur->get_amount();
		cout << endl;
		cur = cur->get_next();
	}
};

void form_x::input_prod(ifstream& f) {
	char bulka[30];
	char a;
	int i = 0;
	while (1) {
		a = f.get();
		if (a == '\n') break;
		bulka[i++] = a;
	}
	push_back(bulka, i, 0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int cur_amount;
		f >> cur_amount;
		char mater[N];
		int j = 0;
		while (1) {
			a = f.get();
			if (a == '\n') break;
			mater[j++] = a;
		}
		push_back(mater, j, cur_amount);
	}
}
void form_x::input_mater(ifstream& f) {
	int n;
	f >> n;
	f.get();
	for (int _ = 0; _ < n; _++) {
		char mater[N];
		int cur_amount;
		char a;
		int i = 0;

		f >> cur_amount;
		f.get();
		while (1) {
			a = f.get();
			if (a == '\n') break;
			mater[i++] = a;
		}
		push_back(mater, i, cur_amount);
	}
}