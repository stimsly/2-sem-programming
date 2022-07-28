#pragma once
#include "laibraries.h"


#ifndef INFO_H
#define INFO_H

const int N = 5;

class info {
private:
	char a[N];
	int i;
public:
	info();
	info(int n, char b[]);

	void set(int i, char a);
	void set_n(int a);
	int get_n();
	char get(int i);
};

#endif