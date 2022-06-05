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
	l_x(char a[], int size, l_x *next = nullptr) {
		for (int i = 0; i < size; i++) {
			cur.set(a[i], i);
		}
		this->cur.set_size(size);
		this->next = next;
	}
	l_x* get_next();
	void set_next(l_x* next);

	int get_size();
	char get_i(int i) ;
	int get_e() { return cur.get_e(); };
	void set_e(int a) { cur.set_e(a); };
	void get_all(char (&a)[100], int &aa) {
		aa = cur.get_size();
		for (int i = 0; i < aa; i++) a[i] = cur.get(i);
	}
};

#endif