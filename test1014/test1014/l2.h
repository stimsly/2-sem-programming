#pragma once
#include "l1.h"
class l2 {
private:
	int a;
public:
	int get_a() { return a; };
	void set_a(int b) { a = b; };
	void add(int b) { a += b; };
};