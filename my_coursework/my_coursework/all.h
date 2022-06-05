#pragma once
#include "form_y.h"

#ifndef ALL_H
#define ALL_H

class all {
private:
	form_y books[26], writers[26];
	int b[26], w[26];
public:
	all() {
		for (int i = 0; i < 26; i++) b[i] = w[i] = 0;
	}
	int get_w(int i) { return w[i]; };
	int get_b(int i) { return b[i]; };
	void output_books();
	void output_books(char a, ofstream &f);
	void output_writers();
	void output_writers(char a, ofstream &f);
	void input(ifstream& f);
	void push_back_w(char name[30], int a, char book[30], int b);
	void clear() {
		for (int i = 0; i < 26; i++) {
			books[i].clear();
			writers[i].clear();
		}
	}
};

#endif