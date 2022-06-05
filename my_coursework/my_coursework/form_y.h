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

	void set_cur(l_y* a) { cur = a; };
	void set_prv(l_y* a) { prv = a; };
	void output(int t);
	bool empty() ;
	void clear();
	void push_back(int n, char a[30][30], int size[30]);
	void push_back_w(char name[30], int a, char book[30], int b);
	void get_first(char (&res)[100], int &len) {
		head->get_first(res, len);
	}
	void remove_book(char a[100], int aa, int d);
};

#endif