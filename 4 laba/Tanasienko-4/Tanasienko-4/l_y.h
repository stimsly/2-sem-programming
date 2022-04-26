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
	l_y(int a[], int size) {
		next = nullptr;
		this->size = 5;
		for (int i = 0; i < size; i += N) {
			int b[N]{};
			int x = 0;
			for (int j = i; j < min(i + N, size); j++) {
				b[j - i] = a[j];
				x++;
			}
			line.push_back(b, x);

		}
	};

	int get_size();

	l_y* get_next() ;
	void set_next(l_y* next) ;

	void count(int(&a)[N * N], int& s);

	void output(ofstream& f);
	
};

#endif