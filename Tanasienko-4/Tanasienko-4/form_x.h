#pragma once
#include "l_x.h"

#ifndef FORMX_H
#define FORMX_H

class form_x {
private:
	l_x* head, *cur;
public:
	form_x() {
		head = nullptr;
		cur = nullptr;
	}
	bool empty();
	void clear();
	void push_back(int a[], int size);

	void count(int(&a)[N * N], int& s);

	void output(ofstream& f);
};

#endif