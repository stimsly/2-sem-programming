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
	bool exist = 1;
public:
	info() {
		size = 0;
		for (int i = 0; i < N; i++) a[i] = '?';
		exist = 1;
	};

	int get_size() ;

	char get(int i) ;
	int get_e();
	void set_e(int a);
	void set(char a, int i);
	void set_size(int a);
};

#endif