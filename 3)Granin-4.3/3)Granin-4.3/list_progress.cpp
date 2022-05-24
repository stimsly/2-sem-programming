#include"list.h"

bool check(Line a, Node* b) {
	int i = 0;
	int x = 1;
	while (1) {
		if (a.get_char(i) != b->get_char(i)) {
			x = 0;
			break;
		}
		if (a.get_char(i) == a.get_mark() and b->get_mark() != b->get_char(i)) {
			x = 0;
			break;
		}
		if (a.get_char(i) != a.get_mark() and b->get_mark() == b->get_char(i)) {
			x = 0;
			break;
		}
		if (a.get_char(i) == a.get_mark() and b->get_mark() == b->get_char(i)) {
			break;
		}
		i++;
	}
	return x;
}

void List::progress(Line a, ofstream &fout) {
	fout << "Найденные номера:\n";
	Node* cur = this->head;
	int cur_number = 0;
	while (cur != nullptr) {
		++cur_number;
		if (check(a, cur)) fout << cur_number << endl;
		cur = cur->get_next();
	}
	if (!cur_number) fout << "Нет таких номеров!";

}