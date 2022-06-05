#pragma once

const int N = 5;
#include "report.h"
class info{
private:
	int type;
//1
	int amount;
	l_y* name;
//0
	char a[N];
	int size;
public:
	info() {
		name = nullptr;
		amount = 0;
		type = -1;
		size = 0;
		for (int i = 0; i < N; i++) a[i] = '?';
	};

	int get_size() ;
	char get(int i) ;
	l_y* get_name() ;
	int get_amount();
	int get_t() ;

	void set(char a, int i);
	void set_amount(int a) ;
	void set_t(int a) ;
	void set_name(l_y* a);
	void set_size(int a);
};

