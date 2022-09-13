#include"list.h"

void List::print(ofstream& f) {
	Node* cur = this->head;
	for (int i = 0; i < Size; i++) {
		f << "<";
		for (int j = 0;; j++) {

			if (cur->get_char(j) == cur->get_mark()) break;
			f << cur->get_char(j);
		}
		f << "> ---->" << endl;
		cur = cur->get_next();
	}
	f << "NULL\n";
}
