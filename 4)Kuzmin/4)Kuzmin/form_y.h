#pragma once
#include "l_y.h"

#ifndef FORMY_H
#define FORMY_H
class form_y {
public:
	l_y* head, * cur, *prv, *last;
	form_y() {
		last = nullptr;
		prv = nullptr;
		cur = nullptr;
		head = nullptr;
	}

	void input(ifstream& f);
	void set_cur(l_y* a) { cur = a; };
	void set_prv(l_y* a) { prv = a; };
	void output(ofstream& f);
	bool empty() ;
	void clear();
	void push_back(char a[], int size);
};

#endif