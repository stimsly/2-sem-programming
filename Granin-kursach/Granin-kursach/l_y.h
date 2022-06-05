#pragma once

#include "form_x.h" 

class l_y {
private:
	l_y* next;
	form_x name;
	form_x links_to_names;
	int amount;
public:
	l_y() {
		amount = 0;
		next = nullptr;
	};
	l_y(int t, char a[100], int aa, int k, l_y* b[100], int bb, int amount[100]) {
	//	cout << "here\n";
		//cout << t << endl;
		if (t == 0) {
			
			for (int i = 0; i < aa; i += N) {
				char b[N];
				int size = 0;
				for (int j = i; j < min(i + N, aa); j++, size++) {
					//cout << a[j];
					b[size] = a[j];
				}
				name.push_back(0, b, size, nullptr, 0);
			}
			next = nullptr;
			this->amount = k;
		}
		else {
			char a[N];
			//cout << bb << endl;
			for (int i = 0; i < bb; i++) {
				links_to_names.push_back(1, a, 0, b[i], amount[i]);
				//cout << b[i] << " " << amount[i] << endl;
			}
			next = nullptr;
			this->amount = 0;
		}
		cout << endl;
		
		
	};

	void clear();
	void output(int t);
	void output(ofstream &f);
	bool try_burgering();
	

	void get_all_line(char(&a)[100], int& i);
	l_y* get_next();
	void set_next(l_y* next);
	int get_amount();
	void set_amount(int a);
};
