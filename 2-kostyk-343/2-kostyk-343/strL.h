#pragma once
#ifndef strL_H 
#define strl_H
const int N = 80;

class StrL {
private:
	char s[N]{};
	int len = 0;
public:
	int getlen();
	char getchar(int i);
	void setchar(int i, int a);
	void setlen(int a);
};

#endif