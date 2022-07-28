#include "l_x.h"

l_x::l_x() {
	next = nullptr;
}
l_x::l_x(int n, char b[]) {
	next = nullptr;
	for (int i = 0; i < n; i++) {
		a.set(i, b[i]);
	}
	a.set_n(n);
}

void l_x::write() {
	for (int i = 0; i < a.get_n(); i++) {
		cout << a.get(i);
	}
}

l_x* l_x::get_next() { return next; }
void l_x::set_next(l_x* a) { next = a; }