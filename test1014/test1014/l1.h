#pragma once

#include "l2.h"

class l1 {
	l2 a;
	int a1;
public:
	void set_l2_a(int b) { a.set_a(b); };
	int get_l2_a() { return a.get_a(); };
	void set(int b) { a1 = b; };
	int get() { return a1; };
	void add() { a.add(a1); };
};