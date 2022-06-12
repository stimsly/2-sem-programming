#include "l_y.h"

int l_y::get_size() {
	return this->size;
}

l_y* l_y::get_next() { return this->next; };
void l_y::set_next(l_y* next) { this->next = next; };

void l_y::get_all_line(char(&a)[100], int& i) {
	line.set_cur(line.get_head());
	while (line.get_cur() != nullptr) {
		int sz = line.get_cur()->size_cur();
		for (int j = 0; j < sz; j++) {
			a[i + j] = line.get_cur()->get_i(j);
		}
		i += sz;
		line.set_cur(line.get_cur()->get_next());
	}
}

void l_y::output(ofstream& f) {

	line.output(f);
	f << endl;
}

void l_y::clear() {
	line.clear();
}