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
	void push_back(char a[], int size, int amount);
	l_x* get_head() { return head; };
	l_x* get_cur() { return cur; };
	void set_cur(l_x* a) { cur = a; };
	void set_head(l_x* a) { head = a; };
	void calc(char(&a)[100][30], int(&was)[100], int(&s)[100], int(&len));

	void input_prod(ifstream& f);
	void input_mater(ifstream& f);
	void output();
};

#endif