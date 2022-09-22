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
	int cost;
	bool is_complete;
public:
	l_y() {
		next = nullptr;
		size = 0;
		cost = 0;
		is_complete = 0;
	};
	l_y(char a[], int size, int cost) {
		next = nullptr;
		this->cost = cost;
		this->size = N;
		is_complete = 0;
		for (int i = 1; i < size; i += N) {
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

	int get_cost() { return cost; };
	l_y* get_next() ;
	bool get_c() { return is_complete; };
	void set_next(l_y* next) ;
	void set_cost(int a) { cost = a; };
	void set_c() { is_complete = 1; };
	void clear();
	void output(ofstream& f);
	
};

#endif