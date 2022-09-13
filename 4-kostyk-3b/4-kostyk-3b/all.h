#pragma once
#include "form_y.h"

#ifndef ALL_H
#define ALL_H

class all {
public:
	form_y a, b;
	int progress();
	void input(ifstream &f1, ifstream &f2) {
		a.input(f1);
		b.input(f2);
	}
	void output(ofstream& fout, int ans) {
		fout << "Первый список:\n";
		a.output(fout);
		fout << "Второй список:\n";
		b.output(fout);
		if (ans == 0) fout << "\nПервый список не входит во второй.\n";
		if (ans == 1) fout << "\nПервый список входит во второй.\n";
	}
};

#endif