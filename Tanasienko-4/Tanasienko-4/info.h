#pragma once
#include<fstream>
using namespace std;

#ifndef INFO_H
#define INFO_H

const int N = 5;

class info{
private:
	int a[N];
	int size = 0;
public:
	info() {
		size = 0;
		for (int i = 0; i < N; i++) a[i] = 0;
	};

	int get_size() ;

	int get(int i) ;

	void set(int a, int i);
	void set_size(int a);

};

#endif