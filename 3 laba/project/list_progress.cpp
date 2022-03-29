#include"list.h"

void List::progress(int delete_number) {
	if (delete_number < 0) return;
	if (delete_number >= this->Size) return;
	if (!(delete_number)) {
		Node* temp = this->head;
		this->head = (this->head->get_next());
		this->Size--;
		delete temp;
		return;
	}

	Node* cur = this->head;
	for(int i = 0; i < delete_number - 1; i++){
		cur = cur->get_next();
	}
	Node* cur2 = cur->get_next();
	cur->set_next((cur2->get_next()));
	delete cur2;
	this->Size--;
}