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
	l_x(int a[], int size, l_x *next = nullptr) {
		for (int i = 0; i < size; i++) {
			cur.set(a[i], i);
		}
		this->cur.set_size(size);
		this->next = next;
	}
	l_x* get_next();
	void set_next(l_x* next) ;

	int size_cur();
	int get_i(int i) ;
};

#endif