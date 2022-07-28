#pragma once
#include "strL.h";
#include <fstream>
#ifndef text_H
#define text_H

using namespace std;

const int M = 50;

class text {
private:
	StrL textM[M];
	int l = 0;
public:
	void input(ifstream& f);
	void output();
	void progress();
};

#endif