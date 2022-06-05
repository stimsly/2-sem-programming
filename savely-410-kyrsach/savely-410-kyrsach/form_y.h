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

	bool empty() ;
	void clear();
	void push_back(char a[100], int aa, int k, ofstream &fout);
	void output(ofstream& f);
	bool was(char a[100], int len);
	
	void set_cur(l_y* a) { cur = a; };
	void set_prv(l_y* a) { prv = a; };
};
