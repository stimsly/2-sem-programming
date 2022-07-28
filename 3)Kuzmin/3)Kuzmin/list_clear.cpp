#include"list.h"

void List::clear() {
	Size = 0;
	head->clear(head);
}
