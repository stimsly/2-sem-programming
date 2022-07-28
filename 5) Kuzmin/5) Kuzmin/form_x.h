#pragma once
#include "l_x.h"

#ifndef FORMX_H
#define FORMX_H

class form_x {
private:
	l_x* head;
	l_x* cur;
public:
	form_x();

	void push_back(int n, char b[]);

	void write();
};

#endif