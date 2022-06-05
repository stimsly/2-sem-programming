#pragma once

#include "l_y.h"


class form_y {
public:
	l_y* head, * cur, *prv, *last;
	form_y() {
		prv = nullptr;
		cur = nullptr;
		head = nullptr;
		last = nullptr;
	}

	void output(int t);
	void output(ofstream &f);
	bool empty() ;
	void clear();
	void push_back(int t, char a[100], int aa, int k, l_y* b[100], int bb, int amount[100]);
	l_y* find_link(char a[100], int len);
	void add(ofstream &f);



	void set_cur(l_y* a) { cur = a; };
	void set_prv(l_y* a) { prv = a; };
};
