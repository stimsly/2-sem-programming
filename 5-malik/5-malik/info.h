#pragma once
#include<fstream>
#include<iostream>
using namespace std;

#ifndef INFO_H
#define INFO_H

const int N = 5;

class info{
private:
	char a[N];
	int size = 0;
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

#endif