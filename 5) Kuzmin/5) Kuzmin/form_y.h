#pragma once
#include "l_y.h"

#ifndef FORMY_H
#define FORMY_H

class form_y {
private:
	l_y* head;
	l_y* cur;
public:
	form_y() {
		head = nullptr;
		cur = nullptr;
	}

	void read(ifstream& f);

	void write();

	void push_back(int n, char b[], int flag);
};

#endif