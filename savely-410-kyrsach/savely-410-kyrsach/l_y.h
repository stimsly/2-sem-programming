#pragma once

#include "form_x.h" 

class l_y {
private:
	l_y* next;
	form_x word;
	int size;
	int k;
public:
	l_y() {
		size = 0;
		k = 0;
		next = nullptr;
	};
	l_y(char a[100], int aa, int k, l_y* next = nullptr) {
	
		for (int i = 0; i < aa; i += N) {
			char b[N];
			int size = 0;
			for (int j = i; j < min(i + N, aa); j++, size++) {
				//cout << a[j];
				b[size] = a[j];
			}
			word.push_back(b, size);
		}
		size = aa;
		this->k = k;
		this->next = next;
	};

	void clear();
	void output(int t);

	void get_all_line(char(&a)[100], int& i);
	l_y* get_next();
	void set_next(l_y* next);
	int get_k() { return k; };
	int get_size() { return size; };
};
