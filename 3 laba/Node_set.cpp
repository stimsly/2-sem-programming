#include"Node.h"

void Node::set_next(Node* next) {
	this->next = next;
}
void Node::set_mark(char mark) {
	this->line.set_mark(mark);
}
void Node::set_char(int i, char a) {
	this->line.set_char(i,a);
}

