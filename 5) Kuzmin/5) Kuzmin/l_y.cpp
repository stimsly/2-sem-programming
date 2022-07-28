#include "l_y.h"

l_y::l_y(int n, char b[]) {
	next = nullptr;
	a.push_back(n, b);
}
void l_y::push_back(int n, char b[]) {
	a.push_back(n, b);
}

void l_y::write() {
	a.write();
}

l_y* l_y::get_next() { return next; }
void l_y::set_next(l_y* a) { next = a; }