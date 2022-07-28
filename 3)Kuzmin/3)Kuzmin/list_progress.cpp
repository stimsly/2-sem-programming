#include"list.h"

bool check(Line a, Node* b) {
	int i = 0;
	int x = 1;
	while (1) {
		if (a.get_char(i) != b->get_char(i)) {
			x = 0;
			break;
		}
		if (a.get_char(i) == a.get_mark() and b->get_mark() == b->get_char(i)) {
			break;
		}
		if (a.get_char(i) == a.get_mark() or b->get_mark() == b->get_char(i)) {
			x = 0;
			break;
		}
		i++;
	}
	return x;
}

void List::progress(Line a, Line b, ofstream &fout) {
	Node* cur = head;
	int was = 0;
	while (cur != nullptr) {
		if (check(a, cur)) {
			was = 1;
			for (int i = 0;; i++) {
				cur->set_char(i, b.get_char(i));
				if (b.get_char(i) == b.get_mark()) break;
			}
			break;
		}
		cur = cur->get_next();
	}
	if (!was) fout << "Ничего не было замененно\n";
}