#pragma once
#include "info.h"

#ifndef LG_H
#define LG_H

class l_x {
private:
	info cur;
	l_x* next;
public:
	l_x() {
		next = nullptr;
	};
	l_x(char a[], int size, int amount, l_x *next = nullptr) {
		for (int i = 0; i < size; i++) {
			cur.set(a[i], i);
		}
		this->cur.set_amount(amount);
		this->cur.set_size(size);
		this->next = next;
	}
	l_x* get_next();
	void set_next(l_x* next);
	void add_(int x) { cur.set_amount(cur.get_amount() + x); };

	int get_size();
	int get_amount() { return cur.get_amount(); };
	char get_i(int i) ;
};

#endif