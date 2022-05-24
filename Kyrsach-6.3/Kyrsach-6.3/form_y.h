#pragma once
#include "l_y.h"

#ifndef FORMY_H
#define FORMY_H
class form_y {
public:
	l_y* head, * cur, *prv, *last;
	form_y() {
		prv = nullptr;
		cur = nullptr;
		head = nullptr;
		last = nullptr;
	}

	void calc(char(&a)[100][30], int(&was)[100], int(&s)[100], int(&len));
	void input(ifstream& f);
	void set_cur(l_y* a) { cur = a; };
	void set_prv(l_y* a) { prv = a; };
	void output();
	bool empty() ;
	void clear();
	void push_back(int n, int amount[30], char a[30][30], int size[30]);
};

#endif