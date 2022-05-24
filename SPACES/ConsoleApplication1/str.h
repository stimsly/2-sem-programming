#pragma once
#include <fstream>

using namespace std;
const int N = 100;

#ifndef STR_H
#define STR_H


class str {
private:
	char line[N]{};
	int len = 0;
public:

	void set_len(int len);
	void set_char(int i, char a);

	int get_len();
	char get_char(int i);
};

#endif // !STR_H