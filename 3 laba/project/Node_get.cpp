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