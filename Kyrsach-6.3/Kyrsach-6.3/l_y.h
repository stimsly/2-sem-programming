#pragma once
#include "form_x.h"
#ifndef LY_H
#define LY_H
class l_y {
private:
	l_y* next;
	form_x line;
	int size;
public:
	l_y() {
		next = nullptr;
		size = 0;
	};
	l_y(int n, int amount[30], char a[30][30], int size[30]) {
		this->size = n + 1;
		for (int i = 0; i < n + 1; i++) {
			line.push_back(a[i], size[i], amount[i]);
		}
		next = nullptr;
	};

	void get_all_line(char(&a)[100], int& i);
	int get_size();

	l_y* get_next() ;
	void set_next(l_y* next) ;

	void clear();
	void output();
	void calc2(char(&a)[100][30], int(&was)[100], int(&s)[100], int(&len)) { line.calc2(a, was, s, len); };

	
};

#endif