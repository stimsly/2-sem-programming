#pragma once


#include "info.h"


class l_x {
private:
	info cur;
	l_x* next;
public:
	l_x() {
		next = nullptr;
	};
	l_x(char a[N], int size) {
		for (int i = 0; i < size; i++) {
			cur.set(a[i], i);
		}
		cur.set_size(size);
		next = nullptr;
		//cout << t << " " << size << " " << name << " " << amount << endl;
	}
	void output(int t);


	l_x* get_next();
	void set_next(l_x* next);

	int get_size();
	char get_i(int i) ;
};

