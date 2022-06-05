#pragma once
#include "form_x.h"
#ifndef LY_H
#define LY_H
class l_y {
private:
	l_y* next;
	form_x line;
public:
	l_y() {
		next = nullptr;
	};
	l_y(int n, char a[30][30], int size[30]) {
		for (int i = 0; i < n + 1; i++) {
			line.push_back(a[i], size[i]);
		}
		next = nullptr;
	};
	l_y(char a[30], int size) {
		line.push_back(a, size);
		next = nullptr;

	};

	void get_all_line(char(&a)[100], int& i);

	l_y* get_next() ;
	void set_next(l_y* next) ;

	void clear();
	void output(int a, int b);
	void get_first(char (&res)[100], int &len) {
		for (int i = 0; i < line.get_head()->get_size(); i++) {
			res[i] = line.get_head()->get_i(i);
		}
		len = line.get_head()->get_size();
	};

	void push_back(char a[100], int len) {
		line.push_back(a, len);
	}
	void delete_book(char a[100], int aa, int d) {
		line.delete_book(a, aa, d);
	}

	
};

#endif