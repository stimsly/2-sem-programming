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

void List::progress(Line a, Line b, ofstream &fout) {
	Node* cur = this->head;
	Node* prev = this->head;
	while (cur != nullptr) {
		if (check(a, cur)) {
			Node* temp = new Node(b);
			if (cur == head) {
				
				temp->set_next(head);
				head = temp;
				return;
			}
			else {
				prev->set_next(temp);
				temp->set_next(cur);
				return;
			}
		}
		prev = cur;
		cur = cur->get_next();
	}

}