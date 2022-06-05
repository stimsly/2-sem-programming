#pragma once

#include "l_x.h" 

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
	void push_back(int t, char a[N], int size, l_y* name, int amount);
	void output(int t);
	void output(ofstream &f);
	void add();


	l_x* get_head();
	l_x* get_cur();
	void set_cur(l_x* a);
	void set_head(l_x* a);
};
