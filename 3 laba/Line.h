#pragma once
#include<fstream>
using namespace std;
const int n = 100;
#ifndef LINE_H
#define LINE_H
class Line {
private:
	char line[n + 1];
	char mark;

public:
	char get_char(int i);
	char get_mark();

	void set_mark(char mark);
	void set_char(int i, char a);
};

#endif