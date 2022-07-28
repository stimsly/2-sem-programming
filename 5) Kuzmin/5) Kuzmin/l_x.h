#pragma once
#include "info.h"

#ifndef LX_H
#define LX_H

class l_x {
private:
	info a;
	l_x* next;
public:
	l_x();
	l_x(int n, char b[]);

	void write();

	l_x* get_next();
	void set_next(l_x* a);
};

#endif