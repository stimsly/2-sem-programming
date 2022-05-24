#pragma once
#include <fstream>
#include "str.h"
using namespace std;
#ifndef TEXT_H
#define TEXT_H

const int M = 20;

class text {
private:
	str textM[M]{};
	int l = 0;
public:
	void input(ifstream& f);
	void progress();
	void skip(int j, int pos, int cur);
	void output(ofstream& f);
};

#endif // !STR_H