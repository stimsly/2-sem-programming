#pragma once
#include "l_y.h"

#ifndef FORMY_H
#define FORMY_H
class form_y {
private:
	l_y* head, * cur;
public:
	form_y() {
		cur = nullptr;
		head = nullptr;
	}

	void input(ifstream& f);

	void find(int(&a)[N * N], int& s, int k);

	void output(ofstream& f);
	bool empty() ;
	void clear();
	void push_back(int a[], int size);
};

#endif