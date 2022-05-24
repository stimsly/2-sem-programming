#pragma once
#include "report.h" 
using namespace std;

#ifndef INFO_H
#define INFO_H

const int N = 30;

class info{
private:
	char a[N];
	int size;
	int amount;
public:
	info() {
		size = 0;
		amount = 0;
		for (int i = 0; i < N; i++) a[i] = '?';
	};

	int get_size() ;

	char get(int i) ;

	void set(char a, int i);
	void set_size(int a);
	int get_amount() { return amount; };
	void set_amount(int a) { amount = a; };
};

#endif