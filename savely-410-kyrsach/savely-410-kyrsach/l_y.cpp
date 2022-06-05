#include "l_y.h"


l_y* l_y::get_next() { return this->next; };
void l_y::set_next(l_y* next) { this->next = next; };

void l_y::get_all_line(char(&a)[100], int& i) {
	word.set_cur(word.get_head());
	while (word.get_cur() != nullptr) {
		int sz = word.get_cur()->get_size();
		for (int j = 0; j < sz; j++) {
			a[i + j] = word.get_cur()->get_i(j);
		}
		i += sz;
		word.set_cur(word.get_cur()->get_next());
	}
}


void l_y::clear() {
	word.clear();
}
