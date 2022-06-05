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
	l_x(int t, char a[], int size, l_y *name, int amount) {
		for (int i = 0; i < size; i++) {
			cur.set(a[i], i);
		}
		cur.set_size(size);
		cur.set_name(name);
		cur.set_amount(amount);
		cur.set_t(t);
		next = nullptr;
		//cout << t << " " << size << " " << name << " " << amount << endl;
	}
	void output(int t);
	bool try_burgering();


	l_x* get_next();
	void set_next(l_x* next);

	int get_size();
	char get_i(int i) ;
	int get_amount();
};

