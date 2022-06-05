#pragma once
#include "l_x.h"

#ifndef FORMX_H
#define FORMX_H

class form_x {
private:
	l_x* head, *cur;
public:
	form_x() {
		head = nullptr;
		cur = nullptr;
	}
	bool empty();
	void clear();
	void push_back(char a[], int size);
	l_x* get_head() { return head; };
	l_x* get_cur() { return cur; };
	void set_cur(l_x* a) { cur = a; };
	void set_head(l_x* a) { head = a; };

	void output(int a, int b);
	void delete_book(char a[100], int aa, int d);
};

#endif