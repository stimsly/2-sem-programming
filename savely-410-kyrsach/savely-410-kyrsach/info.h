#pragma once

const int N = 5;
#include "report.h"
class info{
private:
	char a[N];
	int size;
public:
	info() {
		size = 0;
		for (int i = 0; i < N; i++) a[i] = '?';
	};

	int get_size() ;
	char get(int i) ;
	

	void set(char a, int i);
	void set_size(int a);
};

