#pragma once
#include "form_y.h"

#ifndef ALL_H
#define ALL_H

class all {
public:
	form_y a, b, c;
	void progress();
	void input(ifstream &f1, ifstream &f2) {
		a.input(f1);
		b.input(f2);
	}
	void output(ofstream& fout) {
		fout << "Первый список:\n";
		a.output(fout);
		fout << "Второй список:\n";
		b.output(fout);
		fout << "Результирующий список:\n";
		c.output(fout);
	}
};

#endif