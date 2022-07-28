#include"list.h"

void List::push_back(char line[n + 1], char mark) {
	if (is_empty()) {
		this->head = new Node(line,mark);
	}
	else {
		Node* cur = this->head;
		while (cur->get_next() != nullptr) {
			cur = cur->get_next();
		}
		cur->set_next(new Node(line, mark));
	}
}