#include "l_y.h"


l_y* l_y::get_next() { return this->next; };
void l_y::set_next(l_y* next) { this->next = next; };

void l_y::get_all_line(char(&a)[100], int& i) {
	name.set_cur(name.get_head());
	while (name.get_cur() != nullptr) {
		int sz = name.get_cur()->get_size();
		for (int j = 0; j < sz; j++) {
			a[i + j] = name.get_cur()->get_i(j);
		}
		i += sz;
		name.set_cur(name.get_cur()->get_next());
	}
}

void l_y::output(int t) {
	if (t == 1 or t == 0 or t == 3) {
		name.output(t);
		if (t == 0) cout << " " << amount << "\n";

	}
	if (t == 2) {
		
		links_to_names.output(2);
		cout << endl;
	}
}

void l_y::clear() {
	name.clear();
	links_to_names.clear();
}

void l_x::output(int t) {
	cur.get_name()->output(t);
}

bool l_y::try_burgering() {
	links_to_names.set_cur(links_to_names.get_head());
	while (links_to_names.get_cur() != nullptr) {
		if (!links_to_names.get_cur()->try_burgering()) return 0;
		links_to_names.set_cur(links_to_names.get_cur()->get_next());
	}
	return 1;
}


bool l_x::try_burgering() {
	if (get_amount() <= cur.get_name()->get_amount()) {
		cur.get_name()->set_amount(cur.get_name()->get_amount() - get_amount());
		return 1;
	}
	else return 0;
}

void l_y::set_amount(int a) { amount = a; };
int l_y::get_amount() { return amount; };