#include "form_y.h"

void form_y::read(ifstream& f) {
	int i = 0;
	char b[N];
	while (!f.eof()) {
		f.get(b[i]);
		i++;
		if (b[i - 1] == '\n') {
			push_back(i, b, 1);
			i = 0;
			continue;
		}

		if (i == 5) {
			push_back(i, b, 0);
			i = 0;
		}
	}
}

void form_y::write() {
	cur = head;
	while (cur != nullptr) {
		cur->write();
		cur = cur->get_next();
	}
}

void form_y::push_back(int n, char b[], int flag) {
	if (head == nullptr) {
		head = new l_y(n, b);
	}
	else {
		cur = head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		if (flag) cur->set_next(new l_y(n, b));
		else cur->push_back(n, b);
	}
}