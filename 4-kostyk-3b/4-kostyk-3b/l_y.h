#pragma once
#include "form_x.h"
#include <iostream>
#ifndef LY_H
#define LY_H
class l_y {
private:
	l_y* next;
	form_x line;
	int size;
	int was = 0;
public:
	l_y() {
		next = nullptr;
		size = 0;
	};
	l_y(char a[], int size) {
		next = nullptr;
		this->size = N;
		for (int i = 0; i < size; i += N) {
			char b[N]{};
			int x = 0;
			for (int j = i; j < min(i + N, size); j++) {
				b[j - i] = a[j];
				x++;
			}
			if(x)line.push_back(b, x);

		}
	};

	void get_all_line(char(&a)[100], int& i);
	int get_size();

	int get_was() { return was; };
	l_y* get_next() ;
	void set_next(l_y* next) ;
	void set_was() { was = 1; };

	void clear();
	void output(ofstream& f);
	
};

#endif