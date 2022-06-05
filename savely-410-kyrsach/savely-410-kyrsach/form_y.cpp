#include "form_y.h"

void form_y::clear() {
	while (head != nullptr) {
		cur = head;
		cur->clear();
		head = head->get_next();
		delete cur;
	}
}
bool check3(char a[100], char b[100], int aa, int bb) {

	if (aa != bb) return 0;
	for (int i = 0; i < aa; i++) if (a[i] != b[i]) return 0;
	return 1;
}
bool form_y::was(char a[100], int len) {
	cur = head;
	while (cur != nullptr){
		char b[100];
		int bb = 0;
		cur->get_all_line(b, bb);
		if (check3(a, b, len, bb)) return 1;
		cur = cur->get_next();
	}
	return 0;
}

bool check(char a[100], char b[100], int aa, int bb) {

	if (aa != bb) return 0;
	for (int i = 0; i < aa; i++) if (a[i] != b[i]) return 0;
	return 1;
}


bool form_y::empty() { return head == nullptr; };

bool check2(char a[100], char b[100], int aa, int bb) {
	for (int i = 0; i < aa; i++) {
		if (a[i] > b[i]) return 1;
		if (b[i] > a[i]) return 0;
	}
	return 1;
}

void form_y::output(ofstream &f) {
	cur = head;
	int i = 1;
	while (cur != nullptr) {
		f << i++ << ".";
		char a[100];
		int len = 0;
		cur->get_all_line(a, len);
		for (int i = 0; i < len; i++) f << a[i];
		f << endl;
		cur = cur->get_next();
	}
}

void form_y::push_back(char a[100], int aa, int k, ofstream &fout) {
	if (empty()) {
		fout << "Слово: ";
		for (int i = 0; i < aa; i++) {
			fout << a[i];
		}
		fout << " вставленно в начало списка.\n";
		head = new l_y(a, aa, k);
	}
	else {
		cur = head;
		int x = 1;
		last = nullptr;
		while (cur->get_next() != nullptr) {
			char b[100];
			int bb = 0;
			cur->get_all_line(b, bb);
			if (cur->get_k() < k) {
				last = cur;
				cur = cur->get_next();
			}
			else if (cur->get_k() == k and cur->get_size() < aa) {
				last = cur;
				cur = cur->get_next();
			}
			else if (cur->get_k() == k and cur->get_size() == aa and check2(a,b,aa,bb)) {
				last = cur;
				cur = cur->get_next();
			}
			else break;
			
			x++;
		}
		fout << "Слово: ";
		for (int i = 0; i < aa; i++) {
			fout << a[i];
		}
		fout << " вставленно на позицию: " << x << endl;;

		if(cur->get_next() == nullptr)cur->set_next(new l_y(a, aa, k));
		else if (last == nullptr) {
			head = new l_y(a, aa, k, cur);

		}
		else {
			
			last->set_next(new l_y(a, aa, k, cur));
		}
		last = cur;
	}
}