#include"Node.h"

char Node::get_char(int i) {
	return this->line.get_char(i);
}
char Node::get_mark() {
	return this->line.get_mark();
}

Node* Node::get_next() {
	return this->next;
}

void Node::clear(Node* head) {
	while (head != nullptr) {
		Node* cur = head;
		cur = cur->get_next();
		delete head;
		head = cur;
	}
}