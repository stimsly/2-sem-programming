#include "all.h"

int l_y::get_size() {
	return this->size;
}

l_y* l_y::get_next() { return this->next; };
void l_y::set_next(l_y* next) { this->next = next; };

void l_y::count(int(&a)[N * N], int& s) {
	line.count(a, s);
}

void l_y::output(ofstream& f) {

	line.output(f);
	f << endl;
}

void l_y::clear() {
	line.clear();
}