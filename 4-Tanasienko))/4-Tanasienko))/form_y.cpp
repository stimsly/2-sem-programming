#include "form_y.h"
#include <iostream>
void progress() {

}

void form_y::input(ifstream& f) {
	int i = 0;
	char b[100];
	char a;
	while (1) {
		if (f.eof()) break;
		a = f.get();
		if (f.eof()) break;
		if (a >= '0' and a <= '9' or a == '.' or a == ',' or a == '\n') {

		}
		else continue;
		if (a == ',') a = '.';
		b[i] = a;
		i++;
		if ( (i == 100 or a == '\n')) {
			if(i)push_back(b, i);
			i = 0;
		}
	}
	if (i) push_back(b, i);
}

void form_y::clear() {
	while (head != nullptr) {
		cur = head;
		cur->clear();
		head = head->get_next();
		delete cur;
	}
}

void form_y::output(ofstream& f) {

	cur = head;
	int i = 1;
	while (cur != nullptr) {
		f << "Номер числа: " << i << endl;
		i++;
		//for (int i = 0; i < this->cur->get_size(); i++) {
		cur->output(f);
		//}
		cur = cur->get_next();
	}
}
bool form_y::empty() { return head == nullptr; };

void form_y::push_back(char a[], int size) {
	if (empty()) {
		head = new l_y(a, size);
	}
	else {
		cur = head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		cur->set_next(new l_y(a, size));
		last = cur;
	}
}


bool check(char a[100], char b[100], int aa, int bb) {
	if (aa != bb) return 0;
	for (int i = 0; i < aa; i++) {
		if (a[i] != b[i]) return 0;
	}
	return 1;
}

void form_y::progress() {
	prv = head;

	char aa[100];
	int sza = 0;

	while (prv != nullptr) {
		cout << "now:\n";
		cout << prv << ' ' << cur << endl;
		cur = prv;
		cur->get_all_line(aa, sza);
		l_y* prv2 = cur;
		set_cur(cur->get_next());
		
		while (cur != nullptr) {

			
			
			cout << cur << " " << prv2 << endl;
			char bb[100];
			int szb = 0;
			cur->get_all_line(bb, szb);
			if (check(aa, bb, sza, szb)) {
				l_y* cur2 = cur;
				set_cur(cur->get_next());
				prv2->set_next(cur);
				delete cur2;
			}
			else {
				prv2 = cur;
				set_cur(cur->get_next());
			}
			szb = 0;
		}
		set_prv(prv->get_next());
		sza = 0;
	}
}