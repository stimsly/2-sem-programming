#pragma once
#include "form_x.h"

#ifndef LY_H
#define LY_H

class l_y {
private:
	form_x a;
	l_y* next;
public:
	l_y(int n, char b[]);

	void push_back(int n, char b[]);

	void write();

	l_y* get_next();
	void set_next(l_y* a);
};

#endif